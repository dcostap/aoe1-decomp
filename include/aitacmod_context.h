#ifndef AOE1_AITACMOD_CONTEXT_H
#define AOE1_AITACMOD_CONTEXT_H

// Authentic module context for C:\\msdev\\work\\age1_x1\\aitacmod.cpp.
//
// Binary evidence:
// - AIModule is the direct base.  Its destructor owns the tail target
//   0040E360 and its vtable begins at the object address.
// - TacticalAIModule has the 0xF0 AIModule-sized layout in the class dump.
// - The PDB source order is the constructor at lines 24-26 followed by the
//   virtual destructor at line 31.
// - The scalar deleting destructor at 00412B80 is compiler-generated from the
//   virtual TacticalAIModule destructor.  It is not a source owner.
//
// This module-local context is narrow on purpose.  It supplies only the
// declarations needed by the two source owners and generated destructor.
// It does not replace reviewed shared ABI declarations.

class AIModule {
public:
    virtual ~AIModule();
    AIModule(char* name, int id, int param1, void* param2);
};

class TacticalAIModule : public AIModule {
public:
    TacticalAIModule(void* param1, int param2);
    virtual ~TacticalAIModule();
};

#endif
