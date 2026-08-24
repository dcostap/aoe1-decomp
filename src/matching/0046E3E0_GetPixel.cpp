// VA: 0046E3E0 TPicture::GetPixel
// Picture.cpp lines 256-286
//
// Attempt log:
// - Existing scratch was a decompiler-shaped bpp/pixel-format reconstruction;
//   it had no AlignedWidth calls and did not model the proven orientation/row
//   addressing behavior.
// - Reconstructed the canonical TPicture layout and four orientation/row cases;
//   all four direct AlignedWidth call sites and the signed bounds now align.
// - A ternary `(orientation != 1) ? 1 : -1` reproduces VC5's original
//   dec/neg/sbb/and-eax/dec transform; x <= 0 reproduces test/jle.
// - Tried outer-arm order, an explicit dispatch label, a shared stride local,
//   and explicit if/else. VC5 retains a different outer branch/block basin and
//   merges one pair of call tails; best emitted probe was 123 differing bytes.
// - Final source keeps the period-plausible four-return form and the binary-
//   supported `Height - y - 1` row expression; residual drift is CFG/block
//   placement and call-tail merging, not an unresolved field or behavior fact.
//
// Fresh pass (orch-luna-46e3e0-w2, prior 10 probes not repeated):
// - Reversing the mode arms to nonzero-first with `Height - y - 1` improved the
//   structural diff from 129 to 107 bytes and reproduced the original `test/je`
//   dispatch topology; this is the retained source-level CFG hypothesis.
// - Pointer-base and row-offset spellings improved edit/resync diagnostics and
//   exposed the original Bits/row/Width scheduling, but remained nonexact.
// - A raw 32-bit address variant reached 94 differing bytes, then was rolled
//   back as compiler-steering scaffolding rather than period-plausible source.
// - Final fresh-pass state retains the natural nonzero-first four-arm source;
//   residual drift is the +4-byte arithmetic/register basin in the pixel arms.
//
// Fresh bounded pass (sa-7925fc20-GetPixel):
// - inherited the documented 107-byte clean candidate and did not repeat the
//   prior worker's ten hypotheses.
// - row-offset-first and sequential address variants improved structure to
//   93 bytes but retained four extra bytes and a noncanonical pointer schedule.
// - the final ordinary 32-bit pixel-address expression, with row computation
//   first and the Bits member added before x/Width terms, produced MATCH:
//   204/204 bytes, 4/4 calls, and exact CFG/boundary parity.
// - the cast is limited to the 32-bit pixel-address expression; no absolute
//   addresses, asm, volatility, or fabricated calls are used.
//
#ifndef PICTURE_CONTEXT_H
class TPicture {
public:
    void* Dib;
    void* BitmapInfo;
    unsigned char* Bits;
    void* TransInfo;
    int OwnMemory;
    long Width;
    long Height;
    short Orien;

    long AlignedWidth();
    unsigned char GetPixel(long x, long y, int param_3, int param_4);
};
#endif

unsigned char TPicture::GetPixel(long x, long y, int param_3, int param_4) {
    char orientation = (char)this->Orien;
    if (param_4 != 0) {
        orientation = (orientation != 1) ? 1 : -1;
    }

    if (x <= 0 || x >= this->Width || y < 0 || y >= this->Height) {
        return 0;
    }

    if (param_3 != 0) {
        if (orientation == 1) {
            return *(unsigned char*)(this->AlignedWidth() * y +
                                     (long)this->Bits - x + this->Width - 1);
        }
        return *(unsigned char*)(this->AlignedWidth() *
                                 (this->Height - y - 1) +
                                 (long)this->Bits - x + this->Width - 1);
    }

    if (orientation == 1) {
        return *(unsigned char*)(this->AlignedWidth() * y +
                                 (long)this->Bits + x);
    }
    return *(unsigned char*)(this->AlignedWidth() *
                             (this->Height - y - 1) +
                             (long)this->Bits + x);
}
