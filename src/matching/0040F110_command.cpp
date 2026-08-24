// 0040F110 AIPlayPhase::command

AIPlayPhaseCommand* AIPlayPhase::command(int index) {
    if (index < 0 || index >= 5)
        return 0;
    return &this->commands[index];
}
