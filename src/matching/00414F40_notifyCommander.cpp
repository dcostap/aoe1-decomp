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
    virtual int vf00(void);
    virtual int vf04(void);
    virtual int vf08(void);
    virtual int vf0C(void);
    virtual int vf10(void);
    virtual int vf14(void);
    virtual int notify(int caller, int recipient, int mType, long p1, long p2, long p3);

    int notifyCommander(NotifyEvent* event);
};

int UnitAIModule::notifyCommander(NotifyEvent* event) {
    return this->notify(
        event->caller,
        event->recipient,
        event->mType,
        event->p1,
        event->p2,
        event->p3
    );
}
