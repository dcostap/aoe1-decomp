// VA: 00419ED0 UnitAIModule::addToNotifyQueue
// PDB owner/access: protected nonvirtual UnitAIModule::addToNotifyQueue
// (?addToNotifyQueue@UnitAIModule@@IAEHPAUNotifyEvent@@@Z), aiuaimod.cpp:5831-5834.
// Body boundary: 00419ED0-00419EF2; 00419F00 is the next PDB sibling.
// BINARY NOTE: the wrapper reads all six event fields before its direct call.
// Direct target: protected ?addToNotifyQueue@UnitAIModule@@IAEHHHHJJJ@Z at 00419F00.
// The callee uses ret 18h, while this wrapper uses ret 4 for its event pointer.

#ifndef AOE1_AIUAIMOD_COMPLETE_TU
struct NotifyEvent {
    int caller;
    int recipient;
    int mType;
    long p1;
    long p2;
    long p3;
};

class UnitAIModule {
protected:
    int addToNotifyQueue(NotifyEvent* event);
    int addToNotifyQueue(int caller, int recipient, int mType, long p1, long p2, long p3);
};
#endif

int UnitAIModule::addToNotifyQueue(NotifyEvent* event) {
    return this->addToNotifyQueue(
        event->caller,
        event->recipient,
        event->mType,
        event->p1,
        event->p2,
        event->p3
    );
}
