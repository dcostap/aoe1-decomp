#ifndef AOE1_TACT_CNV_CONTEXT_H
#define AOE1_TACT_CNV_CONTEXT_H

// Shared declaration surface for the tact_cnv.cpp translation unit.  The
// source owner supplies the reviewed period class hierarchy and virtual
// method names.  Import declarations only; do not import the update body.

void rge_read(int, void*, unsigned int);
void rge_write(int, void*, int);

#define TACT_CNV_CONTEXT_ONLY 1
#ifdef TACT_CNV_SHARED_CONTEXT
#define TACT_CNV_CONTEXT_RESTORE_SHARED 1
#undef TACT_CNV_SHARED_CONTEXT
#endif
#include "../src/matching/004CE070_update.cpp"
#ifdef TACT_CNV_CONTEXT_RESTORE_SHARED
#define TACT_CNV_SHARED_CONTEXT 1
#undef TACT_CNV_CONTEXT_RESTORE_SHARED
#endif
#undef TACT_CNV_CONTEXT_ONLY

#endif
