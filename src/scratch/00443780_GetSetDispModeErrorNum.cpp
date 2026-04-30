// VA: 00443780 TDrawSystem::GetSetDispModeErrorNum (183 B)
// PDB source: Drawarea.cpp
// Maps DirectDraw HRESULT to error code constant

int __fastcall GetSetDispModeErrorNum(void* _this, int _, long hr)
{
    if (hr < 0x80004005) {
        if (hr == 0x80004005) return 0x76C;
        if (hr == 0x80004001) return 0x773;
    } else if (hr < 0x88760078) {
        if (hr == 0x80070057) return 0x76F;
        if (hr == 0x88760078) return 0x76D;
    } else if (hr < 0x887600A0) {
        if (hr == 0x88760082) return 0x76E;
        if (hr == 0x887600A0) return 0x770;
    } else if (hr < 0x887601AE) {
        if (hr == 0x887600E1) return 0x771;
        if (hr == 0x887601AE) return 0x772;
    } else {
        if (hr == 0x8876021C) return 0x775;
        if (hr == 0x8876024E) return 0x774;
        if (hr == 0) return 0;
    }
    return 0x7CF;
}
