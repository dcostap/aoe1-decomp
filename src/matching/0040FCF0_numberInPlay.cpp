#ifndef AIPBOOK_CANONICAL_TU
struct PlayEntry {
    int id;
    int pad;
};
class AIPlayStatus {
public:
    unsigned char numberInPlay(void) const;
    PlayEntry entries[50];
};
#endif

unsigned char AIPlayStatus::numberInPlay(void) const {
    unsigned char count = 0;
    for (int i = 0; i < 50; i++) {
        if (this->entries[i].id != -1) {
            count++;
        }
    }
    return count;
}
