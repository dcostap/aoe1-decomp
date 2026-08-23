// VA: 00483200 ~RGE_RMM_Database_Controller
//
// Attempt 1: compile error, wrong world type.
// Attempt 2: fixed world type, but the destructor body was still only a stub.
// Clean reconstruction: the owned map table is an array of 0x48-byte records;
// each record owns four optional arrays, followed by the table itself. The
// class owns the map_info aggregate at +0x4F54 and derives from the real
// RGE_Random_Map_Module base so its destructor tail is emitted naturally.
// Probe 1: a named count and entry pointer created a stack home and preserved
// the entry across all four frees; the executable instead rereads map_info and
// the map base at each field group.
// Probe 2: direct member rereads plus separate positive guards restored
// the original ESI-held this pointer and repeated map-base loads (166 differing
// bytes, but still an 8-byte structural shortfall).
// Probe 3: moving the loop index into the inner guard did not change codegen.
// Probe 4: a natural counted for loop restored the preheader test, delayed EDI
// save, exact block layout, and all 213 bytes.
// Probe 5: canonical exact-sized aggregate names for the four owned info blocks
// and the known base field order preserved the exact output.
// BINARY NOTE: The qualified owner is RGE_RMM_Database_Controller::~RGE_RMM_Database_Controller,
// with PDB span rmm_dbct.cpp:308-331 and original boundary 00483200-004832D4.
// Context audit: this owner now shares the canonical random-map base and data
// records with the rmm_dbct.cpp prefix. The PDB module and address order remain
// unchanged.

#include <stdlib.h>
#include "..\..\include\rmm_dbct_context.h"

RGE_RMM_Database_Controller::~RGE_RMM_Database_Controller() {
    if (this->map_info.map_num > 0) {
        if (this->map_info.maps != 0) {
            for (int i = 0; i < this->map_info.map_num; ++i) {
                if (this->map_info.maps[i].land_info.land_num > 0) {
                    free(this->map_info.maps[i].land_info.land);
                }
                if (this->map_info.maps[i].terrain_info.terrain_num > 0) {
                    free(this->map_info.maps[i].terrain_info.terrain);
                }
                if (this->map_info.maps[i].object_info.object_num > 0) {
                    free(this->map_info.maps[i].object_info.objects);
                }
                if (this->map_info.maps[i].elevation_info.elevation_num > 0) {
                    free(this->map_info.maps[i].elevation_info.elevation);
                }
            }

            free(this->map_info.maps);
            this->map_info.map_num = 0;
        }
    }
}
