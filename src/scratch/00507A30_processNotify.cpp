// VA: 00507A30 TribeArtifactUnitAIModule::processNotify
// Attempt log:
// try 1: reconstruct broad switch from packet and sibling processNotify matches; initial source compiled too small (640B), showing broad missing inline logging/repeated bodies.
// try 2: inlined repeated actionFile/fprintf stop logging instead of a local helper; size improved to 800B but still short.
// try 3: temporary padding branch got a byte-compare (79.1274% positional / 98.2311% edit) and proved the family is still very broad: prologue loads event into EBP instead of original EBX, switch compiles as sparse compares instead of original dense jump-table, and case layout/tails differ widely. Removed the padding branch.
// GIVEUP: behavior is only approximate. Remaining blockers are exact notify type set/jump-table density, event field roles, ArtifactUnit module field semantics, list growth condition/copy loop shape, and shared logging/stop tail source form. No inline asm used; not accepted_drift quality.

extern void* actionFile;
extern int fprintf(void*, const char*, ...);
extern const char str_taiuaimd_path[];
extern const char str_fmt_stopObject[];
extern void* malloc(unsigned int);
extern void free(void*);

class RGE_Visible_Map;
class RGE_Player { public: char gap_00[0x38]; RGE_Visible_Map* visible_map; };
class RGE_Static_Object { public: virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c(); virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c(); virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c(); virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c(); virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4c(); virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5c(); virtual void v60(); virtual void v64(); virtual void v68(); virtual void v6c(); virtual void v70(); virtual void v74(); virtual void v78(); virtual void v7c(); virtual void v80(); virtual void v84(); virtual void v88(); virtual void v8c(); virtual void v90(); virtual void v94(); virtual void v98(); virtual void v9c(); virtual void va0(); virtual void va4(); virtual void va8(); virtual void vac(); virtual void vb0(); virtual void vb4(); virtual void vb8(); virtual void vbc(); virtual void vc0(); virtual void vc4(); virtual void vc8(); virtual void vcc(); virtual void vd0(); virtual void vd4(); virtual void vd8(); virtual void vdc(); virtual void ve0(); virtual void ve4(); virtual void ve8(int); int id; char gap08[4]; RGE_Player* owner; char gap10[0x28]; float x; float y; };
class NotifyEvent { public: int objectId; char gap04[4]; int mType; int value; };

class UnitAIModule {
public:
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual void v18();
    virtual void vt1c(NotifyEvent* event);
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2C();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3C();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4C();
    virtual void v50(); virtual void v54();
    virtual void stopObject(int arg); // +58
    virtual void v5c(); virtual void v60(); virtual void v64(); virtual void v68();
    virtual void v6c(); virtual void v70(); virtual void v74(); virtual void v78();
    virtual void v7c(); virtual void v80(); virtual void v84(); virtual void v88();
    virtual void v8c(); virtual void v90(); virtual void v94(); virtual void v98();
    virtual void v9c(); virtual void va0(); virtual void va4(); virtual void va8();
    virtual void vac(); virtual void vb0(); virtual void vb4(); virtual void vb8();
    virtual void vbc(); virtual void vc0(); virtual void vc4(); virtual void vc8();
    virtual void vcc(); virtual void vd0(); virtual void vd4(); virtual void vd8();
    virtual void vdc(); virtual void ve0(); virtual void ve4(); virtual int vte8(int);
    virtual void vtec(int);

    RGE_Static_Object* objectValue; // +4
    void removeCurrentTarget();
    RGE_Static_Object* lookupObject(int objectId);
    unsigned char visibleStatus(RGE_Visible_Map* map, int x, int y);
    int processNotify(NotifyEvent* event, unsigned long flags);
};

class TribeArtifactUnitAIModule : public UnitAIModule {
public:
    char gap08[0x20];
    int field_28;
    char gap2c[4];
    int field_30;
    int targetId; // +34
    char gap38[0x28];
    int* ids;     // +60
    int count;    // +64
    char gap68[4];
    int capacity; // +6c

    int processNotify(NotifyEvent* event, unsigned long flags);
};

#define LOGSTOP(line) do { if (actionFile != 0) { int objId = -1; if (this->objectValue != 0) objId = this->objectValue->id; fprintf(actionFile, str_fmt_stopObject, objId, str_taiuaimd_path, (line)); } } while(0)

int TribeArtifactUnitAIModule::processNotify(NotifyEvent* event, unsigned long flags)
{
    switch (event->mType) {
    case 0x1fc: {
        RGE_Static_Object* obj = this->lookupObject(this->targetId);
        if (obj != 0) {
            if (this->visibleStatus(this->objectValue->owner->visible_map, (int)obj->x, (int)obj->y) == 0x0f) {
                return 2;
            }
        }
        this->removeCurrentTarget();
        LOGSTOP(0xa9f);
        this->stopObject(1);
        this->vt1c(event);
        return 2;
    }

    case 0x1f9:
        if (this->field_28 != -1) {
            if (this->field_30 + 0x64 == this->field_28) {
                this->removeCurrentTarget();
                LOGSTOP(0xaae);
                this->stopObject(1);
                this->vt1c(event);
                return 2;
            }
            if (this->field_28 != -1) return 2;
        }
        if (this->field_30 != event->value) return 2;
        this->removeCurrentTarget();
        LOGSTOP(0xab7);
        this->stopObject(1);
        this->vt1c(event);
        return 2;

    case 0x1fb:
        if (this->field_28 != -1) {
            if (this->field_30 + 0x64 == this->field_28) {
                this->removeCurrentTarget();
                LOGSTOP(0xac6);
                this->stopObject(1);
                this->vt1c(event);
                return 2;
            }
            if (this->field_28 != -1) return 2;
        }
        if (this->field_30 != event->value) return 2;
        this->removeCurrentTarget();
        LOGSTOP(0xacf);
        this->stopObject(1);
        this->vt1c(event);
        return 2;

    case 0x202:
        if (this->field_28 != -1) {
            if (this->field_30 + 0x64 == this->field_28) {
                this->removeCurrentTarget();
                LOGSTOP(0xade);
                this->stopObject(1);
                this->vt1c(event);
                return 2;
            }
            if (this->field_28 != -1) return 2;
        }
        if (this->field_30 != event->value) return 2;
        this->removeCurrentTarget();
        LOGSTOP(0xae7);
        this->stopObject(1);
        this->vt1c(event);
        return 2;

    case 0x200: {
        int id = event->objectId;
        int i = 0;
        while (i < this->count && i < this->capacity) {
            if (this->ids[i] == id) goto already;
            ++i;
        }
        if (this->count > this->capacity - 1) {
            int newcap = this->count + 1;
            int* p = (int*)malloc(newcap * 4);
            if (p != 0) {
                for (int j = 0; j < this->capacity && j < newcap; ++j) p[j] = this->ids[j];
                free(this->ids);
                this->ids = p;
                this->capacity = newcap;
            }
        }
        this->ids[this->count++] = id;
already:
        this->objectValue->ve8(1);
        return 2;
    }
    }

    this->removeCurrentTarget();
    LOGSTOP(0xb1f);
    this->stopObject(1);
    this->vt1c(event);
    return 2;
}
