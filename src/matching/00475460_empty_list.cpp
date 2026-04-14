class MemberType {
public:
    void empty_list();
};

class TDropDownPanel {
public:
    char gap_0[0xFC];
    MemberType* member_FC;

    void empty_list();
};

void TDropDownPanel::empty_list() {
    if (this->member_FC) {
        this->member_FC->empty_list();
    }
}
