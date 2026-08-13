// 00467380 TEasy_Panel::setup_shadow_area (Panel_ez.cpp:331-370)
// Attempt log:
// 1: Natural source with manual operator_new/placement ctor: no EH prologue, 400B; also TDrawSystem flags offset wrong.
// 2: Real new + TDrawSystem +0x28 triggers EH but sizeof(TDrawArea)=1 and frame 0x114.
// 3: Force sizeof(TDrawArea)=0x100: size matches after padding, but frame is 0x114 and draw_system indirection wrong.
// 4: Model draw_system holder: improves data flow but frame still +4 due hidden new temp.
// 5: Shrink area_name by 4 recovers 0x110 frame but hidden new temp at [esp+20] shifts area_name uses.
// 6: Assign new result through y_max slot improved edit diff to 23.3 but added store and shifted shape locals; kept as clue.
// 7: Explicit holder local worsened frame to 0x114 and spilled old_flags; rolled back.
// 8: Direct holder/no y_max store returns to 65.47%/27.33%.
// 9: area_name[248] regressed to frame mismatch; rolled back.
// 10: Explicit p local made no codegen difference.
// 11: Passing area_name to ctor only moves ctor lea to +24, sprintf still shifted.
// 12: Using area_name for sprintf moves to +28 but not original +20.
// 13: Reordering locals did not move hidden new temp; shape_minmax arg LEAs differ.
// 14: shape arg order variant improved edit to 26.9; first LEA matches but others differ.
// 15: Second shape arg order still 26.9; LEAs [14,1c,18,28].
// 16: Third shape arg order matches original LEA sequence [14,20,18,24].
// 17: Separate flags local no codegen change.
// 18: Reload draw system pointer inside creation block improved to final 65.04% positional / 25.21% edit.
// 19: Restored canonical ownership from the ground-truth layouts: +0x20 is TPanel::render_area
//     (TDrawArea*), whose +0 DrawSystem points at TDrawSystem::Flags, not a synthetic holder.
//     Used the proven reference-output/long/byte method ABIs and the area_name+4 overlay shown by
//     the original stack addresses.  This is the clean source reconstruction being tested.
// 20: The canonical ABI/layout source reached 342 differing bytes before the proven dword overlay
//     was restored; the overlay is behaviorally required even though its stack home remains shifted.
// 21: Removing a named DrawSystem alias, assigning new directly to shadow_area, adding a new-area
//     local, swapping output-local declarations, and restoring windows.h/new.h context were all
//     duplicate codegen basins (final 356 differing bytes, 472-byte size/frame, 11/11 calls).
// 22: A named area_name+4 pointer was also a duplicate.  Remaining blocker is the first EH/new
//     local-layout hunk: original reloads flags through EDX and reuses [esp+10] while VC5 keeps
//     the canonical candidate's allocation/area homes at different offsets.  Left in scratch.
// 23: Retaining a natural TDrawSystem pointer across flags, allocation, Init, and restoration
//     improved positional diff to 348 but grew the frame to 0x114 and worsened block shape;
//     rolled back to the clean direct-access reconstruction.
// 24: Scoping a natural TDrawSystem pointer only across the flag mask and TDrawArea allocation
//     lifetime produced duplicate codegen (356 differing bytes, 0x110 frame); rolled back.
// 25: Scoping the three shape output locals inside the post-allocation block reused the EH
//     allocation home at [esp+10] and recovered the original output stack homes, but reduced
//     the frame to 0x10C.
// 26: Hoisting width and height did not change codegen; restored their natural inner scope.
// 27: Increasing area_name to 260 bytes recovered the original 0x110 frame and raised shape
//     similarity to 94.48%; the positional diff remained 356 bytes.
// 28: A scoped DrawSystem pointer, explicit field-mask assignment, and area_name+4 pointer
//     were duplicate codegen basins; restored the simplest direct member expressions.
// FLAGS: config/flags/00467380_setup_shadow_area.rsp uses /GX; needed for EH prologue around TDrawArea allocation/constructor.

#include <windows.h>
#include <new.h>
#include <stdio.h>

class TDrawSystem {
public:
    char gap_00[0x28];
    unsigned long Flags;
};

class TDrawArea {
public:
    TDrawSystem* DrawSystem;
    char gap_04[0xFC];

    TDrawArea(char* name, int type);
    int Init(TDrawSystem* system, long width, long height, int a, int b);
    void Clear(tagRECT* rect, int color);
    unsigned char* Lock(char* where, int flag);
    void SetShadowTable(class RGE_Color_Table* table);
    void DrawShadowBox(long x1, long y1, long x2, long y2);
    void Unlock(char* where);
};

class RGE_Color_Table;

class TShape {
public:
    unsigned char shape_minmax(long& out_minx, long& out_miny,
                               long& out_maxx, long& out_maxy,
                               long frame);
    unsigned char shape_draw(TDrawArea* area, long x, long y, long frame,
                             unsigned char color_flag, unsigned char* color_table);
};

class TPanel {
public:
    virtual ~TPanel();

    char gap_04[0x10];
    long pnl_wid;                         // +0x14
    long pnl_hgt;                         // +0x18
    char* panelNameValue;                 // +0x1C
    TDrawArea* render_area;               // +0x20
    char gap_24[0xD0];                     // sizeof(TPanel) == 0xF4
};

class TEasy_Panel : public TPanel {
public:
    char gap_F4[0x110];                   // +0xF4 to +0x203
    TShape* background_pic;               // +0x204
    char gap_208[0x244];                  // +0x208 to +0x44B
    RGE_Color_Table* shadow_color_table;  // +0x44C
    char gap_450[4];                       // +0x450 to +0x453
    unsigned char background_color1;      // +0x454
    char gap_455[0x17];                    // +0x455 to +0x46B
    TDrawArea* shadow_area;               // +0x46C

    void setup_shadow_area(int force);
};

void TEasy_Panel::setup_shadow_area(int force)
{
    char area_name[260];

    TDrawArea* area = this->shadow_area;
    if ((area == 0 || force != 0) &&
        this->background_pic != 0 && this->shadow_color_table != 0) {
        int old_flags = this->render_area->DrawSystem->Flags;

        if (area == 0) {
            this->render_area->DrawSystem->Flags &= 1;
            sprintf(area_name + 4, "%s Shadow Panel", this->panelNameValue);
            this->shadow_area = new TDrawArea(area_name + 4, 0);
        }

        if (this->shadow_area != 0) {
            long y_max;
            long x_min;
            long x_max;

            this->background_pic->shape_minmax(
                x_max, y_max, *(long*)area_name, x_min, 0);

            int width = *(long*)area_name - x_max + 1;
            int height = x_min - y_max + 1;
            if (width > this->pnl_wid)
                width = this->pnl_wid;
            if (height > this->pnl_hgt)
                height = this->pnl_hgt;

            if (this->shadow_area->Init(this->render_area->DrawSystem,
                                        width, height, 0, 0)) {
                this->shadow_area->Clear(0, this->background_color1);
                if (this->shadow_area->Lock("panel_ez::setup_shadow_area", 1)) {
                    this->background_pic->shape_draw(this->shadow_area,
                                                     0, 0, 0, 0, 0);
                    this->shadow_area->SetShadowTable(this->shadow_color_table);
                    this->shadow_area->DrawShadowBox(0, 0, width - 1, height - 1);
                    this->shadow_area->Unlock("panel_ez::setup_shadow_area");
                }
            }
        }

        this->render_area->DrawSystem->Flags = old_flags;
    }
}
