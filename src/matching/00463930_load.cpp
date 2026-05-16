// VA: 00463930 RGE_Object_List::load
// Attempt log:
// initial natural switch/new constructor implementation from packet.

class RGE_Game_World;

class RGE_Static_Object { public: char pad[0x88]; RGE_Static_Object(int, RGE_Game_World*, int); };
class RGE_Animated_Object { public: char pad[0x8c]; RGE_Animated_Object(int, RGE_Game_World*, int); };
class RGE_Doppleganger_Object { public: char pad[0xb0]; RGE_Doppleganger_Object(int, RGE_Game_World*, int); };
class RGE_Moving_Object { public: char pad[0x180]; RGE_Moving_Object(int, RGE_Game_World*, int); };
class RGE_Missile_Object { public: char pad[0x1c8]; RGE_Missile_Object(int, RGE_Game_World*, int); };
class RGE_Action_Object { public: char pad[0x194]; RGE_Action_Object(int, RGE_Game_World*, int); };
class RGE_Combat_Object { public: char pad[0x1c4]; RGE_Combat_Object(int, RGE_Game_World*, int); };

class RGE_Object_List {
public:
    virtual void load(unsigned char type, int mode, RGE_Game_World* world);
};

void RGE_Object_List::load(unsigned char type, int mode, RGE_Game_World* world)
{
    switch (type) {
    case 10:
        new RGE_Static_Object(mode, world, 1);
        return;
    case 20:
        new RGE_Animated_Object(mode, world, 1);
        return;
    case 25:
        new RGE_Doppleganger_Object(mode, world, 1);
        return;
    case 30:
        new RGE_Moving_Object(mode, world, 1);
        return;
    case 60:
        new RGE_Missile_Object(mode, world, 1);
        return;
    case 40:
        new RGE_Action_Object(mode, world, 1);
        return;
    case 50:
        new RGE_Combat_Object(mode, world, 1);
        return;
    }
}
