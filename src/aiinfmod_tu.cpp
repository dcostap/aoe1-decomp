// Authentic aiinfmod.cpp owner wrapper.
//
// PDB source module: C:\\msdev\\work\\age1_x1\\aiinfmod.cpp
// PDB owner order: constructor lines 22-24, destructor line 29.
// The scalar deleting destructor at 0040CDC0 is compiler-generated and has no
// source line. It is reproduced by the shared InformationAIModule surface.
//
// The context is narrow and evidence-based: the binary proves AIModule's
// constructor/destructor calls and InformationAIModule's virtual destructor.
#define AIINFMOD_SHARED_CONTEXT 1
#include "../include/aiinfmod_context.h"

// aiinfmod.cpp:22-24
#include "matching/0040CD90_InformationAIModule.cpp"

// aiinfmod.cpp:29
#include "scratch/0040CDE0_InformationAIModule.cpp"

#undef AIINFMOD_SHARED_CONTEXT
