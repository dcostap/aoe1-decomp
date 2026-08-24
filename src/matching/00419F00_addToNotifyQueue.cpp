// VA: 00419F00 addToNotifyQueue (279B)
// aiuaimod.cpp
// PDB owner/access: protected nonvirtual UnitAIModule::addToNotifyQueue(int, int,
// int, long, long, long), aiuaimod.cpp:5840-5868.
// Symbol: ?addToNotifyQueue@UnitAIModule@@IAEHHHHJJJ@Z.
// Body boundary: 00419F00-0041A016; 00419ED0 is the preceding sibling.
// Attempt log:
// - Replaced the stale placeholder with the proven notify-queue ownership:
//   size at +0x1c, capacity at +0x20, and NotifyEvent array at +0x24.
// - The typed field-copy/indexed append baseline matched through the append
//   block; direct/compound shift spellings left a localized register drift.
// - A focused natural source-shape lab showed that spelling capacity growth as
//   multiplication by two reproduces the original VC5 register/block layout.
// - Main-agent audit confirmed canonical UnitAIModule/NotifyEvent ownership;
//   emitted code remains exact.
// - A fresh public-ABI check also matched bytes, but emitted QAE rather than
//   the PDB-qualified protected IAE owner. Keep the protected declaration.

#ifndef AOE1_AIUAIMOD_COMPLETE_TU
struct NotifyEvent {
    int caller;
    int recipient;
    int mType;
    long p1;
    long p2;
    long p3;
};

struct OrderEvent;

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
    int notifyQueueSizeValue;
    int notifyQueueMaxSizeValue;
    NotifyEvent* notifyQueueValue;

protected:
    int addToNotifyQueue(int caller, int recipient, int mType,
                         long p1, long p2, long p3);
};
#endif

int UnitAIModule::addToNotifyQueue(int caller, int recipient, int mType,
                                   long p1, long p2, long p3)
{
    if (this->notifyQueueMaxSizeValue == this->notifyQueueSizeValue) {
        NotifyEvent* newQueue =
            (NotifyEvent*)operator new(this->notifyQueueMaxSizeValue * 0x30);
        if (newQueue == 0) {
            return 0;
        }

        int i = 0;
        if (this->notifyQueueSizeValue > 0) {
            do {
                newQueue[i].caller = this->notifyQueueValue[i].caller;
                newQueue[i].recipient = this->notifyQueueValue[i].recipient;
                newQueue[i].mType = this->notifyQueueValue[i].mType;
                newQueue[i].p1 = this->notifyQueueValue[i].p1;
                newQueue[i].p2 = this->notifyQueueValue[i].p2;
                newQueue[i].p3 = this->notifyQueueValue[i].p3;
                ++i;
            } while (i < this->notifyQueueSizeValue);
        }

        if (this->notifyQueueValue != 0) {
            operator delete(this->notifyQueueValue);
        }
        this->notifyQueueValue = newQueue;
        this->notifyQueueMaxSizeValue = this->notifyQueueMaxSizeValue * 2;
    }

    this->notifyQueueValue[this->notifyQueueSizeValue].caller = caller;
    this->notifyQueueValue[this->notifyQueueSizeValue].recipient = recipient;
    this->notifyQueueValue[this->notifyQueueSizeValue].mType = mType;
    this->notifyQueueValue[this->notifyQueueSizeValue].p1 = p1;
    this->notifyQueueValue[this->notifyQueueSizeValue].p2 = p2;
    this->notifyQueueValue[this->notifyQueueSizeValue].p3 = p3;
    this->notifyQueueSizeValue = this->notifyQueueSizeValue + 1;
    return 1;
}
