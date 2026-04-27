// GetLockErrorNum — real pass
// VA: 00443840
// Maps DirectDraw HRESULT to error code constant

int __stdcall GetLockErrorNum(long hr)
{
    if (hr < 0x8007000E) {
        if (hr == 0x80004005) return 0x7D0;
        if (hr == 0x8007000E) return 0x7D6;
    } else if (hr < 0x88760082) {
        if (hr == 0x80070057) return 0x7D2;
        if (hr == 0x88760082) return 0x7D1;
    } else if (hr < 0x887601AE) {
        if (hr == 0x88760096) return 0x7D8;
        if (hr == 0x887601AE) return 0x7D3;
    } else if (hr < 0x8876021C) {
        if (hr == 0x887601C2) return 0x7D4;
        if (hr == 0x8876021C) return 0x7D5;
    } else {
        if (hr == 0x88760248) return 0x7D7;
        if (hr == 0) return 0;
    }
    return 0x833;
}
