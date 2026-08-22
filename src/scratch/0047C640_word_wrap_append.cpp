// 0047C640 TTextPanel::word_wrap_append (Pnl_txt.cpp:320-560)
// Attempt log:
// baseline: existing broad scratch reconstruction used strlen/isspace and fake
// helpers; calls, frame, and body topology were not aligned.
// probe 2: restored the period MBCS/GDI helper surface and two-stage wrap /
// backtrack behavior; frame became 0x170 and ordered calls became 28/29.
// probe 3: added the binary-proven Japanese single-byte-pair __ismbcspace call;
// ordered call set became exact (29/29), with only a small size drift.
// probe 4: removed an unproven render-area null guard; direct GetDc topology
// reduced the structural drift.
// probes 5-6: tested the TEXTMETRICA/old-font ownership and the four-byte
// leading temp buffer window.  The surviving source uses a separate old-font,
// tm.tmCharSet, and a 0x100-byte clear with temp_text+4 destination.
// probes 7-9: declaration-order and period-polymorphic TPanel context tests;
// the latter was a codegen duplicate.  Probe 10 scoped per-line locals, also a
// duplicate.  Before the current claim, the best reconstruction had frame
// 0x170, exact 29-call sequence/CFG counts, size 1055 vs 1064, and 71.7%
// shape similarity.
// claim shardC4-47C640: split null and empty guards was a codegen duplicate.
// Reordered the Japanese whitespace test before the character-pair tests;
// this moved the build to size 1064, 76.8% shape, and 33.4% exact blocks.
// A named panel alias and two local declaration-order variants were duplicates.
// claim orch-47C640-b: typed render_area/direct calls were a codegen duplicate;
// an input cursor alias was also a duplicate.  A conditional max-width form
// removed one structural spill and reached diff 801, but changed block shape;
// restored the ordinary if/else form.  Splitting the wrap-loop width guard
// was a codegen duplicate.
// Binary pointer topology: the first extent call measures __mbsinc(text) but
// keeps next_char at text; the original then advances it inside the loop.
// Kept that natural source form.  A named first-length temp improved resync
// but broke size and prologue parity, so it was rolled back.
// claim sa-a864d1c5: restored the pinned clean source before pause.  The
// baseline remains 1064 bytes, 0x170 frame, 29 ordered calls, and 986 strict
// differing bytes.  Local declaration order, __mbslen int return, int count
// widths, bool flags, full TTextPanel layout, a derived draw slot, combined
// guards, register qualifiers, max-width polarity, period MBSTRING.H calls,
// and int text_len with narrow comparisons did not produce an exact result.
// The int text_len/narrow-compare probe was the best diagnostic lead at 548
// differing bytes, but its shape similarity fell to 76.49%; it was restored.
// Ambient declaration context (64 variants) and the vc5-small flag family
// (12 variants) each formed one unchanged nonexact group.  No tested source
// or context change recovered the original ESI text / EDI this prologue.
// BINARY NOTE: the original keeps the text length in EBP and the moving input
// cursor in ESI, while the clean source keeps them in a stack home and EBX.
// LIKELY INTENT: the remaining drift is a VC5 register-color or source-context
// basin issue, not an unresolved call, frame, or helper ownership issue.
// left in scratch: the remaining broad drift begins at VC5 prologue/register
// coloring (parameter in EBX vs original ESI, this in ESI vs original EDI),
// plus local slot/block placement; calls, frame, and size now match.
// claim sa-42122c60: test source declaration order for the two persistent
// narrow counters that occupy EBP and EBX in the original.
// claim sa-42122c60 follow-up: 19 focused probes tested counter initialization,
// loop order, flag and buffer types, declaration order, self aliases, and
// register qualifiers.  The loop-entry chars-zero form reduced the byte diff
// to 927 but lost size and block shape; all probes were restored.  The clean
// source remains 1064 bytes with a 0x170 frame and 29 ordered calls.

#include <windows.h>
#include <string.h>

extern "C" short __cdecl __mbslen(const char* str);
extern "C" unsigned char* __cdecl __mbsinc(const unsigned char* str);
extern "C" unsigned char* __cdecl __mbsdec(const unsigned char* start,
                                              const unsigned char* cur);
extern "C" unsigned char* __cdecl __mbsncpy(unsigned char* dst,
                                               const unsigned char* src,
                                               int count);
extern "C" unsigned char* __cdecl __mbsninc(const unsigned char* str,
                                               int count);
extern "C" unsigned char* __cdecl __mbscat(unsigned char* dst,
                                               const unsigned char* src);
extern "C" int __cdecl __ismbcspace(int ch);

class TDrawArea;

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(void*, TPanel*, long, long, long, long, unsigned char);
    virtual void set_rect(void*);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning(int, long, long, long, long, long, long,
                                 long, TPanel*, TPanel*, TPanel*, TPanel*);
    virtual void set_fixed_position(long, long, long, long);

    char gap_04[0x08];
    long pnl_x;                        // +0x0C
    long pnl_y;                        // +0x10
    long pnl_wid;                      // +0x14
    long pnl_hgt;                      // +0x18
    char gap_1C[0x04];
    TDrawArea* render_area;             // +0x20
    char gap_24[0xD0];                 // through the TPanel boundary +0xF4
};

class TDrawArea {
public:
    void* GetDc(char* name);
    void ReleaseDc(char* name);
};

class TTextPanel : public TPanel {
public:
    char gap_F4[0x10];                 // list and line state
    void* font;                        // +0x104
    char gap_108[0x2C];                // through +0x134
    int auto_scbar;                    // +0x134
    char gap_138[0x2C];
    long full_width;                   // +0x164
    long scbar_width;                  // +0x168

    enum CharType {
        SingleByteChar = 0,
        SingleByteKanaChar = 1,
        DoubleByteChar = 2
    };

    CharType char_type(unsigned char* text);
    int append_line(char* text, long value);
    int word_wrap_append(char* text);
};

int TTextPanel::word_wrap_append(char* text)
{
    short text_len;
    short chars;
    short last_chars;
    int found_break;
    int found_return;
    void* dc;
    int found_space;
    unsigned char* last_char;
    long max_wid;
    unsigned char* next_char;
    SIZE text_size;
    int found_linefeed;
    int found_char_break;
    int japanese;
    void* old_font;
    TEXTMETRICA tm;
    char temp_text[256];

    if (text == 0) {
        return 1;
    }
    if (*text == '\0') {
        return 1;
    }

    if (this->auto_scbar != 0) {
        max_wid = this->full_width - this->scbar_width;
    } else {
        max_wid = this->pnl_wid;
    }
    max_wid -= 10;

    dc = this->render_area->GetDc((char*)0x58547c);
    if (dc == 0) {
        return 0;
    }

    old_font = SelectObject((HDC)dc, (HGDIOBJ)this->font);
    GetTextMetricsA((HDC)dc, &tm);
    japanese = (tm.tmCharSet == 0x80);

    for (;;) {
    next_line:
        text_len = __mbslen(text);
        found_break = 0;
        found_linefeed = 0;
        found_char_break = 0;
        found_space = 0;
        found_return = 0;
        next_char = (unsigned char*)text;

        if (*text == '\n') {
            found_linefeed = 1;
            chars = 0;
            goto emit_line;
        }

        chars = 1;
        next_char = (unsigned char*)text;
        GetTextExtentPoint32A((HDC)dc, text,
                              (int)(short)(__mbsinc(
                                  (const unsigned char*)text) -
                                           (unsigned char*)text),
                              &text_size);
        last_char = 0;

        while (chars <= text_len) {
            if (text_size.cx >= max_wid) {
                break;
            }
            if (*next_char == '\n') {
            --chars;
            found_linefeed = 1;
            if (last_char != 0 && *last_char == '\r') {
                found_space = 1;
                --chars;
            }
                break;
            }
            if (*next_char == '\r') {
                found_return = 1;
            }

            last_char = next_char;
            next_char = __mbsinc(next_char);
            ++chars;
            GetTextExtentPoint32A(
                (HDC)dc, text,
                (int)(short)(__mbsinc(next_char) - (unsigned char*)text),
                &text_size);
        }

    emit_line:
        if (!found_linefeed) {
            GetTextExtentPoint32A((HDC)dc, text, (int)(short)strlen(text),
                              &text_size);
            if (text_size.cx <= max_wid) {
                goto append_all;
            }

            chars = 1;
            next_char = (unsigned char*)text;
            last_chars = chars;
            while (chars < text_len) {
                next_char = __mbsinc(next_char);
                GetTextExtentPoint32A(
                    (HDC)dc, text,
                    (int)(short)(next_char - (unsigned char*)text),
                    &text_size);
                if (text_size.cx > max_wid) {
                    break;
                }
                last_chars = chars - 1;
                next_char = __mbsinc(next_char);
                ++chars;
            }

            while (chars > 1) {
                unsigned char* old_next = next_char;
                next_char = __mbsdec((const unsigned char*)text, next_char);
                --chars;

                if (japanese) {
                    CharType first = this->char_type(next_char);
                    CharType second = this->char_type(old_next);
                    if (first == SingleByteChar && second == SingleByteChar &&
                        __ismbcspace(*next_char) != 0) {
                        found_char_break = 1;
                        break;
                    }
                    if ((first == DoubleByteChar && second == DoubleByteChar) ||
                        (first == SingleByteKanaChar && second == SingleByteKanaChar) ||
                        (first == SingleByteChar && second == DoubleByteChar) ||
                        (first == DoubleByteChar && second == SingleByteChar) ||
                        (first == SingleByteChar && second == SingleByteKanaChar) ||
                        (first == SingleByteKanaChar && second == SingleByteChar)) {
                        found_break = 1;
                        break;
                    }
                } else if (__ismbcspace(*next_char) != 0) {
                    found_char_break = 1;
                    break;
                }
            }
        }

        if (!found_break && !found_char_break) {
            chars = last_chars;
            found_break = 1;
        }
        if (!found_linefeed && !found_char_break && !found_break) {
            goto append_all;
        }

        memset(temp_text, 0, 0x100);
        __mbsncpy((unsigned char*)temp_text + 4,
                  (const unsigned char*)text, chars);
        if (found_space) {
            __mbscat((unsigned char*)temp_text + 4,
                     (const unsigned char*)0x580460);
        }
        if (found_linefeed) {
            __mbscat((unsigned char*)temp_text + 4,
                     (const unsigned char*)0x580460);
        }
        if (found_return) {
            unsigned char* p = (unsigned char*)temp_text + 4;
            while (*p != 0) {
                if (*p == '\r') {
                    *p = ' ';
                }
                p = __mbsinc(p);
            }
        }
        this->append_line(temp_text + 4, 0);
        text = (char*)__mbsninc((const unsigned char*)text, chars);
        if (found_space) {
            text = (char*)__mbsinc((const unsigned char*)text);
        }
        if (found_linefeed) {
            text = (char*)__mbsinc((const unsigned char*)text);
        }
        goto next_line;

    append_all:
        this->append_line(text, 0);
        SelectObject((HDC)dc, (HGDIOBJ)old_font);
        this->render_area->ReleaseDc((char*)0x58547c);
        return 1;
    }
}
