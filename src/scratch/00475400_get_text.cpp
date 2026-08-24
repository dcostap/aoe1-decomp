#ifndef PNL_DROP_CONTEXT
class MemberType {
public:
};
class TDropDownPanel {
public:
    char gap_0[0xFC];
    MemberType* member_FC;

    char* get_text(long param);
};
#endif

char* TDropDownPanel::get_text(long param) {
    if (this->member_FC) {
        return this->member_FC->get_text(param);
    }
    return 0;
}
