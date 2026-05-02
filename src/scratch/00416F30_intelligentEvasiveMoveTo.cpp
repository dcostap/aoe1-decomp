// VA: 00416F30 UnitAIModule::intelligentEvasiveMoveTo (666 bytes)
// Combined TU ready - uses include/unit_ai_module.h
// Facet-based evasion: tries 8 directions with 2-tile offset.
// Uses pointer-offset arithmetic for game struct access.
// Uses memcpy workaround for VC5 ICE with function pointer casts.
//
// ACCEPTED_DRIFT candidate.

#include "../../include/unit_ai_module.h"
#include <string.h>

extern "C" float __cdecl distance_to_position(void* obj, float x, float y, float z);

int UnitAIModule::intelligentEvasiveMoveTo(float x, float y, float z, int targetId, int forceFlag)
{
    if (!forceFlag && this->currentActionValue == -1) {
        return 0;
    }
    
    void* obj = (void*)this->objectValue;
    
    // Clamp x to map bounds
    if (x < 0.0f) {
        x = 0.0f;
    } else {
        int mapWidth = *(int*)(*(int*)(*(int*)(*(int*)((char*)obj + 0x0C) + 0x3C) + 0x28) + 0x08);
        if (x >= (float)mapWidth) {
            x -= 0.5f;
        }
    }
    
    // Clamp y to map bounds
    if (y < 0.0f) {
        y = 0.0f;
    } else {
        int mapHeight = *(int*)(*(int*)(*(int*)(*(int*)((char*)obj + 0x0C) + 0x3C) + 0x28) + 0x0C);
        if (y >= (float)mapHeight) {
            y -= 0.5f;
        }
    }
    
    // Convert to ints
    int xi = (int)x;
    int yi = (int)y;
    int zi = (int)(*(float*)((char*)obj + 0x40));
    
    // vtable dispatch via memcpy (workaround for VC5 ICE)
    void** vtbl = *(void***)obj;
    void* setPosPtr;
    void* moveFnPtr;
    memcpy(&setPosPtr, &vtbl[0x198 / 4], 4);
    memcpy(&moveFnPtr, &vtbl[0x154 / 4], 4);
    
    // Try original position
    int posOk = ((int (*)(void*, int, int, int, float, int))setPosPtr)(obj, xi, yi, zi, 1.0f, -1);
    
    // Search facets if blocked
    if (posOk == 0) {
        float objZ = *(float*)((char*)obj + 0x40);
        float bestDist = distance_to_position(obj, (float)xi, (float)yi, objZ);
        
        for (int f = 0; f <= 7; f++) {
            int nx = xi, ny = yi;
            
            switch (f) {
            case 0: nx -= 2; break;
            case 1: ny -= 2; break;
            case 2: nx += 2; break;
            case 3: ny += 2; break;
            case 4: nx += 2; break;
            case 5: ny -= 2; break;
            case 6: nx -= 2; break;
            case 7: nx -= 2; break;
            }
            
            // Clamp to map bounds
            if (nx < 0) nx = 0; else {
                int mw = *(int*)(*(int*)(*(int*)(*(int*)((char*)obj + 0x0C) + 0x3C) + 0x28) + 0x08);
                if (nx >= mw) nx = mw - 1;
            }
            if (ny < 0) ny = 0; else {
                int mh = *(int*)(*(int*)(*(int*)(*(int*)((char*)obj + 0x0C) + 0x3C) + 0x28) + 0x0C);
                if (ny >= mh) ny = mh - 1;
            }
            
            if (targetId != -1) {
                int r = ((int (*)(void*, int, int, int, float, int))setPosPtr)(obj, nx, ny, zi, 1.0f, -1);
                if (r == 1) { xi = nx; yi = ny; break; }
            } else {
                float d = distance_to_position(obj, (float)nx, (float)ny, objZ);
                if (d < bestDist) continue;
            }
        }
    }
    
    // Move to found position
    int moveOk = ((int (*)(void*, float, float, float, float, int))moveFnPtr)(obj, (float)xi - 0.5f, (float)yi - 0.5f, (float)zi, 0.5f, targetId);
    
    if (moveOk == 1) {
        this->setCurrentAction(0x262);
        this->setCurrentTarget((int)-1, (float)xi - 0.5f, (float)yi - 0.5f, (float)zi - 0.5f);
        return 1;
    }
    
    return 0;
}
