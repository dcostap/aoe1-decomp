// 00461560 RGE_Master_Player::load_object(_iobuf*, unsigned char, RGE_Sprite**, RGE_Sound**, short)
// Source: mst_play.cpp lines 176-205
// FLAGS: config/flags/00461560_load_object.rsp
// Attempt log:
// - Initial implementation mirrored from matched 00461270 load_master_object, adjusted for file-loading constructors.
// - Kept /GX because original has EH registration around repeated operator new + constructors.
// - Used original physical switch body order (10,20,30,60,40,50,25) and RGE_Master_Player vptr+gap[0x18] layout so master_objects is +0x1C. Exact match.

void* __cdecl operator new(unsigned int size);
struct _iobuf; class RGE_Sprite; class RGE_Sound;
class RGE_Master_Static_Object { public: char pad[0xB8]; RGE_Master_Static_Object(_iobuf*, RGE_Sprite**, RGE_Sound**, short, int); };
class RGE_Master_Animated_Object : public RGE_Master_Static_Object { public: char pad2[4]; RGE_Master_Animated_Object(_iobuf*, RGE_Sprite**, RGE_Sound**, short, int); };
class RGE_Master_Moving_Object : public RGE_Master_Static_Object { public: char pad3[0x20]; RGE_Master_Moving_Object(_iobuf*, RGE_Sprite**, RGE_Sound**, short, int); };
class RGE_Master_Missile_Object : public RGE_Master_Static_Object { public: char pad4[0x9C]; RGE_Master_Missile_Object(_iobuf*, RGE_Sprite**, RGE_Sound**, short, int); };
class RGE_Master_Action_Object : public RGE_Master_Static_Object { public: char pad5[0x44]; RGE_Master_Action_Object(_iobuf*, RGE_Sprite**, RGE_Sound**, short, int); };
class RGE_Master_Combat_Object : public RGE_Master_Static_Object { public: char pad6[0x90]; RGE_Master_Combat_Object(_iobuf*, RGE_Sprite**, RGE_Sound**, short, int); };
class RGE_Master_Doppleganger_Object : public RGE_Master_Static_Object { public: char pad7[4]; RGE_Master_Doppleganger_Object(_iobuf*, RGE_Sprite**, RGE_Sound**, short, int); };

class RGE_Master_Player {
public:
    char gap[0x18];
    RGE_Master_Static_Object** master_objects;
    virtual void load_object(_iobuf* file, unsigned char type, RGE_Sprite** sprites, RGE_Sound** sounds, short index);
};

void RGE_Master_Player::load_object(_iobuf* file, unsigned char type, RGE_Sprite** sprites, RGE_Sound** sounds, short index)
{
    RGE_Master_Static_Object* obj;
    switch (type) {
    case 10:
        obj = new RGE_Master_Static_Object(file, sprites, sounds, index, 1);
        break;
    case 20:
        obj = new RGE_Master_Animated_Object(file, sprites, sounds, index, 1);
        this->master_objects[index] = obj;
        return;
    case 30:
        obj = new RGE_Master_Moving_Object(file, sprites, sounds, index, 1);
        break;
    case 60:
        obj = new RGE_Master_Missile_Object(file, sprites, sounds, index, 1);
        this->master_objects[index] = obj;
        return;
    case 40:
        obj = new RGE_Master_Action_Object(file, sprites, sounds, index, 1);
        break;
    case 50:
        obj = new RGE_Master_Combat_Object(file, sprites, sounds, index, 1);
        this->master_objects[index] = obj;
        return;
    case 25:
        obj = new RGE_Master_Doppleganger_Object(file, sprites, sounds, index, 1);
        break;
    default:
        return;
    }
    this->master_objects[index] = obj;
}
