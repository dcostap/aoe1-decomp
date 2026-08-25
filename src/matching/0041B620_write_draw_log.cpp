void __cdecl write_draw_log(char* text) {
    if (draw_log != 0) {
        fprintf(draw_log, "%s", text);
        fflush(draw_log);
    }
}
