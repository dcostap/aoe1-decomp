class TCommunications_Handler {
public:
    int NewCommand(void* command, int size, int ordered);
    unsigned char new_command(void* command, int size);
};

unsigned char TCommunications_Handler::new_command(void* command, int size) {
    return (unsigned char)NewCommand(command, size, 0);
}
