// vis_unit.cpp target: Visible_Unit_Manager::GetVisibleUnits
// initial reconstruction from packet; scans requested categories for unit records within distance table radius.
// FLAGS: config\flags\0053B9A0_GetVisibleUnits.rsp
// Attempt log:
// - Baseline was structurally close in CFG but 26 bytes long; explicit five-field output stores were the main size drift.
// - A typed eight-byte record assignment followed by the binary-observed distance-byte overwrite reduced the size gap to 6 bytes.
// - Promoting the distance-table byte to the natural promoted int preserved the EAX/EDX carry into the output path and reduced the rebuilt size to 383 bytes (best positional diff 320).
// - Function-scope count/bucket/record locals, address-taking the threshold parameter, separate zero local, and output-global void* donor spelling did not change the best emitted code; no artificial volatility or raw aliasing retained.
// Left in scratch: structural frame/prologue and duplicated inner-save topology remain broad; original repeatedly reloads distance from its parameter home and uses an independent count slot, while VC5 keeps a register threshold and 0x18 frame.

struct VisibleUnitRec {
    int object_id;
    unsigned char distance;
    unsigned char player;
    unsigned char pos_x;
    unsigned char pos_y;
};

struct VisibleUnitPtr {
    VisibleUnitRec* unit_list;
    short list_size;
    short used;
};

extern void* VisibleUnitList[5];
extern int VisibleUnitList_Size[5];

class Visible_Unit_Manager {
public:
    VisibleUnitPtr** PlayerDataPtrs;
    void* Return_Buffer[5];
    int Player_Count;
    int Category_Count;
    unsigned char* distanceTable;

    int GetVisibleUnits(int x, int y, int distance, int player, int* categories, int category_count, int* player_map);
};

int Visible_Unit_Manager::GetVisibleUnits(int x, int y, int distance, int player, int* categories, int category_count, int* player_map) {
    int found = 0;
    int count;
    VisibleUnitPtr* bucket;
    VisibleUnitRec* rec;
    if (category_count <= 0) {
        return 0;
    }
    if (player >= this->Player_Count) {
        return 0;
    }
    if (distance > 0x0f) {
        distance = 0x0f;
    }

    VisibleUnitPtr* playerData = this->PlayerDataPtrs[player];
    unsigned char* distTable = this->distanceTable;
    VisibleUnitList_Size[0] = 0;
    VisibleUnitList_Size[1] = 0;
    VisibleUnitList_Size[2] = 0;
    VisibleUnitList_Size[3] = 0;
    VisibleUnitList_Size[4] = 0;

    int x2 = x + distance;
    int x1 = x - distance;
    int y1 = y - distance;
    int y2 = y + distance;

    do {
        int category = *categories;
        categories++;
        bucket = &playerData[category];
        rec = bucket->unit_list;
        count = *(int*)&bucket->used & 0xffff;
        while (count != 0) {
            int dx;
            int dy;
            int rx = rec->pos_x;
            if (rx <= x2) {
                if (rx < x) {
                    if (rx < x1) goto next_entry;
                    dx = x - rx;
                } else {
                    dx = rx - x;
                }
                rx = rec->pos_y;
                if (rx <= y2) {
                    if (rx < y) {
                        if (rx < y1) goto next_entry;
                        dy = y - rx;
                    } else {
                        dy = rx - y;
                    }
                    int d = distTable[(dx & 0x0f) + ((dy & 0x0f) << 4)];
                    if (d <= distance) {
                        int mapped = player_map[rec->player];
                        int size = VisibleUnitList_Size[mapped];
                        if (size < 0x100) {
                            VisibleUnitRec* out = (VisibleUnitRec*)VisibleUnitList[mapped] + size;
                            VisibleUnitList_Size[mapped] = size + 1;
                            *out = *rec;
                            out->distance = d;
                            found++;
                        }
                    }
                }
            }
next_entry:
            rec++;
            count--;
        }
        category_count--;
    } while (category_count != 0);

    return found;
}
