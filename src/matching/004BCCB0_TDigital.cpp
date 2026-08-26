#ifndef SOUNDDRV_CANONICAL_TU
class Base_TDigital {
public:
    virtual ~Base_TDigital();
};

class TDigital : public Base_TDigital {
public:
    void exit();
};
#endif

TDigital::~TDigital() {
    this->exit();
}
