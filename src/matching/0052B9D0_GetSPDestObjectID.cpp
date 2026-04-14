class RGE_Static_Object;

struct SP_Victory_Info {
    int ObjectType;
    int AllFlag;
    int PlayerID;
    int gap_0C[5];
    int VictoryType;
    int Amount;
    int AttribType;
    int Object;
    int DestObjectID;
    int gap_34[2];
};

class T_Scenario {
public:
    virtual RGE_Static_Object* lookup_object(int id);

    char gap_4[0x1AA8 - 4];
    SP_Victory_Info sp_victory[16][12];
    char gap_mid[0x4BF0 - 0x1AA8 - sizeof(SP_Victory_Info) * 16 * 12];
    int which_player;

    RGE_Static_Object* GetSPDestObjectID(int sp_index);
};

RGE_Static_Object* T_Scenario::GetSPDestObjectID(int sp_index) {
    return this->lookup_object(this->sp_victory[this->which_player][sp_index].DestObjectID);
}
