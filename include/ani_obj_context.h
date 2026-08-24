#ifndef ANI_OBJ_CONTEXT_H
#define ANI_OBJ_CONTEXT_H

class RGE_Sprite;
class RGE_Master_Static_Object;
class RGE_Master_Animated_Object;
class RGE_Player;
class RGE_Game_World;
class TDrawArea;
class RGE_Color_Table;
class RGE_Action_Object;

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
    RGE_Static_Object(RGE_Master_Static_Object*, RGE_Player*, float, float, float, int);
    RGE_Static_Object(int, RGE_Game_World*, int);

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
    virtual void set_being_worked_on(RGE_Action_Object*, short, unsigned char);
    virtual void release_being_worked_on(RGE_Static_Object*);

    long id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    RGE_Sprite* sprite;
    void* old_sprite;
    RGE_Active_Sprite_List* sprite_list;
    char gap_1C[0x2C];
    unsigned char object_state;
    char gap_49[3];
    short attribute_type_held;
    unsigned char type;
    unsigned char worker_num;
    char gap_50[0x38];

    int setup(RGE_Master_Static_Object*, RGE_Player*, float, float, float);
    int setup(int, RGE_Game_World*);
    void set_sleep_flag(unsigned char);
};

class RGE_Animated_Object : public RGE_Static_Object {
public:
    RGE_Animated_Object(RGE_Master_Animated_Object*, RGE_Player*, float, float, float, int);
    RGE_Animated_Object(int, RGE_Game_World*, int);

protected:
    virtual int setup(RGE_Master_Animated_Object*, RGE_Player*, float, float, float);
    virtual int setup(int, RGE_Game_World*);

public:
    virtual void recycle_in_to_game(RGE_Master_Static_Object*, RGE_Player*, float, float, float);
    virtual unsigned char update();
    virtual void save(int);
    virtual void transform(RGE_Master_Static_Object*);
    virtual void set_being_worked_on(RGE_Action_Object*, short, unsigned char);
    virtual void release_being_worked_on(RGE_Static_Object*);

    float speed;
};

extern "C" void __cdecl rge_read(int file, void* data, int size);
extern "C" void __cdecl rge_write(int handle, void* buffer, int size);

#endif
