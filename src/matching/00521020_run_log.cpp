// VA: 00521020 run_log (246 B)
// PDB source: tribegam.cpp
// Packet-grounded: __cdecl, write timestamped message to aoerun.txt
// Attempt log:
// - Natural first pass used a direct ctime result and omitted the binary-proven strncpy buffer.
// - Restored the 26-byte stime buffer, nested ctime/strncpy call, and C runtime ABI declarations.
// - Reversed the creation test to preserve the original append fall-through and moved memset after time().
// - The recovered source base is stime (not the decompiler's stack-relative stime+4); this is an exact match.

struct _iobuf;

extern "C" {
    _iobuf* __cdecl fopen(const char* path, const char* mode);
    int __cdecl fclose(_iobuf* file);
    int __cdecl fprintf(_iobuf* file, const char* fmt, ...);
    long __cdecl time(long* t);
    char* __cdecl ctime(const long* t);
    char* __cdecl strncpy(char* dest, const char* src, unsigned int count);
    void* __cdecl memset(void* dest, int value, unsigned int count);
}

extern int do_run_log;         // 0x62C4F4
extern int run_log_created;    // 0x86BDFC
extern _iobuf* run_log_file;   // 0x86BDF8

void __cdecl run_log(char* param_1, int param_2)
{
    if (!do_run_log)
        return;

    if (run_log_created) {
        run_log_file = fopen("c:\\aoerun.txt", "a");
    } else {
        run_log_file = fopen("c:\\aoerun.txt", "w");
        run_log_created = 1;
    }

    if (!run_log_file)
        return;

    if (param_2) {
        time((long*)&param_2);
        char stime[26];
        memset(stime, 0, sizeof(stime));
        strncpy(stime, ctime((long*)&param_2), 0x18);
        fprintf(run_log_file, "%s - %s\n", stime, param_1);
    } else {
        fprintf(run_log_file, "%s\n", param_1);
    }

    fclose(run_log_file);
}
