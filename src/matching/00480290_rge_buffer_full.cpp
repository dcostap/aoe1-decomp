extern "C" int __cdecl write(int fd, const void* buffer, unsigned int count);
extern int DAT_0086B260;
extern int rge_write_error;

int __cdecl rge_buffer_full(unsigned char* buffer, int count) {
    if (write(DAT_0086B260, buffer, count) > 0) {
        return 0;
    }
    rge_write_error = 1;
    return 0;
}
