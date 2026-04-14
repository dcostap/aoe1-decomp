struct AIPlayPhase_Entry_0040F110 {
    char data[16];
};

class AIPlayPhase {
public:
    AIPlayPhase_Entry_0040F110 entries_[5];
    AIPlayPhase_Entry_0040F110 *command(int index);
};

AIPlayPhase_Entry_0040F110 *AIPlayPhase::command(int index) {
    if (index < 0 || index >= 5) return 0;
    return &this->entries_[index];
}
