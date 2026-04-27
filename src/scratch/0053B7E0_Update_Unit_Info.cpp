// vis_unit.cpp target: Visible_Unit_Manager::Update_Unit_Info
// initial reconstruction from packet/decompiler for per-player visible unit bitmask update.

extern "C" void* __cdecl calloc(unsigned int count, unsigned int size);
void operator_delete(void* ptr);

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
    unsigned long changed = (old_mask ^ new_mask) & 0xffff;
    if (category < this->Category_Count) {
        int p = 0;
        if (this->Player_Count > 0) {
            int refOffset = 0x194 - (int)refs;
            do {
                if (changed == 0) {
                    return;
                }
                if ((changed & 1) == 1) {
                    VisibleUnitPtr* bucket = &this->PlayerDataPtrs[p][category];
                    if ((new_mask & 1) == 1) {
                        short size = bucket->list_size;
                        if (bucket->used == size) {
                            int sizeInt = size;
                            VisibleUnitRec* newList = (VisibleUnitRec*)calloc(sizeInt + sizeInt, 8);
                            int bytes = sizeInt * 8;
                            char* dst = (char*)newList;
                            char* src = (char*)bucket->unit_list;
                            while (bytes-- != 0) {
                                *dst++ = *src++;
                            }
                            operator_delete(bucket->unit_list);
                            bucket->unit_list = newList;
                            bucket->list_size = (short)(sizeInt + sizeInt);
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
                changed >>= 1;
                p++;
            } while (p < this->Player_Count);
        }
    }
}
