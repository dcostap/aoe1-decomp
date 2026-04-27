// 0047C3B0_set_rect
// Probe 1: structural stub
class TPanel { public: char _gap_00[4]; };
class TTextPanel : public TPanel { public: char _gap_04[0x14c]; void set_rect(int,int,int,int,int,int,int,int,int); };
void TTextPanel::set_rect(int,int,int,int,int,int,int,int,int) {  }
