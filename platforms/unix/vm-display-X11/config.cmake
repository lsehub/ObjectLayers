SET (${plugin}_sources ${unix}/${plugin}/sqUnixX11.c ${unix}/${plugin}/sqUnixMozilla.c)

IF (NOT X11_FOUND)
  PLUGIN_DISABLE ()
ELSE ()
  SET (USE_X11 1)
  IF (X11_Xext_FOUND)
    SET (HAVE_LIB_XEXT 1)
    CHECK_LIBRARY_EXISTS (Xext XShmAttach ${X11_LIBRARY_DIR} USE_XSHM)
  ENDIF ()
  CHECK_INCLUDE_FILE (X11/extensions/Xrender.h HAVE_X11_EXTENSIONS_XRENDER_H -I${X11_INCLUDE_DIR})
  IF (HAVE_X11_EXTENSIONS_XRENDER_H)
    CHECK_LIBRARY_EXISTS (Xrender XRenderQueryVersion ${X11_LIBRARY_DIR} HAVE_LIB_XRENDER)
  ENDIF (HAVE_X11_EXTENSIONS_XRENDER_H)
  IF (OPENGL_FOUND)
    CHECK_INCLUDE_FILE (GL/gl.h HAVE_GL_GL_H -I${X11_INCLUDE_DIR})
    CHECK_INCLUDE_FILE (GL/glx.h HAVE_GL_GLX_H -I${X11_INCLUDE_DIR})
    IF (HAVE_GL_GL_H AND HAVE_GL_GLX_H)
      SET (USE_X11_GLX 1)
    ENDIF (HAVE_GL_GL_H AND HAVE_GL_GLX_H)
  ENDIF (OPENGL_FOUND)
  PLUGIN_INCLUDE_DIRECTORIES (${cross}/plugins/B3DAcceleratorPlugin ${cross}/plugins/FilePlugin)
  PLUGIN_INCLUDE_DIRECTORIES (${X11_INCLUDE_DIR} ${OPENGL_INCLUDE_DIR})
  PLUGIN_LINK_LIBRARIES (${X11_LIBRARIES} ${OPENGL_LIBRARIES})
ENDIF ()

CONFIG_DEFINE (USE_X11)
CONFIG_DEFINE (USE_X11_GLX)

CONFIG_DEFINE (HAVE_LIB_XEXT)
CONFIG_DEFINE (HAVE_LIB_XRENDER)

CONFIG_DEFINE (USE_XSHM)

CONFIG_DEFINE (USE_XICFONT_OPTION)
CONFIG_DEFINE (USE_XICFONT_DEFAULT)
CONFIG_DEFINE (USE_XICFONT_RESOURCE)

CHECK_FUNCTION_EXISTS (snprintf	HAVE_SNPRINTF)
CHECK_FUNCTION_EXISTS (__snprintf	HAVE___SNPRINTF)

CONFIG_DEFINE (HAVE_SNPRINTF)
CONFIG_DEFINE (HAVE___SNPRINTF)

CHECK_INCLUDE_FILE (sys/select.h HAVE_SYS_SELECT_H)

CONFIG_DEFINE (HAVE_SYS_SELECT_H)
