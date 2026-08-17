// STATUS: ACTIVE
// NOTE: reconstruct typed base-save and rge_write calls without inline assembly
// Exact reconstruction: copy the handle before reusing the parameter home for
// the short sprite ID. VC5 then preserves the original partial-register stores.

class RGE_Sprite {
public:
    char gap_00[0x72];
    short id;
};

class RGE_Action {
public:
    virtual ~RGE_Action();
    virtual int setup(void* object);
    virtual int setup(int type, void* object);
    virtual void* create_action_list(void* object);
    virtual void rehook();
    virtual void save(int param_1);
    virtual short action_id(void);
    virtual void first_in_stack(unsigned char value);
    virtual unsigned char inside_obj_update();
    virtual unsigned char idle_update();
    virtual unsigned char update();
    virtual int stop();
    virtual int move_to(void* target, float x, float y, float z);
    virtual int work(void* target, float x, float y, float z);
    virtual unsigned char attack_response(void* target);
    virtual unsigned char relation_response(long player, unsigned char relation);
    virtual void copy_obj(void* object);
    virtual void copy_obj_sprites(void* master, void* first, void* second);
    virtual void get_state_name(char* name);
    virtual void* get_target_obj(void);
    virtual void* get_target_obj2(void);
    virtual void set_target_obj(void* object);
    virtual void set_target_obj2(void* object);
    virtual void set_state(unsigned char state);

    char gap_04[0x3C];
};

void rge_write(int param_1, void* param_2, int param_3);

class RGE_Action_Attack : public RGE_Action {
public:
    RGE_Sprite* move_sprite;
    RGE_Sprite* fight_sprite;
    RGE_Sprite* wait_sprite;
    float range;
    float min_range;
    short missile_id;
    short fire_missile_at_frame;
    unsigned char need_to_attack;
    unsigned char was_same_owner;
    unsigned char indirect_fire_flag;

    void save(int param_1);
};

void RGE_Action_Attack::save(int param_1) {
    int handle = param_1;
    short sprite_id;

    RGE_Action::save(param_1);
    rge_write(handle, &this->range, 4);
    rge_write(handle, &this->min_range, 4);
    rge_write(handle, &this->missile_id, 2);
    rge_write(handle, &this->fire_missile_at_frame, 2);
    rge_write(handle, &this->need_to_attack, 1);
    rge_write(handle, &this->was_same_owner, 1);
    rge_write(handle, &this->indirect_fire_flag, 1);

    if (this->move_sprite != 0) {
        sprite_id = this->move_sprite->id;
    } else {
        sprite_id = -1;
    }
    rge_write(handle, &sprite_id, 2);

    if (this->fight_sprite != 0) {
        sprite_id = this->fight_sprite->id;
    } else {
        sprite_id = -1;
    }
    rge_write(handle, &sprite_id, 2);

    if (this->wait_sprite != 0) {
        sprite_id = this->wait_sprite->id;
    } else {
        sprite_id = -1;
    }
    rge_write(handle, &sprite_id, 2);
}
