class InnerType {
public:
    char gap_0[0x4A];
    short field_4A;
};

class TRIBE_Panel_Pop {
public:
    char gap_0[0x10C];
    InnerType* member_10C;

    int get_player_id();
};

int TRIBE_Panel_Pop::get_player_id() {
    if (this->member_10C) {
        return this->member_10C->field_4A;
    }
    return 0;
}
