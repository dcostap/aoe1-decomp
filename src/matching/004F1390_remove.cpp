// VA: 004F1390
// ManagedArray<int>::remove(int)
// PDB source: utmarray.h lines 120-133
// BINARY NOTE: The search loop uses direct indexing and the shift loop uses
// post-increment. The reviewed period template surface emits the exact body.
// Explicit instantiation emits the owning symbol for this target source unit.

#include "../../include/utmarray.h"

template int ManagedArray<int>::remove(int);
