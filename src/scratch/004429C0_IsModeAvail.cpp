// IsModeAvail — real pass
// VA: 004429C0
// TDrawSystem method — checks if a display mode (bpp, width, height) is available
// Returns field value if match found, 0 otherwise

int __fastcall IsModeAvail(void* _this, int _, int width, int height, int bpp)
{
    if (bpp == 8) {
        if (width < 0x280) {
            if (width == 0x140) {
                if (height == 0xC8) return *(int*)((char*)_this + 0x5C);
                if (height == 0xF0) return *(int*)((char*)_this + 0x60);
            }
        } else {
            if (width == 0x280) return *(int*)((char*)_this + 0x4C);
            if (width == 0x320) return *(int*)((char*)_this + 0x50);
            if (width == 0x400) return *(int*)((char*)_this + 0x54);
            if (width == 0x500) return *(int*)((char*)_this + 0x58);
        }
    } else if (bpp == 16) {
        if (width < 0x280) {
            if (width == 0x140) {
                if (height == 0xC8) return *(int*)((char*)_this + 0x64);
                if (height == 0xF0) return *(int*)((char*)_this + 0x68);
            }
        } else {
            if (width == 0x280) return *(int*)((char*)_this + 0x6C);
        }
    }
    return 0;
}
