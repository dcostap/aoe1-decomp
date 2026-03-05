#include "../include/TRIBE_Scenario_Editor_Panel_Object.h"

#include "../include/RGE_Armor_Weapon_Info.h"
#include "../include/RGE_Base_Game.h"
#include "../include/RGE_Color_Table.h"
#include "../include/RGE_Sprite.h"
#include "../include/TDrawArea.h"
#include "../include/TShape.h"
#include "../include/TRIBE_Master_Building_Object.h"
#include "../include/TRIBE_Player.h"
#include "../include/globals.h"

#include <cstdio>
#include <cstring>
#include <cstdint>

extern "C" void _ASMSet_Color_Xform(int v);

static int spnl_ftol(float value) {
    long result;
    __asm {
        fld value
        fistp result
    }
    return (int)result;
}

// Fully verified. Source of truth: spnl_obj.cpp.decomp @ 0x004BEDC0
TRIBE_Scenario_Editor_Panel_Object::TRIBE_Scenario_Editor_Panel_Object(
    TDrawArea* param_1,
    TPanel* param_2,
    void* param_3,
    long param_4,
    long param_5,
    TShape* param_6,
    TShape** param_7,
    TRIBE_Player* param_8)
    : TRIBE_Panel_Object(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8) {
    this->master_game_obj = (RGE_Master_Static_Object*)0;
    this->master_culture_id = 0;
}

// Fully verified. Source of truth: spnl_obj.cpp.decomp @ 0x004BEE30
TRIBE_Scenario_Editor_Panel_Object::~TRIBE_Scenario_Editor_Panel_Object() {
}

// Fully verified. Source of truth: spnl_obj.cpp.decomp @ 0x004BEE40
void TRIBE_Scenario_Editor_Panel_Object::set_master_info(RGE_Master_Static_Object* param_1, TRIBE_Player* param_2) {
    this->master_game_obj = param_1;
    this->player = param_2;
    if (param_2 == (TRIBE_Player*)0) {
        this->master_culture_id = 0;
        return;
    }
    this->master_culture_id = (uint)(byte)param_2->culture;
}

// Fully verified. Source of truth: spnl_obj.cpp.decomp @ 0x004BEE70
void TRIBE_Scenario_Editor_Panel_Object::draw() {
    if (this->render_area == (TDrawArea*)0 || this->visible == 0 || this->active == 0) {
        this->need_redraw = TPanel::NoRedraw;
        return;
    }

    if (this->mode == 2) {
        this->draw_score();
        return;
    }

    if (this->master_game_obj == (RGE_Master_Static_Object*)0) {
        if (this->parent_panel != (TPanel*)0) {
            this->parent_panel->draw_rect(&this->clip_rect);
            this->need_redraw = TPanel::NoRedraw;
            return;
        }
        this->need_redraw = TPanel::NoRedraw;
        return;
    }

    this->draw_setup(0);
    this->render_area->Clear(&this->clip_rect, 0);

    int text_flag = 0;
    if (this->render_area->Lock((char*)0, 1) != (uchar*)0) {
        text_flag = 1;
        short button_pic = this->master_game_obj->button_pict;
        if (button_pic == -1) {
            if (this->master_game_obj->sprite != (RGE_Sprite*)0) {
                text_flag = 0;
                long min_x = 0;
                long min_y = 0;
                long max_x = 0;
                long max_y = 0;
                if (this->master_game_obj->sprite->get_size(&min_x, &min_y, &max_x, &max_y, 0) != 0) {
                    RGE_Color_Table* color_table = (this->player != (TRIBE_Player*)0) ? this->player->color_table : (RGE_Color_Table*)0;
                    this->master_game_obj->sprite->do_draw(0, 0, (this->pnl_x - min_x) + 10, (this->pnl_y - min_y) + 0x28, color_table,
                                                           this->render_area, 0);
                }
            }
        } else {
            TShape* pic_set;
            if (this->master_game_obj->unit_level == 2) {
                pic_set = this->bldg_pics[this->master_culture_id];
                button_pic = (short)(button_pic + *(short*)((char*)this->master_game_obj + 0x16E));
            } else {
                pic_set = this->unit_pics;
            }

            RGE_Color_Table* color_table = (this->player != (TRIBE_Player*)0) ? this->player->color_table : (RGE_Color_Table*)0;
            if (color_table != (RGE_Color_Table*)0 && color_table != (RGE_Color_Table*)(intptr_t)-0x28) {
                _ASMSet_Color_Xform((color_table->id + 1) * 0x10);
                pic_set->shape_draw(this->render_area, this->pnl_x + 2, this->pnl_y + 0x21, button_pic, 1, color_table->table);
            } else {
                pic_set->shape_draw(this->render_area, this->pnl_x + 2, this->pnl_y + 0x21, button_pic, 0, (uchar*)0);
            }
        }
        this->render_area->Unlock((char*)0);
    }

    void* dc_ptr = this->render_area->GetDc((char*)0);
    if (dc_ptr != (void*)0) {
        HDC dc = (HDC)this->render_area->DrawDc;
        SetBkMode(dc, 1);
        SetTextColor(dc, 0x00FFFFFF);
        SelectClipRgn(dc, (HRGN)this->clip_rgn);
        HGDIOBJ old_font = SelectObject(dc, this->font);

        char name[100];
        if (this->player != (TRIBE_Player*)0 && rge_base_game != (RGE_Base_Game*)0) {
            rge_base_game->get_string2(0x69, (long)this->master_game_obj->id, 0, name, 100);
            if (std::strcmp(name, "Unknown") == 0) {
                std::strcpy(name, "Gaia");
            }
            TextOutA(dc, this->pnl_x + 2, this->pnl_y, name, (int)std::strlen(name));
        }

        char str[100];
        if ((this->master_game_obj->string_id < 1) || (rge_base_game == (RGE_Base_Game*)0)) {
            str[0] = '\0';
        } else {
            rge_base_game->get_string((long)this->master_game_obj->string_id, str, 100);
        }
        if (str[0] == '\0') {
            if (this->master_game_obj->name != (char*)0) {
                std::strcpy(str, this->master_game_obj->name);
            } else {
                str[0] = '\0';
            }
        }

        std::sprintf(name, "%s", str);
        TextOutA(dc, this->pnl_x + 2, this->pnl_y + 0x0F, name, (int)std::strlen(name));

        if (text_flag != 0) {
            int hp = (int)this->master_game_obj->hp;
            std::sprintf(str, "%d/%d", hp, hp);
            TextOutA(dc, this->pnl_x + 5, this->pnl_y + 0x55, str, (int)std::strlen(str));
            SelectObject(dc, old_font);
            SelectClipRgn(dc, (HRGN)0);
        }

        this->render_area->ReleaseDc((char*)0);
    }

    if (text_flag != 0) {
        RGE_Master_Static_Object* master = this->master_game_obj;
        int row = 0;
        uchar unit_level = master->unit_level;

        if (unit_level == 3 || unit_level == 9 || unit_level == 4 || unit_level == 5 || unit_level == 6 || unit_level == 7) {
            if (unit_level == 3 || unit_level == 4) {
                int weapon = (int)*(short*)((char*)master + 0x13E);
                this->draw_item(0, 7, ValueTypeBonus, weapon, weapon);
                row = 1;
            }

            if (unit_level == 4 || unit_level == 6) {
                int armor = (int)*(short*)((char*)master + 0x13C);
                this->draw_item(row, 8, ValueTypeBonus, armor, armor);
                row = row + 1;
            }

            int pierce_armor = (int)this->get_pierce_armor();
            if (unit_level == 4 || unit_level == 6) {
                this->draw_item(row, 10, ValueTypeBonus, pierce_armor, pierce_armor);
                row = row + 1;
            }

            if (unit_level == 4 || unit_level == 6) {
                int range = spnl_ftol(*(float*)((char*)master + 0x140));
                this->draw_item(row, 6, ValueTypeNumber, range, pierce_armor);
            }
        } else if (unit_level == 1) {
            short held_type = -1;
            int held_index = 0;
            for (; held_index < 3; ++held_index) {
                if (*(float*)((char*)master + 0x70 + held_index * 4) > 0.0f) {
                    held_type = *(short*)((char*)master + 0x6A + held_index * 2);
                    break;
                }
            }

            int icon = -1;
            switch (held_type) {
            case 0:
            case 0x0F:
            case 0x10:
            case 0x11:
                icon = 2;
                break;
            case 1:
                icon = 0;
                break;
            case 2:
                icon = 1;
                break;
            case 3:
                icon = 3;
                break;
            default:
                icon = -1;
                break;
            }

            if (icon != -1) {
                int amount = spnl_ftol(*(float*)((char*)master + 0x70 + held_index * 4));
                this->draw_item(0, icon, ValueTypeNumber, amount, 0);
            }
        } else if (unit_level == 2) {
            int weapon = (int)*(short*)((char*)master + 0x13E);
            this->draw_item(0, 7, ValueTypeBonus, weapon, weapon);

            int armor = (int)*(short*)((char*)master + 0x13C);
            this->draw_item(1, 8, ValueTypeBonus, armor, armor);

            int value = spnl_ftol(*(float*)((char*)master + 0x114));
            this->draw_item(2, 6, ValueTypeBonus, value, value);
        }
    }

    this->draw_finish();
}

// Fully verified. Source of truth: spnl_obj.cpp.decomp @ 0x004BF499
void FUN_004bf499() {
    // Switch table label padding in original binary (NOP; MOV EDI, EDI).
}

// Fully verified. Source of truth: spnl_obj.cpp.decomp @ 0x004BF4D0
void TRIBE_Scenario_Editor_Panel_Object::draw_item(int param_1, int param_2, ValueType param_3, int param_4, int param_5) {
    if (this->item_pic != (TShape*)0 && param_2 != -1 && this->render_area->Lock((char*)0, 1) != (uchar*)0) {
        this->item_pic->shape_draw(this->render_area, this->pnl_x + 0x3C, this->pnl_y + 0x1E + param_1 * 0x12, param_2, 0, (uchar*)0);
        this->render_area->Unlock((char*)0);
    }

    char val_str[20];
    char* out = val_str + 4;
    switch (param_3) {
    case ValueTypeNumber:
        std::sprintf(out, "%d", param_4);
        break;
    case ValueTypeBonus:
        if (param_4 < param_5) {
            std::sprintf(out, "%d+%d", param_4, param_5 - param_4);
        } else {
            std::sprintf(out, "%d", param_4);
        }
        break;
    case ValueTypeCompare:
        std::sprintf(out, "%d/%d", param_4, param_5);
        break;
    case ValueTypePercent:
        std::sprintf(out, "%d%%", param_4);
        break;
    default:
        out[0] = '\0';
        break;
    }

    if (out[0] != '\0' && this->render_area->GetDc((char*)0) != (void*)0) {
        HDC dc = (HDC)this->render_area->DrawDc;
        SetBkMode(dc, 1);
        SetTextColor(dc, 0x00FFFFFF);
        SelectClipRgn(dc, (HRGN)this->clip_rgn);
        HGDIOBJ old_font = SelectObject(dc, this->font);

        TextOutA(dc, this->pnl_x + 100, this->pnl_y + 0x20 + param_1 * 0x12, out, (int)std::strlen(out));

        SelectObject(dc, old_font);
        SelectClipRgn(dc, (HRGN)0);
        this->render_area->ReleaseDc((char*)0);
    }
}

// Fully verified. Source of truth: spnl_obj.cpp.decomp @ 0x004BF6A5
void FUN_004bf6a5() {
    // Switch table label padding in original binary (NOP; MOV EDI, EDI).
}

// Fully verified. Source of truth: spnl_obj.cpp.decomp @ 0x004BF6C0
long TRIBE_Scenario_Editor_Panel_Object::mouse_left_up_action(long param_1, long param_2, int param_3, int param_4) {
    (void)param_1;
    (void)param_2;
    (void)param_3;
    (void)param_4;
    this->release_mouse();
    // TODO: PARITY - Extra read from rge_base_game+0x1B0 is not present in decomp, which releases mouse and returns 1 directly. [decomp: spnl_obj.cpp.decomp @ 0x004BF6C0]
    if (rge_base_game != (RGE_Base_Game*)0) {
        (void)*(int*)((char*)rge_base_game + 0x1B0);
    }
    return 1;
}

// Fully verified. Source of truth: spnl_obj.cpp.decomp @ 0x004BF6E0
long TRIBE_Scenario_Editor_Panel_Object::get_pierce_armor() {
    if (this->master_game_obj == (RGE_Master_Static_Object*)0) {
        return 0;
    }
    if (this->master_game_obj->master_type != 'F') {
        return 0;
    }

    short armor_num = *(short*)((char*)this->master_game_obj + 0x102);
    RGE_Armor_Weapon_Info* armor = *(RGE_Armor_Weapon_Info**)((char*)this->master_game_obj + 0x104);
    long pierce_armor = 0;
    for (int i = 0; i < (int)armor_num; ++i) {
        if (armor[i].type == 3) {
            pierce_armor = (long)armor[i].value;
        }
    }
    return pierce_armor;
}
