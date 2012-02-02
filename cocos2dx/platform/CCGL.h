/****************************************************************************
Copyright (c) 2010 cocos2d-x.org

http://www.cocos2d-x.org

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
****************************************************************************/

#ifndef __PLATFOMR_CCGL_H__
#define __PLATFOMR_CCGL_H__

//
// Common layer for OpenGL stuff
//

#include "CCEGLView.h"

#define CC_GLVIEW                   cocos2d::CCEGLView
#define ccglOrtho					glOrthof
#define	ccglClearDepth				glClearDepthf
#define ccglGenerateMipmap			glGenerateMipmapOES
#define ccglGenFramebuffers			glGenFramebuffersOES
#define ccglBindFramebuffer			glBindFramebufferOES
#define ccglFramebufferTexture2D	glFramebufferTexture2DOES
#define ccglDeleteFramebuffers		glDeleteFramebuffersOES
#define ccglCheckFramebufferStatus	glCheckFramebufferStatusOES
#define ccglTranslate				glTranslatef

#define CC_GL_FRAMEBUFFER			GL_FRAMEBUFFER_OES
#define CC_GL_FRAMEBUFFER_BINDING	GL_FRAMEBUFFER_BINDING_OES
#define CC_GL_COLOR_ATTACHMENT0		GL_COLOR_ATTACHMENT0_OES
#define CC_GL_FRAMEBUFFER_COMPLETE	GL_FRAMEBUFFER_COMPLETE_OES

#include "CCCommon.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#include "OpenGLES/ES1/gl.h"
#include "OpenGLES/ES1/glext.h"
#endif

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include <GLES/gl.h>
#define GL_GLEXT_PROTOTYPES
#include <GLES/glext.h>
#endif

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WOPHONE)
#include <GLES/gl.h>
#include <GLES/glext.h>
#endif

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#include <GLES/gl.h>
#include <GLES/glext.h>
#endif

#if (CC_TARGET_PLATFORM == CC_PLATFORM_UNIX)
#if (__MACH__ == 1)
#include <gl.h>
#include <glext.h>
#else
#include <GL/gl.h>
#define GL_GLEXT_PROTOTYPES
#include "GL/glext.h"
#endif
//GLAPI void APIENTRY glBindBuffer (GLenum target, GLuint buffer);
//GLAPI void APIENTRY glDeleteBuffers (GLsizei n, const GLuint *buffers);
//GLAPI void APIENTRY glGenBuffers (GLsizei n, GLuint *buffers);
//GLAPI GLboolean APIENTRY glIsBuffer (GLuint buffer);
//GLAPI void APIENTRY glBufferData (GLenum target, GLsizeiptr size, const GLvoid *data, GLenum usage);
//GLAPI void APIENTRY glBufferSubData (GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid *data);
//GLAPI void APIENTRY glGetBufferSubData (GLenum target, GLintptr offset, GLsizeiptr size, GLvoid *data);


#undef ccglOrtho
#undef ccglClearDepth
#undef ccglTranslate
#undef ccglGenerateMipmap
#undef ccglGenFramebuffers
#undef ccglBindFramebuffer
#undef ccglFramebufferTexture2D
#undef ccglDeleteFramebuffers
#undef ccglCheckFramebufferStatus

#undef CC_GL_FRAMEBUFFER
#undef CC_GL_FRAMEBUFFER_BINDING
#undef CC_GL_COLOR_ATTACHMENT0
#undef CC_GL_FRAMEBUFFER_COMPLETE

#define ccglOrtho					glOrtho
#define	ccglClearDepth				glClearDepth
#define ccglTranslate				glTranslated

#define ccglGenerateMipmap			glGenerateMipmapEXT
#define ccglGenFramebuffers			glGenFramebuffersEXT
#define ccglBindFramebuffer			glBindFramebufferEXT
#define ccglFramebufferTexture2D	glFramebufferTexture2DEXT
#define ccglDeleteFramebuffers		glDeleteFramebuffersEXT
#define ccglCheckFramebufferStatus	glCheckFramebufferStatusEXT
#define glFrustumf                  glFrustum
#if (__MACH__ != 1)
//declare here while define in CCEGLView_linux.cpp
extern PFNGLGENFRAMEBUFFERSEXTPROC         	glGenFramebuffersEXT;
extern PFNGLDELETEFRAMEBUFFERSEXTPROC      	glDeleteFramebuffersEXT;
extern PFNGLBINDFRAMEBUFFEREXTPROC         	glBindFramebufferEXT;
extern PFNGLCHECKFRAMEBUFFERSTATUSEXTPROC  	glCheckFramebufferStatusEXT;
extern PFNGLFRAMEBUFFERTEXTURE2DEXTPROC    	glFramebufferTexture2DEXT;
extern PFNGLGENERATEMIPMAPEXTPROC          	glGenerateMipmapEXT;

extern PFNGLGENBUFFERSARBPROC 			   	glGenBuffersARB;
extern PFNGLBINDBUFFERARBPROC 				glBindBufferARB;
extern PFNGLBUFFERDATAARBPROC 				glBufferDataARB;
extern PFNGLBUFFERSUBDATAARBPROC 			glBufferSubDataARB;
extern PFNGLDELETEBUFFERSARBPROC 			glDeleteBuffersARB;

#define glGenBuffers                glGenBuffersARB
#define glBindBuffer                glBindBufferARB
#define glBufferData                glBufferDataARB
#define glBufferSubData             glBufferSubDataARB
#define glDeleteBuffers             glDeleteBuffersARB
#endif
#define CC_GL_FRAMEBUFFER			GL_FRAMEBUFFER
#define CC_GL_FRAMEBUFFER_BINDING	GL_FRAMEBUFFER_BINDING
#define CC_GL_COLOR_ATTACHMENT0		GL_COLOR_ATTACHMENT0
#define CC_GL_FRAMEBUFFER_COMPLETE	GL_FRAMEBUFFER_COMPLETE

#define GL_POINT_SPRITE_OES         GL_POINT_SPRITE_ARB
#define GL_COORD_REPLACE_OES        GL_COORD_REPLACE_ARB
#define GL_POINT_SIZE_ARRAY_OES     GL_POINT_SIZE
#endif

#if (CC_TARGET_PLATFORM == CC_PLATFORM_AIRPLAY)
#include <IwGL.h>
#endif

NS_CC_BEGIN;

/*
OpenGL GLU implementation
*/

//typedef float GLfloat;

/** OpenGL gluLookAt implementation */
void CC_DLL gluLookAt(GLfloat fEyeX, GLfloat fEyeY, GLfloat fEyeZ,
               GLfloat fLookAtX, GLfloat fLookAtY, GLfloat fLookAtZ,
               GLfloat fUpX, GLfloat fUpY, GLfloat fUpZ);

/** OpenGL gluPerspective implementation */
void CC_DLL gluPerspective(GLfloat fovy, GLfloat aspect, GLfloat zNear, GLfloat zFar);

NS_CC_END;

#endif // __PLATFOMR_CCGL_H__
