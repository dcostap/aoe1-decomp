// VA: 00442F30 TDrawSystem::CheckSurfaces (318 B)
// PDB source: Drawarea.cpp, lines 927-1012
//
// Attempt log:
// - Replaced the generated surface shim with the period DirectDraw surface
//   status/restore flow and the real 0x6C DDSURFACEDESC plus 0x64 DDBLTFX
//   local records. First typed reconstruction follows the packet's loop over
//   DrawAreaList and the original COM vtable slots.
// - Removing the persistent primary-surface local restored the exact ESI/EDI
//   register basin and left a single pixel-format displacement mismatch.
// - The binary's +0x60 load is DDSURFACEDESC.ddpfPixelFormat.dwRGBBitCount,
//   not dwFlags. A direct `return 3` on a child CheckSurface failure preserves
//   the original far failure tail; exact under the default flags.

#include <string.h>
#include "../drawarea_phase2_context.h"
#pragma function(memset)

unsigned char TDrawSystem::CheckSurfaces()
{
    if (this->DrawType != 2)
        return 0;

    if (this->PrimarySurface != 0 && this->DrawArea != 0 &&
        this->DrawArea->DrawSurface != 0) {
        unsigned char result = 0;
        _DDSURFACEDESC ddsd;
        _DDBLTFX ddbltfx;

        long hr = this->PrimarySurface->IsLost();
        if (hr != 0) {
            this->GetIsLostErrorNum(hr);
            memset(&ddsd, 0, sizeof(ddsd));
            ddsd.dwSize = sizeof(ddsd);

            hr = this->DirDraw->GetDisplayMode(&ddsd);
            if (hr == 0 &&
                (ddsd.dwWidth != (unsigned long)this->ScreenWidth ||
                 ddsd.dwHeight != (unsigned long)this->ScreenHeight ||
                 ddsd.ddpfPixelFormat.dwRGBBitCount != 8))
                return 1;

            hr = this->PrimarySurface->Restore();
            if (hr != 0) {
                this->GetRestoreErrorNum(hr);
                return 3;
            }

            this->Restored = 1;
            result = 2;
            ddbltfx.dwSize = sizeof(ddbltfx);
            ddbltfx.dwFillColor = 0;
            this->PrimarySurface->Blt(0, 0, 0, 0x1000400, &ddbltfx);
        }

        DrawAreaNode* node = this->DrawAreaList;
        while (node != 0) {
            if (node->DrawArea != this->PrimaryArea &&
                node->DrawArea->CheckSurface() == 3)
                return 3;
            node = node->NextNode;
        }
        return result;
    }
    return 3;
}
