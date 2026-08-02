// 00458280 RGE_Map::load_border_types
// Source: map.cpp:1802-1822
// Attempt log:
// 1 baseline: typed RGE_Border_Set member loop had the correct size/calls but
//    kept ESI at the record base, not at resource_id (115 differing bytes).
// 2 layout: a named resource_id cursor with the binary-proven -0x1C/+4/+8
//    field offsets and -0x5A0 record stride reduced the drift to 11 bytes.
// 3 control-flow: spelling the nonnegative sound-index arm first reproduced
//    the original jl-to-zero fallback and matched all 205 bytes.
// FLAGS: config/flags/00458280_load_border_types.rsp (/GX is required by the
// observed FS exception-registration frame).
//
// The border table is traversed from its last entry because that is the
// source-level order preserved by the executable.  The sound field is a
// pointer after loading, but the map file initially stores a signed index in
// the same slot.

#include <stdlib.h>

extern "C" void addstring(char** dst, char* left, char* right);

class RGE_Sound;

class TShape {
public:
    char data[0x20];
    TShape(char* filename, long resource_id);
    ~TShape();
    int is_loaded();
};

class RGE_Border_Set {
public:
    unsigned char loaded;       // +0x00
    unsigned char random;       // +0x01
    char name[13];              // +0x02
    char pict_name[13];         // +0x0F
    long resource_id;           // +0x1C
    TShape* shape;              // +0x20
    RGE_Sound* sound;           // +0x24 (file index before loading)
    char rest[0x5A0 - 0x28];
};

class RGE_Map {
public:
    char before_border_types[0x338C];
    RGE_Border_Set border_types[16];

    void load_border_types(RGE_Sound** sounds);
};

void RGE_Map::load_border_types(RGE_Sound** sounds)
{
    char* filename2 = 0;
    long* resource_id = &this->border_types[15].resource_id;
    int count = 16;

    do {
        RGE_Border_Set* border = (RGE_Border_Set*)(resource_id - 7);
        if (border->loaded != 0) {
            addstring(&filename2, border->pict_name, ".shp");
            TShape* shape = new TShape(filename2, *resource_id);
            border->shape = shape;

            if (shape->is_loaded() == 0) {
                border->loaded = 0;
            }

            if ((long)border->sound >= 0) {
                border->sound = sounds[(long)border->sound];
            } else {
                border->sound = 0;
            }
        }

        resource_id -= 0x168;
        --count;
    } while (count != 0);

    if (filename2 != 0) {
        free(filename2);
    }
}
