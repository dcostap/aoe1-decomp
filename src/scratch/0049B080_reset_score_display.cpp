// VA: 0049B080 TRIBE_Screen_Game::reset_score_display
// PDB source: scr_game.cpp
// Attempt log:
// - broad reconstruction from packet: build 9 score records, sort by teams/players, update 8 UI rows.
// - fixed initial frame by increasing the sprintf/text buffer to 0x204; prologue now has original sub esp,2D4 but still lacks original early mov ebp,ecx and uses different saved-register roles.
// - tried local self alias and using self-> throughout; VC5 still homes this at [esp+14] instead of keeping it in EBP, no prologue improvement.
// - current best default /O2: 87.98% positional diff, 66.00% edit diff, first mismatch offset 8. Early zero-record loop and broad helper calls are recognizable, but record indexing/register topology diverges heavily.
// - give-up: likely needs exact original ScoreRec/local-frame layout and real TRIBE_Game/RGE_Game surfaces; no accepted_drift proposed due broad unexplained drift and likely behavioral uncertainty in late UI/update calls.

extern void qsort(void* base, unsigned int num, unsigned int width, int (*cmp)(const void*, const void*));
extern void sprintf(char* dst, char* fmt, ...);

#define rge_base_game (*(RGE_Base_Game**)0x62C574)
#define tribe_game (*(TRIBE_Game**)0x62C4C0)
#define score_cmp ((int (*)(const void*, const void*))0x0049B000)

struct ScoreRec { int team_id; int icon_num; int player_id; int player_score; int team_score; };
class RGE_Base_Game { public: int numberPlayers(); int playerID(int); int get_active(); int get_color(int); };
class Victory { public: int get_victory_points(); };
class Player { public: char gap0[0x30]; Victory* victory; char gap34[0x40-0x34]; int list; char gap44[0x80-0x44]; unsigned char type; char gap81[0x104-0x81]; unsigned char active; char gap105[0x108-0x105]; void* civ; int relation(int); };
class World { public: char gap0[0x3c]; short player_num; char gap3e[2]; Player** players; };
class StatusObj { public: int progress(int); };
class TRIBE_Game { public: char gap0[0x14d4]; StatusObj* data14d4; int player_status(int); int score_value(int, int, int); };
class TPanel { public: virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void set_visible(int); char gap[4]; int a; int b; int c; void set_text(int, char*, int, int, int, int, int, int, int, int, int); };
class TRIBE_Screen_Game { public: char gap0[0x448]; int color448; char gap44c[0x58c-0x44c]; TPanel* score_panels[8]; char gap5ac[8]; World* world; void reset_score_display(); };

void TRIBE_Screen_Game::reset_score_display()
{
    ScoreRec s[9];
    char buf[0x204];
    int i;
    int row;
    int n;
    int team;
    int idx;
    int best;
    int color;
    int bg;
    int marker;
    int marker_color;
    int relation;
    TRIBE_Screen_Game* self = this;

    for (i = 0; i < 9; ++i) {
        s[i].team_id = 0; s[i].icon_num = 0; s[i].player_id = 0; s[i].player_score = 0; s[i].team_score = 0;
    }

    n = 0;
    for (i = 1; i <= rge_base_game->numberPlayers(); ++i) {
        int pid = rge_base_game->playerID(i);
        if (pid != 0 && pid < self->world->player_num) {
            if (s[pid].team_id == 0) { ++n; s[pid].team_id = n; }
            s[pid].icon_num = i;
            s[pid].player_id = pid;
            s[pid].player_score = self->world->players[pid]->victory->get_victory_points();
            s[pid].team_score = s[pid].player_score;
            int cnt = 1;
            if (self->world->players[pid]->active) {
                for (int j = 1; j <= rge_base_game->numberPlayers(); ++j) {
                    if (j != i) {
                        int pid2 = rge_base_game->playerID(j);
                        if (pid2 != 0 && pid2 < self->world->player_num) {
                            if (self->world->players[pid]->relation(pid2) == 0 && self->world->players[pid2]->relation(pid) == 0 && self->world->players[pid2]->active) {
                                if (s[pid2].team_id == 0) s[pid2].team_id = s[pid].team_id;
                                s[pid].team_score += self->world->players[pid2]->victory->get_victory_points();
                                ++cnt;
                            }
                        }
                    }
                }
                s[pid].team_score /= cnt;
            }
        }
    }

    qsort(s, rge_base_game->numberPlayers(), sizeof(ScoreRec), score_cmp);

    best = 0;
    if (rge_base_game->get_active()) {
        int bestval = 11;
        ScoreRec* p = &s[0];
        for (i = 0; i < 8; ++i, ++p) {
            if (p->icon_num && tribe_game->player_status(p->team_id) == 2) {
                int val = *(int*)((char*)tribe_game->data14d4 + p->team_id * 4 + 0x1bc);
                int scale;
                if ((unsigned)val > 999) scale = 1;
                else if ((unsigned)val < 10) scale = 100;
                else scale = 1000 / val;
                if (scale < bestval) { best = p->team_id; bestval = scale; }
            }
        }
    }

    ScoreRec* p = &s[0];
    TPanel** panelp = &self->score_panels[0];
    for (row = 0; row < 8; ++row, ++p, ++panelp) {
        TPanel* panel = *panelp;
        if (panel == 0) break;
        if (p->icon_num == 0) {
            panel->set_visible(0);
        } else {
            sprintf(buf, (char*)0x586510, tribe_game->score_value(p->team_id, p->player_score, p->team_score));
            Player* pl = self->world->players[p->icon_num];
            switch (*(short*)((char*)pl->civ + 0x26)) {
            case 0: color = 0xff0000; bg = 0xb3b3b3; break;
            case 1: color = 0x2139c6; bg = 0; break;
            case 2: color = 0xffff; bg = 0; break;
            case 3: color = 0x4f73a3; bg = 0; break;
            case 4: color = 0xf77f3; bg = 0; break;
            case 5: color = 0xc700; bg = 0; break;
            case 6: color = 0x7b90a2; bg = 0; break;
            case 7: color = 0xadad00; bg = 0; break;
            default: color = 0xffffff; bg = 0; break;
            }
            marker = 0;
            if (pl->type == 2 || (rge_base_game->get_active() && (tribe_game->player_status(p->team_id) != 2 && tribe_game->player_status(p->team_id) != 4))) marker = 1;
            relation = rge_base_game->get_color(marker ? 8 : 11);
            bg = marker_color = 0;
            if (rge_base_game->get_active() && tribe_game->player_status(p->team_id) == 2) {
                int progress = tribe_game->data14d4->progress(p->team_id);
                if (p->team_id == best) { marker = 17; marker_color = self->color448; }
                if ((unsigned)progress >= 300) {
                    bg = self->color448; marker = ((unsigned)progress > 1000) ? 20 : 19;
                }
            }
            panel->set_text(5, buf, color, bg, panel->a, panel->b, panel->c, relation, marker, marker_color, marker);
        }
    }
}
