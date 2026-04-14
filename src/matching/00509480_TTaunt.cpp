class Base_TTaunt {
public:
    virtual ~Base_TTaunt();
};

class TTaunt : public Base_TTaunt {
};

extern "C" void probe_TTaunt(TTaunt* p);
#pragma alloc_text(".xtra", probe_TTaunt)
extern "C" void probe_TTaunt(TTaunt* p) {
    p->TTaunt::~TTaunt();
}
