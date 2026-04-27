// 0047CD40_set_bevel_info
// Probe 1: structural stub
class TPanel { public: char _gap_00[4]; };
class TTextPanel : public TPanel { public: char _gap_04[0x14c]; void set_bevel_info(int,int,int,int,int,int,int); };
void TTextPanel::set_bevel_info(int,int,int,int,int,int,int) {  }
