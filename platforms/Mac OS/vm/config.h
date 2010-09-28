/* config.h.  Generated by configure.  */
/* config.h.in -- template for config.h			-*- C -*-
 *
 *   Copyright (C) 1996-2005 by Ian Piumarta and other authors/contributors
 *                              listed elsewhere in this file.
 *   All rights reserved.
 *
 *   This file is part of Unix Squeak.
 *
 *      You are NOT ALLOWED to distribute modified versions of this file
 *      under its original name.  If you modify this file then you MUST
 *      rename it before making your modifications available publicly.
 *
 *   This file is distributed in the hope that it will be useful, but WITHOUT
 *   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 *   FITNESS FOR A PARTICULAR PURPOSE.
 *
 *   You may use and/or distribute this file ONLY as part of Squeak, under
 *   the terms of the Squeak License as described in `LICENSE' in the base of
 *   this distribution, subject to the following additional restrictions:
 *
 *   1. The origin of this software must not be misrepresented; you must not
 *      claim that you wrote the original software.  If you use this software
 *      in a product, an acknowledgment to the original author(s) (and any
 *      other contributors mentioned herein) in the product documentation
 *      would be appreciated but is not required.
 *
 *   2. You must not distribute (or make publicly available by any
 *      means) a modified copy of this file unless you first rename it.
 *
 *   3. This notice must not be removed or altered in any source distribution.
 *
 *   Using (or modifying this file for use) in any context other than Squeak
 *   changes these copyright conditions.  Read the file `COPYING' in the
 *   directory `platforms/unix/doc' before proceeding with any such use.
 */

/* Author: Ian.Piumarta@squeakland.org
 *
 * Last edited: 2005-03-28 22:47:17 by piumarta on emilia.local
 */

#ifndef __sq_config_h
#define __sq_config_h

/* explicit image width */

#define	HAVE_INTERP_H 1

/* package options */

#define	USE_X11 1
/* #undef	USE_X11_GLX */
#define	USE_QUARTZ 1
#define	USE_QUARTZ_CGL 1
/* #undef	USE_RFB */

/* libraries */

/* #undef	HAVE_LIBX11 */
#define	HAVE_LIBXEXT 1
/* #undef	HAVE_LIBDL */
#define	HAVE_DYLD 1
/* #undef	HAVE_LIBFFI */
/* #undef	HAVE_ICONV */

/* #undef	USE_AUDIO_NONE */
/* #undef	USE_AUDIO_SUN */
/* #undef	USE_AUDIO_NAS */
/* #undef	USE_AUDIO_OSS */
/* #undef	USE_AUDIO_MACOSX */
/* #undef	OSS_DEVICE */

/* header files */

#define	HAVE_UNISTD_H 1
/* #undef	NEED_GETHOSTNAME_P */

#define	HAVE_DIRENT_H 1
/* #undef	HAVE_SYS_NDIR_H */
/* #undef	HAVE_SYS_DIR_H */
/* #undef	HAVE_NDIR_H */

#if MAC_OS_X_VERSION_MIN_REQUIRED < MAC_OS_X_VERSION_10_3
#undef	HAVE_DLFCN_H 
#else
#define	HAVE_DLFCN_H 1
#endif

#define	HAVE_ICONV_H 1

#define	HAVE_SYS_TIME_H 1
#define	TIME_WITH_SYS_TIME 1

#define	HAVE_SYS_FILIO_H 1

/* #undef	HAVE_SYS_AUDIOIO_H */
/* #undef	HAVE_SUN_AUDIOIO_H */

/* #undef	HAVE_PTY_H */
#define	HAVE_UTIL_H 1
/* #undef	HAVE_LIBUTIL_H */
/* #undef	HAVE_STROPTS_H */

/* #undef	HAVE_GL_GL_H */
#define	HAVE_OPENGL_GL_H 1

/* #undef	NEED_SUNOS_H */

/* system calls/library functions */

#define	AT_EXIT atexit

#define	HAVE_TZSET 1

#define	HAVE_OPENPTY 1
/* #undef	HAVE_UNIX98_PTYS */

#define	HAVE_SNPRINTF 1
/* #undef	HAVE___SNPRINTF */

#define	HAVE_MMAP 1

#define	HAVE_DYLD 1

#define	HAVE_LANGINFO_CODESET 1

#define	HAVE_ALLOCA 1
#define	HAVE_ALLOCA_H 1

#define	HAVE_UNSETENV 1

/* widths of primitive types */

#define	SIZEOF_INT 4
#define	SIZEOF_LONG 4
#define	SIZEOF_LONG_LONG 8
#define	SIZEOF_VOID_P 4

/* structures */

#define	HAVE_TM_GMTOFF 1
#define	HAVE_TIMEZONE 1

/* typedefs */

/* #undef	size_t */

#define	squeakInt64 long long

/* architecture */

#define	OS_TYPE "unix"

/* #undef	VM_HOST_VENDOR */
#define	VM_HOST_OS "darwin8.5.0"

#if defined(__BIG_ENDIAN__)
#define	WORDS_BIGENDIAN 1
#define VMENDIANNESS 1
#define	VM_HOST "powerpc-apple-darwin8.5.0"
#define	VM_HOST_CPU "powerpc"
#else
#undef	WORDS_BIGENDIAN 
#define VMENDIANNESS 0
#define	VM_HOST "intel-apple-darwin8.5.0"
#define	VM_HOST_CPU "intel"
#define	DOUBLE_WORD_ORDER 1
#define LSB_FIRST 1
#endif

#define HAVE_LIBDL 1
/* #undef	DOUBLE_WORD_ALIGNMENT */
/* #undef	DOUBLE_WORD_ORDER */

/* damage containment */

#define	DARWIN 1

#ifdef NEED_SUNOS_H
# include "sunos.h"
#endif

/* other configured variables */

#define SQ_VERSION "3.8g-6548"
#define VM_VERSION "3.8a-2"
#define VM_LIBDIR "/usr/local/lib/squeak/3.8a-2"
#define VM_MODULE_PREFIX ""
/* #undef VM_DLSYM_PREFIX */
#define VM_X11DIR "/usr/X11R6/lib"

/* avoid dependencies on glibc2.3 */

/* #undef HAVE_FEATURES_H */

#if defined(HAVE_FEATURES_H)
# include "glibc.h"
#endif

#endif /* __sq_config_h */
