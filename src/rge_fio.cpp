
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

int __cdecl rge_fake_open(int file_handle, int fake_size) {
    if (file_handle >= 0) {
        flags = 2;
        point = 0;
        buffers = (unsigned char*)calloc(0x10000, 1);
        current = buffers;
        file_buffers = 0;
        compression_buffers = 0;
        current_handle = file_handle;
        file_size = fake_size;
    }
    return file_handle;
}

int __cdecl rge_open(char* filename, int flag) {
    int iVar1 = open(filename, flag);
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

int __cdecl rge_open(char* filename, int flag, int pmode) {
    int iVar1 = open(filename, flag, pmode);
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

int __cdecl rge_fake_close(int handle) {
    if (handle >= 0 && handle == current_handle) {
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
    return handle;
}

int __cdecl rge_close(int handle) {
    if (handle >= 0 && handle == current_handle) {
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
        handle = close(handle);
    }
    return handle;
}

void __cdecl rge_read_uncompressed(int handle, void* data, int size) {
    if (handle >= 0 && handle == current_handle) {
        read(handle, data, size);
        file_size = file_size - size;
    }
}

void __cdecl rge_write_uncompressed(int handle, void* data, int size) {
    if ((handle >= 0) && (handle == current_handle)) {
        if (write(handle, data, size) > 0) {
            return;
        }
        rge_write_error = 1;
    }
}

void __cdecl rge_read(int handle, void* data, int size) {
    int temp_size;
    int temp_max;
    void* temp = data;

    if (ENABLE_COMPRESSION == 0) {
        if (handle >= 0 && handle == current_handle) {
            read(handle, temp, size);
            file_size -= size;
            bl += size;
        }
    } else if (handle >= 0 && handle == current_handle) {
        if (flags != 0) {
            int state_size = Inf32BufSize();
            compression_buffers = (unsigned char*)calloc(state_size, 1);
            file_buffers = (unsigned char*)calloc(file_size, 1);
            read(handle, file_buffers, file_size);
            temp_size = file_size;
            compression_point = 0;
            temp_max = 0x10000;
            Inf32Decode(file_buffers, 0, &temp_size,
                         buffers, 0, &temp_max, compression_buffers,
                         1);
            compression_point += temp_size;
            flags = 0;
        }

        {
            int remaining = size;
            int total = size + point;
            unsigned char* ptr = current;

            while (total >= 0x10000) {
                int copy = 0x10000 - point;
                memcpy(temp, ptr, copy);

                temp_size = file_size;
                temp_max = 0x10000;
                Inf32Decode(file_buffers, compression_point, &temp_size,
                             buffers, 0, &temp_max,
                             compression_buffers, 1);
                compression_point += temp_size;

                remaining -= copy;
                point = 0;
                temp = (char*)temp + copy;
                current = buffers;
                ptr = buffers;
                total = remaining;
            }

            if (remaining > 0) {
                memcpy(temp, ptr, remaining);
                point += remaining;
                current += remaining;
            }
        }
    }
}

int __cdecl rge_buffer_full(unsigned char* out_buf_ofs, int out_buf_size) {
    if (write(current_handle, out_buf_ofs, out_buf_size) > 0) {
        return 0;
    }
    rge_write_error = 1;
    return 0;
}

void __cdecl rge_write(int handle, void* data, int size) {
    if (ENABLE_COMPRESSION == 0) {
        if (handle >= 0 && handle == current_handle) {
            int result = write(handle, data, size);
            if (result <= 0) {
                rge_write_error = 1;
            }
        }
    } else {
        if (handle >= 0 && handle == current_handle) {
            if (flags != 1) {
                flags = 1;
                int state_size = deflate_buf_size();
                compression_buffers = (unsigned char*)calloc(state_size, 1);
                deflate_init(compression_buffers, 0x4B, 2, 1,
                             buffers, 0x10000, rge_buffer_full);
            }
            int result = deflate_data(compression_buffers, data, size, 0);
            if (result == 2) {
                rge_write_error = 1;
            }
        }
    }
}
