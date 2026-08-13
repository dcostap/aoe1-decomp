// VA: 005048D0 TribeRangedUnitAIModule2::processNotify
// Attempt log:
// 1: direct reconstruction from packet/decompiler, local offset stubs.
// 2: added large virtual-slot stubs for target/object virtual calls at +F4/+FC/+100 and module calls at +10/+9C; fixed GameObj/World offsets.
// 3: converted failure cases to shared fail return, but VC5 still allocates a 0x0C frame instead of original 0x08 and loop topology is broad mismatch.
// 4: tried defensive null/sentinel branches only as a diagnostic to force compare size; produced 643B but broad 92% mismatch from offset 0, rolled back because it was behavior-altering and not a valid source model.
// 5-8: combined guard, object id, same-TU UnitAIModule ABI, float coordinate fields, and natural new[]/delete[] growth restored exact call order and frame size.
// 9: outer count guard plus while (i < count) reproduced the duplicated entry test and improved shape to 90.95%; the remaining gap is register coloring and late vptr spill.
// 10: a base-pointer alias was codegen-identical and was removed as unsupported steering.
// 11: rewrote the typed evasive result tail as coordinate plus explicit negated displacement; restored the original fchs/fadd tail family, reducing the size gap to 4 bytes and positional diff to 521; first order-call hunk remains.
// 12: removed the saved object alias and used direct this->obj member calls; this restored the original vptr reload and exact 643-byte output.
// exact: direct member accesses preserve the original object/vptr reload schedule and produce all 643 bytes.

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
extern const float DAT_005758b0;
extern const float DAT_005758c4;
extern "C" double __cdecl sqrt(double);

struct NotifyEvent { char pad[8]; int type; };
struct RGE_Static_Object {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55();
    virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59(); virtual void v60(); virtual float vf_F4();
    char gap[0x34]; float x; float y;
};
struct ObjList { RGE_Static_Object* object(int); };
struct WorldWrap { char gap0[0x3c]; ObjList* objects; };
struct GameObj {
    int id;
    char gap08[4];
    WorldWrap* world;
    char pad10[0x28];
    float x;
    float y;
    float field40;
    virtual void g0(); virtual void g1(); virtual void g2(); virtual void g3(); virtual void g4(); virtual void g5(); virtual void g6(); virtual void g7();
    virtual void g8(); virtual void g9(); virtual void g10(); virtual void g11(); virtual void g12(); virtual void g13(); virtual void g14(); virtual void g15();
    virtual void g16(); virtual void g17(); virtual void g18(); virtual void g19(); virtual void g20(); virtual void g21(); virtual void g22(); virtual void g23();
    virtual void g24(); virtual void g25(); virtual void g26(); virtual void g27(); virtual void g28(); virtual void g29(); virtual void g30(); virtual void g31();
    virtual void g32(); virtual void g33(); virtual void g34(); virtual void g35(); virtual void g36(); virtual void g37(); virtual void g38(); virtual void g39();
    virtual void g40(); virtual void g41(); virtual void g42(); virtual void g43(); virtual void g44(); virtual void g45(); virtual void g46(); virtual void g47();
    virtual void g48(); virtual void g49(); virtual void g50(); virtual void g51(); virtual void g52(); virtual void g53(); virtual void g54(); virtual void g55();
    virtual void g56(); virtual void g57(); virtual void g58(); virtual void g59(); virtual void g60(); virtual void g61(); virtual void g62(); virtual float vf_FC();
    virtual float vf_100();
};

class UnitAIModule {
public:
    virtual ~UnitAIModule();
    virtual void save(int);
    virtual void load(int);
    virtual void owner();
    virtual int order(int,int,int,int,float,float,float,float,int,int,int);
    virtual void notify(int,int,int,long,long,long);
    virtual void notifyCommander(int,int,int,long,long,long);
    virtual void notifyCommander(void*);
    virtual void search();
    virtual int importantWhenDead(int);
    virtual int retryableOrder(int);
    virtual int actionRequiresLiveTarget(int);
    virtual int bestUnitToAttack(int,int,float*);
    virtual int mostDangerousEnemy(float*);
    virtual int weakestEnemy(float*);
    virtual int closestAttacker(float*);
    virtual int closestObject(int,int,int,int,int*);
    virtual int closestResourceObject(int,int*);
    virtual int closestUndiscoveredTile(int*,int*,int);
    virtual void logDebug(char*);
    virtual int canAttackUnit(void*);
    virtual int canAttackUnitAtNeutrality(int);
    virtual int stopObject(int);
    virtual int attackObject(int,int);
    virtual int attackRoundupObject(int);
    virtual int huntObject(int,int);
    virtual int gatherObject(int,int);
    virtual int convertObject(int,int);
    virtual int healObject(int,int);
    virtual int repairObject(int,int);
    virtual int buildObject(int,int);
    virtual int tradeWithObject(int,int);
    virtual int explore(int,int,int);
    virtual int enterObject(int,int);
    virtual int unload(int,float,float);
    virtual int transportObject(float,float,float,int);
    virtual int moveTo(float,float,float,float,int);
    virtual int moveTo(int,float,int);
    virtual int moveTo(int,int);
    virtual int evasiveMoveTo(float,float,float,int);
    virtual int runAwayFromAttackers(int);
    virtual int followObject(int,float,int);
    virtual int defendObject(int,float,int);
    virtual int defendPosition(float,float,float,int);
    virtual int seekAndDestroy(int,int,int,int);
    virtual int exploreAndDestroy(int,int,int);
    virtual int importantObject(int);
    virtual int convertToLOSResourceType(int);
    virtual int canConvert(int);
    virtual int processOrder(void*,int);
    int processNotify(NotifyEvent*,unsigned long);

    GameObj* obj;
    char gap08[0x24];
    int p2c;
    int state;
    int target_id;
    char gap38[4];
    float p3c, p40, p44, p48;
    char gap4c[0x14];
    int* ids;
    int count;
    char gap68[4];
    int capacity;
};

class TribeRangedUnitAIModule2 : public UnitAIModule {
public:
    int processNotify(NotifyEvent*, unsigned long);
};

int TribeRangedUnitAIModule2::processNotify(NotifyEvent* ev, unsigned long flags)
{
    RGE_Static_Object* target;
    float evasiveMoveDistance;
    float dx;
    float dy;
    float len;
    if (ev->type != 0x200) {
        return ((UnitAIModule*)this)->processNotify(ev, flags);
    }
    target = 0;
    if (this->state != 0x258 ||
        (target = this->obj->world->objects->object(this->target_id)) == 0 ||
        target->vf_F4() == DAT_005758c4)
        return 2;

    this->order(this->obj->id, 0x2bc, this->target_id, -1, this->p3c, this->p40, this->p44, this->p48, 0, 1, this->p2c);

    evasiveMoveDistance = this->obj->vf_FC() * this->obj->vf_100() * DAT_005758b0;
    dx = target->x - this->obj->x;
    dy = target->y - this->obj->y;

    if (this->count > 0) {
        int i = 0;
        while (i < this->count) {
                if (i > this->capacity - 1) {
                    int newCount = i + 1;
                    int* n = new int[newCount];
                    if (n) {
                        int j = 0;
                        if (this->capacity > 0) {
                            do {
                                if (j < newCount) {
                                    ++j;
                                    n[j-1] = this->ids[j-1];
                                } else {
                                    break;
                                }
                            } while (j < this->capacity);
                        }
                        delete[] this->ids;
                        this->ids = n;
                        this->capacity = newCount;
                    }
                }
                if (this->ids[i] != this->target_id) {
                    if (i > this->capacity - 1) {
                        int newCount = i + 1;
                        int* n = new int[newCount];
                        if (n) {
                            int j = 0;
                            if (this->capacity > 0) {
                                do {
                                    if (j < newCount) {
                                        ++j;
                                        n[j-1] = this->ids[j-1];
                                    } else {
                                        break;
                                    }
                                } while (j < this->capacity);
                            }
                            delete[] this->ids;
                            this->ids = n;
                            this->capacity = newCount;
                        }
                    }
                    RGE_Static_Object* obj2 = this->obj->world->objects->object(this->ids[i]);
                    if (obj2) {
                        dx += obj2->x - this->obj->x;
                        dy += obj2->y - this->obj->y;
                    }
                }
            ++i;
        }
    }

    len = (float)sqrt(dx*dx + dy*dy);
    this->evasiveMoveTo(this->obj->x + (-(dx / len * evasiveMoveDistance)),
                        this->obj->y + (-(dy / len * evasiveMoveDistance)),
                        this->obj->field40, 1);
    return 3;
}
