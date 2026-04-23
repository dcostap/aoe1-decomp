extern "C" __declspec(dllimport) int __stdcall VirtualFree(void* address, unsigned int size, unsigned int free_type);

int __cdecl RESFILE_Decommit_Mapped_Memory(unsigned char* address, int size) {
    if ((address != 0) && (size > 0)) {
        return VirtualFree(address, size, 0x4000);
    }
    return 0;
}
