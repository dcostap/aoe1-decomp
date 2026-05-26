// 0040ABB0 ConstructionAIModule::ConstructionAIModule
// Attempt log:
// 1: reconstruction from packet: base AIModule ctor, two ConstructionItem sentinel ctors/lists, read serialized fields, allocate/reconstruct lot items, link into two lists.
// 2: /GX is required for the original EH-framed constructor basin; without /GX the body is only 1328 bytes vs original 1379.
// 3: first /GX build reached exact 1379-byte size but used a 0x144 frame instead of original 0x148 and had broad mismatch (76.8673% positional / 87.0921% edit).
// 4: reused a single name buffer for both list loops and added a volatile dummy local trying to force the missing 4-byte stack slot; exact-size remained but prologue frame stayed 0x144.
// 5: behavior modeled includes the initial serialized count/name/reference-point fields, two 0x80-byte ConstructionItem allocations, setter calls, and linking onto +0xF4/+0x178 sentinel lists.
// 6: remaining gap is constructor/EH/local-slot/source-shape mismatch: original has very specific 0x148 frame with name buffer at esp+54, loop index at esp+48, allocation temp at esp+4C, EH states 0..4, and manual list-link scheduling. Current natural source preserves behavior but wrong frame/local packing and broad call/register ordering. Not accepted_drift-safe.

extern "C" void rge_read(int fd, void* dst, int size);

class AIModule { public: AIModule(char*, int, int, int); };
class ConstructionItem {
public:
    char gap[0x6c];
    ConstructionItem* next;
    ConstructionItem* prev;
    ConstructionItem();
    ConstructionItem(int,int,float,float,float,float,float,float,int,int,int,int);
    void setID(int); void setGameID(int); void setUniqueID(int); void setSkip(int); void setInProgress(int); void setBuilt(int);
};
class ConstructionAIModule : public AIModule {
public:
    char gap_base[0xF0-sizeof(AIModule)];
    int numberConstructionLotsValue;
    ConstructionItem lots;
    int numberSecondValue;
    ConstructionItem second;
    char gap1fc[0x2FC-0x1EC];
    int xReferencePointValue, yReferencePointValue, zReferencePointValue, mapXSizeValue, mapYSizeValue;
    int zero310;
    ConstructionAIModule(int p1, int fd);
};

ConstructionAIModule::ConstructionAIModule(int p1, int fd) : AIModule((char*)0x57F380, 0x3ea, p1, 0), lots(), second()
{
    int n;
    int len;
    int typeID, gameID, uniqueID, skip, inProgress, built, buildAttempts;
    float x,y,z,xSize,ySize,zSize;
    ConstructionItem* item;
    volatile int dummyLocal;
    char name[0x104];

    dummyLocal = 0;
    this->numberConstructionLotsValue = 0;
    this->numberSecondValue = 0;
    this->lots.next = &this->lots;
    this->lots.prev = &this->lots;
    this->second.next = &this->second;
    this->second.prev = &this->second;
    this->xReferencePointValue = 0xbf800000;
    this->yReferencePointValue = 0xbf800000;
    this->zReferencePointValue = 0xbf800000;
    this->mapXSizeValue = -1;
    this->mapYSizeValue = -1;
    this->zero310 = 0;
    *(int*)this = 0x56E7A0;

    rge_read(fd, &this->numberConstructionLotsValue, 4);
    rge_read(fd, &len, 4);
    rge_read(fd, (char*)this + 0x1F8, len);
    *((char*)this + 0x1F8 + len) = 0;
    rge_read(fd, &this->xReferencePointValue, 4);
    rge_read(fd, &this->yReferencePointValue, 4);
    rge_read(fd, &this->zReferencePointValue, 4);
    rge_read(fd, &this->mapXSizeValue, 4);
    rge_read(fd, &this->mapYSizeValue, 4);

    for (n=0; n<this->numberConstructionLotsValue; n++) {
        rge_read(fd, &len, 4);
        rge_read(fd, name, len);
        name[len] = 0;
        rge_read(fd, &typeID, 4);
        rge_read(fd, &gameID, 4);
        rge_read(fd, &uniqueID, 4);
        rge_read(fd, &x, 4);
        rge_read(fd, &y, 4);
        rge_read(fd, &z, 4);
        rge_read(fd, &xSize, 4);
        rge_read(fd, &ySize, 4);
        rge_read(fd, &zSize, 4);
        rge_read(fd, &skip, 4);
        rge_read(fd, &inProgress, 4);
        rge_read(fd, &built, 4);
        rge_read(fd, &buildAttempts, 4);
        item = new ConstructionItem(typeID, gameID, x, y, z, xSize, ySize, zSize, skip, inProgress, built, buildAttempts);
        item->setID(uniqueID);
        item->setGameID(gameID);
        item->setUniqueID(uniqueID);
        item->setSkip(skip);
        item->setInProgress(inProgress);
        item->setBuilt(built);
        item->next = &this->lots;
        item->prev = this->lots.prev;
        this->lots.prev->next = item;
        this->lots.prev = item;
    }

    rge_read(fd, &this->numberSecondValue, 4);
    for (n=0; n<this->numberSecondValue; n++) {
        rge_read(fd, &len, 4);
        rge_read(fd, name, len);
        name[len] = 0;
        rge_read(fd, &typeID, 4);
        rge_read(fd, &gameID, 4);
        rge_read(fd, &uniqueID, 4);
        rge_read(fd, &x, 4);
        rge_read(fd, &y, 4);
        rge_read(fd, &z, 4);
        rge_read(fd, &xSize, 4);
        rge_read(fd, &ySize, 4);
        rge_read(fd, &zSize, 4);
        rge_read(fd, &skip, 4);
        rge_read(fd, &inProgress, 4);
        rge_read(fd, &built, 4);
        rge_read(fd, &buildAttempts, 4);
        item = new ConstructionItem(typeID, gameID, x, y, z, xSize, ySize, zSize, skip, inProgress, built, buildAttempts);
        item->setID(uniqueID);
        item->setGameID(gameID);
        item->setUniqueID(uniqueID);
        item->setSkip(skip);
        item->setInProgress(inProgress);
        item->setBuilt(built);
        item->next = &this->second;
        item->prev = this->second.prev;
        this->second.prev->next = item;
        this->second.prev = item;
    }
}
