// VA: 00441A70, RGE_Doppleganger_Object::RGE_Doppleganger_Object, 318 bytes
// Source: dpl_obj.cpp lines 121-162
// FLAGS: /GX (SEH frame for constructor)
//
// Constructor with SEH frame:
// - push -1 / push handler / push fs:0 / mov [fs:0],esp (SEH prologue)
// - call RGE_Animated_Object(this, param_1, world, 0)
// - Set vtable to 0x570220
// - Initialize all fields to 0/null
// - Conditional setup(param_1, world) call
// - rge_read sequence for save file loading
// - Conditional CantSeeBits read based on save_game_version >= 7.06
//
// Fields (base class = RGE_Static_Object + RGE_Animated_Object = 0x8C bytes):
//   +0x00 vtable (set to 0x570220 by derived ctor)
//   +0x8C doppled_object
//   +0x90 draw_color
//   +0x94 doppled_master_obj  
//   +0x98 doppled_player
//   +0x9C MapAddress
//   +0xA0 LastMapValue
//   +0xA4 CantSeeBits
//   +0xA8 map_draw_level
//   +0xA9 map_color
//   +0xAC doppledObjectID (-1)
//
// === Attempt log ===
// 1: 256 bytes (no /GX), need flag file. With /GX: 318 bytes but 72% diff.
// 2-3: Various source reorderings. Edit diff 150-198, positional 72-74%.
// LEFT IN SCRATCH: Deep scheduling differences in SEH constructor.
// Differences: (a) original's mov esi,ecx happens after push edi/xor ebx;
//     our VC5 does it before. (b) original loads param_1 once into edi 
//     for reuse across base ctor call; our VC5 re-loads from stack.
//     (c) original schedules second doppledObjectID=-1 between push args
//     and rge_read call; our VC5 doesn't. (d) SEH funclet address differs
//     (relocated). Struct layout and offsets are correct.

typedef unsigned long ulong;

class RGE_Game_World;

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    RGE_Static_Object(int mode, RGE_Game_World* world, int doSetup);
    int setup(int mode, RGE_Game_World* world);

    char pad_04[0x88];
};

class RGE_Animated_Object : public RGE_Static_Object {
public:
    RGE_Animated_Object(int mode, RGE_Game_World* world, int doSetup);
    int setup(int mode, RGE_Game_World* world);
};

extern "C" void __cdecl rge_read(int handle, void* buf, int count);

extern float save_game_version;

class RGE_Doppleganger_Object : public RGE_Animated_Object {
public:
    RGE_Doppleganger_Object(int param_1, RGE_Game_World* world, int param_3);
    int setup(int param_1, RGE_Game_World* world);
    
    void* doppled_object;       // +0x8C
    void* draw_color;           // +0x90
    void* doppled_master_obj;   // +0x94
    int doppled_player;         // +0x98
    ulong* MapAddress;          // +0x9C
    int LastMapValue;           // +0xA0
    int CantSeeBits;            // +0xA4
    char map_draw_level;        // +0xA8
    char map_color;             // +0xA9
    int doppledObjectID;        // +0xAC
};

RGE_Doppleganger_Object::RGE_Doppleganger_Object(int param_1, RGE_Game_World* world, int param_3)
    : RGE_Animated_Object(param_1, world, 0)
{
    *(void**)this = (void*)0x570220;
    
    this->doppled_object = 0;
    this->draw_color = 0;
    this->doppled_master_obj = 0;
    this->doppled_player = 0;
    this->MapAddress = 0;
    this->LastMapValue = 0;
    this->CantSeeBits = 0;
    this->map_draw_level = 0;
    this->map_color = 0;
    this->doppledObjectID = -1;
    
    if (param_3 != 0) {
        this->setup(param_1, world);
    }
    
    rge_read(param_1, &param_1, 4);
    this->doppled_object = (void*)(size_t)param_1;
    rge_read(param_1, &this->map_draw_level, 1);
    rge_read(param_1, &this->map_color, 4);
    rge_read(param_1, &param_1, 4);
    this->doppled_master_obj = (void*)(size_t)param_1;
    rge_read(param_1, &this->doppled_player, 4);
    
    if (save_game_version >= 7.06f) {
        rge_read(param_1, &this->CantSeeBits, 4);
    }
}
