// GetColorKeyErrorNum — real pass
// VA: 00443C00
// Maps DirectDraw HRESULT to error code constant

int __stdcall GetColorKeyErrorNum(long hr)
{
    if (hr < 0x80004005) {
        if (hr == 0x80004001) return 0x82C;
        if (hr == 0x80004005) return 0x82B;
    } else if (hr < 0x8007000E) {
        if (hr == 0x8007000E) return 0x82F;
        if (hr == 0x80070057) return 0x82E;
    } else if (hr < 0x88760082) {
        if (hr == 0x88760082) return 0x82D;
    } else if (hr < 0x88760096) {
        if (hr == 0x88760096) return 0x830;
    } else {
        if (hr == 0) return 0;
        if (hr == -1) return 0x831;
    }
    return 0x833;
}
