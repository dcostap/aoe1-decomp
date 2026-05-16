// 00501690 TribeTacticalAIModule::unexploredArea
// Attempt log:
// 1: natural implementation from packet/decompiler, with typed member calls and switch offsets: compile failed due bad field_40 gap.
// 2: fix RGE_Static_Object layout gap: very close structure, first 117 bytes exact; 9.63% edit diff, mostly one-byte branch shifts and tail comparison/return drift.
// 3: change final bestDistance test to == -1.0f with fallback first: worsened edit diff to 22.8%; rolled back.
// 4: restore success-first final branch.
// 5: add 4-byte pad before informationAI so member calls use md+0xCEC instead of md+0xCE8: improved edit diff to 7.31%.
// 6: add field at object+0x44 and pass field_40 to distance_to_position: no change; realized original [ecx+40] is world_z bits, not a separate int.
// 7: use world_z float as third distance argument: tiny improvement; remaining diff mostly branch-distance/tail layout and compare operand order.
// 8: swap lookupZone comparison operands to try original cmp [esp+13],al: improved compare opcode and edit diff to 6.95%.
// 9: reorder distance_to_position signature to x,y,self,z to match original push z; push self; then x/y FPU stores: improved edit diff to 6.77%.
// 10: remaining best version has first 117 bytes exact and correct calls/switch/stack frame; remaining nonzero bytes are branch displacement shifts and small tail scheduling differences from a 1-byte shorter loop/final section, with no known behavior delta. Proposed accepted_drift for review rather than promoting exact.

struct XYPoint { int x; int y; };

class RGE_Static_Object {
public:
    char gap00[0x38];
    float world_x;
    float world_y;
    float world_z;
    int field_40;
    int distance_arg;
    unsigned char currentZone();
    unsigned char lookupZone(int x, int y);
    float distance_to_position(float x, float y, RGE_Static_Object* self, float z);
};

class TribeInformationAIModule {
public:
    int mapXSize();
    int mapYSize();
    int tileUncovered(int x, int y);
    void setTileExplored(int x, int y);
    int unexploredPlayerLocation(int player, XYPoint* out);
};

class MainDecisionAIModule {
public:
    RGE_Static_Object* object(int id);
    RGE_Static_Object* object(int p1,int p2,int p3,int p4,int p5,int p6,int p7,int p8,int p9,int p10);
    char gap04[0xcec-4];
    char info_pad[4];
    TribeInformationAIModule informationAI;
};

class TribeTacticalAIModule {
public:
    char gap00[0xf0];
    MainDecisionAIModule* md;
    int unexploredArea(int player, XYPoint& out);
};

int TribeTacticalAIModule::unexploredArea(int player, XYPoint& out)
{
    RGE_Static_Object* unit = this->md->object(player);
    if (unit == 0) {
        return 0;
    }
    unsigned char unitZone = unit->currentZone();
    RGE_Static_Object* explorer = this->md->object(-1, 0x6d, -1, -1, -1, -1, -1, -1, -1, -1);
    float bestDistance = -1.0f;
    int bestX = -1;
    int bestY = -1;
    if (explorer != 0) {
        int i = 0;
        do {
            out.x = (int)explorer->world_x;
            out.y = (int)explorer->world_y;
            switch (i) {
            case 0: out.x -= 10; out.y -= 10; break;
            case 1: out.y -= 10; break;
            case 2: out.x += 10; out.y -= 10; break;
            case 3: out.x += 10; break;
            case 4: out.x += 10; out.y += 10; break;
            case 5: out.y += 10; break;
            case 6: out.x -= 10; out.y += 10; break;
            case 7: out.x -= 10; break;
            }
            if (out.x >= 0 && out.y >= 0 && out.x < this->md->informationAI.mapXSize() && out.y < this->md->informationAI.mapYSize()) {
                if (this->md->informationAI.tileUncovered(out.x, out.y) != 1 && unitZone == unit->lookupZone(out.x, out.y)) {
                    float d = unit->distance_to_position((float)out.x, (float)out.y, unit, unit->world_z);
                    if (bestDistance == -1.0f || d < bestDistance) {
                        bestDistance = d;
                        bestX = out.x;
                        bestY = out.y;
                    }
                }
            }
            i++;
        } while (i < 8);
    }
    if (bestDistance != -1.0f) {
        out.x = bestX;
        out.y = bestY;
        this->md->informationAI.setTileExplored(bestX, bestY);
        return 1;
    }
    return this->md->informationAI.unexploredPlayerLocation(player, &out) != 0;
}
