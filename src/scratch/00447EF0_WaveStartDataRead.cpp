__declspec(dllimport) int __stdcall mmioSeek(int handle, int offset, int origin);
__declspec(dllimport) int __stdcall mmioDescend(int handle, void* chunkInfo, void* parentInfo, int flags);

int __cdecl _WaveStartDataRead(int* handle_ptr, void* buffer, int* wave_info) {
    if (mmioSeek(*handle_ptr, wave_info[3] + 4, 0) == -1) {
        return 1;
    }

    *(int*)buffer = 0x61746164;
    return mmioDescend(*handle_ptr, buffer, wave_info, 0x10);
}
