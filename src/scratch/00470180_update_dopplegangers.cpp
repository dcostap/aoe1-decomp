class RGE_Doppleganger_Creator_ud {
public:
    void update(void);
};
extern RGE_Doppleganger_Creator_ud* DAT_0062e660;

class RGE_Object_List_ud {
public:
    void poll_objects(void);
};

class RGE_Visible_Map_ud {
public:
    void update_visible(void);
};

class RGE_Player_ud {
public:
    void update_dopplegangers(void);
    char gap_00[0x30];
    RGE_Object_List_ud* doppleganger_list;
    char gap_34[0x0C];
    RGE_Visible_Map_ud* visible_map;
};

void RGE_Player_ud::update_dopplegangers(void) {
    if (DAT_0062e660)
        DAT_0062e660->update();
    this->doppleganger_list->poll_objects();
    this->visible_map->update_visible();
}
