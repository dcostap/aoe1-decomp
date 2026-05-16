// VA: 005131C0 TRIBE_Player::interface_item_avail
// Attempt log:
// v1 natural implementation with helper: compiled main 544B vs 804B, helper not inlined enough.
// v2 duplicate fill code inline like original: /O2 grew to 704B but still undersized vs 804B.
// v3 /GX: no change/benefit, still 704B; rolled back flag.
// v4 /Od: same-size 804B but EBP-frame debug family and 94.9005% positional, rolled back flag.
// v5 kept v2: it models count pass, special 0x76/0x6d extra item, free/calloc, item fill, obj_cost, help message/page.
// scratch give-up: remaining gap is broad source-shape/local-layout mismatch; likely needs exact original variable topology for obj_cost out-params and duplicated item-fill scheduling, not accepted-drift-safe.

extern "C" void* __cdecl calloc(unsigned int, unsigned int);
extern "C" void __cdecl free(void*);
extern float DAT_00576828;

class RGE_Master_Static_Object {
public:
    char gap_00[4]; unsigned char type; char gap_05[3]; char* name; char gap_0c[0x40]; short pict; char gap_4e[4]; unsigned char available; char gap_53[0x109]; short interface_group;
    long get_help_message(); long get_help_page();
};
struct ObjNodeData { char gap_00[0x10]; short id; };
struct ObjNode { ObjNodeData* data; ObjNode* next; };
struct ListHead { ObjNode* head; ObjNode* first; };
struct PlayerData { char gap_00[0xc0]; float civ_points; };
struct Item_Avail { char* name; short id; short pict; short inv1; float amt1; short inv2; float amt2; short inv3; float amt3; long help_message; long help_page; };

class TRIBE_Player {
public:
    char gap_00[0x22]; short master_count; RGE_Master_Static_Object** masters; ListHead* object_list; char gap_2c[0x24]; PlayerData* data;
    void obj_cost(short, char**, short*, short*, short*, short*, short*, short*, short*, float);
    void interface_item_avail(Item_Avail**, short*, short);
};

void TRIBE_Player::interface_item_avail(Item_Avail** out, short* count_out, short group)
{
    short count = 0;
    int add_extra = 0;
    short inv1, amt1, inv2, amt2, inv3, amt3, tribe, amt_tribe;

    if (this->master_count > 0) {
        RGE_Master_Static_Object** pp = this->masters;
        int n = this->master_count;
        do {
            RGE_Master_Static_Object* m = *pp;
            if (m != 0 && m->type >= 0x46 && m->available != 0 && m->interface_group == group) count++;
            pp++;
            n--;
        } while (n != 0);
    }

    if (group == 0x76 && this->data->civ_points == DAT_00576828 && this->masters[0x6d]->available == 0) {
        add_extra = 1;
        ObjNode* node = this->object_list->first;
        while (node != 0) {
            if (node->data->id == 0x6d) add_extra = 0;
            node = node->next;
        }
    }
    if (add_extra != 0) count++;

    if (*out != 0) { free(*out); *out = 0; }
    *count_out = count;
    if (count == 0) return;
    *out = (Item_Avail*)calloc((int)count, 0x28);

    short out_i = 0;
    int idx = 0;
    if (this->master_count > 0) {
        do {
            RGE_Master_Static_Object* m = this->masters[(short)idx];
            if (m != 0 && m->type >= 0x46 && m->available != 0 && m->interface_group == group) {
                int off = (int)out_i * 0x28;
                Item_Avail* item = (Item_Avail*)((char*)*out + off);
                item->id = (short)idx;
                item->pict = m->pict;
                item->name = m->name;
                this->obj_cost((short)idx, 0, &inv1, &amt1, &inv2, &amt2, &inv3, &amt3, &amt_tribe, 1.0f);
                item->inv1 = inv1;
                item->amt1 = (float)(int)amt1;
                item->inv2 = inv2;
                item->amt2 = (float)(int)amt2;
                item->inv3 = inv3;
                item->amt3 = (float)(int)amt3;
                item->help_message = m->get_help_message();
                item->help_page = m->get_help_page();
                out_i++;
            }
            idx++;
        } while ((short)idx < this->master_count);
    }

    if (add_extra != 0) {
        int off = (int)out_i * 0x28;
        Item_Avail* item = (Item_Avail*)((char*)*out + off);
        RGE_Master_Static_Object* m = this->masters[0x6d];
        item->id = 0x6d;
        item->pict = m->pict;
        item->name = m->name;
        this->obj_cost(0x6d, 0, &inv1, &amt1, &inv2, &amt2, &inv3, &amt3, &amt_tribe, 1.0f);
        item->inv1 = inv1;
        item->amt1 = (float)(int)amt1;
        item->inv2 = inv2;
        item->amt2 = (float)(int)amt2;
        item->inv3 = inv3;
        item->amt3 = (float)(int)amt3;
        item->help_message = m->get_help_message();
        item->help_page = m->get_help_page();
    }
}
