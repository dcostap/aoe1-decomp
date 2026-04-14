class TRIBE_Screen_Sed_Open {
public:
    virtual void handle_idle();
};

class TRIBE_Screen_Disconnect : public TRIBE_Screen_Sed_Open {
public:
    void handle_idle();
};

void TRIBE_Screen_Disconnect::handle_idle() { TRIBE_Screen_Sed_Open::handle_idle(); }
