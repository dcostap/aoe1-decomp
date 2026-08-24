// Authentic owner wrapper for C:\\msdev\\work\\age1_x1\\com_addr.cpp.
//
// PDB-qualified owner order and source bands:
//   004249D0 RGE_Communications_Addresses::RGE_Communications_Addresses 8-79
//   00424B10 RGE_Communications_Addresses::~RGE_Communications_Addresses 82-90
//   00424B60 RGE_Communications_Addresses::GetHostName 93-97
//   00424B80 RGE_Communications_Addresses::SetIPAliases 100-135
//   00424C20 RGE_Communications_Addresses::GetAddress 138-143
//   00424C50 RGE_Communications_Addresses::GetAlias 146-154
//   00424C80 RGE_Communications_Addresses::SetIPAddresses 157-198
//   00424D90 RGE_Communications_Addresses::EraseInformation 202-206
//
// The nearby compiler-generated entry 00424AC0 is IPAD's vector-deleting
// destructor.  It is retained as a generated comparison in the proposal.
// GetAlias stays in this authentic owner order.  The complete-TU build differs
// from its standalone exact source by one SIB byte, so the proposal records it
// as observed rather than forcing a policy-invalid context change.
// The original module uses the /GX EH context required by the constructor and
// destructor, so the existing constructor response file supplies this TU's
// flags without changing global configuration.

#define COM_ADDR_TU_CONTEXT 1
#include "../include/com_addr_context.h"

#include "matching/004249D0_RGE_Communications_Addresses.cpp"
#include "matching/00424B10_RGE_Communications_Addresses.cpp"
#include "matching/00424B60_GetHostName.cpp"
#include "matching/00424B80_SetIPAliases.cpp"
#include "matching/00424C20_GetAddress.cpp"
#include "matching/00424C50_GetAlias.cpp"
#include "matching/00424C80_SetIPAddresses.cpp"
#include "matching/00424D90_EraseInformation.cpp"

#undef COM_ADDR_TU_CONTEXT
