// 004F1E10 TribeTacticalAIModule::taskIdleSoldiers
// taitacmd.cpp
// Attempt log:
// try 1: broad reconstruction from packet: resume from saved group id, walk idle soldier group list, validate states, task/retask by action type.
// try 2: modeled savedGroupId at +0xF80 and initial search through +0x9D8 list against sentinel +0x9D4.
// try 3: modeled TacticalAIGroup::id/type/hasTarget repeated-call style and skip for types 0x6A/0x6B/0x6C plus invalid hasTarget.
// try 4: modeled readyToTask local, canUse(this/player) gate for byte +0x2C8 <= 10, and memberCount/desiredCount comparison.
// try 5: modeled overfull-group leader/target branch only as placeholder because original uses player object lookups and coordinate comparison.
// try 6: modeled zero-count and canUse(player,1) early readyToTask clearing.
// try 7: modeled type 0x66/0x69 and 0x64/0x67 resource/defense target gates, including setMode(0/4) paths.
// try 8: modeled attack-group readiness for 0x65/0x68 through canAttackNow placeholder.
// try 9: modeled no-ready command(...,9,1,0,0) path and ready retask setType for 0x66/0x69->8, 0x64/0x67->2, 0x65/0x68->4, 0x6D->0x13.
// try 10: modeled iteration tail saving next group id and debug_timeGetTime(0x5880C0,0xEA9) time-slice return.
// try 11: default compile produced .text 704B vs original 989B; /GX probe produced identical 704B, removed flag file.
// left in scratch: broad list-walk/tasking control is modeled, but exact overfull-group object lookup/coordinate branch, player submodule calls, and command/set-mode source shape are incomplete; rebuilt is far size-short. No accepted_drift: no localized diff.

class TacticalAIGroup { public:
    TacticalAIGroup* prev; TacticalAIGroup* next;
    int id(); int type(); int memberCount(); int desiredCount(); int leaderId();
    int currentTask(); int targetId(); int hasTarget(); int canUse(void*, int);
    void setMode(int); void setType(int); void command(void*, int, int, int, int);
};
class TribeTacticalAIModule {
public:
    char gap0[0xF0]; void* player;
    char gapF4[0x9D4-0xF4]; TacticalAIGroup sentinel; TacticalAIGroup* head;
    char gap9DC[0xF80-0x9DC]; int savedGroupId;
    void taskIdleSoldiers(unsigned int startTicks, unsigned int maxTicks);
    int findDefenseTarget(); int findAttackTarget(); int findExploreTarget(); int canAttackNow(); int canExploreNow(); int canPatrolNow();
};
extern unsigned long debug_timeGetTime(const char*, int);
extern int roundFloat(float);

void TribeTacticalAIModule::taskIdleSoldiers(unsigned int startTicks, unsigned int maxTicks) {
    TacticalAIGroup* g;
    TacticalAIGroup* end;
    int readyToTask;
    int isGathered;
    int savedThis;
    int savedEnd;

    savedThis = (int)this;
    g = head;
    if (savedGroupId != -1) {
        end = &sentinel;
        if (g != end) {
            while (g) {
                if (g->id() == savedGroupId) break;
                g = g->next;
                if (g == end) break;
            }
        }
        if (g->id() != savedGroupId) g = head;
    }
    end = &sentinel;
    savedEnd = (int)end;
    if (g == end || !g) { savedGroupId = -1; return; }

    while (g != end) {
        if (g->type() == 0x6b || g->type() == 0x6c || g->type() == 0x6a || (g->hasTarget() && g->hasTarget()!=1)) {
            g = g->next;
        } else {
            readyToTask = 1;
            if (*(unsigned char*)((char*)g+0x2c8) <= 10) readyToTask = g->canUse(this,1);
            isGathered = g->memberCount();
            if (isGathered > g->desiredCount()) {
                void* a = 0; void* b = 0;
                int leader = g->leaderId();
                if (a && b) {
                    int c1 = roundFloat(*(float*)((char*)b+0x3c));
                    int c2 = roundFloat(*(float*)((char*)b+0x38));
                    if (((unsigned char)c1) != ((unsigned char)c2)) {
                        g->setMode(g->desiredCount());
                        readyToTask = 0;
                    } else readyToTask = 0;
                } else readyToTask = 0;
            } else if (isGathered == 0) {
                readyToTask = 0;
            } else if (!g->canUse(player,1)) {
                readyToTask = 0;
            } else {
                if ((g->type()==0x66 || g->type()==0x69) && !g->canUse((char*)player+0xcec,0)) readyToTask = 0;
                if (g->type()==0x64 || g->type()==0x67) {
                    if (!findDefenseTarget()) {
                        if (findAttackTarget()==-1 && g->type()==0x64) readyToTask = 0;
                        else g->setMode(0);
                    }
                    if (findDefenseTarget()==4) {
                        if (findExploreTarget()==-1 && g->type()==0x64) readyToTask = 0;
                        else g->setMode(4);
                    }
                } else if ((g->type()==0x65 || g->type()==0x68) && !canAttackNow()) readyToTask = 0;
            }

            if (!readyToTask) {
                if (!isGathered) g->command(this, player ? 9 : 9, 1, 0, 0);
            } else {
                int t = g->type();
                if (t==0x66 || t==0x69) g->setType(8);
                else if (t==0x64 || t==0x67) {
                    if (!canExploreNow() && t==0x67) g->setType(0x69);
                    g->setType(2);
                } else if (t==0x65 || t==0x68) g->setType(4);
                else if (t==0x6d) g->setType(0x13);
            }
            g = g->next;
            savedGroupId = g->id();
            if (debug_timeGetTime((const char*)0x5880C0,0x0EA9) - startTicks >= maxTicks) return;
        }
    }
    savedGroupId = -1;
}
