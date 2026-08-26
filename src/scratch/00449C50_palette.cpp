// VA: 00449C50 RGE_Flic_Player::palette(tagRGBQUAD* palette)
// flics.cpp lines 81-171
// Palette chunks are decoded from either the in-memory frame stream or a
// temporary file-backed frame.  Keep the FLIC and frame headers typed so the
// 0x60 oframe2 field and 0x10 frame-header size are owned by their records.
// Attempt log:
// - Completed the skeleton with the canonical typed FlicHead/FrameHead and
//   tagRGBQUAD surfaces; calls, frame, and size then matched, but the first
//   guard/loop basin remained 368 differing bytes.
// - Reversed to the positive file-backed guard and assigned the payload owner
//   before read; this recovered the original 407-byte frame and call topology.
// - Matched the decoder's pointer progression by advancing once after the
//   skip byte and once after count normalization; best source is 407 bytes /
//   262 differing bytes with all seven direct calls aligned.
// - Function-scope counter/register and raw index1 variants were neutral; the
//   remaining structural gap is the original framehead stack reload/zero-home
//   order and EDX/ESI packet-count coloring.
// - Replaced the raw index1 cursor with the typed FrameHead pointer; emitted
//   code stayed identical, so the living source now keeps proven header
//   ownership without decompiler-only offset plumbing.
// - Added a typed two-byte PalettePacket for the packed skip/count header; this
//   preserved the natural +6 header anchor and +2 payload step and improved the
//   emitted result to 243 differing bytes.
// - Added a natural packet countdown local after each positive packet guard;
//   this recovered the original movsx/test/copy countdown topology and reached
//   the best 212-byte result with all seven relocated call sites aligned.
// - Scoped count/color/skip declaration variants were codegen duplicates; keep
//   the typed packet plus countdown as the clean source.  Remaining drift is
//   the FrameHead stack reload and payload count/palette-base register coloring.
// - This claim: sequencing/while-loop forms, count register qualification, a
//   typed count-byte cursor, and a long frame-address alias were duplicates or
//   regressed.  Retain the 407-byte typed source at 212 diff; the first gap is
//   the frame-count zero-home/reload order, followed by payload count and
//   palette-base coloring while all seven call relocations remain aligned.
// - This claim: moving/splitting the outer counter zero assignment, adding a
//   separate color countdown, reordering locals, and restoring stdlib context
//   were duplicates or regressed.  A binary-proven `handle > -1` cleanup guard
//   improved CFG shape but shifted the tail and was restored; a short packet
//   count widened the body.  Final clean result remains 407 bytes / 212 diff.
// - Replaced the typed packet-header advance with signed-byte cursor reads and
//   two separate post-increments, matching the original movsx-byte/two-inc
//   block.  Strict diff rose to 254, but exact-block coverage rose to 60.39%.
// - A separate payload color countdown was an emitted-code duplicate; retain
//   it because the oracle keeps packet count and payload countdown distinct.
// - Reopen claim: typed FrameHead aliases, a chunks reference, a scoped decoder
//   alias, an initialized header pointer, and a char storage view were all
//   codegen duplicates.  Restore the clean signed-byte candidate; the first
//   unresolved gap remains the FrameHead reload and zero-home order.
// - This claim: restored the prior typed-packet basin, then tested the direct
//   index1 alias, branch-local FrameHead, payload pre-decrement loops, and the
//   type-0x0B pre-increment destination form.  The best new metric was 241
//   differing bytes, but its packet anchor used a metric-only +6 cursor.
// - Restored the behavior-correct chunk+8 packet anchor and typed chunk view.
//   The final checked source is 407 bytes / 261 differing bytes, with seven
//   calls, the 0x10 frame, and 79.87% exact-block coverage.  The unresolved
//   gap is packet-base register coloring and the frame-count reload basin.
// - This claim: restored a natural FrameHead local and typed PaletteChunk
//   owner.  Typed chunk fields, declaration order, and unqualified counters
//   were codegen duplicates.  Natural type-0x0B assignment order regressed.
//   The clean source remains behavior-correct at 407 bytes / 261 differing
//   bytes, with all seven calls aligned and the 0x10 frame preserved.
// - Main review replaced the null-based pointer counter with an ordinary int
//   chunk index. The emitted code and validation metrics are unchanged.
// - This claim: removed the unused packet member from the typed chunk header
//   and used its typed successor as payload. Output stayed identical; retain
//   the simpler header surface.
// - Accepted-drift audit: do not promote this candidate. In a type-0x0B color
//   run, the rebuild advances the input cursor and decrements the color count
//   before the third palette store. The original does both after that store.
//   A fault on the third store therefore has a different register and loop
//   context, although successful output and cleanup match.
// - New claim: restored the binary-supported int* packed-chunk owner and the
//   ordinary chunk counter. Natural packet update order
//   now preserves the original type-0x0B store/fault order.  Strict diff fell
//   from 261 to 212 bytes; size, frame, and all seven calls remain exact.
// - New claim: signed-byte packet reads and two explicit header increments
//   recovered more original blocks (60.39% versus 47.40%), but strict diff
//   rose to 254 bytes.  Restore the typed two-byte packet header because it
//   is the smaller supported source basin.
// - New claim: raw frame-address, long-index, unused FrameHead, and split
//   temp-counter declarations were codegen duplicates.  The unresolved
//   first gap remains the original frame-header reload and ECX/ESI coloring.
// - Wrapper context pass: guarded the local donor declarations so the owner can
//   share the canonical packed FlicHead, FrameHead, tagRGBQUAD, and
//   RGE_Flic_Player declarations. Standalone codegen stayed unchanged.
// Exact-finish pass: the first frame-header hunk still requires the original
// stack reload and zero-home order. Prior typed-header, raw index, long-index,
// and declaration-scope forms remain the only supported basins; no new natural
// source recovered the missing register schedule.
// Audit continuation: the PDB lists long index1, char* temp_buffer, and a
// FrameHead pointer. Raw, typed, branch-local, and reordered forms stayed at
// 212 bytes of drift. Signed-byte packet reads recovered the original INC/INC
// blocks and 60.39% block coverage, but changed the 0-to-0x100 count behavior
// or reduced the body to 405 bytes. Restore the typed packet form.
// - This claim: FrameHead declaration order, a cleanup-only index1 alias, the
//   negative file guard, register count locals, payload declaration order, and
//   the reviewed full flics context were neutral or regressed. Restore this
//   typed source. The first unresolved hunk remains the ECX frame-header load.
// - Exact-finish continuation: authentic full flics.cpp compilation through
//   src/flics_tu.cpp preserved the 407-byte owner and all surrounding symbols.
//   PDB local-role, frame-address, loop-form, packet-cursor, signed-byte
//   header, pre-decrement, and type-0x0B store-order probes did not beat the
//   pinned 212-byte source. Restore the pinned source after every probe.
// - Behavior-correct finish: the packet cursor advances past the two-byte
//   packet-count field before each positive packet loop. Zero counts become
//   0x100. Type-0x0B advances the palette cursor before its three stores.
//   These forms preserve malformed stream bounds and store/fault order.
// - Final validation in full flics.cpp: 407-byte boundary, 0x10 frame, owner
//   symbol, and all seven direct calls match. The behavior-correct source has
//   66.88% exact-block coverage and 221 differing bytes.
// - Exact blocker: the original assigns the packed chunk to EBX and the
//   packet count to EBP. Natural VC5 assigns those roles in reverse here.
//   Tests with raw cursors, aliases, declaration order, and register locals
//   did not recover the original schedule without worse behavior or size.
// - BINARY NOTE: 0044A05D remains a reviewed padding-only flics.cpp boundary.
//   No compiler-facing owner was added or changed.
// Captain pass:
// - The context gate is proved by the flics.cpp PDB module, the 81-171 source
//   band, the RGE_Flic_Player owner, the linked address sequence, and the
//   seven direct calloc/lseek/read/free anchors.
// - A symmetric source form uses direct RGBQUAD addressing in both chunk arms
//   and remains 221 bytes different.  The behavior-preserving asymmetric form
//   uses a tagRGBQUAD* in type 4 and direct addressing in type 0x0B; it lowers
//   to 187 differing bytes without changing behavior, calls, frame, or owner.
// - Walkbacks proved the alias change is required for the improvement.  The
//   declaration-order change was codegen-neutral and was removed.  Byte cursors,
//   long counters, and split zero stores were neutral or worse.
// - The grouped candidate keeps all 13 exact owners, the two observed owners,
//   and the authentic flics.cpp include order.  Palette remains nonexact because
//   the original EBX/EBP packet and chunk allocation basin is unresolved.

#ifndef FLICS_SHARED_CONTEXT
extern "C" void* __cdecl calloc(unsigned int count, unsigned int size);
extern "C" void __cdecl free(void* block);
extern "C" int __cdecl lseek(int handle, int offset, int origin);
extern "C" int __cdecl read(int handle, void* buffer, unsigned int size);

struct FlicHead {
    long size;
    unsigned short type;
    short frames;
    short width;
    short height;
    short depth;
    short flags;
    long speed;
    short reserved1;
    unsigned char pad_16[2];
    long created;
    long creator;
    long updated;
    long updater;
    short aspect_dx;
    short aspect_dy;
    char reserved2[38];
    unsigned char pad_52[2];
    char* oframe1;
    char* oframe2;
    char reserved3[40];
};

struct FrameHead {
    long size;
    short type;
    short chunks;
    char reserved[8];
};

struct tagRGBQUAD {
    unsigned char rgbBlue;
    unsigned char rgbGreen;
    unsigned char rgbRed;
    unsigned char rgbReserved;
};

struct PalettePacket {
    signed char skip;
    signed char count;
};

class RGE_Flic_Player {
public:
    unsigned char* flic_buffer;
    int flic_handle;
    FlicHead flichead;
    void* drawarea;
    long drawarea_width;
    long flic_width;
    unsigned char* window_buffer;
    unsigned char* save_buffer;
    char* chunk;
    long x1;
    long y1;
    long x2;
    long y2;
    long flic_size_x;
    long flic_size_y;

    void palette(tagRGBQUAD* palette);
};
#endif

// Main-agent audit confirmed the typed file/frame/palette surfaces; byte cursors
// are retained only where the packed FLIC chunk format requires them.
void RGE_Flic_Player::palette(tagRGBQUAD* palette)
{
    FrameHead* framehead;
    int* chunk;
    int* frame_buffer = 0;
    int packets;
    int color_index;

    if (this->flic_handle > -1) {
        framehead = (FrameHead*)calloc(1, 0x10);
        lseek(this->flic_handle, (int)this->flichead.oframe2, 0);
        read(this->flic_handle, framehead, 0x10);
        chunk = (int*)calloc(framehead->size, 1);
        frame_buffer = chunk;
        read(this->flic_handle, chunk, framehead->size);
    } else {
        framehead = (FrameHead*)this->flichead.oframe2;
        chunk = (int*)((char*)framehead + 0x10);
    }

    int chunk_index = 0;
    if (0 < framehead->chunks) {
        do {
            if ((short)chunk[1] == 4) {
                packets = *(short*)((char*)chunk + 6);
                color_index = 0;
                unsigned char* packet = (unsigned char*)chunk + 6;
                packet += 2;
                if (0 < packets) {
                    int packet_count = packets;
                    do {
                        PalettePacket* packet_header = (PalettePacket*)packet;
                        int count = packet_header->count;
                        color_index += packet_header->skip;
                        packet = (unsigned char*)(packet_header + 1);
                        if (count == 0) {
                            count = 0x100;
                        }
                        if (0 < count) {
                            tagRGBQUAD* color = palette + color_index;
                            color_index += count;
                            int color_count = count;
                            unsigned char* green = &color->rgbGreen;
                            unsigned char* input = packet;
                            do {
                                unsigned char* next = input + 3;
                                green[1] = input[0];
                                green[0] = input[1];
                                ((tagRGBQUAD*)(green - 1))->rgbBlue = input[2];
                                green += 4;
                                input = next;
                            } while (--color_count != 0);
                            packet = input;
                        }
                        packet_count--;
                    } while (packet_count != 0);
                }
            }

            if ((short)chunk[1] == 0x0B) {
                packets = *(short*)((char*)chunk + 6);
                color_index = 0;
                unsigned char* packet = (unsigned char*)chunk + 6;
                packet += 2;
                if (0 < packets) {
                    int packet_count = packets;
                    do {
                        PalettePacket* packet_header = (PalettePacket*)packet;
                        int count = packet_header->count;
                        color_index += packet_header->skip;
                        packet = (unsigned char*)(packet_header + 1);
                        if (count == 0) {
                            count = 0x100;
                        }
                        if (0 < count) {
                            unsigned char* green = &palette[color_index].rgbGreen;
                            color_index += count;
                            int color_count = count;
                            do {
                                green += 4;
                                green[-3] = (unsigned char)(packet[0] << 2);
                                green[-4] = (unsigned char)(packet[1] << 2);
                                green[-5] = (unsigned char)(packet[2] << 2);
                                packet += 3;
                            } while (--color_count != 0);
                        }
                        packet_count--;
                    } while (packet_count != 0);
                }
            }

            chunk = (int*)((char*)chunk + *chunk);
            chunk_index++;
        } while (chunk_index < (int)framehead->chunks);
    }

    if (this->flic_handle >= 0) {
        if (framehead != 0) {
            free(framehead);
        }
        if (frame_buffer != 0) {
            free(frame_buffer);
        }
    }
}
