// 004E39D0 TribeInformationAIModule::artifactToCapture
// Source: taiinfmd.cpp lines 7925-7976
// Prior attempts used raw record pointers and compiler-steering locals.  This
// pass restores the same-TU direct indexed scan used by ruinToCapture.
// Session baseline: the prior living reconstruction was 387 bytes and used
// EBP as this, so it had the wrong loop shape and an unresolved 41-byte gap.
// Probe 2: direct indexed ObjectMemory access, typed RGE_Player visibility,
// and the nested owner/playerVisible gate produced 428 bytes and 82 differing
// bytes.  This established the canonical scan and call topology.
// Probe 3: reversing the product operands was a codegen duplicate.
// Probe 4: naming the converted town-center distance before multiplication
// produced an exact 428-byte match.  No custom flags or inline asm are used.

#ifndef TAIINFMD_PREFIX_CONTEXT
#ifndef TAIINFMD_PREFIX_CONTEXT
typedef unsigned char uchar;

class RGE_Static_Object {
public:
    char gap_00[0x38];
    float world_x;
    float world_y;
    float world_z;
    char gap_44[4];
    unsigned char object_state;
    float distance_to_object(RGE_Static_Object* other);
};

class RGE_Visible_Map {
public:
    unsigned char get_visible(int x, int y);
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void set_game_status(unsigned char);
    virtual void do_resign(int);
    virtual void changeToHumanPlayer();
    virtual void changeToComputerPlayer();
    virtual char* aiStatus(int);
    virtual int playerVisible(int player_id); // vt+18
    char gap_04[0x34];
    RGE_Visible_Map* visible; // +38
};

#endif
class MainDecisionAIModule {
public:
    char gap_00[0xF0];
    RGE_Player* player; // +F0
    RGE_Static_Object* object(int id);
    RGE_Static_Object* object(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9, int p10);
};

struct ObjectMemory {
    int id;
    short type;
    char gap_06[2];
    unsigned char x;
    unsigned char y;
    unsigned char z;
    unsigned char owner;
    char gap_0C[0x18];
};

#ifndef TAIINFMD_PREFIX_CONTEXT
class TribeInformationAIModule {
public:
    char gap_00[0x100];
    MainDecisionAIModule* md;
    char gap_104[0x0C];
    int maxImportantObjectMemory;
    ObjectMemory* importantObjectMemory;

    int numberUnitsWithinXTiles(int player, int x, int y, int tiles);
    ObjectMemory* artifactToCapture(int player);
};
#endif

#endif
ObjectMemory* TribeInformationAIModule::artifactToCapture(int player)
{
    RGE_Static_Object* townCenter;
    ObjectMemory* bestMemory;
    int bestResult;
    int i;
    RGE_Visible_Map* visibleMap;

    townCenter = this->md->object(
        -1, 0x6D, -1, -1, -1, -1, -1, -1, -1, -1);
    bestMemory = 0;
    bestResult = -1;
    i = 0;
    visibleMap = this->md->player->visible;

    if (this->maxImportantObjectMemory > 0) {
        do {
            if (this->importantObjectMemory[i].type == 0x9F) {
                if (player == -1 ||
                    (int)this->importantObjectMemory[i].owner == player) {
                    if (player != -1 ||
                        this->md->player->playerVisible(
                            this->importantObjectMemory[i].owner) != 0) {
                        RGE_Static_Object* artifact = this->md->object(
                            this->importantObjectMemory[i].id);
                        if (artifact != 0 && artifact->object_state <= 2) {
                            int artifactX = (int)artifact->world_x;
                            int artifactY = (int)artifact->world_y;
                            if (visibleMap->get_visible(artifactX, artifactY) != 0) {
                                this->importantObjectMemory[i].x =
                                    (unsigned char)(int)artifact->world_x;
                                this->importantObjectMemory[i].y =
                                    (unsigned char)(int)artifact->world_y;
                                this->importantObjectMemory[i].z =
                                    (unsigned char)(int)artifact->world_z;
                                int result = this->numberUnitsWithinXTiles(
                                    player, artifactX, artifactY, 5);
                                if (townCenter != 0) {
                                    int distance = (int)townCenter->distance_to_object(
                                        artifact);
                                    result = distance * result;
                                }
                                if (bestMemory == 0 || result < bestResult) {
                                    bestResult = result;
                                    bestMemory =
                                        &this->importantObjectMemory[i];
                                }
                            }
                        }
                    }
                }
            }
            i++;
        } while (i < this->maxImportantObjectMemory);
    }
    return bestMemory;
}
