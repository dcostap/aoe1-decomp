#ifndef SCENARIO_TU
class RGE_Scenario {
public:
    int Get_player_Active(int player);
    int active_player_count();
};
#endif

int RGE_Scenario::active_player_count() {
    int count;
    int player;

    count = 0;
    player = 0;
    do {
        if (Get_player_Active(player) != 0) {
            count = count + 1;
        }
        player = player + 1;
    } while (player < 0x10);
    return count;
}
