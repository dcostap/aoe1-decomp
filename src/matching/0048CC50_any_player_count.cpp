#ifndef SCENARIO_TU
class RGE_Scenario {
public:
    int Get_player_Active(int index);
    int Get_player_Type(int index);
    int any_player_count(void);
};
#endif

int RGE_Scenario::any_player_count(void) {
    int count = 0;
    int i = 0;

    do {
        if (this->Get_player_Active(i) != 0) {
            if (this->Get_player_Type(i) == 1) {
                count++;
            }
        }
        i++;
    } while (i < 0x10);
    return count;
}
