// STATUS: active lead
// the subtract/decrement chain is now close, but VC5 still falls into a final zero-test basin instead of the original third `dec` / `jz` / tail-jump family
// explicit statement-split decrements did not escape that basin, so the remaining gap is localized to the third check / tail-jump shape

class RGE_Dialog_List {
public:
    virtual short get_cur_id();
};

class TRIBE_Dialog_List : public RGE_Dialog_List {
public:
    char gap_04[0x4A8];
    int field_4AC;

    short get_cur_id();
};

short TRIBE_Dialog_List::get_cur_id() {
    int value;

    value = this->field_4AC;
    value = value - 100;
    if (value == 0) {
        goto fail;
    }
    value = value - 1;
    if (value == 0) {
        goto fail;
    }
    value = value - 1;
    if (value == 0) {
        goto fail;
    }
    return RGE_Dialog_List::get_cur_id();
fail:
    return -1;
}
