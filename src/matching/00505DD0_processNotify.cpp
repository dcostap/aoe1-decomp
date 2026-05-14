// 00505DD0 TribePriestUnitAIModule::processNotify
// Attempt log:
// 1: Direct reconstruction from packet: switch on event->mType, stop/log tails, special 0x25c/0x25b virtual flows, target-visible branch.
// 2: Inlined repeated logging instead of helper; got to 1-byte diff. Fixed RGE_Player::visible_map offset from +34 to +38.

extern void* actionFile;
extern int fprintf(void*, const char*, ...);
extern const char str_taiuaimd_path[];
extern const char str_fmt_stopObject[];

class RGE_Visible_Map;
class RGE_Player { public: int computerPlayer(); char gap_00[0x38]; RGE_Visible_Map* visible_map; };
class RGE_Static_Object { public: virtual void v00(); int id; char gap_08[4]; RGE_Player* owner; char gap_10[0x28]; float x; float y; };
class UnitAIModule;

class NotifyEvent { public: char gap_00[8]; int mType; };

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
    virtual int vt6c(int id, int flag);
    virtual int vt70(int id, int flag);
    virtual void v74(); virtual void v78(); virtual void v7c(); virtual void v80();
    virtual void v84(); virtual void v88(); virtual void v8c(); virtual void v90();
    virtual void v94(); virtual void v98(); virtual void v9c(); virtual void va0();
    virtual void va4(); virtual void va8(); virtual void vac(); virtual void vb0();
    virtual void vb4(); virtual void vb8(); virtual void vbc(); virtual void vc0();
    virtual void vc4(); virtual void vc8(); virtual void vcc(); virtual void vd0();
    virtual void vd4(); virtual void vd8(); virtual void vdc();
    virtual int vte0(int a, int b);
    virtual int vte4(int a);

    RGE_Static_Object* objectValue; // +4

    void removeCurrentTarget();
    RGE_Static_Object* lookupObject(int objectId);
    unsigned char visibleStatus(RGE_Visible_Map* map, int x, int y);
    int processNotify(NotifyEvent* event, unsigned long param_2);
};

class TribePriestUnitAIModule : public UnitAIModule {
public:
    char gap_08[0x28];
    int field_30;
    int field_34;

    int processNotify(NotifyEvent* event, unsigned long param_2);
};

int TribePriestUnitAIModule::processNotify(NotifyEvent* event, unsigned long param_2)
{
    switch (event->mType) {
    case 0x1f9:
    case 0x1fb:
    case 0x202:
        if (this->objectValue->owner->computerPlayer() == 0 && this->field_30 == 0x25c) {
            this->removeCurrentTarget();
            if (actionFile != 0) {
                int objId;
                if (this->objectValue != 0) {
                    objId = this->objectValue->id;
                } else {
                    objId = -1;
                }
                fprintf(actionFile, str_fmt_stopObject, objId, str_taiuaimd_path, 0x63b);
            }
            this->stopObject(1);
            this->vt1c(event);
            return 2;
        }
        if (this->field_30 == 0x25c) {
            int id = this->vte4(0);
            if (id != -1 && this->vt6c(id, 1) == 1) {
                return 3;
            }
        } else if (this->field_30 == 0x25b) {
            int id = this->vte0(0, 0);
            if (id != -1 && this->vt70(id, 1) == 1) {
                return 3;
            }
        }
        this->removeCurrentTarget();
        if (actionFile != 0) {
                int objId;
                if (this->objectValue != 0) {
                    objId = this->objectValue->id;
                } else {
                    objId = -1;
                }
                fprintf(actionFile, str_fmt_stopObject, objId, str_taiuaimd_path, 0x675);
            }
        this->stopObject(0);
        this->vt1c(event);
        return 2;

    case 0x1fc:
    {
        RGE_Static_Object* obj = this->lookupObject(this->field_34);
        if (obj != 0) {
            if (this->visibleStatus(this->objectValue->owner->visible_map, (int)obj->x, (int)obj->y) == 0x0f) {
                return 2;
            }
        }
        this->removeCurrentTarget();
        if (actionFile != 0) {
                int objId;
                if (this->objectValue != 0) {
                    objId = this->objectValue->id;
                } else {
                    objId = -1;
                }
                fprintf(actionFile, str_fmt_stopObject, objId, str_taiuaimd_path, 0x68f);
            }
        this->stopObject(1);
        this->vt1c(event);
        break;
    }
    }

    return UnitAIModule::processNotify(event, param_2);
}
