struct NotifyEvent {
    int caller;
    int recipient;
    int mType;
    int p1;
    int p2;
    int p3;
};

class UnitAIModule {
public:
    int addToNotifyQueue(NotifyEvent* event);
    int addToNotifyQueue(int caller, int recipient, int mType, long p1, long p2, long p3);
};

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
