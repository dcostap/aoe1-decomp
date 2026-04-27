// VA: 00433F20 do_command_order (880B)
// Command.cpp

class Commands {
public:
    char gap4[0x4];
    int field_8;
    
    void do_command_order(int* cmd);
};

int __cdecl sub_00432F20(int a1, int a2, int a3, int a4);

void Commands::do_command_order(int* cmd) {
    int byteVal = *(unsigned char*)((char*)cmd + 8);
    int* cmdData = (int*)((char*)cmd + 0x14);
    int* objInfo = *(int**)((char*)cmd + 4);
    
    int result = sub_00432F20((int)objInfo, 0, 0, byteVal);
    if (result) {
        field_8 = result;
    }
}
