// VA: 00403020 RGE_Action_Gather::save
// PDB source: ACT_GATH.cpp.  The shared module context owns the class ABI.

#ifndef ACT_GATH_CONTEXT_H
#include "../../include/act_gath_context.h"
#endif

void RGE_Action_Gather::save(int outfile) {
    RGE_Action::save(outfile);
    rge_write(outfile, &this->targetType, 4);
}
