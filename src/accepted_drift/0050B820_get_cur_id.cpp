// VA: 0050B820 get_cur_id (27B, tdlg_lst.cpp)
// ACCEPTED_DRIFT: benign control-flow pattern difference
// Original uses sub/dec/dec/je chain (switch optimization), rebuilt uses 
// early-return jne pattern or range comparison. All behaviorally identical.
// Attempt log:
// v1: if/else chain -> jne early-return pattern
// v2: switch -> range compare
// v3: goto -> almost matched (test/jne vs dec/je for third compare)
// v4: range check -> different still
// Accepted: logic is identical, only control flow encoding differs

class RGE_Dialog_List {
public:
    short get_cur_id();
    char pad_00[0x4AC];
};

class TRIBE_Dialog_List : public RGE_Dialog_List {
public:
    int field_4AC;

    short get_cur_id();
};

short TRIBE_Dialog_List::get_cur_id() {
    int v = field_4AC - 100;
    if (v == 0) goto ret_minus_1;
    if (--v == 0) goto ret_minus_1;
    if (--v == 0) goto ret_minus_1;
    return RGE_Dialog_List::get_cur_id();
ret_minus_1:
    return -1;
}
