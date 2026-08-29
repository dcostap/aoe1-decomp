/* Authentic C++ source module for C:\\msdev\\work\\age1_x1\\rge_fio.cpp. */

#include "../include/rge_fio.h"

extern "C" int __cdecl open(const char* path, int mode, ...);
extern "C" int __cdecl lseek(int file, int offset, int origin);
extern "C" int __cdecl tell(int file);
extern "C" int __cdecl read(int file, void* buffer, unsigned int size);
extern "C" int __cdecl write(int file, const void* buffer,
                              unsigned int size);
extern "C" int __cdecl close(int file);
extern "C" void* __cdecl calloc(unsigned int count, unsigned int size);
extern "C" void __cdecl free(void* pointer);
extern "C" void* __cdecl memcpy(void* destination, const void* source,
                                unsigned int size);
#pragma intrinsic(memcpy)

extern "C" int __cdecl _Inf32BufSize();
extern "C" int __cdecl _Inf32Decode(void* compressed, int offset,
                                    void* file_size, void* buffer, int zero,
                                    void* buffer_size, void* state, int one);
extern "C" int __cdecl deflate_buf_size();
extern "C" int __cdecl deflate_init(
    void* state, int level, int method, int window_bits, void* buffer,
    int size, int (__cdecl *callback)(unsigned char*, int));
extern "C" int __cdecl deflate_data(void* state, void* source, int size,
                                    int flush);
extern "C" void __cdecl deflate_deinit(void* state);

// These data names are the reviewed addresses used by the original module.
extern int DAT_0086b25c;
extern int DAT_0086b260;
extern unsigned char DAT_0086b264;
extern int DAT_0086b268;
extern int DAT_0086b26c;
extern int DAT_0086b270;
extern int DAT_0086b274;
extern int DAT_0086b278;
extern int DAT_0086b27c;
extern int DAT_0086b280;
extern int ENABLE_COMPRESSION;

int __cdecl rge_fake_open(int param_1, int param_2)
{
    if (param_1 >= 0) {
        DAT_0086b264 = 2;
        DAT_0086b268 = 0;
        DAT_0086b270 = (int)calloc(0x10000, 1);
        DAT_0086b278 = DAT_0086b270;
        DAT_0086b280 = 0;
        DAT_0086b26c = 0;
        DAT_0086b260 = param_1;
        DAT_0086b27c = param_2;
    }
    return param_1;
}

int __cdecl rge_open(char* param_1, int param_2)
{
    int iVar1 = open(param_1, param_2);
    if (iVar1 >= 0) {
        DAT_0086b264 = 2;
        DAT_0086b268 = 0;
        DAT_0086b270 = (int)calloc(0x10000, 1);
        DAT_0086b278 = DAT_0086b270;
        DAT_0086b280 = 0;
        DAT_0086b26c = 0;
        DAT_0086b260 = iVar1;
        lseek(iVar1, 0, 2);
        DAT_0086b27c = tell(iVar1);
        DAT_0086b274 = 0;
        lseek(iVar1, 0, 0);
    }
    return iVar1;
}

int __cdecl rge_open(char* param_1, int param_2, int param_3)
{
    int iVar1 = open(param_1, param_2, param_3);
    if (iVar1 >= 0) {
        DAT_0086b264 = 2;
        DAT_0086b268 = 0;
        DAT_0086b270 = (int)calloc(0x10000, 1);
        DAT_0086b278 = DAT_0086b270;
        DAT_0086b280 = 0;
        DAT_0086b26c = 0;
        DAT_0086b260 = iVar1;
        lseek(iVar1, 0, 2);
        DAT_0086b27c = tell(iVar1);
        DAT_0086b274 = 0;
        lseek(iVar1, 0, 0);
    }
    return iVar1;
}

int __cdecl rge_fake_close(int file)
{
    if (file >= 0 && file == DAT_0086b260) {
        if (DAT_0086b270 != 0) {
            free((void*)DAT_0086b270);
            DAT_0086b270 = 0;
        }
        if (DAT_0086b26c != 0) {
            free((void*)DAT_0086b26c);
            DAT_0086b26c = 0;
        }
        if (DAT_0086b280 != 0) {
            free((void*)DAT_0086b280);
            DAT_0086b280 = 0;
        }
        DAT_0086b260 = -1;
    }
    return file;
}

int __cdecl rge_close(int file)
{
    if (file >= 0 && file == DAT_0086b260) {
        if (DAT_0086b264 == 1 && DAT_0086b26c != 0) {
            int result = deflate_data((void*)DAT_0086b26c, 0, 0, 1);
            if (result == 2) {
                rge_write_error = 1;
            }
            deflate_deinit((void*)DAT_0086b26c);
        }
        DAT_0086b260 = -1;
        if (DAT_0086b270 != 0) {
            free((void*)DAT_0086b270);
            DAT_0086b270 = 0;
        }
        if (DAT_0086b26c != 0) {
            free((void*)DAT_0086b26c);
            DAT_0086b26c = 0;
        }
        if (DAT_0086b280 != 0) {
            free((void*)DAT_0086b280);
            DAT_0086b280 = 0;
        }
        file = close(file);
    }
    return file;
}

void __cdecl rge_read_uncompressed(int file, void* buffer, int size)
{
    if (file >= 0 && file == DAT_0086b260) {
        read(file, buffer, size);
        DAT_0086b27c = DAT_0086b27c - size;
    }
}

void __cdecl rge_write_uncompressed(int file, void* buffer, int size)
{
    if ((file >= 0) && (file == DAT_0086b260)) {
        if (write(file, buffer, size) > 0) {
            return;
        }
        rge_write_error = 1;
    }
}

void __cdecl rge_read(int file, void* buffer, int size)
{
    int fsize;
    int loc;
    void* rbuf = buffer;

    if (ENABLE_COMPRESSION == 0) {
        if (file >= 0 && file == DAT_0086b260) {
            read(file, rbuf, size);
            DAT_0086b27c -= size;
            DAT_0086b274 += size;
        }
    } else if (file >= 0 && file == DAT_0086b260) {
        if (DAT_0086b264 != 0) {
            int state_size = _Inf32BufSize();
            DAT_0086b26c = (int)calloc(state_size, 1);
            DAT_0086b280 = (int)calloc(DAT_0086b27c, 1);
            read(file, (void*)DAT_0086b280, DAT_0086b27c);
            fsize = DAT_0086b27c;
            DAT_0086b25c = 0;
            loc = 0x10000;
            _Inf32Decode((void*)DAT_0086b280, 0, &fsize,
                         (void*)DAT_0086b270, 0, &loc, (void*)DAT_0086b26c,
                         1);
            DAT_0086b25c += fsize;
            DAT_0086b264 = 0;
        }

        {
            int remaining = size;
            int total = size + DAT_0086b268;
            int* ptr = (int*)DAT_0086b278;

            while (total >= 0x10000) {
                int copy = 0x10000 - DAT_0086b268;
                memcpy(rbuf, ptr, copy);

                fsize = DAT_0086b27c;
                loc = 0x10000;
                _Inf32Decode((void*)DAT_0086b280, DAT_0086b25c, &fsize,
                             (void*)DAT_0086b270, 0, &loc,
                             (void*)DAT_0086b26c, 1);
                DAT_0086b25c += fsize;

                remaining -= copy;
                DAT_0086b268 = 0;
                rbuf = (char*)rbuf + copy;
                DAT_0086b278 = DAT_0086b270;
                ptr = (int*)DAT_0086b270;
                total = remaining;
            }

            if (remaining > 0) {
                memcpy(rbuf, ptr, remaining);
                DAT_0086b268 += remaining;
                DAT_0086b278 += remaining;
            }
        }
    }
}

int __cdecl rge_buffer_full(unsigned char* buffer, int size)
{
    if (write(DAT_0086b260, buffer, size) > 0) {
        return 0;
    }
    rge_write_error = 1;
    return 0;
}

void __cdecl rge_write(int file, void* buffer, int size)
{
    if (ENABLE_COMPRESSION == 0) {
        if (file >= 0 && file == DAT_0086b260) {
            int result = write(file, buffer, size);
            if (result <= 0) {
                rge_write_error = 1;
            }
        }
    } else {
        if (file >= 0 && file == DAT_0086b260) {
            if (DAT_0086b264 != 1) {
                DAT_0086b264 = 1;
                int state_size = deflate_buf_size();
                DAT_0086b26c = (int)calloc(state_size, 1);
                deflate_init((void*)DAT_0086b26c, 0x4B, 2, 1,
                             (void*)DAT_0086b270, 0x10000, rge_buffer_full);
            }
            int result = deflate_data((void*)DAT_0086b26c, buffer, size, 0);
            if (result == 2) {
                rge_write_error = 1;
            }
        }
    }
}
