// 0040ABB0 ConstructionAIModule::ConstructionAIModule
// Attempt log:
// - Recovered the full 0x80-byte ConstructionItem and 0xF0-byte polymorphic AIModule ownership;
//   /GX now gives the original 0x148 frame and compiler-owned vptr/EH surface.
// - Reconstructed the binary-proven serialized read order, name+4 buffer, 8-argument constructor,
//   setter order, and both sentinel-list link paths. Typed IntFloat wire unions preserve raw float/int
//   bits without fabricated calls or conversion helpers; all 58 direct calls align.
// - Moved the proven scalar defaults into member initializers, following the exact same-TU constructor
//   donor. This recovers the delayed compiler-owned vptr schedule and the first 96-instruction block;
//   diff improves from 631 to 570 bytes while frame size and all 58 calls remain exact.
// - Reordered wire locals to the packet's declaration order. The emitted code is unchanged, and the
//   natural 257-byte shared name buffer remains the best source reconstruction. The 256-byte and
//   larger diagnostic buffer variants were rejected because they lose the 0x148 frame or do not move
//   name+4 to the oracle's esp+54 home.
// - Remaining structural drift starts at the first loop: rebuilt name+4 is esp+58 and wire locals use
//   different stack homes than the oracle's esp+54/name and proven +10..+44 slots. Do not tune registers;
//   manual vptr/novtable tricks remain prohibited.

extern "C" void rge_read(int fd, void* dst, int size);

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
    virtual ~ConstructionAIModule();
    int numberConstructionLotsValue;
    ConstructionItem lots;
    int numberSecondValue;
    ConstructionItem second;
    char constructionPlanNameValue[0x104];
    float xReferencePointValue, yReferencePointValue, zReferencePointValue;
    int mapXSizeValue, mapYSizeValue;
    int zero310;
    ConstructionAIModule(int p1, int fd);
};

union IntFloat {
    int i;
    float f;
};

ConstructionAIModule::ConstructionAIModule(int p1, int fd)
    : AIModule("ConAI", 0x3ea, p1, 0),
      numberConstructionLotsValue(0),
      lots(),
      numberSecondValue(0),
      second(),
      xReferencePointValue(-1.0f),
      yReferencePointValue(-1.0f),
      zReferencePointValue(-1.0f),
      mapXSizeValue(-1),
      mapYSizeValue(-1),
      zero310(0)
{
    IntFloat x, y, z, uniqueID, xSize, buildAttempts, ySize, inProgress, zSize;
    IntFloat skip;
    int typeID;
    int built;
    IntFloat gameID, i;
    int n;
    ConstructionItem* item;
    char name[257];

    this->lots.next = &this->lots;
    this->lots.prev = &this->lots;
    this->second.next = &this->second;
    this->second.prev = &this->second;

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
        rge_read(fd, &x.i, 4);
        rge_read(fd, name + 4, x.i);
        name[x.i + 4] = 0;
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
        item = new ConstructionItem(y.f, zSize.f, gameID.f, ySize.f, i.f, xSize.f, typeID, name + 4);
        item->setInProgress(z.i);
        item->setBuilt(uniqueID.i);
        item->setBuildAttempts(buildAttempts.i);
        item->setGameID(inProgress.i);
        item->setUniqueID(skip.i);
        item->setSkip(built);
        item->next = &this->lots;
        item->prev = this->lots.prev;
        this->lots.prev->next = item;
        this->lots.prev = item;
    }

    rge_read(fd, &this->numberSecondValue, 4);
    for (n=0; n<this->numberSecondValue; n++) {
        rge_read(fd, &x.i, 4);
        rge_read(fd, name + 4, x.i);
        name[x.i + 4] = 0;
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
        item = new ConstructionItem(y.f, z.f, uniqueID.f, buildAttempts.f, inProgress.f, skip.f, built, name + 4);
        item->setInProgress(zSize.i);
        item->setBuilt(gameID.i);
        item->setBuildAttempts(ySize.i);
        item->setGameID(i.i);
        item->setUniqueID(xSize.i);
        item->setSkip(typeID);
        item->next = &this->second;
        item->prev = this->second.prev;
        this->second.prev->next = item;
        this->second.prev = item;
    }
}
