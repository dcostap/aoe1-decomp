#ifndef PNL_DROP_CONTEXT
class MemberType {
public:
    int currentLineNumber();
};

class TDropDownPanel {
public:
    char gap_0[0xFC];
    MemberType* member_FC;

    int currentLineNumber();
};
#endif

int TDropDownPanel::currentLineNumber() {
    if (this->member_FC) {
        return this->member_FC->currentLineNumber();
    }
    return 0;
}
