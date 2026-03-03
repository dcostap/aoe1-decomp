#include "../include/TRIBE_Panel_Text_Line.h"

#include "../include/TDrawArea.h"

#include <cstring>
#include <new>
#include <windows.h>

// TODO: MISSING_FUNC - Class destructor symbol TRIBE_Panel_Text_Line::~TRIBE_Panel_Text_Line (vt[0]) from bucket_0520 is not implemented as a class method in this TU; only C-style ctor/draw helpers are present. [decomp: bucket_0520.decomp @ 0x00520E20]

// Fully verified. Source of truth: tpnl_txl.cpp.decomp @ 0x00520D70
TRIBE_Panel_Text_Line* tpnl_txl_ctor_00520D70(TRIBE_Panel_Text_Line* this_, TDrawArea* param_1, TPanel* param_2, void* param_3) {
    new (this_) TPanel();
    this_->font = param_3;
    this_->text_type = 0;
    this_->text[0] = '\0';
    this_->id = 0;

    if (this_->TPanel::setup(param_1, param_2, 0, 0, 0, 0, 0) == 0) {
        this_->error_code = 1;
    }
    return this_;
}

// Fully verified. Source of truth: tpnl_txl.cpp.decomp @ 0x00520E30
void tpnl_txl_set_info_00520E30(TRIBE_Panel_Text_Line* this_, uchar param_1, char* param_2, long param_3) {
    if (this_ == nullptr) {
        return;
    }

    if (param_2 == nullptr) {
        param_2 = (char*)"";
    }

    if (param_1 == this_->text_type && std::strcmp(this_->text, param_2) == 0 && param_3 == this_->id) {
        return;
    }

    this_->text_type = param_1;
    std::strncpy(this_->text, param_2, sizeof(this_->text) - 1);
    this_->text[sizeof(this_->text) - 1] = '\0';
    this_->id = param_3;
    this_->set_redraw(TPanel::Redraw);
}

// Fully verified. Source of truth: tpnl_txl.cpp.decomp @ 0x00520ED0
void tpnl_txl_draw_00520ED0(TRIBE_Panel_Text_Line* this_) {
    if (this_ == nullptr || this_->active == 0 || this_->visible == 0 || this_->render_area == nullptr) {
        return;
    }

    if (this_->parent_panel != nullptr) {
        this_->parent_panel->draw_rect(&this_->render_rect);
    }

    this_->draw_setup(0);
    HDC dc = (HDC)this_->render_area->GetDc((char*)"tpnl_txl::draw");
    if (dc != nullptr) {
        HGDIOBJ old_font = SelectObject(dc, (HGDIOBJ)this_->font);
        SetBkMode(dc, 1);
        SetTextColor(dc, 0);
        if (this_->text[0] != '\0') {
            TextOutA(dc, this_->pnl_x, this_->pnl_y, this_->text, (int)std::strlen(this_->text));
        }
        SelectObject(dc, old_font);
        this_->render_area->ReleaseDc((char*)"tpnl_txl::draw");
    }
    this_->draw_finish();
}
