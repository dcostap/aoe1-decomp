// 004E1D10 TribeInformationAIModule::findStagingPoint
// PDB source: taiinfmd.cpp lines 6798-7027.
// PDB module 0x33 gives the parameter names and the complete stack-local list.
// Exact donor 004603B0 proves the typed canLinePath point-reference ABI.
// PDB types prove TRIBE_Player, RGE_Game_World, RGE_Map, and RGE_Tile ownership.
//
// EXACT: Probe 89 first matched all 1219 bytes with all 20 ordered calls.
// The decisive group restored the two bounded scans and the complete score expression.
// Both passability loop conditions include good. This preserves their different failure exits.
// Explicit else-zero penalty arms preserve the two cold zero blocks.
// One sum preserves the EAX score accumulator and output publication order.
// A canLinePath result of one adds stageDistance. The x86 mask includes NOT.
//
// Walkbacks 90-98 kept exact code after removing incidental source scope and alias choices.
// Split pointer initializers, narrow point scopes, for-header indices, and typed tile indexing remained exact.
// The retained form uses direct map roots, narrow scopes, and typed map traversal.

#ifndef TAIINFMD_PREFIX_CONTEXT
#ifndef TAIINFMD_PREFIX_CONTEXT
struct XYPoint { int x; int y; };
struct ObjectMemory {
    int id;
    short type;
    short group;
    unsigned char x;
    unsigned char y;
    unsigned char z;
    unsigned char owner;
    short hitPoints;
    unsigned char gap0E[2];
    int attackAttempts;
    unsigned char kills;
    unsigned char gap15[3];
    float damageCapability;
    float rateOfFire;
    float range;
};

#endif
class RGE_Visible_Map { public: unsigned char get_visible(int x, int y); };
struct RGE_Master_Static_Object;
struct RGE_Player;
struct TDrawArea;
struct RGE_Color_Table;
struct RGE_Action_Object;
class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game(RGE_Master_Static_Object*, RGE_Player*, float, float, float);
    virtual void recycle_out_of_game();
    virtual void draw(TDrawArea*, short, short, RGE_Color_Table*);
    virtual void shadow_draw(TDrawArea*, short, short, unsigned char);
    virtual void normal_draw(TDrawArea*, short, short);
    virtual void draw_front_frame(TDrawArea*, short, short);
    virtual void draw_back_frame(TDrawArea*, short, short);
    virtual void draw_frame(TDrawArea*, short, short);
    virtual unsigned char update();
    virtual void check_damage_sprites();
    virtual void rehook();
    virtual void save(int);
    virtual float teleport(float, float, float);
    virtual void new_sprite(void*);
    virtual void add_overlay_sprite(void*, unsigned char);
    virtual void remove_overlay_sprite(void*);
    virtual void change_ownership(void*);
    virtual void modify(float, unsigned char);
    virtual void modify_delta(float, unsigned char);
    virtual void modify_percent(float, unsigned char);
    virtual void transform(RGE_Master_Static_Object*);
    virtual void copy_obj(RGE_Master_Static_Object*);
    virtual void set_object_state(unsigned char);
    virtual void remove_visible_resource();
    virtual void create_doppleganger_when_dying();
    virtual void destroy_obj();
    virtual void die_die_die();
    virtual void damage(int, void*, float, void*, RGE_Static_Object* = 0);
    virtual float calculateDamage(int, void*, float, void*, RGE_Static_Object* = 0);
    virtual void rotate(long);
    virtual unsigned char can_attack();
    virtual void set_attribute(short, float);
    virtual void set_attribute_amount(float, unsigned char, unsigned char);
    virtual int heal(int, int);
    virtual unsigned char heal(float);
    virtual int canRepair();
    virtual void notify_of_relation(long, unsigned char);
    virtual void do_command(RGE_Static_Object*, float, float, float);
    virtual void move_to(RGE_Static_Object*, float, float, float);
    virtual void work(RGE_Static_Object*, float, float, float);
    virtual void stop();
    virtual void set_attack(RGE_Static_Object*);
    virtual void play_command_sound();
    virtual void play_move_sound();
    virtual void new_angle(float);
    virtual RGE_Static_Object* spawn_death_obj();
    virtual void* get_command_master(RGE_Static_Object*, float, float, float);
    virtual void set_being_worked_on(void*, short, unsigned char);
    virtual void release_being_worked_on(RGE_Static_Object*);
    virtual unsigned char is_moving();
    virtual RGE_Static_Object* get_target_obj();
    virtual void enter_obj(RGE_Static_Object*);
    virtual void exit_obj();
    virtual int explore_terrain(void*, unsigned char, int);
    virtual void unexplore_terrain(void*, unsigned char, int);
    virtual void* get_los_table();
    virtual int inAttackRange(RGE_Static_Object*);
    virtual unsigned char underAttack();
    virtual void setUnderAttack(unsigned char);
    virtual float calc_attack_modifier(RGE_Static_Object*);
    virtual float getSpeed();
    virtual float getAngle();
    virtual float maximumSpeed();
    virtual float rateOfFire();
    virtual float damageCapability(RGE_Static_Object*);
    virtual float damageCapability();
    virtual float weaponRange();
    virtual float minimumWeaponRange();
    virtual int passableTile(float y, float x, int flag); // +114
    virtual unsigned char facetToNextWaypoint();
    virtual int currentTargetID();
    virtual float currentTargetX();
    virtual float currentTargetY();
    virtual float currentTargetZ();
    virtual void setWaitingToMove(unsigned char);
    virtual unsigned char waitingToMove();
    virtual unsigned char actionState();
    virtual unsigned char keepGatheringWhenObjectIsOut(int);
    virtual unsigned char produceWhenKilledBy(int);
    virtual unsigned char useSameZoneDropsite();
    virtual void logDebug(const char*, ...);
    virtual void notify(int, int, int, long, long, long);
    virtual int attack(float, float, float, int);
    virtual int attack(int, int);
    virtual int moveTo(float, float, float, float, int);
    virtual int moveTo(int, float, int);
    virtual int moveTo(int, int);
    virtual int moveAwayFrom(int, int);
    virtual int hunt(int, int);
    virtual int gather(int, int);
    virtual int convert(int, int);
    virtual int repair(int, int);
    virtual int build(int, int);
    virtual int trade(int, int);
    virtual int explore(int, int, int);
    virtual int enter(int, int);
    virtual int unload(int, float, float, float);
    virtual int transport(float, float, float, int);
    virtual int stopAction();
    virtual int pause();
    virtual int canPath(int, float, float*, int, int, int);
    virtual int canPath(void*, float, int, float*, int, int, int);
    virtual int canBidirectionPath(int, int, float, float*, int, int, int);
    virtual int canPathWithObstructions(int, float, float*, int, int, int, void*);
    virtual int canPathWithAdditionalPassability(void*, float, int, float*, int, int, int, int, int);
    virtual int findFirstTerrainAlongExceptionPath(int, float*, float*);
    virtual int canLinePathByInts(int, int, int, int, float, int);
    virtual int canLinePath(const XYPoint& a, const XYPoint& b, float c, XYPoint& d, int e); // +1B0
    int findClosestPointInTerrainType(XYPoint p, XYPoint* out, int type, int terrain, int radius);
    unsigned char lookupZone(int x, int y);
};
class RGE_Game_World;
class TRIBE_Player {
public:
    char gap0[0x38];
    RGE_Visible_Map* visible;
    RGE_Game_World* world;
};
struct RGE_Tile {
    char gap0[5];
    unsigned char terrain;
    char gap6[18];
};
class RGE_Map { public: char gap[0x8D8C]; RGE_Tile** map_row_offset; };
class RGE_Game_World { public: char gap[0x28]; RGE_Map* map; };
class MainDecisionAIModule {
public:
    virtual ~MainDecisionAIModule();
    char gap0[0xEC];
    TRIBE_Player* player;
    RGE_Static_Object* object(int id);
};
class TribeMainDecisionAIModule : public MainDecisionAIModule {
public:
    char gapf4[0x12478];
    TRIBE_Player* aiPlayer;
};
class InfluenceMap { public: int lookupValue(int x, int y); };
extern int debug_rand(char*, int);
extern "C" double sqrt(double);

#ifndef TAIINFMD_PREFIX_CONTEXT
class TribeInformationAIModule {
public:
    virtual ~TribeInformationAIModule();
    char gap[0xFC]; TribeMainDecisionAIModule* md;
    ObjectMemory* objectMemory(int id);
    int isBoat(RGE_Static_Object* obj);
    int setupLOSMap(int owner, int x, int y);
    int setupAttackMap(int owner, int x, int y);
    int mapBound(XYPoint* p);
    int findStagingPoint(XYPoint p, XYPoint& out, int p3, int p4, int targetID, int radius, int objID);
};
#endif

#endif
int TribeInformationAIModule::findStagingPoint(XYPoint startPoint, XYPoint& rPoint,
                                               int useTransport,
                                               int landTerrainRequired,
                                               int targetID, int stageDistance,
                                               int unitID)
{
    ObjectMemory* target;
    RGE_Static_Object* unit;
    target = this->objectMemory(targetID);
    if (!target) return 0;
    unit = this->md->object(unitID);
    if (!unit) return 0;

    int terrainType, terrain;
    if (this->isBoat(unit) == 1 && useTransport == 0) { terrainType = 1; terrain = 0x16; }
    else { terrainType = 2; terrain = 0; }

    XYPoint zoneRefPoint;
    zoneRefPoint.x = startPoint.x; zoneRefPoint.y = startPoint.y;
    unit->findClosestPointInTerrainType(startPoint, &zoneRefPoint, terrainType, terrain, 4);
    unsigned char targetZone = unit->lookupZone(zoneRefPoint.x, zoneRefPoint.y);

    int maxLOSValue = this->setupLOSMap(target->owner, target->x, target->y);
    int maxAttackValue = this->setupAttackMap(target->owner, target->x, target->y);
    XYPoint min, max, targetPoint;
    min.x = (int)target->x - stageDistance; min.y = (int)target->y - stageDistance; this->mapBound(&min);
    max.x = (int)target->x + stageDistance; max.y = (int)target->y + stageDistance; this->mapBound(&max);
    targetPoint.x = target->x; targetPoint.y = target->y; this->mapBound(&targetPoint);

    RGE_Visible_Map* vMap = this->md->player->visible;
    RGE_Map* gMap = this->md->aiPlayer->world->map;
    int bestValue = -1;

    for (int x = min.x; x <= max.x; ++x) {
        for (int y = min.y; y <= max.y; ++y) {
            unsigned char tile = (unsigned char)(gMap->map_row_offset[y][x].terrain & 0x1f);
            vMap->get_visible(x, y);
            if (useTransport == 1) {
                if (tile != 2) continue;
            } else if (landTerrainRequired == 1) {
                if (tile == 1 || tile == 0x16) continue;
            } else if (landTerrainRequired == 0 && tile != 1 && tile != 0x16) {
                continue;
            }
            if (unit->lookupZone(x, y) != targetZone) continue;
            if (useTransport == 1) {
                XYPoint passableMin;
                XYPoint passableMax;
                passableMin.x = x - 2; passableMin.y = y - 2; this->mapBound(&passableMin);
                passableMax.x = x + 2; passableMax.y = y + 2; this->mapBound(&passableMax);
                int good = 1;
                for (int a = passableMin.x; a <= passableMax.x && good; ++a) {
                    for (int b = passableMin.y; b <= passableMax.y && good; ++b) {
                        unsigned char t = (unsigned char)(gMap->map_row_offset[b][a].terrain & 0x1f);
                        if (t != 1 && t != 0x16 && unit->passableTile((float)a, (float)b, 1) == 0) good = 0;
                    }
                }
                if (!good) continue;
            }
            int dx = target->x - x;
            int dy = target->y - y;
            int d2 = dx * dx + dy * dy;
            int dist = (int)sqrt((double)d2);
            int randomization = debug_rand("C:\\msdev\\work\\age1_x1\\taiinfmd.cpp", 0x1b3f) % (stageDistance * 3);
            XYPoint temp;
            XYPoint temp2;
            temp.x = x; temp.y = y;
            // BINARY NOTE: A successful line path adds stageDistance to the score.
            int pathPenalty = unit->canLinePath(temp, targetPoint, 1.0f, temp2, 1) == 1 ? stageDistance : 0;
            int losPenalty;
            int attackPenalty;
            if (maxLOSValue > 0)
                losPenalty = -(losMap->lookupValue(x, y) * stageDistance / maxLOSValue);
            else
                losPenalty = 0;
            if (maxAttackValue > 0)
                attackPenalty = -(attackMap->lookupValue(x, y) * stageDistance / maxAttackValue);
            else
                attackPenalty = 0;
            int v = attackPenalty + losPenalty + pathPenalty + randomization + dist;
            if (bestValue == -1 || bestValue < v) { bestValue = v; rPoint.x = x; rPoint.y = y; }
        }
    }
    return bestValue != -1;
}
