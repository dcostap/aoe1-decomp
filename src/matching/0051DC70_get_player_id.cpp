class InnerType {
public:
    char gap_0[0x4A];
    short field_4A;
};

class TRIBE_Panel_Time {
public:
    char gap_0[0x118];
    InnerType* member_118;

    int get_player_id();
};

int TRIBE_Panel_Time::get_player_id() {
    if (this->member_118) {
        return this->member_118->field_4A;
    }
    return 0;
}
