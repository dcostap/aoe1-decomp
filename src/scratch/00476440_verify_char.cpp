// Attempt log for 00476440 TEditPanel::verify_char
// try 1: natural reconstruction from packet with minimal TEditPanel layout and import-pointer calls; first 72B exact, then switch body too large/normalized subtract-1.
// try 2: add explicit case 0 to switch to discourage subtract-1 normalization; switch dispatch shape restored but body still too large.
// try 3: reverse _mbscmp argument order and make case4 dot flow through invalid-char tail like original; edit diff improved but case8 discarded strcmp result.
// try 4: use reversed _mbscmp but keep ==0 success; worse.
// try 5: restore _mbscmp(text, s_10)==0, focus elsewhere.
// try 6: split allow_overflow checks into two independent ifs to preserve redundant test/reloads; first pre-switch region now exact, diff down to 36.95%.
// try 7: use shared invalid/valid goto tails for switch body to reduce duplicated beep/return blocks; positional improved to 34.10% but edit diff worse, compiler still placed an early invalid block after case8.
// try 8: /GX flag probe; unchanged, rolled back.
// try 9: /O1 flag probe; too-small 481B object, rolled back.
// try 10: /Oy- flag probe earlier worsened from offset 0, rolled back.
// BLOCKER: pre-switch region through 004764FA is exact after splitting allow_overflow checks; remaining mismatch is switch-body block layout/tail sharing around case8/cases1-3 and case4/6 invalid tails. Exact size but broad switch layout diff remains, not accepted_drift-safe.

typedef unsigned char uchar;
extern "C" int (__stdcall* const MessageBeep)(unsigned int);
extern "C" int (__stdcall* const IsDBCSLeadByte)(unsigned int);
extern "C" int __cdecl _mbscmp(const unsigned char*, const unsigned char*);
extern "C" unsigned char* __cdecl _mbschr(const unsigned char*, unsigned int);

extern int g_dbc_beep_flag;
static const unsigned char s_10[] = "10";

class TEditPanel {
public:
    char gap_000[0xF8];
    short max_len;
    char gap_0FA[2];
    unsigned char* text;
    int cursor;
    char gap_104[0x24];
    int verify_type;
    char gap_12C[0x20];
    int allow_overflow;

    void update_text();
    int verify_char(int ch);
};

int TEditPanel::verify_char(int ch)
{
    if (g_dbc_beep_flag != 0) {
        g_dbc_beep_flag = 0;
        return 0;
    }
    if (ch == 9) return 0;
    if (ch == 13 && this->verify_type != 7) return 0;
    if (ch == 8) return 1;

    this->update_text();
    if (this->allow_overflow == 0) {
        if (this->cursor >= (int)this->max_len - 1) {
            MessageBeep(0xffffffff);
            return 0;
        }
    }
    if (this->allow_overflow == 0) {
        if (this->cursor >= (int)this->max_len - 2) {
            if (IsDBCSLeadByte(ch)) {
                g_dbc_beep_flag = 1;
                MessageBeep(0xffffffff);
                return 0;
            }
        }
    }

    switch (this->verify_type) {
    case 0:
        goto valid;
    case 8:
        if (this->cursor < 2) {
            if (ch >= '0' && ch <= '9') goto valid;
        }
        if (this->cursor == 2 && ch == '0') {
            if (_mbscmp(this->text, s_10) == 0) goto valid;
        }
        goto invalid;
    case 1:
    case 2:
    case 3:
        this->update_text();
        if (ch >= '0' && ch <= '9') goto valid;
        if (ch == '-' && this->text[0] == 0 && this->verify_type == 3) goto valid;
        if (ch == '.') {
            if (_mbschr(this->text, ch) != 0) goto invalid;
            if (this->verify_type == 1) goto valid;
        }
        goto invalid;
    case 4:
    case 5:
        this->update_text();
        if (ch == '.') {
            if (this->verify_type == 4) {
                if (_mbschr(this->text, ch) == 0) goto valid;
            }
        }
        if (ch == '.' || ch == '\\' || ch == ':' || ch == '/' || ch == '"' || ch == '*' || ch == '?' || ch == '>' || ch == '<' || ch == '|') goto invalid;
        goto valid;
    case 6:
        this->update_text();
        if (ch == ':' && this->cursor != 1) goto invalid;
        if (ch == '/' || ch == '"' || ch == '*' || ch == '?' || ch == '>' || ch == '<' || ch == '|') goto invalid;
        goto valid;
    default:
        goto valid;
    }
invalid:
    MessageBeep(0xffffffff);
    return 0;
valid:
    return 1;

}
