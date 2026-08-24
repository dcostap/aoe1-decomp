// VA: 00443990 TDrawSystem::GetBlitErrorNum (308 B)
// PDB source: Drawarea.cpp
// Packet-grounded: HRESULT-to-error-number switch, following the exact
// GetCreateErrorNum same-TU source family.
// Main-agent audit confirmed the natural HRESULT switch and same-TU draw-system
// surface; exact bytes were revalidated after promotion.

#ifndef DRAWAREA_CANONICAL_TU
class TDrawSystem {
public:
    int GetBlitErrorNum(long hr);
};
#endif

int TDrawSystem::GetBlitErrorNum(long hr)
{
    switch (hr) {
    case 0:
        return 0;
    case (long)0x80004005:
        return 0x898;
    case (long)0x88760082:
        return 0x899;
    case (long)0x80070057:
        return 0x89A;
    case (long)0x88760154:
        return 0x89B;
    case (long)0x8876006E:
        return 0x89C;
    case (long)0x88760096:
        return 0x89D;
    case (long)0x887600B4:
        return 0x89E;
    case (long)0x887601C2:
        return 0x8A2;
    case (long)0x887600CD:
        return 0x8A0;
    case (long)0x88760240:
        return 0x8A1;
    case (long)0x8876023F:
        return 0x89F;
    case (long)0x80004001:
        return 0x8A3;
    case (long)0x887600FA:
        return 0x8A4;
    case (long)0x88760118:
        return 0x8A5;
    case (long)0x88760122:
        return 0x8A6;
    case (long)0x88760136:
        return 0x8A7;
    case (long)0x887601AE:
        return 0x8A8;
    default:
        return 0x8FB;
    }
}
