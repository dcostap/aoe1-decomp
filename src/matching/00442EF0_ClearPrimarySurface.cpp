// VA: 00442EF0 TDrawSystem::ClearPrimarySurface (62 B)
// Clears the primary surface using Blt.

#include "../drawarea_phase2_context.h"

void TDrawSystem::ClearPrimarySurface()
{
    if (this->ScreenMode != 2)
        return;

    IDirectDrawSurface* surface = this->PrimarySurface;
    if (surface == 0)
        return;

    _DDBLTFX ddbltfx;
    ddbltfx.dwSize = 0x64;
    ddbltfx.dwFillColor = 0;
    surface->Blt(0, 0, 0, 0x1000400, &ddbltfx);
}
