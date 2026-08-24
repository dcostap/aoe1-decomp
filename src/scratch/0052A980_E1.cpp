#ifndef AOE1_TRIG_TU_CONTEXT
class TRIGONOMETRY {
public:
    TRIGONOMETRY();
};
#endif

// BINARY NOTE: The global definition lets VC5 emit the shipped _$E1
// constructor tail. Do not replace it with a hand-written ABI shim.
TRIGONOMETRY trig;
