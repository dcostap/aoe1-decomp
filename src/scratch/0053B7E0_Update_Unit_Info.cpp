// vis_unit.cpp target: Visible_Unit_Manager::Update_Unit_Info
// initial reconstruction from packet/decompiler for per-player visible unit bitmask update.
// Attempt log:
// - Baseline had exact size/frame but modeled growth cleanup as operator_delete; changing to cdecl free aligned both direct calls.
// - Reversed the mask XOR operands without codegen movement; mutating the incoming old_mask home was binary-backed but entered a smaller/wrong basin when assigned to new_mask and restored only the old-mask-home family.
// - Typed memcpy recovered the original rep movsd/rep movsb copy (and is retained); direct short list_size arithmetic improved the best positional diff to 306 bytes, though the frame remains 0x14 versus 0x10.
// - Hoisting the new-list/old-list pointers was diagnostic only and was rolled back.
// - This session tested a named mask delta, ordered object-base arithmetic,
//   top-tested versus guarded do-loop control flow, and function-scope offset
//   locals; none improved the canonical 306-byte frontier. Volatile pointer
//   diagnostics matched the original frame locally but were rolled back as
//   compiler-steering scaffolding.
// - Typed VUR_Ptrs field trial recovered the 0x10 frame and reduced the size
//   gap to 7 bytes, but positional diff worsened from 306 to 409; restored.
// Left in scratch: broad prologue/stack-home/register coloring and the growth pointer-repair schedule remain; call set, cleanup convention, packed record effects, and copy width are established.

extern "C" void* __cdecl calloc(unsigned int count, unsigned int size);
extern "C" void __cdecl free(void* ptr);
extern "C" void* __cdecl memcpy(void* dst, const void* src, unsigned int size);

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

struct RGE_Static_Object {
    char gap_00[0x194];
};

extern RGE_Static_Object** VIS_UNIT_objectsValue;

class Visible_Unit_Manager {
public:
    VisibleUnitPtr** PlayerDataPtrs;
    void* Return_Buffer[5];
    int Player_Count;
    int Category_Count;
    void* distanceTable;

    void Update_Unit_Info(int object_id, int player, int x, int y, int category, unsigned long old_mask, unsigned long new_mask, VisibleUnitRec** refs);
};

void Visible_Unit_Manager::Update_Unit_Info(int object_id, int player, int x, int y, int category, unsigned long old_mask, unsigned long new_mask, VisibleUnitRec** refs) {
    old_mask = (new_mask ^ old_mask) & 0xffff;
    if (category < this->Category_Count) {
        int p = 0;
        if (this->Player_Count > 0) {
            int refOffset = 0x194 - (int)refs;
            do {
                if (old_mask == 0) {
                    return;
                }
                if ((old_mask & 1) == 1) {
                    VisibleUnitPtr* bucket = &this->PlayerDataPtrs[p][category];
                    if ((new_mask & 1) == 1) {
                        short size = bucket->list_size;
                        if (bucket->used == size) {
                            VisibleUnitRec* newList = (VisibleUnitRec*)calloc(size + size, 8);
                            memcpy(newList, bucket->unit_list, size * 8);
                            free(bucket->unit_list);
                            bucket->unit_list = newList;
                            bucket->list_size = (short)(size + size);
                            int i = 0;
                            if (bucket->used > 0) {
                                VisibleUnitRec* r = newList;
                                do {
                                    RGE_Static_Object* obj = VIS_UNIT_objectsValue[r->object_id];
                                    if (obj != 0) {
                                        *(VisibleUnitRec**)((char*)obj + refOffset + (int)refs) = r;
                                    }
                                    i++;
                                    r++;
                                } while (i < bucket->used);
                            }
                        }
                        int used = bucket->used;
                        VisibleUnitRec* rec = bucket->unit_list + used;
                        rec->distance = 0;
                        rec->object_id = object_id;
                        rec->player = (unsigned char)player;
                        rec->pos_x = (unsigned char)x;
                        rec->pos_y = (unsigned char)y;
                        bucket->used++;
                        *refs = rec;
                    } else {
                        VisibleUnitRec* rec = *refs;
                        VisibleUnitRec* last = bucket->unit_list + bucket->used - 1;
                        if (last != rec) {
                            *rec = *last;
                            RGE_Static_Object* obj = VIS_UNIT_objectsValue[rec->object_id];
                            if (obj != 0) {
                                *(VisibleUnitRec**)((char*)obj + refOffset + (int)refs) = rec;
                            }
                        }
                        *refs = 0;
                        bucket->used--;
                    }
                }
                refs++;
                new_mask >>= 1;
                old_mask >>= 1;
                p++;
            } while (p < this->Player_Count);
        }
    }
}
