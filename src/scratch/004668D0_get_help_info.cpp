// STATUS: blocked
// BLOCKER: active/hit-test gating and child walk are understood, but VC5 still chooses a different parameter-load order around vfBC/vfCC and a shorter byte-copy fallback instead of the original rep-scan/rep-mov string copy shape
// NOTE: last_child traversal, help_string_id/help_page_id fallback, and call boundaries are correct; remaining drift is argument scheduling and fallback copy codegen only

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
    virtual void vf4C(void);
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
    virtual void vf88(void);
    virtual void vf8C(void);
    virtual void vf90(void);
    virtual void vf94(void);
    virtual void vf98(void);
    virtual void vf9C(void);
    virtual void vfA0(void);
    virtual void vfA4(void);
    virtual void vfA8(void);
    virtual void vfAC(void);
    virtual void vfB0(void);
    virtual void vfB4(void);
    virtual void vfB8(void);
    virtual int vfBC(long x, long y);
    virtual void vfC0(void);
    virtual void vfC4(void);
    virtual void vfC8(void);
    virtual unsigned char vfCC(char** out_str, long* out_page, long x, long y);

    char gap_04[0x58];
    PanelNode* last_child_node;
    char gap_60[0x0C];
    int active;
    char gap_70[0x74];
    int help_string_id;
    int help_page_id;

    char* get_string(int string_id);
    unsigned char get_help_info(char** out_str, long* out_page, long x, long y);
};

unsigned char TPanel::get_help_info(char** out_str, long* out_page, long x, long y) {
    PanelNode* node;

    if (active == 0) {
        return 0;
    }
    if (vfBC(x, y) == 0) {
        return 0;
    }
    node = last_child_node;
    while (node != 0) {
        if (node->panel->vfCC(out_str, out_page, x, y)) {
            return 1;
        }
        node = node->prev_node;
    }
    if (help_string_id >= 0) {
        char* src;
        char* dst;

        src = get_string(help_string_id);
        dst = *out_str;
        do {
            *dst = *src;
            dst++;
        } while (*src++ != 0);
        *out_page = help_page_id;
        return 1;
    }
    return 0;
}
