// 0052BBC0 T_Scenario::Save_victory_conditions_into_players attempt
// Mirrors packet control flow with raw offsets and member-call surfaces.
// Attempts:
// - first natural source compiled too short (.text 1136 vs original 1185) but matched the opening destroy_all loop and preset blocks closely by structure.
// - corrected victory-mode offset to +0x5140, scenario condition table to +0x1AD0, and preset fields to raw offsets (+1A94/+1A98/+1A9C/+1AA0/+1AA4, score gate +4BE8); this yielded 407 equal leading bytes once temporary padding allowed extraction.
// - temporary unreachable call padding made size comparable but changed frame from original sub esp,10 to sub esp,14; removed for final scratch because it is not a valid drift candidate.
// - remaining work: grow code naturally without changing the 0x10 frame, and model late condition dispatch argument/field layout exactly.

class RGE_Victory_Conditions {
public:
    void destroy_all();
    unsigned char add_explore(int type, int amount, int flag);
    unsigned char add_attributes(int a, int b, int amount, int flag);
    unsigned char add_capture(int a, int objid, int flag);
    unsigned char add_bring(int a, int objid, int x, int y);
    unsigned char add_create(int a, int who, int objid, int x, float y, int z);
    unsigned char add_destroy(int a, int who, int objid);
    unsigned char add_discover(int a, int what);
    unsigned char add_score(int score, int a);
    unsigned char add_time(int time, int a);
};

struct Player { char pad0[0x34]; RGE_Victory_Conditions* victory; };
struct World { char pad0[0x3c]; short player_num; char pad3e[2]; Player** players; };

struct Cond { int kind; int p1; int p2; int p3; int p4; int p5; int p6; int p7; int p8; int p9; int p10; int p11; int p12; int p13; int p14; };

class T_Scenario {
public:
    virtual int get_object_ID(int id);
    char pad04[4]; World* world; char pad0c[0x1A88];
    int score; int kills; int buildings; int razings; int artifacts; int ruins; int discoveries; int exploration; int gold;
    char pad1aac[0x18]; Cond conds[12]; char pad_after[0x33A0]; int victory_mode;
    void SaveAttributesIntoPlayers();
    void Save_victory_conditions_into_players(int save_attrs);
};

void T_Scenario::Save_victory_conditions_into_players(int save_attrs) {
    int local_10;
    int j;
    int i;
    int local_4;
    if (save_attrs) this->SaveAttributesIntoPlayers();

    World* w = this->world;
    int one = 1;
    for (int p = 1; p < (int)w->player_num; ++p) {
        w->players[p]->victory->destroy_all();
        w = this->world;
    }

    if (this->victory_mode == 4) {
        if (*(int*)((char*)this+0x4BE8) != 0) {
            w = this->world;
            for (int p = 1; p < (int)w->player_num; ++p) {
                RGE_Victory_Conditions* vc = w->players[p]->victory;
                if (*(int*)((char*)this+0x1AA0)) vc->add_explore(8, *(int*)((char*)this+0x1AA0), one);
                if (*(int*)((char*)this+0x1A94)) vc->add_attributes(8, 14, *(int*)((char*)this+0x1A94), one);
                if (*(int*)((char*)this+0x1A98)) vc->add_attributes(8, 7, *(int*)((char*)this+0x1A98), one);
                if (*(int*)((char*)this+0x1A9C)) vc->add_attributes(8, 13, *(int*)((char*)this+0x1A9C), 0);
                if (*(int*)((char*)this+0x1AA4)) vc->add_attributes(8, 3, *(int*)((char*)this+0x1AA4), one);
                w = this->world;
            }
            if (*(int*)((char*)this+0x4BE8) != 0) goto after_victory_presets;
        }
        w = this->world;
        for (int p = 1; p < (int)w->player_num; ++p) {
            RGE_Victory_Conditions* vc = w->players[p]->victory;
            if (*(int*)((char*)this+0x1AA0)) vc->add_explore(8, *(int*)((char*)this+0x1AA0), one);
            if (*(int*)((char*)this+0x1A94)) vc->add_attributes(9, 14, *(int*)((char*)this+0x1A94), one);
            if (*(int*)((char*)this+0x1A98)) vc->add_attributes(10, 7, *(int*)((char*)this+0x1A98), one);
            if (*(int*)((char*)this+0x1A9C)) vc->add_attributes(11, 13, *(int*)((char*)this+0x1A9C), 0);
            if (*(int*)((char*)this+0x1AA4)) vc->add_attributes(12, 3, *(int*)((char*)this+0x1AA4), one);
            w = this->world;
        }
    }

after_victory_presets:
    i = 0;
    w = this->world;
    if ((int)w->player_num - 1 <= 0) return;
    int rowoff = 4;
    int player_index_offset = 0x72;
    Cond* cbase = this->conds;
    do {
        Player* player = this->world->players[rowoff/4];
        RGE_Victory_Conditions* vc = player->victory;
        local_10 = 0;
        Cond* c = cbase;
        do {
            int k = c->kind;
            if (k != 0) {
                if (k == 4) {
                    int sub = c->p2;
                    if (sub == 6) { vc->add_explore(1, c->p1, 1); }
                    else if (sub == 4) { vc->add_attributes(1, 11, c->p1, 0); }
                    else if (sub == 3) { vc->add_attributes(1, 0, c->p1, 0); }
                    else if (sub == 2) { vc->add_attributes(1, 2, c->p1, 0); }
                    else if (sub == 1) { vc->add_attributes(1, 1, c->p1, 0); }
                    else if (sub == 0) { vc->add_attributes(1, 3, c->p1, 0); }
                    else if (sub == 5) { vc->add_attributes(1, 6, c->p1, 0); }
                } else if (k == 6) {
                    vc->add_attributes(1, c->p2, c->p1, 0);
                } else if (k == 5) {
                    vc->add_capture(1, this->get_object_ID(c->p3), 1);
                } else if (k == 3) {
                    int id = c->p4;
                    if (this->get_object_ID(id)) vc->add_bring(1, this->get_object_ID(c->p2), this->get_object_ID(c->p3), c->p1);
                    else vc->add_bring(1, this->get_object_ID(c->p2), *(int*)((char*)this + ((i + local_10) * 15) * 4), c->p1);
                } else if (k == 2) {
                    float f = *(float*)&c->p3;
                    if (f > 0.0) vc->add_create(1, c->p7, c->p1, *(int*)((char*)this + ((i + local_10) * 15) * 4), f, c->p4);
                    else vc->add_destroy(1, c->p7, c->p1);
                } else if (k == 7) {
                    vc->add_discover(1, c->p2);
                } else if (k == 1) {
                    if (c->p7 && c->p6) vc->add_score(1, c->p7);
                    else if (c->p5) {
                        if (c->p7) vc->add_time(1, this->world->players[c->p5]->victory ? c->p1 : c->p1);
                        else vc->add_time(1, this->world->players[c->p5]->victory ? (int)this->world->players[c->p5] : 0);
                    } else if (this->get_object_ID(c->p2)) vc->add_time(1, this->get_object_ID(c->p2));
                }
            }
            ++local_10;
            ++c;
        } while (local_10 < 12);
        player_index_offset += 12;
        rowoff += 4;
        ++i;
        w = this->world;
    } while (i < (int)w->player_num - 1);
}
