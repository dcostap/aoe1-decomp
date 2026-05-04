// probe 4: natural virtual-call surface with the nested md->unit object layout

class StopUnitDispatch {
public:
    virtual void vf00();
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
    virtual void stopUnit(int unit, int param_1, int command, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int param_2);

    char gap_04[0x46];
    short unit_id;
};

class TribeMD {
public:
    char gap_00[0xF0];
    StopUnitDispatch* unit;
};

class TribeTacticalAIModule {
public:
    char gap_00[0xF0];
    TribeMD* md;

    int stopUnit(int param_1, int param_2);
};

int TribeTacticalAIModule::stopUnit(int param_1, int param_2) {
    this->md->unit->stopUnit(this->md->unit->unit_id, param_1, 0x2C2, -1, -1,
        0xBF800000, 0xBF800000, 0xBF800000, 0xBF800000, 1, 0, param_2);
    return 1;
}
