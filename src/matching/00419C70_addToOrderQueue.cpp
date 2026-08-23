// VA: 00419C70 addToOrderQueue (607B)
// PDB owner/access: protected nonvirtual UnitAIModule::addToOrderQueue
// (?addToOrderQueue@UnitAIModule@@IAEHHHHHMMMMHH@Z), aiuaimod.cpp:5762-5826.
// Body boundary: 00419C70-00419ECE; 00419ED0 is the next PDB sibling.
// aiuaimod.cpp
// Attempt log:
// - Reconstructed the canonical OrderEvent queue. The queue has nine 4-byte
//   fields, a 0x24-byte stride, and UnitAIModule fields at +0x10, +0x14, and
//   +0x18. The p9 path shifts existing records toward the next slot.
// - PDB/Ghidra proves this overload is protected and nonvirtual. The previous
//   public declaration emitted identical bytes but the wrong QAEH owner symbol.
// - The protected declaration now emits the PDB-qualified IAEH owner while
//   preserving the exact boundary, direct allocation calls, ret 28h cleanup,
//   queue rereads, publication order, and null-fault order.

struct OrderEvent {
    int issuer;
    int orderType;
    int priority;
    int target;
    int targetOwner;
    float targetX;
    float targetY;
    float targetZ;
    float range;
};

void* __cdecl operator new(unsigned int size);
void __cdecl operator delete(void* ptr);

class UnitAIModule {
public:
    virtual ~UnitAIModule();
    void* objectValue;
    int moodValue;
    int objectCategoryValue;
    int orderQueueSizeValue;
    int orderQueueMaxSizeValue;
    OrderEvent* orderQueueValue;

protected:
    int addToOrderQueue(int p1, int p2, int p3, int p4,
                        float p5, float p6, float p7, float p8,
                        int p9, int p10);
};

int UnitAIModule::addToOrderQueue(int p1, int p2, int p3, int p4,
                                  float p5, float p6, float p7, float p8,
                                  int p9, int p10)
{
    if (this->orderQueueMaxSizeValue == this->orderQueueSizeValue) {
        OrderEvent* newQueue =
            (OrderEvent*)operator new(this->orderQueueMaxSizeValue * 0x48);
        if (newQueue == 0) {
            return 0;
        }

        int i = 0;
        if (this->orderQueueSizeValue > 0) {
            do {
                newQueue[i].issuer = this->orderQueueValue[i].issuer;
                newQueue[i].orderType = this->orderQueueValue[i].orderType;
                newQueue[i].priority = this->orderQueueValue[i].priority;
                newQueue[i].target = this->orderQueueValue[i].target;
                newQueue[i].targetOwner = this->orderQueueValue[i].targetOwner;
                newQueue[i].targetX = this->orderQueueValue[i].targetX;
                newQueue[i].targetY = this->orderQueueValue[i].targetY;
                newQueue[i].targetZ = this->orderQueueValue[i].targetZ;
                newQueue[i].range = this->orderQueueValue[i].range;
                ++i;
            } while (i < this->orderQueueSizeValue);
        }

        if (this->orderQueueValue != 0) {
            operator delete(this->orderQueueValue);
        }
        this->orderQueueValue = newQueue;
        this->orderQueueMaxSizeValue = this->orderQueueMaxSizeValue * 2;
    }

    if ((p9 != 0) && (this->orderQueueSizeValue != 0)) {
        int i = 0;
        if (this->orderQueueSizeValue > 0) {
            do {
                this->orderQueueValue[i + 1].issuer =
                    this->orderQueueValue[i].issuer;
                this->orderQueueValue[i + 1].orderType =
                    this->orderQueueValue[i].orderType;
                this->orderQueueValue[i + 1].priority =
                    this->orderQueueValue[i].priority;
                this->orderQueueValue[i + 1].target =
                    this->orderQueueValue[i].target;
                this->orderQueueValue[i + 1].targetOwner =
                    this->orderQueueValue[i].targetOwner;
                this->orderQueueValue[i + 1].targetX =
                    this->orderQueueValue[i].targetX;
                this->orderQueueValue[i + 1].targetY =
                    this->orderQueueValue[i].targetY;
                this->orderQueueValue[i + 1].targetZ =
                    this->orderQueueValue[i].targetZ;
                this->orderQueueValue[i + 1].range =
                    this->orderQueueValue[i].range;
                ++i;
            } while (i < this->orderQueueSizeValue);
        }

        this->orderQueueValue->issuer = p1;
        this->orderQueueValue->orderType = p2;
        this->orderQueueValue->priority = p10;
        this->orderQueueValue->target = p3;
        this->orderQueueValue->targetOwner = p4;
        this->orderQueueValue->targetX = p5;
        this->orderQueueValue->targetY = p6;
        this->orderQueueValue->targetZ = p7;
        this->orderQueueValue->range = p8;
        this->orderQueueSizeValue = this->orderQueueSizeValue + 1;
        return 1;
    }

    this->orderQueueValue[this->orderQueueSizeValue].issuer = p1;
    this->orderQueueValue[this->orderQueueSizeValue].orderType = p2;
    this->orderQueueValue[this->orderQueueSizeValue].priority = p10;
    this->orderQueueValue[this->orderQueueSizeValue].target = p3;
    this->orderQueueValue[this->orderQueueSizeValue].targetOwner = p4;
    this->orderQueueValue[this->orderQueueSizeValue].targetX = p5;
    this->orderQueueValue[this->orderQueueSizeValue].targetY = p6;
    this->orderQueueValue[this->orderQueueSizeValue].targetZ = p7;
    this->orderQueueValue[this->orderQueueSizeValue].range = p8;
    this->orderQueueSizeValue = this->orderQueueSizeValue + 1;
    return 1;
}
