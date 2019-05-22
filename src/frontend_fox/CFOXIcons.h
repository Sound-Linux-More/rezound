/* script generated source code */
#ifndef __Images_H__
#define __Images_H__
#include "../../config/common.h"

#include <fox/fx.h>

class CFOXIcons
{
public:
        CFOXIcons(FXApp *app);
        virtual ~CFOXIcons();

        FXIcon *getByName(const char *name) const;

	FXIcon *advanced_action_buff;
	FXIcon *advanced_action;
	FXIcon *Constant;
	FXIcon *edit_copy;
	FXIcon *edit_crop;
	FXIcon *edit_cut;
	FXIcon *edit_delete;
	FXIcon *edit_paste;
	FXIcon *edit_redo;
	FXIcon *edit_undo;
	FXIcon *Falling_Sawtooth_Wave___0_1_;
	FXIcon *Falling_Sawtooth_Wave___1_1_;
	FXIcon *file_close;
	FXIcon *file_new;
	FXIcon *file_open;
	FXIcon *file_revert;
	FXIcon *file_save_as;
	FXIcon *file_save;
	FXIcon *GreenCheck1;
	FXIcon *GreenLED1;
	FXIcon *GreenPlus1;
	FXIcon *icon_logo_16;
	FXIcon *icon_logo_32;
	FXIcon *jump_to_beginning;
	FXIcon *jump_to_next_q;
	FXIcon *jump_to_previous_q;
	FXIcon *jump_to_selection;
	FXIcon *logo;
	FXIcon *normal_action_buff;
	FXIcon *normal_action;
	FXIcon *notes;
	FXIcon *OffLED1;
	FXIcon *pause;
	FXIcon *play_all_looped;
	FXIcon *play_all_once;
	FXIcon *play_selection_looped;
	FXIcon *play_selection_once;
	FXIcon *RedLED1;
	FXIcon *RedMinus1;
	FXIcon *RedX1;
	FXIcon *Rising_Sawtooth_Wave___0_1_;
	FXIcon *Rising_Sawtooth_Wave___1_1_;
	FXIcon *Sine_Wave___0_1_;
	FXIcon *Sine_Wave___1_1_;
	FXIcon *stop;
	FXIcon *YellowLED1;
	int dummy;
};

extern CFOXIcons *FOXIcons;

#endif
