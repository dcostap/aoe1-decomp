// 0047C560 TTextPanel::set_text (Pnl_txt.cpp:268-314)
// virtual void __thiscall TTextPanel::set_text(char* text)
//
// Canonical model:
//   - frees the old list, then accepts one text string.
//   - empty input appends a blank line; null input does so only for a
//     fixed-length panel (fixed_len != 0).
//   - when word wrap is disabled (word_wrap == 0) and the panel is not
//     word-wrap aligned (horz_align != AlignWordwrap), newline-separated
//     chunks are appended one at a time via a 256-byte temp buffer;
//     otherwise the whole string is handed to word_wrap_append.
//   - field ownership per PDB: horz_align +0x114, word_wrap +0x118,
//     fixed_len +0x138 (short). AlignWordwrap == 6.
//
// Attempt log:
//   probe 1 (baseline): int len = (short)(nl - text); then strncpy(..., len)
//     emitted the temp_text lea before the movsx ebp,ax (19-byte diff).
//   probe 2: split into int len = nl - text; strncpy(temp_text, text,
//     (short)len); temp_text[(short)len] = 0; - VC5 now evaluates the
//     (short)len inside the call's right-to-left arg sequence, keeping
//     sub eax,esi; movsx ebp,ax; push ebp; lea eax; push esi; push eax.
//     EXACT MATCH (0.0000%).
//   Lesson: for this VC5 basin, the pointer-diff cast must live inside the
//     strncpy argument, and the null-termination index must reuse the same
//     (short)len expression so ebp is CSE'd as the index register.

extern "C" char* __cdecl _mbschr(const char* s, int c);
extern "C" char* __cdecl strncpy(char* dst, const char* src, unsigned int n);

#ifndef PNL_TXT_TU_CONTEXT
class TTextPanel {
public:
    char gap_00[0x114];
    int horz_align;            // +0x114 (Alignment)
    int word_wrap;             // +0x118
    char gap_11C[0x1C];
    short fixed_len;           // +0x138

    void free_text();
    int append_line(const char* text, int data);
    int word_wrap_append(char* text);
    void set_text(char* text);
};
#endif

void TTextPanel::set_text(char* text) {
    char temp_text[256];

    free_text();
    if (text == 0) {
        if (fixed_len != 0) {
            append_line("", 0);
            return;
        }
    } else {
        if (*text == '\0') {
            append_line("", 0);
            return;
        }
        if (word_wrap == 0 && horz_align != 6) {   // 6 == AlignWordwrap
            while (true) {
                char* nl = _mbschr(text, '\n');
                if (nl == 0) {
                    break;
                }
                int len = nl - text;
                strncpy(temp_text, text, (short)len);
                temp_text[(short)len] = '\0';
                append_line(temp_text, 0);
                text = nl + 1;
            }
            append_line(text, 0);
            return;
        }
        word_wrap_append(text);
    }
}
