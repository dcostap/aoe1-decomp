// TribeDiplomacyDialog::draw (0043E770)
// PDB source: dlg_dip.cpp:880-903
// Size: 195 bytes
// Calling convention: __thiscall
// BINARY NOTE: PDB order places this protected virtual sibling at 0043E770,
// immediately after check_stone's 0043E767 body. Bytes 0043E768-0043E76F are
// padding data, not a second function. The owning body ends at 0043E832.
// BINARY NOTE: Keep the protected MAEXXZ owner. A public UAEXXZ declaration
// emitted identical body bytes but is not the qualified PDB symbol.
// ACCEPTED_DRIFT: the sole emitted difference is `cmp eax, ebp` in the
// executable versus `test eax, eax` in the rebuild after `xor ebp, ebp`.
// The following branch consumes only ZF, so calls, memory effects, CFG, and
// behavior are identical; all other 193 bytes match positionally.
//
// ATTEMPT LOG:
// - Existing baseline had the right calls but the wrong loop topology and was 19 bytes short.
// - Reconstructed the donor-style do loop: y offset starts at zero before the guard, the world
//   is loaded before draw_setup, the player cursor starts at byte offset 4, and player_num-1 is
//   reloaded at the loop bottom. This moved the result to a 189-byte structural near-match.
// - Named the proven TPanel fields (+0x0C pnl_x, +0x10 pnl_y, +0x20 render_area), corrected the
//   TShape argument ABI, and kept the color-table pointer only through the color call while
//   rereading it for shape_draw. This recovered the original 195-byte body and all other bytes.
// - Restored the exact TPanel -> TEasy_Panel -> TDialogPanel size surface and typed the proven
//   RGE_Player::color_table / RGE_Color_Table fields; emitted bytes stayed unchanged.
// - Guard spelling/declaration probes and two focused guard variant labs (plain, typed/null,
//   integer/alias locals, redundant predicates) all collapsed to the same VC5 output.
// - Best validation: size/frame/call-set and 193/195 bytes match; the sole remaining drift is
//   original `cmp eax,ebp` versus rebuilt `test eax,eax` at +0x14 (2 bytes, no CFG or call drift).
// - No inline asm or custom flags. LEFT IN SCRATCH: the isolated zero-compare instruction
//   appears to require original TU/source context; the initial bounded variant pass was
//   exhausted.
// - Exact-finish pass: restored `protected virtual draw()` after confirming that the
//   byte-identical public form emits the wrong UAEXXZ symbol. Pointer casts, integer and
//   reference zero aliases, redundant predicates, early-return layout, declaration-scope
//   changes, duplicate initialization, period-header context, and computed-zero forms did
//   not recover CMP; the reduced natural source remains 193/195 bytes exact.

#ifndef DLG_DIP_SHARED_CONTEXT
extern "C" int __cdecl _ASMSet_Color_Xform(int param_1);

class TDrawArea;

class TShape {
public:
    unsigned char shape_draw(TDrawArea* param1, long param2, long param3,
                             int param4, unsigned char param5, unsigned char* param6);
};

struct RGE_Game_World {
    unsigned char gap_00[0x3C];
    short player_num;
    unsigned char gap_3E[2];
    class RGE_Player** players;
};

struct RGE_Color_Table {
    unsigned char gap_00[0x26];
    short color_index;
    unsigned char table[0x100];
};

struct RGE_Player {
    unsigned char gap_00[0x108];
    RGE_Color_Table* color_table;
};

struct RGE_Base_Game {
    unsigned char gap_00[0x3F4];
    RGE_Game_World* world;
};

extern RGE_Base_Game* rge_base_game;

struct DipVTable {
    virtual void dd00() = 0; virtual void dd01() = 0;
    virtual void dd02() = 0; virtual void dd03() = 0;
    virtual void dd04() = 0; virtual void dd05() = 0;
    virtual void dd06() = 0; virtual void dd07() = 0;
    virtual void dd08() = 0; virtual void dd09() = 0;
    virtual void draw_setup(int) = 0;   // vt[10] = 0x28
    virtual void draw_finish() = 0;      // vt[11] = 0x2C
};

class TPanel {
public:
    virtual void draw();
    char gap_04[0x08];
    long pnl_x;
    long pnl_y;
    char gap_14[0x0C];
    TDrawArea* render_area;
    char _pad_24[0xF4 - 0x24];
};

class TEasy_Panel : public TPanel {
public:
    char _pad_F4[0x478 - 0xF4];
    virtual void draw();
};

class TDialogPanel : public TEasy_Panel {
public:
    char _pad_478[0x490 - 0x478];
};

class TribeDiplomacyDialog : public TDialogPanel {
protected:
    char _pad_490[0x60C - 0x490];
    TShape* backgroundPics;
    virtual void draw();
};
#endif

void TribeDiplomacyDialog::draw()
{
    int yOff;
    TEasy_Panel::draw();
    yOff = 0;
    if (backgroundPics != 0)
    {
        RGE_Game_World* w = rge_base_game->world;
#ifdef DLG_DIP_SHARED_CONTEXT
        this->draw_setup(0);
#else
        ((DipVTable*)this)->draw_setup(0);
#endif
        if (w->player_num - 1 > 0)
        {
            int i = 0;
            int playerOffset = 4;
            do
            {
                RGE_Player* player = *(RGE_Player**)((char*)w->players + playerOffset);
                RGE_Color_Table* f = player->color_table;
                if (f != 0)
                {
                    _ASMSet_Color_Xform(
                        (f->color_index + 1) * 16);
                    backgroundPics->shape_draw(
                        this->render_area,
                        this->pnl_x + 0x0A,
                        this->pnl_y + yOff + 0x50,
                        0,
                        1,
                        (*(RGE_Player**)((char*)w->players + playerOffset))->color_table->table
                    );
                }
                yOff += 0x1E;
                playerOffset += 4;
                ++i;
            } while (i < w->player_num - 1);
        }
#ifdef DLG_DIP_SHARED_CONTEXT
        this->draw_finish();
#else
        ((DipVTable*)this)->draw_finish();
#endif
    }
}
