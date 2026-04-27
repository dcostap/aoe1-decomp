// 0047D120_key_down_action
// Probe 1: structural stub
class TPanel { public: char _gap_00[4]; };
class TTextPanel : public TPanel { public: char _gap_04[0x14c]; void key_down_action(int,int); };
void TTextPanel::key_down_action(int,int) {  }
