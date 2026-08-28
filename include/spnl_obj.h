#ifndef AOE1_SPNL_OBJ_H
#define AOE1_SPNL_OBJ_H

// PDB source module: C:\msdev\work\age1_x1\spnl_obj.cpp.
// This header owns only the scenario-editor panel extension.
#include "tpnl_obj.h"

class RGE_Master_Static_Object;

class TRIBE_Scenario_Editor_Panel_Object : public TRIBE_Panel_Object {
public:
    virtual ~TRIBE_Scenario_Editor_Panel_Object();
    TRIBE_Scenario_Editor_Panel_Object(TDrawArea*, TPanel*, void*, long, long,
                                       TShape*, TShape**, TRIBE_Player*);

    virtual void draw();
    virtual void draw_item(int, int, ValueType, int, int);
    virtual long mouse_left_up_action(long, long, int, int);

    void set_master_info(RGE_Master_Static_Object*, TRIBE_Player*);
    long get_pierce_armor();

    RGE_Master_Static_Object* master_game_obj;
    int master_culture_id;
};

typedef char spnl_obj_panel_size_check[
    (sizeof(TRIBE_Scenario_Editor_Panel_Object) == 0x21C) ? 1 : -1];

#endif  // AOE1_SPNL_OBJ_H
