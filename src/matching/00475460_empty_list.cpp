#ifndef PNL_DROP_CONTEXT
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
#endif

void TDropDownPanel::empty_list() {
    if (this->member_FC) {
        this->member_FC->empty_list();
    }
}
