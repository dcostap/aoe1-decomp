// VA: 004C8CB0 TRIBE_Building_Object::change_ownership
// t_b_obj.cpp lines 494-546
// Attempt log:
// 1: natural raw-offset source: too short 384 B; base modeled non-polymorphic causing +4 this-adjust and virtual slots shifted.
// 2: move virtual surface to TRIBE_Combat_Object base and fix +1DA field layout: virtual offsets fixed but still 384 B/no local slot.
// 3: volatile sound_off loop variables force stack slot and 416 B, but VC5 chose EBX=4.
// 4: introduce `two` local for state/step: no improvement, EBX still 4.
// 5: move play_sound surface to RGE_Player; size matched but remaining broad drift; before/after owner slots shifted and loop init order off.
// 6: add one combat vtable pad and declare loop index first: exact to loop addressing; first mismatch 0x25 from [eax+ebp] vs original [ebp+eax].
// 7: integer address expressions did not alter base/index order.
// 8: expanded active_counts decrement matched original length and lowered diff to 4.86%; remaining first drift is equivalent base/index encoding in sound loops.
// 9: cast loop offsets to char* before adding info: no change.
// 10: flags /O2 no-/Oy, /Ox unchanged; /O1 too short.
// Accepted-drift suggestion: final mismatch is 21/432 positional, 20/432 edit. Remaining drift is localized equivalent addressing/register allocation: commuted base+index encodings in the two sound loops, a few ecx/edx/eax choices in the queue-count and master-object blocks, and paired branch displacement shifts. Calls, vtable slots, field offsets, predicates, stores, stack cleanup, and side effects match.

#ifndef T_B_OBJ_CONTEXT_H
class RGE_Player {
public:
#define PPAD(n) virtual void p##n();
    PPAD(0) PPAD(1) PPAD(2) PPAD(3) PPAD(4) PPAD(5) PPAD(6) PPAD(7)
    PPAD(8) PPAD(9) PPAD(10) PPAD(11) PPAD(12) PPAD(13) PPAD(14) PPAD(15)
    PPAD(16) PPAD(17) PPAD(18) PPAD(19) PPAD(20) PPAD(21) PPAD(22) PPAD(23)
    PPAD(24) PPAD(25) PPAD(26) PPAD(27) PPAD(28) PPAD(29)
#undef PPAD
    virtual void play_sound(short id, float amount, int zero); // +78
    char gap_04[0x20];
    void** master_objects; // +0x24
    char gap_28[0x22];
    short id; // +0x4A
    char gap_4C[0x1D4];
    void* tech; // +0x220
};

class RGE_Master_Object {
public:
#define MPAD(n) virtual void m##n();
    MPAD(0) MPAD(1) MPAD(2) MPAD(3) MPAD(4) MPAD(5)
#undef MPAD
    virtual void create_object(RGE_Player* player, float x, float y, float z);
};

class RGE_Action_List { public: void delete_list(); };
class TRIBE_Player_Tech { public: unsigned char do_tech(short id); };

class TRIBE_Combat_Object {
public:
#define VPAD(n) virtual void v##n();
    VPAD(0) VPAD(1) VPAD(2) VPAD(3) VPAD(4) VPAD(5) VPAD(6) VPAD(7)
    VPAD(8) VPAD(9) VPAD(10) VPAD(11) VPAD(12) VPAD(13) VPAD(14) VPAD(15)
    VPAD(16) VPAD(17) VPAD(18) VPAD(19) VPAD(20) VPAD(21) VPAD(22) VPAD(23)
    VPAD(24) VPAD(25) VPAD(26) VPAD(27) VPAD(28) VPAD(29)
#undef VPAD
#define VPAD2(n) virtual void w##n();
    VPAD2(0) VPAD2(1) VPAD2(2) VPAD2(3) VPAD2(4) VPAD2(5) VPAD2(6) VPAD2(7)
    VPAD2(8) VPAD2(9) VPAD2(10) VPAD2(11) VPAD2(12) VPAD2(13) VPAD2(14) VPAD2(15)
    VPAD2(16) VPAD2(17) VPAD2(18) VPAD2(19) VPAD2(20) VPAD2(21) VPAD2(22) VPAD2(23)
#undef VPAD2
    virtual void after_owner(RGE_Player* p, int one, int minus_one); // +D8
    virtual void before_owner(RGE_Player* p, int one, int minus_one); // +DC
    void change_ownership(RGE_Player* player);
};

class RGE_Base_Game { public: char gap[0xA34]; int active_counts[16]; };
extern RGE_Base_Game* rge_base_game;

class TRIBE_Building_Object : public TRIBE_Combat_Object {
public:
    char gap_004[4];
    void* obj_info;      // +08
    RGE_Player* owner;   // +0C
    char gap_010[0x28];
    float world_x;       // +38
    float world_y;       // +3C
    float world_z;       // +40
    char gap_044[4];
    unsigned char object_state; // +48
    char gap_049[0x13B];
    RGE_Action_List* action_list; // +184
    char gap_188[0x40];
    void* production_queue; // +1C8
    char gap_1CC[2];
    short field_1CE;
    char gap_1D0[10];
    short need_attr; // +1DA

    void change_ownership(RGE_Player* player);
};
#endif

void TRIBE_Building_Object::change_ownership(RGE_Player* player)
{
    register int two = 2;
    if (this->object_state == two) {
        int i = 0;
        volatile int sound_off = 0x6a;
        int sound_step = two;
        int amount_off = 0x70;
        do {
            int info = (int)this->obj_info;
            if (*(unsigned char*)((char*)i + info + 0x88) >= 4) {
                short id = *(short*)((char*)sound_off + info);
                if (id >= 0) {
                    this->owner->play_sound(id, -*(float*)((char*)amount_off + info), 0);
                }
            }
            amount_off += 4;
            ++i;
            sound_off += sound_step;
        } while (amount_off < 0x7c);
    }

    if (this->object_state == 0) {
        this->before_owner(this->owner, 1, -1);
    }

    if (this->field_1CE > 0) {
        if (this->need_attr == 4) {
            this->need_attr = -1;
            RGE_Player* old_owner = this->owner;
            RGE_Base_Game* game = rge_base_game;
            int id = old_owner->id;
            int* count_ptr = &game->active_counts[id];
            int count_val = *count_ptr;
            count_val--;
            *count_ptr = count_val;
        }
        this->field_1CE = 1;
        *(short*)((char*)this->production_queue + 2) = 1;
    }

    this->action_list->delete_list();
    TRIBE_Combat_Object::change_ownership(player);

    if (this->object_state == 0) {
        this->after_owner(this->owner, 1, -1);
    }

    if (this->object_state == two) {
        short master_id = *(short*)((char*)this->obj_info + 0x172);
        if (master_id > -1) {
            RGE_Player* owner = this->owner;
            RGE_Master_Object* master = (RGE_Master_Object*)owner->master_objects[master_id];
            master->create_object(owner, this->world_x, this->world_y, this->world_z);
        }
        short tech_id = *(short*)((char*)this->obj_info + 0x178);
        if (tech_id > -1) {
            ((TRIBE_Player_Tech*)this->owner->tech)->do_tech(tech_id);
        }
        if (this->object_state == two) {
            int i = 0;
            volatile int sound_off = 0x6a;
            int sound_step = two;
            int amount_off = 0x70;
            do {
                int info = (int)this->obj_info;
                if (*(unsigned char*)((char*)i + info + 0x88) >= 4) {
                    short id = *(short*)((char*)sound_off + info);
                    if (id >= 0) {
                        this->owner->play_sound(id, *(float*)((char*)amount_off + info), 0);
                    }
                }
                amount_off += 4;
                ++i;
                sound_off += sound_step;
            } while (amount_off < 0x7c);
        }
    }
}
