// 0047D200_action
// Probe 1: structural stub
class TPanel { public: char _gap_00[4]; };
class TTextPanel : public TPanel { public: char _gap_04[0x14c]; int action(int,int); };
int TTextPanel::action(int,int) { return 0; }
