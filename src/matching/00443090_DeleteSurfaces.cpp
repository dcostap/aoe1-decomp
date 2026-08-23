// VA: 00443090 TDrawSystem::DeleteSurfaces
// PDB source: Drawarea.cpp lines 1037-1056

#include "../../include/drawarea_context.h"

void TDrawSystem::DeleteSurfaces()
{
    if (this->DrawArea != 0) {
        delete this->DrawArea;
        this->DrawArea = 0;
    }

    if (this->PrimarySurface != 0) {
        if (this->PrimaryArea != 0)
            delete this->PrimaryArea;

        this->PrimaryArea = 0;
        this->PrimarySurface->Release();
        this->PrimarySurface = 0;
    }
}
