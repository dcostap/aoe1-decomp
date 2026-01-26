#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/screens.h"
#include "../include/custom_debug.h"
#include "../include/TDrawArea.h"

// TEasy_Panel stubs
TEasy_Panel::TEasy_Panel(char* name) : TPanel(name) {
    memset(easy_panel_pad, 0, sizeof(easy_panel_pad));
}

long TEasy_Panel::setup(TDrawArea* render_area, TPanel* parent, char* info_file, long p4, int p5, long p6, long p7, long p8, long p9, long p10) {
    CUSTOM_DEBUG_LOG_FMT("TEasy_Panel::setup: %s", info_file);
    // TEasy_Panel setup often calls TPanel::setup with info-file derived rects
    // For now, call TPanel::setup with some defaults if parent provides them
    return TPanel::setup(render_area, parent, 0, 0, 640, 480, 0);
}

void TEasy_Panel::set_ideal_size(long w, long h) {}

int TEasy_Panel::create_button(TPanel* parent, TButtonPanel** btn, char* name, int id, int x, int y, int w, int h, int p9, int p10, int p11) {
    CUSTOM_DEBUG_LOG_FMT("TEasy_Panel::create_button: id=%d, name='%s', x=%d, y=%d, w=%d, h=%d", id, name ? name : "NULL", x, y, w, h);
    if (btn) {
        *btn = new TButtonPanel(); 
        if (*btn) {
            int scaled_x = x;
            int scaled_y = y;
            int scaled_w = w;
            int scaled_h = h;

            if (this->render_area) {
                scaled_x = (x * this->render_area->Width) / 640;
                scaled_y = (y * this->render_area->Height) / 480;
                scaled_w = (w * this->render_area->Width) / 640;
                scaled_h = (h * this->render_area->Height) / 480;
                CUSTOM_DEBUG_LOG_FMT("  Scaled: x=%d, y=%d, w=%d, h=%d (area=%dx%d)", scaled_x, scaled_y, scaled_w, scaled_h, this->render_area->Width, this->render_area->Height);
            }

            (*btn)->setup(this->render_area, parent, scaled_x, scaled_y, scaled_w, scaled_h, (TButtonPanel::DrawType)p9, nullptr, (TButtonPanel::NotifyType)p10, id);
        }
    }
    return 1;
}

int TEasy_Panel::create_text(TPanel* parent, TTextPanel** txt, int res_id, int x, int y, int w, int h, int p8, int p9, int p10) {
    if (txt) {
         *txt = new TTextPanel();
         // TODO: setup text
    }
    return 1;
}

// TScreenPanel
TScreenPanel::TScreenPanel(char* name) : TEasy_Panel(name) {}
TScreenPanel::~TScreenPanel() {}

long TScreenPanel::setup(TDrawArea* render_area, char* name, long p3, uchar p4, int p5) {
    CUSTOM_DEBUG_LOG_FMT("TScreenPanel::setup: %s", name);
    return TEasy_Panel::setup(render_area, nullptr, name, p3, p4, 0, 0, 0, 0, p5);
}
