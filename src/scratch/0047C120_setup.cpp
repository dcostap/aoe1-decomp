// 0047C120_setup
// Probe 1: structural stub
class TPanel { public: char _gap_00[4]; };
class TTextPanel : public TPanel { public: char _gap_04[0x14c]; void setup(int,int,int,int,int,int,int,int,int,int); };
void TTextPanel::setup(int,int,int,int,int,int,int,int,int,int) {  }
