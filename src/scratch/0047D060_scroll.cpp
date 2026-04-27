// 0047D060_scroll
// Probe 1: structural stub
class TPanel { public: char _gap_00[4]; };
class TTextPanel : public TPanel { public: char _gap_04[0x14c]; void scroll(int,int); };
void TTextPanel::scroll(int,int) {  }
