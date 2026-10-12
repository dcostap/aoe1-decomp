/* Differential test: the original compress.lib Deflate object against src/Deflate.c,
   compiled with its public names prefixed by src_. Both encoders share the same
   state and output buffers, so stored pointers compare equal too. Pass -quick to
   skip inputs larger than 40,000 bytes. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int (__cdecl *WRITE_FN)(unsigned char *, int);
extern int __cdecl deflate_buf_size(void);
extern int __cdecl deflate_init(void *, int, int, int, void *, int, WRITE_FN);
extern int __cdecl deflate_data(void *, void *, int, int);
extern void __cdecl deflate_deinit(void *);
extern int __cdecl src_deflate_buf_size(void);
extern int __cdecl src_deflate_init(void *, int, int, int, void *, int, WRITE_FN);
extern int __cdecl src_deflate_data(void *, void *, int, int);
extern void __cdecl src_deflate_deinit(void *);

#define STATE_SIZE 0x3817C
#define OUT_MAX 65536

typedef struct {
    unsigned char *data;
    int size;
    int capacity;
    int calls;
    int fail_at;
    unsigned char state[STATE_SIZE];
    unsigned char out[OUT_MAX];
    int results[8192];
    int result_count;
} LOG;

static LOG logs[2];
static LOG *current;
static unsigned char state[STATE_SIZE];
static unsigned char out[OUT_MAX];

static int __cdecl collect(unsigned char *data, int size)
{
    LOG *log = current;
    log->calls++;
    if (log->size + size + 8 > log->capacity) {
        log->capacity = (log->size + size + 8) * 2;
        log->data = (unsigned char *)realloc(log->data, log->capacity);
        if (!log->data) exit(40);
    }
    memcpy(log->data + log->size, &size, 4);
    memcpy(log->data + log->size + 4, &data, 4);
    memcpy(log->data + log->size + 8, data, size);
    log->size += size + 8;
    return log->fail_at && log->calls >= log->fail_at;
}

static void run(int which, unsigned char *input, int size, int level, int mode, int lazy,
                int chunk, int out_size, int fill, int last_flag)
{
    LOG *log = &logs[which];
    int i, amount, result, n = 0;
    memset(state, 0, STATE_SIZE);
    memset(out, fill, OUT_MAX);
    current = log;
    log->size = 0;
    log->calls = 0;
    result = which ? src_deflate_init(state, level, mode, lazy, out, out_size, collect)
                   : deflate_init(state, level, mode, lazy, out, out_size, collect);
    log->results[n++] = result;
    for (i = 0; i < size; i += amount) {
        amount = size - i;
        if (amount > chunk) amount = chunk;
        result = which ? src_deflate_data(state, input + i, amount, last_flag && i + amount == size)
                       : deflate_data(state, input + i, amount, last_flag && i + amount == size);
        if (n < 8190) log->results[n++] = result;
        if (result) break;
    }
    if (!result && !last_flag) {
        result = which ? src_deflate_data(state, 0, 0, 1) : deflate_data(state, 0, 0, 1);
        log->results[n++] = result;
    }
    if (which) src_deflate_deinit(state); else deflate_deinit(state);
    memcpy(log->state, state, STATE_SIZE);
    memcpy(log->out, out, OUT_MAX);
    log->result_count = n;
}

static int cases, failures;

static void compare(const char *name, unsigned char *input, int size, int level, int mode,
                    int lazy, int chunk, int out_size, int fail_at, int fill, int last_flag)
{
    logs[0].fail_at = logs[1].fail_at = fail_at;
    run(0, input, size, level, mode, lazy, chunk, out_size, fill, last_flag);
    run(1, input, size, level, mode, lazy, chunk, out_size, fill, last_flag);
    cases++;
    if (logs[0].result_count != logs[1].result_count
        || memcmp(logs[0].results, logs[1].results, logs[0].result_count * sizeof(int))
        || logs[0].size != logs[1].size || memcmp(logs[0].data, logs[1].data, logs[0].size)
        || memcmp(logs[0].state, logs[1].state, STATE_SIZE)
        || memcmp(logs[0].out, logs[1].out, OUT_MAX)) {
        int i, j;
        for (i = 0; i < logs[0].size && i < logs[1].size && logs[0].data[i] == logs[1].data[i]; ++i) ;
        for (j = 0; j < STATE_SIZE && logs[0].state[j] == logs[1].state[j]; ++j) ;
        printf("MISMATCH %s size %d level %d mode %d lazy %d chunk %d out %d fail %d fill %d last %d: "
               "results %d/%d logs %d/%d first log diff %d first state diff 0x%X\n", name, size,
               level, mode, lazy, chunk, out_size, fail_at, fill, last_flag, logs[0].result_count,
               logs[1].result_count, logs[0].size, logs[1].size, i, j);
        failures++;
    }
}

static unsigned char *make(int pattern, int size)
{
    static const char *words[] = {"the ", "unit ", "villager ", "attack ", "\r\n", "1997 ",
                                  "Age of Empires ", "\t", "0x00", "rome "};
    unsigned char *data = (unsigned char *)malloc(size + 64);
    unsigned int random = 0x19780717u + pattern * 7919u;
    int i = 0;
    while (i < size) {
        random ^= random << 13;
        random ^= random >> 17;
        random ^= random << 5;
        switch (pattern) {
        case 0:
            data[i++] = 0;
            break;
        case 1:
            data[i] = (unsigned char)(i % 251);
            i++;
            break;
        case 2:
            data[i++] = (unsigned char)random;
            break;
        case 3: {
            const char *w = words[random % 10];
            while (*w && i < size)
                data[i++] = *w++;
            break;
        }
        case 4:
            data[i++] = (unsigned char)(random & 3);
            break;
        case 5:
            /* Long repeats near the maximum distance. */
            if (i >= 40000 && (random & 7)) {
                int d = 30000 + random % 2768, k;
                for (k = 0; k < 300 && i < size; ++k, ++i)
                    data[i] = data[i - d];
            } else {
                data[i++] = (unsigned char)(random >> 8);
            }
            break;
        default:
            data[i] = (unsigned char)((i / 3000) & 1 ? random : 'a' + (i & 1));
            i++;
            break;
        }
    }
    return data;
}

static unsigned char *load(const char *name, int *size)
{
    FILE *file = fopen(name, "rb");
    unsigned char *data;
    if (!file) exit(30);
    fseek(file, 0, SEEK_END);
    *size = ftell(file);
    fseek(file, 0, SEEK_SET);
    data = (unsigned char *)malloc(*size + 16);
    if (fread(data, 1, *size, file) != (size_t)*size) exit(31);
    fclose(file);
    return data;
}

int main(int argc, char **argv)
{
    static const int sizes[] = {0, 1, 2, 3, 258, 4095, 4096, 4097, 32767, 32768, 32769,
                                36000, 65536, 100003, 300000};
    static const int levels[] = {-5, 0, 1, 2, 3, 4, 5, 16, 75, 1500, 1501, 100000};
    static const int chunks[] = {1, 7, 997, 4096, 65536, 0x7FFFFFFF};
    static const int outs[] = {1, 3, 64, 4096, 65536};
    int pattern, s, l, mode, lazy, c, a = 1, quick = 0;
    setvbuf(stdout, NULL, _IONBF, 0);
    if (argc > 1 && strcmp(argv[1], "-quick") == 0) {
        quick = 1;
        a = 2;
    }
    if (deflate_buf_size() != STATE_SIZE || src_deflate_buf_size() != STATE_SIZE) return 2;
    for (pattern = 0; pattern < 7; ++pattern)
        for (s = 0; s < sizeof(sizes) / sizeof(*sizes); ++s) {
            int size = sizes[s];
            unsigned char *data;
            if (quick && size > 40000)
                continue;
            data = make(pattern, size);
            for (l = 0; l < sizeof(levels) / sizeof(*levels); ++l)
                for (mode = 0; mode < 4; ++mode)
                    for (lazy = 0; lazy < 2; ++lazy) {
                        int chunk = chunks[(pattern + s + l + mode) % 6];
                        int out_size = outs[(pattern + s + l + lazy) % 5];
                        if (size > 40000 && chunk < 64)
                            chunk = 997;
                        compare("synthetic", data, size, levels[l], mode, lazy, chunk, out_size,
                                0, (pattern + l) & 1 ? 0xA5 : 0, (l + mode) % 3 == 0);
                    }
            /* Write-callback failure paths. */
            for (c = 1; c < 4; ++c)
                compare("failure", data, size, 75, 2, 1, 997, 64, c, 0, 0);
            free(data);
        }
    for (; a < argc; ++a) {
        int size;
        unsigned char *data = load(argv[a], &size);
        for (l = 0; l < sizeof(levels) / sizeof(*levels); l += 2)
            for (mode = 0; mode < 3; ++mode)
                for (lazy = 0; lazy < 2; ++lazy)
                    compare(argv[a], data, size, levels[l], mode, lazy,
                            chunks[2 + (l + mode + lazy) % 4], 65536, 0, 0, 0);
        free(data);
    }
    printf("%d cases, %d mismatches\n", cases, failures);
    return failures != 0;
}
