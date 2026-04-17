// STATUS: almost_matched
// CLASS: add-base-vs-direct-displacement
// RISK: low
// WHY: Original loads the four stack dwords, then does `add ecx,12FCh` once and stores at [ecx],[ecx+4],[ecx+8],[ecx+0Ch]. VC5 deterministically emits direct stores to [ecx+12FCh], [ecx+1300h], [ecx+1304h], [ecx+1308h] instead. Same memory effects, same stack cleanup, stable codegen drift.
// NEXT: Revisit only if TU-level context or a different VC5-family backend changes address-materialization strategy.
class TCommunications_Handler_sssg {
public:
    void SetSessionGUID(unsigned long a, unsigned long b, unsigned long c, unsigned long d);
};

void TCommunications_Handler_sssg::SetSessionGUID(unsigned long a, unsigned long b, unsigned long c, unsigned long d) {
    unsigned long* guid_words = (unsigned long*)((char*)this + 0x12FC);
    guid_words[0] = a;
    guid_words[1] = b;
    guid_words[2] = c;
    guid_words[3] = d;
}
