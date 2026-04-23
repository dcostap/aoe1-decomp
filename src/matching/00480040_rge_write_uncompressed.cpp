extern "C" int __cdecl write(int handle, void* buffer, int count);

extern int DAT_0086b260;
extern int rge_write_error;

void __cdecl rge_write_uncompressed(int handle, void* buffer, int count) {
    if ((handle >= 0) && (handle == DAT_0086b260)) {
        if (write(handle, buffer, count) > 0) {
            return;
        }
        rge_write_error = 1;
    }
}
