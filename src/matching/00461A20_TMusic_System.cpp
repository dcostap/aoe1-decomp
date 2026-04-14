class Base_TMusic_System {
public:
    virtual ~Base_TMusic_System();
};

class TMusic_System : public Base_TMusic_System {
};

extern "C" void probe_TMusic_System(TMusic_System* p);
#pragma alloc_text(".xtra", probe_TMusic_System)
extern "C" void probe_TMusic_System(TMusic_System* p) {
    p->TMusic_System::~TMusic_System();
}
