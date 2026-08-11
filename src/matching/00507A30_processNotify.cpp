// VA: 00507A30 TribeArtifactUnitAIModule::processNotify
// Attempt log:
// try 1: reconstruct broad switch from packet and sibling processNotify matches; initial source compiled too small (640B), showing broad missing inline logging/repeated bodies.
// try 2: inlined repeated actionFile/fprintf stop logging instead of a local helper; size improved to 800B but still short.
// try 3: temporary padding branch got a byte-compare (79.1274% positional / 98.2311% edit) and proved the family is still very broad: prologue loads event into EBP instead of original EBX, switch compiles as sparse compares instead of original dense jump-table, and case layout/tails differ widely. Removed the padding branch.
// try 4: restored the period typed world/visible-map and operator new/delete surfaces, reordered the special cases by their PDB bands, and restored the dense 0x1f4..0x2bb switch case set.
// try 5: changed the field_28 guard to retain the binary-redundant second -1 check and restored the indexed list scan/copy topology; structural islands aligned through the list body.
// try 6: expanded each logging prefix while sharing the fprintf tail; exact size and calls returned, but the temporary line-local/goto source was 328 bytes off.
// try 7: restored ordinary duplicated LOGSTOP plus stop/notify statements; VC5 tail-merged the observed common suffix and produced an exact 848-byte match.

extern void* actionFile;
extern int fprintf(void*, const char*, ...);
extern const char str_taiuaimd_path[];
extern const char str_fmt_stopObject[];
extern void* operator new(unsigned int);
extern void operator delete(void*);

class RGE_Visible_Map;
class RGE_Static_Object;
class RGE_Game_World {
public:
    RGE_Static_Object* object(int id);
};

class RGE_Player {
public:
    char gap_00[0x38];
    RGE_Visible_Map* visible_map; // +0x38
    RGE_Game_World* world;         // +0x3c
};

class RGE_Visible_Map {
public:
    unsigned char get_visible(int x, int y);
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4c();
    virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5c();
    virtual void v60(); virtual void v64(); virtual void v68(); virtual void v6c();
    virtual void v70(); virtual void v74(); virtual void v78(); virtual void v7c();
    virtual void v80(); virtual void v84(); virtual void v88(); virtual void v8c();
    virtual void v90(); virtual void v94(); virtual void v98(); virtual void v9c();
    virtual void va0(); virtual void va4(); virtual void va8(); virtual void vac();
    virtual void vb0(); virtual void vb4(); virtual void vb8(); virtual void vbc();
    virtual void vc0(); virtual void vc4(); virtual void vc8(); virtual void vcc();
    virtual void vd0(); virtual void vd4(); virtual void vd8(); virtual void vdc();
    virtual void ve0(); virtual void ve4();
    virtual unsigned char underAttack(); // +0xe8
    virtual void setUnderAttack(int one); // +0xec

    int id;
    char gap08[4];
    RGE_Player* owner;
    char gap10[0x28];
    float x;
    float y;
};
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

#define LOGSTOP(line) do { \
        if (actionFile != 0) { \
            int objId; \
            if (this->objectValue != 0) objId = this->objectValue->id; \
            else objId = -1; \
            fprintf(actionFile, str_fmt_stopObject, objId, str_taiuaimd_path, (line)); \
        } \
    } while (0)

int TribeArtifactUnitAIModule::processNotify(NotifyEvent* event, unsigned long flags)
{

    switch (event->mType) {
    case 0x1fc: {
        RGE_Static_Object* obj = this->objectValue->owner->world->object(this->targetId);
        if (obj != 0) {
            if (this->objectValue->owner->visible_map->get_visible(
                    (int)obj->x, (int)obj->y) == 0x0f)
                return 2;
        }
        this->removeCurrentTarget();
        LOGSTOP(0xa9f);
        this->stopObject(1);
        this->vt1c(event);
        return 2;
    }

    case 0x1fa:
        if (this->field_28 != -1) {
            if (this->field_30 + 0x64 == this->field_28) {
                this->removeCurrentTarget();
                LOGSTOP(0xaae);
                this->stopObject(1);
                this->vt1c(event);
                return 2;
            }
        }
        if (this->field_28 != -1) return 2;
        if (this->field_30 != event->value) return 2;
        this->removeCurrentTarget();
        LOGSTOP(0xab7);
        this->stopObject(1);
        this->vt1c(event);
        return 2;

    case 0x1f9:
        if (this->field_28 != -1) {
            if (this->field_30 + 0x64 == this->field_28) {
                this->removeCurrentTarget();
                LOGSTOP(0xac6);
                this->stopObject(1);
                this->vt1c(event);
                return 2;
            }
        }
        if (this->field_28 != -1) return 2;
        if (this->field_30 != event->value) return 2;
        this->removeCurrentTarget();
        LOGSTOP(0xacf);
        this->stopObject(1);
        this->vt1c(event);
        return 2;

    case 0x1fb:
        if (this->field_28 != -1) {
            if (this->field_30 + 0x64 == this->field_28) {
                this->removeCurrentTarget();
                LOGSTOP(0xade);
                this->stopObject(1);
                this->vt1c(event);
                return 2;
            }
        }
        if (this->field_28 != -1) return 2;
        if (this->field_30 != event->value) return 2;
        this->removeCurrentTarget();
        LOGSTOP(0xae7);
        this->stopObject(1);
        this->vt1c(event);
        return 2;

    case 600: {
        int id = event->objectId;
        int i = 0;
        while (i < this->count && i < this->capacity) {
            if (this->ids[i] == id) goto already;
            ++i;
        }

        if (this->count > this->capacity - 1) {
            int newCount = this->count + 1;
            int* p = (int*)operator new(newCount * 4);
            if (p != 0) {
                for (int j = 0; j < this->capacity && j < newCount; ++j)
                    p[j] = this->ids[j];
                operator delete(this->ids);
                this->ids = p;
                this->capacity = newCount;
            }
        }
        this->ids[this->count] = id;
        ++this->count;
already:
        this->objectValue->setUnderAttack(1);
        return 2;
    }

    case 0x1f4:
    case 0x1f5:
    case 0x1f6:
    case 0x1f7:
    case 0x1f8:
    case 0x1fd:
    case 0x1fe:
    case 0x1ff:
    case 0x200:
    case 0x201:
    case 0x202:
    case 0x203:
    case 0x204:
    case 0x205:
    case 0x206:
    case 0x207:
    case 0x208:
    case 0x209:
    case 0x20a:
    case 0x20b:
    case 0x20c:
    case 0x20d:
    case 0x20e:
    case 0x20f:
    case 0x210:
    case 0x211:
    case 0x212:
    case 0x213:
    case 0x214:
    case 0x215:
    case 0x216:
    case 0x217:
    case 0x218:
    case 0x219:
    case 0x21a:
    case 0x21b:
    case 0x21c:
    case 0x21d:
    case 0x21e:
    case 0x21f:
    case 0x220:
    case 0x221:
    case 0x222:
    case 0x223:
    case 0x224:
    case 0x225:
    case 0x226:
    case 0x227:
    case 0x228:
    case 0x229:
    case 0x22a:
    case 0x22b:
    case 0x22c:
    case 0x22d:
    case 0x22e:
    case 0x22f:
    case 0x230:
    case 0x231:
    case 0x232:
    case 0x233:
    case 0x234:
    case 0x235:
    case 0x236:
    case 0x237:
    case 0x238:
    case 0x239:
    case 0x23a:
    case 0x23b:
    case 0x23c:
    case 0x23d:
    case 0x23e:
    case 0x23f:
    case 0x240:
    case 0x241:
    case 0x242:
    case 0x243:
    case 0x244:
    case 0x245:
    case 0x246:
    case 0x247:
    case 0x248:
    case 0x249:
    case 0x24a:
    case 0x24b:
    case 0x24c:
    case 0x24d:
    case 0x24e:
    case 0x24f:
    case 0x250:
    case 0x251:
    case 0x252:
    case 0x253:
    case 0x254:
    case 0x255:
    case 0x256:
    case 0x257:
    case 0x259:
    case 0x25a:
    case 0x25b:
    case 0x25c:
    case 0x25d:
    case 0x25e:
    case 0x25f:
    case 0x260:
    case 0x261:
    case 0x262:
    case 0x263:
    case 0x264:
    case 0x265:
    case 0x266:
    case 0x267:
    case 0x268:
    case 0x269:
    case 0x26a:
    case 0x26b:
    case 0x26c:
    case 0x26d:
    case 0x26e:
    case 0x26f:
    case 0x270:
    case 0x271:
    case 0x272:
    case 0x273:
    case 0x274:
    case 0x275:
    case 0x276:
    case 0x277:
    case 0x278:
    case 0x279:
    case 0x27a:
    case 0x27b:
    case 0x27c:
    case 0x27d:
    case 0x27e:
    case 0x27f:
    case 0x280:
    case 0x281:
    case 0x282:
    case 0x283:
    case 0x284:
    case 0x285:
    case 0x286:
    case 0x287:
    case 0x288:
    case 0x289:
    case 0x28a:
    case 0x28b:
    case 0x28c:
    case 0x28d:
    case 0x28e:
    case 0x28f:
    case 0x290:
    case 0x291:
    case 0x292:
    case 0x293:
    case 0x294:
    case 0x295:
    case 0x296:
    case 0x297:
    case 0x298:
    case 0x299:
    case 0x29a:
    case 0x29b:
    case 0x29c:
    case 0x29d:
    case 0x29e:
    case 0x29f:
    case 0x2a0:
    case 0x2a1:
    case 0x2a2:
    case 0x2a3:
    case 0x2a4:
    case 0x2a5:
    case 0x2a6:
    case 0x2a7:
    case 0x2a8:
    case 0x2a9:
    case 0x2aa:
    case 0x2ab:
    case 0x2ac:
    case 0x2ad:
    case 0x2ae:
    case 0x2af:
    case 0x2b0:
    case 0x2b1:
    case 0x2b2:
    case 0x2b3:
    case 0x2b4:
    case 0x2b5:
    case 0x2b6:
    case 0x2b7:
    case 0x2b8:
    case 0x2b9:
    case 0x2ba:
    case 0x2bb:
        return 2;
    }

    this->removeCurrentTarget();
    LOGSTOP(0xb1f);
    this->stopObject(1);
    this->vt1c(event);
    return 2;
}

#undef LOGSTOP
