extern "C" unsigned long __cdecl debug_timeGetTime(const char* file, int line);

#ifndef AOE1_PANEL_CONTEXT_H
class TPanel;

struct PanelNode {
    TPanel* panel;
    PanelNode* prev_node;
    PanelNode* next_node;
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
    virtual void vf20(void);
    virtual void vf24(void);
    virtual void vf28(void);
    virtual void vf2C(void);
    virtual void vf30(void);
    virtual void vf34(void);
    virtual void vf38(void);
    virtual void vf3C(void);
    virtual void vf40(void);
    virtual void vf44(void);
    virtual void vf48(void);
    virtual long vf4C(void);
    virtual void vf50(void);
    virtual void vf54(void);
    virtual void vf58(void);
    virtual void vf5C(void);
    virtual void vf60(void);
    virtual void vf64(void);
    virtual void vf68(void);
    virtual void vf6C(void);
    virtual void vf70(void);
    virtual void vf74(void);
    virtual void vf78(void);
    virtual void vf7C(void);
    virtual void vf80(void);
    virtual void vf84(void);
    virtual void vf88(int a1, int a2, int a3, int a4);
    virtual void vf8C(void);
    virtual void vf90(void);
    virtual void vf94(void);
    virtual void vf98(void);
    virtual void vf9C(int a1, int a2, int a3, int a4);

    char gap_04[0x58];
    PanelNode* last_child_node;
    char gap_60[0x0C];
    int active;
    int field_70;
    int have_focus;
    int field_78;
    int field_7C;
    int field_80;
    int gap_84;
    int clip_rgn;
    int field_8C;
    int field_90;
    int field_94;
    int field_98;
    int field_9C;
    int field_A0;
    int field_A4;
    int field_A8;
    int field_AC;
    int field_B0;
    int field_B4;
    int field_B8;
    int mouse_hold_interval;
    int field_C0;
    int mouse_down_ctrl;
    int mouse_down_x;
    int mouse_down_y;
    int mouse_down_shift;
    int mouse_down_time;
    char gap_D8[0x14];
    unsigned char mouse_action;
    unsigned char mouse_down_button;

    long handle_idle(void);
};

#endif
long TPanel::handle_idle(void) {
    PanelNode* node;
    long result;

    if (active != 0 && mouse_action == 1) {
        if ((int)(debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Panel.cpp", 0x5FD) - mouse_down_time) >= mouse_hold_interval) {
            mouse_action = 2;
            if (mouse_down_button == 1) {
                mouse_left_hold_action(mouse_down_ctrl, mouse_down_x, mouse_down_y, mouse_down_shift);
            } else {
                mouse_right_hold_action(mouse_down_ctrl, mouse_down_x, mouse_down_y, mouse_down_shift);
            }
        }
    }

    node = last_child_node;
    while (node != 0) {
                result = node->panel->handle_idle();
        if (result != 0) {
            return result;
        }
        node = node->prev_node;
    }
    return 0;
}
