// VA: 00441A70, RGE_Doppleganger_Object::RGE_Doppleganger_Object, 318 bytes
// Source: dpl_obj.cpp lines 121-162
// FLAGS: /GX (SEH frame for constructor)
//
// Constructor with SEH frame:
// - push -1 / push handler / push fs:0 / mov [fs:0],esp (SEH prologue)
// - call RGE_Animated_Object(this, param_1, world, 0)
// - Install the derived vtable through the natural polymorphic class surface
// - Initialize all fields to 0/null
// - Conditional setup(param_1, world) call
// - rge_read sequence for save file loading
// - Conditional CantSeeBits read based on save_game_version >= 7.06
//
// Fields (base class = RGE_Static_Object + RGE_Animated_Object = 0x8C bytes):
//   +0x00 derived vtable
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
// - Initial /GX reconstruction had the right calls and fields but reloaded the
//   file argument and missed the original output-home/register topology.
// - Naming the input `handle` and reusing one ordinary `value` local for the two
//   deserialized object IDs preserved the input in EDI and the parameter-home
//   reuse seen by VC5. The reset of doppledObjectID after the first read is part
//   of the original load behavior, not just initialization.
// - A natural polymorphic base/derived declaration emits the derived vtable;
//   no manual vptr store is retained. The /GX candidate matches all 318 bytes.

typedef unsigned long ulong;

#ifndef DPL_OBJ_SHARED_CONTEXT
class RGE_Game_World;
class RGE_Color_Table;
class RGE_Master_Static_Object;

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    RGE_Static_Object(int mode, RGE_Game_World* world, int doSetup);
    int setup(int mode, RGE_Game_World* world);

    char pad_04[0x88];
};

class RGE_Animated_Object : public RGE_Static_Object {
public:
    virtual unsigned char update();
    RGE_Animated_Object(int mode, RGE_Game_World* world, int doSetup);
    virtual int setup(int mode, RGE_Game_World* world);
};

extern "C" void __cdecl rge_read(int handle, void* buf, int count);

extern float save_game_version;

class RGE_Doppleganger_Object : public RGE_Animated_Object {
public:
    virtual unsigned char update();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void destroy_obj();

    RGE_Doppleganger_Object(int param_1, RGE_Game_World* world, int param_3);
    virtual int setup(int param_1, RGE_Game_World* world);

    RGE_Static_Object* doppled_object;       // +0x8C
    RGE_Color_Table* draw_color;             // +0x90
    RGE_Master_Static_Object* doppled_master_obj; // +0x94
    int doppled_player;         // +0x98
    ulong* MapAddress;          // +0x9C
    int LastMapValue;           // +0xA0
    int CantSeeBits;            // +0xA4
    char map_draw_level;        // +0xA8
    char map_color;             // +0xA9
    int doppledObjectID;        // +0xAC
};
#endif

RGE_Doppleganger_Object::RGE_Doppleganger_Object(int handle, RGE_Game_World* world, int param_3)
    : RGE_Animated_Object(handle, world, 0)
{
    int value;

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
        this->setup(handle, world);
    }

    rge_read(handle, &value, 4);
    this->doppled_object = (RGE_Static_Object*)(size_t)value;
    this->doppledObjectID = -1;
    rge_read(handle, &this->map_draw_level, 1);
    rge_read(handle, &this->map_color, 4);
    rge_read(handle, &value, 4);
    this->doppled_master_obj = (RGE_Master_Static_Object*)(size_t)value;
    rge_read(handle, &this->doppled_player, 4);

    if (save_game_version >= 7.06f) {
        rge_read(handle, &this->CantSeeBits, 4);
    }
}
