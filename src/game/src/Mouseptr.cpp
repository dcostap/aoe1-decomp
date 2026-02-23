#include "../include/TMousePointer.h"
#include "../include/TDrawArea.h"
#include "../include/TDrawSystem.h"
#include "../include/TShape.h"
#include "../include/debug_helpers.h"
#include <string.h>
#include <stdio.h>
#include <windows.h>

// External global
extern TMousePointer* MouseSystem;

static const HRESULT kDDERR_NOCLIPPER = (HRESULT)0x88760238; // DDERR_NOCLIPPER (not in all SDK headers)

TMousePointer::TMousePointer(int p1) {
    // Fully verified. Source of truth: mouseptr.cpp.decomp @ 0x0045AE50
    memset(this, 0, sizeof(TMousePointer));
    this->save_x = -0x7fff;
    this->save_y = -0x7fff;
    this->Mouse_Mode = p1;
    this->cursor_file_id = -1;
    this->cursor_file[0] = '\0';
    this->LastDrawTime = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Mouseptr.cpp", 100) - 0x24;
}

TMousePointer::~TMousePointer() {
    // Fully verified. Source of truth: mouseptr.cpp.decomp @ 0x0045B000
    if (this->Cursor_Shape != nullptr) {
        delete this->Cursor_Shape;
        this->Cursor_Shape = nullptr;
    }
    this->delete_surfaces();
    MouseSystem = nullptr;
}

int TMousePointer::setup(int custom_draw_flag, TDrawArea* draw_area, char* filename, int file_id, int max_cursors) {
    // Fully verified. Source of truth: mouseptr.cpp.decomp @ 0x0045B120
    MouseSystem = this;
    this->custom_draw = custom_draw_flag;
    this->render_area = draw_area;

    if (custom_draw_flag == 0) {
        return 1;
    }

    if (draw_area == nullptr || draw_area->DrawSystem == nullptr) {
        return 0;
    }

    if (draw_area->DrawSystem->DrawType == 1) {
        return 0;
    }

    this->renderSurface = draw_area->DrawSurface;
    this->PrimarySurface = draw_area->DrawSystem->PrimarySurface;
    this->primary_area = draw_area->DrawSystem->PrimaryArea;

    SetCursor(nullptr);

    char file_name[260];
    sprintf(file_name, "%s.slp", filename);

    this->Cursor_Shape = new TShape(file_name, file_id);
    if (this->Cursor_Shape == nullptr) {
        return 0;
    }
    if (this->Cursor_Shape->is_loaded() == 0 || this->Cursor_Shape->FShape == nullptr) {
        return 0;
    }

    this->Max_Cursors = max_cursors;
    if (max_cursors <= 0 || max_cursors >= 0x11) {
        return 0;
    }

    this->Num_Cursors = this->Cursor_Shape->shape_count();
    if (this->Num_Cursors > this->Max_Cursors) {
        return 0;
    }

    if (this->LoadCursors(filename, file_id, 0) == 0) {
        return 0;
    }

    this->set_facet(0);
    this->set_game_facet(0);
    this->Setup = 1;
    return 1;
}

void TMousePointer::set_facet(int facet_index) {
    // Fully verified. Source of truth: mouseptr.cpp.decomp @ 0x0045BE20
    if (-1 < facet_index && facet_index < this->Num_Cursors) {
        this->facet = facet_index;
        Shape_Info* info = this->Cursor_Shape->shape_info;
        this->cWidth = info[facet_index].Width;
        this->cHeight = info[facet_index].Height;
        this->d_top = info[facet_index].Hotspot_Y;
        this->d_left = info[facet_index].Hotspot_X;
        this->d_right = this->cWidth - info[facet_index].Hotspot_X;
        this->d_bottom = this->cHeight - info[facet_index].Hotspot_Y;
    }
}

void TMousePointer::set_game_facet(int facet_index) {
    // Fully verified. Source of truth: mouseptr.cpp.decomp @ 0x0045BE80
    if (-1 < facet_index && facet_index < this->Num_Cursors) {
        this->game_facet = facet_index;
        Shape_Info* info = this->Cursor_Shape->shape_info;
        this->gWidth = info[facet_index].Width;
        this->gHeight = info[facet_index].Height;
        this->g_top = info[facet_index].Hotspot_Y;
        this->g_left = info[facet_index].Hotspot_X;
        this->g_right = this->gWidth - info[facet_index].Hotspot_X;
        this->g_bottom = this->gHeight - info[facet_index].Hotspot_Y;
    }
}

void TMousePointer::set_game_mode(int mode) {
    // Fully verified. Source of truth: mouseptr.cpp.decomp @ 0x0045B290
    this->GameMode = mode;
}

int TMousePointer::in_game_mode() {
    // Fully verified. Source of truth: mouseptr.cpp.decomp @ 0x0045B2C0
    return ((this->GameMode != 0) && (this->GameEnabled != 0)) ? 1 : 0;
}

void TMousePointer::set_game_window(int left, int top, int right, int bottom) {
    // Fully verified. Source of truth: mouseptr.cpp.decomp @ 0x0045B2E0
    this->game_window.left = left;
    this->game_window.top = top;
    this->game_window.right = right;
    this->game_window.bottom = bottom;
}

void TMousePointer::set_game_enable(int enabled) {
    // Source of truth: `src/game/src/Mouseptr.cpp.decomp` (`set_game_enable` @ 0x0045B2A0).
    this->GameEnabled = enabled;
}

int TMousePointer::get_game_enable() {
    // Source of truth: `src/game/src/Mouseptr.cpp.decomp` (`get_game_enable` @ 0x0045B2B0).
    return this->GameEnabled;
}

void TMousePointer::Poll() {
    // Fully verified. Source of truth: mouseptr.cpp.decomp @ 0x0045C010
    IDirectDrawClipper* clipper = nullptr;

    if (this->active != 0 && this->custom_draw != 0 && this->GameMode != 0 && this->GameEnabled != 0) {
        ulong now = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Mouseptr.cpp", 0x42e);
        if (0x21 < now - this->LastDrawTime) {
            int moved = this->update_mouse_position();
            if (moved != 0) {
                this->LastDrawTime = now;

                if (this->Mouse_Mode == 0) {
                    HRESULT hr = this->PrimarySurface->GetClipper(&clipper);
                    if (hr == kDDERR_NOCLIPPER) {
                        hr = DD_OK;
                        clipper = nullptr;
                    }
                    if (hr != DD_OK) {
                        this->LastddError = (long)hr;
                        return;
                    }
                    if (clipper != nullptr) {
                        hr = this->PrimarySurface->SetClipper(nullptr);
                        if (hr != DD_OK) {
                            this->LastddError = (long)hr;
                            return;
                        }
                    }
                }

                if (this->save_area_valid != 0) {
                    HRESULT hr = this->restoreSurface->Blt(&this->restore_rect, this->save_area->DrawSurface,
                        &this->save_rect, DDBLT_WAIT, nullptr);
                    if (hr != DD_OK) {
                        this->LastddError = (long)hr;
                        return;
                    }

                    IDirectDrawSurface* primary = this->PrimarySurface;
                    if (this->restoreSurface != primary) {
                        hr = primary->Blt(&this->restore_rect, this->save_area->DrawSurface,
                            &this->save_rect, DDBLT_WAIT, nullptr);
                        if (hr != DD_OK) {
                            this->LastddError = (long)hr;
                            return;
                        }
                    }
                }

                if (this->MouseOnScreen == 0) {
                    this->save_area_valid = 0;
                } else {
                    tagRECT* ptVar1 = &this->mouse_rect;
                    IDirectDrawSurface* saveSurf = this->save_area->DrawSurface;
                    HRESULT hr = saveSurf->Blt(&this->new_save_rect, this->PrimarySurface, ptVar1, DDBLT_WAIT, nullptr);
                    if (hr != DD_OK) {
                        this->LastddError = (long)hr;
                        this->LastddError = this->GetDDBltError((long)hr);
                        return;
                    }

                    this->restoreSurface = this->PrimarySurface;
                    this->restore_rect = *ptVar1;
                    this->save_rect = this->new_save_rect;
                    this->save_area_valid = 1;

                    if (this->Mouse_Mode == 0) {
                        this->cursors[this->next_facet]->SetTrans(1, '\0');
                        hr = this->PrimarySurface->BltFast((DWORD)ptVar1->left, (DWORD)this->mouse_rect.top,
                            this->cursors[this->next_facet]->DrawSurface, &this->cursor_rect,
                            DDBLTFAST_WAIT | DDBLTFAST_SRCCOLORKEY);
                        if (hr != DD_OK) {
                            this->LastddError = (long)hr;
                            return;
                        }
                    }

                    if (this->Mouse_Mode == 1) {
                        uchar* bits = this->primary_area->Lock((char*)"mouseptr::poll", 1);
                        if (bits != nullptr) {
                            long facet = this->next_facet;
                            Shape_Info* info = this->Cursor_Shape->shape_info;
                             this->Cursor_Shape->shape_draw(this->primary_area,
                                 info[facet].Hotspot_X + ptVar1->left,
                                 this->mouse_rect.top + info[facet].Hotspot_Y,
                                 facet, 0, nullptr);
                            this->primary_area->Unlock((char*)"mouseptr::poll");
                        }
                    }

                    this->last_facet = this->next_facet;
                }

                if (this->Mouse_Mode == 0 && clipper != nullptr) {
                    HRESULT hr = this->PrimarySurface->SetClipper(clipper);
                    if (hr != DD_OK) {
                        this->LastddError = (long)hr;
                        return;
                    }
                }

                this->drawn = 1;
            }
        }
    }
}

// Helper method stubs

int TMousePointer::LoadCursors(char* filename, int file_id, int reload) {
    // Fully verified. Source of truth: mouseptr.cpp.decomp @ 0x0045B310
    int load_ok = 1;

    if (this->Cursor_Shape != nullptr) {
        delete this->Cursor_Shape;
        this->Cursor_Shape = nullptr;
    }

    if (reload == 0) {
        this->cursor_file_id = file_id;
        sprintf(this->cursor_file, "%s.slp", filename);
    }

    this->Cursor_Shape = new TShape(this->cursor_file, this->cursor_file_id);
    if (this->Cursor_Shape == nullptr ||
        this->Cursor_Shape->is_loaded() == 0 ||
        this->Cursor_Shape->FShape == nullptr) {
        return 0;
    }

    this->Num_Cursors = this->Cursor_Shape->shape_count();
    this->Max_CX = 0;
    this->Max_CY = 0;

    long count = this->Num_Cursors;
    if (0 < count) {
        for (long i = 0; i < count; ++i) {
            Shape_Info* info = this->Cursor_Shape->shape_info;
            if (this->Max_CX < info[i].Width) this->Max_CX = (int)info[i].Width;
            if (this->Max_CY < info[i].Height) this->Max_CY = (int)info[i].Height;
        }
    }

    if (this->Max_CX != 0 && this->Max_CY != 0) {
        this->Max_CX = 0x40;
        this->Max_CY = 0x30;

        if (this->save_area != nullptr || this->create_surfaces() != 0) {
            this->set_facet(this->facet);
            this->set_game_facet(this->game_facet);

            if (this->Mouse_Mode != 0) {
                return 1;
            }

            int num = this->Num_Cursors;
            if (num <= this->Max_Cursors) {
                if (0 < num) {
                    for (int i = 0; i < num; ++i) {
                        Shape_Info* info = this->Cursor_Shape->shape_info;
                        if (this->Max_CX < info[i].Width || this->Max_CY < info[i].Height) {
                            return 0;
                        }
                    }
                }

                for (int i = 0; i < this->Max_Cursors; ++i) {
                    TDrawArea* da = this->cursors[i];
                    da->Clear(nullptr, 0);
                    da->SetTrans(1, '\0');

                    if (i < this->Num_Cursors) {
                        uchar* bits = da->Lock((char*)"mouseptr::LoadCursors", 1);
                        if (bits == nullptr) {
                            load_ok = 0;
                        } else {
                            da->FillRect(0, 0, this->Max_CX, this->Max_CY, '\0');
                            Shape_Info* info = this->Cursor_Shape->shape_info;
                             this->Cursor_Shape->shape_draw(da,
                                 info[i].Hotspot_X,
                                 info[i].Hotspot_Y,
                                 (long)i, 0, nullptr);
                            da->Unlock((char*)"mouseptr::LoadCursors");
                        }
                    }
                }

                return load_ok;
            }
        }
    }

    return 0;
}

int TMousePointer::create_surfaces() {
    // Fully verified. Source of truth: mouseptr.cpp.decomp @ 0x0045B5D0
    if (this->custom_draw == 0) {
        return 1;
    }

    if (this->save_area == nullptr && 0 < this->Max_CX && 0 < this->Max_CY) {
        this->save_area = new TDrawArea((char*)"Mouse Save area");
        if (this->save_area == nullptr) {
            return 0;
        }
        if (this->save_area->Init(this->render_area->DrawSystem, nullptr, this->Max_CX, this->Max_CY, 0, 0, 0) == 0) {
            return 0;
        }
    }

    if (this->Mouse_Mode == 0 && 0 < this->Max_Cursors) {
        for (int i = 0; i < this->Max_Cursors; ++i) {
            if (this->cursors[i] == nullptr) {
                char name_buf[32];
                sprintf(name_buf, "Mouse Cursor #%d", i);
                this->cursors[i] = new TDrawArea(name_buf);
                if (this->cursors[i] == nullptr) {
                    return 0;
                }
                if (this->cursors[i]->Init(this->render_area->DrawSystem, nullptr, this->Max_CX, this->Max_CY, 0, 0, 0) == 0) {
                    return 0;
                }
            }
        }
    }

    return 1;
}

void TMousePointer::delete_surfaces() {
    // Fully verified. Source of truth: mouseptr.cpp.decomp @ 0x0045B560
    if (this->custom_draw == 0) {
        return;
    }

    if (this->save_area != nullptr) {
        delete this->save_area;
        this->save_area = nullptr;
    }

    if (0 < this->Max_Cursors) {
        for (int i = 0; i < this->Max_Cursors; ++i) {
            if (this->cursors[i] != nullptr) {
                delete this->cursors[i];
                this->cursors[i] = nullptr;
            }
        }
    }

    this->Num_Cursors = 0;
    this->reset();
}

void TMousePointer::reset() {
    // Assembly at 0x0045BF80
    // Lines 2068-2071
    this->save_area_valid = 0;
    this->drawn = 0;
}

int TMousePointer::Restore_Mouse(TDrawArea* param_1) {
    // Source of truth: Mouseptr.cpp.decomp @ 0x0045B0A0 (TMousePointer::Restore_Mouse).
    if (this->Shutdown == 0) {
        return 0;
    }
    if (this->custom_draw != 0) {
        if (this->Setup == 0) {
            return 0;
        }
        this->render_area = param_1;
        this->renderSurface = param_1->DrawSurface;
        this->PrimarySurface = param_1->DrawSystem->PrimarySurface;
        this->primary_area = param_1->DrawSystem->PrimaryArea;
        if (this->LoadCursors(nullptr, -1, 1) == 0) {
            return 0;
        }
        this->Shutdown = 0;
    }
    return 1;
}

void TMousePointer::center() {
    // Source of truth: mouseptr.cpp.decomp @ 0x0045BF90
    if (this->render_area == nullptr || this->render_area->DrawSystem == nullptr) {
        return;
    }

    TDrawSystem* draw_system = this->render_area->DrawSystem;
    if (draw_system->ScreenMode == 1) {
        RECT win_rect;
        if (GetWindowRect((HWND)draw_system->Wnd, &win_rect) != 0) {
            int center_x = win_rect.left + (win_rect.right - win_rect.left) / 2;
            int center_y = win_rect.top + (win_rect.bottom - win_rect.top) / 2;
            SetCursorPos(center_x, center_y);
        }
        return;
    }

    SetCursorPos(draw_system->ScreenWidth / 2, draw_system->ScreenHeight / 2);
}

void TMousePointer::erase() {
    // Fully verified. Source of truth: mouseptr.cpp.decomp @ 0x0045BD60
    if (((this->active != 0) && (this->custom_draw != 0)) && (this->drawn != 0) && (this->save_area_valid != 0)) {
        IDirectDrawSurface* restore = this->restoreSurface;
        if (restore != nullptr && restore != this->PrimarySurface) {
            HRESULT hr = restore->Blt(&this->restore_rect, this->save_area->DrawSurface, &this->save_rect, DDBLT_WAIT, nullptr);
            if (hr != DD_OK) {
                this->LastddError = (long)hr;
                return;
            }

            if (this->GameMode != 0 && this->GameEnabled != 0) {
                this->save_area_valid = 1;
                this->restoreSurface = this->PrimarySurface;
                return;
            }

            InvalidateRect((HWND)this->render_area->Wnd, &this->restore_rect, FALSE);
            this->save_area_valid = 0;
        }
    }
}

int TMousePointer::update_mouse_position() {
    // Fully verified. Source of truth: mouseptr.cpp.decomp @ 0x0045B760
    if (this->custom_draw == 0) {
        return 0;
    }

    POINT point;
    GetCursorPos(&point);
    if (this->render_area->DrawSystem->ScreenMode == 1) {
        ScreenToClient((HWND)this->render_area->Wnd, &point);
        if (0x8000 < point.x) point.x -= 0x10000;
        if (0x8000 < point.y) point.y -= 0x10000;
    }

    this->mouse_x = point.x;
    this->mouse_y = point.y;

    bool in_game = false;
    if (this->GameMode != 0 && this->GameEnabled != 0 &&
        this->mouse_x >= this->game_window.left &&
        this->mouse_x < this->game_window.right &&
        this->mouse_y >= this->game_window.top &&
        this->mouse_y < this->game_window.bottom) {
        this->next_facet = this->game_facet;
        in_game = true;
    } else {
        this->next_facet = this->facet;
        in_game = false;
    }

    if (this->save_area_valid != 0 &&
        point.x == this->save_x &&
        point.y == this->save_y &&
        this->next_facet == this->last_facet) {
        return 0;
    }

    this->save_x = point.x;
    this->save_y = point.y;

    this->new_save_rect.left = 0;
    this->new_save_rect.top = 0;

    int bottom_delta;
    int right_delta;

    if (in_game) {
        right_delta = this->gWidth;
        this->new_save_rect.right = right_delta;
        this->new_save_rect.bottom = this->gHeight;
        this->mouse_rect.left = (int)this->mouse_x - this->g_left;
        this->mouse_rect.top = (int)this->mouse_y - this->g_top;
        this->mouse_rect.right = this->g_right + (int)this->mouse_x;
        bottom_delta = this->g_bottom;
    } else {
        right_delta = this->cWidth;
        this->new_save_rect.right = right_delta;
        this->new_save_rect.bottom = this->cHeight;
        this->mouse_rect.left = (int)this->mouse_x - this->d_left;
        this->mouse_rect.top = (int)this->mouse_y - this->d_top;
        this->mouse_rect.right = this->d_right + (int)this->mouse_x;
        bottom_delta = this->d_bottom;
    }
    this->mouse_rect.bottom = bottom_delta + (int)this->mouse_y;

    this->cursor_rect = this->new_save_rect;

    int mr_right = this->mouse_rect.right;
    int mr_bottom = this->mouse_rect.bottom;
    if (-1 < mr_right && -1 < mr_bottom) {
        TDrawArea* area = this->render_area;
        int mr_left = this->mouse_rect.left;
        int mr_top = this->mouse_rect.top;
        if (mr_left <= area->Width && mr_top <= area->Height) {
            if (mr_left < 0) {
                this->cursor_rect.left = -mr_left;
                this->mouse_rect.left = 0;
                this->new_save_rect.right = this->new_save_rect.right + mr_left;
            }
            if (area->Width < mr_right) {
                int d = mr_right - area->Width;
                this->cursor_rect.right = this->cursor_rect.right - d;
                this->new_save_rect.right = this->new_save_rect.right - d;
                this->mouse_rect.right = area->Width;
            }
            if (mr_top < 0) {
                this->mouse_rect.top = 0;
                this->cursor_rect.top = -mr_top;
                this->new_save_rect.bottom = this->new_save_rect.bottom + mr_top;
            }
            if (area->Height < mr_bottom) {
                int d = mr_bottom - area->Height;
                this->cursor_rect.bottom = this->cursor_rect.bottom - d;
                this->new_save_rect.bottom = this->new_save_rect.bottom - d;
                this->mouse_rect.bottom = area->Height;
            }

            this->MouseOnScreen = 1;
            return 1;
        }
    }

    this->MouseOnScreen = 0;
    return 1;
}

void TMousePointer::draw(int param_1) {
    // Fully verified. Source of truth: mouseptr.cpp.decomp @ 0x0045BA60
    IDirectDrawClipper* clipper = nullptr;

    if (this->active != 0 && this->custom_draw != 0) {
        ulong now = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Mouseptr.cpp", 0x2e3);

        if (this->GameMode == 0 ||
            (this->GameEnabled == 0 || param_1 != 0 || (0x21 < now - this->LastDrawTime))) {
            int moved = this->update_mouse_position();
            if (moved != 0 || param_1 != 0) {
                this->LastDrawTime = now;

                if (this->save_area_valid != 0 &&
                    this->restoreSurface != nullptr &&
                    this->restoreSurface != this->PrimarySurface) {
                    HRESULT hr = this->restoreSurface->Blt(&this->restore_rect, this->save_area->DrawSurface,
                        &this->save_rect, DDBLT_WAIT, nullptr);
                    if (hr != DD_OK) {
                        this->LastddError = (long)hr;
                        return;
                    }
                }

                if (this->MouseOnScreen == 0) {
                    this->save_area_valid = 0;
                } else {
                    tagRECT* ptVar1 = &this->mouse_rect;
                    IDirectDrawSurface* saveSurf = this->save_area->DrawSurface;
                    HRESULT hr = saveSurf->Blt(&this->new_save_rect, this->renderSurface, ptVar1, DDBLT_WAIT, nullptr);
                    if (hr != DD_OK) {
                        this->LastddError = (long)hr;
                        return;
                    }

                    this->restoreSurface = this->renderSurface;
                    this->restore_rect = *ptVar1;
                    this->save_rect = this->new_save_rect;
                    this->save_area_valid = 1;

                    if (this->Mouse_Mode == 0) {
                        hr = this->renderSurface->GetClipper(&clipper);
                        if (hr == kDDERR_NOCLIPPER) {
                            hr = DD_OK;
                            clipper = nullptr;
                        }
                        if (hr != DD_OK) {
                            this->LastddError = (long)hr;
                            return;
                        }
                        if (clipper != nullptr) {
                            hr = this->renderSurface->SetClipper(nullptr);
                            if (hr != DD_OK) {
                                this->LastddError = (long)hr;
                                return;
                            }
                        }
                    }

                    if (this->Mouse_Mode == 1) {
                        uchar* bits = this->render_area->Lock((char*)"mouseptr::draw", 1);
                        if (bits != nullptr) {
                            long facet = this->next_facet;
                            Shape_Info* info = this->Cursor_Shape->shape_info;
                             this->Cursor_Shape->shape_draw(this->render_area,
                                 info[facet].Hotspot_X + ptVar1->left,
                                 info[facet].Hotspot_Y + this->mouse_rect.top,
                                 facet, 0, nullptr);
                            this->render_area->Unlock((char*)"mouseptr::draw");
                        }
                    }

                    if (this->Mouse_Mode == 0) {
                        this->cursors[this->next_facet]->SetTrans(1, '\0');
                        hr = this->renderSurface->BltFast((DWORD)ptVar1->left, (DWORD)this->mouse_rect.top,
                            this->cursors[this->next_facet]->DrawSurface, &this->cursor_rect,
                            DDBLTFAST_WAIT | DDBLTFAST_SRCCOLORKEY);
                        if (hr != DD_OK) {
                            this->LastddError = (long)hr;
                            return;
                        }
                    }

                    this->last_facet = this->next_facet;

                    if (this->Mouse_Mode == 0 && clipper != nullptr) {
                        hr = this->renderSurface->SetClipper(clipper);
                        if (hr != DD_OK) {
                            this->LastddError = (long)hr;
                            return;
                        }
                    }
                }

                if (this->GameMode == 0 || this->GameEnabled == 0) {
                    InvalidateRect((HWND)this->render_area->Wnd, &this->mouse_rect, FALSE);
                }

                this->drawn = 1;
            }
        }
    }
}

void TMousePointer::on() {
    // Fully verified. Source of truth: mouseptr.cpp.decomp @ 0x0045BF40
    if (this->Shutdown == 0) {
        if (this->custom_draw == 0) {
            HCURSOR c = LoadCursorA(nullptr, MAKEINTRESOURCEA(0x7f00));
            SetCursor(c);
        }
        this->active = 1;
    }
}

void TMousePointer::off() {
    // Fully verified. Source of truth: mouseptr.cpp.decomp @ 0x0045BEE0
    if (this->Shutdown == 0) {
        if (this->custom_draw != 0 && this->drawn != 0 && this->save_area_valid != 0) {
            this->erase();
            if (this->render_area != nullptr && this->render_area->DrawSystem != nullptr) {
                this->render_area->DrawSystem->Paint(&this->restore_rect);
            }
        }
        SetCursor(nullptr);
        this->active = 0;
        this->reset();
    }
}

int TMousePointer::GetDDBltError(long err) {
    // Fully verified. Source of truth: mouseptr.cpp.decomp @ 0x0045C300
    if (err < -0x7fffbffa) {
        if (err == -0x7fffbffb) return 1;
        if (err == -0x7fffbfff) return 0x11;
    } else if (err < -0x7789ffc8) {
        if (err == -0x7789ffc9) return 0x12;
        if (err == -0x7ff8ffa9) return 4;
    } else if (err < -0x7789ff7d) {
        if (err == -0x7789ff7e) return 3;
        if (err == -0x7789ff92) return 2;
    } else if (err < -0x7789ff4b) {
        if (err == -0x7789ff4c) return 6;
        if (err == -0x7789ff6a) return 5;
    } else if (err < -0x7789ff05) {
        if (err == -0x7789ff06) return 10;
        if (err == -0x7789ff33) return 8;
    } else if (err < -0x7789fedd) {
        if (err == -0x7789fede) return 0xc;
        if (err == -0x7789fee8) return 0xb;
    } else if (err < -0x7789feab) {
        if (err == -0x7789feac) return 0xe;
        if (err == -0x7789feca) return 0xd;
    } else if (err < -0x7789fe3d) {
        if (err == -0x7789fe3e) return 0x10;
        if (err == -0x7789fe52) return 0xf;
    } else {
        if (err == -0x7789fdc1) return 7;
        if (err == -0x7789fdc0) return 9;
        if (err == 0) return 0;
    }
    return -1;
}
