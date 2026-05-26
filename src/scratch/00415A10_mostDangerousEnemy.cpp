// VA: 00415A10 UnitAIModule::mostDangerousEnemy
// aiuaimod.cpp
// Retry 2026-05-26: rebuilt full behavior with lookupObject, objectValue virtual threat calls, FPU compare, and outThreat store.
// Best result: exact size 188B, MISMATCH 73 positional / 20 edit bytes, first mismatch +40.
// Tried 10 variants: nested virtual call vs temp float, explicit actionObj local, owner local, master local order, threat2 short vs int,
// direct global id expression vs id temp, idx temp for best update, objectValue direct reload vs saved local, and loop/source order changes.
// Left in scratch: remaining drift is localized codegen/register coloring and one-byte branch-distance shifts in the per-object threat block:
// rebuilt keeps master in EDI and vtable in EBX while original keeps master in EBX and vtable in EDI; update block loads global/index in
// opposite order. Behavior/calls/stack cleanup/FPU compare look equivalent, but not proposing accepted_drift because drift spans register
// allocation throughout the central virtual-call block rather than a tiny isolated encoding difference.

class RGE_Master_Static_Object {
public:
    char gap_000[0x108];
    short field_108;
    char gap_10A[2];
    int field_10C;
};

class RGE_Static_Object {
public:
    char gap_00[8];
    RGE_Master_Static_Object* master_obj;
    void* owner;
};

class RGE_Action_Object {
public:
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1C();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2C();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3C();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4C();
    virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5C();
    virtual void v60(); virtual void v64(); virtual void v68(); virtual void v6C();
    virtual void v70();
    virtual float threat2(int a, int b, float c); // +0x74
    virtual void v78(); virtual void v7C(); virtual void v80(); virtual void v84();
    virtual void v88(); virtual void v8C(); virtual void v90(); virtual void v94();
    virtual void v98(); virtual void v9C(); virtual void vA0(); virtual void vA4();
    virtual void vA8(); virtual void vAC(); virtual void vB0(); virtual void vB4();
    virtual void vB8(); virtual void vBC(); virtual void vC0(); virtual void vC4();
    virtual void vC8(); virtual void vCC(); virtual void vD0(); virtual void vD4();
    virtual void vD8(); virtual void vDC(); virtual void vE0(); virtual void vE4();
    virtual void vE8(); virtual void vEC();
    virtual float threat1(RGE_Static_Object* a, void* owner, RGE_Static_Object* b); // +0xF0
};

class UnitAIModule {
public:
    virtual ~UnitAIModule();
    virtual void v04(); virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1C();
    virtual void preMostDangerous(); // +0x20

    RGE_Action_Object* objectValue;

    RGE_Static_Object* lookupObject(int id);
    int mostDangerousEnemy(float* outThreat);
};

int UnitAIModule::mostDangerousEnemy(float* outThreat) {
    preMostDangerous();

    int best = -1;
    float bestThreat = 0.0f;
    int i = 0;
    if (*(int*)0x87D7D8 > 0) {
        do {
            RGE_Static_Object* obj = lookupObject(*(int*)(*(int*)0x87D7F0 + i * 8));
            if (obj) {
                void* owner = obj->owner;
                RGE_Master_Static_Object* master = obj->master_obj;
                float f = objectValue->threat2(master->field_108, master->field_10C,
                    objectValue->threat1(obj, owner, obj));
                if (best == -1 || f > bestThreat) {
                    bestThreat = f;
                    int idx = i;
                    best = *(int*)(*(int*)0x87D7F0 + idx * 8);
                }
            }
            i++;
        } while (i < *(int*)0x87D7D8);
    }

    if (outThreat) {
        *outThreat = bestThreat;
    }
    return best;
}
