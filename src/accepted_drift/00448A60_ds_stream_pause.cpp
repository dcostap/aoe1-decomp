// VA: 00448A60 ds_stream_pause (11 B)
// PDB source: Dsutil.c
// Pauses the stream

int stream_paused;

void __cdecl ds_stream_pause()
{
    stream_paused = 1;
}
