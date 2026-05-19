// 0047D200 TTextPanel::action
// Source: Pnl_txt.cpp lines 927-955
// Probe 1: structural stub emitted only 16 bytes.
// Fresh 2026-05-19 try 2: packet-derived TTextPanel layout, natural switch, direct base action.

class TPanel {
public:
    long action(TPanel* panel, long msg, unsigned long p1, unsigned long p2);
};

class TTextPanel : public TPanel {
public:
    char gap_04[0x130];
    TPanel* scbar_panel; // +0x130

    void scroll(unsigned char code, unsigned long pos, unsigned long flag);
    long action(TPanel* panel, long msg, unsigned long p1, unsigned long p2);
};

long TTextPanel::action(TPanel* panel, long msg, unsigned long p1, unsigned long p2)
{
    if (this->scbar_panel && panel == this->scbar_panel) {
        switch (msg) {
        case 0:
            this->scroll(3, 0, 1);
            return 1;
        case 1:
            this->scroll(2, 0, 1);
            return 1;
        case 2:
            this->scroll(5, 0, 1);
            return 1;
        case 3:
            this->scroll(4, 0, 1);
            return 1;
        case 4:
            this->scroll(1, p1, 0);
            return 1;
        }
    }
    return TPanel::action(panel, msg, p1, p2);
}
