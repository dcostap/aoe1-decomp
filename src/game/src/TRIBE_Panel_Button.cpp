#include "../include/TRIBE_Panel_Button.h"
#include <string.h>

TRIBE_Panel_Button::TRIBE_Panel_Button() : TButtonPanel() {
    this->display_garrison = 0;
    this->garrsion_number = 0;
    this->tribe_button_type = 0;
    this->border_pic = nullptr;
    this->color_table = nullptr;
    this->border_frame = 0;
    this->text_msg[0] = '\0';
    this->in_use = 0;
}

TRIBE_Panel_Button::TRIBE_Panel_Button(
    TDrawArea* area,
    TPanel* parent,
    TDigital* sound,
    void* font,
    long font_wid,
    long font_hgt,
    TShape* border_pic_param)
    : TButtonPanel() {
    this->display_garrison = 0;
    this->garrsion_number = 0;
    this->tribe_button_type = 0;
    this->border_pic = border_pic_param;
    this->color_table = nullptr;
    this->border_frame = 0;
    this->text_msg[0] = '\0';
    this->in_use = 0;

    long ok = this->setup(
        area,
        parent,
        0,
        0,
        0,
        0,
        TButtonPanel::DrawClear,
        sound,
        TButtonPanel::NotifyAction,
        -1);
    if (ok == 0) {
        this->error_code = 1;
        return;
    }

    this->set_font(font, font_wid, font_hgt);
}

TRIBE_Panel_Button::~TRIBE_Panel_Button() {}

void TRIBE_Panel_Button::set_text_msg(char* text) {
    if (text == nullptr) {
        this->text_msg[0] = '\0';
        return;
    }

    strncpy(this->text_msg, text, sizeof(this->text_msg));
    this->text_msg[sizeof(this->text_msg) - 1] = '\0';
}
