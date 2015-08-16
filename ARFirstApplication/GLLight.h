
#ifndef __GLLIGHT_H__
#define __GLLIGHT_H__

/*=========================================================================================

        GLLight.h

        OpenGL иж бз бе иж ? 1   им e ии P иж бд иж w b _ D
         ? z z E и╣ ? ик ? R ? бд D

 @ @Copyright (c)  H w i r, 2007-. ver.07/06/01

=========================================================================================*/



/*=========================================================================
 y ?   zLightPosition
 y p r z ? 1 им и║ u Y ии
 y ?   z
                x,y,z    ? 1 им и║ u

 y ? l z ии ж╠
=========================================================================*/

void LightPosition(double x, double y, double z)
{
        float position[4];
        position[0] = x;
        position[1] = y;
        position[2] = z;
        position[3] = 0.0;
        glLightfv( GL_LIGHT0, GL_POSITION, position );
}



/*=========================================================================
 y ?   zLightPosition
 y p r z ? 1 eON иж бд иж
 y ?   z
                x,y,z                    ? 1 им и║ u
                diffuse***               g U ? ? W  
                specular***              ? и║ ? ? W  
                ambient***               ? ? ? ? W  
                shininess                ? и║ ? им w  

 y ? l z ии ж╠
=========================================================================*/

void LightOn(double x, double y, double z,
                         double diffuseRed, double diffuseGreen, double diffuseBlue,
                         double specularRed, double specularGreen, double specularBlue,
                         double ambientRed, double ambientGreen, double ambientBlue,
                         double shininess)
{
        GLfloat diffuse[] = {diffuseRed, diffuseGreen, diffuseBlue, 1.0f};
        GLfloat specular[] = {specularRed, specularGreen, specularBlue, 1.0f};
        GLfloat ambient[] = {ambientRed, ambientGreen, ambientBlue, 1.0f};
        GLfloat mat_specular[] = {1.0f, 1.0f, 1.0f, 1.0f};

        glEnable( GL_LIGHTING );
        glEnable( GL_LIGHT0 );
        glEnable( GL_COLOR_MATERIAL );
        glLightfv( GL_LIGHT0, GL_DIFFUSE, diffuse );
        glLightfv( GL_LIGHT0, GL_SPECULAR, specular );
        glLightfv( GL_LIGHT0, GL_AMBIENT, ambient );
        LightPosition(x,y,z);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
        glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
}



/*=========================================================================
 y ?   zLightOff
 y p r z ? 1 eOFF иж бд иж
 y ?   z ии ж╠
 y ? l z ии ж╠
=========================================================================*/

void LightOff(void)
{
        glDisable(GL_LIGHTING);
}



/*=========================================================================
 y ?   zGouraudShading
 y p r z O   [ V F [ f B   O
 y ?   z ии ж╠
 y ? l z ии ж╠
=========================================================================*/

void GouraudShading(void)
{
        glShadeModel(GL_SMOOTH);
}



#endif
