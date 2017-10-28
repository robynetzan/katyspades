#include <GL/gl.h>
#include <GL/glu.h>

#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <float.h>
#include <stdio.h>
#include "GL/glext.h"

#include "GLFW/glfw3.h"

#include "lodepng/lodepng.h"

#include <enet/enet.h>
#include "libdeflate.h"

#ifdef _WIN32
#define OS_WINDOWS
#endif

#ifdef __linux__
#define OS_LINUX
#endif

#ifdef DEVICE_RASPBERRYPI
#define OS_LINUX
#endif

#ifndef min
#define min(a,b) ((a)<(b)?(a):(b))
#endif
#ifndef max
#define max(a,b) ((a)>(b)?(a):(b))
#endif

typedef unsigned char boolean;
#define true 1
#define false 0

#define rgb(r,g,b)	(((b)<<16)|((g)<<8)|(r))
#define red(col)	((col)&0xFF)
#define green(col)	(((col)>>8)&0xFF)
#define blue(col)	(((col)>>16)&0xFF)


#define PI			3.1415F
#define DOUBLEPI	(PI*2.0F)
#define HALFPI		(PI*0.5F)
#define EPSILON		0.005F

#include "sound.h"
#include "chunk.h"
#include "map.h"
#include "model.h"
#include "file.h"
#include "camera.h"
#include "aabb.h"
#include "particle.h"
#include "network.h"
#include "player.h"
#include "grenade.h"
#include "cameracontroller.h"
#include "font.h"
#include "texture.h"
#include "weapon.h"

unsigned char key_map[512];
unsigned char button_map[3];
unsigned char draw_outline;

PFNGLPOINTPARAMETERFVPROC glPointParameterfv;
PFNGLPOINTPARAMETERFPROC glPointParameterf;
PFNGLCREATESHADERPROC glCreateShader;
PFNGLSHADERSOURCEPROC glShaderSource;
PFNGLCOMPILESHADERPROC glCompileShader;
PFNGLCREATEPROGRAMPROC glCreateProgram;
PFNGLATTACHSHADERPROC glAttachShader;
PFNGLLINKPROGRAMPROC glLinkProgram;
PFNGLUSEPROGRAMPROC glUseProgram;
PFNGLGETUNIFORMLOCATIONPROC glGetUniformLocation;
PFNGLUNIFORM1FPROC glUniform1f;
PFNGLUNIFORM4FPROC glUniform4f;
PFNGLUNIFORM1IPROC glUniform1i;
PFNGLTEXIMAGE3DPROC glTexImage3D;


void matrix_pointAt(float dx, float dy, float dz);

extern struct RENDER_OPTIONS {
	boolean opengl14;
	boolean color_correction;
	boolean shadow_entities;
	boolean ambient_occlusion;
	float render_distance;
	int window_width;
	int window_height;
	unsigned char multisamples;
	boolean player_arms;
	boolean fullscreen;
} settings;

#define CHAT_NO_INPUT	0
#define CHAT_ALL_INPUT	1
#define CHAT_TEAM_INPUT	2

extern int chat_input_mode;

extern char chat[10][256];
extern unsigned int chat_color[10];
void chat_add(unsigned int color, char* msg);