// 0041F9F0 RGE_Base_Game::restart_music_system (basegame.cpp:2876-2888, 149B)
// STATUS: GIVEN_UP (2026-05-19)
// FLAGS: default
//
// Remaining mismatch: size 149 vs 144 (body bytes identical; prologue/epilogue
// structure differs: register save order, save timing, epilogue sharing).
// Boss denied accepted_drift due to size mismatch preventing byte-level review.
//
// Attempt log (2026-05-19):
// try 1-2: baseline - register saves at prologue, merged epilogues = 144B vs 149
// try 3: restructured with goto + separate return paths to force inline epilogues - still 144B
// try 4: removed ms local variable, used this->music_system directly - still 144B
// try 5: flag tries /G5, /Os, /GA - no change
// GIVEUP: VC5 internal prologue/epilogue heuristic mismatch; cannot override register save order
//   (ebx,esi,edi vs edi,esi,ebx) or save timing (prologue vs after early-null-check) from C++ source.
// Retry 2026-05-19 Boss pass: 10 source variants (self/ms locals, direct member access, shared-goto return, explicit pos/loop/to/cur locals, duplicate original tests, nested if/else, result local) all remained 144B or worse (one 128B). Flag probes /Od, /O1, /Ox, /O2 without /Oy did not help (/Od broad mismatch, /O1 110B, /Ox and /Oy- still 144B). Restored prior scratch.
// Retry 2026-05-20: 10 more variants: nested no-goto, self/ms locals, raw/direct calls, separate-goto epilogues, result local, duplicate tests, explicit pos/loop/to/cur locals, volatile music_system, single outer else, raw byte-offset members. All close variants still 144B; volatile music_system reached exact size but broad 71.8121% positional / 144.2953% edit regression; one explicit-local variant shrank to 128B. Restored 144B best.
// GIVEUP: same blocker remains. Original delays callee-save pushes until after the music_system null check and uses separate inline epilogues; VC5 C++ source keeps selecting the 144B shared-epilogue/prologue family unless volatile forces a completely wrong stack-home basin. Not accepted_drift: best is 5 bytes short and exact-size variant is broadly reordered.
// Retry 2026-05-21 Boss pass: tried explicit `self`/`ms` locals, raw byte-offset access to bias EAX=self/ECX=music_system, ms-before-self ordering, `register` self, `__stdcall` and int-return TMusic declarations, non-virtual declaration, /Ob0 and /Gz flag probes, and duplicate explicit track_from test/goto file-case shape. All close variants stayed 144B; no variant recovered original delayed `push edi; push esi; push ebx` with EAX self and ECX music_system. Restored prior 144B best; no accepted_drift proposal.
// Retry 2026-05-24 assigned pass: 15 further probes. Volatile music_system field/local and volatile-after-check variants reached exact 149B but were broad wrong stack-home/register families (best 69.7987% positional, first mismatch 0). Nested positive, separate return labels, ms local/direct-after-check stayed 144B or failed. Volatile track_from exact-size variant worsened to 91.9463%. Flag probes /Ob0 /Og /Oa /Ow /Gs /Gy on the best source all stayed 144B. Still not accepted_drift: best behavioral source is 5 bytes short; exact-size volatile families are broad byte-0 topology mismatches.
// Retry 2026-05-26 Boss pass: 10 further probes. Rechecked non-virtual explicit-vptr
// class surface, direct/no-local member access, `self` locals, no-local `save_music_track_from`
// rereads, TMusic return type `int` vs `void`, `register int from`, and combinations of
// self/from/to locals. All close variants still compile to the same 144-byte family with
// an initial `push ecx` stack home, eager EBX/ESI saves, and shared/short epilogues; none
// recover original `mov eax,ecx; mov ecx,[eax+64h]` null gate followed by delayed
// `push edi; push esi; push ebx`. No accepted_drift: best source is short/truncated, exact-size
// volatile variants from earlier are broad mismatches.

class TMusic_System {
public:
    void play_track(int track_from, int pos, int loop);
    void play_tracks(int track_from, int track_to, int pos, int cur_track, int loop);
    void play_file(char* filename, int pos, int loop);
};

class RGE_Base_Game {
public:
    // vtable at +0x00 (implicit from virtual function)
    char gap_04[0x60];
    TMusic_System* music_system;   // +0x64
    char gap_68[0x0C];
    int save_music_track_from;      // +0x74
    int save_music_track_to;        // +0x78
    int save_music_cur_track;       // +0x7C
    char save_music_file[4];        // +0x80
    char gap_84[0x100];
    int save_music_pos;             // +0x184
    int save_music_loop;            // +0x188

    virtual int restart_music_system();
};

int RGE_Base_Game::restart_music_system()
{
    if (!this->music_system)
        return 1;

    int track_from = this->save_music_track_from;
    if (!track_from)
        goto check_file;

    if (track_from == this->save_music_track_to) {
        this->music_system->play_track(track_from, this->save_music_pos, this->save_music_loop);
        return 1;
    }

    if (this->save_music_track_to) {
        this->music_system->play_tracks(track_from, this->save_music_track_to,
            this->save_music_pos, this->save_music_cur_track, this->save_music_loop);
        return 1;
    }

check_file:
    if (this->save_music_file[0]) {
        this->music_system->play_file(this->save_music_file, this->save_music_pos, this->save_music_loop);
    }

    return 1;
}
