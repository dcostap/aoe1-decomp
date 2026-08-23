#ifndef SCENARIO_TU
class RGE_Timeline {
public:
    void update();
};

class RGE_Scenario {
public:
    char gap_0[4];
    RGE_Timeline *time_line;
    void update();
};
#endif

void RGE_Scenario::update() {
    if (this->time_line)
        this->time_line->update();
}
