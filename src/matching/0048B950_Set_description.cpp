#ifndef SCENARIO_TU
class RGE_Scenario {
public:
    void Set_message(char* text, long field_index);
    void Set_description(char* text);
};
#endif

void RGE_Scenario::Set_description(char* text) { this->Set_message(text, 0); }
