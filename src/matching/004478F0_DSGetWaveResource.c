// first pass: FindResourceA -> LoadResource -> LockResource -> parse helper, returning 1 only on full success
// keeping the resource-type pointer as a real address operand is important for the exact push order here
extern const char DSWaveResourceType[];

extern void *(__stdcall *FindResourceA)(void *hModule, const char *lpName, const char *lpType);
extern void *(__stdcall *LoadResource)(void *hModule, void *hResInfo);
extern void *(__stdcall *LockResource)(void *hResData);
extern int __cdecl _DSParseWaveResource(void *waveData, void *out1, void *out2, void *out3);

int __cdecl _DSGetWaveResource(void *hModule, const char *lpName, void *out1, void *out2, void *out3) {
    void *resource;

    resource = (*FindResourceA)(hModule, lpName, (const char *)0x570428);
    if (resource != 0) {
        resource = (*LoadResource)(hModule, resource);
        if (resource != 0) {
            resource = (*LockResource)(resource);
            if (resource != 0) {
                if (_DSParseWaveResource(resource, out1, out2, out3) != 0) {
                    return 1;
                }
            }
        }
    }

    return 0;
}
