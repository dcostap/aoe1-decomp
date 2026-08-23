// attempt 1: natural null-check + virtual helper call + item/goto range gate
// result: exact match after restoring the base layout and reversing the range compare into the original VC5 basin
// moved to src\matching\004784A0_mouse_move_action.cpp after local validation

#ifndef AOE1_PNL_LST_CONTEXT_H
class TTextPanel {
public:
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual int is_inside(long param_1, long param_2);

    char gap_00[0xF8];
    short item_min;
    short item_max;
    char gap_100[0x88];
};

class TListPanel : public TTextPanel {
public:
    int auto_track;

    short item_at(long param_1, long param_2);
    void goto_item(long param_1, long param_2);
    long mouse_move_action(long param_1, long param_2, int param_3, int param_4);
};
#endif

long TListPanel::mouse_move_action(long param_1, long param_2, int, int) {
    if (this->auto_track == 0) {
        return 0;
    }

    if (this->is_inside(param_1, param_2) == 0) {
        return 0;
    }

    short item = this->item_at(param_1, param_2);
    if (item < this->item_min) {
        return 1;
    }
    if (item > this->item_max) {
        return 1;
    }
    this->goto_item(param_1, param_2);

    return 1;
}
