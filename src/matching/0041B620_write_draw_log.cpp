#ifndef BASEGAME_GROUPED_TU
struct _iobuf;
extern _iobuf* draw_log;
extern "C" int __cdecl fprintf(_iobuf* file, const char* format, const char* text);
extern "C" int __cdecl fflush(_iobuf* file);
#endif

void __cdecl write_draw_log(char* text) {
    if (draw_log != 0) {
        fprintf(draw_log, "%s", text);
        fflush(draw_log);
    }
}
