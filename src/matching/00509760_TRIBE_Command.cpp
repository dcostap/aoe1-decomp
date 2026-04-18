class TRIBE_Command {
public:
    void parent_destroy();
    void destroy();
};

void TRIBE_Command::destroy() {
    this->parent_destroy();
}
