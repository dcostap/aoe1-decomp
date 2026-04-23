class RGE_RMM_Database_Controller {
public:
    virtual ~RGE_RMM_Database_Controller();
    RGE_RMM_Database_Controller(char* a, char* b, char* c, char* d);
};

class TRIBE_RMM_Database_Controller : public RGE_RMM_Database_Controller {
public:
    TRIBE_RMM_Database_Controller(char* a, char* b, char* c, char* d);
};

TRIBE_RMM_Database_Controller::TRIBE_RMM_Database_Controller(char* a, char* b, char* c, char* d)
    : RGE_RMM_Database_Controller(a, b, c, d) {
}
