// VA: 0041A350 RGE_Animated_Object::update
// ani_obj.cpp lines 79-125
// BINARY NOTE: PDB names this public virtual method. Its body is 0041A350-0041A3C6;
// RGE_Animated_Object::setup at 0041A310 ends before this body.
// BINARY NOTE: The +0x18 field is RGE_Active_Sprite_List. Its calls use
// is_animating at +0x18 and update at +0x08. The +0x5C calls are the inherited
// public RGE_Static_Object::set_object_state method.
// BINARY NOTE: State 3 reads master_obj->death_sprite before the state call.
// State 4 publishes state 5 and clears speed only after is_animating returns 0.

class RGE_Sprite;
class RGE_Master_Static_Object;
class RGE_Player;
class RGE_Game_World;
class TDrawArea;
class RGE_Color_Table;

class RGE_Active_Sprite_List {
public:
    virtual ~RGE_Active_Sprite_List();
    virtual short frame(RGE_Sprite* sprite);
    virtual void update(float time_delta, float speed);
    virtual void draw(short, short, short, short, short, RGE_Color_Table*, TDrawArea*);
    virtual void normal_draw(short, short, short, RGE_Color_Table*, TDrawArea*);
    virtual void shadow_draw(short, short, short, RGE_Color_Table*, TDrawArea*, unsigned char);
    virtual unsigned char is_animating(RGE_Sprite* sprite);
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    char gap_04[0x80];
    float world_time_delta_seconds;
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x38];
    RGE_Game_World* world;
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    char gap_04[0x18];
    RGE_Sprite* death_sprite;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game(RGE_Master_Static_Object*, RGE_Player*, float, float, float);
    virtual void recycle_out_of_game();
    virtual void draw(TDrawArea*, short, short, RGE_Color_Table*);
    virtual void shadow_draw(TDrawArea*, short, short, unsigned char);
    virtual void normal_draw(TDrawArea*, short, short);
    virtual void draw_front_frame(TDrawArea*, short, short);
    virtual void draw_back_frame(TDrawArea*, short, short);
    virtual void draw_frame(TDrawArea*, short, short);
    virtual unsigned char update();
    virtual void check_damage_sprites();
    virtual void rehook();
    virtual void save(int);
    virtual float teleport(float, float, float);
    virtual void new_sprite(RGE_Sprite*);
    virtual void add_overlay_sprite(RGE_Sprite*, unsigned char);
    virtual void remove_overlay_sprite(RGE_Sprite*);
    virtual void change_ownership(RGE_Player*);
    virtual void modify(float, unsigned char);
    virtual void modify_delta(float, unsigned char);
    virtual void modify_percent(float, unsigned char);
    virtual void transform(RGE_Master_Static_Object*);
    virtual void copy_obj(RGE_Master_Static_Object*);
    virtual void set_object_state(unsigned char);

    long id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    RGE_Sprite* sprite;
    void* old_sprite;
    RGE_Active_Sprite_List* sprite_list;
    char gap_1C[0x2C];
    unsigned char object_state;
    char gap_49[0x3F];
};

class RGE_Animated_Object : public RGE_Static_Object {
public:
    float speed;

    virtual unsigned char update();
};

// 0041A350 - 119 bytes
unsigned char RGE_Animated_Object::update() {
    unsigned char result = RGE_Static_Object::update();

    unsigned char state = this->object_state;

    switch (state) {
    case 3: {
        RGE_Master_Static_Object* master = this->master_obj;
        if (master->death_sprite == 0) {
            this->set_object_state(5);
        } else {
            this->set_object_state(4);
        }
        break;
    }
    case 4: {
        unsigned char ret = this->sprite_list->is_animating(this->sprite);
        if (ret == 0) {
            this->object_state = 5;
            this->speed = 0.0f;
        }
        break;
    }
    }

    RGE_Game_World* world = this->owner->world;
    this->sprite_list->update(world->world_time_delta_seconds, this->speed);

    return result;
}
