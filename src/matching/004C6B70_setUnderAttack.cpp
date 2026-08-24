// VA: 004C6B70 setUnderAttack (13B)
// stat_obj.cpp, PDB lines 4215-4217
// BINARY NOTE: PDB owner is RGE_Static_Object::setUnderAttack(unsigned char).
// BINARY NOTE: The owned body is [004C6B70, 004C6B7D); 004C6B7D begins padding.
// BINARY NOTE: Keep the virtual, non-const setter ABI and the narrow +0x86 store.

#ifndef RGE_STAT_OBJ_SHARED_CONTEXT
class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    char gap_0[0x82];
    unsigned char field_86;
    virtual void setUnderAttack(unsigned char v);
};
#endif

void RGE_Static_Object::setUnderAttack(unsigned char v) { this->field_86 = v; }
