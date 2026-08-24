#ifndef PNL_DROP_CONTEXT
class MemberType {
public:
    int numberLines();
};

class TDropDownPanel {
public:
    char gap_0[0xFC];
    MemberType* member_FC;

    int numberLines();
};
#endif

int TDropDownPanel::numberLines() {
    if (this->member_FC) {
        return this->member_FC->numberLines();
    }
    return 0;
}
