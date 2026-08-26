// VA: 00512A90 TRIBE_Player::load_master_object
// Natural new-expression /GX shape from tplayer.cpp packet.
// FLAGS: config/flags/00512A90_load_master_object.rsp

class RGE_Sprite;
class RGE_Sound;
class RGE_Master_Static_Object;

#ifndef AOE1_TPLAYER_TU_SHARED_CONTEXT
class RGE_Player {
public:
    virtual ~RGE_Player();
    void load_master_object(int param_1, short index, unsigned char type, RGE_Sprite** sprites, RGE_Sound** sounds);
};

class TRIBE_Master_Fish_Object {
public:
    char pad[0x164];
    TRIBE_Master_Fish_Object(int param_1, RGE_Sprite** sprites, RGE_Sound** sounds, int flag);
};

class TRIBE_Master_Projectile_Object {
public:
    char pad[0x17C];
    TRIBE_Master_Projectile_Object(int param_1, RGE_Sprite** sprites, RGE_Sound** sounds, int flag);
};

class TRIBE_Master_Tree_Object {
public:
    char pad[0xB8];
    TRIBE_Master_Tree_Object(int param_1, RGE_Sprite** sprites, RGE_Sound** sounds, int flag);
};

class TRIBE_Player : public RGE_Player {
public:
    char pad_04[0x24 - 4];
    void** master_objects;

    void load_master_object(int param_1, short index, unsigned char type, RGE_Sprite** sprites, RGE_Sound** sounds);
};
#endif

void TRIBE_Player::load_master_object(int param_1, short index, unsigned char type, RGE_Sprite** sprites, RGE_Sound** sounds) {
    void* obj;

    switch (type) {
    case 'F':
        obj = new TRIBE_Master_Fish_Object(param_1, sprites, sounds, 1);
        break;
    case 'P':
        obj = new TRIBE_Master_Projectile_Object(param_1, sprites, sounds, 1);
        master_objects[index] = (RGE_Master_Static_Object*)obj;
        return;
    case 'Z':
        obj = new TRIBE_Master_Tree_Object(param_1, sprites, sounds, 1);
        break;
    default:
        RGE_Player::load_master_object(param_1, index, type, sprites, sounds);
        return;
    }
    master_objects[index] = (RGE_Master_Static_Object*)obj;
}
