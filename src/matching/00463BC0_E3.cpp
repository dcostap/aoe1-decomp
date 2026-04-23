extern "C" int atexit(void (*func)(void));
void E2(void);

void E3(void) {
    atexit(E2);
}
