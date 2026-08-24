// Authentic tact_cnv.cpp reconstruction wrapper.
//
// Source module: C:\\msdev\\work\\age1_x1\\tact_cnv.cpp
// PDB owner order and source-line bands:
//  004CD9E0  TRIBE_Action_Convert::TRIBE_Action_Convert  (48-52)
//  004CDA90  TRIBE_Action_Convert::TRIBE_Action_Convert  (61-81)
//  004CDB20  TRIBE_Action_Convert::TRIBE_Action_Convert  (90-102)
//  004CDB70  TRIBE_Action_Convert::save                    (108-112)
//  004CDBB0  TRIBE_Action_Convert::first_in_stack          (118-216)
//  004CDE10  TRIBE_Action_Convert::set_state               (222-305)
//  004CE070  TRIBE_Action_Convert::update                  (311-522)
//  004CE450  TRIBE_Action_Convert::work                    (529-547)
//  004CE4B0  TRIBE_Action_Convert::martyrdom                (553-567)
//
// The body owners are existing exact matching sources.  This wrapper keeps
// their PDB order and leaves the nearby compiler-generated deleting destructor
// to the compiler.

#define TACT_CNV_SHARED_CONTEXT 1
#include "../include/tact_cnv_context.h"

#include "matching/004CD9E0_TRIBE_Action_Convert.cpp"
#include "matching/004CDA90_TRIBE_Action_Convert.cpp"
#include "matching/004CDB20_TRIBE_Action_Convert.cpp"
#include "matching/004CDB70_save.cpp"
#include "matching/004CDBB0_first_in_stack.cpp"
#include "matching/004CDE10_set_state.cpp"
#include "matching/004CE070_update.cpp"
#include "matching/004CE450_work.cpp"
#include "matching/004CE4B0_martyrdom.cpp"

TRIBE_Action_Convert::~TRIBE_Action_Convert()
{
}

static void tact_cnv_force_vector_delete(TRIBE_Action_Convert* value)
{
    delete [] value;
}

#undef TACT_CNV_SHARED_CONTEXT
