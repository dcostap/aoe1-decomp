// 004D5310 TribeBuildAIModule::cancelBuildItem
// Attempt log:
// 1: natural implementation from packet/decompiler with local typed surfaces: broad mismatch; compiler used sub esp,10 and byte jump table, original uses push ecx one local and direct address jump table.
// 2: remove named float corner locals and use direct clearArea expressions to reduce frame pressure: prologue now matches through first call; mismatch starts at switch because VC5 chose byte dispatch table.
// 3: switch on action+1 to encourage direct address jump table like original: no change, VC5 still emits compact byte dispatch table because many cases collapse.
// 4: prologue/frame now matches after removing named float corner locals; first mismatch is switch/local store at 004D5333.
// 5: current source models detask, lot-status dispatch, object/isMoveable gates, construction lot vs fallback clearArea, construction remove, build-list update, removeLot, and wonder reset.
// 6: remaining early mismatch is not accepted-drift-safe: switch dispatch shape differs (original direct address jump table, rebuilt byte-index table) and cascades branch offsets/control layout.
// 7: FPU clearArea expression ordering is only approximate; original calls y/ySize/x/xSize twice in a specific sequence with push-placeholder temporaries.
// 8: removeLot tail uses __ftol on y then x and passes newLotStatus; current source likely matches behavior but has not reached exact arg/register staging.
// 9: virtual constructionAI calls are modeled as virtual slots +0x4C/+0x58 but exact class surface may still be incomplete.
// 10: left in scratch: broad mismatch remains after meaningful source-shape attempts; not accepted_drift-safe.

typedef unsigned char uchar;
class RGE_Static_Object;
class ConstructionItem { public: float x(); float y(); float xSize(); float ySize(); int typeID(); };
class BuildItem : public ConstructionItem { public: void setInProgress(int); };
class ConstructionAI {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18();
    virtual void removeLot(float x, float y, int status);
    virtual void v20(); virtual void v21();
    virtual void cancel(float x, float y, int n);
    ConstructionItem* lot(float x, float y);
};
class TribeInformationAIModule { public: void removeLot(int type, int x, int y, uchar status); };
class TribeTacticalAIModule { public: void clearArea(int obj, float x1, float y1, float x2, float y2); char pad[0x122b0]; int wonderInProgressValue; };
class TribeMainDecisionAIModule {
public:
    char pad0[0x6c4]; ConstructionAI constructionAI;
    char pad1[0xcec - 0x6c4 - sizeof(ConstructionAI)]; TribeInformationAIModule informationAI;
    char pad2[0x1146c - 0xcec - sizeof(TribeInformationAIModule)]; TribeTacticalAIModule tacticalAI;
    void detask(int id); RGE_Static_Object* object(int id); int isMoveable(int id);
};
class TribeBuildAIModule { public: char pad[0x5bc]; TribeMainDecisionAIModule* md; BuildItem* specificBuildListItem(int); int cancelBuildItem(int,int,int,float,float,int,int); };

int TribeBuildAIModule::cancelBuildItem(int action, int objId, int buildId, float x, float y, int status, int taskId)
{
    if (taskId != -1) this->md->detask(taskId);
    int lotStatus = 0;
    int moving = 0;
    uchar newLotStatus = 2;
    switch (action + 1) {
    case 0:
        lotStatus = 1;
        moving = 0;
        newLotStatus = 0;
        break;
    case 9:
        moving = 1;
        lotStatus = 1;
        break;
    case 2: case 3: case 4: case 5: case 6: case 7: case 8:
        break;
    default:
        lotStatus = 1;
        moving = 0;
        break;
    }
    RGE_Static_Object* obj = this->md->object(objId);
    if (obj && moving == 1) {
        if (this->md->isMoveable(objId) == 1) {
            ConstructionItem* lot = this->md->constructionAI.lot(x, y);
            if (lot) {
                this->md->tacticalAI.clearArea(objId,
                    lot->x() - lot->xSize() * 0.5f,
                    lot->y() - lot->ySize() * 0.5f,
                    lot->x() - lot->xSize() * -0.5f,
                    lot->y() - lot->ySize() * -0.5f);
            } else {
                this->md->tacticalAI.clearArea(objId, x - 2.0f, y - 2.0f, x - -2.0f, y - -2.0f);
            }
        } else {
            this->md->constructionAI.cancel(x, y, 10);
        }
    }
    this->md->constructionAI.removeLot(x, y, lotStatus);
    BuildItem* item = this->specificBuildListItem(buildId);
    if (item) {
        item->setInProgress(0);
        this->md->informationAI.removeLot(item->typeID(), (int)x, (int)y, newLotStatus);
        if (item->typeID() == 0x114) this->md->tacticalAI.wonderInProgressValue = 0;
    }
    return 1;
}
