#ifndef AOE1_GETDXVER_H
#define AOE1_GETDXVER_H

// Declarations for the original C:\\msdev\\work\\age1_x1\\getdxver.cpp
// translation unit.

#include <windows.h>
#include <objbase.h>
#include <winver.h>
#include <ddraw.h>
#include <dplay.h>

// The pinned headers do not declare these two legacy API GUIDs.  The module
// references the imported constants but does not define or own them.
typedef HRESULT (__stdcall* DIRECTDRAWCREATE)( void*, LPDIRECTDRAW*, void* );
extern const GUID CLSID_DirectPlay;
extern const GUID IID_IDirectPlay3;
extern const GUID IID_IDirectDrawSurface3;

int IsDPlay501a();
void GetDXVersion( unsigned long* version, unsigned long* platform );

#endif
