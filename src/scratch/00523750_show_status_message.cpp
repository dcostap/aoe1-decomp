// quick-win hypothesis: stack buffer + virtual get_string + delegate to the other status-message helper
// if this misses, the first thing to revisit is the local buffer base / argument order, not the call set
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

class TRIBE_Game : public RGE_Base_Game {
public:
    void show_status_message(int string_id, char* param_2, long param_3);
    void show_status_message(char* param_1, char* param_2, long param_3);
};

void TRIBE_Game::show_status_message(int string_id, char* param_2, long param_3) {
    char str[0xFC];
    this->get_string(string_id, str + 4, 0x100);
    this->show_status_message(str + 4, param_2, param_3);
}
