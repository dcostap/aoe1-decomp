// 0047C560_set_text
// Probe 1: structural stub
class TPanel { public: char _gap_00[4]; };
class TTextPanel : public TPanel { public: char _gap_04[0x14c]; void set_text(int,int,char); };
void TTextPanel::set_text(int,int,char) {  }
