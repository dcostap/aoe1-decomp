// 004512D0 RGE_Master_Doppleganger_Object::make_new_obj
// Source: m_dg_obj.cpp lines 94-108
// Size/layout repair pass. One complete class definition + size guard.

#include <stdlib.h>

extern "C" void* __cdecl operator_new(size_t size);

class RGE_Player;
class RGE_Master_Static_Object;
class RGE_Game_World;
class RGE_Static_Object;

// DgRecycled: standalone (no base), compiler-managed vtable at offset 0
class DgRecycled {
public:
    virtual ~DgRecycled();
    virtual void d01();   virtual void d02();   virtual void d03();
    virtual void d04();   virtual void d05();   virtual void d06();
    virtual void d07();   virtual void d08();   virtual void d09();
    virtual void d10();   virtual void d11();   virtual void d12();
    virtual void d13();   virtual void d14();   virtual void d15();
    virtual void d16();   virtual void d17();   virtual void d18();
    virtual void d19();   virtual void d20();   virtual void d21();
    virtual void d22();   virtual void d23();   virtual void d24();
    virtual void d25();   virtual void d26();   virtual void d27();
    virtual void d28();   virtual void d29();   virtual void d30();
    virtual void d31();   virtual void d32();   virtual void d33();
    virtual void d34();   virtual void d35();   virtual void d36();
    virtual void d37();   virtual void d38();   virtual void d39();
    virtual void d40();   virtual void d41();   virtual void d42();
    virtual void d43();   virtual void d44();   virtual void d45();
    virtual void d46();   virtual void d47();   virtual void d48();
    virtual void d49();   virtual void d50();   virtual void d51();
    virtual void d52();   virtual void d53();   virtual void d54();
    virtual void d55();   virtual void d56();   virtual void d57();
    virtual void d58();   virtual void d59();   virtual void d60();
    virtual void d61();   virtual void d62();   virtual void d63();
    virtual void d64();   virtual void d65();   virtual void d66();
    virtual void d67();   virtual void d68();   virtual void d69();
    virtual void d70();   virtual void d71();   virtual void d72();
    virtual void d73();   virtual void d74();   virtual void d75();
    virtual void d76();   virtual void d77();   virtual void d78();
    virtual void d79();   virtual void d80();   virtual void d81();
    virtual void d82();   virtual void d83();   virtual void d84();
    virtual void d85();   virtual void d86();   virtual void d87();
    virtual void d88();   virtual void d89();   virtual void d90();
    virtual void d91();   virtual void d92();   virtual void d93();
    virtual void d94();   virtual void d95();   virtual void d96();
    virtual void d97();   virtual void d98();   virtual void d99();
    virtual void d100();  virtual void d101();  virtual void d102();
    virtual void d103();  virtual void d104();  virtual void d105();
    virtual void d106();  virtual void d107();  virtual void d108();
    virtual void d109();  virtual void d110();  virtual void d111();
    virtual void d112();  virtual void d113();  virtual void d114();
    virtual void d115();  virtual void d116();  virtual void d117();
    virtual void d118();  virtual void d119();  virtual void d120();
    virtual void d121();  virtual void d122();
    virtual void recycle_in_to_game(RGE_Master_Static_Object*, RGE_Player*, float, float, float, RGE_Static_Object*);
};

// Master hierarchy: void* vtable (data member) for correct field offsets
class RGE_Master_Static_Object {
public:
    void* vtable;
    char master_type;
    char _pad_5[0xA4 - 0x5];
    char recyclable;
    char _pad_a5[0xBC - 0xA5];
};

class RGE_Master_Animated_Object : public RGE_Master_Static_Object {
public:
};

class RGE_Master_Doppleganger_Object : public RGE_Master_Animated_Object {
public:
    virtual RGE_Static_Object* make_new_obj(RGE_Player*, float, float, float, RGE_Static_Object*);
};

// === ONE complete class definition before make_new_obj ===
class RGE_Doppleganger_Object {
public:
    char gap_00[0xB0];
    RGE_Doppleganger_Object(RGE_Master_Doppleganger_Object*, RGE_Player*,
                            float, float, float, int, RGE_Static_Object*);
};

// === Size guard: compile-time assertion ===
typedef char assert_dg_size[(sizeof(RGE_Doppleganger_Object) == 0xB0) ? 1 : -1];

class RGE_Player {
public:
    char _pad_player[0x3C];
    RGE_Game_World* world;
};

class RGE_Game_World {
public:
    RGE_Static_Object* recycle_object_in_to_game(char);
};

RGE_Static_Object*
RGE_Master_Doppleganger_Object::make_new_obj(RGE_Player* player, float x, float y, float z, RGE_Static_Object* static_obj)
{
    if (recyclable) {
        RGE_Static_Object* recycled = player->world->recycle_object_in_to_game(master_type);
        if (recycled) {
            ((DgRecycled*)recycled)->recycle_in_to_game(
                (RGE_Master_Static_Object*)this, player, x, y, z, static_obj);
            return recycled;
        }
    }

    return (RGE_Static_Object*)new RGE_Doppleganger_Object(this, player, x, y, z, 1, static_obj);
}
