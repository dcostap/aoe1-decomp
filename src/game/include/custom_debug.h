#pragma once
/*
 * CUSTOM DEBUG INFRASTRUCTURE
 * ===========================
 * This header provides custom debugging utilities for the AoE1 decompilation.
 * These are NOT part of the original game - they are added to help debug the reimplementation.
 * 
 * Usage:
 *   #include "custom_debug.h"
 *   
 *   CUSTOM_DEBUG_LOG("Message here");
 *   CUSTOM_DEBUG_LOG_FMT("Value: %d", someValue);
 *   CUSTOM_DEBUG_CHECKPOINT("Setup Phase 1");
 *   CUSTOM_DEBUG_ERROR(error_code, "description");
 * 
 * The debug log is written to: decomp_debug.log in the working directory.
 * 
 * Toggle with: #define CUSTOM_DEBUG_ENABLED 1 (or 0 to disable)
 * 
 * Message Box Suppression:
 *   When CUSTOM_DEBUG_SUPPRESS_MESSAGEBOXES is set to 1, MessageBoxA calls
 *   will be redirected to the debug log instead of showing UI dialogs.
 *   This is useful for automated testing/debugging runs where you don't
 *   want to manually click through error dialogs.
 */

#ifndef CUSTOM_DEBUG_ENABLED
#define CUSTOM_DEBUG_ENABLED 1
#endif

// Set to 1 to suppress MessageBoxA popups and log them instead
#ifndef CUSTOM_DEBUG_SUPPRESS_MESSAGEBOXES
#define CUSTOM_DEBUG_SUPPRESS_MESSAGEBOXES 1
#endif

#include <windows.h>
#include <stdio.h>
#include <stdarg.h>

// =============================================================================
// CUSTOM DEBUG IMPLEMENTATION BLOCK
// Any code wrapped in this block is custom to our reimplementation, not in the OG exe.
// =============================================================================
#define CUSTOM_DEBUG_BEGIN  /* BEGIN CUSTOM DEBUG CODE - NOT IN ORIGINAL */
#define CUSTOM_DEBUG_END    /* END CUSTOM DEBUG CODE */

#if CUSTOM_DEBUG_ENABLED

// Global debug state
static FILE* g_debugLog = nullptr;
static int g_debugInitialized = 0;
static CRITICAL_SECTION g_debugLock;

// Initialize debug logging system
inline void CustomDebug_Init() {
    if (g_debugInitialized) return;
    
    InitializeCriticalSection(&g_debugLock);
    g_debugLog = fopen("decomp_debug.log", "w");
    if (g_debugLog) {
        SYSTEMTIME st;
        GetLocalTime(&st);
        fprintf(g_debugLog, "=== DECOMP DEBUG LOG ===\n");
        fprintf(g_debugLog, "Started: %04d-%02d-%02d %02d:%02d:%02d\n\n",
                st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond);
        fflush(g_debugLog);
    }
    g_debugInitialized = 1;
}

// Shutdown debug logging
inline void CustomDebug_Shutdown() {
    if (g_debugLog) {
        fprintf(g_debugLog, "\n=== END DEBUG LOG ===\n");
        fclose(g_debugLog);
        g_debugLog = nullptr;
    }
    if (g_debugInitialized) {
        DeleteCriticalSection(&g_debugLock);
        g_debugInitialized = 0;
    }
}

// Write to debug log (thread-safe)
inline void CustomDebug_Write(const char* prefix, const char* fmt, ...) {
    if (!g_debugInitialized) CustomDebug_Init();
    if (!g_debugLog) return;
    
    EnterCriticalSection(&g_debugLock);
    
    DWORD tick = GetTickCount();
    fprintf(g_debugLog, "[%08lu] %s: ", tick, prefix);
    
    va_list args;
    va_start(args, fmt);
    vfprintf(g_debugLog, fmt, args);
    va_end(args);
    
    fprintf(g_debugLog, "\n");
    fflush(g_debugLog);
    
    LeaveCriticalSection(&g_debugLock);
}

// Capture Windows error with message
inline void CustomDebug_WinError(const char* context) {
    DWORD err = GetLastError();
    if (err == 0) return;
    
    char buf[512];
    FormatMessageA(FORMAT_MESSAGE_FROM_SYSTEM, NULL, err, 0, buf, sizeof(buf), NULL);
    CustomDebug_Write("WIN_ERROR", "%s - Code %lu: %s", context, err, buf);
}

// Macros for easy use
#define CUSTOM_DEBUG_INIT()           CustomDebug_Init()
#define CUSTOM_DEBUG_SHUTDOWN()       CustomDebug_Shutdown()
#define CUSTOM_DEBUG_LOG(msg)         CustomDebug_Write("LOG", "%s", msg)
#define CUSTOM_DEBUG_LOG_FMT(fmt,...) CustomDebug_Write("LOG", fmt, __VA_ARGS__)
#define CUSTOM_DEBUG_CHECKPOINT(name) CustomDebug_Write("CHECKPOINT", ">>> %s", name)
#define CUSTOM_DEBUG_ERROR(code,desc) CustomDebug_Write("ERROR", "code=%d: %s", (int)(code), desc)
#define CUSTOM_DEBUG_WIN_ERROR(ctx)   CustomDebug_WinError(ctx)
#define CUSTOM_DEBUG_FUNC_ENTER()     CustomDebug_Write("FUNC", "ENTER %s", __FUNCTION__)
#define CUSTOM_DEBUG_FUNC_EXIT()      CustomDebug_Write("FUNC", "EXIT  %s", __FUNCTION__)

// =============================================================================
// MESSAGE BOX SUPPRESSION
// When enabled, intercepts MessageBoxA calls and logs them instead of showing UI.
// =============================================================================
#if CUSTOM_DEBUG_SUPPRESS_MESSAGEBOXES

// Replacement function that logs instead of showing a dialog
inline int CustomDebug_MessageBoxA(HWND hWnd, LPCSTR lpText, LPCSTR lpCaption, UINT uType) {
    if (!g_debugInitialized) CustomDebug_Init();
    
    const char* typeStr = "INFO";
    if (uType & MB_ICONERROR) typeStr = "ERROR";
    else if (uType & MB_ICONWARNING) typeStr = "WARNING";
    else if (uType & MB_ICONQUESTION) typeStr = "QUESTION";
    
    CustomDebug_Write("MSGBOX", "[%s] %s: %s", typeStr, 
                      lpCaption ? lpCaption : "(no title)", 
                      lpText ? lpText : "(no message)");
    
    // Return IDOK by default, or appropriate response based on type
    if (uType & MB_YESNO) return IDYES;
    if (uType & MB_OKCANCEL) return IDOK;
    if (uType & MB_RETRYCANCEL) return IDCANCEL;
    if (uType & MB_YESNOCANCEL) return IDYES;
    return IDOK;
}

// Replace MessageBoxA with our logging version
// NOTE: This must be included AFTER windows.h in files that use it
#undef MessageBoxA
#define MessageBoxA CustomDebug_MessageBoxA

#endif // CUSTOM_DEBUG_SUPPRESS_MESSAGEBOXES

#else // CUSTOM_DEBUG_ENABLED == 0

// No-op versions when debug is disabled
#define CUSTOM_DEBUG_INIT()           ((void)0)
#define CUSTOM_DEBUG_SHUTDOWN()       ((void)0)
#define CUSTOM_DEBUG_LOG(msg)         ((void)0)
#define CUSTOM_DEBUG_LOG_FMT(fmt,...) ((void)0)
#define CUSTOM_DEBUG_CHECKPOINT(name) ((void)0)
#define CUSTOM_DEBUG_ERROR(code,desc) ((void)0)
#define CUSTOM_DEBUG_WIN_ERROR(ctx)   ((void)0)
#define CUSTOM_DEBUG_FUNC_ENTER()     ((void)0)
#define CUSTOM_DEBUG_FUNC_EXIT()      ((void)0)

#endif // CUSTOM_DEBUG_ENABLED

