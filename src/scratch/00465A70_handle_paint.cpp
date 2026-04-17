// STATUS: blocked
// BLOCKER: layout and call offsets are understood, but VC5 still delays the esi save until after the early visibility/activity gates, so the prologue/epilogue never matches the original push-esi-first shape
// NOTE: render-area/active checks, child redraw loop, overlapping-parent callback, vf30 paint call, and just_drawn toggles all match semantically; remaining drift is register/prologue scheduling only

extern "C" __declspec(dllimport) int __stdcall IsIconic(void* hWnd);

class RGE_Base_Game {
public:
    char gap_00[0x18];
    int prog_active;
};

extern RGE_Base_Game* rge_base_game;

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

long TPanel::handle_paint(void) {
    PanelNode* node;
    ParentPanel* parent;

    if (render_area != 0 && visible != 0 && active != 0 && rge_base_game->prog_active != 0 && IsIconic(render_area->Wnd) == 0) {
        if (need_redraw != 0) {
            node = first_child_node;
            while (node != 0) {
                node->panel->vf20(need_redraw);
                node = node->next_node;
            }
            parent = parent_panel;
            if (parent != 0 && parent->overlapping_children != 0) {
                parent->vf24(this, this, need_redraw);
            }
            vf30();
            need_redraw = 0;
            just_drawn = 1;
        }
        node = first_child_node;
        while (node != 0) {
            node->panel->vf54();
            node = node->next_node;
        }
        just_drawn = 0;
    }
    return 0;
}
