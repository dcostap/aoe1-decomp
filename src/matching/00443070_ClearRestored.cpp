// VA: 00443070 TDrawSystem::ClearRestored
// PDB source: Drawarea.cpp lines 1018-1031

#include "../../include/drawarea_context.h"

void TDrawSystem::ClearRestored()
{
    DrawAreaNode* node;

    node = this->DrawAreaList;
    this->Restored = 0;
    while (node != 0) {
        node->DrawArea->Restored = 0;
        node = node->NextNode;
    }
}
