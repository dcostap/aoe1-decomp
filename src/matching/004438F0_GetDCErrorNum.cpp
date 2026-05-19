// VA: 004438F0 TDrawSystem::GetDCErrorNum (147 B)
// PDB source: Drawarea.cpp
// Maps DirectDraw HRESULT to error code constant
// Attempt log:
// try 1: removed stale /Od custom flag; /O2 emits FPO/no-frame shape but source tree was inverted and needed configured trailing padding.
// try 2: signed negative constants in if-tree changed unsigned jbe to signed jle but still inverted broad layout.
// try 3: switch over HRESULT cases to test VC5 sparse-switch binary-search lowering.

class TDrawSystem {
public:
    int GetDCErrorNum(long hr);
};

int TDrawSystem::GetDCErrorNum(long hr)
{
    switch (hr) {
    case 0:
        return 0;
    case -2147467259L:
        return 0x834;
    case -2147467263L:
        return 0x83A;
    case -2147024809L:
        return 0x837;
    case -2005532542L:
        return 0x836;
    case -2005532222L:
        return 0x839;
    case -2005532132L:
        return 0x83B;
    case -2005532080L:
        return 0x838;
    case -2005532052L:
        return 0x835;
    default:
        return 0x897;
    }
}

// PSEUDO-FUNCTION: configured range includes trailing NOP bytes after ret.
__declspec(naked) void padding_pseudo_function(void) {
    __asm _emit 0x90
    __asm _emit 0x90
    __asm _emit 0x90
}
