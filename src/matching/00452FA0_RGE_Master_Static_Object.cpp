extern "C" void __cdecl free(void* block);

class RGE_Master_Static_Object {
public:
    char gap_04[0x4];
    char* name;
    char gap_0C[0x88];
    void* damage_sprites;

    virtual ~RGE_Master_Static_Object();
};

RGE_Master_Static_Object::~RGE_Master_Static_Object() {
    if (this->name != 0) {
        free(this->name);
        this->name = 0;
    }
    if (this->damage_sprites != 0) {
        free(this->damage_sprites);
        this->damage_sprites = 0;
    }
}
