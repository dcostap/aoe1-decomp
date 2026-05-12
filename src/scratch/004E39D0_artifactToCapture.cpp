// 004E39D0 TribeInformationAIModule::artifactToCapture
// Source: taiinfmd.cpp lines 7925-7976
// attempt 1: natural source from packet/decompiler with local layout; wrong register coloring (EBP=this) and frame 0x1C.
// attempt 2: model md->field_F0 owner/check object separately from visible_map at +0x38; frame size fixed to 0x18 but rebuilt still 400B vs original 428B.
// attempt 3: introduced self local to encourage ESI=this; VC5 chose EBP=this and ESI=offset, still short.
// attempt 4: register offset before self; added stack spill and worsened prologue.
// attempt 5: removed self and kept register offset; this colored as EBP and offset as ESI, still not original.
// attempt 6: array indexing importantObjectMemory[i+1] instead of byte offset; worsened to EBX=this and extra saved regs.
// attempt 7: register self plus explicit offset; no change, still EBP=this/ESI=offset.
// attempt 8: volatile vMap local to preserve unused zero local; no codegen/size change.
// attempt 9: volatile parameter to force redundant player reload/compare; no codegen/size change.
// attempt 10: diagnostic /Od compile produced 428B but broad mismatch from offset 0; reverted flags.
// Left in scratch: behavior modeled, but optimized VC5 register coloring/loop topology remains wrong (original ESI=this, EBP=byte offset; rebuilt tends EBP=this or EBX=this and emits a 400B function). Not accepted_drift.

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

class PlayerVisibility {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual int playerVisible(int player_id); // vt+18
    char gap_04[0x34];
    RGE_Visible_Map* visible_map; // +38
};

class MainDecisionAIModule {
public:
    char gap_00[0xF0];
    PlayerVisibility* visibility; // +F0
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

ObjectMemory* TribeInformationAIModule::artifactToCapture(int player)
{
    register TribeInformationAIModule* self = this;
    register int offset = 0;
    RGE_Static_Object* townCenter = self->md->object(-1, 0x6d, -1, -1, -1, -1, -1, -1, -1, -1);
    PlayerVisibility* visibility = self->md->visibility;
    int i = -1;
    ObjectMemory* bestMem = 0;
    RGE_Visible_Map* vMap = 0;
    int bestScore = (int)visibility->visible_map;

    if (self->maxImportantObjectMemory > 0) {
        do {
            ObjectMemory* mem = (ObjectMemory*)((char*)self->importantObjectMemory + offset);
            if (mem->type == 0x9f) {
                if (player != -1) {
                    int owner = mem->owner;
                    if (owner != player) {
                        goto next;
                    }
                    if (player != -1) {
                        goto matching_player;
                    }
                }
                if (!self->md->visibility->playerVisible(mem->owner)) {
                    goto next;
                }

matching_player:
                RGE_Static_Object* artifact = self->md->object(mem->id);
                if (artifact != 0 && artifact->object_state <= 2) {
                    int artifactX = (int)artifact->world_x;
                    int artifactY = (int)artifact->world_y;
                    if (((RGE_Visible_Map*)bestScore)->get_visible(artifactX, artifactY)) {
                        mem->x = (unsigned char)(int)artifact->world_x;
                        mem->y = (unsigned char)(int)artifact->world_y;
                        mem->z = (unsigned char)(int)artifact->world_z;
                        int score = self->numberUnitsWithinXTiles(player, artifactX, artifactY, 5);
                        if (townCenter != 0) {
                            score = (int)townCenter->distance_to_object(artifact) * score;
                        }
                        if (bestMem == 0 || score < bestScore) {
                            bestScore = score;
                            bestMem = mem;
                        }
                    }
                }
            }
next:
            i++;
            offset += 0x24;
        } while (i < self->maxImportantObjectMemory - 1);
    }
    return bestMem;
}
