#ifndef AOE1_TPLAYER_TU_SHARED_CONTEXT
class TRIBE_Player {
public:
    void obj_cost(short param_1, char** param_2, short* param_3, short* param_4, short* param_5, short* param_6, short* param_7, short* param_8, float param_9);
    int objectCostByType(int param_1);
};
#endif

int TRIBE_Player::objectCostByType(int input)
{
    short param_1;
    short inv_3;
    short inv_2;
    short inv_1;
    short local_4;
    short local_2;

    obj_cost((short)input, (char**)0, &local_2, &param_1, &local_4, &inv_2, &inv_1, &inv_3, 1.0f);
    return (int)param_1 + (int)inv_3 + (int)inv_2;
}
