// VA: 00506320 TribeTradeShipUnitAIModule::processNotify
// Attempt log:
// try 1: packet-grounded reconstruction from asm: notify-type dispatch for 0x1f4/0x202/0x20f, trade-search retry paths, waypoint/order completion, important-object array maintenance, and fallback to UnitAIModule.
// try 2: modeled exact top-level subtract dispatch: 0x1f4 and 0x20f to death/target path, 0x202 to retry path, fallback to UnitAIModule::processNotify. Current source order still differs.
// try 3: modeled 0x202 currentOrder 0x267 path with vtable+0x40 searches and vtable+0x7c assignment checks returning 6.
// try 4: modeled 0x202 currentOrder 0x25d waypoint path with vtable+0x48, addToWaypointQueue, vtable+0x80, removeCurrentTarget/log/stop/recursive notify tails.
// try 5: modeled 0x1f4/0x20f event-value <=0 branch: object notify, addToWaypointQueue, return 4.
// try 6: modeled importantObjects search/grow/append path using newMax local to match known grow-array lesson; behavior plausible but register allocation is broad.
// try 7: modeled object visible/computer-player checks via raw vtable calls where real class surfaces are unknown; this compiles but call/stack shape is not trustworthy.
// try 8: modeled final orderObject/log/stop/va4 return-3 path and return-2 retryable currentTargetValue path.
// try 9: validation reaches exact size 941 only with approximate raw call surfaces, but broad mismatch (89.4793% positional / 66.6312% edit); first mismatch at prologue because rebuilt uses a local stack slot/push ecx and original has no local frame.
// GIVEUP blockers: exact UnitAIModule/ActionObject/Player class surfaces and vtable slots, natural signatures for object notify/computer-player/order helpers, top-level switch/source ordering, and no-frame register allocation. No inline asm used; no accepted_drift proposal.

extern void* actionFile;
extern int fprintf(void*, const char*, ...);
extern void* operator new(unsigned int size);
extern void operator delete(void* p);
static const char* taiuaimd_cpp = (const char*)0x0057F964;
static const char* fmt_stop = (const char*)0x00588AE8;

class NotifyEvent { public: int objectId; char gap04[4]; int mType; int gap0c; int value; };
class RGE_Action_Object { public: virtual void v00(); int id; char gap08[4]; void* owner; };
class UnitAIModule {
public:
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual int orderObject(int,int,int,int,int,int,int,int,int,int,int,int); // +10 guessed
    virtual void v14(); virtual void v18(); virtual int processNotify(NotifyEvent*, unsigned long); // +1c
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c(); virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c();
    virtual int findTradeUnit(int,int,int,int,int); // +40
    virtual void v44(); virtual int getWaypoint(int*, int*, int); // +48
    virtual void v4c(); virtual void v50(); virtual void v54(); virtual void stopObject(int); // +58
    virtual void v5c(); virtual void v60(); virtual void v64(); virtual void v68(); virtual void v6c(); virtual void v70(); virtual void v74(); virtual void v78();
    virtual int assignTradeUnit(int,int); // +7c
    virtual int setupWaypoint(int,int,int); // +80
    virtual void v84(); virtual void v88(); virtual void v8c(); virtual void v90(); virtual void v94(); virtual void v98(); virtual void v9c(); virtual void va0();
    virtual void va4(int); // +a4

    RGE_Action_Object* objectValue; // +4
    char gap08[0x20];
    int currentTargetValue; // +28
    int lastTargetValue; // +2c
    int currentOrderValue; // +30
    int currentTarget2Value; // +34
    char gap38[4];
    int orderData0; // +3c
    int orderData1; // +40
    int orderData2; // +44
    int orderData3; // +48
    char gap4c[0x14];
    int* importantObjects; // +60
    int numberImportantObjects; // +64
    char gap68[4];
    int maxImportantObjects; // +6c

    void removeCurrentTarget();
    void addToWaypointQueue(int, int);
    void sub_417960(int);
};

class TribeTradeShipUnitAIModule : public UnitAIModule {
public:
    int processNotify(NotifyEvent* event, unsigned long param_2);
};

static void log_stop(UnitAIModule* self, int line)
{
    if (actionFile != 0) {
        int objId = -1;
        if (self->objectValue != 0) objId = self->objectValue->id;
        fprintf(actionFile, fmt_stop, objId, taiuaimd_cpp, line);
    }
}

int TribeTradeShipUnitAIModule::processNotify(NotifyEvent* event, unsigned long param_2)
{
    int type = event->mType;
    if (type == 0x202 || type == 0x1f4) {
        if (event->value <= 0) {
            RGE_Action_Object* obj = this->objectValue;
            int id = event->objectId;
            obj->owner; // keep surface visible
            // notify object of trade/target event
            (*(void (**)(void*, int,int,int,int,int,int))(*(int*)(((char*)obj)+0x0c) + 0xe8))(*(void**)(((char*)obj)+0x0c), obj->id, obj->id, 0x209, id, 0, 0);
            this->addToWaypointQueue(param_2, event->objectId);
            return 4;
        }
        if (this->numberImportantObjects == 0 || (*(int (**)(void*))(**(int**)((char*)this->objectValue + 0x0c) + 0x6edb0))(*(void**)((char*)this->objectValue + 0x0c)) == 1) {
            RGE_Action_Object* obj = this->objectValue;
            (*(void (**)(void*, int,int,int,int,int,int))(*(int*)(((char*)obj)+0x0c) + 0xe8))(*(void**)(((char*)obj)+0x0c), obj->id, obj->id, 0x201, event->objectId, 0, 0);
        }
        int found = 0;
        int i;
        for (i = 0; i < this->numberImportantObjects && i < this->maxImportantObjects; ++i) {
            if (this->importantObjects[i] == event->objectId) { found = 1; break; }
        }
        if (!found) {
            if ((*(int (**)(void*))(**(int**)((char*)this->objectValue + 0x0c) + 0x6edb0))(*(void**)((char*)this->objectValue + 0x0c)) == 0 && this->currentTarget2Value != event->objectId) {
                this->sub_417960(event->objectId);
            }
            for (i = 0; i < this->numberImportantObjects && i < this->maxImportantObjects; ++i) {
                if (this->importantObjects[i] == event->objectId) { found = 1; break; }
            }
            if (!found) {
                if (this->numberImportantObjects > this->maxImportantObjects - 1) {
                    int newMax = this->numberImportantObjects + 1;
                    int* arr = (int*)operator new(newMax * 4);
                    if (arr) {
                        int j;
                        for (j = 0; j < this->maxImportantObjects && j < newMax; ++j) arr[j] = this->importantObjects[j];
                        operator delete(this->importantObjects);
                        this->importantObjects = arr;
                        this->maxImportantObjects = newMax;
                    }
                }
                this->importantObjects[this->numberImportantObjects] = event->objectId;
                ++this->numberImportantObjects;
            }
        }
        (*(void (**)(RGE_Action_Object*, int))(*(int*)this->objectValue + 0xec))(this->objectValue, 1);
        if ((*(int (**)(void*))(**(int**)((char*)this->objectValue + 0x0c) + 0x6edb0))(*(void**)((char*)this->objectValue + 0x0c)) == 0 && this->currentTargetValue != -1) return 2;
        if (this->currentOrderValue != 0x262) {
            this->orderObject(this->currentTargetValue, this->objectValue->id, -1, this->orderData0, this->orderData1, this->orderData2, 0, 0, this->orderData3, this->lastTargetValue, 0, this->currentTarget2Value);
            log_stop(this, 0x761);
            this->stopObject(1);
        }
        this->va4(1);
        return 3;
    }

    if (type == 0x20f) {
        if (this->currentOrderValue == 0x267) {
            int id = this->findTradeUnit(-1, 0, 2, 0x2d, 0);
            if (id != -1 && this->assignTradeUnit(id, 1) == 1) return 6;
            id = this->findTradeUnit(-1, 1, 2, 0x2d, 0);
            if (id != -1 && this->assignTradeUnit(id, 1) == 1) return 6;
        } else if (this->currentOrderValue == 0x25d) {
            int a = 0, b = 0;
            if (this->getWaypoint(&a, &b, 1) == 1) {
                this->addToWaypointQueue(a, b);
                if (this->setupWaypoint(a, b, 1) == 0) {
                    this->removeCurrentTarget();
                    log_stop(this, 0x79c);
                    this->stopObject(1);
                    this->processNotify(event, param_2);
                }
            } else {
                this->removeCurrentTarget();
                log_stop(this, 0x7a8);
                this->stopObject(1);
                this->processNotify(event, param_2);
            }
        }
        this->removeCurrentTarget();
        log_stop(this, 0x7b0);
        this->stopObject(1);
        this->processNotify(event, param_2);
        return 2;
    }

    return UnitAIModule::processNotify(event, param_2);
}
