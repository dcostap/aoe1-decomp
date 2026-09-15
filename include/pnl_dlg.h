#ifndef AOE1_PNL_DLG_H
#define AOE1_PNL_DLG_H

// This header owns TDialogPanel. Its base comes from panel_ez.h.
#include "panel_ez.h"

class TDialogPanel : public TEasy_Panel {
public:
    void* dlg_wnd;
    TPanel* save_parent_child;
    int text_font_id;
    int input_font_id;
    int button_font_id;
    int button_sound_id;

    TDialogPanel(char* panel_name_in);
    virtual ~TDialogPanel();
    virtual int setup(TDrawArea* render_area_in, TPanel* parent_in, long wid_in, long hgt_in, char* info_file_name, long resource_file_id, int allow_shadow_area_in);
    virtual int setup(TDrawArea* render_area_in, TPanel* parent_in, long wid_in, long hgt_in, unsigned char color_in, int allow_shadow_area_in);
    virtual void set_focus(int have_focus_in);
};

typedef char pnl_dlg_tdialog_size_check[
    (sizeof(TDialogPanel) == 0x490) ? 1 : -1];

#endif
