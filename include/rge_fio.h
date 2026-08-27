#ifndef AOE1_RGE_FIO_H
#define AOE1_RGE_FIO_H

// Public C++ surface recovered from rge_fio.cpp and its PDB symbols.
int __cdecl rge_fake_open(int file, int size);
int __cdecl rge_open(char* path, int mode);
int __cdecl rge_open(char* path, int mode, int attr);
int __cdecl rge_fake_close(int file);
int __cdecl rge_close(int file);
void __cdecl rge_read_uncompressed(int file, void* buffer, int size);
void __cdecl rge_write_uncompressed(int file, void* buffer, int size);
void __cdecl rge_read(int file, void* buffer, int size);
int __cdecl rge_buffer_full(unsigned char* buffer, int size);
void __cdecl rge_write(int file, void* buffer, int size);

// The original PDB names the process-wide error flag rge_write_error.
extern int rge_write_error;

#endif  // AOE1_RGE_FIO_H
