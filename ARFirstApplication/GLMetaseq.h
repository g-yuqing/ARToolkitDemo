#ifndef __GLMETASEQ_H__
#define __GLMETASEQ_H__

/*=========================================================================================
           ^ Z R C A ? им ? ж╠ ?   f  (*.mqo) eOpenGL ? иж ? Y   T ?   e и╣ ? ? ?C/C++ p w b _
=========================================================================================*/

/*
GLMetaseq
The MIT License
Copyright (c) 2009 Sunao Hashimoto and Keisuke Konishi

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.


GLMetaseq
MIT   C Z   X
Copyright (c) 2009 Sunao Hashimoto and Keisuke Konishi

 ии o иж ии ? иж e   иж ] бщ A { \ t g E F A бз ? ? ? A ?   им t @ C   i ии o u \ t g
 E F A v j им ? ? e ? ? бд иж бд б┴ ? им l иж ? ж╠ A \ t g E F A e 3 бь ид иж ж╠ бш б└ ? e
 3   ?   ? ж╠ и╣ бд B б└ и║ иж ик A \ t g E F A им ? ? e g p A ? и║ A ? X A     A f и▓ A
 D z A T u   C Z   X A бз ? ?/ и╣ ? ик им   бд иж     A бз ? ? \ t g E F A e ?   бд иж
   ии иж бе ? б└ ? e   ? бд иж     ид 3 бь ид иж и╣ и╣ и║ и╣ бд B

 ? L им   им   \ | бз ? ? {   ? \ | e A \ t g E F A им бд б┴ ? им ? ? и╣ ? ик d v ии   a
 иж L и▓ бд иж ид им ? ж╠ и╣ бд B

 \ t g E F A ик u ? ио им и╣ и╣ v ? A ? | ?   иж ? ? и┤ ?   иж ? e a ик ? A ? ? им ? ?
 ид ии - ?   3 и║ и╣ бд B б└ б└ ? бщ бш ? ? ? ик A бш i ? A ив ии им и▓ I ? им K   ? A бз ? ?
     ? N Q иж ? бщ ? им ? ? ид и╣ Y и╣ бд a A ? и║ иж ид ии 3 и║ иж ид им ? ик   ии и╣ 1 ? B
 им и░ и╣ ? ик   им   и░ ик A _ ? s б┴ A s @ s б┴ A и╣ ? ик ? и║ ии O ?   ? бш ? A \ t g
 E F A иж N ? и╣ ? ик ? A ж╠ A   иж бщ ик \ t g E F A им g p и╣ ? ик ? им ? им ж╠ бщ иж
 ? ив ? ? ? иж и║ ? им ?   A 1 Q A ? им ? им ` б└ иж ? бщ ? ? ? им ио C ид   ик ии бщ ид им
 ? ж╠ и╣ бд B
*/

/*
----------------------------------------------------------------------------------------
        1.  б└ им w b _ e g бш ? ? им   ио _
----------------------------------------------------------------------------------------

           ? Y   Y ? \ ии e N X `   им ?   ` ? икbmp Ctga Cjpeg Cpng
         @ ? ? ж╠
         @ @jpeg им ? Y   Y иж икJPEG   C u     ilibjpeg.lib, jpeglib.h j a и║ r K v
         @ @jpeg им ? Y   Y e L ? иж бд иж иж ик C б└ им w b _ им DEF_USE_LIBJPEG  e 1  иж бд иж б└ ?

         @     png им ? Y   Y иж икPNG   C u     ilibpng.lib, zlib.lib, png.h ,zlib.h j a и║ r K v
         @ @png им ? Y   Y e L ? иж бд иж иж ик C б└ им w b _ им DEF_USE_LIBPNG   e 1  иж бд иж б└ ?

           e N X `   ?   им T C Y ик u и║ ио a2 имn ? T C Y(64,128,256 c) им 3 ? ` v иж ид иж


----------------------------------------------------------------------------------------
        2.  g бщ ?(1) 1 ? имMQO t @ C   e ? Y   ? ? \ | бд иж и║  
----------------------------------------------------------------------------------------

        (1)    и▓ ? iARToolKit им и║   CargInit() им ? иж g p j

                mqoInit();

        (2)  t @ C   ? ? им   f   им ? Y   Y

                MQO_MODEL model;
                model = mqoCreateModel( "mario.mqo", 1.0 );

        (3)    f   им ? ? o ж╠

                mqoCallModel( model );

        (4)    f   им ив  

                mqoDeleteModel( model );

        (5)  I 1     i v   O     I 1   иж a ив ? - ? 3 бщ j

                mqoCleanup();

----------------------------------------------------------------------------------------
        3.  g бщ ?(2)  A ? t @ C   e ? Y   ? ? \ | бд иж и║  
----------------------------------------------------------------------------------------

        (1)    и▓ ? iARToolKit им и║   CargInit() им ? иж g p j

                mqoInit();

        (2)  A ? V [ P   X им им ?

           @ ив Fmario0.mqo  ` mario9.mqo  e ? Y   T

                MQO_SEQUENCE seq;
                seq = mqoCreateSequence( "mario%d.mqo", 10, 1.0 );

        (3)  A ? V [ P   X им w ии t   [   им ? ? o ж╠ ii ик t   [   ?   j

                mqoCallSequence( seq, i );

        (4)  A ? V [ P   X им ив  

                mqoDeleteSequence( seq );

        (5)  I 1     i v   O     I 1   иж a ив ? - ? 3 бщ j

                mqoCleanup();

----------------------------------------------------------------------------------------
        4.  ? ии d l
----------------------------------------------------------------------------------------

           \ | @ \
         E T | [ g ж╠ ? бщ ижMQO t @ C   им o [ W     ик uMetasequoia Ver1.0/2.0 `2.4 v

         E ?   ж╠ ? бщ иж T ? ? ?
         @ F i ? j
         @ e N X `   } b v i o   v } b v ? ?   ^UV } b s   O им Y j

         E ?   ж╠ ? бщ иж I u W F N g ? ?
         @ \ | ^ ? \ | им ? ии ? |
         @ X   [ W   O им L 3
         @ ? _ @ и╣ e   ? иж ? ? им X   [ W   O p
         @ ? _ ? ?
         @ и║ ? ? i ? _ J   [ ? ?   j

         E ии и║ E ? и║ E ? ] им иж ик ? ?  
         E   ^ { [   ик ? ?  

           d l
         E `     N ? ик бф гд ? ж╠ ? ? ?   ? ? ?   им ? и║ e ж╠ ии бщ б└ ? иж ии ив ? бщ иж a
         @ ? и║ ж╠ ? ж╠ и╣ ив ? бщ иж D
         E e N X `   им p X иж ? o C g ?   e ? ? ив ? бщ ?
         @ ? им ии ? иж'\'(0x5c) a'/'(0x2f) a ик бщ ив ? бщ иж ? бш и╣ - e N X `   a ? ? ии бщ D
         E бщ   F им } e   A   иж ?   ж╠ ? бщ ии бщ D
         @Object `     N бзface `     N им T ? C   f b N X iM(%d) j a-1 иж бщ ?   D

*/



/*=========================================================================
 y   [ U a C ио ? Y ии z
=========================================================================*/

#define MAX_TEXTURE                             100                     //  e N X `   им ? ? ? ии ж╠ бщ  
#define MAX_OBJECT                              50                      // 1 ? имMQO t @ C   ид им ? ? I u W F N g  
#define SIZE_STR                                256                     //  ?   ? o b t @ им T C Y
#define DEF_IS_LITTLE_ENDIAN    1                       //  G   f B A   w ии iintel n=1 j
#define DEF_USE_LIBJPEG                 0                       // libjpeg им g p i1: g p 0: бщ g p j
#define DEF_USE_LIBPNG                  0                       // libpng  им g p i1: g p 0: бщ g p j



/*=========================================================================
 y R   p C   I v V     z
=========================================================================*/

// JPEG e g p бд иж
#ifdef D_JPEG
        #undef  DEF_USE_LIBJPEG
        #define DEF_USE_LIBJPEG 1
#endif

// JPEG e g p ж╠ ии бщ
#ifdef D_NO_JPEG
        #undef  DEF_USE_LIBJPEG
        #define DEF_USE_LIBJPEG 0
#endif

// PNG e g p бд иж
#ifdef D_PNG
        #undef  DEF_USE_LIBPNG
        #define DEF_USE_LIBPNG 1
#endif

// PNG e g p ж╠ ии бщ
#ifdef D_NO_PNG
        #undef  DEF_USE_LIBPNG
        #define DEF_USE_LIBPNG 0
#endif


/*=========================================================================
 y w b _ z
=========================================================================*/

#ifdef WIN32
        #include <windows.h>
#else
        #ifndef MAX_PATH
                #define MAX_PATH    256
        #endif
        #ifndef TRUE
                #define TRUE    (1==1)
        #endif
        #ifndef FALSE
            #define FALSE   (1!=1)
        #endif
#endif

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifdef __APPLE__
        #include <OpenGL/gl.h>
        #include <OpenGL/glu.h>
        #include <GLUT/glut.h>
        #include <OpenGL/glext.h>
#else
        #include <GL/gl.h>
        #include <GL/glu.h>
        #include <GL/glut.h>
//      #include <gl/glext.h>
#endif


/*=========================================================================
 y @ \ Y ии z libjpeg g p Y ии
=========================================================================*/

#if DEF_USE_LIBJPEG

        #define XMD_H // INT16 ?INT32 им ? ии ` G   [ e h ?
        #ifdef FAR
                #undef FAR
        #endif

        #include "jpeglib.h"
        #pragma comment(lib,"jpeg.lib")

#endif


/*=========================================================================
 y @ \ Y ии z libpng g p Y ии
=========================================================================*/

#if DEF_USE_LIBPNG

        #include "png.h"
        #include "zlib.h"
        #pragma comment(lib,"libpng.lib")
        #pragma comment(lib,"zlib.lib")

#endif


/*=========================================================================
 y } N   ии ` z  ? ? l } N  
=========================================================================*/

#ifndef MAX
        #define MAX(a, b)  (((a) > (b)) ? (a) : (b))
#endif


/*=========================================================================
 y ^ ии ` z TGA t H [ } b g
=========================================================================*/

#define DEF_TGA_COLOR_MAP_FLAG_VALID    1
#define DEF_TGA_TYPE_NON                                0
#define DEF_TGA_TYPE_INDEX                              1
#define DEF_TGA_TYPE_FULL                               2
#define DEF_TGA_TYPE_MONO                               3
#define DEF_TGA_TYPE_RLEINDEX                   9
#define DEF_TGA_TYPE_RLEFULL                    10
#define DEF_TGA_TYPE_RLEMONO                    11
#define DEF_TGA_BIT_INFO_RIGHT_TO_LEFT  0x00
#define DEF_TGA_BIT_INFO_LEFT_TO_RIGHT  0x10
#define DEF_TGA_BIT_INFO_DOWN_TO_TOP    0x00
#define DEF_TGA_BIT_INFO_TOP_TO_DOWN    0x20

typedef struct {
        unsigned char   id;
        unsigned char   color_map_flag;
        unsigned char   type;
        unsigned short  color_map_entry;
        unsigned char   color_map_entry_size;
        unsigned short  x;
        unsigned short  y;
        unsigned short  width;
        unsigned short  height;
        unsigned char   depth;
        unsigned char   bit_info;
} STR_TGA_HEAD;


/*=========================================================================
 y ^ ии ` z OpenGL p F \ бщ им (4 Ffloat)
=========================================================================*/
typedef struct {
        GLfloat r;
        GLfloat g;
        GLfloat b;
        GLfloat a;
} glCOLOR4f;


/*=========================================================================
 y ^ ии ` z OpenGL p Q   3 ид W \ бщ им (float)
=========================================================================*/
typedef struct {
        GLfloat x;
        GLfloat y;
} glPOINT2f;


/*=========================================================================
 y ^ ии ` z OpenGL p R   3 ид W \ бщ им (float)
=========================================================================*/
typedef struct tag_glPOINT3f {
        GLfloat x;
        GLfloat y;
        GLfloat z;
} glPOINT3f;


/*=========================================================================
 y ^ ии ` z  и║ ? ? \ бщ им
=========================================================================*/
typedef struct {
        int                     n;              // 1 ? им и║ e \ ? бд иж ? _ им   i3 `4 j
        int                     m;              //  и║ им T ? ?  
        int                     v[4];   //  ? _ ?   e i [ ж╠ ? z ?
        glPOINT2f       uv[4];  // UV } b v
} MQO_FACE;


/*=========================================================================
 y ^ ии ` z  T ? ? ? \ бщ им i t @ C   ? ? ? ? e ? Y   T ? иж g p j
=========================================================================*/
typedef struct {
        glCOLOR4f       col;                            //  F
        GLfloat         dif[4];                         //  g U ?
        GLfloat         amb[4];                         //  и╣ ик ?
        GLfloat         emi[4];                         //  ? ии ? ?
        GLfloat         spc[4];                         //  ? ? ?
        GLfloat         power;                          //  ? ? ? им - 3
        int                     useTex;                         //  e N X `   им L 3
        char            texFile[SIZE_STR];      //  e N X `   t @ C  
        char            alpFile[SIZE_STR];      //  A   t @ e N X `   t @ C  
        GLuint          texName;                        //  e N X `   ?
} MQO_MATDATA;


/*=========================================================================
 y ^ ии ` z  I u W F N g \ бщ им i p [ c P ? им f [ ^ j
=========================================================================*/
typedef struct {
        char            objname[SIZE_STR];      //  p [ c ?
        int                     visible;                        //  ?   ио ?
        int                     shading;                        //  V F [ f B   O i0: t   b g ^1: O   [ j
        float           facet;                          //  X   [ W   O p
        int                     n_face;                         //  и║  
        int                     n_vertex;                       //  ? _  
        MQO_FACE        *F;                                     //  и║
        glPOINT3f       *V;                                     //  ? _
} MQO_OBJDATA;


/*=========================================================================
 y ^ ии ` z  e N X `   v [  
=========================================================================*/
typedef struct {
        GLuint                  texture_id;                     //  e N X `  ID
        int                             texsize;                        //  e N X `   T C Y
        char                    texfile[MAX_PATH];      //  e N X `   t @ C  
        char                    alpfile[MAX_PATH];      //  A   t @ e N X `   t @ C  
        unsigned char   alpha;                          //  A   t @
} TEXTURE_POOL;


/*=========================================================================
 y ^ ии ` z  ? _ f [ ^ i e N X `   g p   j
=========================================================================*/
typedef struct {
        GLfloat point[3];       //  ? _ z ? (x, y, z)
        GLfloat normal[3];      //  @ и╣ z ? (x, y, z)
        GLfloat uv[2];          // UV z ? (u, v)
} VERTEX_TEXUSE;


/*=========================================================================
 y ^ ии ` z  ? _ f [ ^ i e N X `   s g p   j
=========================================================================*/
typedef struct {
        GLfloat point[3];       //  ? _ z ? (x, y, z)
        GLfloat normal[3];      //  @ и╣ z ? (x, y, z)
} VERTEX_NOTEX;


/*=========================================================================
 y ^ ии ` z  } e   A   ? ? i } e   A   и║ иж ? _ z ? e   ? j
=========================================================================*/
typedef struct {
        int                             isValidMaterialInfo;//  } e   A   ? ? им L ?/ 3 ?
        int                             isUseTexture;           //  e N X `   им L 3 FUSE_TEXTURE / NOUSE_TEXTURE
        GLuint                  texture_id;                     //  e N X `   им ? O(OpenGL)
        GLuint                  VBO_id;                         //  ? _ o b t @ имID(OpenGL) @ ?   ж╠ ? иж   ? бе g p
        int                             datanum;                        //  ? _  
        GLfloat                 color[4];                       //  F z ? (r, g, b, a)
        GLfloat                 dif[4];                         //  g U ?
        GLfloat                 amb[4];                         //  и╣ ик ?
        GLfloat                 emi[4];                         //  ? ии ? ?
        GLfloat                 spc[4];                         //  ? ? ?
        GLfloat                 power;                          //  ? ? ? им - 3
        VERTEX_NOTEX    *vertex_p;                      //  |   S   им Y им   им ? _ z ?
        VERTEX_TEXUSE   *vertex_t;                      //  e N X `   g p   им ? _ z ?
} MQO_MATERIAL;


/*=========================================================================
 y ^ ии ` z  ид   I u W F N g i1 ? им p [ c e ?   j
=========================================================================*/
typedef struct {
        char                    objname[SIZE_STR];              //  I u W F N g ?
        int                             isVisible;                              // 0 F ? \ | @ ? им ? F \ |
        int                             isShadingFlat;                  //  V F [ f B   O   [ h
        int                             matnum;                                 //  g p } e   A    
        MQO_MATERIAL    *mat;                                   //  } e   A   z ?
} MQO_INNER_OBJECT;


/*=========================================================================
 y ^ ии ` z MQO I u W F N g i1 ? им   f   e ?   j @ |MQO_MODEL им ид им
=========================================================================*/
typedef struct {
        unsigned char           alpha;                          //  ? _ z ? им ?   иж w ии 3 и║ ? A   t @ l i Q ? p j
        int                                     objnum;                         //  ид   I u W F N g  
        MQO_INNER_OBJECT        obj[MAX_OBJECT];        //  ид   I u W F N g z ?
} MQO_OBJECT;


/*=========================================================================
 y ^ ии ` z MQO_MODEL \ бщ им
=========================================================================*/
typedef MQO_OBJECT * MQO_MODEL;         // MQO_MODEL ик ? ? ` ? \ бщ им ? им A h   X


/*=========================================================================
 y ^ ии ` z MQO V [ P   X
=========================================================================*/
typedef struct {
        MQO_MODEL       model;          //    f  
        int                     n_frame;        //  t   [    
} MQO_SEQUENCE;


/*=========================================================================
 y ^ ии ` z glext.h  ? ? им VBO Extension  им ии `
=========================================================================*/
#ifdef WIN32
        #define GL_ARRAY_BUFFER_ARB     0x8892
        #define GL_STATIC_DRAW_ARB      0x88E4
        typedef void (APIENTRY * PFNGLBINDBUFFERARBPROC)    (GLenum target, GLuint buffer);
        typedef void (APIENTRY * PFNGLDELETEBUFFERSARBPROC) (GLsizei n, const GLuint *buffers);
        typedef void (APIENTRY * PFNGLGENBUFFERSARBPROC)    (GLsizei n, GLuint *buffers);
        typedef void (APIENTRY * PFNGLBUFFERDATAARBPROC)    (GLenum target, int size, const GLvoid *data, GLenum usage);
#endif


/*=========================================================================
 y O   [ o   ?   ии ` z
=========================================================================*/

#ifdef __GLMETASEQ_C__
        #define __GLMETASEQ_C__EXTERN
#else
        #define __GLMETASEQ_C__EXTERN extern
#endif

__GLMETASEQ_C__EXTERN int g_isVBOSupported;     // OpenGL им ? _ o b t @ им T | [ g L 3

#ifdef WIN32
        // VBO Extension  ?   им | C   ^
        __GLMETASEQ_C__EXTERN PFNGLGENBUFFERSARBPROC glGenBuffersARB;           // VBO  ? O ? ?
        __GLMETASEQ_C__EXTERN PFNGLBINDBUFFERARBPROC glBindBufferARB;           // VBO    ? ? бе
        __GLMETASEQ_C__EXTERN PFNGLBUFFERDATAARBPROC glBufferDataARB;           // VBO  f [ ^   [ h
        __GLMETASEQ_C__EXTERN PFNGLDELETEBUFFERSARBPROC glDeleteBuffersARB;     // VBO  ик  
#endif

#undef __GLMETASEQ_C__EXTERN


/*=========================================================================
 y ?   иж ? z
=========================================================================*/

#ifdef __cplusplus
extern "C" {
#endif


//    и▓ ?
void mqoInit(void);

//  I 1    
void mqoCleanup(void);

//    f   ? ?
MQO_MODEL        mqoCreateModel(char *filename, double scale);

//  V [ P   X ? ?
MQO_SEQUENCE mqoCreateSequence(const char *format, int n_file, double scale);

//  V [ P   X ? ? i g бъ ? j
MQO_SEQUENCE mqoCreateSequenceEx(const char *format, int n_file, double scale,
                                                                 int fade_inout, unsigned char alpha);

//    f   ? ? o ж╠
void mqoCallModel(MQO_MODEL model);

//  V [ P   X ? ? o ж╠
void mqoCallSequence(MQO_SEQUENCE seq, int i);

//    f   им ик  
void mqoDeleteModel(MQO_MODEL model);

//  V [ P   X им ик  
void mqoDeleteSequence(MQO_SEQUENCE seq);


#ifdef __cplusplus
}
#endif




#endif  // -- end of header --