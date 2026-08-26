#ifndef PNL_DROP_CONTEXT
#ifndef PNL_DROP_CONTEXT
class MemberType {
public:
    int currentLine();
};
#endif

class TDropDownPanel {
public:
    char gap_0[0xFC];
    MemberType* member_FC;

    int currentLine();
};
#endif

char* TDropDownPanel::currentLine() {
    if (this->member_FC) {
        return this->member_FC->currentLine();
    }
    return 0;
}
