// 004D5310 TribeBuildAIModule::cancelBuildItem
// Attempt log:
// 1: fresh typed reconstruction matched the call set but emitted a byte switch
//    table and was 35 bytes too large (554 differing bytes).
// 2: natural action-case spelling alone did not change VC5 output.
// 3: initialized lotStatus from the zero moving flag; this matched the original
//    EDI-backed parameter-home store and reduced the diff to 550 bytes.
// 4: separate empty case arms for actions 1 through 7 selected the original
//    four-byte address table, exact size, and a four-byte diff.
// 5: modeled the taibldmd vptrs and tactical wonder fields at md+122b0/+122b4;
//    this fixed the wonder reset and reduced the diff to one stack displacement.
// 6: adding the canonical BuildAIModule base did not change emitted code.
// 7: a non-volatile buildId copy and an entry declaration for item were removed;
//    both emitted the same code.
// 8: a volatile lookup-id home was diagnostic only, worsened the function, and
//    was restored.
// 9: final best source is natural typed ownership with 599-byte output and one
//    remaining mismatch: rebuilt [esp+20] vs original [esp+2c] before lookup.
// 10: left in scratch; the stack-home difference remains behavior-sensitive and
//     is not accepted-drift-safe.

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
class TribeTacticalAIModule {
public:
    virtual ~TribeTacticalAIModule();
    char pad0[0xe40];
    int wonderInProgressValue;
    int wonderBuiltValue;
    char pad1[0x122b4 - 0xe4c];
    void clearArea(int obj, float x1, float y1, float x2, float y2);
};
class TribeMainDecisionAIModule {
public:
    virtual ~TribeMainDecisionAIModule();
    char pad0[0x6c0]; ConstructionAI constructionAI;
    char pad1[0xcec - 0x6c4 - sizeof(ConstructionAI)]; TribeInformationAIModule informationAI;
    char pad2[0x1146c - 0xcec - sizeof(TribeInformationAIModule)]; TribeTacticalAIModule tacticalAI;
    void detask(int id); RGE_Static_Object* object(int id); int isMoveable(int id);
};
class BuildAIModule {
public:
    virtual ~BuildAIModule();
    BuildItem* specificBuildListItem(int);
};
class TribeBuildAIModule : public BuildAIModule {
public:
    char pad[0x5b8];
    TribeMainDecisionAIModule* md;
    int cancelBuildItem(int,int,int,float,float,int,int);
};

int TribeBuildAIModule::cancelBuildItem(int action, int objId, int buildId, float x, float y, int status, int taskId)
{
    BuildItem* item;
    if (taskId != -1) this->md->detask(taskId);
    int moving = 0;
    int lotStatus = moving;
    uchar newLotStatus = 2;
    switch (action) {
    case -1:
        lotStatus = 1;
        moving = 0;
        newLotStatus = 0;
        break;
    case 8:
        moving = 1;
        lotStatus = moving;
        break;
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    case 7:
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
    item = this->specificBuildListItem(buildId);
    if (item) {
        item->setInProgress(0);
        this->md->informationAI.removeLot(item->typeID(), (int)x, (int)y, newLotStatus);
        if (item->typeID() == 0x114) this->md->tacticalAI.wonderInProgressValue = 0;
    }
    return 1;
}
