// VA: 005048D0 TribeRangedUnitAIModule2::processNotify
// Attempt log:
// 1: direct reconstruction from packet/decompiler, local offset stubs.
// 2: added large virtual-slot stubs for target/object virtual calls at +F4/+FC/+100 and module calls at +10/+9C; fixed GameObj/World offsets.
// 3: converted failure cases to shared fail return, but VC5 still allocates a 0x0C frame instead of original 0x08 and loop topology is broad mismatch.
// 4: tried defensive null/sentinel branches only as a diagnostic to force compare size; produced 643B but broad 92% mismatch from offset 0, rolled back because it was behavior-altering and not a valid source model.
// left in scratch: current honest source compiles to 640B (configured/original 643B, check_function stops before compare). Best diagnostic compare with forced-size branch showed broad mismatch; honest rebuilt already has wrong 0x0C frame (original 0x08), early shared-fail layout differs, and array-growth loop topology/register allocation diverges substantially. Not accepted_drift-safe.

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
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
    char pad4[8];
    WorldWrap* world;
    char pad10[0x28];
    float x;
    float y;
    int field40;
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

class UnitAIModule { public: int processNotify(NotifyEvent*, unsigned long); };

class TribeRangedUnitAIModule2 {
public:
    GameObj* obj;
    char gap08[0x24];
    int p2c;
    int state;
    int target_id;
    char gap38[4];
    int p3c, p40, p44, p48;
    char gap4c[0x14];
    int* ids;
    int count;
    char gap68[4];
    int capacity;
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual int vf10(int,int,int,int,int,int,int,int,int,int,int);
    virtual void m5(); virtual void m6(); virtual void m7(); virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11(); virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19(); virtual void m20(); virtual void m21(); virtual void m22(); virtual void m23(); virtual void m24(); virtual void m25(); virtual void m26(); virtual void m27(); virtual void m28(); virtual void m29(); virtual void m30(); virtual void m31(); virtual void m32(); virtual void m33(); virtual void m34(); virtual void m35(); virtual void m36(); virtual void m37(); virtual void m38();
    virtual void vf9c(float,float,TribeRangedUnitAIModule2*,int,int);
    int processNotify(NotifyEvent*, unsigned long);
};

int TribeRangedUnitAIModule2::processNotify(NotifyEvent* ev, unsigned long flags)
{
    RGE_Static_Object* target;
    GameObj* o;
    float evasiveMoveDistance;
    float dx;
    float dy;
    float len;
    if (ev->type != 0x200) {
        return ((UnitAIModule*)this)->processNotify(ev, flags);
    }
    if (this->state != 0x258) goto fail;

    target = this->obj->world->objects->object(this->target_id);
    if (!target) goto fail;
    if (target->vf_F4() == *(float*)0x005758C4) goto fail;

    this->vf10(this->obj->field40, 0x2bc, this->target_id, -1, this->p3c, this->p40, this->p44, this->p48, 0, 1, this->p2c);

    o = this->obj;
    evasiveMoveDistance = o->vf_100() * o->vf_FC() * *(float*)0x005758B0;
    dx = target->x - o->x;
    dy = target->y - o->y;

    if (this->count > 0) {
        int i = 0;
        if (this->count > 0) {
            do {
                if (i > this->capacity - 1) {
                    int newCount = i + 1;
                    int* n = (int*)operator new(newCount * 4);
                    if (n) {
                        int j = 0;
                        if (this->capacity > 0) {
                            while (j < newCount && j < this->capacity) {
                                ++j;
                                n[j-1] = this->ids[j-1];
                            }
                        }
                        operator delete(this->ids);
                        this->ids = n;
                        this->capacity = newCount;
                    }
                }
                if (this->ids[i] != this->target_id) {
                    if (i > this->capacity - 1) {
                        int newCount = i + 1;
                        int* n = (int*)operator new(newCount * 4);
                        if (n) {
                            int j = 0;
                            if (this->capacity > 0) {
                                while (j < newCount && j < this->capacity) {
                                    ++j;
                                    n[j-1] = this->ids[j-1];
                                }
                            }
                            operator delete(this->ids);
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
            } while (i < this->count);
        }
    }

    len = (float)sqrt(dx*dx + dy*dy);
    this->vf9c(this->obj->x - dx / len * evasiveMoveDistance,
               this->obj->y - dy / len * evasiveMoveDistance,
               this, this->obj->field40, 1);
    return 3;
fail:
    return 2;
}
