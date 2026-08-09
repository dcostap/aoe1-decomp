// baseline reconstruction: period-plausible visible-map reset and mask update
// probe 2: combine the nonzero mask before the unified-map loop so the row
// counter remains in EBP, matching the binary's single live mask.
// probe 3: put the zero-tile-count assignment in the equality arm so VC5
// emits the original fall-through tail and late total-tile assignment.
// Exact under the default VC5 /O2 /Oy flags; no custom response file.
// Main-agent audit replaced raw vptr storage with canonical world/player
// destructor surfaces; emitted code remains exact.

extern unsigned long* unified_map_offsets[256];
extern void __cdecl log_map_call(int param_1, int param_2, int param_3,
                                 int param_4, int param_5, int param_6,
                                 int param_7, int param_8, int param_9);

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    unsigned long world_time;
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x46];
    short id;
};

class RGE_Map;

class RGE_Visible_Map {
public:
    unsigned char** map_offsets;
    RGE_Game_World* world;
    RGE_Player* player;
    RGE_Map* map;
    unsigned char* visible_map;
    int widthValue;
    int heightValue;
    int numberTilesExploredValue;
    int numberTotalTilesValue;
    unsigned long PlayerVisibleMaskValue;
    unsigned long PlayerVisibleMaskInvertValue;
    unsigned long PlayerExploredMaskValue;
    unsigned long PlayerExploredMaskInvertValue;
    unsigned long input_csum;

    void set_all(unsigned char value);
};

void RGE_Visible_Map::set_all(unsigned char value) {
    log_map_call(this->world->world_time, (int)this->player->id, 5, 0,
                 (unsigned int)value, 0, 0, 0, 0);

    int y = 0;
    if (0 < this->heightValue) {
        do {
            int x = 0;
            if (0 < this->widthValue) {
                do {
                    this->map_offsets[y][x] = value;
                    x = x + 1;
                } while (x < this->widthValue);
            }
            y = y + 1;
        } while (y < this->heightValue);
    }

    if ((value == 0xff) || (value == 0)) {
        unsigned long mask = this->PlayerVisibleMaskInvertValue;
        if (value == 0xff) {
            mask = mask & this->PlayerExploredMaskInvertValue;
        }

        y = 0;
        if (0 < this->heightValue) {
            unsigned long** offsets = unified_map_offsets;
            do {
                int x = 0;
                if (0 < this->widthValue) {
                    do {
                        (*offsets)[x] = (*offsets)[x] & mask;
                        x = x + 1;
                    } while (x < this->widthValue);
                }
                y = y + 1;
                offsets = offsets + 1;
            } while (y < this->heightValue);
        }
    } else {
        unsigned long mask = this->PlayerExploredMaskValue;
        mask = mask | this->PlayerVisibleMaskValue;
        y = 0;
        if (0 < this->heightValue) {
            unsigned long** offsets = unified_map_offsets;
            do {
                int x = 0;
                if (0 < this->widthValue) {
                    do {
                        (*offsets)[x] = (*offsets)[x] | mask;
                        x = x + 1;
                    } while (x < this->widthValue);
                }
                y = y + 1;
                offsets = offsets + 1;
            } while (y < this->heightValue);
        }
    }

    if (value == 0xff) {
        this->numberTilesExploredValue = 0;
    } else {
        this->numberTilesExploredValue = this->numberTotalTilesValue;
    }
}
