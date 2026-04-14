class MemberType {
public:
    int currentLine();
};

class TDropDownPanel {
public:
    char gap_0[0xFC];
    MemberType* member_FC;

    int currentLine();
};

int TDropDownPanel::currentLine() {
    if (this->member_FC) {
        return this->member_FC->currentLine();
    }
    return 0;
}
