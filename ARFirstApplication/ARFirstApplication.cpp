#ifdef _WIN32
#include <windows.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#ifndef __APPLE__
#include <GL/gl.h>
#include <GL/glut.h>
#else
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#endif
#include <AR/gsub.h>
#include <AR/video.h>
#include <AR/param.h>
#include <AR/ar.h>
#include "GLMetaseq.h"
#include "GLLight.h"

//
// Camera configuration.
//
#ifdef _WIN32
//*vconf保存了摄像头配置文件，XML中记录了摄像头的ID等信息，如果有多个，就学要对他多一些了解
char			*vconf = "Data\\WDM_camera_flipV.xml";
#else
char			*vconf = "";
#endif

int             xsize, ysize;//窗口X,Y尺寸
int             thresh = 100;//与摄像头检测表示部分有关，二值化阈值
int             count = 0;//计数器，记录帧数，之后又专门处理帧的部分

char           *cparam_name = "Data/camera_para.dat";//摄像机参数，记录     识别精度信息
ARParam         cparam;

char           *patt_name = "Data/patt.hiro";//标识图
int             patt_id;//标记的大小 一下三个都是记录标识图几何外形的，坐标变换时使用
double          patt_width = 80.0;//尺寸
double          patt_center[2] = { 0.0, 0.0 };//中心
double          patt_trans[3][4];//矩阵

static void   init(void);
static void   cleanup(void);
static void   keyEvent(unsigned char key, int x, int y);
static void   mainLoop(void);
static void   draw(void);

MQO_MODEL mqoObject;

int main(int argc, char **argv)
{
	glutInit(&argc, argv);//OpenGL初始化
	init();//基本参数初始化

	arVideoCapStart();//摄像头开始工作
	argMainLoop(NULL, keyEvent, mainLoop);//主循环
	return (0);
}

static void   keyEvent(unsigned char key, int x, int y)
{
	/* quit if the ESC key is pressed */
	if (key == 0x1b) {
		printf("*** %f (frame/sec)\n", (double)count / arUtilTimer());
		cleanup();//退出时清理使用过的内存等资源
		exit(0);
	}
}

/* main loop */
static void mainLoop(void)
{
	ARUint8         *dataPtr;//图像数据
	ARMarkerInfo    *marker_info;//标记信息
	int             marker_num;//寻找的标记号码
	int             j, k;

	/* grab a vide frame */
	if ((dataPtr = (ARUint8 *)arVideoGetImage()) == NULL) {
		arUtilSleep(2);//如果2ms内没有获取图像则程序返回
		return;
	}
	if (count == 0) arUtilTimerReset();//定时器复位
	count++;//帧数加一

	argDrawMode2D();//渲染前更新摄像头参数，主要为渲染2D或3D对象做准备
	argDispImage(dataPtr, 0, 0);

	/* detect the markers in the video frame */
	if (arDetectMarker(dataPtr, thresh, &marker_info, &marker_num) < 0) {//dataPtr帧数据，thresh二值化阈值，&marker_info标识特征信息
		cleanup();//marker_num 标识数量
		exit(0);
	}//在摄像头画面中检测标记图案，如果出错，程序退出

	arVideoCapNext();//获取下一帧图像

	/* check for object visibility */
	k = -1;//以下是寻找标记图案，-1代表没有寻找到标记图案
	for (j = 0; j < marker_num; j++) {
		if (patt_id == marker_info[j].id) {
			if (k == -1) k = j;
			else if (marker_info[k].cf < marker_info[j].cf) k = j;
		}
	}
	if (k == -1) {
		argSwapBuffers();//屏幕缓冲
		return;
	}

	/* get the transformation between the marker and the real camera */
	arGetTransMat(&marker_info[k], patt_center, patt_width, patt_trans);

	draw();//渲染模型

	argSwapBuffers();//屏幕缓冲
}

static void init(void)
{
	ARParam  wparam;//有很多这种类的存在

	/* open the video path */
	if (arVideoOpen(vconf) < 0) exit(0);//设定视频设备，出错就退出
	/* find the size of the window */
	if (arVideoInqSize(&xsize, &ysize) < 0) exit(0);
	printf("Image size (x,y) = (%d,%d)\n", xsize, ysize);

	/* set the initial camera parameters */ //初始化摄像头特征参数，参数可以用例子中程序获得
	if (arParamLoad(cparam_name, 1, &wparam) < 0) {//摄像头精度参数
		printf("Camera parameter load error !!\n");
		exit(0);
	}
	arParamChangeSize(&wparam, xsize, ysize, &cparam);//根据精度参数修改设置
	arInitCparam(&cparam);//初始化摄像头
	printf("*** Camera Parameter ***\n");
	arParamDisp(&cparam);

	if ((patt_id = arLoadPatt(patt_name)) < 0) {//加载标识图矩阵
		printf("pattern load error !!\n");
		exit(0);
	}

	/* open the graphics window */
	argInit(&cparam, 1.0, 0, 0, 0, 0);//打开图像窗口
	mqoInit();
	printf("loading mode\n");
	mqoObject = mqoCreateModel("Data/miku.mqo", 0.1);
}

/* cleanup function called when program exits */
static void cleanup(void)
{
	arVideoCapStop();//停止捕捉
	arVideoClose();//关闭视频设备
	argCleanup();//清理及回收资源，WINDOWS不会自动释放资源
}

static void draw(void)
{
	double    gl_para[16];
	GLfloat   mat_ambient[] = { 0.0, 0.0, 1.0, 1.0 };
	GLfloat   mat_flash[] = { 0.0, 0.0, 1.0, 1.0 };
	GLfloat   mat_flash_shiny[] = { 50.0 };
	GLfloat   light_position[] = { 100.0, -200.0, 200.0, 0.0 };
	GLfloat   ambi[] = { 0.1, 0.1, 0.1, 0.1 };
	GLfloat   lightZeroColor[] = { 0.9, 0.9, 0.9, 0.1 };

	//3D绘图模式
	argDrawMode3D();
	argDraw3dCamera(0, 0);
	glClearDepth(1.0);
	glClear(GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	//加载摄像头变化矩阵
	/* load the camera transformation matrix */
	argConvGlpara(patt_trans, gl_para);
	glMatrixMode(GL_MODELVIEW);
	glLoadMatrixd(gl_para);

	//灯光部分
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambi);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightZeroColor);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_flash);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_flash_shiny);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMatrixMode(GL_MODELVIEW);
	
	//模型的坐标(x,y,z)
	//使用自己的模型，或者修改坐标，只要操作下面两个函数
	glTranslatef(0.0, 0.0, 25.0);
	glRotatef(90.0,1.0, 0.0, 0.0);
	//glutSolidCube(50.0);
	mqoCallModel(mqoObject);
	glDisable(GL_LIGHTING);

	glDisable(GL_DEPTH_TEST);
}
