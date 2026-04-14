class Base_TDigital {
public:
    virtual ~Base_TDigital();
};

class TDigital : public Base_TDigital {
};

extern "C" void probe_TDigital(TDigital* p);
#pragma alloc_text(".xtra", probe_TDigital)
extern "C" void probe_TDigital(TDigital* p) {
    p->TDigital::~TDigital();
}
