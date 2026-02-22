#include "../include/globals.h"
#include <io.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

extern "C" {
#include "../../third_party/puff/puff.h"
}

RGE_Base_Game* rge_base_game = nullptr;
long SDI_Object_ID = -1;
int SDI_Draw_Line = 0;
int SDI_Capture_Info = 0;
int do_draw_log = 0;
int safe_draw_log = 0;
char draw_log_name[260] = {0};
FILE* draw_log = nullptr;
HINSTANCE StringTable = nullptr;
TRegistry* Regs = nullptr;
HWND AppWnd = nullptr;
HINSTANCE AppInst = nullptr;
void* chat = nullptr;
void* comm = nullptr;
void* sound_driver = nullptr;
void* driveInfo = nullptr;
TMousePointer* MouseSystem = nullptr;

int do_run_log = 0;
int run_log_created = 0;
FILE* run_log_file = nullptr;
HINSTANCE StringTableX = nullptr;
int disable_terrain_sounds = 0;
int debug_random_on = 0;
int out_of_sync = 0;
int out_of_sync2 = 0;
int player_dropped[9] = {0};
TPanelSystem* panel_system = nullptr;
int debugActions = 0;
FILE* actionFile = nullptr;
int video_codec_available = 0;
int log_output = 0;

int quick_start_game_mode = 0;
int restore_mouse_after_paint = 0;
int restoration_count = 0;
unsigned char shape_file_first = 0;
unsigned char sound_file_first = 0;
int debug_timeGetTime_on = 0;
// system_ignore_size_messages defined in Drawarea.cpp
int do_restore_palette = 0;
unsigned long restore_palette_timer = 0;
void* save_active_wnd = nullptr;
int MouseCursorInChildContol = 0;
int DDSys_CanColorFill = 1;
int no_other_humans_count = 0;
int all_cp = 0;
int numberPathingIterations = 2500; // default per decomp (0x9c4)
int useComputerPlayers = 1; // default per ASM (= 1h)
int show_timing_max = 0;
float save_game_version = 7.23f;
unsigned char die_die_die = 0;
int world_update_counter = 0;
unsigned long* unified_map_offsets[256] = {0};
int ENABLE_COMPRESSION = 1;
int rge_write_error = 0;
int Map_Update_Suppresion = 0;
int fog_next_shape = 0;

static int g_rge_handle = -1;
static unsigned char g_rge_mode = 2;
static unsigned char* g_rge_window = nullptr;
static unsigned char* g_rge_window_ptr = nullptr;
static unsigned char* g_rge_inflate_work = nullptr;
static unsigned char* g_rge_compressed_data = nullptr;
static unsigned char* g_rge_inflated_data = nullptr;
static long g_rge_compressed_size = 0;
static long g_rge_stream_read_pos = 0;
static long g_rge_read_count = 0;

static void rge_reset_buffers() {
    if (g_rge_window != nullptr) {
        free(g_rge_window);
        g_rge_window = nullptr;
    }
    if (g_rge_inflate_work != nullptr) {
        free(g_rge_inflate_work);
        g_rge_inflate_work = nullptr;
    }
    if (g_rge_compressed_data != nullptr) {
        free(g_rge_compressed_data);
        g_rge_compressed_data = nullptr;
    }
    if (g_rge_inflated_data != nullptr) {
        free(g_rge_inflated_data);
        g_rge_inflated_data = nullptr;
    }
    g_rge_window_ptr = nullptr;
    g_rge_compressed_size = 0;
    g_rge_stream_read_pos = 0;
    g_rge_read_count = 0;
}

static int inflate_raw_deflate_all(const unsigned char* src, unsigned long src_len, unsigned char** dst, unsigned long* dst_len) {
    if (src == nullptr || src_len == 0 || dst == nullptr || dst_len == nullptr) {
        return -1;
    }

    unsigned long cap = src_len * 6UL;
    if (cap < 0x10000UL) cap = 0x10000UL;

    for (int attempt = 0; attempt < 8; ++attempt) {
        unsigned char* out = (unsigned char*)malloc(cap);
        if (out == nullptr) {
            return -1;
        }

        unsigned long out_len = cap;
        unsigned long in_len = src_len;
        int ret = puff(out, &out_len, src, &in_len);
        if (ret == 0) {
            *dst = out;
            *dst_len = out_len;
            return 0;
        }

        free(out);
        if (ret != 1) {
            return ret;
        }

        if (cap > 0x40000000UL) {
            break;
        }
        cap *= 2UL;
    }

    return 1;
}

static int rge_prepare_read_cache(int handle) {
    if (handle < 0 || handle != g_rge_handle) {
        return 0;
    }

    if (g_rge_compressed_size <= 0) {
        return 0;
    }

    g_rge_compressed_data = (unsigned char*)calloc((size_t)g_rge_compressed_size, 1);
    if (g_rge_compressed_data == nullptr) {
        return 0;
    }

    int got = _read(handle, g_rge_compressed_data, (unsigned int)g_rge_compressed_size);
    if (got <= 0) {
        return 0;
    }

    if (got != g_rge_compressed_size) {
        g_rge_compressed_size = got;
    }

    unsigned char* out = nullptr;
    unsigned long out_len = 0;
    int ret = inflate_raw_deflate_all(g_rge_compressed_data, (unsigned long)g_rge_compressed_size, &out, &out_len);
    if (ret != 0) {
        // Fallback for non-deflate payloads opened through rge_open.
        out_len = (unsigned long)g_rge_compressed_size;
        out = (unsigned char*)calloc((size_t)out_len, 1);
        if (out == nullptr) {
            return 0;
        }
        memcpy(out, g_rge_compressed_data, (size_t)out_len);
    }

    g_rge_inflated_data = out;
    g_rge_stream_read_pos = 0;
    g_rge_mode = 0;
    g_rge_read_count = 0;
    g_rge_compressed_size = (long)out_len;
    return 1;
}

void run_log(char* param_1, int param_2) {}

int rge_fake_open(int handle, int remaining_bytes) {
    if (handle > -1) {
        rge_reset_buffers();
        g_rge_mode = 2;
        g_rge_handle = handle;
        g_rge_compressed_size = remaining_bytes;
        g_rge_window = (unsigned char*)calloc(0x10000, 1);
        g_rge_window_ptr = g_rge_window;
    }
    return handle;
}

int rge_open(char* path, int oflag) {
    int fd = _open(path, oflag);
    if (fd > -1) {
        rge_reset_buffers();
        g_rge_mode = 2;
        g_rge_handle = fd;
        g_rge_window = (unsigned char*)calloc(0x10000, 1);
        g_rge_window_ptr = g_rge_window;

        _lseek(fd, 0, SEEK_END);
        g_rge_compressed_size = _tell(fd);
        g_rge_read_count = 0;
        _lseek(fd, 0, SEEK_SET);
    }
    return fd;
}

int rge_open(char* path, int oflag, int pmode) {
    int fd = _open(path, oflag, pmode);
    if (fd > -1) {
        rge_reset_buffers();
        g_rge_mode = 2;
        g_rge_handle = fd;
        g_rge_window = (unsigned char*)calloc(0x10000, 1);
        g_rge_window_ptr = g_rge_window;

        _lseek(fd, 0, SEEK_END);
        g_rge_compressed_size = _tell(fd);
        g_rge_read_count = 0;
        _lseek(fd, 0, SEEK_SET);
    }
    return fd;
}

int rge_fake_close(int handle) {
    if (handle > -1 && handle == g_rge_handle) {
        rge_reset_buffers();
        g_rge_handle = -1;
    }
    return handle;
}

int rge_close(int handle) {
    if (handle > -1 && handle == g_rge_handle) {
        rge_reset_buffers();
        g_rge_handle = -1;
        return _close(handle);
    }
    return handle;
}

void rge_read(int handle, void* buf, int size) {
    if (size <= 0 || buf == nullptr) {
        return;
    }

    if (handle < 0 || handle != g_rge_handle) {
        return;
    }

    if (ENABLE_COMPRESSION == 0) {
        int got = _read(handle, buf, size);
        if (got > 0) {
            g_rge_read_count += got;
        }
        return;
    }

    if (g_rge_mode != 0) {
        if (!rge_prepare_read_cache(handle)) {
            memset(buf, 0, (size_t)size);
            return;
        }
    }

    long available = g_rge_compressed_size - g_rge_stream_read_pos;
    if (available < 0) {
        available = 0;
    }

    int to_copy = size;
    if ((long)to_copy > available) {
        to_copy = (int)available;
    }

    if (to_copy > 0) {
        memcpy(buf, g_rge_inflated_data + g_rge_stream_read_pos, (size_t)to_copy);
    }
    if (to_copy < size) {
        memset((unsigned char*)buf + to_copy, 0, (size_t)(size - to_copy));
    }

    g_rge_stream_read_pos += to_copy;
    g_rge_read_count += to_copy;
}

void rge_write(int handle, void* buf, int size) {
    if (handle < 0 || handle != g_rge_handle) {
        return;
    }

    int wrote = _write(handle, buf, size);
    if (wrote < 1) {
        rge_write_error = 1;
    }
}

long rge_stream_tell(int handle) {
    if (handle < 0 || handle != g_rge_handle) {
        return -1;
    }

    if (ENABLE_COMPRESSION == 0) {
        return _tell(handle);
    }

    if (g_rge_mode != 0) {
        if (!rge_prepare_read_cache(handle)) {
            return -1;
        }
    }

    return g_rge_stream_read_pos;
}

long rge_stream_seek(int handle, long pos) {
    if (handle < 0 || handle != g_rge_handle) {
        return -1;
    }

    if (ENABLE_COMPRESSION == 0) {
        return _lseek(handle, pos, SEEK_SET);
    }

    if (g_rge_mode != 0) {
        if (!rge_prepare_read_cache(handle)) {
            return -1;
        }
    }

    if (pos < 0) {
        pos = 0;
    }
    if (pos > g_rge_compressed_size) {
        pos = g_rge_compressed_size;
    }

    g_rge_stream_read_pos = pos;
    g_rge_read_count = (int)pos;
    return g_rge_stream_read_pos;
}
