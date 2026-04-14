class AIPlay {
public:
    char tag_[2];
    int humanPlay();
};

int AIPlay::humanPlay() {
    if (this->tag_[0] == 0x48 && this->tag_[1] == 0x50) return 1;
    return 0;
}
