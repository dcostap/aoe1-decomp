// VA: 00443AD0 TDrawSystem::GetCreateErrorNum (291 B)
// PDB source: Drawarea.cpp
// Packet-grounded: large HRESULT-to-error-number switch tree
// Maps DirectX/COM error codes to game-internal error numbers

int TDrawSystem_GetCreateErrorNum(void* self, int hresult)
{
    // Hierarchical comparison tree mapping HRESULT -> error number
    
    if (hresult < 0x8876005F) {
        // First level: very negative errors
        if (hresult == 0x80004005) return 0x8FC;        // E_FAIL
        if (hresult == 0x8007000E) return 0x908;        // E_OUTOFMEMORY
        // else fall through to default
    } else if (hresult < 0x88760082) {
        if (hresult == 0x8876005F) return 0x90B;        // DDERR_GENERIC
        if (hresult == 0x80070057) return 0x8FE;        // E_INVALIDARG
    } else if (hresult < 0x887600B4) {
        if (hresult == 0x88760082) return 0x8FD;
        if (hresult == 0x88760064) return 0x902;
    } else if (hresult < 0x887600E1) {
        if (hresult == 0x887600B4) return 0x904;
        if (hresult == 0x88760091) return 0x903;
    } else if (hresult < 0x88760154) {
        if (hresult == 0x887600E1) return 0x907;
        if (hresult == 0x887600D4) return 0x901;
    } else if (hresult < 0x88760233) {
        if (hresult == 0x88760154) return 0x906;
        if (hresult == 0x887600E6) return 0x905;
    } else if (hresult < 0x88760234) {
        if (hresult == 0x88760233) return 0x900;
        if (hresult == 0x8876017C) return 0x8FF;
    } else {
        if (hresult == 0x88760234) return 0x909;
        if (hresult == 0x88760235) return 0x90A;
        if (hresult == 0) return 0;
    }
    
    return 0x95F;  // Unknown error
}
