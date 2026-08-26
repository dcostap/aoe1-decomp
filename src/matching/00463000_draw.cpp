// RGE_Object_List::draw (00463000)
// PDB source: obj_list.cpp:205-314
// Size: 221 bytes

#ifndef OBJLIST_SHARED_CONTEXT
struct RGE_Game_World {
    unsigned char g0[0x3C];
    short player_num;
    unsigned char _pad0[2];
    struct RGE_Player** players;  // +0x40
    unsigned char g1[0x38];        // +0x44 to +0x7B
    short curr_player;             // +0x7C
};

struct RGE_Player {
    unsigned char g0[0x3C];
    RGE_Game_World* world;        // +0x3C
    unsigned char g1[0x0A];        // +0x40 to +0x49
    short id;                      // +0x4A
    unsigned char g2[0xBC];        // +0x4C to +0x107
    void* color_table;             // +0x108
};

struct MasterObj {
    unsigned char g0[0x65];
    unsigned char fog_flag;        // +0x65
};

struct ObjDrawVT {
    virtual void destroy(int) = 0;
    virtual void recycle_in_to_game(void*, void*, float, float, float) = 0;
    virtual void recycle_out_of_game() = 0;
    virtual void draw(void*,short,short,void*) = 0; // vt[3] at +0x0C
};

struct ObjForDraw : ObjDrawVT {
    long id;                       // +0x04
    MasterObj* master_obj;         // +0x08
    RGE_Player* owner;            // +0x0C
    unsigned char g0[0x38];        // +0x10 to +0x47
    unsigned char object_state;    // +0x48
    unsigned char g1[0x05];        // +0x49 to +0x4D
    unsigned char type;            // +0x4E
    unsigned char g2[0x41];        // +0x4F to +0x8F
    void* ally_color_table;        // +0x90
};

struct RGE_Object_Node {
    ObjForDraw* node;              // +0x00
    RGE_Object_Node* next;         // +0x04
    RGE_Object_Node* prev;         // +0x08
    unsigned char centered;        // +0x0C
};

struct RGE_Object_List {
    char gap_00[4];                // +0x00
    RGE_Object_Node* list;         // +0x04
    short number_of_objects;       // +0x08
    void draw(TDrawArea* param_1, short param_2, short param_3, unsigned char param_4);
};
#endif

void RGE_Object_List::draw(TDrawArea* param_1, short param_2, short param_3, unsigned char param_4)
{
    RGE_Object_Node* p = list;
    if (!p) return;
    do {
#ifdef OBJLIST_SHARED_CONTEXT
        RGE_Object_Draw_View* obj = (RGE_Object_Draw_View*)p->node;
#else
        ObjForDraw* obj = p->node;
#endif
        if (obj) {
            RGE_Player* owner = obj->owner;
            unsigned char should_draw = 1;
            void* color_table = owner->color_table;
            switch (obj->master_obj->fog_flag) {
            case 0:
                if (param_4) should_draw = 0;
                break;
            case 1:
                break;
            case 2:
                if (param_4 && obj->object_state > 2) should_draw = 0;
                break;
            case 3:
                should_draw = 0;
                if (param_4) {
                    RGE_Game_World* w = owner->world;
                    short pid = owner->id;
                    short cp = w->curr_player;
                    RGE_Player* cp_player = w->players[cp];
                    if (*(int*)((unsigned char*)cp_player + pid * 4 + 0xAC)) {
                        color_table = obj->ally_color_table;
                        should_draw = 1;
                    }
                }
                break;
            case 4:
                if (param_4 && number_of_objects > 1) {
                    for (RGE_Object_Node* n = list; n; n = n->next) {
                        if (n->node->type == 0x19) { should_draw = 0; break; }
                    }
                }
                break;
            }
            if (should_draw) {
                obj->draw(param_1, param_2, param_3, color_table);
            }
        }
        p = p->next;
    } while (p);
}
