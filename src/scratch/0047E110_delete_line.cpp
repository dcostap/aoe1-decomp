// 0047E110_delete_line
// Probe 1: structural stub
class TPanel { public: char _gap_00[4]; };
class TTextPanel : public TPanel { public: char _gap_04[0x14c]; void delete_line(int); };
void TTextPanel::delete_line(int) {  }
