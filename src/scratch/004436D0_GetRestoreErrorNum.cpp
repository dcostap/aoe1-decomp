// GetRestoreErrorNum — real pass
// VA: 004436D0
// Maps DirectDraw HRESULT to error code constant

int __stdcall GetRestoreErrorNum(long hr)
{
    if (hr < 0x80004005) {  // branch boundary
        if (hr == 0x80004005) return 0x708;  // DDERR_SURFACELOST
        if (hr == 0x80004001) return 0x70F;  // DDERR_NOEXCLUSIVEMODE
    } else if (hr < 0x88760082) {
        if (hr == 0x80070057) return 0x70C;  // E_INVALIDARG
        if (hr == 0x8007000E) return 0x70E;  // E_OUTOFMEMORY
        if (hr == 0x88760082) return 0x70B;  // DDERR_SURFACEBUSY
    } else if (hr < 0x8876024B) {
        if (hr == 0x8876005F) return 0x70A;  // DDERR_WASSTILLDRAWING
        if (hr == 0x887600E1) return 0x70D;  // DDERR_INVALIDPARAMS
        if (hr == 0x8876024B) return 0x710;
    } else {
        if (hr == 0x8876024C) return 0x709;
        if (hr == 0) return 0;
        if (hr == 0x88760082) return 0x70B;
    }
    // below handles all the remaining comparisons in original order
    if (hr == 0x8007000E) return 0x70E;
    if (hr == 0x80070057) return 0x70C;
    if (hr == 0x8876005F) return 0x70A;
    if (hr == 0x88760082) return 0x70B;
    if (hr == 0x887600E1) return 0x70D;
    if (hr == 0x8876024B) return 0x710;
    if (hr == 0x8876024C) return 0x709;
    if (hr == 0x80004001) return 0x70F;
    if (hr == 0x80004005) return 0x708;
    if (hr == 0) return 0;
    return 0x76B;
}
