# ReZound frontend_fox/Makefile.am Written by Anthony Ventimiglia
## Process this file with automake to create Makefile.in
##
##
##   Copyright (C) 2002 - Anthony Ventimiglia
##   
##   This file is part of ReZound, an audio editing application, but
##   could be used for other applications which could use the PoolFile
##   class's functionality.
##   
##   PoolFile is free software; you can redistribute it and/or modify
##   it under the terms of the GNU General Public License as published
##   by the Free Software Foundation; either version 2 of the License,
##   or (at your option) any later version.
##   
##   PoolFile is distributed in the hope that it will be useful, but
##   WITHOUT ANY WARRANTY; without even the implied warranty of
##   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
##   GNU General Public License for more details.
##   
##   You should have received a copy of the GNU General Public License
##   along with this program; if not, write to the Free Software
##   Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA
################################################################################

include $(top_srcdir)/config/am_include.mk

noinst_LTLIBRARIES=libfrontend.la
libfrontend_la_SOURCES= \
			CFOXIcons.cpp \
			CActionMenuCommand.cpp \
			CChannelSelectDialog.cpp \
			CCrossfadeEdgesDialog.cpp \
			CActionParamDialog.cpp \
			CCueDialog.cpp \
			CCueListDialog.cpp \
			CMainWindow.cpp \
			CNewSoundDialog.cpp \
			CRecordDialog.cpp \
			CRecordMacroDialog.cpp \
			CMacroActionParamsDialog.cpp \
			CPasteChannelsDialog.cpp \
			CProgressDialog.cpp \
			CSoundFileManager.cpp \
			CFrontendHooks.cpp \
			CSoundWindow.cpp \
			CMetersWindow.cpp \
			CStatusComm.cpp \
			CUserNotesDialog.cpp \
			CRezSaveParametersDialog.cpp \
			CRawDialog.cpp \
			CVoxDialog.cpp \
			COggDialog.cpp \
			CMp3Dialog.cpp \
			CJACKPortChoiceDialog.cpp \
			CMIDIDumpSampleIdDialog.cpp \
			ClibaudiofileSaveParametersDialog.cpp \
			drawPortion.cpp \
			FileActionDialogs.cpp \
			EditActionDialogs.cpp \
			EffectActionDialogs.cpp \
			FilterActionDialogs.cpp \
			GenerateActionDialogs.cpp \
			RemasterActionDialogs.cpp \
			LoopingActionDialogs.cpp \
			CAboutDialog.cpp \
			FXConstantParamValue.cpp \
			FXTextParamValue.cpp \
			FXDiskEntityParamValue.cpp \
			FXComboTextParamValue.cpp \
			FXCheckBoxParamValue.cpp \
			FXGraphParamValue.cpp \
			FXLFOParamValue.cpp \
			FXPluginRoutingParamValue.cpp \
			FXModalDialogBox.cpp \
			FXRezWaveView.cpp \
			FXWaveScrollArea.cpp \
			FXWaveCanvas.cpp \
			CLADSPAActionDialog.cpp \
			CKeyBindingsDialog.cpp \
			rememberShow.cpp \
			settings.cpp

## bin_PROGRAMS is the macro that tells automake the name of the programs to
## install in the bin directory (/usr/local/bin) by default. By setting
## --prefix= at configure time the user can change this (eg: ./configure
## --prefix=/usr will install ReZound under /usr/bin/ReZound )
bin_PROGRAMS=rezound

## for every name listed under bin_PROGRAMS, you have a prog_SOURCES. This lists
## all the sources in the current directory that are used to build ReZound.
rezound_SOURCES= main.cpp 

## ReZound_LDADD is a list of extras to pass at link time. All the objects
## created by the above ReZound_SOURCES are automatically linked in, so here I
## list object files from other directories as well as flags passed to the
## linker. By using convienience libraries, it makes this part much easier. 
## It's up to each subdirectory's Makefile to build it's .la library.
## notice we use $(top_builddir) for the modules. This allows building in a 
## separate directory
_rezound_LDADD= libfrontend.la\
	$(top_builddir)/src/backend/libbackend.la \
	$(top_builddir)/src/backend/File/libFile.la \
	$(top_builddir)/src/backend/Edits/libEdits.la \
	$(top_builddir)/src/backend/Effects/libEffects.la \
	$(top_builddir)/src/backend/Filters/libFilters.la \
	$(top_builddir)/src/backend/Looping/libLooping.la \
	$(top_builddir)/src/backend/Remaster/libRemaster.la \
	$(top_builddir)/src/backend/Generate/libGenerate.la \
	@MAYBE_LADSPA_LIB@ \
	$(top_builddir)/src/misc/CNestedDataFile/libmiscCN.la \
	$(top_builddir)/src/PoolFile/libPoolFile.la \
	$(top_builddir)/src/misc/libmisc.la

rezound_LDADD=$(_rezound_LDADD) @FOX_LIBS@

## if I don't do this, automake leaves out @abc@ vars when creating the rezound_DEPENDENCES value
## so changes to the LADSPA lib (that may or may not be built) don't cause a re-link
rezound_DEPENDENCIES=$(_rezound_LDADD)


AM_CXXFLAGS=@FOX_CFLAGS@

noinst_HEADERS=\
	CFOXIcons.h \
	fox_compat.h \
	CActionMenuCommand.h \
	CChannelSelectDialog.h \
	CCrossfadeEdgesDialog.h \
	CActionParamDialog.h \
	CCueDialog.h \
	CCueListDialog.h \
	CMainWindow.h \
	CNewSoundDialog.h \
	CRecordDialog.h \
	CRecordMacroDialog.h \
	CMacroActionParamsDialog.h \
	CPasteChannelsDialog.h \
	CProgressDialog.h \
	CSoundFileManager.h \
	CFrontendHooks.h \
	CSoundWindow.h \
	CMetersWindow.h \
	CStatusComm.h \
	CUserNotesDialog.h \
	CRezSaveParametersDialog.h \
	CRawDialog.h \
	CVoxDialog.h \
	COggDialog.h \
	CMp3Dialog.h \
	CJACKPortChoiceDialog.h \
	CMIDIDumpSampleIdDialog.h \
	ClibaudiofileSaveParametersDialog.h \
	FileActionDialogs.h \
	EditActionDialogs.h \
	EffectActionDialogs.h \
	FilterActionDialogs.h \
	GenerateActionDialogs.h \
	RemasterActionDialogs.h \
	LoopingActionDialogs.h \
	CAboutDialog.h \
	FXConstantParamValue.h \
	FXPluginRoutingParamValue.h \
	FXTextParamValue.h \
	FXDiskEntityParamValue.h \
	FXComboTextParamValue.h \
	FXCheckBoxParamValue.h \
	FXGraphParamValue.h \
	FXLFOParamValue.h \
	FXModalDialogBox.h \
	FXRezWaveView.h \
	FXWaveScrollArea.h \
	FXWaveCanvas.h \
	CLADSPAActionDialog.h \
	CKeyBindingsDialog.h \
	FXPopupHint.h \
	FXBackBufferedCanvas.h \
	drawPortion.h \
	rememberShow.h \
	custom_cursors.h \
	utils.h \
	settings.h 

EXTRA_DIST=convert_images.sh


distclean-compile: 
	-rm -f CFOXIcons.h CFOXIcons.cpp


## Commented out with namechange

## # Have some rules to manage creating and removing a soft-link 
## # called 'rezound' to the 'ReZound' binary because lower case 
## # is the norm.
## LINK_NAME=rezound
## 
## install-exec-local:
## 	cd $(bindir) && rm -f $(LINK_NAME) && $(LN_S) ReZound $(LINK_NAME)
## uninstall-local:
## 	cd $(bindir) && rm -f $(LINK_NAME)
## 
