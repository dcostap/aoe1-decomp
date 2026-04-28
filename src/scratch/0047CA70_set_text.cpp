// 0047CA70 TTextPanel::set_text
// Size: 63 bytes, diff: 2 bytes (3.17%)
//
// Remaining gap: [esp+4] vs [esp+8] — VC5 stack liveness optimization
// Original places char str[4096] at [ESP+0], overlapping str[0..3] with saved ESI.
// str+4 = [ESP+4]. This is a VC5 optimization where the array's dead prefix bytes
// are reused as the register save slot.
//
// Our rebuilt places str at [ESP+4], saving ESI at [ESP+0] separately.
// str+4 = [ESP+8].
//
// Tried (all same result):
// - virtual ~TPanel() (slot alignment)
// - Different class names (TTextPanel vs TTTextPanel)
// - #pragma pack(4)
// - struct with pad[4]+data[4092] layout
// - char str[0x1000] / char str[4100]
// - &str[4] syntax
// - Removing all non-destructor virtual functions
//
// This looks like a VC5 register-allocation basin that differs between the
// original TU context (Pnl_txt.cpp) and our isolated compilation.
// 2 bytes, highly localized — candidate for variant_lab if needed.

#include <stdlib.h>

class TPanel {
public:
    virtual ~TPanel();
    char gap_0[0xF0];
    int get_string(int, char*, int);
};

class TTextPanel : public TPanel {
public:
    void set_text(long id);
    virtual void set_text2(char* text);
    char* list;
};

void TTextPanel::set_text(long id) {
    char str[4096];

    TPanel::get_string(id, str + 4, 0x1000);
    this->set_text2(str + 4);
}
