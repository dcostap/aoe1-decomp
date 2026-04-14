class BaseClass {
public:
    virtual ~BaseClass();
    BaseClass(int param);
};

class TRIBE_RMM_Database_Controller : public BaseClass {
public:
    virtual ~TRIBE_RMM_Database_Controller();
    TRIBE_RMM_Database_Controller(int param);
};

TRIBE_RMM_Database_Controller::TRIBE_RMM_Database_Controller(int param) : BaseClass(param) {
}
