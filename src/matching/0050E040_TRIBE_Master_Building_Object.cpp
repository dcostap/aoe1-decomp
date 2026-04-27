// first pass: call the combat-object base ctor with 0, then conditionally run the building-object setup helper
// /GX was required to land the exact EH ctor/body basin for this constructor overload
#include "..\..\include\game_types.h"

class TRIBE_Sound;
class TRIBE_Sprite;
class TRIBE_Master_Building_Object;

class TRIBE_Master_Combat_Object {
public:
    virtual ~TRIBE_Master_Combat_Object();
    TRIBE_Master_Combat_Object(TRIBE_Master_Combat_Object* source, int do_setup);
};

class TRIBE_Master_Building_Object : public TRIBE_Master_Combat_Object {
public:
    RGE_Sound* construction_sound;
    RGE_Sprite* construction_sprite;
    unsigned char building_connect_flag;
    short building_facet;
    unsigned char build_and_go_away;
    short on_build_make_obj;
    short on_build_make_tile;
    short on_build_make_overlay;
    short on_build_make_tech;

    TRIBE_Master_Building_Object(TRIBE_Master_Building_Object* source, int do_setup);
    virtual ~TRIBE_Master_Building_Object();
    int setup(TRIBE_Master_Building_Object* source);
};

TRIBE_Master_Building_Object::TRIBE_Master_Building_Object(TRIBE_Master_Building_Object* source, int do_setup)
    : TRIBE_Master_Combat_Object((TRIBE_Master_Combat_Object*)source, 0) {
    *(void**)this = (void*)0x576700;
    if (do_setup != 0) {
        setup(source);
    }
}
