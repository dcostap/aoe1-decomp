#ifndef PNL_DROP_CONTEXT
class MemberType {
public:
};
class TDropDownPanel {
public:
    char gap_0[0xFC];
    MemberType* member_FC;

    int get_line(long param);
};
#endif

int TDropDownPanel::get_line(long param) {
    if (this->member_FC) {
        return this->member_FC->get_line(param);
    }
    return 0;
}
