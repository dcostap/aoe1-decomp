// VA: 005414A0 RGE_Game_World::data_load_effects
// FLAGS: /GX required for original SEH/new/ctor cleanup basin
// left in scratch: /GX natural new emits the expected SEH prolog, allocation, and ctor call, but VC5 sinks
// the member store into the non-null path and branches the null path past the configured range. Original keeps
// a common tail (`jmp`, `xor eax,eax`, then one store/SEH restore). Tried explicit placement-new temp and
// volatile temp/member forms; same sunk-store basin.

void* __cdecl operator new(unsigned int size);
void* __cdecl operator new(unsigned int size, void* ptr);

class RGE_Effects {
public:
    char gap_00[0x0C];
    RGE_Effects(char* filename);
};

class RGE_Game_World {
public:
    char gap_00[0x4C];
    volatile RGE_Effects* effects;

    void data_load_effects(char* filename);
};

void RGE_Game_World::data_load_effects(char* filename) {
    volatile RGE_Effects* effects = (RGE_Effects*)operator new(0x0C);
    if (effects == 0) {
        effects = 0;
    } else {
        effects = new((void*)effects) RGE_Effects(filename);
    }
    this->effects = (RGE_Effects*)effects;
}
