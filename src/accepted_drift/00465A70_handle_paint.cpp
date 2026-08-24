// ACCEPTED_DRIFT: reviewed 2026-05-26 by orchestrator. Body/calls/memory effects match after resync; diff is an extra early zeroing of ESI, shifted branch displacements, and equivalent zero-return epilogue (`mov eax,esi` vs `xor eax,eax`). ESI is zero on all early exits and after child-list exhaustion; real child uses reload ESI before dereference.
// STATUS: blocked
// BLOCKER: layout and call offsets are understood, but VC5 still delays the esi save until after the early visibility/activity gates, so the prologue/epilogue never matches the original push-esi-first shape
// NOTE: render-area/active checks, child redraw loop, overlapping-parent callback, vf30 paint call, and just_drawn toggles all match semantically; remaining drift is register/prologue scheduling only
// 2026-05-26 Boss retry: 10+ probes. Tried function-scope node init/return forms, draw/visible/active locals, positive return-node tail,
// first_child_node preinit, /O1 and /Ob0 flag probes, direct-address rge_base_game, `this`-derived node init, volatile node, and macro global.
// Best kept improves to edit diff 6.6298% (12 edit bytes): exact call/body order except an extra `xor esi,esi` after `mov edi,ecx`,
// shifted branch displacements, and tail `mov eax,esi; pop edi; pop esi; ret` instead of `pop edi; xor eax,eax; pop esi; ret`.
// GIVEUP exact. Possible accepted_drift candidate if reviewed: ESI is zero on every early exit and loop exhaustion path, and all real ESI
// uses reload child nodes before dereference; remaining diff is equivalent zero-return/register scheduling plus branch displacement shifts.

extern "C" __declspec(dllimport) int __stdcall IsIconic(void* hWnd);

#ifndef AOE1_PANEL_CONTEXT_H
class RGE_Base_Game {
public:
    char gap_00[0x18];
    int prog_active;
};

#define rge_base_game (*(RGE_Base_Game**)0x62C574)

struct TDrawArea {
    char gap_00[4];
    void* Wnd;
};

class TPanel;

struct PanelNode {
    TPanel* panel;
    PanelNode* prev_node;
    PanelNode* next_node;
};

class ParentPanel {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual void vf18(void);
    virtual void vf1C(void);
    virtual void vf20(void);
    virtual void vf24(TPanel* a1, TPanel* a2, int a3);

    char gap_28[0x78];
    int overlapping_children;
};

class TPanel {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual void vf18(void);
    virtual void vf1C(void);
    virtual void vf20(int redraw_mode);
    virtual void vf24(void);
    virtual void vf28(void);
    virtual void vf2C(void);
    virtual long vf30(void);
    virtual void vf34(void);
    virtual void vf38(void);
    virtual void vf3C(void);
    virtual void vf40(void);
    virtual void vf44(void);
    virtual void vf48(void);
    virtual void vf4C(void);
    virtual void vf50(void);
    virtual long vf54(void);

    char gap_04[0x1C];
    TDrawArea* render_area;
    char gap_24[0x10];
    int position_mode;
    int need_redraw;
    int field_3C;
    ParentPanel* parent_panel;
    char gap_44[0x10];
    PanelNode* node;
    PanelNode* first_child_node;
    char gap_5C[0x10];
    int active;
    int visible;
    char gap_74[0x10];
    int just_drawn;

    long handle_paint(void);
};

#endif
long TPanel::handle_paint(void) {
    PanelNode* node = 0;
        TPanel* parent;

    if (render_area != 0 && visible != 0 && active != 0 && rge_base_game->prog_active != 0 && IsIconic(render_area->Wnd) == 0) {
        if (need_redraw != 0) {
            node = first_child_node;
            while (node != 0) {
                node->panel->set_redraw(need_redraw);
                node = node->next_node;
            }
            parent = parent_panel;
            if (parent != 0 && parent->overlapping_children != 0) {
                parent->set_overlapped_redraw(this, this, need_redraw);
            }
            draw();
            need_redraw = 0;
            just_drawn = 1;
        }
        node = first_child_node;
        while (node != 0) {
            node->panel->handle_paint();
            node = node->next_node;
        }
        just_drawn = 0;
    }
    if (node == 0)
        return 0;
    return (long)node;
}
