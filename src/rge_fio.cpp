
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

extern "C" int __cdecl Inf32BufSize();
extern "C" int __cdecl Inf32Decode(void* compressed, int offset,
                                    void* file_size, void* buffer, int zero,
                                    void* buffer_size, void* state, int one);
extern "C" int __cdecl deflate_buf_size();
extern "C" int __cdecl deflate_init(
    void* state, int level, int method, int window_bits, void* buffer,
    int size, int (__cdecl *callback)(unsigned char*, int));
extern "C" int __cdecl deflate_data(void* state, void* source, int size,
                                    int flush);
extern "C" void __cdecl deflate_deinit(void* state);

static int compression_point;
static int current_handle;
static unsigned char flags;
static long point;
static unsigned char* compression_buffers;
static unsigned char* buffers;
static int bl;
static unsigned char* current;
static int file_size;
static unsigned char* file_buffers;
extern int ENABLE_COMPRESSION;

int __cdecl rge_fake_open(int param_1, int param_2)
{
    if (param_1 >= 0) {
        flags = 2;
        point = 0;
        buffers = (unsigned char*)calloc(0x10000, 1);
        current = buffers;
        file_buffers = 0;
        compression_buffers = 0;
        current_handle = param_1;
        file_size = param_2;
    }
    return param_1;
}

int __cdecl rge_open(char* param_1, int param_2)
{
    int iVar1 = open(param_1, param_2);
    if (iVar1 >= 0) {
        flags = 2;
        point = 0;
        buffers = (unsigned char*)calloc(0x10000, 1);
        current = buffers;
        file_buffers = 0;
        compression_buffers = 0;
        current_handle = iVar1;
        lseek(iVar1, 0, 2);
        file_size = tell(iVar1);
        bl = 0;
        lseek(iVar1, 0, 0);
    }
    return iVar1;
}

int __cdecl rge_open(char* param_1, int param_2, int param_3)
{
    int iVar1 = open(param_1, param_2, param_3);
    if (iVar1 >= 0) {
        flags = 2;
        point = 0;
        buffers = (unsigned char*)calloc(0x10000, 1);
        current = buffers;
        file_buffers = 0;
        compression_buffers = 0;
        current_handle = iVar1;
        lseek(iVar1, 0, 2);
        file_size = tell(iVar1);
        bl = 0;
        lseek(iVar1, 0, 0);
    }
    return iVar1;
}

int __cdecl rge_fake_close(int file)
{
    if (file >= 0 && file == current_handle) {
        if (buffers != 0) {
            free(buffers);
            buffers = 0;
        }
        if (compression_buffers != 0) {
            free(compression_buffers);
            compression_buffers = 0;
        }
        if (file_buffers != 0) {
            free(file_buffers);
            file_buffers = 0;
        }
        current_handle = -1;
    }
    return file;
}

int __cdecl rge_close(int file)
{
    if (file >= 0 && file == current_handle) {
        if (flags == 1 && compression_buffers != 0) {
            int result = deflate_data(compression_buffers, 0, 0, 1);
            if (result == 2) {
                rge_write_error = 1;
            }
            deflate_deinit(compression_buffers);
        }
        current_handle = -1;
        if (buffers != 0) {
            free(buffers);
            buffers = 0;
        }
        if (compression_buffers != 0) {
            free(compression_buffers);
            compression_buffers = 0;
        }
        if (file_buffers != 0) {
            free(file_buffers);
            file_buffers = 0;
        }
        file = close(file);
    }
    return file;
}

void __cdecl rge_read_uncompressed(int file, void* buffer, int size)
{
    if (file >= 0 && file == current_handle) {
        read(file, buffer, size);
        file_size = file_size - size;
    }
}

void __cdecl rge_write_uncompressed(int file, void* buffer, int size)
{
    if ((file >= 0) && (file == current_handle)) {
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
        if (file >= 0 && file == current_handle) {
            read(file, rbuf, size);
            file_size -= size;
            bl += size;
        }
    } else if (file >= 0 && file == current_handle) {
        if (flags != 0) {
            int state_size = Inf32BufSize();
            compression_buffers = (unsigned char*)calloc(state_size, 1);
            file_buffers = (unsigned char*)calloc(file_size, 1);
            read(file, file_buffers, file_size);
            fsize = file_size;
            compression_point = 0;
            loc = 0x10000;
            Inf32Decode(file_buffers, 0, &fsize,
                         buffers, 0, &loc, compression_buffers,
                         1);
            compression_point += fsize;
            flags = 0;
        }

        {
            int remaining = size;
            int total = size + point;
            unsigned char* ptr = current;

            while (total >= 0x10000) {
                int copy = 0x10000 - point;
                memcpy(rbuf, ptr, copy);

                fsize = file_size;
                loc = 0x10000;
                Inf32Decode(file_buffers, compression_point, &fsize,
                             buffers, 0, &loc,
                             compression_buffers, 1);
                compression_point += fsize;

                remaining -= copy;
                point = 0;
                rbuf = (char*)rbuf + copy;
                current = buffers;
                ptr = buffers;
                total = remaining;
            }

            if (remaining > 0) {
                memcpy(rbuf, ptr, remaining);
                point += remaining;
                current += remaining;
            }
        }
    }
}

int __cdecl rge_buffer_full(unsigned char* buffer, int size)
{
    if (write(current_handle, buffer, size) > 0) {
        return 0;
    }
    rge_write_error = 1;
    return 0;
}

void __cdecl rge_write(int file, void* buffer, int size)
{
    if (ENABLE_COMPRESSION == 0) {
        if (file >= 0 && file == current_handle) {
            int result = write(file, buffer, size);
            if (result <= 0) {
                rge_write_error = 1;
            }
        }
    } else {
        if (file >= 0 && file == current_handle) {
            if (flags != 1) {
                flags = 1;
                int state_size = deflate_buf_size();
                compression_buffers = (unsigned char*)calloc(state_size, 1);
                deflate_init(compression_buffers, 0x4B, 2, 1,
                             buffers, 0x10000, rge_buffer_full);
            }
            int result = deflate_data(compression_buffers, buffer, size, 0);
            if (result == 2) {
                rge_write_error = 1;
            }
        }
    }
}
