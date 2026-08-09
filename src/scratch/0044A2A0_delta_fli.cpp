// RGE_Flic_Player::delta_fli
// VA: 0044A2A0 (232 bytes)
// flics.cpp lines 445-488
// Decodes delta-FLIC video frames.
//
// Attempt log:
// - v1 baseline (natural reconstruction): chunk = this->chunk; count = *(int*)chunk;
//   chunk += 8; if (count <= 0) return; do { lines = (signed char)*chunk++; x = 0;
//   if (lines > 0) { do { x += *chunk; cnt = chunk[1]; chunk += 2;
//   if (cnt < 0) { cnt = -cnt; memset(window_buffer + x, *chunk, cnt); chunk++; }
//   else { memcpy(window_buffer + x, chunk, cnt); chunk += cnt; } x += cnt; }
//   while (--lines != 0); } window_buffer += drawarea_width; } while (--count != 0);
//   diff 282 -> 177 (shape 93.9%, size 233/232). Packet loop + loop bottoms already
//   byte-exact; only 3 localized gaps remained: count-spill placement, lines-spill
//   placement, and chunk+=2 vs two inc ebp.
// - v2: x=0 declared before chunk++; split chunk+=2 into chunk++; chunk++.
//   diff 177 -> 174 (shape 95.1%). x=0 order now matches (xor ebx,ebx before inc ebp)
//   but VC5 still merges the two increments into add ebp,2 (3B vs 2B). BEST state.
// - v3: wrapped outer do-while in if (count > 0) { ... } per Ghidra shape: REGRESSED
//   to 184 (shape 91.5%, size 235). Reverted to v2.
// - Remaining gap (v2): original spills count/lines to their home slots AFTER the
//   guard branches (count: [esp+18h] after jle + push edi/ebx; lines: [esp+14h] after
//   jle) in separate spill blocks; rebuilt spills both BEFORE the jle. Original also
//   emits two separate inc ebp for the packet-header advance (PDB lines 468/469)
//   while rebuilt merges to add ebp,2. Untried: barrier between the two chunk++
//   statements (e.g. +=1 forms, comma, or a use of chunk between them); for-loop
//   spelling of the packet loop; volatile/cast spelling of chunk[1].
// - This claim: separate success-path counters (`remaining` and `line_remaining`)
//   move both compiler spills after their guard branches and improve the result to
//   154 positional bytes / 97.56% shape / 233 emitted bytes. Pointer-local,
//   +=1, pre/post-increment, subscript-assignment, and payload-pointer variants
//   did not change that emitted code or improve the remaining header-advance gap.
//   A focused three-way header variant lab likewise found no exact or size-valid
//   candidate. Best source retained below; remaining mismatch is the two `inc ebp`
//   instructions at PDB lines 468-469 versus VC5's `add ebp,2`.
// - A typed payload pointer spanning the two header bytes reproduced an older
//   232-byte / 221-byte-diff basin and was rolled back; it did not provide a
//   useful source-level barrier for the separate increments.

#include <string.h>

class RGE_Flic_Player {
public:
    unsigned char* flic_buffer;   // +0x00
    int flic_handle;              // +0x04
    char flichead[0x84];          // +0x08
    void* drawarea;               // +0x8C
    long drawarea_width;          // +0x90
    long flic_width;              // +0x94
    unsigned char* window_buffer; // +0x98
    unsigned char* save_buffer;   // +0x9C
    char* chunk;                  // +0xA0
    long x1;                      // +0xA4
    long y1;                      // +0xA8
    long x2;                      // +0xAC
    long y2;                      // +0xB0
    long flic_size_x;             // +0xB4
    long flic_size_y;             // +0xB8

    void delta_fli();
};

// Main-agent audit confirmed canonical FLIC player/frame ownership and retained
// the natural packed delta decoder.
void RGE_Flic_Player::delta_fli()
{
    char* chunk = this->chunk;
    int count = *(int*)chunk;
    chunk += 8;
    if (count <= 0) return;
    int remaining = count;

    do {
        int lines = (signed char)*chunk;
        int x = 0;
        chunk++;
        if (lines > 0) {
            int line_remaining = lines;
            do {
                x += (signed char)*chunk;
                char cnt = chunk[1];
                chunk++;
                chunk++;
                if (cnt < 0) {
                    cnt = -cnt;
                    memset(this->window_buffer + x, *chunk, cnt);
                    chunk++;
                } else {
                    memcpy(this->window_buffer + x, chunk, cnt);
                    chunk += cnt;
                }
                x += cnt;
            } while (--line_remaining != 0);
        }
        this->window_buffer += this->drawarea_width;
        remaining--;
    } while (remaining != 0);
}
