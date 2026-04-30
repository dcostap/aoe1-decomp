// VA: 004438F0 TDrawSystem::GetDCErrorNum (147 B)
// PDB source: Drawarea.cpp
// Maps DirectDraw HRESULT to error code constant
// FLAGS: /Od — VC5 /O2 applies neg/sbb/and/add transform that doesn't match original

int __fastcall GetDCErrorNum(void* _this, int _, long hr)
{
    if (hr > 0x80004005) {
        if (hr > 0x88760082) {
            if (hr > 0x8876021C) {
                if (hr == 0x88760250) return 0x838;
                if (hr == 0x8876026C) return 0x835;
                if (hr == 0) return 0;
            } else {
                if (hr == 0x8876021C) return 0x83B;
                if (hr == 0x887601C2) return 0x839;
            }
        } else {
            if (hr == 0x88760082) return 0x836;
            if (hr == 0x80070057) return 0x837;
        }
    } else if (hr == 0x80004005) {
        return 0x834;
    } else {
        if (hr == 0x80004001) return 0x83A;
    }
    return 0x897;
}
