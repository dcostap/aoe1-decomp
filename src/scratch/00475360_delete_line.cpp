#ifndef PNL_DROP_CONTEXT
class MemberType {
public:
};
class TDropDownPanel {
public:
    char gap_0[0xFC];
    MemberType* member_FC;

    int delete_line(long param);
};
#endif

int TDropDownPanel::delete_line(long param) {
    if (this->member_FC) {
        return this->member_FC->delete_line(param);
    }
    return 0;
}
