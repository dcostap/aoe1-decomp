#ifndef RMM_TDBC_SHARED_CONTEXT
class RGE_RMM_Database_Controller {
public:
    virtual unsigned char de_init();
};

class TRIBE_RMM_Database_Controller : public RGE_RMM_Database_Controller {
public:
    virtual unsigned char de_init();
};
#endif

unsigned char TRIBE_RMM_Database_Controller::de_init() {
    this->RGE_RMM_Database_Controller::de_init();
    return 1;
}
