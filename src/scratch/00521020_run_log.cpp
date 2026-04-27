// VA: 00521020 run_log (246 B)
// PDB source: tribegam.cpp
// Packet-grounded: __cdecl, write timestamped message to aoerun.txt

extern void* fopen(const char* path, const char* mode);
extern int fclose(void* file);
extern int fprintf(void* file, const char* fmt, ...);
extern long time(long* t);
extern char* ctime(const long* t);

int do_run_log;         // 0x62C4F4
int run_log_created;    // 0x86BDFC
void* run_log_file;     // 0x86BDF8

void __cdecl run_log(char* param_1, int param_2)
{
    if (!do_run_log)
        return;
    
    if (!run_log_created) {
        run_log_file = fopen("c:\\aoerun.txt", "w");
        run_log_created = 1;
    } else {
        run_log_file = fopen("c:\\aoerun.txt", "a");
    }
    
    if (!run_log_file)
        return;
    
    if (param_2) {
        long t;
        time(&t);
        char* timestr = ctime(&t);
        fprintf(run_log_file, "%s - %s\n", timestr, param_1);
    } else {
        fprintf(run_log_file, "%s\n", param_1);
    }
    
    fclose(run_log_file);
}
