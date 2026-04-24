// From tplayer.cpp
// attempt 1: wrong class layout (0x88 vs 0x848)
// attempt 2: fixed layout, size matches (101), mismatch at offset 4 (param load order)
// attempt 3: reversed param types to int, mismatch moved to offset 23 (stack offset shift)
// attempt 4: tried reversing param order; mismatch back at offset 3
// attempt 5: reverted to PDB order + casts; mismatch at offset 23 (push order/stack layout)
// Original: push 0,0 before loading params; VC5 loads params earlier, different stack baseline
// Left in scratch: stack layout codegen basin issue

class TRIBE_World;
class RGE_Master_Player;

void __cdecl tribe_init(void*, void*, void*, void*, void*, void*, int, int, int, int, int);

class TRIBE_Gaia {
public:
    void* vtable;
    char gap_04[0x44];
    unsigned char field_48;
    char gap_49[0x7FF];
    int field_848;
    int field_84C;
    int field_850;
    int field_854;

    TRIBE_Gaia(TRIBE_World* world, RGE_Master_Player* player, unsigned char param_3, char* param_4, unsigned char param_5);
};

TRIBE_Gaia::TRIBE_Gaia(TRIBE_World* world, RGE_Master_Player* player, unsigned char param_3, char* param_4, unsigned char param_5) {
    tribe_init(this, player, world, (void*)param_3, param_4, (void*)param_5, 0, 1, 0, 0, 0);
    this->vtable = (void*)0x5769A0;
    this->field_48 = 2;
    this->field_848 = 0;
    this->field_84C = 0x1D;
    this->field_854 = 0;
    this->field_850 = 0;
}
