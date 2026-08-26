// first pass: FindResourceA -> LoadResource -> LockResource -> parse helper, returning 1 only on full success
// keeping the resource-type pointer as a real address operand is important for the exact push order here
extern const char DSWaveResourceType[];

extern int __cdecl DSParseWaveResource(void *waveData, void *out1, void *out2, void *out3);

int __cdecl DSGetWaveResource(void *hModule, const char *lpName, void *out1, void *out2, void *out3) {
    void *resource;

    resource = FindResourceA((HMODULE)hModule, lpName, (LPCSTR)0x570428);
    if (resource != 0) {
        resource = LoadResource((HMODULE)hModule, (HRSRC)resource);
        if (resource != 0) {
            resource = LockResource((HGLOBAL)resource);
            if (resource != 0) {
                if (DSParseWaveResource(resource, out1, out2, out3) != 0) {
                    return 1;
                }
            }
        }
    }

    return 0;
}
