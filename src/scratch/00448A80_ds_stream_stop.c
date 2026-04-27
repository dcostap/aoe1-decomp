/* VA: 00448A80 ds_stream_stop */
/* Dsutil.c lines 1638-1678, 162 bytes */

extern int g_ds_stream_active;
extern int g_ds_stream_paused;
extern int g_ds_buffer;
extern int g_mixer_active;
extern int g_mixer_buffer;

extern int (__stdcall *g_pfnWait)(void*, int);
extern void (__stdcall *g_pfnSleep)(int);

void __cdecl ds_stream_stop() {
    int old_active;
    int old_mixer;

    g_ds_stream_paused = 1;
    old_active = g_ds_stream_active;
    if (old_active) {
        g_ds_stream_active = 0;
        g_pfnWait((void*)g_ds_buffer, 0x32);
        g_pfnSleep(0x32);
    }
    old_mixer = g_mixer_active;
    if (old_mixer) {
        g_mixer_active = 0;
        g_pfnWait((void*)g_mixer_buffer, 0x32);
        g_pfnSleep(0x32);
    }
}
