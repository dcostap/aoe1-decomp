// Authentic Mouseptr.cpp source module.
// Definitions follow the PDB source order from Mouseptr.cpp.

#include "../include/Mouseptr.h"

extern TMousePointer* MouseSystem;
extern "C" unsigned long __cdecl debug_timeGetTime(char* file, int line);

#include <stdio.h>

TMousePointer::TMousePointer(int mode)
{
    RECT* save_rect_ptr = &this->save_rect;

    save_rect_ptr->top = 0;
    save_rect_ptr->right = 0;
    save_rect_ptr->left = 0;
    save_rect_ptr->bottom = 0;

    mouse_rect = *save_rect_ptr;
    custom_draw = 0;
    render_area = 0;
    save_area = 0;
    primary_area = 0;
    Cursor_Shape = 0;
    Max_CX = 0;
    Max_CY = 0;
    cursor_rect = *save_rect_ptr;
    cWidth = 0;
    cHeight = 0;
    gWidth = 0;
    gHeight = 0;
    mouse_x = 0;
    mouse_y = 0;
    facet = 0;
    game_facet = 0;
    next_facet = 0;
    last_facet = 0;
    new_save_rect = *save_rect_ptr;
    d_top = 0;
    d_left = 0;
    d_bottom = 0;
    d_right = 0;
    g_top = 0;
    g_left = 0;
    g_bottom = 0;
    g_right = 0;
    active = 0;
    drawn = 0;
    restore_rect = *save_rect_ptr;
    Shutdown = 0;
    Setup = 0;
    save_x = -32767;
    save_y = -32767;
    Mouse_Mode = mode;
    restoreSurface = 0;
    renderSurface = 0;
    GameMode = 0;
    GameEnabled = 0;
    MouseOnScreen = 0;
    Num_Cursors = 0;
    Max_Cursors = 0;
    cursor_file_id = -1;
    cursor_file[0] = 0;

    for (int i = 0; i < 16; ++i) {
        cursors[i] = 0;
    }

    LastDrawTime = debug_timeGetTime(
        "C:\\msdev\\work\\age1_x1\\Mouseptr.cpp", 100);
    LastDrawTime -= 36;
    save_area_valid = 0;
    LastddError = 0;
}

TMousePointer::~TMousePointer()
{
    TShape* shape = this->Cursor_Shape;

    if (shape != 0) {
        delete shape;
        this->Cursor_Shape = 0;
    }
    this->delete_surfaces();
    MouseSystem = 0;
}

int TMousePointer::Shutdown_Mouse()
{
    if (this->Shutdown != 0) {
        return 0;
    }
    if (this->custom_draw == 0) {
        return 1;
    }
    if (this->Setup == 0) {
        return 0;
    }
    this->reset();
    this->render_area = 0;
    this->restoreSurface = 0;
    this->renderSurface = 0;
    this->PrimarySurface = 0;
    this->primary_area = 0;
    this->active = 0;
    this->Shutdown = 1;
    return 1;
}

int TMousePointer::Restore_Mouse(TDrawArea* area)
{
    if (this->Shutdown == 0)
        return 0;

    if (this->custom_draw != 0) {
        if (this->Setup == 0)
            return 0;

        this->render_area = area;
        this->renderSurface = area->DrawSurface;
        this->PrimarySurface = area->DrawSystem->PrimarySurface;
        this->primary_area = area->DrawSystem->PrimaryArea;

        if (this->LoadCursors(0, -1, 1) == 0)
            return 0;

        this->Shutdown = 0;
    }

    return 1;
}

int TMousePointer::setup(int custom_draw, TDrawArea* render_area,
                         char* base, int palette, int max_cursors)
{
    char file_name[260];
    MouseSystem = this;
    this->custom_draw = custom_draw;
    this->render_area = render_area;
    if (custom_draw == 0)
        return 1;
    if (render_area->DrawSystem->DrawType == 1)
        return 0;
    this->renderSurface = render_area->DrawSurface;
    this->PrimarySurface = render_area->DrawSystem->PrimarySurface;
    this->primary_area = render_area->DrawSystem->PrimaryArea;
    SetCursor(0);
    sprintf(file_name, "%s.slp", base);
    this->Cursor_Shape = new TShape(file_name, palette);
    if (this->Cursor_Shape == 0)
        return 0;
    if (!this->Cursor_Shape->is_loaded())
        return 0;
    if (this->Cursor_Shape->FShape == 0)
        return 0;
    this->Max_Cursors = max_cursors;
    if (max_cursors < 1 || max_cursors > 16)
        return 0;
    this->Num_Cursors = this->Cursor_Shape->shape_count();
    if (this->Num_Cursors > this->Max_Cursors)
        return 0;
    if (!this->LoadCursors(base, palette, 0))
        return 0;
    this->set_facet(0);
    this->set_game_facet(0);
    this->Setup = 1;
    return 1;
}

void TMousePointer::set_game_mode(int value)
{
    this->GameMode = value;
}

void TMousePointer::set_game_enable(int value)
{
    this->GameEnabled = value;
}

int TMousePointer::get_game_enable()
{
    return this->GameEnabled;
}

int TMousePointer::in_game_mode()
{
    if (this->GameMode && this->GameEnabled) {
        return 1;
    }
    return 0;
}

void TMousePointer::set_game_window(int left, int top, int right, int bottom)
{
    this->game_window.left = left;
    this->game_window.top = top;
    this->game_window.right = right;
    this->game_window.bottom = bottom;
}

int TMousePointer::LoadCursors(char* base, int file_id, int keep_name)
{
    int LoadOk = 1;
    int count;
    TShape* old = this->Cursor_Shape;
    if (old != 0) {
        delete old;
    }

    if (keep_name == 0) {
        this->cursor_file_id = file_id;
        sprintf(this->cursor_file, "%s.slp", base);
    }

    TShape* shape = new TShape(this->cursor_file, this->cursor_file_id);
    this->Cursor_Shape = shape;
    if (shape == 0)
        return 0;
    if (!shape->is_loaded())
        return 0;
    if (this->Cursor_Shape->FShape == 0)
        return 0;

    count = this->Cursor_Shape->shape_count();
    this->Num_Cursors = count;
    this->Max_CX = 0;
    this->Max_CY = 0;
    if (count > 0) {
        TShape* sh = this->Cursor_Shape;
        int off = 0;
        int n = count;
        do {
            Shape_Info* p = (Shape_Info*)((char*)sh->shape_info + off);
            int w = p->Width;
            if (w > this->Max_CX)
                this->Max_CX = w;
            int h = p->Height;
            if (h > this->Max_CY)
                this->Max_CY = h;
            off += 0x20;
            n--;
        } while (n != 0);
    }

    if (this->Max_CX == 0 || this->Max_CY == 0)
        return 0;
    this->Max_CX = 0x40;
    this->Max_CY = 0x30;
    if (this->save_area == 0) {
        if (!this->create_surfaces())
            return 0;
    }
    this->set_facet(this->facet);
    this->set_game_facet(this->game_facet);

    if (this->Mouse_Mode == 0) {
        if (this->Num_Cursors > this->Max_Cursors)
            return 0;
        for (int i = 0; i < this->Num_Cursors; i++) {
            // BINARY NOTE: The height check follows the width check.
            long* height = &((Shape_Info*)this->Cursor_Shape->shape_info)[i].Height;
            if (height[-1] > this->Max_CX)
                return 0;
            if (*height > this->Max_CY)
                return 0;
        }
        int cur = 0;
        if (this->Max_Cursors > 0) {
            int off = 0;
            TDrawArea** pp = this->cursors;
            do {
                (*pp)->Clear(0, 0);
                (*pp)->SetTrans(1, (unsigned char)0);
                if (cur < this->Num_Cursors) {
                    if ((*pp)->Lock("mouseptr::LoadCursors", 1)) {
                        (*pp)->FillRect(0, 0, this->Max_CX, this->Max_CY,
                                        (unsigned char)0);
                        Shape_Info* si =
                            (Shape_Info*)((char*)this->Cursor_Shape->shape_info + off);
                        this->Cursor_Shape->shape_draw(
                            *pp, si->Hotspot_X, si->Hotspot_Y, cur,
                            (unsigned char)0, 0);
                        (*pp)->Unlock("mouseptr::LoadCursors");
                    } else {
                        LoadOk = 0;
                    }
                }
                cur++;
                pp++;
                off += 0x20;
            } while (cur < this->Max_Cursors);
        }
    }
    return LoadOk;
}

void TMousePointer::delete_surfaces()
{
    TMousePointer* self = this;
    TDrawArea* t;
    int i;
    if (self->custom_draw != 0) {
        if ((t = self->save_area) != 0) {
            delete t;
            self->save_area = 0;
        }
        for (i = 0; i < self->Max_Cursors; ++i) {
            if ((t = self->cursors[i]) != 0) {
                delete t;
                self->cursors[i] = 0;
            }
        }
        self->Num_Cursors = 0;
        self->reset();
    }
}

int TMousePointer::create_surfaces()
{
    int i;
    char NameBuf[32];

    if (this->custom_draw == 0) {
        return 1;
    }

    if (this->save_area == 0 && this->Max_CX > 0 && this->Max_CY > 0) {
        this->save_area = new TDrawArea("Mouse Save area", 0);
        if (this->save_area == 0) {
            return 0;
        }
        if (this->save_area->Init(this->render_area->DrawSystem,
                                  this->Max_CX, this->Max_CY, 0, 0) == 0) {
            return 0;
        }
    }

    if (this->Mouse_Mode == 0 && 0 < this->Max_Cursors) {
        for (i = 0; i < this->Max_Cursors; i++) {
            if (this->cursors[i] == 0) {
                sprintf(NameBuf, "Mouse Cursor #%d", i);
                this->cursors[i] = new TDrawArea(NameBuf, 0);
                if (this->cursors[i] == 0) {
                    return 0;
                }
                if (this->cursors[i]->Init(this->render_area->DrawSystem,
                                           this->Max_CX, this->Max_CY, 0, 0) == 0) {
                    return 0;
                }
            }
        }
    }

    return 1;
}

int TMousePointer::update_mouse_position()
{
    POINT point;
    int in_game;
    if (this->custom_draw == 0)
        return 0;
    GetCursorPos(&point);
    if (this->render_area->DrawSystem->ScreenMode == 1) {
        ScreenToClient(this->render_area->Wnd, &point);
        if (point.x > 0x8000)
            point.x -= 0x10000;
        if (point.y > 0x8000)
            point.y -= 0x10000;
    }
    this->mouse_x = point.x;
    this->mouse_y = point.y;
    if (this->GameMode != 0 && this->GameEnabled != 0 &&
        this->mouse_x >= this->game_window.left &&
        this->mouse_x < this->game_window.right &&
        point.y >= this->game_window.top &&
        point.y < this->game_window.bottom) {
        this->next_facet = this->game_facet;
        in_game = 1;
    } else {
        this->next_facet = this->facet;
        in_game = 0;
    }
    if (this->save_area_valid != 0 && point.x == this->save_x &&
        point.y == this->save_y && this->next_facet == this->last_facet)
        return 0;
    this->save_x = point.x;
    this->save_y = point.y;
    this->new_save_rect.left = 0;
    this->new_save_rect.top = 0;
    if (in_game != 0) {
        this->new_save_rect.right = this->gWidth;
        this->new_save_rect.bottom = this->gHeight;
        this->mouse_rect.left = this->mouse_x - this->g_left;
        this->mouse_rect.top = this->mouse_y - this->g_top;
        this->mouse_rect.right = this->g_right + this->mouse_x;
        this->mouse_rect.bottom = this->g_bottom + this->mouse_y;
    } else {
        this->new_save_rect.right = this->cWidth;
        this->new_save_rect.bottom = this->cHeight;
        this->mouse_rect.left = this->mouse_x - this->d_left;
        this->mouse_rect.top = this->mouse_y - this->d_top;
        this->mouse_rect.right = this->d_right + this->mouse_x;
        this->mouse_rect.bottom = this->d_bottom + this->mouse_y;
    }
    this->cursor_rect = this->new_save_rect;
    if (this->mouse_rect.right >= 0 && this->mouse_rect.bottom >= 0) {
        TDrawArea* da = this->render_area;
        if (this->mouse_rect.left <= da->Width &&
            this->mouse_rect.top <= da->Height) {
            if (this->mouse_rect.left < 0) {
                this->cursor_rect.left = -this->mouse_rect.left;
                this->new_save_rect.right -= this->cursor_rect.left;
                this->mouse_rect.left = 0;
            }
            if (this->mouse_rect.right > da->Width) {
                int t = this->mouse_rect.right - da->Width;
                this->cursor_rect.right -= t;
                this->new_save_rect.right -= t;
                this->mouse_rect.right = da->Width;
            }
            int top = this->mouse_rect.top;
            if (top < 0) {
                this->mouse_rect.top = 0;
                top = -top;
                this->cursor_rect.top = top;
                this->new_save_rect.bottom -= top;
            }
            if (this->mouse_rect.bottom > da->Height) {
                int t = this->mouse_rect.bottom - da->Height;
                this->cursor_rect.bottom -= t;
                this->new_save_rect.bottom -= t;
                this->mouse_rect.bottom = da->Height;
            }
            this->MouseOnScreen = 1;
            return 1;
        }
    }
    this->MouseOnScreen = 0;
    return 1;
}

void TMousePointer::draw(int forced)
{
    IDirectDrawClipper* lplpDDClipper;
    lplpDDClipper = 0;
    if (this->active != 0 && this->custom_draw != 0) {
        ulong t = debug_timeGetTime(
            "C:\\msdev\\work\\age1_x1\\Mouseptr.cpp", 0x2e3);
        if (this->GameMode != 0 && this->GameEnabled != 0 && forced == 0) {
            if (t - this->LastDrawTime < 0x22)
                return;
        }
        if (this->update_mouse_position() != 0 || forced != 0) {
            this->LastDrawTime = t;
            if (this->save_area_valid != 0 &&
                this->restoreSurface != this->PrimarySurface) {
                long err = this->restoreSurface->Blt(
                    &this->restore_rect, this->save_area->DrawSurface,
                    &this->save_rect, 0x1000000, 0);
                if (err != 0) {
                    this->LastddError = err;
                    return;
                }
            }
            if (this->MouseOnScreen != 0) {
                RECT* ptVar1 = &this->mouse_rect;
                long err = this->save_area->DrawSurface->Blt(
                    &this->new_save_rect, this->renderSurface, ptVar1,
                    0x1000000, 0);
                if (err != 0) {
                    this->LastddError = err;
                    return;
                }
                this->restoreSurface = this->renderSurface;
                this->restore_rect = this->mouse_rect;
                this->save_rect = this->new_save_rect;
                this->save_area_valid = 1;
                if (this->Mouse_Mode == 0) {
                    err = this->renderSurface->GetClipper(&lplpDDClipper);
                    if (err == (long)0x88760238) {
                        err = 0;
                        lplpDDClipper = 0;
                    }
                    if (err != 0) {
                        this->LastddError = err;
                        return;
                    }
                    if (lplpDDClipper != 0) {
                        err = this->renderSurface->SetClipper(0);
                        if (err != 0) {
                            this->LastddError = err;
                            return;
                        }
                    }
                }
                if (this->Mouse_Mode == 1) {
                    uchar* p = this->render_area->Lock(
                        "mouseptr::draw", 1);
                    if (p != 0) {
                        long f = this->next_facet;
                        Shape_Info* si = this->Cursor_Shape->shape_info;
                        this->Cursor_Shape->shape_draw(
                            this->render_area,
                            si[f].Hotspot_X + ptVar1->left,
                            si[f].Hotspot_Y + this->mouse_rect.top,
                            f, 0, 0);
                        this->render_area->Unlock("mouseptr::draw");
                    }
                }
                if (this->Mouse_Mode == 0) {
                    this->cursors[this->next_facet]->SetTrans(1, 0);
                    err = this->renderSurface->BltFast(
                        ptVar1->left, this->mouse_rect.top,
                        this->cursors[this->next_facet]->DrawSurface,
                        &this->cursor_rect, 0x11);
                    if (err != 0) {
                        this->LastddError = err;
                        return;
                    }
                }
                this->last_facet = this->next_facet;
                if (this->Mouse_Mode == 0 && lplpDDClipper != 0) {
                    err = this->renderSurface->SetClipper(lplpDDClipper);
                    if (err != 0) {
                        this->LastddError = err;
                        return;
                    }
                }
            } else {
                this->save_area_valid = 0;
            }
            if (this->GameMode == 0 || this->GameEnabled == 0) {
                InvalidateRect(this->render_area->Wnd, &this->mouse_rect, 0);
            }
            this->drawn = 1;
        }
    }
}

void TMousePointer::erase()
{
    if (!active)
        return;
    if (!custom_draw)
        return;
    if (!drawn)
        return;
    if (!save_area_valid)
        return;
    if (restoreSurface == PrimarySurface)
        return;

    long result = restoreSurface->Blt(
        &restore_rect, save_area->DrawSurface, &save_rect, 0x1000000, 0);

    if (result != 0) {
        LastddError = result;
        return;
    }

    if (GameMode && GameEnabled) {
        save_area_valid = 1;
        restoreSurface = PrimarySurface;
        return;
    }

    InvalidateRect(render_area->Wnd, &restore_rect, 0);
    save_area_valid = 0;
}

void TMousePointer::set_facet(int f)
{
    if (f < 0 || f >= this->Num_Cursors)
        return;

    this->facet = f;
    Shape_Info* info = this->Cursor_Shape->shape_info + f;
    this->cWidth = info->Width;
    this->cHeight = info->Height;
    this->d_top = info->Hotspot_Y;
    this->d_left = info->Hotspot_X;
    this->d_right = this->cWidth - info->Hotspot_X;
    this->d_bottom = this->cHeight - info->Hotspot_Y;
}

void TMousePointer::set_game_facet(int facet)
{
    if (facet >= 0 && facet < this->Num_Cursors) {
        Shape_Info* info = this->Cursor_Shape->shape_info;
        this->game_facet = facet;
        info = info + facet;
        this->gWidth = info->Width;
        this->gHeight = info->Height;
        this->g_top = info->Hotspot_Y;
        this->g_left = info->Hotspot_X;
        this->g_right = this->gWidth - info->Hotspot_X;
        this->g_bottom = this->gHeight - info->Hotspot_Y;
    }
}

void TMousePointer::off()
{
    if (this->Shutdown == 0) {
        if (this->custom_draw != 0 && this->drawn != 0 &&
            this->save_area_valid != 0) {
            this->erase();
            this->render_area->DrawSystem->Paint(&this->restore_rect);
        }
        SetCursor(0);
        this->active = 0;
        this->reset();
    }
}

void TMousePointer::on(void)
{
    if (this->Shutdown == 0) {
        if (this->custom_draw == 0) {
            SetCursor(LoadCursorA(0, (const char*)0x7F00));
        }
        this->active = 1;
    }
}

void TMousePointer::reset()
{
    this->save_area_valid = 0;
    this->drawn = 0;
}

void TMousePointer::center()
{
    TDrawSystem* draw_system = this->render_area->DrawSystem;
    int x;
    int y;

    if (draw_system->ScreenMode == 1) {
        RECT win_rect;
        GetWindowRect(draw_system->Wnd, &win_rect);
        x = (win_rect.right - win_rect.left) / 2 + win_rect.left;
        y = (win_rect.bottom - win_rect.top) / 2 + win_rect.top;
    } else {
        x = draw_system->ScreenWidth / 2;
        y = draw_system->ScreenHeight / 2;
    }
    SetCursorPos(x, y);
}

void TMousePointer::Poll()
{
    IDirectDrawClipper* lplpDDClipper;
    lplpDDClipper = 0;
    if (this->active != 0 && this->custom_draw != 0 &&
        this->GameMode != 0 && this->GameEnabled != 0) {
        ulong t = debug_timeGetTime(
            "C:\\msdev\\work\\age1_x1\\Mouseptr.cpp", 0x42e);
        if (t - this->LastDrawTime >= 0x22) {
            if (this->update_mouse_position() != 0) {
                this->LastDrawTime = t;
                if (this->Mouse_Mode == 0) {
                    long err = this->PrimarySurface->GetClipper(
                        &lplpDDClipper);
                    if (err == (long)0x88760238) {
                        err = 0;
                        lplpDDClipper = 0;
                    }
                    if (err != 0) {
                        this->LastddError = err;
                        return;
                    }
                    if (lplpDDClipper != 0) {
                        err = this->PrimarySurface->SetClipper(0);
                        if (err != 0) {
                            this->LastddError = err;
                            return;
                        }
                    }
                }
                if (this->save_area_valid != 0) {
                    long err = this->restoreSurface->Blt(
                        &this->restore_rect, this->save_area->DrawSurface,
                        &this->save_rect, 0x1000000, 0);
                    if (err != 0) {
                        this->LastddError = err;
                        return;
                    }
                    if (this->restoreSurface != this->PrimarySurface) {
                        err = this->PrimarySurface->Blt(
                            &this->restore_rect, this->save_area->DrawSurface,
                            &this->save_rect, 0x1000000, 0);
                        if (err != 0) {
                            this->LastddError = err;
                            return;
                        }
                    }
                }
                if (this->MouseOnScreen != 0) {
                    RECT* ptVar1 = &this->mouse_rect;
                    long err = this->save_area->DrawSurface->Blt(
                        &this->new_save_rect, this->PrimarySurface, ptVar1,
                        0x1000000, 0);
                    if (err != 0) {
                        this->LastddError = err;
                        this->LastddError = this->GetDDBltError(err);
                        return;
                    }
                    this->restoreSurface = this->PrimarySurface;
                    this->restore_rect = *ptVar1;
                    this->save_rect = this->new_save_rect;
                    this->save_area_valid = 1;
                    if (this->Mouse_Mode == 0) {
                        this->cursors[this->next_facet]->SetTrans(1, 0);
                        err = this->PrimarySurface->BltFast(
                            ptVar1->left, this->mouse_rect.top,
                            this->cursors[this->next_facet]->DrawSurface,
                            &this->cursor_rect, 0x11);
                        if (err != 0) {
                            this->LastddError = err;
                            return;
                        }
                    }
                    if (this->Mouse_Mode == 1) {
                        uchar* p = this->primary_area->Lock(
                            "mouseptr::poll", 1);
                        if (p != 0) {
                            Shape_Info* si =
                                this->Cursor_Shape->shape_info +
                                this->next_facet;
                            this->Cursor_Shape->shape_draw(
                                this->primary_area,
                                si->Hotspot_X + ptVar1->left,
                                this->mouse_rect.top + si->Hotspot_Y,
                                this->next_facet, 0, 0);
                            this->primary_area->Unlock("mouseptr::poll");
                        }
                    }
                    this->last_facet = this->next_facet;
                } else {
                    this->save_area_valid = 0;
                }
                if (this->Mouse_Mode == 0 && lplpDDClipper != 0) {
                    long err = this->PrimarySurface->SetClipper(
                        lplpDDClipper);
                    if (err != 0) {
                        this->LastddError = err;
                        return;
                    }
                }
                this->drawn = 1;
            }
        }
    }
}

int TMousePointer::GetDDBltError(long a_hresult)
{
    switch (a_hresult) {
    case 0x80004005: return 1;
    case 0x80004001: return 17;
    case 0x88760037: return 18;
    case 0x80070057: return 4;
    case 0x88760082: return 3;
    case 0x8876006E: return 2;
    case 0x887600B4: return 6;
    case 0x88760096: return 5;
    case 0x887600FA: return 10;
    case 0x887600CD: return 8;
    case 0x88760122: return 12;
    case 0x88760118: return 11;
    case 0x88760154: return 14;
    case 0x88760136: return 13;
    case 0x887601C2: return 16;
    case 0x887601AE: return 15;
    case 0x8876023F: return 7;
    case 0x88760240: return 9;
    case 0: return 0;
    default: return -1;
    }
}
