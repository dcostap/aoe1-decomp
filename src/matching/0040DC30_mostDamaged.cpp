// attempt 1: natural loop over tracked object ids, growing id array and selecting highest damage percentage

void* operator new(unsigned int);
void operator delete(void*);

#ifndef AOE1_AIMDMOD_TU_CONTEXT_H
class RGE_Static_Object;
class RGE_Static_Object_Type { public: char gap_00[0x10]; short type_id; char gap_12[2]; short class_id; char gap_16[0x10]; short max_hp; };
class RGE_Game_World { public: RGE_Static_Object* object(long id); };
class GameShell { public: char gap_00[0x3C]; RGE_Game_World* world; };
class UnitAIModule {};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game(void*, void*, float, float, float);
    virtual void recycle_out_of_game();
    virtual void draw(void*, short, short, void*);
    virtual void shadow_draw(void*, short, short, unsigned char);
    virtual void normal_draw(void*, short, short);
    virtual void draw_front_frame(void*, short, short);
    virtual void draw_back_frame(void*, short, short);
    virtual void draw_frame(void*, short, short);
    virtual unsigned char update();
    virtual void check_damage_sprites();
    virtual void rehook();
    virtual void save(int);
    virtual float teleport(float, float, float);
    virtual void new_sprite(void*);
    virtual void add_overlay_sprite(void*, unsigned char);
    virtual void remove_overlay_sprite(void*);
    virtual void change_ownership(void*);
    virtual void modify(float, unsigned char);
    virtual void modify_delta(float, unsigned char);
    virtual void modify_percent(float, unsigned char);
    virtual void transform(void*);
    virtual void copy_obj(void*);
    virtual void set_object_state(unsigned char);
    virtual void remove_visible_resource();
    virtual void create_doppleganger_when_dying();
    virtual void destroy_obj();
    virtual void die_die_die();
    virtual void damage(int, void*, float, void*, RGE_Static_Object* = 0);
    virtual float calculateDamage(int, void*, float, void*, RGE_Static_Object* = 0);
    virtual void rotate(long);
    virtual unsigned char can_attack();
    virtual void set_attribute(short, float);
    virtual void set_attribute_amount(float, unsigned char, unsigned char);
    virtual int heal(int, int);
    virtual unsigned char heal(float);
    virtual int canRepair();
    char gap_004[4];
    RGE_Static_Object_Type* type;
    char gap_00C[0x30-0x0C];
    float hit_points;
    char gap_034[0x48-0x34];
    unsigned char object_state;
    UnitAIModule* unitAI();
};

class MainDecisionAIModule {
public:
    char gap_000[0xF0];
    GameShell* game;
    long* object_ids;
    long object_count;
    char gap_0FC[4];
    long object_capacity;
    RGE_Static_Object* mostDamaged(int class_id, int type_id);
};
#endif

RGE_Static_Object* MainDecisionAIModule::mostDamaged(int class_id, int type_id) {
    RGE_Static_Object* mDB = 0;
    int damagePercentage = 0;
    int i = 0;
    if (this->object_count > 0) {
        do {
            if (i > this->object_capacity - 1) {
                int newCapacity = i + 1;
                long* newIds = (long*)operator new(newCapacity * 4);
                if (newIds) {
                    int j = 0;
                    while (j < this->object_capacity && j < newCapacity) {
                        newIds[j] = this->object_ids[j];
                        ++j;
                    }
                    operator delete(this->object_ids);
                    this->object_ids = newIds;
                    this->object_capacity = newCapacity;
                }
            }
            RGE_Static_Object* obj = this->game->world->object(this->object_ids[i]);
            if (obj && obj->unitAI() && obj->object_state) {
                RGE_Static_Object_Type* type = obj->type;
                if ((int)type->class_id == class_id) {
                    int maxhp = type->max_hp;
                    if ((float)maxhp > obj->hit_points && obj->canRepair() == 1) {
                        if (type_id == -1 || type_id == (int)obj->type->type_id) {
                            int hp = obj->type->max_hp;
                            int pct = ((long)((float)hp - obj->hit_points) * 100) / hp;
                    if (pct > damagePercentage) {
                                mDB = obj;
                                damagePercentage = pct;
                            }
                        }
                    }
                }
            }
            ++i;
        } while (i < this->object_count);
    }
    return mDB;
}
