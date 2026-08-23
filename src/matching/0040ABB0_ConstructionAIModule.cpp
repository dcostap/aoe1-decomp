// 0040ABB0 ConstructionAIModule::ConstructionAIModule
// Attempt log:
// - Recovered the full 0x80-byte ConstructionItem and 0xF0-byte polymorphic AIModule ownership;
//   /GX now gives the original 0x148 frame and compiler-owned vptr/EH surface.
// - Reconstructed the binary-proven serialized read order, local name buffer, 8-argument constructor,
//   setter order, and both sentinel-list link paths. Typed IntFloat wire unions preserve raw float/int
//   bits without fabricated calls or conversion helpers; all 58 direct calls align.
// - Moved the proven scalar defaults into member initializers, following the exact same-TU constructor
//   donor. This recovers the delayed compiler-owned vptr schedule and the first 96-instruction block;
//   diff improves from 631 to 570 bytes while frame size and all 58 calls remain exact.
// - Scoped the serialized wire locals per list loop and carried the sentinel predecessor through the
//   item link. This restored the original stack homes, register reuse, 0x148 frame, and 1379-byte size;
//   the remaining six-byte drift was only the decompiler's name-plus-four cursor.
// - Direct access to the natural local name buffer removes that cursor. The VC5 output is an exact
//   1379-byte match with all 58 calls aligned. Native scalar and aggregate-local diagnostics were
//   rejected because they added conversion or frame drift.

extern "C" void rge_read(int fd, void* dst, int size);

#ifndef AICONMOD_CANONICAL_TU
class BaseItem {
public:
    virtual ~BaseItem();
};

class AIModule {
public:
    virtual ~AIModule();
    char gap_04[0xEC];
    AIModule(char*, int, int, int);
};

class ConstructionItem : public BaseItem {
public:
    char gap_04[0x68];
    ConstructionItem* next;
    ConstructionItem* prev;
    int inProgressValue;
    int builtValue;
    int buildAttemptsValue;
    virtual ~ConstructionItem();
    ConstructionItem();
    ConstructionItem(float,float,float,float,float,float,int,const char*);
    void setBuildAttempts(int); void setGameID(int); void setUniqueID(int); void setSkip(int); void setInProgress(int); void setBuilt(int);
};
class ConstructionAIModule : public AIModule {
public:
    enum PlacementResult { PlacementOk = 0 };
    virtual ~ConstructionAIModule();
    int numberConstructionLotsValue;
    ConstructionItem constructionLots;
    int numberRandomConstructionLotsValue;
    ConstructionItem randomConstructionLots;
    char constructionPlanNameValue[0x104];
    float xReferencePointValue, yReferencePointValue, zReferencePointValue;
    int mapXSizeValue, mapYSizeValue;
    int lastPlacementReturnCodeValue;
    ConstructionAIModule(int p1, int fd);
};
#endif

union IntFloat {
    int i;
    float f;
};

ConstructionAIModule::ConstructionAIModule(int p1, int fd)
    : AIModule("ConAI", 0x3ea, p1, 0),
      numberConstructionLotsValue(0),
      constructionLots(),
      numberRandomConstructionLotsValue(0),
      randomConstructionLots(),
      xReferencePointValue(-1.0f),
      yReferencePointValue(-1.0f),
      zReferencePointValue(-1.0f),
      mapXSizeValue(-1),
      mapYSizeValue(-1),
      lastPlacementReturnCodeValue(PlacementOk)
{
    char name[257];
    IntFloat x;
    int n;
    ConstructionItem* item;
    ConstructionItem* prev;

    this->constructionLots.next = &this->constructionLots;
    this->constructionLots.prev = &this->constructionLots;
    this->randomConstructionLots.next = &this->randomConstructionLots;
    this->randomConstructionLots.prev = &this->randomConstructionLots;

    rge_read(fd, &this->numberConstructionLotsValue, 4);
    rge_read(fd, &x.i, 4);
    rge_read(fd, this->constructionPlanNameValue, x.i);
    this->constructionPlanNameValue[x.i] = 0;
    rge_read(fd, &this->xReferencePointValue, 4);
    rge_read(fd, &this->yReferencePointValue, 4);
    rge_read(fd, &this->zReferencePointValue, 4);
    rge_read(fd, &this->mapXSizeValue, 4);
    rge_read(fd, &this->mapYSizeValue, 4);

    for (n=0; n<this->numberConstructionLotsValue; n++) {
        IntFloat y, z, uniqueID, xSize, buildAttempts, ySize, inProgress, zSize;
        IntFloat skip;
        int typeID;
        int built;
        IntFloat gameID, i;

        rge_read(fd, &x.i, 4);
        rge_read(fd, name, x.i);
        name[x.i] = 0;
        rge_read(fd, &typeID, 4);
        rge_read(fd, &inProgress.i, 4);
        rge_read(fd, &skip.i, 4);
        rge_read(fd, &y.f, 4);
        rge_read(fd, &zSize.f, 4);
        rge_read(fd, &gameID.i, 4);
        rge_read(fd, &ySize.f, 4);
        rge_read(fd, &i.i, 4);
        rge_read(fd, &xSize.f, 4);
        rge_read(fd, &built, 4);
        rge_read(fd, &z.f, 4);
        rge_read(fd, &uniqueID.i, 4);
        rge_read(fd, &buildAttempts.i, 4);
        item = new ConstructionItem(y.f, zSize.f, gameID.f, ySize.f, i.f, xSize.f, typeID, name);
        item->setInProgress(z.i);
        item->setBuilt(uniqueID.i);
        item->setBuildAttempts(buildAttempts.i);
        item->setGameID(inProgress.i);
        item->setUniqueID(skip.i);
        item->setSkip(built);
        item->next = &this->constructionLots;
        prev = this->constructionLots.prev;
        item->prev = prev;
        prev->next = item;
        this->constructionLots.prev = item;
    }

    rge_read(fd, &this->numberRandomConstructionLotsValue, 4);
    for (n=0; n<this->numberRandomConstructionLotsValue; n++) {
        IntFloat y, z, uniqueID, xSize, buildAttempts, ySize, inProgress, zSize;
        IntFloat skip;
        int typeID;
        int built;
        IntFloat gameID, i;

        rge_read(fd, &x.i, 4);
        rge_read(fd, name, x.i);
        name[x.i] = 0;
        rge_read(fd, &built, 4);
        rge_read(fd, &i.i, 4);
        rge_read(fd, &xSize.i, 4);
        rge_read(fd, &y.f, 4);
        rge_read(fd, &z.f, 4);
        rge_read(fd, &uniqueID.i, 4);
        rge_read(fd, &buildAttempts.i, 4);
        rge_read(fd, &inProgress.i, 4);
        rge_read(fd, &skip.i, 4);
        rge_read(fd, &typeID, 4);
        rge_read(fd, &zSize.i, 4);
        rge_read(fd, &gameID.i, 4);
        rge_read(fd, &ySize.i, 4);
        item = new ConstructionItem(y.f, z.f, uniqueID.f, buildAttempts.f, inProgress.f, skip.f, built, name);
        item->setInProgress(zSize.i);
        item->setBuilt(gameID.i);
        item->setBuildAttempts(ySize.i);
        item->setGameID(i.i);
        item->setUniqueID(xSize.i);
        item->setSkip(typeID);
        item->next = &this->randomConstructionLots;
        prev = this->randomConstructionLots.prev;
        item->prev = prev;
        prev->next = item;
        this->randomConstructionLots.prev = item;
    }
}
