// Authentic complete owner wrapper for C:\\msdev\\work\\age1_x1\\com_err.cpp.
//
// PDB-qualified owner order and source bands:
//   00424E40 RGE_Comm_Error::RGE_Comm_Error(void*)       lines 6-9
//   00424E60 RGE_Comm_Error::NotifyWindowParam(...)      lines 12-15
//   00424EA0 RGE_Comm_Error::~RGE_Comm_Error()           line 19
//   00424EB0 RGE_Comm_Error::ShowReturn(long, char*)     lines 23-380
//
// Exact original body boundaries:
//   00424E40-00424E51 (18 bytes), 00424E60-00424E94 (53 bytes),
//   00424EA0-00424EA0 (1 byte), and 00424EB0-00425737 (2184 bytes).
//
// The surrounding bytes are not owners in this TU.  IPAD owns 00424DD0-00424E21
// and 00424E30 owns its one-byte destructor.  Data or padding occupies
// 00424E22-00424E2F, 00424E31-00424E3F, 00424E52-00424E5F,
// 00424E95-00424E9F, 00424EA1-00424EAF, and 00425738-0042574F.
// The last range includes ShowReturn's switch table.  Do not register these
// ranges or the com_addr.cpp/com_addr.h owners as synthetic functions.
//
// One module flag set: config/flags/com_err.rsp (/nologo /c /O2 /Oy).

#define COM_ERR_TU_CONTEXT 1
#include "../include/com_err_context.h"

#include "matching/00424E40_RGE_Comm_Error.cpp"
#include "matching/00424E60_NotifyWindowParam.cpp"
#include "matching/00424EA0_RGE_Comm_Error.cpp"
#include "matching/00424EB0_ShowReturn.cpp"

#undef COM_ERR_TU_CONTEXT
