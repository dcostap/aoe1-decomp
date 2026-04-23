extern "C" int __cdecl read(int handle, void* buffer, int count);

extern int DAT_0086b260;
extern int DAT_0086b27c;

void __cdecl rge_read_uncompressed(int handle, void* buffer, int count) {
    if ((handle >= 0) && (handle == DAT_0086b260)) {
        read(handle, buffer, count);
        DAT_0086b27c = DAT_0086b27c - count;
    }
}
