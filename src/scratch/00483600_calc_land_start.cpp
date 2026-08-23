// 00483600 RGE_RMM_Database_Controller::calc_land_start
// rmm_dbct.cpp, source lines 435-545.
//
// Attempt log:
// try 1-11 (prior worker): broad decompiler-shaped reconstruction. It used
// roundFloat/rand_scaled helpers and an incorrectly sized local slot record;
// the resulting 960-byte output had five extra helper calls and a 0x2c frame.
// try 12: restored the period typed RGE_Land_Info ownership (0x34-byte lines),
// inline debug_rand scaling, the x87 sqrt/bound expressions, and the binary's
// retry-on-inner-box / retry-on-close-neighbor control flow.
// try 13: restored the same-TU polymorphic base/controller surface; emitted
// bytes were unchanged, confirming the touched offsets are already canonical.
// try 14: delayed radius+radius until after the first log; this moved the
// callee-save coloring and improved the positional diff to 970 bytes.
// try 15: tested a saved original-radius plus typed current/previous cursor
// mode-2 source; it reached 967 bytes but grew the function to 1067 bytes and
// lost block coverage, so it was restored to the cleaner 1059-byte candidate.
// try 16: named map-range and register-qualified radius probes were codegen
// duplicates; no further source axis was productive within this assignment.
// try 17: changed the retry state from int to typed bool; the packet's byte
// parameter-home writes became a 0x30-frame, 0-byte-size candidate and cut
// positional drift from 970 to 575 bytes while preserving all 16 calls.
// worker probes: inverted the mode-2 bounds arm, removed the doubled-radius
// local, named the controller, hoisted distance deltas, and saved the radius;
// each was a codegen duplicate. Reusing the radius parameter as the loop index
// preserved some late blocks but grew the frame to 0x34 and drift to 1002.
// An explicit inner while loop was also a duplicate. Restore the typed-bool
// candidate; the remaining gap is saved-register and local-home allocation.
// current: retain the bool candidate; calls and frame are exact, while the
// remaining drift is block shape and register/local-home placement.
// Named rmm_dbct.cpp and debug-log literals retained the typed source and
// improved positional drift to 570 bytes.
// Current worker pass (probes 1-30): canonical long/RGE data ownership and the
// same-TU controller virtual surface were codegen duplicates. Float suffixes on
// the two branch scale constants improved drift from 570 to 568 bytes. The
// executable proves one shared retry-store block: an accepted box candidate and
// an accepted distance candidate both reach it, while scan exhaustion skips it.
// Explicit labels for that block improved drift to 544 bytes with exact frame,
// size, call count, and CFG counts. Typed explicit scan cursors, parameter
// mutation, declaration scopes, and register hints did not improve it. The
// current clean source remains unresolved at the saved-register/local-home
// boundary, with target this=EDI/two=EBP versus rebuilt this=EBP/two=EDI.
// Current claim pass (probes 1-17): direct radius expressions, saved-radius
// copies, register hints, canonical long field declarations, base virtual order,
// function-scope and case-local temporaries, explicit member ownership, and a
// named distance accumulator were neutral or worse. The clean source is
// restored. Final validation remains a 544-byte mismatch with exact size/frame,
// all 16 ordered calls, and the same CFG counts. The open lead is the natural
// declaration or register basin that preserves the target's EBX radius and
// EBP doubled-radius roles while spilling inner deltas to the observed homes.
// Follow-up exact-finish pass: refreshed the canonical header ABI and rebuilt
// the natural source. The body remains a 544-byte mismatch before boundary
// padding. The owner symbol, 16 ordered calls, x87 conversion sequence, and
// 0x30 frame remain correct. Fresh probes found no new codegen basin:
// narrow x/y, narrow bounds, narrow indices, declaration order, case-local
// coordinates, controller aliasing, header context, and function-scope two
// were duplicates or worse. Natural retry control flow reached 568 bytes.
// Reusing radius as the outer index reached 1005 bytes, a 0x34 frame, and
// broke the boundary. Restore the simpler loop form.
// BINARY NOTE: The rebuilt object ends at 00483A15, ten bytes before target.
// Earlier cached checks padded this body with ten NOP bytes. The compiler
// object does not emit those bytes. Do not claim exactness from stale padding.
//
// Context audit: rmm_dbct.cpp owners 00483020, 00483200, 00483430, 00483540,
// and 004835A0 now use one canonical random-map base and controller record
// surface. This owner follows those exact anchors in PDB address order. The
// target remains unresolved; this context pass does not establish exactness.
// Individual anchor checks remain exact: 00483020 (466), 00483200 (213),
// 00483430 (264), 00483540 (84), and 004835A0 (82). A diagnostic combined
// object with these owners and this target keeps 00483200, 00483540, and
// 004835A0 exact, but 00483020 and 00483430 change under combined-TU codegen;
// it is not a safe exact group. The same object leaves this target at 1056
// bytes, exact frame and ordered calls, with a 544-byte strict mismatch.
// The authentic address sequence also contains unresolved 00482B70 before
// these anchors and accepted-drift 004832E0 between them. Do not claim a full
// rmm_dbct.cpp prefix until those owners are resolved or explicitly excluded
// by the main-agent context review.
// Current exact-finish probes: an original-radius copy and a reduced
// rmm_base_context.h declaration surface were codegen duplicates. Typed outer
// and inner output cursors changed the frame or worsened the body to 719 bytes;
// a single typed scan cursor and a single output cursor reached 666 and 697.
// All variants were restored. The natural source remains the 544-byte clean
// checkpoint with exact frame, size, ordered calls, and x87 call sequence.
// Specialist pass: the original listing places retry=false inside the inner
// candidate do body, after its random-call pushes. This improved shape, but
// retained a wrong local-home basin. A preguarded outer do/while with a
// function-scope index reached a 516-byte mismatch with 0x30 frame and all
// 16 ordered calls, but swapped this/two registers and output-pointer homes.
// A scoped saved-radius plus parameter-index form reached 645 bytes and kept
// 334 instructions, but added a jump and did not match the target homes.
// Parameter-index forms without a scoped lifetime grew the frame to 0x34.
// Restore the simpler clean source. Do not retain these nonexact forms.

#include <math.h>
#include "..\..\include\rmm_dbct_context.h"

static char s_rmm_dbct_path[] = "C:\\msdev\\work\\age1_x1\\rmm_dbct.cpp";
static char s_calc_land_start[] =
    "********Random Map calc land start, rand: %d";
static char s_calc_land_end_point1[] =
    "********Random Map calc land end (point1) ";
static char s_calc_land_end_point2[] =
    "********Random Map calc land end (point2) ";
static char s_calc_land_end_point3[] =
    "********Random Map calc land end (point3) ";
static char s_calc_land_xy[] =
    "********Random Map calc land xy player %d (%d, %d)";
static char s_calc_land_end[] =
    "********Random Map calc land end, rand:";

void RGE_RMM_Database_Controller::calc_land_start(
    long start, long radius, long count, RGE_Land_Data_Entry* land) {
    long i;
    long j;
    long x;
    long y;
    bool retry;
    float bound;
    long minx;
    long miny;
    long maxx;
    long maxy;

    L->Log(s_calc_land_start, debug_rand(s_rmm_dbct_path, 0x1c3));
    long two = radius + radius;
    bound = (float)(this->map_width - two) / sqrt((float)count);
    if (count > 3 && count < 7)
        bound *= 0.9F;
    else if (count >= 7)
        bound *= 0.8F;

    // BINARY NOTE: The scale factors here are 4-byte float constants.
    // The coordinate factors below are 8-byte constants in the executable.
    float bound_square = bound * bound;
    minx = (int)((this->map_width / 2) - (bound * 0.9));
    miny = (int)((this->map_height / 2) - (bound * 0.9));
    maxx = (int)((this->map_width / 2) - (bound * -0.9));
    maxy = (int)((this->map_height / 2) - (bound * -0.9));
    if (minx <= radius) minx = radius + 1;
    if (miny <= radius) miny = radius + 1;
    if (maxx >= this->map_width - radius - 1) maxx = this->map_width - radius - 2;
    if (maxy >= this->map_height - radius - 1) maxy = this->map_height - radius - 2;

    switch (land->placement_type) {
    case 0:
        L->Log(s_calc_land_end_point1);
        for (i=start;i<start+count;i++) {
            this->land_info.land[i].x = (debug_rand(s_rmm_dbct_path, 0x1e5) * (this->map_width - two)) / 0x7fff + radius;
            this->land_info.land[i].y = (debug_rand(s_rmm_dbct_path, 0x1e6) * (this->map_height - two)) / 0x7fff + radius;
        }
        break;
    case 1:
        L->Log(s_calc_land_end_point2);
        for (i=start;i<start+count;i++) {
            this->land_info.land[i].x = land->x;
            this->land_info.land[i].y = land->y;
        }
        break;
    case 2:
        L->Log(s_calc_land_end_point3);
        for (i=start;i<start+count;i++) {
            retry = 0;
            do {
                x = (debug_rand(s_rmm_dbct_path, 0x1fc) * (this->map_width - two)) / 0x7fff + radius;
                y = (debug_rand(s_rmm_dbct_path, 0x1fd) * (this->map_height - two)) / 0x7fff + radius;
                if (x > minx && x < maxx && y > miny && y < maxy)
                    goto retry_found;
                for (j=start; j<i; ++j) {
                    int dx=x-this->land_info.land[j].x; if (dx<0) dx=-dx;
                    int dy=y-this->land_info.land[j].y; if (dy<0) dy=-dy;
                    if ((float)(dx*dx + dy*dy) <= bound_square) {
                        if (j == i - 1) {
                            this->land_info.land[i].x = x;
                            this->land_info.land[i].y = y;
                            L->Log(s_calc_land_xy, i, x, y);
                        }
                        goto retry_found;
                    }
                }
                goto retry_done;
retry_found:
                // BINARY NOTE: Both accepted candidates use this retry store.
                retry = 1;
retry_done:
                ;
            } while (retry);
            this->land_info.land[i].x=x; this->land_info.land[i].y=y;
            L->Log(s_calc_land_xy, i, x, y);
        }
        break;
    default:
        break;
    }
    L->Log(s_calc_land_end);
}
