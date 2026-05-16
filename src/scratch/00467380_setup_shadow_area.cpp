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
// FLAGS: config/flags/00467380_setup_shadow_area.rsp uses /GX; needed for EH prologue around TDrawArea allocation/constructor.
// Left in scratch: behavior/calls/field offsets mostly understood. Remaining blocker is VC5 EH-new/local layout and scheduling: rebuilt uses hidden new temp at [esp+20] and shifted sprintf/ctor buffer LEAs; original reuses [esp+10]. Flag-mask block is close but still has register/scheduling drift (`mov eax,[eax]` vs original `mov edx,[eax]`, early buffer LEA). Later calls/shape args are much closer after arg-order probe.

extern "C" int __cdecl sprintf(char*, const char*, ...);

class TDrawSystem { public: char pad_00[0x28]; int flags; };
class TDrawSystemHolder { public: TDrawSystem* sys; };
class TDrawArea {
public:
    char size_pad[0x100];
    TDrawArea(char* name, int type);
    int Init(TDrawSystem* sys, int w, int h, int a, int b);
    void Clear(void* rect, unsigned int color);
    unsigned char* Lock(char* where, int flag);
    void SetShadowTable(void* table);
    void DrawShadowBox(long x1, long y1, long x2, long y2);
    void Unlock(char* where);
};
class TShape {
public:
    unsigned char shape_minmax(long* x_max, long* y_max, long* y_min, long* x_min, int flag);
    unsigned char shape_draw(TDrawArea* area, int a, int b, int c, int d, int e);
};

class TEasy_Panel {
public:
    void* vtbl;                 // +00
    char pad04[0x14-4];
    int width;                  // +14
    int height;                 // +18
    char* name;                 // +1c
    TDrawSystemHolder* draw_system; // +20
    char pad24[0x204-0x24];
    TShape* background_pic;     // +204
    char pad208[0x44c-0x208];
    void* shadow_color_table;   // +44c
    char pad450[0x454-0x450];
    unsigned char background_color1; // +454
    char pad455[0x46c-0x455];
    TDrawArea* shadow_area;     // +46c

    void setup_shadow_area(int force);
};

void TEasy_Panel::setup_shadow_area(int force)
{
    char area_name[252];
    long y_min;
    long y_max;
    long x_min;
    long x_max;

    TDrawArea* area = this->shadow_area;
    if ((area == 0 || force != 0) && this->background_pic != 0 && this->shadow_color_table != 0) {
        TDrawSystem* ds = this->draw_system->sys;
        int old_flags = ds->flags;
        if (area == 0) {
            TDrawSystem* ds2 = this->draw_system->sys;
            int flags = ds2->flags;
            flags &= 1;
            ds2->flags = flags;
            sprintf(area_name, "%s Shadow Panel", this->name);
            TDrawArea* p = new TDrawArea(area_name, 0);
            this->shadow_area = p;
        }
        area = this->shadow_area;
        if (area != 0) {
            this->background_pic->shape_minmax(&y_max, &x_min, &y_min, &x_max, 0);
            int w = y_min - y_max + 1;
            int h = x_min - x_max + 1;
            if (w > this->width) w = this->width;
            if (h > this->height) h = this->height;
            if (this->shadow_area->Init(this->draw_system->sys, w, h, 0, 0)) {
                this->shadow_area->Clear(0, this->background_color1);
                if (this->shadow_area->Lock("panel_ez::setup_shadow_area", 1)) {
                    this->background_pic->shape_draw(this->shadow_area, 0, 0, 0, 0, 0);
                    this->shadow_area->SetShadowTable(this->shadow_color_table);
                    this->shadow_area->DrawShadowBox(0, 0, w - 1, h - 1);
                    this->shadow_area->Unlock("panel_ez::setup_shadow_area");
                }
            }
        }
        this->draw_system->sys->flags = old_flags;
    }
}
