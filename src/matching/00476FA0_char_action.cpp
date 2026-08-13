// VA: 00476FA0 TInputPanel::char_action
// Attempt log:
// initial natural source from packet with MBCS helpers/IAT beep: compiles but emitted .text is 576 bytes vs expected 600, so no byte comparison.
// tried /GX to see if hidden EH/extra context was needed; unchanged 576-byte .text, removed flag.
// modeled MessageBeep as extern const stdcall function pointer to get IAT call surface.
// used real MBCS helper names _mbslen/_mbscmp/_mbschr for helper calls.
// modeled TInputPanel as virtual and bad_sound/get_text/insert_character members with packet offsets 0x198/0x19c/0x1a0/0x1ac.
// tried natural switch by input type with duplicated invalid return blocks; compiler still produces a shorter control-flow family.
// tried explicit invalid1/invalid2/invalid3 labels to preserve the three original bad-input tails; still short.
// corrected the initial signed guard to ch < 0x1B; this aligned the equality/guard prefix.
// explicit case 0 anchored the VC5 jump table at the original 0..8 range; case 7 remains an empty valid arm.
// restored TTextPanel ownership for get_text and the virtual-vptr-adjusted TInputPanel field offsets.
// restored the independent file-format dot rejection; this recovered the original +0137/+014F mbschr block.
// added MessageBeep fallbacks to all invalid tails; the natural compiler basin still merges percent/numeric play tails.
// final shared-beep goto experiment collapsed play call sites and was rolled back to the #9 codegen-best source.
// reversed percent _mbscmp operands so VC5 evaluates get_text first and pushes it before the literal, matching the original call order; diff improved 290 to 277.
// inlined typed error handling in each percent/numeric, file, and path arm; this restored the third play call, exact size, and diff 222.
// replaced the guarded do/while with a pretested while; this restored the jl backedge, success fall-through, exact block layout, and reduced diff 222 to 1.
// declared _mbslen as unsigned int; this restored the original unsigned jae at the percent length guard and produced an exact match.
// modeled the BX/BP loop counter as a short local; output stayed exact and the source now matches the observed width naturally.
// exact under the default VC5 flags; source remains a typed switch with named fields and direct period API calls.

typedef unsigned short ushort;
extern "C" unsigned int __cdecl _mbslen(const char*);
extern "C" int __cdecl _mbscmp(const char*, const char*);
extern "C" char* __cdecl _mbschr(const char*, unsigned int);
extern "C" void (__stdcall* const MessageBeep)(unsigned int);

class TDigital { public: int play(); };
class TTextPanel {
public:
    virtual void vf00();
    char gap[0x184];
    char* get_text();
};
class TInputPanel : public TTextPanel {
public:
    char gap[0x10];
    TDigital* bad_sound;
    int type;
    char* text;
    char gap2[8];
    ushort path_drive_flag;
    int insert_character(long ch);
    virtual long char_action(long ch, short count);
};

long TInputPanel::char_action(long ch, short count)
{
    short i;
    if (ch == 8 || ch == 9 || ch == 10 || ch == 13 || ch == 27 || ch < 0x1B) {
        return 1;
    }
    if (count == 0) count = 1;
    i = 0;
    if (count <= 0) return 1;
    while (i < count) {
        switch (this->type) {
        case 8:
            if (_mbslen(this->get_text()) < 2 && ch >= '0' && ch <= '9') break;
            if (_mbslen(this->get_text()) != 2 || ch != '0' ||
                _mbscmp((char*)"10", this->get_text()) != 0) {
                if (this->bad_sound != 0) this->bad_sound->play();
                else MessageBeep(0xFFFFFFFF);
                return 1;
            }
            break;
        case 1:
        case 2:
        case 3:
            if (ch >= '0' && ch <= '9') break;
            if (ch == '-' && this->text[0] == 0 && this->type != 3) break;
            if (ch == '.' && _mbschr(this->text, ch) != 0 && this->type == 1) break;
            if (this->bad_sound != 0) this->bad_sound->play();
            else MessageBeep(0xFFFFFFFF);
            return 1;
        case 4:
        case 5:
            if (ch == '.') {
                if (this->type == 4 && _mbschr(this->text, ch) == 0) break;
            }
            if (ch == '.' || ch == '\\' || ch == ':' || ch == '/' || ch == '"' || ch == '*' || ch == '?' || ch == '>' || ch == '<' || ch == '|') {
                if (this->bad_sound != 0) this->bad_sound->play();
                else MessageBeep(0xFFFFFFFF);
                return 1;
            }
            break;
        case 6:
            if ((ch == ':' && this->path_drive_flag != 1) || ch == '/' || ch == '"' || ch == '*' || ch == '?' || ch == '>' || ch == '<' || ch == '|') {
                if (this->bad_sound != 0) this->bad_sound->play();
                else MessageBeep(0xFFFFFFFF);
                return 1;
            }
            break;
        case 0:
            break;
        case 7:
            break;
        default:
            break;
        }
        if (this->insert_character(ch) == 0) return 1;
        ++i;
    }
    return 1;
}
