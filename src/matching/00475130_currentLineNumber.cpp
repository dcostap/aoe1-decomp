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

int TDropDownPanel::currentLineNumber() {
    if (this->member_FC) {
        return this->member_FC->currentLineNumber();
    }
    return 0;
}
