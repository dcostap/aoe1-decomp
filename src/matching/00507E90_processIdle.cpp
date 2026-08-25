#ifndef TAIUAIMD_COMPLETE_TU
class RGE_Static_Object;
class RGE_Game_World;

extern int numberDifferentPlayerObjectsVisible;

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_00[0x3C];
    RGE_Game_World* world;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game();
    virtual void recycle_out_of_game();
    virtual void draw();
    virtual void shadow_draw();
    virtual void normal_draw();
    virtual void draw_front_frame();
    virtual void draw_back_frame();
    virtual void draw_frame();
    virtual unsigned char update();
    virtual void check_damage_sprites();
    virtual void rehook();
    virtual void save(int);
    virtual float teleport(float, float, float);
    virtual void new_sprite();
    virtual void add_overlay_sprite();
    virtual void remove_overlay_sprite();
    virtual void change_ownership(RGE_Player*);
    char gap_04[0x8];
    RGE_Player* owner;
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    RGE_Static_Object* object(int);
};

class UnitAIModule {
public:
    virtual ~UnitAIModule();
    virtual void save(int);
    virtual void load(int);
    virtual RGE_Player* owner();
    virtual int order(int, int, int, int, float, float, float, float, int, int, int);
    virtual int notify(int, int, int, long, long, long);
    virtual int notifyCommander(int, int, int, long, long, long);
    virtual int notifyCommander(void*);
    virtual void search();
    virtual int importantWhenDead(int);
    virtual int retryableOrder(int);
    virtual int actionRequiresLiveTarget(int);
    virtual int bestUnitToAttack(int, int, float*);
    virtual int mostDangerousEnemy(float*);
    virtual int weakestEnemy(float*);
    virtual int closestAttacker(float*);
    virtual int closestObject(int, int, int, int, int*);
    RGE_Static_Object* objectValue;
};

class TribeArtifactUnitAIModule : public UnitAIModule {
public:
    virtual int processIdle(int);
};
#endif

int TribeArtifactUnitAIModule::processIdle(int param_1) {
    int iVar1;
    RGE_Static_Object *pRVar2;

    iVar1 = this->closestObject(-1, -1, -1, -1, 0);
    if ((numberDifferentPlayerObjectsVisible <= 1) && (iVar1 != -1)) {
        pRVar2 = this->objectValue->owner->world->object(iVar1);
        if (pRVar2 != 0) {
            if (this->objectValue->owner != pRVar2->owner) {
                this->objectValue->change_ownership(pRVar2->owner);
                return 6;
            }
        }
    }
    return 5;
}
