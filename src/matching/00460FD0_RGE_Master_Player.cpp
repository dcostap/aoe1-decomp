// VA: 00460FD0 RGE_Master_Player::RGE_Master_Player(FILE*)
// PDB source: mst_play.cpp
// Attempt log:
// - Reconstructed the FILE* constructor from the original fscanf/calloc sequence and
//   the proven RGE_Master_Player layout; baseline was exact-size with a 6-byte
//   first-fscanf argument-order mismatch.
// - Swapped the two short fscanf destinations to the binary/source order (+0x2A,
//   then +0x20); exact match.
// - Replaced the manual vtable field/store with the proven polymorphic class surface;
//   compiler-generated vptr remains exact and is the retained canonical source.

#ifndef MST_PLAY_SHARED_CONTEXT
#include <stdio.h>
#include <stdlib.h>

struct RGE_Master_Static_Object;
class RGE_Sprite;
class RGE_Sound;

class RGE_Master_Player {
public:
    virtual ~RGE_Master_Player();
    virtual void finish_init(int, RGE_Sprite**, RGE_Sound**);
    virtual void load_master_object(int, unsigned char, RGE_Sprite**, RGE_Sound**, short);
    virtual void create_master_object_space(short);
    virtual void load_object(FILE*, unsigned char, RGE_Sprite**, RGE_Sound**, short);
    virtual void save(int);

    char name[20];                    // +0x04
    short master_object_num;          // +0x18
    unsigned char pad_1A[2];          // +0x1A
    RGE_Master_Static_Object** master_objects; // +0x1C
    short attribute_num;             // +0x20
    unsigned char pad_22[2];         // +0x22
    float* attributes;                // +0x24
    unsigned char culture;            // +0x28
    unsigned char type;               // +0x29
    short tribe_effect;              // +0x2A

    RGE_Master_Player(FILE* file);
};
#endif

RGE_Master_Player::RGE_Master_Player(FILE* file)
{
    short temp_index;
    short temp_culture;
    short temp_amount;
    float amount;

    type = 0;
    fscanf(file, "%s %hd %hd", name, &tribe_effect, &attribute_num);

    if (attribute_num > 0) {
        attributes = (float*)calloc((int)attribute_num, 4);
    } else {
        attributes = 0;
    }

    fscanf(file, "%hd", &temp_index);
    for (short i = 0; i < temp_index; i++) {
        fscanf(file, "%hd %f", &temp_amount, &amount);
        attributes[temp_amount] = amount;
    }

    fscanf(file, "%hd", &temp_culture);
    culture = (unsigned char)temp_culture;
    master_object_num = 0;
    master_objects = 0;
}
