extern float g_attack_modifier;

class RGE_Base_Game {
public:
    float calc_attack_modifier(int unused);
};

float RGE_Base_Game::calc_attack_modifier(int unused) {
    return g_attack_modifier;
}
