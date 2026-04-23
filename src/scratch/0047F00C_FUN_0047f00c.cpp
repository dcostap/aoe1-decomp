extern "C" __declspec(dllimport) int __stdcall MessageBoxA(void* hWnd, const char* lpText, const char* lpCaption, unsigned int uType);

void FUN_0047f00c(void) {
    MessageBoxA(0, "Error: Reading resfile header.", "RESOURCE ERROR", 0x30);
}
