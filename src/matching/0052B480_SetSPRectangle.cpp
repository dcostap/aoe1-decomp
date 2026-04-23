class SP_Victory_Info {
public:
    int ObjType;
    int AllFlag;
    int PlayerID;
    int DestObjID;
    float x1;
    float y1;
    float x2;
    float y2;
    int VictoryType;
    int Amount;
    int AttribType;
    int obj_ID;
    int dest_obj_ID;
    void* obj;
    void* dest_obj;
};

class T_Scenario {
public:
    char gap_0[0x1AA8];
    SP_Victory_Info sp_victory[16][12];
    char gap_1[0x448];
    int which_player;

    void SetSPRectangle(int sp_index, float x1, float y1, float x2, float y2);
};

void T_Scenario::SetSPRectangle(int sp_index, float x1, float y1, float x2, float y2) {
    this->sp_victory[this->which_player][sp_index].x1 = x1;
    this->sp_victory[this->which_player][sp_index].y1 = y1;
    this->sp_victory[this->which_player][sp_index].x2 = x2;
    this->sp_victory[this->which_player][sp_index].y2 = y2;
}
