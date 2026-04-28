// 004D6780 TribeConstructionAIModule::placeDock
// Size: 117 bytes

class ConstructionItem {
public:
    char gap_00[0x6C];
    ConstructionItem* next; // +0x6C
    ConstructionItem* prev; // +0x70
};

class BuildItem;

class TribeInformationAIModule {
public:
    ConstructionItem* placeDock(BuildItem* item, float a, float b, int c, int d);
};

class TribeConstructionAIModule {
public:
    char gap_00[0x174];
    int dock_count;                // +0x174
    ConstructionItem* dock_list;   // +0x178 (linked list anchor)
    char gap_17C[0x6C];
    ConstructionItem* dock_tail;   // +0x1E8
    char gap_1EC[0x110];
    float dock_y;                  // +0x2FC
    float dock_x;                  // +0x300
    char gap_304[0x0C];
    int dock_state;                // +0x310
    void* ai_module_ptr;           // +0x314

    ConstructionItem* placeDock(BuildItem* item);
};

ConstructionItem* TribeConstructionAIModule::placeDock(BuildItem* item) {
    ConstructionItem* result;

    result = ((TribeInformationAIModule*)((char*)this->ai_module_ptr + 0xCEC))->placeDock(
        item, this->dock_y, this->dock_x, 1, 2);

    if (result != 0) {
        result->next = (ConstructionItem*)&this->dock_list;
        {
            ConstructionItem* tail = this->dock_tail;
            result->prev = tail;
            tail->next = result;
        }
        this->dock_tail = result;
        this->dock_count++;
        this->dock_state = 0;
        return result;
    }

    this->dock_state = 5;
    return 0;
}
