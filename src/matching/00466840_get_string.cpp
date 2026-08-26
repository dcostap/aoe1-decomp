#ifndef AOE1_PANEL_CONTEXT_H
class RGE_Base_Game {
public:
    virtual int get_string(int string_id, char* buffer, int length);
};

extern RGE_Base_Game* rge_base_game;

class TPanel {
public:
    int get_string(int string_id, char* buffer, int length);
};

#endif
int TPanel::get_string(int string_id, char* buffer, int length) {
    rge_base_game->get_string(string_id, buffer, length);
    return buffer[0] != 0;
}
