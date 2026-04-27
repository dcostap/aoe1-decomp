// VA: 00434A00 do_command_formation (775B)
// Command.cpp

class Commands {
public:
    char gap4[0x4];
    int field_8;
    char gapC[0x24];
    int field_30;
    
    void do_command_formation(int* cmd);
};

int __cdecl sub_00432F20(int a1, int a2, int a3, int a4);

void Commands::do_command_formation(int* cmd) {
    int count = *(int*)((char*)cmd + 4);
    int* data = (int*)((char*)cmd + 0x0C);
    
    if (count == 1) {
        field_8 = count;
    }
    
    int result = sub_00432F20((int)cmd, 0, 0, count);
    if (result) {
        field_30 = result;
    }
}
