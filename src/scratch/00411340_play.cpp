struct AIPlay {
    char data[0x608];
};

struct AIPlayBook {
    int vfptr;
    int numberPlays;
    char gap_8[0x44];
    AIPlay plays[10];
};

AIPlay* __fastcall play(AIPlayBook* self, int, int index) {
    if (index < 0)
        return 0;
    if (index >= self->numberPlays)
        return 0;
    return &self->plays[index];
}
