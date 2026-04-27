// VA: 0053DA10 command_make_work (156B)
// vw_dimap.cpp

class RGE_Diamond_Map_View {
public:
    virtual ~RGE_Diamond_Map_View();
    char gap0[0xF8];
    void* gameObj;
    
    int command_make_work(int a1, int a2);
};

int __cdecl command_make_parse(int* outX, int* outY, int* outW, int* outH, int a1, int a2);
int __cdecl command_make_execute_work(void* obj, int fx, int fy, int flags);

extern int g_some_global;

int RGE_Diamond_Map_View::command_make_work(int a1, int a2) {
    int parsed[4];
    int result;
    
    if (!g_some_global) return 0;
    
    result = command_make_parse(&parsed[0], &parsed[1], &parsed[2], &parsed[3], a1, a2);
    if (!result) return 0;
    
    int screenX = (short)parsed[0];
    int screenY = (short)parsed[1];
    float fx = (float)screenX - 0.5f;
    float fy = (float)screenY;
    
    command_make_execute_work(gameObj, *(int*)&fx, *(int*)&fy, 0);
    
    return 1;
}
