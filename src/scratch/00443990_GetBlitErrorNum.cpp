// VA: 00443990 TDrawSystem::GetBlitErrorNum (308 B)
// PDB source: Drawarea.cpp
// Packet-grounded: HRESULT-to-error-number switch for blit errors (similar to GetCreateErrorNum)

int TDrawSystem_GetBlitErrorNum(void* self, int hresult)
{
    // Balanced comparison tree for DirectDraw blit HRESULTs
    if (hresult < 0x8876005F) {
        if (hresult == 0x80004005) return 0x8FC;        // E_FAIL
        if (hresult == 0x8007000E) return 0x908;        // E_OUTOFMEMORY
    } else if (hresult < 0x88760082) {
        if (hresult == 0x8876005F) return 0x90B;        // DDERR_GENERIC
        if (hresult == 0x88760064) return 0x902;
    } else if (hresult < 0x88760091) {
        if (hresult == 0x88760082) return 0x8FD;
        if (hresult == 0x80070057) return 0x8FE;        // E_INVALIDARG
    } else if (hresult < 0x887600B4) {
        if (hresult == 0x88760091) return 0x903;
        if (hresult == 0x887600A2) return 0x906;        // ?
    } else if (hresult < 0x887600D4) {
        if (hresult == 0x887600B4) return 0x904;
        if (hresult == 0x887600C9) return 0x905;
    } else if (hresult < 0x887600E1) {
        if (hresult == 0x887600D4) return 0x901;
        if (hresult == 0x887600DA) return 0x900;
    } else if (hresult < 0x887600E6) {
        if (hresult == 0x887600E1) return 0x907;
    } else {
        // Additional range
        if (hresult == 0x887600E6) return 0x905;
        if (hresult == 0x88760234) return 0x909;
        if (hresult == 0) return 0;
    }
    
    return 0x95F;  // Unknown/default error
}
