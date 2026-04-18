extern int ds_stream_paused;
int __cdecl ds_stream_resume(void) {
    ds_stream_paused = 0;
    return 1;
}
