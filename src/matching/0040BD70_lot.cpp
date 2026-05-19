// ConstructionAIModule::lot (__thiscall)
// VA: 0040BD70
// aiconmod.cpp:556-570
// 155 bytes
//
// Attempt 4: Fixed BaseItem (sizeof=0x6C) vs ConstructionItem (adds next at +0x6C).

class BaseItem {
public:
    float x();
    float y();
    char gap_00[0x6C];           // sizeof = 0x6C (no next ptr)
};

class ConstructionItem : public BaseItem {
public:
    ConstructionItem* next;      // +0x6C (sizeof = 0x70)
};

// Layout:
// +0xF4: sentinel1 (BaseItem inline, 0x6C bytes) → ends at +0x15F
// +0x160: constructionLots (ConstructionItem* head ptr)
// +0x164: (gap 0x14 bytes) 
// +0x178: sentinel2 (BaseItem inline, 0x6C bytes)
// +0x1E4: randomConstructionLots (ConstructionItem* head ptr)

class ConstructionAIModule {
public:
    char gap_00[0x0F4];
    BaseItem sentinel1;                    // +0x0F4
    ConstructionItem* constructionLots;     // +0x160
    char gap_164[0x14];                    // +0x164 to +0x177
    BaseItem sentinel2;                    // +0x178
    ConstructionItem* randomConstructionLots; // +0x1E4

    ConstructionItem* lot(float x, float y);
};

ConstructionItem* ConstructionAIModule::lot(float x, float y)
{
    ConstructionItem* p = this->constructionLots;

    while ((BaseItem*)p != &this->sentinel1 && p != 0) {
        if (p->x() == x && p->y() == y)
            return p;
        p = p->next;
    }

    p = this->randomConstructionLots;

    while ((BaseItem*)p != &this->sentinel2 && p != 0) {
        if (p->x() == x && p->y() == y)
            return p;
        p = p->next;
    }

    return 0;
}
