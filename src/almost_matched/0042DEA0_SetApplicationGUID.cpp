// STATUS: almost_matched
// CLASS: add-base-vs-direct-displacement
// RISK: low
// WHY: Original loads the four stack dwords, then does `add ecx,12ECh` once and stores at [ecx],[ecx+4],[ecx+8],[ecx+0Ch]. VC5 deterministically emits direct stores to [ecx+12ECh], [ecx+12F0h], [ecx+12F4h], [ecx+12F8h] instead. Same memory effects, same stack cleanup, stable codegen drift.
// NEXT: Revisit only if TU-level context or a different VC5-family backend changes address-materialization strategy.
class TCommunications_Handler {
public:
    void SetApplicationGUID(unsigned long a, unsigned long b, unsigned long c, unsigned long d);
};

void TCommunications_Handler::SetApplicationGUID(unsigned long a, unsigned long b, unsigned long c, unsigned long d) {
    unsigned long* guid_words = (unsigned long*)((char*)this + 0x12EC);
    guid_words[0] = a;
    guid_words[1] = b;
    guid_words[2] = c;
    guid_words[3] = d;
}
