// vis_unit.cpp target: Visible_Unit_Manager::GetVisibleUnits
// initial reconstruction from packet; scans requested categories for unit records within distance table radius.
// FLAGS: config\flags\0053B9A0_GetVisibleUnits.rsp
// Attempt log:
// - Baseline was structurally close in CFG but 26 bytes long; explicit five-field output stores were the main size drift.
// - A typed eight-byte record assignment followed by the binary-observed distance-byte overwrite reduced the size gap to 6 bytes.
// - Promoting the distance-table byte to the natural promoted int preserved the EAX/EDX carry into the output path and reduced the rebuilt size to 383 bytes (best positional diff 320).
// - Function-scope PDP/distance locals, shared-coordinate compound bounds,
//   bucket references, and the proven dword-overlapping used-field read were
//   retained as the cleanest ownership model; the best ordinary source emits
//   382 bytes with a 317-byte positional diff.
// - Volatile-pointer diagnostics improved emitted metrics locally (313 bytes)
//   but were rolled back as compiler-steering scaffolding; they did not recover
//   the original frame or local homes.
// - A natural inner for-loop post-expression produced identical code; restored
//   the while form and left the structural frame gap unchanged.
// - Restoring the natural unsigned-byte distance result recovered the original
//   0x1c frame and improved the positional diff to 308 with 50.26% resync
//   similarity; VC5 still spills the byte at -0x1c and emits five extra bytes.
// - Unsigned count spelling and implicit byte promotion were codegen duplicates.
// - A natural pre-decrement outer category loop was tested against the original
//   direct parameter-home decrement; VC5 retained the same load/decrement/store.
// - Reordering y2 before y1 was tested against the proven stack homes; VC5
//   emitted the same code, so both structural leads were rolled back.
// Left in scratch: original prologue zero-register order, PDP/count stack homes,
// and duplicated inner-save topology remain unresolved; the current source is
// the clean typed byte-distance reconstruction, not a compiler-steering variant.

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
    unsigned int count;
    unsigned char* distTable;
    VisibleUnitPtr* PDP;
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

    distTable = this->distanceTable;
    PDP = this->PlayerDataPtrs[player];
    VisibleUnitList_Size[0] = 0;
    VisibleUnitList_Size[1] = 0;
    VisibleUnitList_Size[2] = 0;
    VisibleUnitList_Size[3] = 0;
    VisibleUnitList_Size[4] = 0;

    int x2 = x;
    int x1 = x;
    x2 += distance;
    x1 -= distance;
    int y1 = y;
    int y2 = y;
    y1 -= distance;
    y2 += distance;

    do {
        int category = *categories;
        categories++;
        VisibleUnitPtr& bucket = PDP[category];
        rec = bucket.unit_list;
        count = *(int*)&bucket.used & 0xffff;
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
                    unsigned char d = distTable[(dx & 0x0f) + ((dy & 0x0f) << 4)];
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
