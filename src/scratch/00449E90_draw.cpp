// 00449E90 RGE_Flic_Player::draw
// Attempt log:
// 1: Natural reconstruction from packet/decompiler using known flic layout and helper methods: 38.8% diff; FlicHead was 0x80 not 0x84, shifting runtime fields 4 bytes low, and chunk switch compacted from min 7 instead of original min 4.
// 2: Fix FlicHead tail to size 0x84 and add no-op case 4 to widen switch range: down to 7.8% diff, remaining early coordinate setup register/order mismatch.
// 3: Reorder coordinate/drawarea assignments to mirror original source-line order and delay drawarea local: no change.
// 4: Remove drawarea local and use the parameter directly for the AlignedWidth/orientation block: no change.
// 5: Direct width/height expressions instead of locals: no change.
// 6: Load height before x2 assignment: no change.
// 7: Param locals for x/y/area and use those through setup: no change.
// 8: Precompute x2/y2 locals before stores: no change.
// 9: Temporary /O1 flag made function 441 bytes, wrong family; removed flag.
// 10: Temporary /Ob0 flag no change; removed flag.
// 11: Temporary /Od produced 91.54% broad mismatch; removed flag.
// 12: Reordered the natural coordinate stores to x1/x2/drawarea/height/y1/y2; emitted code unchanged.
// 13: Reused the stored drawarea member for later API/field accesses; this regressed to 248 differing bytes and was restored.
// 14: Declared height before width while retaining width-then-height loads; emitted code unchanged.
// 15: Focused four-way lab over natural coordinate order/direct-field forms produced two codegen groups, all at the 36-byte baseline diff.
// 16: Reversed the natural x2 addition operand order; emitted code unchanged.
// Fresh pass: widened width/height locals to int; VC5 emitted the same 36-byte diff, restored.
// Fresh pass: added a post-coordinate draw-area alias; emitted code unchanged, restored.
// Fresh pass: register-qualified dimensions and then parameters; emitted code unchanged, restored.
// Fresh pass: combined AlignedWidth and Orien into one product; emitted code unchanged, restored.
// Fresh pass: moved dimension declarations and reordered early locals; emitted code unchanged, restored.
// Fresh pass: moved the typed height load before x2, matching the original flics.cpp frame setup order; emitted code unchanged.
// Fresh pass: moved the natural height load after x2 and y1 to test the paired coordinate register order; emitted code unchanged, restored.
// Follow-up bounded pass: function-scope scalar declarations, pointer declaration
// order, y and draw-area aliases, register-qualified dimensions, separate pitch
// locals, and the decompiler's int* frame/chunk surface were codegen duplicates.
// Coordinate statement permutations formed one worse 23-byte-diff basin and did
// not recover the oracle register colors. Standard-header context variants were
// also duplicate. The natural 461-byte source remains the clean reconstruction;
// the remaining 36 differing bytes are localized to coordinate register coloring.
// BLOCKER: behavior and layout appear correct; remaining 7.8091% diff is localized codegen/register scheduling in coordinate setup after frame load. Original uses EBX for width then reuses EBX for drawarea (`movsx ebx,[esi+10] ... mov ebx,ecx`), while VC5 keeps width in ECX and loads drawarea into EBX early. Later switch/tail and frees are structurally aligned.
// Revisit validation: the clean source still builds to 461 bytes with 13 ordered calls, no frame, matching saved registers, and 36 differing bytes. Keep this natural source; further work needs new register-color evidence.

extern "C" void* calloc(unsigned int count, unsigned int size);
extern "C" void free(void* ptr);
extern "C" long lseek(int handle, long offset, int origin);
extern "C" int read(int handle, void* buffer, int size);

#pragma pack(1)
struct FlicHead {
    long size;
    unsigned short type;
    short frames;
    short width;
    short height;
    short depth;
    short flags;
    long speed;
    char reserved0[0x40];
    char* oframe1;
    char* oframe2;
    char reserved1[0x28];
};
#pragma pack()

class TDrawArea {
public:
    char gap_00[8];
    unsigned char* Bits;
    char gap_0c[0x10];
    long Height;
    char gap_20[4];
    long Orien;
    long AlignedWidth();
};

class RGE_Flic_Player {
public:
    unsigned char* flic_buffer; // +0
    int flic_handle;           // +4
    FlicHead flichead;         // +8
    TDrawArea* drawarea;       // +8c
    long drawarea_width;       // +90
    long flic_width;           // +94
    unsigned char* window_buffer; // +98
    unsigned char* save_buffer;   // +9c
    char* chunk;               // +a0
    long x1;                   // +a4
    long y1;                   // +a8
    long x2;                   // +ac
    long y2;                   // +b0
    long flic_size_x;          // +b4
    long flic_size_y;          // +b8

    unsigned char draw(TDrawArea* area, long x, long y);
    void literal();
    void delta_flc();
    void delta_fli();
    void black();
    void byte_run();
};

unsigned char RGE_Flic_Player::draw(TDrawArea* area, long x, long y)
{
    void* temp_buffer = 0;
    int* frame;
    char* chunk_base;

    if (this->flic_handle > -1) {
        frame = (int*)calloc(1, 0x10);
        lseek(this->flic_handle, (long)this->flichead.oframe2, 0);
        read(this->flic_handle, frame, 0x10);
        chunk_base = (char*)calloc(*frame, 1);
        temp_buffer = chunk_base;
        read(this->flic_handle, chunk_base, *frame);
    } else {
        frame = (int*)this->flichead.oframe2;
        chunk_base = (char*)frame + 0x10;
    }

    short width = this->flichead.width;
    this->x1 = x;
    this->drawarea = area;
    short height = this->flichead.height;
    this->x2 = (long)width + x;
    this->y1 = y;
    this->y2 = (long)height + y;

    long aw = area->AlignedWidth();
    aw *= area->Orien;
    this->drawarea_width = aw;
    if (area->Orien < 1) {
        this->window_buffer = area->Bits + this->x1 + ((this->y1 - area->Height) + 1) * aw;
    } else {
        this->window_buffer = area->Bits + this->x1 + aw * this->y1;
    }
    this->save_buffer = this->window_buffer;

    int i = 0;
    if (*(short*)((char*)frame + 6) > 0) {
        do {
            this->chunk = chunk_base + 6;
            switch (*(short*)(chunk_base + 4)) {
            case 4:
                break;
            case 0x10:
                this->literal();
                break;
            case 7:
                this->delta_flc();
                break;
            case 0x0c:
                this->delta_fli();
                break;
            case 0x0d:
                this->black();
                break;
            case 0x0f:
                this->byte_run();
                break;
            }
            chunk_base += *(int*)chunk_base;
            ++i;
        } while (i < *(short*)((char*)frame + 6));
    }

    this->flichead.oframe2 += *frame;
    unsigned char result;
    if ((this->flichead.oframe2 - (char*)this->flic_buffer) >= this->flichead.size) {
        this->flichead.oframe2 = this->flichead.oframe1;
        if (this->flic_buffer != 0) {
            this->flichead.oframe2 = this->flichead.oframe1 + *(int*)this->flichead.oframe1;
        }
        result = 2;
    } else {
        result = 0;
    }

    if (this->flic_handle > -1) {
        if (frame != 0) {
            free(frame);
        }
        if (temp_buffer != 0) {
            free(temp_buffer);
        }
    }
    return result;
}
