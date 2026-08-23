#ifndef TACT_BLD_CONTEXT_H
class TRIBE_Action_Build {
public:
    virtual ~TRIBE_Action_Build();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual int set_state(int);
    int stop();
};
#endif

int TRIBE_Action_Build::stop() {
    this->set_state(2);
    return 1;
}
