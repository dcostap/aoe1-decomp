// 004C11E0 RGE_Static_Object constructor
// stat_obj.cpp:182-186, 164 bytes, /GX
// Round2 pass: 10 variants tried: field-by-field natural ctor, temp zero local,
// raw *(int*) field stores, explicit state local, do_setup temp, visible destructor
// definition, shared -1 temp, small source order changes, and checking nearby ctor
// patterns. Best behavior source compiles to 160-byte non-EH .text; visible dtor
// variant emits a different broad EH/codegen family. Original has VC5 constructor EH
// registration/state around otherwise simple field initialization and optional setup;
// local stubs could not reproduce the exact EH/vptr/state basin. Not accepted drift.
// Retry 2026-05-20 assigned pass:
// try 11: revalidated current /GX source; object text order starts with compiler-emitted dtor/deleting-dtor helpers and checker sees only a 160-byte constructor COMDAT, not original 164B EH constructor.
// try 12: __declspec(novtable) on class; shrank to wrong 112B/non-EH family.
// try 13: removed virtual destructor; wrong 112B/non-EH family.
// try 14: pure virtual destructor and reordered destructor declaration; still helper COMDAT first / wrong size.
// try 15: flag probes /Gy-, /Ob0, /GR-, and no /GX; no useful change from wrong 112/160B families.
// try 16: initializer-list field initialization; still 160B wrong text-order/non-EH extraction.
// try 17: raw byte-offset stores; still 160B wrong text-order family.
// try 18: manual vptr write in body; shrank to wrong 128B family.
// try 19: named do_setup local and compact assignment order; still 160B family.
// try 20: /Og- and /Od reached 164B but broad wrong unoptimized/prologue family (140 positional diff); /O1, /vd0, /vmg rejected/wrong size. Flags restored to /O2 /Oy /GX.
// Retry 2026-05-21 Boss pass: 19 more probes. Tried compact current body, inline dtor definition after ctor (164B but wrong helper/text order, 85.9756% positional), novtable, manual vptr, raw offset stores, do_setup local, initializer-list stores, no virtual dtor, pure virtual dtor, and flags /Ob0 /GR- /G5 /GB /vd0 /Gy- /no-GX /no-Oy /O1 /Od. Normal variants stayed 160B too small; novtable/no-virtual/manual-vptr variants shrank to 112/128B; only /Od and inline dtor reached 164B but broad wrong prologue/helper family from byte 0. Still no accepted_drift: structural EH COMDAT/text-order/prologue mismatch.
// GIVEUP: exact source/layout facts are understood, but local isolated VC5 cannot reproduce the original constructor EH COMDAT/text-order basin. Not proposing accepted_drift because this is structural EH/prologue/text-section drift, not localized equivalent codegen.
// Retry 2026-05-24 Boss pass: 12 more probes. Revalidated current /GX source: constructor .text is still 160B, below configured 164B.
// Tried inline dtor (164B but mismatch from byte 0), out-of-line dtor after ctor (164B byte-0 mismatch), explicit virtual base with dtor
// (164B and EH prologue matches through +25, but store order/vptr/base helper text is structurally wrong), manual vptr/no virtual, initializer-list,
// do_setup temp, reordered unitAI/-1 stores, virtual dummy/setup/destroy surfaces without destructor, and protected destructor visibility.
// Best new clue was virtual-base EH family first mismatch +25, but it inserts/omits broad initialization chunks and helper text; not kept.
// GIVEUP again; no accepted_drift because the remaining difference is constructor EH/vtable/text-order structure, not localized benign drift.

class RGE_Game_World;
class RGE_Sprite;
class RGE_Object_Node;
class UnitAIModule;

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    char gap04[0x0C];
    RGE_Sprite* sprite;
    RGE_Sprite* old_sprite;
    char gap18[0x38];
    RGE_Object_Node* player_object_node;
    int pathingGroupValue;
    int pathingGroupNumber;
    int pathingGroupDesired;
    int pathingGroupMax;
    int groupValue;
    int groupNumber;
    int groupDesired;
    int groupMax;
    int unitAIValue;
    int groupCommanderValue;
    int zoneMapIndex;
    float groupRangeValue;
    unsigned char inObstructionMapValue;
    unsigned char lastInObstructionMapValue;
    unsigned char underAttackValue;

    RGE_Static_Object(int id, RGE_Game_World* world, int do_setup);
    int setup(int id, RGE_Game_World* world);
};

RGE_Static_Object::RGE_Static_Object(int id, RGE_Game_World* world, int do_setup)
{
    sprite = 0;
    old_sprite = 0;
    pathingGroupValue = 0;
    pathingGroupNumber = 0;
    pathingGroupDesired = 0;
    pathingGroupMax = 0;
    groupValue = 0;
    groupNumber = 0;
    groupDesired = 0;
    groupMax = 0;
    groupCommanderValue = -1;
    zoneMapIndex = -1;
    unitAIValue = 0;
    groupRangeValue = 5.0f;
    inObstructionMapValue = 0;
    lastInObstructionMapValue = 0;
    underAttackValue = 0;
    player_object_node = 0;
    if (do_setup != 0)
        setup(id, world);
}

