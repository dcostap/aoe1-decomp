// VA: 00448A60 ds_stream_pause (11 B)
// PDB source: Dsutil.c
// Pauses the stream
// ACCEPTED_DRIFT: VC5 generates mov dword [addr],1 while original uses mov eax,1/mov [addr],eax.
// Both are functionally identical with equivalent address encoding after relocation.

int stream_paused;

void __cdecl ds_stream_pause()
{
    stream_paused = 1;
}
