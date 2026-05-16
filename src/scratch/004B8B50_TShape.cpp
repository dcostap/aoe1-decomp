// VA: 004B8B50 TShape::TShape
// Source: Shape.cpp lines 67-176
// Attempt log:
// 1: natural constructor reconstruction from packet: initialize fields, try .SLP/.SHP file loads, then resource lookup fallback; compile issue from goto over fd and bad pragmas.
// 2: increased local filename buffer to 260 bytes to match original 0x104 stack reservation; fixed frame size but prologue/register and helper factoring still broad.
// FLAGS: config/flags/004B8B50_TShape.rsp
// 3: tried /Oi to encourage inline string ops like original rep movs/scas; no change.
// 4: tried /O1 /Oy flag probe; object shrank to 546 and failed configured size.
// 5: tried /O2 /Oy /Ob0 flag probe; no change, flag removed.
// 6: reviewed original string handling: source likely inlined strcpy/strlen by writing extension directly into local buffer; helper factoring keeps rebuilt in different basin.
// 7: current source has correct stack reservation and total size, but prologue differs (original zeroes eax before saves and uses EBP=this; rebuilt saves ESI first and uses ESI=this).
// 8: call surface modeled: color_log, open/lseek/tell/malloc/read/close, resource_load fallback, Shape_Loads, signature check.
// 9: leaving broad mismatch: file-extension buffer construction and branch factoring produce very different block layout despite similar behavior.
// 10: not accepted_drift-safe; constructor memory effects/call ordering around file loads and fallback need exact review.

#include <string.h>

extern "C" void __cdecl color_log(int, int, int);
extern "C" int __cdecl open_file(const char*, int);
extern "C" int __cdecl lseek_file(int, long, int);
extern "C" int __cdecl tell_file(int);
extern "C" void* __cdecl malloc_file(unsigned int);
extern "C" int __cdecl read_file(int, void*, unsigned int);
extern "C" int __cdecl close_file(int);
extern "C" void* __cdecl resource_load(unsigned int, int, int*, int*);

#define shape_file_first (*(unsigned char*)0x0086BBFC)
#define Shape_Loads (*(int*)0x0086BBE8)
#define shape_signature (*(int*)0x0057FB58)
#define SLP_EXT ((const char*)0x00586FAC)
#define SHP_EXT ((const char*)0x00586FA8)

class TShape {
public:
    void* shp_data;       // +00
    int loaded;           // +04
    int size;             // +08
    int field_0c;         // +0C
    void* shape;          // +10
    void* frames;         // +14
    void* slp_data;       // +18
    void* slp_frames;     // +1C

    TShape(const char* filename, int resource_id);
};

static void append_ext(char* dst, const char* src, const char* ext)
{
    strcpy(dst, src);
    char* p = dst + strlen(dst) - 4;
    strcpy(p, ext);
}

TShape::TShape(const char* filename, int resource_id)
{
    this->shp_data = 0;
    this->field_0c = 0;
    this->shape = 0;
    this->frames = 0;
    this->slp_data = 0;

    int fd;
    int id;
    if (!shape_file_first) {
        id = resource_id;
        if (id >= 0) {
            goto resource_path;
        }
    }

    this->loaded = 1;
    color_log(0x54, 0x54, 1);

    char name[260];
    append_ext(name, filename, SLP_EXT);
    Shape_Loads++;
    fd = open_file(name, 0x8000);
    if (fd != -1) {
        lseek_file(fd, 0, 2);
        int sz = tell_file(fd);
        this->slp_data = malloc_file(sz);
        lseek_file(fd, 0, 0);
        read_file(fd, this->slp_data, sz);
        close_file(fd);
        this->slp_frames = (char*)this->slp_data + 0x20;
        this->loaded = 1;
        this->size = sz;
    }

    if (this->slp_data == 0) {
        append_ext(name, filename, SHP_EXT);
        fd = open_file(name, 0x8000);
        if (fd != -1) {
            lseek_file(fd, 0, 2);
            int sz = tell_file(fd);
            this->shp_data = malloc_file(sz);
            lseek_file(fd, 0, 0);
            read_file(fd, this->shp_data, sz);
            close_file(fd);
            this->shape = this->shp_data;
            this->frames = (char*)this->shp_data + 8;
            this->loaded = 1;
            this->size = sz;
        }
    }

    color_log(0x54, 0x5f, 1);
    id = resource_id;
resource_path:
    if (this->slp_data == 0 && this->shp_data == 0 && id >= 0) {
        Shape_Loads++;
        this->shp_data = resource_load(0x73687020, id, &this->loaded, &this->size);
        if (this->shp_data != 0) {
            if (*(int*)this->shp_data == shape_signature) {
                this->shape = this->shp_data;
                this->frames = (char*)this->shp_data + 8;
                return;
            }
        } else {
            this->shp_data = resource_load(0x736c7020, id, &this->loaded, &this->size);
            if (this->shp_data != 0) {
                this->slp_data = this->shp_data;
                this->slp_frames = (char*)this->shp_data + 0x20;
                this->shp_data = 0;
            }
        }
    }
}
