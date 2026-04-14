extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);

class RGE_Base_Game_ssn {
public:
    void setScenarioName(const char* name);
    char gap_00[0x8FD];
    char scenarioName[0x80];
    char gap_97D[0xFF];
};

void RGE_Base_Game_ssn::setScenarioName(const char* name) {
    strncpy(this->scenarioName, name, 0x80);
    *((unsigned char*)this + 0x97C) = 0;
}
