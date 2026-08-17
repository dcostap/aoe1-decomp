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
// - Inventory type dumps confirm VISIBLE_UNIT_REC is five packed bytes after
//   object_id, VISIBLE_UNIT_PTR is 8 bytes, and the manager is 0x24 bytes.
// - Ternary distance clamping recovers the original entry zero register and
//   early guard shape. It is the best current basin at 391 bytes and 290
//   positional mismatches; the statement-form clamp exposes the original
//   parameter-home store but falls to 392 bytes and 308 mismatches.
// - Direct member and pointer-bucket forms, loop-scoped count, typed globals,
//   and direct bound initializers were tested. Several are codegen duplicates.
// - A direct typed PDP[category] traversal and function-scope count are source
//   cleaner but codegen duplicates. A continue-based skip adds a jump and is
//   not retained. Main review made used unsigned because the original masks it
//   to 16 bits. Typed access now preserves zero extension without an overlapping
//   dword read.
// - Revisit probes confirmed that direct distanceTable access, late found
//   initialization, named owner-index locals, and PDP-before-table assignment
//   do not recover the original frame or register topology.
// - A signed short used field emits movsx and worsens the clean frontier.
//   A promoted distance result reduces the mismatch but drops the frame to
//   0x18. An explicit dword-overlap probe improves resynchronization only and
//   remains outside this typed clean source.
// Left in scratch: original zero-register order, PDP/count homes, bucket LEA,
// and inner byte/register topology remain unresolved. The source keeps typed
// record ownership, the explicit clamp, the 0x100 output bound, five global
// output buckets, and two bounded scans.

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
    unsigned short used;
};

extern VisibleUnitRec* VisibleUnitList[5];
extern int VisibleUnitList_Size[5];

class Visible_Unit_Manager {
public:
    VisibleUnitPtr** PlayerDataPtrs;
    VisibleUnitRec* Return_Buffer[5];
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

    int x2 = x + distance;
    int x1 = x - distance;
    int y1 = y - distance;
    int y2 = y + distance;

    do {
        int category = *categories++;
        VisibleUnitRec* rec = PDP[category].unit_list;
        count = PDP[category].used;
        for (; count != 0; count--) {
            int dx;
            int dy;
            if (rec->pos_x <= x2) {
                if (rec->pos_x < x) {
                    if (rec->pos_x < x1) goto next_entry;
                    dx = x - rec->pos_x;
                } else {
                    dx = rec->pos_x - x;
                }
                if (rec->pos_y <= y2) {
                    if (rec->pos_y < y) {
                        if (rec->pos_y < y1) goto next_entry;
                        dy = y - rec->pos_y;
                    } else {
                        dy = rec->pos_y - y;
                    }
                    unsigned char d = distTable[(dx & 0x0f) + ((dy & 0x0f) << 4)];
                    if (d <= distance) {
                        int mapped = player_map[rec->player];
                        int size = VisibleUnitList_Size[mapped];
                        if (size < 0x100) {
                            VisibleUnitRec* out = VisibleUnitList[mapped] + size;
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
        }
        category_count--;
    } while (category_count != 0);

    return found;
}
