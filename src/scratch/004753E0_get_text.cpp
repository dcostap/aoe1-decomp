class MemberType {
public:
    int get_text();
};

class TDropDownPanel {
public:
    char gap_0[0xFC];
    MemberType* member_FC;

    int get_text();
};

int TDropDownPanel::get_text() {
    if (this->member_FC) {
        return this->member_FC->get_text();
    }
    return 0;
}
