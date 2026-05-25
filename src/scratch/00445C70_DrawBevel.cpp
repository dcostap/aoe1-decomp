// 00445C70 TDrawArea::DrawBevel
// 2026-05-21 Boss pass:
// Replaced inherited stub with behavior-equivalent bevel drawing source.
// Tried natural decompiler-shaped source, packet-expression source, parameter-mutating width/height source,
// explicit orig-order temps, self local, forced parameter stores, register x1/x2 signatures, separate left/right
// locals, xor-swap/no-temp swap, address/offset recomputation variants, and flags /Ob0, /O2-no-/Oy, /G5, /Oa, /O1.
// Natural/decompiler source compiles to 160B (too short) and starts by loading a parameter before saving registers.
// Exact-size variants compile to 167B but fall into a wrong push-ecx/local-frame basin or otherwise broad register
// topology drift. Best retained exact-size behavior-equivalent source is the parameter-mutating width/height form:
// 167B, 86.2275% positional / 116.7665% edit, first mismatch 0.
// GIVEUP: no accepted_drift proposal; remaining mismatch is broad prologue/register/call-argument topology, not localized.
// 2026-05-24 Boss pass: 20 more probes. Revalidated baseline exact-size wrong push-ecx/local-frame basin (86.2275% positional, first mismatch 0). Tried decompiler/natural source, >= nested form, original-endpoint call source, no-return nested source, self-local forms, mixed width/height locals, int/long color helper signatures, int/long color formals, register/volatile parameters, xor-swap, parameter-mutating self variants, height-local/width-local variants, and flags /Ob0 /Og- /G3 /G4 /Ox /Os. Natural/local variants remain 160B too short; exact-size variants all stay broad wrong prologue/register/call-argument topology. Not accepted_drift: mismatch is structural from byte 0.

class TDrawArea {
public:
    void DrawHorzLine(long x, long y, long w, unsigned char color);
    void DrawVertLine(long x, long y, long h, unsigned char color);
    void DrawBevel(long x1, long y1, long x2, long y2, unsigned char c1, unsigned char c2);
};

void TDrawArea::DrawBevel(long x1, long y1, long x2, long y2, unsigned char c1, unsigned char c2)
{
    if (x1 > x2) {
        long t = x1;
        x1 = x2;
        x2 = t;
    }
    if (y1 > y2) {
        long t = y1;
        y1 = y2;
        y2 = t;
    }

    x2 = x2 - x1 + 1;   // width
    if (x2 < 1)
        return;

    y2 = y2 - y1 + 1;   // height
    if (y2 < 1)
        return;

    DrawHorzLine(x1 + 1, y1, x2 - 1, c1);
    y2--;
    DrawVertLine(x1 + x2 - 1, y1 + 1, y2, c1);
    DrawHorzLine(x1, y1 + y2, x2, c2);
    DrawVertLine(x1, y1, y2, c2);
}
