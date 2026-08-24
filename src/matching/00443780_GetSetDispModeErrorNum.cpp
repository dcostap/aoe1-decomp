// VA: 00443780 TDrawSystem::GetSetDispModeErrorNum (183 B)
// PDB source: Drawarea.cpp
// Maps DirectDraw HRESULT to error code constant.
// attempt: use natural sparse signed switch; sibling GetDCErrorNum matched this VC5 basin.

#ifndef DRAWAREA_CANONICAL_TU
class TDrawSystem {
public:
    int GetSetDispModeErrorNum(long hr);
};
#endif

int TDrawSystem::GetSetDispModeErrorNum(long hr)
{
    switch (hr) {
    case (long)0x00000000: return 0;
    case (long)0x80004001: return 0x773;
    case (long)0x80004005: return 0x76C;
    case (long)0x80070057: return 0x76F;
    case (long)0x88760078: return 0x76D;
    case (long)0x88760082: return 0x76E;
    case (long)0x887600A0: return 0x770;
    case (long)0x887600E1: return 0x771;
    case (long)0x887601AE: return 0x772;
    case (long)0x8876021C: return 0x775;
    case (long)0x8876024E: return 0x774;
    default: return 0x7CF;
    }
}
