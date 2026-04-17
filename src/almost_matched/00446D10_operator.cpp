// STATUS: almost_matched
// CLASS: codegen_register_allocation
// RISK: low
// WHY: VC5 register allocator consistently assigns index→edx,length→eax instead of index→eax,length→esi. All source-shape probes produce the same edx/eax mapping. The rebuilt is semantically equivalent but instruction-different. No source-level change can force VC5 to use the specific register pair (eax,esi) from the original beta build.
// NEXT: None under VC5 — codegen-level constraint.
class DString {
public:
    char* stringValue;
    int lengthValue;
    char* operator[](int index);
};

char* DString::operator[](int index) {
    if (index < 0 || index >= this->lengthValue) {
        return this->stringValue;
    }
    return this->stringValue + index;
}
