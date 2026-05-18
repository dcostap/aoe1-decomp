// 0040F530 AIPlay::fillGroups
// aipbook.cpp
// Attempt log:
// try 1: broad reconstruction from packet: bucket input units by type, fill play groups by required unit types, choose best candidates, compute deviation.
// try 2: modeled large local frame as counts[6] plus 6x50 bucket table, initialized counts with zero rep-like loop and ok/minUnits=1.
// try 3: modeled play lookup via world/playbook using status->playId at +0x190 and early return when play is null.
// try 4: modeled input unit bucketing: world->object(id), world->names->typeOf(object), type range 0..5, append id into bucket, else ok=0.
// try 5: modeled first fill pass over play groups and six unit types, using groupRequiredCount/type needs and assigning bucket units with assignUnit(id,group,type).
// try 6: modeled assignment success removing bucket entry (-1) and early filled exit when statusPriority() equals play byte42.
// try 7: modeled second pass over remaining bucket ids for mode4f==1, selecting best group by priority when group demand exceeds current status want.
// try 8: modeled mode4f==2 simpler first-eligible group assignment pass.
// try 9: modeled final deviation calculation over groups/types as positive required-current difference and stored byte at status+0x1C4.
// try 10: fixed compile by adding missing AIPlayStatus method stubs; default compile produced .text 1040B vs original 1150B.
// try 11: /GX probe produced identical 1040B, removed flag file.
// left in scratch: broad behavior is modeled, but exact AIPlay/AIPlayStatus method ownership is wrong (some calls are on status/this/play), bucket table stride/order and group loop topology are incomplete; rebuilt is 110B size-short. No accepted_drift: no localized full diff.

class RGE_Static_Object {};
class NameValue { public: virtual int typeOf(RGE_Static_Object*); };
class World { public: char gap[0xa0]; NameValue* names; RGE_Static_Object* object(int); };
class AIPlayBook { public: char gap[0xa0]; World* world; class AIPlay* play(int); };
class AIPlayStatus { public: char gap0[0x190]; int playId; char gap194[0x1c4-0x194]; unsigned char deviation; int assignUnit(int,int,int); unsigned char statusPriority(); unsigned char statusPriority(int); unsigned char statusWant(int,int); };
class AIPlay {
public:
    char gap0[0x42]; unsigned char byte42; char gap43[0x4f-0x43]; unsigned char mode4f; char gap50[2]; unsigned char groupCount;
    int fillGroups(AIPlayStatus* status, int* unitIds, int unitCount, World* world);
    unsigned char groupRequiredCount(int group);
    unsigned char groupType(int group, int slot);
    unsigned char statusType(int group, int slot);
    unsigned char statusPriority(int group);
    unsigned char statusWant(int group, int slot);
    int assignUnit(int unitId, int group, int slot);
};

int AIPlay::fillGroups(AIPlayStatus* status, int* unitIds, int unitCount, World* world) {
    int counts[6];
    int buckets[6][50];
    int ok = 1;
    int i,j,k,g,slot;
    int deviation = 0;
    AIPlay* play = ((AIPlayBook*)world->names)->play(status->playId);
    if (!play) return 0;
    for (i=0;i<6;i++) counts[i]=0;

    if (unitCount > 0) {
        for (i=0;i<unitCount;i++) {
            RGE_Static_Object* o = world->object(unitIds[i]);
            if (o) {
                int t = world->names->typeOf(o);
                if (t >= 0 && t < 6) {
                    int n = counts[t];
                    buckets[t][n] = unitIds[i];
                    counts[t] = n + 1;
                    continue;
                }
            }
            ok = 0;
        }
    }

    for (g=0; g<play->groupCount; ++g) {
        AIPlay* grp = play;
        if (!grp) return 0;
        for (i=0;i<6;i++) {
            int need = grp->groupRequiredCount(i);
            if (need) {
                int used=0;
                for (j=0; j<counts[i] && used<need; ++j) {
                    int id = buckets[i][j];
                    if (id != -1) {
                        if (status->assignUnit(id,g,i)==1) {
                            ++used;
                            buckets[i][j] = -1;
                            if (status->statusPriority() == grp->byte42) goto filled;
                        } else ok = 0;
                    }
                }
            }
        }
    }

    for (i=0;i<6;i++) {
        for (j=0;j<counts[i];j++) {
            int id = buckets[i][j];
            if (id == -1) continue;
            if (play->mode4f == 1) {
                int best=-1; int bestScore=0;
                for (g=0; g<play->groupCount; ++g) {
                    AIPlay* grp = play;
                    if (grp) {
                        unsigned char want = status->statusWant(g,i);
                        unsigned char have = grp->groupType(g,i);
                        if (have > want) {
                            if (best == -1 || bestScore > status->statusPriority(g)) { best=g; bestScore=status->statusPriority(g); }
                        }
                    }
                }
                if (best != -1) {
                    if (status->assignUnit(id,best,i)==1) { buckets[i][j] = -1; if (status->statusPriority()==play->byte42) goto filled; }
                    else ok = 0;
                }
            } else if (play->mode4f == 2) {
                for (g=0; g<play->groupCount; ++g) {
                    AIPlay* grp = play;
                    if (grp) {
                        if (grp->groupType(g,i) > status->statusWant(g,i)) {
                            if (status->assignUnit(id,g,i)==1) { buckets[i][j] = -1; if (status->statusPriority()==play->byte42) goto filled; }
                            else ok = 0;
                            break;
                        }
                    }
                }
            }
        }
    }
filled:
    for (g=0; g<play->groupCount; ++g) {
        AIPlay* grp = play;
        if (grp) {
            for (i=0;i<6;i++) {
                int a = grp->groupRequiredCount(i);
                int b = status->statusWant(g,i);
                if (a > b) deviation += a - b;
            }
        }
    }
    status->deviation = (unsigned char)deviation;
    return ok;
}
