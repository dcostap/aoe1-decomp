// VA: 00434400 do_command_move (1186B)
// Command.cpp

class Commands {
public:
    char gap4[0x4];
    int field_8;
    
    void do_command_move(int* cmd);
};

int __cdecl sub_00432F20(int a1, int a2, int a3, int a4);

void Commands::do_command_move(int* cmd) {
    int* objInfo = *(int**)((char*)cmd + 4);
    int byteVal = *(unsigned char*)((char*)cmd + 8);
    
    int result = sub_00432F20((int)objInfo, 0, 0, byteVal);
    if (result) {
        field_8 = result;
    }
}
