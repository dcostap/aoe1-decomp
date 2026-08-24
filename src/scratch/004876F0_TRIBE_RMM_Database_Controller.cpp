#ifndef RMM_TDBC_SHARED_CONTEXT
class RGE_RMM_Database_Controller {
public:
    virtual ~RGE_RMM_Database_Controller();
    RGE_RMM_Database_Controller(int param);
};

class TRIBE_RMM_Database_Controller : public RGE_RMM_Database_Controller {
public:
    virtual ~TRIBE_RMM_Database_Controller();
    TRIBE_RMM_Database_Controller(int param);
};
#endif

TRIBE_RMM_Database_Controller::TRIBE_RMM_Database_Controller(int param)
    : RGE_RMM_Database_Controller(param) {
}
