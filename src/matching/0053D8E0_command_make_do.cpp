extern int allow_user_commands;
extern float FLOAT_005777e8;
int RGE_Diamond_Map_View::command_make_do(long a1, long a2) {
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
        result = this->player->command_make_do(0, y, x) & 0xff;
    }
    return result;
}
