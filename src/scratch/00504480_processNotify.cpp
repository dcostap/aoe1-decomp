// VA: 00504480 TribeLionUnitAIModule::processNotify(NotifyEvent*, unsigned long)
// PDB source: taiuaimd.cpp lines 375-436
// attempt 1: based on matching predator processNotify, adding 0x1FA game-mode branch; first was underspecified and optimized too small.
// attempt 2: fill scenario-editor timing branch/logging/stopObject path from original asm.
// attempt 3: put 0x1FC branch inline and 0x1FA case out-of-line like original's subtract dispatch.

#ifdef TAIUAIMD_COMPLETE_TU
extern FILE* actionFile;
#else
extern void* actionFile;
#endif
extern int fprintf(void*, const char*, ...);
extern const char str_taiuaimd_path[];
extern const char str_fmt_stopObject[];

#ifndef TAIUAIMD_COMPLETE_TU
class RGE_Static_Object;

class RGE_Game_World {
public:
    RGE_Static_Object* object(int id);
    int get_next_object_id();
};

class RGE_Player {
public:
    char gap_00[0x3C];
    RGE_Game_World* world; // +0x3C
};

class RGE_Master_Static_Object {
public:
    char gap_00[0x28];
    float range;
};

class RGE_Static_Object {
public:
    virtual void v00();
    int id;                         // +0x04
    RGE_Master_Static_Object* master_obj; // +0x08
    RGE_Player* owner;              // +0x0C
    float distance_to_object(RGE_Static_Object* other);
};

class RGE_Base_Game {
public:
    int singlePlayerGame();
    int inScenarioEditor();
};

extern RGE_Base_Game* rge_base_game;

class NotifyEvent {
public:
    char gap_00[8];
    int mType; // +8
    int param_c; // +0x0c
};

class UnitAIModule {
public:
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual void v18();
    virtual void vt07(NotifyEvent* event); // +0x1C
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2C();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3C();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4C();
    virtual void v50(); virtual void v54();
    virtual void stopObject(int a); // +0x58
    virtual void doAction(int id, int flag); // +0x5C

    RGE_Static_Object* objectValue; // +4

    void removeCurrentTarget();
    void some_00417770();
    int processNotify(NotifyEvent* event, unsigned long param_2);
};

class TribeLionUnitAIModule : public UnitAIModule {
public:
    char gap_08[0x2C];
    int field_34;
    char gap_38[0xC8];
    int field_100;

    int processNotify(NotifyEvent* event, unsigned long param_2);
};
#endif

int TribeLionUnitAIModule::processNotify(NotifyEvent* event, unsigned long param_2)
{
    switch (event->mType) {
    case 0x1FC:
    {
        RGE_Static_Object* obj = this->objectValue->owner->world->object(this->field_34);
        if (obj != 0) {
            float dist = this->objectValue->distance_to_object(obj);
#ifdef TAIUAIMD_COMPLETE_TU
            if (!(dist > *(float*)((char*)this->objectValue->master_obj + 0x28))) {
#else
            if (!(dist > this->objectValue->master_obj->range)) {
#endif
                this->doAction(this->field_34, 1);
                return 3;
            }
        }

        this->removeCurrentTarget();
        if (actionFile != 0) {
            int id;
            if (this->objectValue != 0) {
                id = this->objectValue->id;
            } else {
                id = -1;
            }
            fprintf(actionFile, str_fmt_stopObject, id, str_taiuaimd_path, 0x1AC);
        }
        this->stopObject(1);
        this->vt07(event);
    }
    break;

    case 0x1FA:
#ifdef TAIUAIMD_COMPLETE_TU
        if (*(int*)((char*)event + 0x0C) != 0x258) {
#else
        if (event->param_c != 0x258) {
#endif
            break;
        }
        if (rge_base_game->singlePlayerGame() == 1 && rge_base_game->inScenarioEditor() == 1) {
#ifdef TAIUAIMD_COMPLETE_TU
            int value = taiuaimd_world_next_object_id(this->objectValue->owner->world) + 3;
#else
            int value = this->objectValue->owner->world->get_next_object_id() + 3;
#endif
            value = value + value * 4;
            value = value + value * 4;
            value = value + value * 4;
            value = value + value * 4;
            value = value << 3;
            this->field_100 = value;
        } else {
            this->field_100 = 0x61A8;
        }
        this->some_00417770();
        this->removeCurrentTarget();
        if (actionFile != 0) {
            int id;
            if (this->objectValue != 0) {
                id = this->objectValue->id;
            } else {
                id = -1;
            }
            fprintf(actionFile, str_fmt_stopObject, id, str_taiuaimd_path, 0x191);
        }
        this->stopObject(1);
        break;
    }

    return UnitAIModule::processNotify(event, param_2);
}
