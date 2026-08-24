extern float g_attack_modifier;

#ifndef RGE_COM_OBJ_SHARED_CONTEXT
class RGE_Base_Game {
public:
    float calc_attack_modifier(int unused);
};
#endif

float RGE_Base_Game::calc_attack_modifier(int unused) {
    return g_attack_modifier;
}
