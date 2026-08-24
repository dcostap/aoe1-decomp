#ifndef PNL_DROP_CONTEXT
class MemberType {
public:
    int get_id();
};
class TDropDownPanel {
public:
    char gap_0[0xFC];
    MemberType* member_FC;

    int get_id();
};
#endif

int TDropDownPanel::get_id() {
    if (this->member_FC) {
        return this->member_FC->get_id();
    }
    return 0;
}
