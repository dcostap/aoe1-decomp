#ifndef AOE1_RGE_FIO_H
#define AOE1_RGE_FIO_H

#include <fcntl.h>
#include <sys/stat.h>

int __cdecl rge_fake_open(int file_handle, int fake_size);
int __cdecl rge_open(char* filename, int flag);
int __cdecl rge_open(char* filename, int flag, int pmode);
int __cdecl rge_fake_close(int handle);
int __cdecl rge_close(int handle);
void __cdecl rge_read_uncompressed(int handle, void* data, int size);
void __cdecl rge_write_uncompressed(int handle, void* data, int size);
void __cdecl rge_read(int handle, void* data, int size);
int __cdecl rge_buffer_full(unsigned char* out_buf_ofs, int out_buf_size);
void __cdecl rge_write(int handle, void* data, int size);

extern int rge_write_error;

#endif  // AOE1_RGE_FIO_H
