// 0047C640 TTextPanel::word_wrap_append
// Pnl_txt.cpp
// Attempt log:
// try 1: broad reconstruction from packet: acquire DC/font metrics, scan words/newlines to fit max width, append wrapped chunks, release DC.
// try 2: modeled null/empty input returns and max width as either panel width or wrapRight-wrapLeft minus 10.
// try 3: modeled DrawArea::GetDc("pnl_txt::word_wrap_append"), SelectObject(font), and release/restore at the tail.
// try 4: modeled initial strlen and GetTextExtentPoint32A scan over multibyte chars via _mbsinc until text width exceeds max.
// try 5: modeled newline and carriage-return detection, including LF and CRLF flags that later append a blank/space suffix.
// try 6: modeled full-string-fit path that directly appends remaining text.
// try 7: modeled overwide-line fallback scan for a break point, including wordWrapMode classification calls to this+0047C520 and isspace fallback.
// try 8: modeled output buffer as 256-byte local zeroed with loop/rep-like C, then _mbsnbcpy chunk copy and optional strcat(" ") suffixes.
// try 9: modeled CR replacement pass using _mbsinc and append_line(out,0), then advance source pointer by copied chars plus skipped LF/space markers.
// try 10: default compile produced .text 1040B vs original 1064B, no full diff.
// try 11: /GX probe produced identical 1040B, removed flag file.
// left in scratch: broad behavior and size are close, but exact _mbsnbcpy/_mbsinc source shape, TEXTMETRIC high-bit path, break-classification pointer topology, and local variable/register layout still differ; no accepted_drift because no localized full diff.

extern "C" int __stdcall GetTextExtentPoint32A(void*, const char*, int, void*);
extern "C" void* __stdcall SelectObject(void*, void*);
extern "C" int __cdecl strlen(const char*);
extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);
extern "C" char* __cdecl strcat(char*, const char*);
extern "C" char* __cdecl strchr(const char*, int);
extern "C" int __cdecl isspace(int);
extern "C" char* __cdecl _mbsinc(char*);
extern "C" char* __cdecl _mbsnbcpy(char*, const char*, unsigned int);
extern "C" int __cdecl _ismbblead(unsigned int);

struct SIZE2 { int cx; int cy; };
class DrawArea { public: void* GetDc(const char*); void ReleaseDc(const char*); };
class TTextPanel {
public:
    void* vtbl; char gap04[0x10]; int width; char gap18[8]; DrawArea* area;
    char gap24[0x104-0x24]; void* font;
    char gap108[0x134-0x108]; int wordWrapMode;
    char gap138[0x164-0x138]; int wrapRight; int wrapLeft;
    int word_wrap_append(char* text);
    int classify(char* p);
    void append_line(char* s, int flag);
};

int TTextPanel::word_wrap_append(char* text) {
    char out[256];
    SIZE2 sz;
    char* p;
    char* q;
    char* last;
    void* dc;
    void* oldfont;
    int maxwid;
    int len;
    int chars;
    int foundBreak, foundLinefeed, foundReturn, foundSpace;
    int needSpace;

    if (!text) return 1;
    if (!*text) return 1;
    maxwid = wordWrapMode ? (wrapRight - wrapLeft) : width;
    maxwid -= 10;
    dc = area->GetDc((const char*)0x58547c);
    if (!dc) return 0;
    oldfont = SelectObject(dc, font);
    // original queries TEXTMETRIC here and checks tmPitchAndFamily high bit.
    needSpace = 0;

    p = text;
again:
    foundLinefeed = foundSpace = foundBreak = foundReturn = 0;
    chars = 0;
    last = p;
    if (*p == '\n') { foundLinefeed = 1; goto emit; }
    len = strlen(p);
    GetTextExtentPoint32A(dc, p, (short)len, &sz);
    if (len >= 1) {
        q = p;
        while (sz.cx < maxwid && chars <= len) {
            if (*q == '\n') { --chars; foundLinefeed = 1; if (last && *last == '\r') { foundSpace = 1; --chars; } break; }
            if (*q == '\r') foundReturn = 1;
            last = q;
            q = _mbsinc(q);
            ++chars;
            GetTextExtentPoint32A(dc, p, (short)(q - p), &sz);
            if (chars > len) break;
        }
    }
    if (!foundLinefeed) {
        GetTextExtentPoint32A(dc, p, (short)strlen(p), &sz);
        if (sz.cx <= maxwid) goto emit_all;
        chars = 1; q = p;
        while (chars < len) {
            GetTextExtentPoint32A(dc, p, (short)(q - p), &sz);
            if (sz.cx > maxwid) break;
            last = (char*)(chars-1);
            q = _mbsinc(q);
            ++chars;
        }
        if (chars > 1) {
            q = (char*)_mbsnbcpy((char*)q, p, 0) + (int)q;
            --chars;
            while (chars > 1) {
                int c1, c2;
                if (wordWrapMode) {
                    c1 = classify(q); c2 = classify((char*)last);
                    if ((!c1 && !c2 && isspace((unsigned char)*q)) || (c1==2 && c2==2) || (c1==1 && c2==1) || (!c1 && c2==2) || (c1==2 && !c2) || (!c1 && c2==1) || (c1==1 && !c2)) { foundBreak = 1; break; }
                } else if (isspace((unsigned char)*q)) { foundBreak = 1; break; }
                --chars;
                q = p + chars;
            }
            if (!foundBreak && !foundReturn) { chars = (int)last; foundBreak = 1; }
        }
    }
emit:
    if (foundLinefeed || foundBreak || foundReturn) {
        int n = chars;
        for (int i=0;i<256;i++) out[i]=0;
        _mbsnbcpy(out, p, (unsigned int)n);
        if (foundSpace) strcat(out, (const char*)0x580460);
        if (foundLinefeed) strcat(out, (const char*)0x580460);
        if (foundReturn) {
            char* r = out;
            while (*r) { if (*r == '\r') *r = ' '; r = _mbsinc(r); }
        }
        append_line(out, 0);
        p = p + n;
        if (foundSpace) p = _mbsinc(p);
        if (foundLinefeed) p = _mbsinc(p);
        goto again;
    }
emit_all:
    append_line(p, 0);
    SelectObject(dc, oldfont);
    area->ReleaseDc((const char*)0x58547c);
    return 1;
}
