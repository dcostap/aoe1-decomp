// VA: 00442860 TDrawSystem::CheckAvailModesCallback
// PDB source: Drawarea.cpp lines 504-574
// Attempt log:
// - Replaced the initial offset-only callback scaffold with the period DirectDraw
//   descriptor/mode-info ownership and the observed callback return value.

#include "../drawarea_phase2_context.h"

long __stdcall TDrawSystem::CheckAvailModesCallback(
    _DDSURFACEDESC* mode_desc, void* context)
{
    register long result = 1;
    TDrawSystem* mode_info = (TDrawSystem*)context;
    int bpp = mode_desc->ddpfPixelFormat.dwRGBBitCount;

    if (bpp == 8) {
        if (mode_desc->dwWidth == 640 && mode_desc->dwHeight == 480) {
            mode_info->ModeAvail640 = 1;
            goto done;
        }
        if (mode_desc->dwWidth == 800 && mode_desc->dwHeight == 600) {
            mode_info->ModeAvail800 = 1;
            goto done;
        }
        if (mode_desc->dwWidth == 1024 && mode_desc->dwHeight == 768) {
            mode_info->ModeAvail1024 = 1;
            goto done;
        }
        if (mode_desc->dwWidth == 1280 && mode_desc->dwHeight == 1024) {
            mode_info->ModeAvail1280 = 1;
            goto done;
        }
        if (mode_desc->dwWidth == 320 && mode_desc->dwHeight == 200) {
            mode_info->ModeAvail320_200 = 1;
            goto done;
        }
        if (mode_desc->dwWidth == 320 && mode_desc->dwHeight == 240) {
            mode_info->ModeAvail320_240 = 1;
            goto done;
        }
    } else if (bpp == 16) {
        if (mode_desc->dwWidth == 640 && mode_desc->dwHeight == 480) {
            mode_info->ModeAvail640_16 = 1;
            goto done;
        }
        if (mode_desc->dwWidth == 800 && mode_desc->dwHeight == 600) {
            mode_info->ModeAvail800_16 = 1;
            goto done;
        }
        if (mode_desc->dwWidth == 1024 && mode_desc->dwHeight == 768) {
            mode_info->ModeAvail1024_16 = 1;
            goto done;
        }
        if (mode_desc->dwWidth == 320 && mode_desc->dwHeight == 200) {
            mode_info->ModeAvail320_200_16 = 1;
            goto done;
        }
        if (mode_desc->dwWidth == 320 && mode_desc->dwHeight == 240) {
            mode_info->ModeAvail320_240_16 = 1;
            goto done;
        }
    }
done:
    return result;
}
