// 00441BB0 RGE_Doppleganger_Object::recycle_in_to_game
// PDB: dpl_obj.cpp:166-235, 384 bytes
// __thiscall, void, ret 0x18
// FLAGS: default
//
// Attempt log:
// v0: initial — wrong register allocation (no ebp, edi used for param_6, 58.8% diff)
// v1: fixed prologue — avoid keeping param_6 in callee-saved reg; prologue matches (7.3% diff)
// v2: using void* mapAddr intermediate to force stores after ftol; 0.5% diff (2 bytes)
// v3-v9: various register/scheduling tweaks — stable 2-byte diff is register choice
//
// ACCEPTED_DRIFT: remaining 2 bytes = lea edx vs lea eax for MapAddress computation.
// Original: lea edx,[ecx+eax*4] / mov [esi+9Ch],edx
// Rebuilt:  lea eax,[ecx+eax*4] / mov [esi+9Ch],eax
// Benign register allocation difference — eax immediately overwritten by mov al,[edi+48h]
// in both versions. Rest of function (86 trailing bytes) is byte-identical,
// including all branch targets, epilogues, register saves/restores, and virtual calls.
// 382/384 bytes match (99.48%), no behavioral difference.

extern "C" int __cdecl __ftol();

struct RGE_Active_Sprite_Node;
struct RGE_Active_Sprite_List;

struct RGE_Active_Sprite_List {
    void* vtable_ptr;
    RGE_Active_Sprite_Node* list;
    void* owner;

    RGE_Active_Sprite_Node* copy_sprite_list();
    void use_sprite_list(RGE_Active_Sprite_Node* list);
};

// VirtualHelper for vtable calls: destroy_obj at +0x68, validate at +0x1F0
struct VirtualHelper {
    virtual void _v00();
    virtual void _v04();
    virtual void _v08();
    virtual void _v0C();
    virtual void _v10();
    virtual void _v14();
    virtual void _v18();
    virtual void _v1C();
    virtual void _v20();
    virtual void _v24();
    virtual void _v28();
    virtual void _v2C();
    virtual void _v30();
    virtual void _v34();
    virtual void _v38();
    virtual void _v3C();
    virtual void _v40();
    virtual void _v44();
    virtual void _v48();
    virtual void _v4C();
    virtual void _v50();
    virtual void _v54();
    virtual void _v58();
    virtual void _v5C();
    virtual void _v60();
    virtual void _v64();
    virtual void destroy_obj();     // +0x68 (slot 26)
    virtual void _v6C();
    virtual void _v70();
    virtual void _v74();
    virtual void _v78();
    virtual void _v7C();
    virtual void _v80();
    virtual void _v84();
    virtual void _v88();
    virtual void _v8C();
    virtual void _v90();
    virtual void _v94();
    virtual void _v98();
    virtual void _v9C();
    virtual void _vA0();
    virtual void _vA4();
    virtual void _vA8();
    virtual void _vAC();
    virtual void _vB0();
    virtual void _vB4();
    virtual void _vB8();
    virtual void _vBC();
    virtual void _vC0();
    virtual void _vC4();
    virtual void _vC8();
    virtual void _vCC();
    virtual void _vD0();
    virtual void _vD4();
    virtual void _vD8();
    virtual void _vDC();
    virtual void _vE0();
    virtual void _vE4();
    virtual void _vE8();
    virtual void _vEC();
    virtual void _vF0();
    virtual void _vF4();
    virtual void _vF8();
    virtual void _vFC();
    virtual void _v100();
    virtual void _v104();
    virtual void _v108();
    virtual void _v10C();
    virtual void _v110();
    virtual void _v114();
    virtual void _v118();
    virtual void _v11C();
    virtual void _v120();
    virtual void _v124();
    virtual void _v128();
    virtual void _v12C();
    virtual void _v130();
    virtual void _v134();
    virtual void _v138();
    virtual void _v13C();
    virtual void _v140();
    virtual void _v144();
    virtual void _v148();
    virtual void _v14C();
    virtual void _v150();
    virtual void _v154();
    virtual void _v158();
    virtual void _v15C();
    virtual void _v160();
    virtual void _v164();
    virtual void _v168();
    virtual void _v16C();
    virtual void _v170();
    virtual void _v174();
    virtual void _v178();
    virtual void _v17C();
    virtual void _v180();
    virtual void _v184();
    virtual void _v188();
    virtual void _v18C();
    virtual void _v190();
    virtual void _v194();
    virtual void _v198();
    virtual void _v19C();
    virtual void _v1A0();
    virtual void _v1A4();
    virtual void _v1A8();
    virtual void _v1AC();
    virtual void _v1B0();
    virtual void _v1B4();
    virtual void _v1B8();
    virtual void _v1BC();
    virtual void _v1C0();
    virtual void _v1C4();
    virtual void _v1C8();
    virtual void _v1CC();
    virtual void _v1D0();
    virtual void _v1D4();
    virtual void _v1D8();
    virtual void _v1DC();
    virtual void _v1E0();
    virtual void _v1E4();
    virtual void _v1E8();
    virtual void _v1EC();
    virtual void validate();        // +0x1F0 (slot 124)
};

extern unsigned long* unified_map_offsets[];

class RGE_Master_Static_Object;
class RGE_Player;
class RGE_Static_Object;
class RGE_Animated_Object;

class RGE_Static_Object {
public:
    virtual void recycle_in_to_game(RGE_Master_Static_Object* master, RGE_Player* player, float x, float y, float z);
};

class RGE_Animated_Object : public RGE_Static_Object {
public:
    char gap_00[0x84];
    float speed;

    void recycle_in_to_game(RGE_Master_Static_Object* master, RGE_Player* player, float x, float y, float z);
};

class RGE_Doppleganger_Object : public RGE_Animated_Object {
public:
    void recycle_in_to_game(RGE_Master_Static_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5, RGE_Static_Object* param_6);
};

void RGE_Doppleganger_Object::recycle_in_to_game(
    RGE_Master_Static_Object* param_1,
    RGE_Player* param_2,
    float param_3,
    float param_4,
    float param_5,
    RGE_Static_Object* param_6)
{
    // Zero all doppleganger-specific fields
    *(int*)((char*)this + 0x8C) = 0;  // doppled_object
    *(int*)((char*)this + 0x90) = 0;  // draw_color
    *(int*)((char*)this + 0x94) = 0;  // doppled_master_obj
    *(int*)((char*)this + 0x98) = 0;  // doppled_player
    *(int*)((char*)this + 0x9C) = 0;  // MapAddress
    *(int*)((char*)this + 0xA0) = 0;  // LastMapValue
    *(int*)((char*)this + 0xA4) = 0;  // CantSeeBits
    *(unsigned char*)((char*)this + 0xA8) = 0;  // map_draw_level
    *(unsigned char*)((char*)this + 0xA9) = 0;  // map_color
    *(int*)((char*)this + 0xAC) = -1;  // doppledObjectID

    // Call base class version (passes first 5 params)
    RGE_Animated_Object::recycle_in_to_game(param_1, param_2, param_3, param_4, param_5);

    // Set type to doppleganger (0x19 = 25)
    *(unsigned char*)((char*)this + 0x4E) = 0x19;

    // Store doppled_object
    *(int*)((char*)this + 0x8C) = (int)param_6;

    if (param_6 != 0) {
        // Copy fields from source object directly
        *(int*)((char*)this + 0x94) = *(int*)((char*)param_6 + 0x08);  // doppled_master_obj = param_6->master_obj
        *(int*)((char*)this + 0x98) = (signed short)*(short*)((char*)*(int*)((char*)param_6 + 0x0C) + 0x4A);  // doppled_player = owner->id
        *(int*)((char*)this + 0xAC) = *(int*)((char*)param_6 + 0x04);  // doppledObjectID = param_6->id

        // Copy sprite
        *(int*)((char*)this + 0x10) = *(int*)((char*)param_6 + 0x10);  // this->sprite = param_6->sprite

        // Copy sprite list
        RGE_Active_Sprite_Node* newNode = ((RGE_Active_Sprite_List*)*(int*)((char*)param_6 + 0x18))->copy_sprite_list();
        ((RGE_Active_Sprite_List*)*(int*)((char*)this + 0x18))->use_sprite_list(newNode);

        // Reload doppled_object pointer (now stored in field)
        void* obj = *(void**)((char*)this + 0x8C);

        // Copy facet
        *(unsigned char*)((char*)this + 0x35) = *(unsigned char*)((char*)obj + 0x35);

        // draw_color = owner->color_table
        *(int*)((char*)this + 0x90) = *(int*)((char*)*(int*)((char*)obj + 0x0C) + 0x108);

        // map_draw_level and map_color
        unsigned char ml = *(unsigned char*)((char*)*(int*)((char*)obj + 0x08) + 0x8E);
        *(unsigned char*)((char*)this + 0xA8) = ml;

        if (ml == 3) {
            *(unsigned char*)((char*)this + 0xA9) = *(unsigned char*)((char*)*(int*)((char*)obj + 0x08) + 0x90);
        } else {
            *(unsigned char*)((char*)this + 0xA9) = *(unsigned char*)((char*)*(int*)((char*)*(int*)((char*)obj + 0x0C) + 0x108) + 0x25);
        }

        // Map address calculation (ftol order: y first, then x)
        int row = (int)(long)param_4;  // ftol(y) -> ebp
        int col = (int)(long)param_3;  // ftol(x) -> eax
        void* mapAddr = (void*)((unsigned long*)unified_map_offsets[row] + col);

        *(int*)((char*)this + 0xA0) = 0;  // LastMapValue = 0
        *(int*)((char*)this + 0xA4) = 0;  // CantSeeBits = 0
        *(int*)((char*)this + 0x9C) = (int)mapAddr;  // MapAddress

        // Check object_state
        if (*(unsigned char*)((char*)obj + 0x48) >= 7) {
            *(int*)((char*)this + 0x8C) = 0;  // doppled_object = NULL
            *(int*)((char*)this + 0xAC) = -1;  // doppledObjectID = -1
            ((VirtualHelper*)this)->validate();
            return;
        }
    } else {
        // param_6 == NULL path
        *(int*)((char*)this + 0xAC) = -1;  // doppledObjectID = -1
        *(int*)((char*)this + 0x94) = 0;   // doppled_master_obj = NULL
        *(int*)((char*)this + 0x98) = 0;   // doppled_player = 0
        ((VirtualHelper*)this)->destroy_obj();
    }

    // Shared tail: call validate
    ((VirtualHelper*)this)->validate();
}
