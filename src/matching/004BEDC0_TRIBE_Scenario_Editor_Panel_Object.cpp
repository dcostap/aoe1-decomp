class TDrawArea;
class TPanel;
class TShape;
class TRIBE_Player;
class RGE_Master_Static_Object;

class TRIBE_Panel_Object {
public:
    char gap_00[0x214];

    TRIBE_Panel_Object(TDrawArea* draw_area, TPanel* panel, void* unk, long a4, long a5, TShape* shape, TShape** shape_list, TRIBE_Player* player);
};

class TRIBE_Scenario_Editor_Panel_Object : public TRIBE_Panel_Object {
public:
    RGE_Master_Static_Object* master_game_obj;
    int master_culture_id;

    TRIBE_Scenario_Editor_Panel_Object(TDrawArea* draw_area, TPanel* panel, void* unk, long a4, long a5, TShape* shape, TShape** shape_list, TRIBE_Player* player);
};

TRIBE_Scenario_Editor_Panel_Object::TRIBE_Scenario_Editor_Panel_Object(TDrawArea* draw_area, TPanel* panel, void* unk, long a4, long a5, TShape* shape, TShape** shape_list, TRIBE_Player* player)
    : TRIBE_Panel_Object(draw_area, panel, unk, a4, a5, shape, shape_list, player) {
    *(void**)this = (void*)0x574440;
    this->master_game_obj = 0;
    this->master_culture_id = 0;
}
