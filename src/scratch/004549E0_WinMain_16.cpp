// VA: 004549E0 _WinMain@16 (1553B)
// main.cpp
// EH frame (/GX)

char _sg_584AB4[] = "some_string";

void* __cdecl sub_0054DEE0(unsigned size);

int __stdcall WinMain(int hInstance, int hPrevInstance, int lpCmdLine, int nCmdShow) {
    void* heap = sub_0054DEE0(0x1440);
    if (!heap) return 0;
    
    // Parse command line
    const char* cmdLine = (const char*)lpCmdLine;
    if (cmdLine) {
        // Initialize and run game
    }
    
    return nCmdShow;
}
