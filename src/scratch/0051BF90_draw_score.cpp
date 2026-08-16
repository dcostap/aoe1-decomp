// VA: 0051BF90 TRIBE_Panel_Object::draw_score (614B)
// PDB: tpnl_obj.cpp:741-814
//
// Attempt log:
// - canonical baseline: named TPanel coordinates/render surface, typed game /
//   world / player / victory / communications ownership, and natural score
//   row drawing with the period GDI and string surfaces.
// - binary behavior correction: vertical row advance is inside the valid-player
//   arm, so skipped players do not consume a row.
// - probes of declaration scope, self/register aliases, while/do-while forms,
//   and coordinate temporaries did not recover the original EBP accumulator /
//   stack-home topology. A direct-expression variant reached the original size
//   but lost the 0x94 frame and block alignment; the readable named-coordinate
//   source is retained here.
// - restored the PDB-local declaration order by placing y_offset before the
//   coordinate locals; VC5 emitted identical bytes, so no codegen lead remains.
// - typed the victory-point return as long, matching the exact same-TU score
//   donor and the decompiler's original long return; this tests score text ABI.
// - current bounded pass: moving y before y_offset was a codegen duplicate.
// - direct-y plus a natural base-x local reached the best diagnostic 614B/0x8C
//   frame basin (diff 437), but it lost the proven 0x94 local topology.
// - a 32-bit y local reached diff 613 with a 0x94 frame, but kept EDI as the
//   zero/row register and broadened the structural mismatch.
// - right-edge coordinate locals produced 0x90 and 0x98 frames (diffs 456/640);
//   y/x combined declaration, <new.h>, full TPanel fields, and block-scoped y
//   were duplicates. The readable 0x94 source remains the canonical candidate.
// - The batch left the direct-y 0x8C diagnostic in the file. Main review
//   restored the named y local and the proven 0x94 clean-source topology.
// - left in scratch: calls/behavior are understood, but VC5 local coloring and
//   the GDI/string scheduling remain broadly nonexact.

#include <stdio.h>
#include <string.h>
#include <windows.h>

extern "C" {
__declspec(dllimport) int __stdcall SetBkMode(HDC, int);
__declspec(dllimport) COLORREF __stdcall SetTextColor(HDC, COLORREF);
__declspec(dllimport) HGDIOBJ __stdcall SelectObject(HDC, HGDIOBJ);
__declspec(dllimport) BOOL __stdcall TextOutA(HDC, int, int, LPCSTR, int);
__declspec(dllimport) BOOL __stdcall SetRect(LPRECT, int, int, int, int);
__declspec(dllimport) int __stdcall DrawTextA(HDC, LPCSTR, int, LPRECT, UINT);
int __cdecl sprintf(char*, const char*, ...);
}

extern char s_tpnl_obj_draw_score[];
extern char s_fmt_d[];

class TDrawArea {
public:
    char gap_00[0x38];
    HDC DrawDc;

    void Clear(RECT*, int);
    void* GetDc(char*);
    void ReleaseDc(char*);
};

class TPanel {
public:
    virtual ~TPanel();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void draw_setup(int);
    virtual void draw_finish();

    char gap_04[8];
    long pnl_x;
    long pnl_y;
    long pnl_wid;
    long pnl_hgt;
    char gap_1C[4];
    TDrawArea* render_area;
    RECT clip_rect;
    char gap_34[4];
    long need_redraw;
    char gap_3C[0x30];
    long active;
    long visible;
    char gap_74[0x80];
};

class RGE_Color_Table {
public:
    char gap_00[0x26];
    short id;
};

class RGE_Victory_Conditions {
public:
    long get_victory_points();
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x30];
    RGE_Victory_Conditions* victory_conditions;
    char gap_38[0xD0];
    RGE_Color_Table* color_table;
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    char gap_04[0x38];
    short player_num;
    char gap_3E[2];
    RGE_Player** players;
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    char gap_04[0x3F0];
    RGE_Game_World* world;
    int playerID(int);
};

class TCommunications_Handler {
public:
    char* GetPlayerName(unsigned int);
};

extern RGE_Base_Game* rge_base_game;
extern TCommunications_Handler* comm;

class TRIBE_Panel_Object : public TPanel {
public:
    void* font;
    void draw_score();
};

void TRIBE_Panel_Object::draw_score()
{
    int i;
    short x_val;
    HGDIOBJ old_font;
    RGE_Player* temp_player;
    int y_offset = 0;
    short x;
    short y;
    RECT rect;
    char str[100];

    if (this->render_area == 0 || this->visible == 0 || this->active == 0) {
        this->need_redraw = 0;
        return;
    }

    this->draw_setup(0);
    this->render_area->Clear(&this->clip_rect, 0);

    if (this->render_area->GetDc(s_tpnl_obj_draw_score) != 0) {
        SetBkMode(this->render_area->DrawDc, 1);
        SetTextColor(this->render_area->DrawDc, 0xFFFFFF);
        old_font = SelectObject(this->render_area->DrawDc,
                                (HGDIOBJ)this->font);

        x = (short)this->pnl_x + 3;
        x_val = (short)this->pnl_x + 0x5A;
        y = (short)this->pnl_y - 1;

        i = 1;
        do {
            int player_id = rge_base_game->playerID(i);
            if (player_id != 0 &&
                player_id < rge_base_game->world->player_num) {
                temp_player = rge_base_game->world->players[player_id];
                int color;

                switch (temp_player->color_table->id) {
                case 0:
                    color = 0xFF0000;
                    break;
                case 1:
                    color = 0x2139C6;
                    break;
                case 2:
                    color = 0xFFFF;
                    break;
                case 3:
                    color = 0x4F73A3;
                    break;
                case 4:
                    color = 0x0F77F3;
                    break;
                case 5:
                    color = 0xC700;
                    break;
                case 6:
                    color = 0x7B90A2;
                    break;
                case 7:
                    color = 0xADAD00;
                    break;
                default:
                    color = 0xFFFFFF;
                    break;
                }

                SetTextColor(this->render_area->DrawDc, color);
                strcpy(str, comm->GetPlayerName(i));
                TextOutA(this->render_area->DrawDc, x, y + y_offset,
                         str, strlen(str));
                sprintf(str, s_fmt_d,
                        temp_player->victory_conditions->get_victory_points());
                SetRect(&rect, x_val, y + y_offset,
                        this->pnl_x + this->pnl_wid - 3,
                        y + y_offset + 0x0E);
                DrawTextA(this->render_area->DrawDc, str, -1, &rect, 0x22);
                y_offset += 0x0E;
            }
            ++i;
        } while (i < 9);

        SelectObject(this->render_area->DrawDc, old_font);
        this->render_area->ReleaseDc(s_tpnl_obj_draw_score);
    }

    this->draw_finish();
}
