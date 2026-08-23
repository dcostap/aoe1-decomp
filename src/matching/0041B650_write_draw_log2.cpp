#ifndef BASEGAME_GROUPED_TU
struct _iobuf;
extern _iobuf* draw_log;
extern char draw_log_name[];
extern "C" int __cdecl fprintf(_iobuf* file, const char* format, const char* text);
extern "C" int __cdecl fclose(_iobuf* file);
extern "C" _iobuf* __cdecl fopen(const char* filename, const char* mode);
#endif

void __cdecl write_draw_log2(char* text) {
    if (draw_log != 0) {
        fprintf(draw_log, "%s", text);
        fclose(draw_log);
        draw_log = fopen(draw_log_name, "a+");
    }
}
