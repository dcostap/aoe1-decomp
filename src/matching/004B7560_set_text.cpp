#include "../../include/scr_stms_context.h"

// Attempt log:
// - The shared overloaded TTextPanel view emitted vslot +0xE0; the oracle
//   uses +0xE8.
// - The donor-backed declaration-only view reached +0xE4 with overloaded
//   names, then +0xEC with 57 placeholders and unique names.
// - The reduced 56-slot view with unique names emits the exact +0xE8 call.
// - Walkbacks proved both the unique names and the 56-slot count are needed.
// - Candidate scr_stms.cpp validation matches all five owners and its one
//   compiler-generated destructor.
// BINARY NOTE: scr_stms.cpp uses the Pnl_txt text surface.  Its long and
// char* overloads occupy +0xE4 and +0xE8.  The shared status context keeps a
// narrower declaration for the other constructor calls, so this local view
// preserves the proven call slot without changing shared ownership.
// This declaration-only view does not construct or own a text-panel object.
class Status_Text_Panel {
public:
    virtual void vf00(); virtual void vf01(); virtual void vf02(); virtual void vf03();
    virtual void vf04(); virtual void vf05(); virtual void vf06(); virtual void vf07();
    virtual void vf08(); virtual void vf09(); virtual void vf0A(); virtual void vf0B();
    virtual void vf0C(); virtual void vf0D(); virtual void vf0E(); virtual void vf0F();
    virtual void vf10(); virtual void vf11(); virtual void vf12(); virtual void vf13();
    virtual void vf14(); virtual void vf15(); virtual void vf16(); virtual void vf17();
    virtual void vf18(); virtual void vf19(); virtual void vf1A(); virtual void vf1B();
    virtual void vf1C(); virtual void vf1D(); virtual void vf1E(); virtual void vf1F();
    virtual void vf20(); virtual void vf21(); virtual void vf22(); virtual void vf23();
    virtual void vf24(); virtual void vf25(); virtual void vf26(); virtual void vf27();
    virtual void vf28(); virtual void vf29(); virtual void vf2A(); virtual void vf2B();
    virtual void vf2C(); virtual void vf2D(); virtual void vf2E(); virtual void vf2F();
    virtual void vf30(); virtual void vf31(); virtual void vf32(); virtual void vf33();
    virtual void vf34(); virtual void vf35(); virtual void vf36(); virtual void vf37();
    virtual void set_text_list(char** text, short id);
    virtual void set_text_long(long text_id);
    virtual void set_text(char* text);
};

void TRIBE_Screen_Status_Message::set_text(char* param) {
    ((Status_Text_Panel*)this->member_478)->set_text(param);
}
