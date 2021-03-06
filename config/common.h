/* $Id: common.h 2006 2013-07-22 21:09:37Z ddurham $
 * 
 * Copyright (C) 2002 - Anthony Ventimiglia
 * 
 * This file is part of ReZound, an audio editing application.
 * 
 * ReZound is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published
 * by the Free Software Foundation; either version 2 of the License,
 * or (at your option) any later version.
 * 
 * ReZound is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA
 */
#ifndef rezound_COMMON_H
#define rezound_COMMON_H

/* for things like UINT64_C() and PRIx64 from stdint.h */
#define __STDC_CONSTANT_MACROS
#define __STDC_FORMAT_MACROS

/* common.h -- This file will deal with low-level portability problems. It
 * should be includede at the top of every package file. */

//This is added for g++-3.0 and later, which requires it
// TODO work to remove this global namespace directive and support things properly in the .h and .cpp
namespace std {}
using namespace std;

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stddef.h>

#if defined(__clang__)
#	define STATIC_TPL

#elif defined(__GNUC__)
#	ifndef GCC_VERSION
#		define GCC_VERSION (__GNUC__ * 100 + __GNUC_MINOR__)
#	endif

// requirement of static template functions changed in gcc-4.3
#	if GCC_VERSION >= 403
#		define STATIC_TPL
#	else
#		define STATIC_TPL static
#	endif
#endif



/* Redefine PACKAGE TO REZOUND_PACKAGE to clear up possible conflicts with
 * other autoconfed packages 
 */
#ifdef PACKAGE
static const char *REZOUND_PACKAGE=PACKAGE;
# undef PACKAGE
#else
# define REZOUND_PACKAGE "rezound"	
/* Just in case it wasn't defined, the only time this should happen if for some reason someone would decide to compile without an automake built Makefile*/
#endif

/* do the same thing for VERSION */
#ifdef VERSION
static const char *REZOUND_VERSION=VERSION;
# undef VERSION
#else
# define REZOUND_VERSION	"vx.xxx" /* just in case it wasn't defined. */
#endif


/* 
 * According to the gcc info pages this should take care of detecting gcc and
 * define __func__ to __PRETTY_FUNCTION__ if g++ is being used to compile. No
 * configure trickery is needed. Defining here will affect all code since
 * common.h is included all around. 
 */
#ifdef __GNUC__ //Using gcc
# define __func__ __PRETTY_FUNCTION__
#else // not gcc
/*
 * I'm not sure if I should define this to __func__ or undefine it, this is
 * redundant, but I put it here to make it obvious, so if we'd rather undefine
 * it, it stands out here. 
 */
# define __func__ __func__
#endif //__GNUC__

/* include code that determines the platform, and may supply missing function implementations */
#include "platform/platform.h"

/* determine if pitch/tempo changing is available */
#ifdef HAVE_LIBSOUNDTOUCH
	#define AVAIL_PITCH_CHANGE
	#define AVAIL_TEMPO_CHANGE
#endif

/*
 * It is not good to simply use bool==bool because anything non-zero is seen as true
 * which wouldn't equate.  This returns true iff both are non-zero or both are zero
 */
static bool compareBool(int a,int b) { return (a && b) || (!a && !b); }



/* 
 * Include this now so that it can't be included later and then the #define gettext(a)-to-nothing 
 * below won't mutate the header file's declaration 
 */
#ifdef HAVE_LIBINTL_H
	#include <libintl.h>
#endif 

#ifdef ENABLE_NLS
	/* this avoids having gettext("") return junk instead of a simple "" */
	#define gettext(String) ((String)==NULL ? NULL : ( (String)[0]==0 ? "" : gettext(String) ))
	#define _(String) gettext (String)
#else
	#define _(String) String
	#define gettext(String) String
#endif

// NOOP for gettext
#define N_(String) String


#endif /* COMMON_H */
