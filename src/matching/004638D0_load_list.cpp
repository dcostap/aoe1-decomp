class RGE_Game_World;

extern void rge_read(int param_1, void* param_2, int param_3);

class RGE_Object_List {
public:
    virtual void load(unsigned char param_1, int param_2, RGE_Game_World* param_3);
    void invert(void);
    void load_list(int param_1, RGE_Game_World* param_2);
};

void RGE_Object_List::load_list(int param_1, RGE_Game_World* param_2) {
    unsigned char param_3;

    while (1) {
        rge_read(param_1, &param_3, 1);
        if (param_3 == 0) {
            break;
        }
        this->load(param_3, param_1, param_2);
    }
    this->invert();
}
