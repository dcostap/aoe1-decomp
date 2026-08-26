#ifndef SOUNDDRV_CANONICAL_TU
class Base_TSound_Driver {
public:
    virtual ~Base_TSound_Driver();
};

class TSound_Driver : public Base_TSound_Driver {
public:
    void exit();
};
#endif

TSound_Driver::~TSound_Driver() {
    this->exit();
}
