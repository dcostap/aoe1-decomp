void __cdecl write_draw_log2(char* text) {
    if (draw_log != 0) {
        fprintf(draw_log, "%s", text);
        fclose(draw_log);
        draw_log = fopen(draw_log_name, "a+");
    }
}
