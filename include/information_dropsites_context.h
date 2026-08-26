#ifndef INFORMATION_DROPSITES_CONTEXT_H
#define INFORMATION_DROPSITES_CONTEXT_H

// Keep this legacy context on the canonical taiinfmd ABI surface.
// The old context carried anonymous virtual-slot placeholders for shared
// engine classes. The authentic prefix owns those classes and their named
// virtual methods.
#ifndef TAIINFMD_PREFIX_CONTEXT
#define TAIINFMD_PREFIX_CONTEXT 1
#define INFORMATION_DROPSITES_LOCAL_PREFIX 1
#endif
#include "taiinfmd_prefix_context.h"
#ifdef INFORMATION_DROPSITES_LOCAL_PREFIX
#undef INFORMATION_DROPSITES_LOCAL_PREFIX
#undef TAIINFMD_PREFIX_CONTEXT
#endif

#endif
