struct NotifyEvent {
    int caller;
    int recipient;
    int mType;
    int p1;
    int p2;
    int p3;
};

struct CommanderDispatch {
    void* vf00;
    void* vf04;
    void* vf08;
    void* vf0C;
    void* vf10;
    void* vf14;
    int (__stdcall *notify)(int, int, int, int, int, int);
};

class UnitAIModule {
public:
    int notifyCommander(NotifyEvent* event);
    CommanderDispatch* dispatch;
};

int UnitAIModule::notifyCommander(NotifyEvent* event) {
    return this->dispatch->notify(
        event->caller,
        event->recipient,
        event->mType,
        event->p1,
        event->p2,
        event->p3
    );
}
