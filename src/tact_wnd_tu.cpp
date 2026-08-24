// Authentic tact_wnd.cpp reconstruction wrapper.
//
// Source module: C:\\msdev\\work\\age1_x1\\tact_wnd.cpp
// PDB owner order and source-line bands:
//  004D3470  TRIBE_Action_Wonder::TRIBE_Action_Wonder (35-37)
//  004D34C0  TRIBE_Action_Wonder::TRIBE_Action_Wonder (42-45)
//  004D34F0  TRIBE_Action_Wonder::~TRIBE_Action_Wonder (50-97)
//  004D3690  TRIBE_Action_Wonder::first_in_stack       (101-104)
//  004D36B0  TRIBE_Action_Wonder::set_state             (108-148)
//  004D3810  TRIBE_Action_Wonder::update                (152-179)
//
// The nearby 004D34A0 vector deleting destructor is compiler generated.  The
// force-delete helper below gives VC5 the authentic generated owner without
// adding an ordinary source function to the module.
//
// The context keeps one RGE_Action hierarchy and one RGE_Action_Object slot
// surface.  It does not use manual vtable writes, fake virtual slots, or raw
// offset replacement declarations.

#include "../include/tact_wnd_context.h"

#include "matching/004D3470_TRIBE_Action_Wonder.cpp"
#include "matching/004D34C0_TRIBE_Action_Wonder.cpp"
#include "matching/004D34F0_TRIBE_Action_Wonder.cpp"
#include "matching/004D3690_first_in_stack.cpp"
#include "matching/004D36B0_set_state.cpp"
#include "matching/004D3810_update.cpp"

static void tact_wnd_force_vector_delete(TRIBE_Action_Wonder* value)
{
    delete [] value;
}
