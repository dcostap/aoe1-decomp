// TRIBE_Dialog_List::get_cur_id (27B)
// Attempt log:
// v6: compound expression approach

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
    int v = field_4AC;
    if (v <= 102 && v >= 100) {
        return -1;
    }
    return RGE_Dialog_List::get_cur_id();
}
