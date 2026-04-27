// VA: 00434920 do_command_give_attribute (210B)
// Command.cpp

class Commands {
public:
    char gap4[0x4];
    char field_8;
    
    void do_command_give_attribute(int* cmd);
};

void Commands::do_command_give_attribute(int* cmd) {
    int* objInfo = *(int**)((char*)cmd + 4);
    unsigned char byteVal = *(unsigned char*)((char*)cmd + 1);
    int* table = *(int**)((char*)objInfo + 0x40);
    int result = table[byteVal];
    
    unsigned char byteVal2 = *(unsigned char*)((char*)cmd + 3);
    if (byteVal2) {
        field_8 = (char)byteVal2;
    }
}
