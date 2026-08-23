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
// sa508a60b0_shape5 probes (2026-08-09):
// - Rechecked the old wrapper-based candidate: 541B/612 strict with 20 calls
//   and mismatched helper relocations.
// - Replaced wrappers with the exact CRT/resource symbols, inlined the natural
//   strcpy/strlen extension handling, and restored canonical TShape field
//   ownership; calls became 18/18 aligned and the candidate reached 688B/603.
// - Reusing the existing SLP filename buffer for SHP (no second filename copy)
//   reduced the candidate to 641B/559 strict with 93.04% shape similarity and
//   81.28% resync similarity. A loaded=1 local, including register-qualified
//   spelling, was codegen-duplicate and removed. Remaining gap is localized
//   VC5 prologue/constant liveness plus string-copy scheduling; call ABI and
//   broad constructor behavior are established.
// - Main-agent audit replaced fixed-address globals and extension pointers with
//   named symbols and ordinary string literals.
// shardB2-B8B50: folded both extension replacements into open(strcpy(...), 0x8000);
// this moved the flag push before the copy as in the original, reaching 635 bytes
// and 381 strict diff bytes. Remaining first mismatch is the color_log argument
// setup at 004B8B86; no class, signature, or flag changes were made.
// shardE-4B8B50: shared int/char/register type locals for the repeated value 1
// were codegen duplicates; restored the clean literal source.
// shardE-4B8B50: moving Shape_Loads++ after the first open improved strict diff
// by one byte but reduced block shape; restored the clean order.
// shardE-4B8B50: a diagnostic name+4 comma-expression matched more early blocks
// but worsened strict diff and source plausibility; restored the clean source.
// orch-4B8B50-a: PDB string evidence lists only filename/resource_file_id/NextFile;
// positive file guard, direct resource_file_id, and scoped type variants were
// codegen duplicates. Moving Shape_Loads++ after open reached diff 380 but had
// worse block shape, so the source-order and PDB-named clean form remains.
// - Named the resource header version field. The raw dword cast was a file-format
//   placeholder, not the owning source model.
// sa-a74ff577 revisit (2026-08-17):
// - Restored the inventory-proven typed TShape ownership: uchar* shape,
//   Shape_File_Header, Shape_Offsets, SLhape_File_Header, and Shape_Info.
// - Typed record arithmetic, a branch-local load-mode value, CRT header context,
//   and a sequenced counter expression were either codegen duplicates or worse.
// - Final natural source remains 635 bytes with 18 aligned calls; checker diff is
//   381 bytes. The first mismatch is the original EBX-held color-log constant.
// sa-c00eb8d9 revisit (2026-08-22):
// - Assignment-form and block-scoped `loaded = 1` locals reused for both file
//   stores and both color logs were codegen duplicates. Member assignment in the
//   first log was worse and added nine bytes.
// - Nested filename copy, array-subscript extension offsets, comma sequencing,
//   and expanded Shape_Loads increment forms did not improve the clean source.
// - Shape_Loads as a TU-local static and complete TShape overload declarations
//   were codegen duplicates. Restored the pinned natural source.
// - Original assembly still proves `mov ebx,1; push ebx` before the first log,
//   then EBX-backed load_type stores in both file-success arms and the second log.
//   The simplest source that causes this register liveness remains unresolved.
// sa-c2d88934-r1 revisit (2026-08-23):
// - Legacy PDB records confirm Shape.cpp, TShape size 0x20, fields at +00..+1C,
//   and only the NextFile local. The constructor has no base or vptr activity.
// - Grouped SLP publication, reversed SLP publication order, a register local,
//   scoped file locals, and declaration-order variants were exact-code duplicates.
// - Restored the pinned natural source. Fresh validation remains 635 bytes,
//   18 aligned calls, and 381 differing bytes. EBX constant liveness is blocked.

#include <string.h>

extern "C" void __cdecl color_log(unsigned char, unsigned char, int);
extern "C" int __cdecl open(const char*, int);
extern "C" int __cdecl lseek(int, int, int);
extern "C" int __cdecl tell(int);
extern "C" void* __cdecl malloc(unsigned int);
extern "C" int __cdecl read(int, void*, unsigned int);
extern "C" int __cdecl close(int);
extern "C" unsigned char* __cdecl RESFILE_load(unsigned long, unsigned long, int&, int&);

extern unsigned char shape_file_first;
extern int Shape_Loads;
extern int shape_version_110;

typedef unsigned char uchar;

struct Shape_Header {
    long bounds;
    long origin;
    long xmin;
    long ymin;
    long xmax;
    long ymax;
};

struct Shape_File_Header {
    long version;
    long shape_num;
};

struct Shape_Offsets {
    long shape;
    long palette;
};

struct SLhape_File_Header {
    char Version[4];
    long Num_Shapes;
    char Comment[24];
};

struct Shape_Info;

class TShape {
public:
    uchar* shape;         // +00
    int load_type;        // +04
    int load_size;        // +08
    Shape_Header* shape_header;       // +0C
    Shape_File_Header* head;          // +10
    Shape_Offsets* offsets;           // +14
    SLhape_File_Header* FShape;       // +18
    Shape_Info* shape_info;           // +1C

    TShape(char* filename, long resource_id);
};

TShape::TShape(char* filename, long resource_file_id)
{
    this->shape = 0;
    this->shape_header = 0;
    this->head = 0;
    this->offsets = 0;
    this->FShape = 0;

    char NextFile[260];
    int fd;
    if (shape_file_first || resource_file_id < 0) {
    color_log('T', 'T', 1);

    strcpy(NextFile, filename);
    Shape_Loads++;
    fd = open(strcpy(NextFile + strlen(NextFile) - 4, ".slp"), 0x8000);
    if (fd != -1) {
        lseek(fd, 0, 2);
        int sz = tell(fd);
        this->FShape = (SLhape_File_Header*)malloc(sz);
        lseek(fd, 0, 0);
        read(fd, this->FShape, sz);
        close(fd);
        this->shape_info = (Shape_Info*)(this->FShape + 1);
        this->load_type = 1;
        this->load_size = sz;
    }

    if (this->FShape == 0) {
        fd = open(strcpy(NextFile + strlen(NextFile) - 4, ".shp"), 0x8000);
        if (fd != -1) {
            lseek(fd, 0, 2);
            int sz = tell(fd);
            this->shape = (uchar*)malloc(sz);
            lseek(fd, 0, 0);
            read(fd, this->shape, sz);
            close(fd);
            this->head = (Shape_File_Header*)this->shape;
            this->offsets = (Shape_Offsets*)(this->shape + sizeof(Shape_File_Header));
            this->load_type = 1;
            this->load_size = sz;
        }
    }

    color_log('T', '_', 1);
    }

    if (this->FShape == 0 && this->shape == 0 && resource_file_id >= 0) {
        Shape_Loads++;
        this->shape = (uchar*)RESFILE_load(0x73687020, resource_file_id, this->load_type, this->load_size);
        if (this->shape != 0) {
            if (((Shape_File_Header*)this->shape)->version == shape_version_110) {
                this->head = (Shape_File_Header*)this->shape;
                this->offsets = (Shape_Offsets*)(this->shape + sizeof(Shape_File_Header));
                return;
            }
        } else {
            this->shape = (uchar*)RESFILE_load(0x736c7020, resource_file_id, this->load_type, this->load_size);
            if (this->shape != 0) {
                this->FShape = (SLhape_File_Header*)this->shape;
                this->shape = 0;
                this->shape_info = (Shape_Info*)(this->FShape + 1);
            }
        }
    }
}
