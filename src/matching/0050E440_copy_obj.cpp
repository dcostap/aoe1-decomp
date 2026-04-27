// VA: 0050E440 TRIBE_Master_Building_Object::copy_obj (137 B)
// PDB source: tm_b_obj.cpp

struct TRIBE_Master_Combat_Object_Base {
    char base[0x164];
    void copy_obj(void* src);
};

struct TRIBE_Master_Building_Object {
    char base[0x164];
    void* construction_sound;      // +0x164
    void* construction_sprite;     // +0x168
    unsigned char building_connect_flag;  // +0x16C
    short building_facet;          // +0x16E
    unsigned char build_and_go_away;      // +0x170
    short on_build_make_obj;       // +0x172
    short on_build_make_tile;      // +0x174
    short on_build_make_overlay;   // +0x176
    short on_build_make_tech;      // +0x178
    
    void copy_obj(void* src);
};

void TRIBE_Master_Building_Object::copy_obj(void* src)
{
    ((TRIBE_Master_Combat_Object_Base*)this)->copy_obj(src);
    construction_sprite = ((TRIBE_Master_Building_Object*)src)->construction_sprite;
    construction_sound = ((TRIBE_Master_Building_Object*)src)->construction_sound;
    building_connect_flag = ((TRIBE_Master_Building_Object*)src)->building_connect_flag;
    building_facet = ((TRIBE_Master_Building_Object*)src)->building_facet;
    build_and_go_away = ((TRIBE_Master_Building_Object*)src)->build_and_go_away;
    on_build_make_obj = ((TRIBE_Master_Building_Object*)src)->on_build_make_obj;
    on_build_make_tile = ((TRIBE_Master_Building_Object*)src)->on_build_make_tile;
    on_build_make_overlay = ((TRIBE_Master_Building_Object*)src)->on_build_make_overlay;
    on_build_make_tech = ((TRIBE_Master_Building_Object*)src)->on_build_make_tech;
}
