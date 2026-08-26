#ifndef PNL_DROP_CONTEXT
class MemberType {
public:
    int get_line();
};
class TDropDownPanel {
public:
    char gap_0[0xFC];
    MemberType* member_FC;

    int get_line();
};
#endif

long TDropDownPanel::get_line() {
    if (this->member_FC) {
        return this->member_FC->get_line();
    }
    return 0;
}
