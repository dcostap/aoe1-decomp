// VA: 0053D8E0 command_make_do (141B)
// vw_dimap.cpp

class RGE_Diamond_Map_View {
public:
    virtual ~RGE_Diamond_Map_View();
    char gap0[0xF8];
    void* gameObj;    // +0xF8
    
    int command_make_do(int a1, int a2);
};

int __cdecl command_make_parse(int* outX, int* outY, int* some1, int* some2, int a1, int a2);

int __cdecl command_make_execute_do(void* view, int a1, int a2, int a3);

extern int g_some_global;  // [58631Ch]

int RGE_Diamond_Map_View::command_make_do(int a1, int a2) {
    int parsed[4];  // local coords
    int result;
    
    if (!g_some_global) return 0;
    
    result = command_make_parse(&parsed[0], &parsed[1], &parsed[2], &parsed[3], a1, a2);
    if (!result) return 0;
    
    // Process parsed screen coords
    int screenX = (short)parsed[0];
    int screenY = (short)parsed[1];
    float fx = (float)screenX - 0.5f;  // 5777E8h = 0.5f ?
    float fy = (float)screenY;
    
    // Convert to world coords via some object
    command_make_execute_do(gameObj, *(int*)&fx, *(int*)&fy, 0);
    
    return 1;
}
