#ifndef AOE1_DSUTIL_H
#define AOE1_DSUTIL_H

/*
 * Declarations shared by the Dsutil.c source module.
 *
 * BINARY NOTE: Dsutil.c is a C source module. The shipped module uses the
 * period VC5 Windows, WinMM, DirectSound, and C runtime declarations.
 * /Oi- is required by the measured direct memcpy and memset call sites.
 */
#include <windows.h>
#include <mmsystem.h>
#define CINTERFACE
#include <dsound.h>
#include <string.h>

#endif
