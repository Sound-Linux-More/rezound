/* 
 * Copyright (C) 2002 - David W. Durham
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

#include "FXLFOParamValue.h"

#include <istring>
#include <stdexcept>

#include <CNestedDataFile/CNestedDataFile.h>
#define DOT (CNestedDataFile::delimChar)

#include "FXConstantParamValue.h"
#include "CFOXIcons.h"

#include "utils.h"

/*
	- This is the LFO selection widget used over and over by ReZound on action dialogs

	- NOTE: I am using FXListBox's itemData point to store indexes into the LFO 
	  registry rather than just in the index of the item in the FXListBox because 
	  sometimes I exclude bipolar LFOs, which makes the index off.
*/

FXDEFMAP(FXLFOParamValue) FXLFOParamValueMap[]=
{
	//Message_Type		ID					Message_Handler
	FXMAPFUNC(SEL_COMMAND,	FXLFOParamValue::ID_LFO_TYPE_COMBOBOX,	FXLFOParamValue::onLFOTypeChange),
};

FXIMPLEMENT(FXLFOParamValue,FXVerticalFrame,FXLFOParamValueMap,ARRAYNUMBER(FXLFOParamValueMap))

static const double interpretValue(const double x,const int s) { return(x*s); }
static const double uninterpretValue(const double x,const int s) { return(x/s); }

FXLFOParamValue::FXLFOParamValue(FXComposite *p,int opts,const char *title,const string ampUnits,const string ampTitle,const double maxAmp,const string freqUnits,const double maxFreq,const bool hideBipolarLFOs) :
	FXVerticalFrame(p,opts|FRAME_RAISED |LAYOUT_FILL_X|LAYOUT_FILL_Y,0,0,0,0, 2,2,2,2, 0,2),

	titleLabel(new FXLabel(this,title,NULL,LABEL_NORMAL|LAYOUT_CENTER_X)),
	sliders(new FXHorizontalFrame(this,LAYOUT_FILL_X|LAYOUT_FILL_Y, 0,0,0,0, 0,0,0,0, 0,0)),
		amplitudeSlider(new FXConstantParamValue(interpretValue,uninterpretValue,min((int)maxAmp,1),(int)maxAmp,min((int)maxAmp,1),false,sliders,LAYOUT_CENTER_X,ampTitle.c_str())),
		frequencySlider(new FXConstantParamValue(interpretValue,uninterpretValue,min((int)maxFreq,1),(int)maxFreq,min((int)maxFreq,1),false,sliders,LAYOUT_CENTER_X,"Frequency")),
		phaseSlider(new FXConstantParamValue(interpretValue,uninterpretValue,360,360,360,true,sliders,LAYOUT_CENTER_X,"Phase")),
	LFOTypeComboBox(new FXListBox(this,16,this,ID_LFO_TYPE_COMBOBOX,FRAME_SUNKEN|FRAME_THICK|LISTBOX_NORMAL|LAYOUT_CENTER_X|LAYOUT_FIX_WIDTH,0,0,180,0)),

	textFont(getApp()->getNormalFont())
{
	// create a smaller font to use 
        FXFontDesc d;
        textFont->getFontDesc(d);
        d.size-=10;
        textFont=new FXFont(getApp(),d);

	// allow this to be hidden (cause varied repeat doesn't need it)
	if(ampTitle=="")
		amplitudeSlider->hide();

	amplitudeSlider->setUnits(ampUnits.c_str());
	frequencySlider->setUnits(freqUnits.c_str());
	phaseSlider->setUnits("deg");

	// something initial
	amplitudeSlider->setValue(1.0);
	frequencySlider->setValue(1.0);
	phaseSlider->setValue(90.0);

		// ??? could seriously add icons for these
	for(size_t t=0;t<gLFORegistry.getCount();t++)
	{
		if(!hideBipolarLFOs || !gLFORegistry.isBipolar(t))
		{
			LFOTypeComboBox->appendItem(gLFORegistry.getName(t).c_str(),FOXIcons->getByName(gLFORegistry.getName(t).c_str()),(void *)t);
		}
	}
	LFOTypeComboBox->setCurrentItem(0);

	onLFOTypeChange(NULL,0,NULL);

	setFontOfAllChildren(this,textFont);
}

FXLFOParamValue::~FXLFOParamValue()
{
	delete textFont;
}

long FXLFOParamValue::onLFOTypeChange(FXObject *sender,FXSelector sel,void *ptr)
{
	if((size_t)(LFOTypeComboBox->getItemData(LFOTypeComboBox->getCurrentItem()))==0)
	{ // constant needs only to have an amplitude setting
		amplitudeSlider->enable();
		frequencySlider->disable();
		phaseSlider->disable();
	}
	else
	{
		amplitudeSlider->enable();
		frequencySlider->enable();
		phaseSlider->enable();
	}
	return(1);
}

const CLFODescription FXLFOParamValue::getValue()
{
	//validateRange();
	return(CLFODescription(
		amplitudeSlider->getValue(),
		frequencySlider->getValue(),
		phaseSlider->getValue(),
		gLFORegistry.getIndexByName(LFOTypeComboBox->getItemText(LFOTypeComboBox->getCurrentItem()).text())
	));

}

const string FXLFOParamValue::getTitle() const
{
	return(titleLabel->getText().text());
}

/*
void FXLFOParamValue::setTipText(const FXString &text)
{
	titleLabel->setTipText(text);	
	valueTextBox->setTipText(text);
	valueSpinner->setTipText(text);
}

FXString FXLFOParamValue::getTipText() const
{
	return(titleLabel->getTipText());	
}
*/

void FXLFOParamValue::readFromFile(const string &prefix,CNestedDataFile *f)
{
	const string key=prefix+DOT+getTitle();
	const string LFOName=f->keyExists((key+DOT+"name").c_str()) ? f->getValue((key+DOT+"name").c_str()) : "Constant";
	try
	{
		const size_t LFOIndex=gLFORegistry.getIndexByName(LFOName);
		for(int t=0;t<LFOTypeComboBox->getNumItems();t++)
		{
			if(((size_t)LFOTypeComboBox->getItemData(t))==LFOIndex)
			{
				LFOTypeComboBox->setCurrentItem(t);
				break;
			}
		}
	}
	catch(...)
	{
		LFOTypeComboBox->setCurrentItem(0); // default to the first position which should be sine
	}
	onLFOTypeChange(NULL,0,NULL);

	amplitudeSlider->readFromFile(key,f);
	frequencySlider->readFromFile(key,f);
	phaseSlider->readFromFile(key,f);
}

void FXLFOParamValue::writeToFile(const string &prefix,CNestedDataFile *f)
{
	const string key=prefix+DOT+getTitle();
	f->createKey((key+DOT+"name").c_str(),LFOTypeComboBox->getItemText(LFOTypeComboBox->getCurrentItem()).text());

	amplitudeSlider->writeToFile(key,f);
	frequencySlider->writeToFile(key,f);
	phaseSlider->writeToFile(key,f);
}


