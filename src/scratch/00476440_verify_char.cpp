// Attempt log for 00476440 TEditPanel::verify_char
// Attempt log:
// 1: prior natural/goto pass; stale build was 632B with two extra indirect
//    call sites in the switch body.
// 2: renamed the input flag to DAT_0086b244; emitted code was unchanged.
// 3: rebuilt the PDB-ordered percent/number/file/path switch around the common
//    result tail; size fell to 576B but bool normalization remained.
// 4-5: combined and then positively spelled file/path invalid-character tests;
//    call topology improved but the compiler still duplicated one beep tail.
// 6: widened the result local to int; no emitted change.
// 7: carried raw mbscmp status and an inverted numeric invalid flag; 560B.
// 8: restored explicit case zero/default-valid dispatch; exact 525B section,
//    12 calls, and 315 differing bytes.
// 9: restored the two redundant sel_len guards and text_len-first thresholds;
//    pre-switch bytes now align through 004764FA and the best diff is 285B.
// Left in scratch: the remaining drift is switch-tail placement (raw mbscmp
// flags/common result, one file-colon beep duplication, and branch spans).
// The typed field ownership and raw status semantics are retained; no opaque
// register/absolute-address scaffolding is used.
// New claim: baseline revalidated the 576-byte/285-byte-diff clean source.
// Probes 1-4 tested signed global ABI and positive file/path equality chains,
// then direct numeric/percent valid-invalid branches; the latter improved
// block/call alignment but added a beep site and 12 bytes, so clean source was
// restored.  Remaining lead is natural switch-tail placement, not layout.
// Fresh natural-return switch reconstruction widened the body to 624 bytes
// and dropped a required beep call; it was rejected.  Separating the numeric
// beep and direct percent comparison improved block alignment but added one
// beep call and 12 bytes.  A nested file-dot branch added two calls and was
// also rejected.  The clean typed switch remains authoritative.

extern "C" int (__stdcall* const MessageBeep)(unsigned int);
extern "C" int (__stdcall* const IsDBCSLeadByte)(unsigned int);
extern "C" int __cdecl _mbscmp(const unsigned char*, const unsigned char*);
extern "C" unsigned char* __cdecl _mbschr(const unsigned char*, unsigned int);

// Shared input-state flag; the generated global name is the proven relocation
// identity used by the other exact pnl_edit.cpp functions.
extern unsigned int DAT_0086b244;
static const unsigned char s_10[] = "10";

class TEditPanel {
public:
    char gap_000[0xF8];
    short fixed_len;
    char gap_0FA[2];
    char* text;
    int text_len;
    char gap_104[0x24];
    int format;
    char gap_12C[0x20];
    int sel_len;

    void update_text();
    int verify_char(int ch);
};

int TEditPanel::verify_char(int ch)
{
    if (DAT_0086b244 != 0) {
        DAT_0086b244 = 0;
        return 0;
    }
    if (ch == 9) return 0;
    if (ch == 13 && this->format != 7) return 0;
    if (ch == 8) return 1;

    this->update_text();
    if (this->sel_len == 0) {
        if (this->text_len >= this->fixed_len - 1) {
            MessageBeep(0xffffffff);
            return 0;
        }
    }
    if (this->sel_len == 0) {
        if (this->text_len >= this->fixed_len - 2 && IsDBCSLeadByte(ch) != 0) {
            DAT_0086b244 = 1;
            MessageBeep(0xffffffff);
            return 0;
        }
    }

    int validation_result;
    switch (this->format) {
    case 0:
        goto valid;
    case 8:
        if (this->text_len < 2) {
            if (ch >= '0' && ch <= '9') goto valid;
        }
        if (this->text_len != 2 || ch != '0') goto invalid;
        // Keep the CRT comparison's raw zero/nonzero result for the common
        // post-switch test; the executable carries its TEST flags into that
        // tail rather than materializing a bool.
        validation_result = _mbscmp(s_10, (const unsigned char*)this->text);
        break;
    case 1:
    case 2:
    case 3:
        this->update_text();
        if (ch >= '0' && ch <= '9') goto valid;
        if (ch == '-' && this->text[0] == 0 && this->format != 3) goto valid;
        if (ch != '.' || _mbschr((const unsigned char*)this->text, '.') == 0) goto invalid;
        validation_result = this->format != 1;
        break;
    case 4:
    case 5:
        this->update_text();
        if (ch == '.' && this->format == 4 &&
            _mbschr((const unsigned char*)this->text, '.') == 0) {
            goto valid;
        }
        if (ch != '.' && ch != '\\' && ch != ':') goto valid_chars;
        goto invalid;
    case 6:
        this->update_text();
        if (ch == ':' && this->text_len != 1) goto invalid;
        goto valid_chars;
    default:
        goto valid;
    }

    if (validation_result != 0) goto invalid;
    goto valid;

valid_chars:
    if (ch != '/' && ch != '"' && ch != '*' && ch != '?' &&
        ch != '>' && ch != '<' && ch != '|') goto valid;
    goto invalid;

invalid:
    MessageBeep(0xffffffff);
    return 0;

valid:
    return 1;
}
