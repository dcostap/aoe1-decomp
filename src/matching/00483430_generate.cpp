// 00483430 generate (264B)
// rmm_dbct.cpp, lines 378-389, /GX EH frame.
//
// Clean reconstruction: the four generator objects are created with the
// period source's standalone new-expressions, then the inherited random-map
// generator is called. The controller fields and generator sizes below are
// named/layout-backed declarations; they are not decompiler cursor plumbing.
//
// Previous scratch stub only allocated one buffer and stored it as field_4F50;
// that was not the observed four-constructor behavior and has been replaced.
// Main-agent audit restored the donor-backed module destructor surface;
// emitted code remains exact.
// Context audit: this owner uses the canonical random-map base and dbct data
// surface. It remains in rmm_dbct.cpp source order before init and de_init.

#include <new.h>
#include "..\..\include\rmm_dbct_context.h"

uchar RGE_RMM_Database_Controller::generate() {
    new RGE_RMM_Terrain_Generator(this->map, this, &this->terrain_info);
    new RGE_RMM_Land_Generator(this->map, this, &this->land_info);
    new RGE_RMM_Object_Generator(this->map, this, this->world,
                                 &this->object_info, 1);
    new RGE_RMM_Elevation_Generator(this->map, this, &this->elevation_info);

    return RGE_Random_Map_Module::generate();
}
