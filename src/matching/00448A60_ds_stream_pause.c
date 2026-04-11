static int _stream_paused = 0;

int __cdecl ds_stream_pause(void) {
    return _stream_paused = 1;
}
