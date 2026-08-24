// VA: 004D6800 TribeConstructionAIModule::setBuilt
// taiconmd.cpp:363-379

#ifndef TAICONMD_SHARED_CONTEXT
class BaseItem {
public:
    virtual ~BaseItem();
    char gap_04[0x68];

    int typeID(void) const;
    float x(void) const;
    float y(void) const;
};

class ConstructionItem : public BaseItem {
public:
    ConstructionItem* next;
    ConstructionItem* prev;
    int inProgressValue;
    int builtValue;
    int buildAttemptsValue;

    void setBuilt(int v);
};

class MasterObject {
public:
    char gap_00[0x10];
    short id;
};

class RGE_Static_Object {
public:
    char gap_00[0x08];
    MasterObject* master_obj;
    char gap_0C[0x2C];
    float world_x;
    float world_y;
};

class TribeInformationAIModule {
public:
    void storeLot(int typeID, unsigned char x, unsigned char y, unsigned char built);
};

class MainAI {
public:
    char gap_000[0xCEC];
    TribeInformationAIModule informationAI;
};

class TribeConstructionAIModule {
public:
    char gap_000[0xF4];
    ConstructionItem constructionLots;
    char gap_178[0x1A0];
    MainAI* mainAI;

    void setBuilt(RGE_Static_Object* obj, int built);
};
#endif

void TribeConstructionAIModule::setBuilt(RGE_Static_Object* obj, int built) {
    ConstructionItem* item;

    item = this->constructionLots.next;
    while (item != &this->constructionLots && item != 0) {
        if (item->typeID() == obj->master_obj->id && item->x() == obj->world_x && item->y() == obj->world_y) {
            item->setBuilt(built);
            return;
        }
        item = item->next;
    }

    this->mainAI->informationAI.storeLot(obj->master_obj->id, (unsigned char)obj->world_x, (unsigned char)obj->world_y, 1);
}
