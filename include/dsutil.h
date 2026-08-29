#ifndef AOE1_DSUTIL_H
#define AOE1_DSUTIL_H

#include <windows.h>
#include <mmsystem.h>
#define CINTERFACE
#include <dsound.h>
#include <string.h>

/* Dsutil owns the process-wide DirectSound stream state. */
#ifdef __cplusplus
extern "C" {
#endif
extern unsigned int _uLastPercent;
extern LPDIRECTSOUNDBUFFER _lpDSBStreamBuffer;
extern int _bFileOpen;
extern int _bPlaying;
extern int _bTimerInstalled;
extern unsigned int _uTimerID;
extern HWND _main_wnd;
extern unsigned int _lpBuffer;
extern LPDIRECTSOUND _lpDS;
extern int _ds_ready;
extern int _stream_paused;
extern LPWAVEFORMATEX _wiWave;

extern HMMIO ds_wave_file;
extern MMCKINFO ds_wave_data_chunk;
extern MMCKINFO ds_wave_riff_chunk;
extern LPDIRECTSOUNDBUFFER ds_stream_buffer;
extern unsigned int ds_buffer_size;
extern unsigned int ds_chunk_size;
extern unsigned int ds_write_cursor;
extern unsigned int ds_last_play_cursor;
extern unsigned long ds_stream_position;
extern int ds_stream_stop_requested;
extern unsigned int ds_stream_loop;
extern int ds_stream_at_end;
extern unsigned int ds_silence_chunks;
extern unsigned long ds_buffer_bytes;
extern long ds_last_percent;
extern int ds_stream_callback_active;

#ifdef __cplusplus
}
#endif

#endif
