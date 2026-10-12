#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int __cdecl deflate_buf_size(void);
extern int __cdecl deflate_init(void*, int, int, int, void*, int, int (__cdecl *)(unsigned char*, int));
extern int __cdecl deflate_data(void*, void*, int, int);
extern void __cdecl deflate_deinit(void*);
extern int __cdecl Inf32BufSize(void);
extern int __cdecl Inf32Decode(void*, int, int*, void*, int, int*, void*, int);

static unsigned char* packed;
static int packed_size;
static int packed_capacity;

static int __cdecl collect(unsigned char* data, int size)
{
    if (size < 0 || packed_size + size > packed_capacity) exit(20);
    memcpy(packed + packed_size, data, size);
    packed_size += size;
    return 0;
}

static int test_case(int index, int size, int pattern, int chunk)
{
    unsigned char* input = (unsigned char*)calloc(size + 16, 1);
    unsigned char* buffer = (unsigned char*)calloc(65536, 1);
    void* encoder = calloc(deflate_buf_size(), 1);
    void* decoder = calloc(Inf32BufSize(), 1);
    unsigned int random = 0x19780717;
    int i, amount, result, offset, consumed, produced;
    char name[80];
    FILE* file;
    packed_capacity = size * 2 + 131072;
    packed = (unsigned char*)calloc(packed_capacity, 1);
    packed_size = 0;
    if (!input || !buffer || !encoder || !decoder || !packed) return 21;
    for (i = 0; i < size; ++i) {
        random ^= random << 13;
        random ^= random >> 17;
        random ^= random << 5;
        input[i] = pattern == 0 ? 0 : pattern == 1 ? (unsigned char)(i % 251) : (unsigned char)random;
    }
    result = deflate_init(encoder, 75, 2, 1, buffer, 65536, collect);
    printf("case %d size %d pattern %d chunk %d init %d\n", index, size, pattern, chunk, result);
    for (i = 0; i < size; i += amount) {
        amount = size - i;
        if (amount > chunk) amount = chunk;
        result = deflate_data(encoder, input + i, amount, 0);
        if (result == 2) return 22;
    }
    result = deflate_data(encoder, 0, 0, 1);
    if (result == 2) return 23;
    deflate_deinit(encoder);
    sprintf(name, "fixture_%02d.raw", index);
    file = fopen(name, "wb");
    if (!file) return 24;
    fwrite(input, 1, size, file);
    fclose(file);
    sprintf(name, "fixture_%02d.deflate", index);
    file = fopen(name, "wb");
    if (!file) return 25;
    fwrite(packed, 1, packed_size, file);
    fclose(file);
    offset = 0;
    for (i = 0; i < size; i += amount) {
        consumed = packed_size;
        produced = 65536;
        result = Inf32Decode(packed, offset, &consumed, buffer, 0, &produced, decoder, 1);
        amount = size - i;
        if (amount > 65536) amount = 65536;
        if (produced != amount) return 34;
        if (memcmp(input + i, buffer, amount)) {
            printf("decode mismatch: %d input %d consumed %d produced %d result %d\n", i, offset, consumed, produced, result);
            return 26;
        }
        offset += consumed;
    }
    if (size % 65536 == 0) {
        consumed = packed_size;
        produced = 65536;
        Inf32Decode(packed, offset, &consumed, buffer, 0, &produced, decoder, 1);
        if (produced != 0) return 35;
    }
    printf("case %d passed; packed %d\n", index, packed_size);
    free(packed);
    free(decoder);
    free(encoder);
    free(buffer);
    free(input);
    return 0;
}

static unsigned char* load_file(char* name, int* size)
{
    FILE* file = fopen(name, "rb");
    unsigned char* data;
    if (!file) exit(30);
    fseek(file, 0, SEEK_END);
    *size = ftell(file);
    fseek(file, 0, SEEK_SET);
    data = (unsigned char*)calloc(*size + 16, 1);
    if (!data || fread(data, 1, *size, file) != (unsigned int)*size) exit(31);
    fclose(file);
    return data;
}

static int decode_files(char* compressed_name, char* expected_name)
{
    int input_size, expected_size, offset = 0, i, amount, consumed, produced;
    unsigned char* input = load_file(compressed_name, &input_size);
    unsigned char* expected = load_file(expected_name, &expected_size);
    unsigned char* buffer = (unsigned char*)calloc(65536, 1);
    void* decoder = calloc(Inf32BufSize(), 1);
    if (!buffer || !decoder) return 32;
    for (i = 0; i < expected_size; i += amount) {
        consumed = input_size;
        produced = 65536;
        Inf32Decode(input, offset, &consumed, buffer, 0, &produced, decoder, 1);
        amount = expected_size - i;
        if (amount > 65536) amount = 65536;
        if (produced != amount) return 36;
        if (memcmp(expected + i, buffer, amount)) return 33;
        offset += consumed;
    }
    printf("external stream passed: %d bytes\n", expected_size);
    free(decoder);
    free(buffer);
    free(expected);
    free(input);
    return 0;
}

int main(int argc, char** argv)
{
    int sizes[] = {0, 1, 257, 65535, 65536, 65537, 131072, 1048576};
    int i, pattern, result, index = 0;
    if (argc == 3) return decode_files(argv[1], argv[2]);
    if (deflate_buf_size() != 0x3817C || Inf32BufSize() != 0xAD90) return 27;
    for (i = 0; i < 8; ++i) {
        for (pattern = 0; pattern < 3; ++pattern) {
            result = test_case(index++, sizes[i], pattern, i % 2 ? 997 : 65536);
            if (result) return result;
        }
    }
    return 0;
}
