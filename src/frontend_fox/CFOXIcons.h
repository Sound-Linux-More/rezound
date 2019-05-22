/* script generated source code */
#ifndef __CFOXIcons_H__
#define __CFOXIcons_H__
#include "../../config/common.h"

#include <fox/fx.h>

class CFOXIcons
{
public:
        CFOXIcons(FXApp *app);
        virtual ~CFOXIcons();

        FXIcon *getByName(const char *name) const;

	FXIcon *Constant;
	FXIcon *edit_copy;
	FXIcon *edit_crop;
	FXIcon *edit_cut;
	FXIcon *edit_delete;
	FXIcon *edit_paste;
	FXIcon *edit_redo;
	FXIcon *edit_undo;
	FXIcon *exit;
	FXIcon *explain;
	FXIcon *Falling_Sawtooth_Wave___0_1_;
	FXIcon *Falling_Sawtooth_Wave___1_1_;
	FXIcon *file_close;
	FXIcon *file_new;
	FXIcon *file_open;
	FXIcon *file_revert;
	FXIcon *file_save_as;
	FXIcon *file_save;
	FXIcon *filter_bandpass;
	FXIcon *filter_custom;
	FXIcon *filter_highpass;
	FXIcon *filter_lowpass;
	FXIcon *filter_notch;
	FXIcon *graph_clear;
	FXIcon *graph_horz_flip;
	FXIcon *graph_smooth;
	FXIcon *graph_vert_flip;
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
	FXIcon *record;
	FXIcon *RedLED1;
	FXIcon *RedMinus1;
	FXIcon *RedX1;
	FXIcon *Rising_Sawtooth_Wave___0_1_;
	FXIcon *Rising_Sawtooth_Wave___1_1_;
	FXIcon *shuttle_backward;
	FXIcon *shuttle_forward;
	FXIcon *shuttle_normal;
	FXIcon *Sine_Wave___0_1_;
	FXIcon *Sine_Wave___1_1_;
	FXIcon *small_jump_to_beginning;
	FXIcon *small_jump_to_next_q;
	FXIcon *small_jump_to_previous_q;
	FXIcon *small_jump_to_selection;
	FXIcon *small_pause;
	FXIcon *small_play_all_looped;
	FXIcon *small_play_all_once;
	FXIcon *small_play_selection_looped;
	FXIcon *small_play_selection_once;
	FXIcon *small_record;
	FXIcon *small_small_record;
	FXIcon *small_stop;
	FXIcon *stop;
	FXIcon *YellowLED1;
	FXIcon *zoom_fit;
	FXIcon *zoom_in;
	FXIcon *zoom_out_full;
	FXIcon *zoom_out;
	int dummy;
};

extern CFOXIcons *FOXIcons;

#endif
