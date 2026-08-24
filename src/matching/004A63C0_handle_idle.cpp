#ifndef SCR_MPS_TU_CONTEXT
class TRIBE_Screen_Sed_Open {
public:
    virtual void handle_idle();
};

class TRIBE_Screen_Disconnect : public TRIBE_Screen_Sed_Open {
public:
    void handle_idle();
};
#endif

long TRIBE_Screen_Disconnect::handle_idle() { return TPanel::handle_idle(); }
