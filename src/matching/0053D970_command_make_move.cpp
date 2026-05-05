extern int allow_user_commands;
extern float FLOAT_005777e8;
extern void* base_game;
class RGE_Base_Game { public: virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0C(); virtual void vf10(int,int); };
class RGE_Game { public:
    virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0C(); virtual void vf10(); virtual void vf14(); virtual void vf18(); virtual void vf1C();
    virtual void vf20(); virtual void vf24(); virtual void vf28(); virtual void vf2C(); virtual void vf30(); virtual void vf34(); virtual void vf38(); virtual void vf3C();
    virtual void vf40(); virtual void vf44(); virtual void vf48(); virtual void vf4C(); virtual void vf50(); virtual void vf54(); virtual void vf58(); virtual void vf5C();
    virtual void vf60(); virtual void vf64(); virtual void vf68(); virtual void vf6C(); virtual void vf70(); virtual void vf74(); virtual void vf78(); virtual void vf7C();
    virtual void vf80(); virtual void vf84(); virtual void vf88(); virtual void vf8C(); virtual void vf90(); virtual void vf94(); virtual void vf98(); virtual void vf9C();
    virtual unsigned char vfA0(int, float, float);
};
class RGE_Diamond_Map_View {
public:
    virtual ~RGE_Diamond_Map_View();
    char gap0[0xF4];
    RGE_Game* gameObj;
    int pick_tile(long a1, long a2, long* out1, long* out2, void* out3);
    int command_make_move(long a1, long a2);
};
int RGE_Diamond_Map_View::command_make_move(long a1, long a2) {
    int result;
    long tile;
    long out2;
    int local_4;
    if (allow_user_commands == 0) return 0;
    result = 0;
    if (this->pick_tile(a1, a2, &a1, &a2, &local_4) != 0) {
        tile = (short)a2;
        float x = (float)tile - FLOAT_005777e8;
        out2 = (short)a1;
        float y = (float)out2 - FLOAT_005777e8;
        result = this->gameObj->vfA0(0, y, x) & 0xff;
    }
    ((RGE_Base_Game*)base_game)->vf10(0, 0);
    return result;
}
