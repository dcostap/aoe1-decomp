#include "TPanel.h"
#include <cstring>

TPanel::TPanel() {
    memset(this, 0, sizeof(TPanel));
}

TPanel::~TPanel() {
}

long TPanel::setup(TDrawArea *render_area_in, TPanel *parent, long x, long y, long wid, long hgt, unsigned char color_in) {
    this->render_area = render_area_in;
    this->parent_panel = parent;
    this->pnl_x = x;
    this->pnl_y = y;
    this->pnl_wid = wid;
    this->pnl_hgt = hgt;
    this->color = color_in;
    this->active = 1;
    this->visible = 1;
    return 1;
}

void TPanel::set_rect(RECT rect) {
    this->pnl_x = rect.left;
    this->pnl_y = rect.top;
    this->pnl_wid = rect.right - rect.left;
    this->pnl_hgt = rect.bottom - rect.top;
}

void TPanel::set_rect(long x, long y, long wid, long hgt) {
    this->pnl_x = x;
    this->pnl_y = y;
    this->pnl_wid = wid;
    this->pnl_hgt = hgt;
}

void TPanel::set_color(unsigned char color_in) {
    this->color = color_in;
}

void TPanel::set_active(int active_in) {
    this->active = active_in;
}
