// 00461270 RGE_Master_Player::load_master_object(int,unsigned char,RGE_Sprite**,RGE_Sound**,short)
// Source: mst_play.cpp lines 132-161
// FLAGS: config/flags/00461270_load_master_object.rsp
// Attempt log:
// - Initial explicit switch/new implementation from packet/decompiler.
// - Kept /GX because original has EH registration around repeated operator new + constructors.
// - Reordered source switch cases to original physical order (10,20,30,60,40,50,25); this fixed branch distances/jump-table default target.
// - Corrected RGE_Master_Player local layout: virtual vptr plus gap[0x18] puts master_objects at +0x1C. Exact match.

#ifndef MST_PLAY_SHARED_CONTEXT
void* __cdecl operator new(unsigned int size);
class RGE_Sprite; class RGE_Sound;
class RGE_Master_Static_Object { public: char pad[0xB8]; RGE_Master_Static_Object(int, RGE_Sprite**, RGE_Sound**, int); };
class RGE_Master_Animated_Object : public RGE_Master_Static_Object { public: char pad2[4]; RGE_Master_Animated_Object(int, RGE_Sprite**, RGE_Sound**, int); };
class RGE_Master_Moving_Object : public RGE_Master_Static_Object { public: char pad3[0x20]; RGE_Master_Moving_Object(int, RGE_Sprite**, RGE_Sound**, int); };
class RGE_Master_Missile_Object : public RGE_Master_Static_Object { public: char pad4[0x9C]; RGE_Master_Missile_Object(int, RGE_Sprite**, RGE_Sound**, int); };
class RGE_Master_Action_Object : public RGE_Master_Static_Object { public: char pad5[0x44]; RGE_Master_Action_Object(int, RGE_Sprite**, RGE_Sound**, int); };
class RGE_Master_Combat_Object : public RGE_Master_Static_Object { public: char pad6[0x90]; RGE_Master_Combat_Object(int, RGE_Sprite**, RGE_Sound**, int); };
class RGE_Master_Doppleganger_Object : public RGE_Master_Static_Object { public: char pad7[4]; RGE_Master_Doppleganger_Object(int, RGE_Sprite**, RGE_Sound**, int); };

class RGE_Master_Player {
public:
    char gap[0x18];
    RGE_Master_Static_Object** master_objects;
    virtual void load_master_object(int id, unsigned char type, RGE_Sprite** sprites, RGE_Sound** sounds, short index);
};
#endif

void RGE_Master_Player::load_master_object(int id, unsigned char type, RGE_Sprite** sprites, RGE_Sound** sounds, short index)
{
    RGE_Master_Static_Object* obj;
    switch (type) {
    case 10:
        obj = new RGE_Master_Static_Object(id, sprites, sounds, 1);
        break;
    case 20:
        obj = new RGE_Master_Animated_Object(id, sprites, sounds, 1);
        this->master_objects[index] = obj;
        return;
    case 30:
        obj = new RGE_Master_Moving_Object(id, sprites, sounds, 1);
        break;
    case 60:
        obj = new RGE_Master_Missile_Object(id, sprites, sounds, 1);
        this->master_objects[index] = obj;
        return;
    case 40:
        obj = new RGE_Master_Action_Object(id, sprites, sounds, 1);
        break;
    case 50:
        obj = new RGE_Master_Combat_Object(id, sprites, sounds, 1);
        this->master_objects[index] = obj;
        return;
    case 25:
        obj = new RGE_Master_Doppleganger_Object(id, sprites, sounds, 1);
        break;
    default:
        return;
    }
    this->master_objects[index] = obj;
}
