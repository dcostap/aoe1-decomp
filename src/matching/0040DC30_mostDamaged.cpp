// attempt 1: natural loop over tracked object ids, growing id array and selecting highest damage percentage

void* operator new(unsigned int);
void operator delete(void*);

class RGE_Static_Object;
class RGE_Static_Object_Type { public: char gap_00[0x10]; short type_id; char gap_12[2]; short class_id; char gap_16[0x10]; short max_hp; };
class RGE_Game_World { public: RGE_Static_Object* object(long id); };
class GameShell { public: char gap_00[0x3C]; RGE_Game_World* world; };
class UnitAIModule {};

class RGE_Static_Object {
public:
    virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0C();
    virtual void vf10(); virtual void vf14(); virtual void vf18(); virtual void vf1C();
    virtual void vf20(); virtual void vf24(); virtual void vf28(); virtual void vf2C();
    virtual void vf30(); virtual void vf34(); virtual void vf38(); virtual void vf3C();
    virtual void vf40(); virtual void vf44(); virtual void vf48(); virtual void vf4C();
    virtual void vf50(); virtual void vf54(); virtual void vf58(); virtual void vf5C();
    virtual void vf60(); virtual void vf64(); virtual void vf68(); virtual void vf6C();
    virtual void vf70(); virtual void vf74(); virtual void vf78(); virtual void vf7C();
    virtual void vf80(); virtual void vf84(); virtual void vf88(); virtual void vf8C();
    virtual long vf90();
    char gap_004[4];
    RGE_Static_Object_Type* type;
    char gap_00C[0x30-0x0C];
    float hit_points;
    char gap_034[0x48-0x34];
    unsigned char alive;
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
            if (obj && obj->unitAI() && obj->alive) {
                RGE_Static_Object_Type* type = obj->type;
                if ((int)type->class_id == class_id) {
                    int maxhp = type->max_hp;
                    if ((float)maxhp > obj->hit_points && obj->vf90() == 1) {
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
