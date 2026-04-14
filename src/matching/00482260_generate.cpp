class RGE_Random_Map_Module {
public:
    virtual void generate();
};

class RGE_RMM_Controller : public RGE_Random_Map_Module {
public:
    void generate();
};

void RGE_RMM_Controller::generate() { RGE_Random_Map_Module::generate(); }
