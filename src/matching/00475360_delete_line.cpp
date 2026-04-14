class MemberType {
public:
    int target_method(int param);
};

class TDropDownPanel {
public:
    char gap_0[0xFC];
    MemberType* member_FC;

    int delete_line(int param);
};

int TDropDownPanel::delete_line(int param) {
    if (this->member_FC) {
        return this->member_FC->target_method(param);
    }
    return 0;
}
