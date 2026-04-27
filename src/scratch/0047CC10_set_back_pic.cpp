// 0047CC10_set_back_pic
// Probe 1: structural stub
class TPanel { public: char _gap_00[4]; };
class TTextPanel : public TPanel { public: char _gap_04[0x14c]; void set_back_pic(int); };
void TTextPanel::set_back_pic(int) {  }
