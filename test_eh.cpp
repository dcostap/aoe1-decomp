// Test EH frame generation
void test() {
    __try {
        int x = 0;
    } __except(1) {
        int y = 0;
    }
}
