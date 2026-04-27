// VA: 00442860 TDrawSystem::CheckAvailModesCallback (345 B)
// PDB source: Drawarea.cpp
// Packet-grounded: __stdcall DirectDraw enum callback, checks bpp+res, stores info

struct AvailModeInfo {
    char gap00[0x4C];
    int Mode_640x480;          // +0x4C
    int Mode_800x600;          // +0x50
    int Mode_1024x768;         // +0x54
    int Mode_1280x1024;        // +0x58
    int Mode_320x200;          // +0x5C
    int Mode_320x240;          // +0x60
    int Mode_640x480_16;       // +0x64
    int Mode_800x600_16;       // +0x68
    int Mode_1024x768_16;      // +0x6C
    int Mode_1280x1024_16;     // +0x70
    int Mode_320x200_16;       // +0x74
    int Mode_320x240_16;       // +0x78
};

int __stdcall TDrawSystem_CheckAvailModesCallback(void* modeDesc, AvailModeInfo* info)
{
    int bpp = *(int*)((char*)modeDesc + 0x54);  // DDPIXELFORMAT.dwRGBBitCount
    
    if (bpp == 8) {
        int w = *(int*)((char*)modeDesc + 0x0C);  // dwWidth
        int h = *(int*)((char*)modeDesc + 0x08);  // dwHeight
        
        if (w == 640 && h == 480)   { info->Mode_640x480 = 1; return 0; }
        if (w == 800 && h == 600)   { info->Mode_800x600 = 1; return 0; }
        if (w == 1024 && h == 768)  { info->Mode_1024x768 = 1; return 0; }
        if (w == 1280 && h == 1024) { info->Mode_1280x1024 = 1; return 0; }
        if (w == 320 && h == 200)   { info->Mode_320x200 = 1; return 0; }
        if (w == 320 && h == 240)   { info->Mode_320x240 = 1; return 0; }
    } else if (bpp == 16) {
        int w = *(int*)((char*)modeDesc + 0x0C);
        int h = *(int*)((char*)modeDesc + 0x08);
        
        if (w == 640 && h == 480)   { info->Mode_640x480_16 = 1; return 0; }
        if (w == 800 && h == 600)   { info->Mode_800x600_16 = 1; return 0; }
        if (w == 1024 && h == 768)  { info->Mode_1024x768_16 = 1; return 0; }
        if (w == 320 && h == 200)   { info->Mode_320x200_16 = 1; return 0; }
        if (w == 320 && h == 240)   { info->Mode_320x240_16 = 1; return 0; }
    }
    
    return 0;  // Continue enumeration
}
