int __stdcall TRIBE_Player_load_master_object_impl(int a, int b, int c, int d, int e);

class TRIBE_Player_lmo {
public:
    int load_master_object(int a, int b, int c, int d, int e);
};

int TRIBE_Player_lmo::load_master_object(int a, int b, int c, int d, int e) {
    return TRIBE_Player_load_master_object_impl(a, b, c, d, e);
}
