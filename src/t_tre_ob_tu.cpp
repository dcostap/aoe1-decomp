// Authentic t_tre_ob.cpp recovery wrapper.
//
// Source module: C:\\msdev\\work\\age1_x1\\t_tre_ob.cpp
// PDB source-line order:
//   004CCA60  TRIBE_Tree_Object::TRIBE_Tree_Object (36-39)
//   004CCB20  TRIBE_Tree_Object::TRIBE_Tree_Object (44-47)
//   004CCB90  TRIBE_Tree_Object::set_object_state (51-62)
//
// The scalar deleting destructor at 004CCAF0 and the two destructor bodies at
// 004CCB0E/004CCB10 are compiler-generated neighbors.  The owner sources use
// one canonical RGE_Static_Object surface and preserve the shipped base call.
// Candidate check: the two constructors, set_object_state, and 004CCAF0 all
// match under /nologo /c /O2 /Oy /GX.  The generated destructor is not a source
// owner; it is emitted naturally by the virtual class surface.

#include "matching/004CCA60_TRIBE_Tree_Object.cpp"
#include "matching/004CCB20_TRIBE_Tree_Object.cpp"
#include "scratch/004CCB90_set_object_state.cpp"
