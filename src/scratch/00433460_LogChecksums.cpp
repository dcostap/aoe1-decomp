// VA: 00433460 LogChecksums (1579B)
// com_sync.cpp

class TDebuggingLog {
public:
    void Log(const char* fmt, ...);
};

extern TDebuggingLog* g_debuggingLog;

class RGE_Communications_Synchronize {
public:
    char gap0[0x14];
    int sendChatMsgs;       // +14
    int newData;            // +18
    int lastResult;         // +1C
    int offset;             // +20
    int doChecksums;        // +24
    int lastWorldRandom;    // +28
    int gameWorldChecksum;  // +2C
    // array at +30
    
    void LogChecksums();
};

void RGE_Communications_Synchronize::LogChecksums() {
    if (!newData) return;
    
    g_debuggingLog->Log("Sync results:");
    g_debuggingLog->Log("  offset: %d", offset);
    
    if (lastResult) {
        g_debuggingLog->Log("  Result: OK");
    } else {
        g_debuggingLog->Log("  Result: FAIL");
    }
    
    // Log each entry's checksums
    int i;
    for (i = 0; i <= offset; i++) {
        int* entry = (int*)((char*)this + 0x30 + i * 0x24);
        g_debuggingLog->Log("  [%d]: turn=%d wr=%08x c1=%08x c2=%08x", 
            i, entry[0], entry[1], entry[2], entry[3]);
    }
}
