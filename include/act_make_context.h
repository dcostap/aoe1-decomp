#ifndef ACT_MAKE_CONTEXT_H
#define ACT_MAKE_CONTEXT_H

// Canonical declaration context for ACT_make.cpp.
//
// The accepted update owner already contains the period class surfaces proved
// by this module's field offsets, virtual calls, and PDB line bands.  Reuse
// those declarations here, without including its function body.  The wrapper
// includes the owner again after this context, so the body remains at its PDB
// line position.
//
// PDB module: C:\\msdev\\work\\age1_x1\\ACT_make.cpp.
// Normal owner order: 004049B0, 004049E0 generated destructor,
// 00404A10, 00404A40, 00404A70, 00404A90.
// The constructor and helper owners are exact under the ordinary /O2 /Oy
// context.  update remains observed accepted drift: its behavior and ordered
// calls match, but VC5 does not reproduce the original split callee-save
// schedule in this isolated module.
#define ACT_MAKE_CONTEXT_DECLARE 1
#define ACT_MAKE_CONTEXT_DECLARATIONS_ONLY 1
#include "../src/accepted_drift/00404A90_update.cpp"
#undef ACT_MAKE_CONTEXT_DECLARATIONS_ONLY
#undef ACT_MAKE_CONTEXT_DECLARE

#endif
