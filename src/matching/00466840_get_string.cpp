class RGE_Base_Game {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual void vf18(void);
    virtual void vf1C(void);
    virtual int get_string(int string_id, char* buffer, int length);
};

extern RGE_Base_Game* rge_base_game;

class TPanel {
public:
    int get_string(int string_id, char* buffer, int length);
};

int TPanel::get_string(int string_id, char* buffer, int length) {
    rge_base_game->get_string(string_id, buffer, length);
    return buffer[0] != 0;
}
