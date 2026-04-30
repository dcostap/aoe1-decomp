// 00448A60 ds_stream_pause
// Dsutil.c:1620-1623, 11 bytes

extern int _stream_paused;
void ds_stream_pause(void) {
    _stream_paused = 1;
}
