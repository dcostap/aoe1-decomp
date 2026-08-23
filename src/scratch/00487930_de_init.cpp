class T_Scenario {
public:
    void deInitHelper();
    unsigned char de_init();
};

unsigned char T_Scenario::de_init() {
    this->deInitHelper();
    return 1;
}
