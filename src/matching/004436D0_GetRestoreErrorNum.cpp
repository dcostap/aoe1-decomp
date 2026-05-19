// GetRestoreErrorNum — real pass
// VA: 004436D0
// Maps DirectDraw HRESULT to error code constant
// Fresh 2026-05-19: signed sparse switch is the natural VC5 binary-search tree.

class TDrawSystem {
public:
    int GetRestoreErrorNum(long hr);
};

int TDrawSystem::GetRestoreErrorNum(long hr)
{
    switch (hr) {
    case 0:
        return 0;
    case (long)0x80004005:
        return 0x708;
    case (long)0x8876024C:
        return 0x709;
    case (long)0x8876005F:
        return 0x70A;
    case (long)0x88760082:
        return 0x70B;
    case (long)0x80070057:
        return 0x70C;
    case (long)0x887600E1:
        return 0x70D;
    case (long)0x8007000E:
        return 0x70E;
    case (long)0x80004001:
        return 0x70F;
    case (long)0x8876024B:
        return 0x710;
    default:
        return 0x76B;
    }
}
