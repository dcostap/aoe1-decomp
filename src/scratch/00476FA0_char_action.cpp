// VA: 00476FA0 TInputPanel::char_action
// Attempt log:
// initial natural source from packet with MBCS helpers/IAT beep: compiles but emitted .text is 576 bytes vs expected 600, so no byte comparison.
// tried /GX to see if hidden EH/extra context was needed; unchanged 576-byte .text, removed flag.
// modeled MessageBeep as extern const stdcall function pointer to get IAT call surface.
// used real MBCS helper names _mbslen/_mbscmp/_mbschr for helper calls.
// modeled TInputPanel as virtual and bad_sound/get_text/insert_character members with packet offsets 0x198/0x19c/0x1a0/0x1ac.
// tried natural switch by input type with duplicated invalid return blocks; compiler still produces a shorter control-flow family.
// tried explicit invalid1/invalid2/invalid3 labels to preserve the three original bad-input tails; still short.
// left in scratch: behavior mostly understood, but source is in a too-short basin and no positional diff is available because rebuilt .text is 24 bytes short.

typedef unsigned short ushort;
extern "C" int __cdecl _mbslen(const char*);
extern "C" int __cdecl _mbscmp(const char*, const char*);
extern "C" char* __cdecl _mbschr(const char*, unsigned int);
extern "C" void (__stdcall* const MessageBeep)(unsigned int);

class TDigital { public: int play(); };
class TInputPanel {
public:
    char gap[0x198];
    TDigital* bad_sound;
    int type;
    char* text;
    char gap2[8];
    ushort path_drive_flag;
    char* get_text();
    int insert_character(long ch);
    virtual long char_action(long ch, short count);
};

long TInputPanel::char_action(long ch, short count)
{
    int i;
    if (ch == 8 || ch == 9 || ch == 10 || ch == 13 || ch == 27 || ch < 0) {
        return 1;
    }
    if (count == 0) count = 1;
    i = 0;
    if (count <= 0) return 1;
    do {
        switch (this->type) {
        case 8:
            if (_mbslen(this->get_text()) < 2 && ch >= '0' && ch <= '9') break;
            if (_mbslen(this->get_text()) != 2 || ch != '0') goto invalid1;
            if (_mbscmp(this->get_text(), (char*)0x00585334) != 0) goto invalid1;
            break;
        case 1:
        case 2:
        case 3:
            if (ch >= '0' && ch <= '9') break;
            if (ch == '-' && this->text[0] == 0 && this->type != 3) break;
            if (ch != '.') goto invalid2;
            if (_mbschr(this->text, ch) == 0) goto invalid2;
            if (this->type == 1) break;
            goto invalid2;
        case 4:
        case 5:
            if (ch == '.') {
                if (this->type == 4 && _mbschr(this->text, ch) == 0) break;
                goto invalid2;
            }
            if (ch == '\\' || ch == ':' || ch == '/' || ch == '"' || ch == '*' || ch == '?' || ch == '>' || ch == '<' || ch == '|') goto invalid2;
            break;
        case 6:
            if (ch == ':' && this->path_drive_flag != 1) goto invalid3;
            if (ch == '/' || ch == '"' || ch == '*' || ch == '?' || ch == '>' || ch == '<' || ch == '|') goto invalid3;
            break;
        default:
            break;
        }
        if (this->insert_character(ch) == 0) return 1;
        ++i;
    } while ((short)i < count);
    return 1;

invalid1:
    if (this->bad_sound != 0) this->bad_sound->play();
    return 1;
invalid2:
    if (this->bad_sound != 0) this->bad_sound->play();
    return 1;
invalid3:
    if (this->bad_sound != 0) this->bad_sound->play();
    else MessageBeep(0xFFFFFFFF);
    return 1;
}
