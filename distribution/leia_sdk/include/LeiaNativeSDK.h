
#ifndef LEIA_NATIVE_SDK_H
#define LEIA_NATIVE_SDK_H

#include "LeiaCameraViews.h"
#include <GLES3/gl3.h>

#ifdef __cplusplus
extern "C" {
#endif

enum LeiaShader {
  LEIA_VERTEX_DOF,
  LEIA_FRAGMENT_DOF,
  LEIA_VERTEX_RESERVED_ONE,
  LEIA_FRAGMENT_RESERVED_ONE,
  LEIA_VERTEX_RESERVED_TWO,
  LEIA_FRAGMENT_RESERVED_TWO,
  LEIA_VERTEX_VIEW_INTERLACE,
  LEIA_FRAGMENT_VIEW_INTERLACE,
  LEIA_VERTEX_RESERVED_THREE,
  LEIA_FRAGMENT_RESERVED_THREE,
  LEIA_VERTEX_RESERVED_FOUR,
  LEIA_FRAGMENT_RESERVED_FOUR,
  LEIA_VERTEX_VIEW_SHARPENING,
  LEIA_FRAGMENT_VIEW_SHARPENING,
  LEIA_VERTEX_RESERVED_FIVE,
  LEIA_FRAGMENT_RESERVED_FIVE,
  LEIA_VERTEX_RESERVED_SIX,
  LEIA_FRAGMENT_RESERVED_SIX,
  LEIA_NUMBER_OF_SHADERS
};

const char *leiaGetShader(enum LeiaShader shader, unsigned int *out_size);

void leiaViewInterlace(GLuint *views_as_texture_2d, LeiaCameraData *data,
                       GLuint view_interlace_program, GLuint fbo_target,
                       int screen_width_pixels, int screen_height_pixels,
                       int alignment_offset);
void leiaViewSharpening(GLuint interlaced_texture, LeiaCameraData *data,
                        GLuint view_sharpening_program, GLuint fbo_target,
                        int screen_width_pixels, float a, float b,
                        float normalizer);
void leiaDOF(GLuint rendered_texture, GLuint depth_texture,
             LeiaCameraData *data, GLuint dof_program, GLuint fbo_target,
             float aperture);

GLuint leiaCreateProgram(const char *vert_source, const char *frag_source);

#ifdef __cplusplus
}
#endif

#endif // LEIA_NATIVE_SDK_H
