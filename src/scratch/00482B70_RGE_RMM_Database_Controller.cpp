// 00482B70 RGE_RMM_Database_Controller(char*,char*,char*,char*) attempt
// Natural fscanf/calloc constructor based on packet. Broad attempt log:
// - modeled base ctor call, vptr/field initialization, land table and three file passes.
// - first natural compile was .text 1152 vs original 1185; added a temporary unreachable fscanf padding probe only to inspect diff family.
// - with three extra address-taken locals, prologue reached sub esp,34; first mismatch then saved-this home [esp+2c] vs original [esp+24].
// - remaining mismatch is broad (about 74% positional / 54% edit); fscanf argument topology and loop/store offsets need a ground-up rewrite from original stack slots.
// - left in scratch; not an accepted_drift candidate.

extern "C" void* __cdecl fopen(const char*, const char*);
extern "C" int __cdecl fclose(void*);
extern "C" int __cdecl fscanf(void*, const char*, ...);
extern "C" void* __cdecl calloc(unsigned int, unsigned int);

struct ObjectSub { int a[6]; };
struct TerrainTypeSub { int a[11]; };

struct LandEntry {
    int id; unsigned char zone; char pad05[3]; int base_size; int terrain_type; int land_percent; unsigned char placement_type; unsigned char amount_percent; char pad12[2]; int clump; int edge_spacing; int min_placement; unsigned char by_player; unsigned char group; char pad1e[2]; int unk20; int unit_count; ObjectSub* units;
};
struct ObjectGroup { int count; ObjectSub* list; };
struct TerrainGroup { int count; TerrainTypeSub* list; };
struct MapInfo { int id; char pad04[0x24]; int terrain_group_count; ObjectGroup objects; TerrainGroup terrains; };

class RGE_Random_Map_Module { public: RGE_Random_Map_Module(int,int,int); };
class RGE_RMM_Database_Controller: public RGE_Random_Map_Module {
public:
    char gap04[0x4f50];
    int land_count;
    MapInfo* lands;
    RGE_RMM_Database_Controller(char*,char*,char*,char*);
};

RGE_RMM_Database_Controller::RGE_RMM_Database_Controller(char* terrainFile, char* objectFile, char* terrainTypeFile, char* mapFile)
    : RGE_Random_Map_Module(0,0,0)
{
    void* infile;
    int map_id;
    int terrain_num;
    int object_num;
    int temp_terrain_type;
    int land_num;
    int local_30;
    int tmp1,tmp2,tmp3,tmp4;
    int pad_a, pad_b, pad_c;

    *(void**)this = (void*)0x571E88;
    *(int*)((char*)this + 0x30) = 0;
    *(int*)((char*)this + 0x34) = -1;
    *(int*)((char*)this + 0x38) = 0;

    infile = fopen(mapFile, "r");
    map_id = (int)infile;
    if (infile) {
        fscanf(infile, " %d", &this->land_count);
        if (this->land_count > 0) {
            this->lands = (MapInfo*)calloc(this->land_count, 0x48);
            if (this->land_count > 0) {
                int off = 0;
                int i = 0;
                do {
                    fscanf(infile, "%d", (char*)this->lands + off);
                    ++i; off += 0x48;
                } while (i < this->land_count);
            }
        } else {
            this->lands = 0;
        }
        fclose(infile);
    } else {
        this->lands = 0;
        this->land_count = 0;
    }

    if (this->land_count <= 0) {
        this->land_count = 0;
        this->lands = 0;
        return;
    }

    infile = fopen(terrainFile, "r");
    map_id = (int)infile;
    if (infile) {
        fscanf(infile, "%d", &terrain_num);
        land_num = 0;
        if (terrain_num > 0) {
            do {
                fscanf(infile, "%d", &local_30);
                LandEntry* land = (LandEntry*)((char*)this->lands + (local_30 * 9) * 8 + 4);
                int* unit_count = (int*)((char*)land + 0x24);
                fscanf(infile, "%d %d %d %d %d %d %d %d %d", unit_count, &land->id, &land->base_size, &land->terrain_type, &land->land_percent, &land->clump, &land->edge_spacing, &land->min_placement, unit_count);
                if (*unit_count > 0) {
                    land->units = (ObjectSub*)calloc(*unit_count, 0x2c);
                    int k = 0;
                    if (*unit_count > 0) {
                        int off = 0;
                        do {
                            ObjectSub* o = (ObjectSub*)((char*)land->units + off);
                            fscanf(infile, "%d %d %d %d %d %d %d %d %d %d %d", o, (char*)o+8, &tmp1, (char*)o+12, &tmp2, (char*)o+20, &tmp3, (char*)o+24, &tmp4, (char*)o+32, (char*)o+36);
                            ++k;
                            ((char*)land->units)[off+4] = (char)tmp1;
                            ((char*)land->units)[off+0x10] = (char)tmp2;
                            ((char*)land->units)[off+0x11] = (char)tmp3;
                            ((char*)land->units)[off+0x1c] = (char)tmp4;
                            ((char*)land->units)[off+0x1d] = (char)tmp4;
                            *(int*)((char*)land->units + off + 0x28) = 8;
                            off += 0x2c;
                        } while (k < *unit_count);
                    }
                } else land->units = 0;
                ++land_num;
            } while (land_num < terrain_num);
        }
        fclose(infile);
    }

    infile = fopen(objectFile, "r");
    if (infile) {
        fscanf(infile, "%d", &object_num);
        land_num = 0;
        if (object_num > 0) do {
            fscanf(infile, "%d", &local_30);
            ObjectGroup* grp = (ObjectGroup*)((char*)this->lands + (local_30 * 9) * 8 + 0x30);
            fscanf(infile, "%d", &grp->count);
            if (grp->count > 0) {
                grp->list = (ObjectSub*)calloc(grp->count, 0x18);
                int off=0; int k=0;
                do { fscanf(infile, "%d %d %d %d %d", (char*)grp->list+off, (char*)grp->list+off+4, (char*)grp->list+off+8, (char*)grp->list+off+12, (char*)grp->list+off+16); *(int*)((char*)grp->list+off+0x14)=0x14; ++k; off+=0x18; } while(k<grp->count);
            } else grp->list=0;
            ++land_num;
        } while (land_num < object_num);
        fclose(infile);
    }

    infile = fopen(terrainTypeFile, "r");
    if (infile) {
        fscanf(infile, "%d", &temp_terrain_type);
        land_num = 0;
        if (temp_terrain_type > 0) do {
            fscanf(infile, "%d", &local_30);
            TerrainGroup* grp = (TerrainGroup*)((char*)this->lands + (local_30 * 9) * 8 + 0x38);
            fscanf(infile, "%d", &grp->count);
            if (grp->count > 0) {
                grp->list = (TerrainTypeSub*)calloc(grp->count, 0x2c);
                int off=0; int k=0;
                do { fscanf(infile, "%d %d %d %d %d %d %d %d %d %d %d", (char*)grp->list+off, (char*)grp->list+off+4, &tmp1, &tmp2, (char*)grp->list+off+12, (char*)grp->list+off+16, (char*)grp->list+off+20, (char*)grp->list+off+24, (char*)grp->list+off+28, (char*)grp->list+off+32, (char*)grp->list+off+36); ((char*)grp->list)[off+8]=(char)tmp1; ((char*)grp->list)[off+9]=(char)tmp2; ++k; off+=0x2c; } while(k<grp->count);
            } else grp->list=0;
            ++land_num;
        } while(land_num < temp_terrain_type);
        fclose(infile);
    }
}
