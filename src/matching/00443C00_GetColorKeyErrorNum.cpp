// GetColorKeyErrorNum — real pass
// VA: 00443C00
// Maps DirectDraw HRESULT to color-key error code constant.
// Fresh 2026-05-19: use sparse signed switch, matching sibling GetRestoreErrorNum pattern.

#ifndef DRAWAREA_CANONICAL_TU
class TDrawSystem {
public:
    int GetColorKeyErrorNum(long hr);
};
#endif

int TDrawSystem::GetColorKeyErrorNum(long hr)
{
    switch (hr) {
    case 0:
        return 0;
    case (long)0x80004005:
        return 0x960;
    case (long)0x88760082:
        return 0x961;
    case (long)0x80070057:
        return 0x962;
    case (long)0x88760250:
        return 0x963;
    case (long)0x88760104:
        return 0x964;
    case (long)0x88760244:
        return 0x965;
    case (long)0x887601C2:
        return 0x966;
    case (long)0x80004001:
        return 0x967;
    case (long)0x8876021C:
        return 0x968;
    default:
        return 0x9C3;
    }
}
