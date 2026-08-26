// VA: 004C6B60 underAttack (7B)
// stat_obj.cpp
// BINARY NOTE: PDB owner is RGE_Static_Object::underAttack() const.
// BINARY NOTE: The owned body is [004C6B60, 004C6B67); 004C6B67 begins padding.
// BINARY NOTE: The body is one narrow byte read at this + 0x86 followed by ret.

#ifndef RGE_STAT_OBJ_SHARED_CONTEXT
class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    char gap_0[0x82];
    unsigned char underAttackValue;
    virtual unsigned char underAttack() const;
};
#endif

unsigned char RGE_Static_Object::underAttack() const { return this->underAttackValue; }
