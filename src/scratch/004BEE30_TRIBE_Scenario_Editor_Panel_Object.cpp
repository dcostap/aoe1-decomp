class Base_TRIBE_Scenario_Editor_Panel_Object {
public:
    virtual ~Base_TRIBE_Scenario_Editor_Panel_Object();
};

class TRIBE_Scenario_Editor_Panel_Object : public Base_TRIBE_Scenario_Editor_Panel_Object {
public:
    virtual ~TRIBE_Scenario_Editor_Panel_Object();
};

TRIBE_Scenario_Editor_Panel_Object::~TRIBE_Scenario_Editor_Panel_Object() {
}
