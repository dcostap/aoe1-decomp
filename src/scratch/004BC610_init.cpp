// Attempt log:
// - Baseline local COM/vtable reconstruction had exact size/frame but the
//   DirectSound import name was wrong and SetFormat failure was treated as a
//   cleanup edge not present in the executable.
// - Renamed the import to the period DirectSoundCreate WINAPI symbol.
// - Reconstructed the positive CreateSoundBuffer body: SetFormat's result is
//   overwritten by Play, and the two observed Release effects remain separate
//   source paths even though VC5 still merges their emitted call site.
// - Restored the VC5-era DSOUND.H interface surface and moved DSCAPS size
//   initialization to the GetCaps band; this moved the first mismatch to the
//   capability/priority flag and improved the structural diff substantially.
// - Binary evidence fixes the format to 22050 Hz / 44100 average bytes/sec.
// - The remaining blocker is VC5 commoning one of the two original indirect
//   Release sites and associated register/frame coloring; no productive lead
//   remains in this bounded pass.
// - A natural typed DirectSound local for the cooperative-level failure kept
//   both Release call sites and aligned all 12 calls, but grew the function by
//   26 bytes; restored the clean member-based source.
// - Replaced the goto around cooperative-level setup with a natural nested
//   if/else: failed priority setup falls through to normal setup, while the
//   successful priority path sets the format flag after that call site.
// - Made the cooperative success flag an int; VC5 now keeps it in EBP and the
//   primary-buffer field address in EBX, as in the original register lifetime.
// - Removed the fmt memset; the binary writes each WAVEFORMATEX field directly
//   after the primary-buffer call, unlike the zero-fill path used by dsbd.
// - Tried a positive cooperative-level outer branch with a separate failure
//   cleanup arm; it made the first CFG hunk worse, so it was rolled back.
// - A branch-local typed DirectSound receiver for cooperative cleanup was
//   optimized away and did not split the Release site; restored member access.
// - Reordered the natural WAVEFORMATEX assignments to average rate, block
//   align, then bit depth, matching the binary's post-push store order.
// - Captured the created DirectSound interface before capability setup and
//   used that typed receiver only for cooperative failure cleanup.
// - Used the binary-supported shared buffer-failure cleanup edge: CreateSoundBuffer
//   jumps to it on failure, while successful Play jumps over it to initialization.
// - The explicit buffer-failure labels changed the call sequence and were
//   rolled back; retain the natural CreateSoundBuffer success body.
// - A typed pointer-to-member slot did not retain the separate Release site;
//   restored the captured receiver, which gives 12-call parity and the best
//   structural result in this claim.
// - Moved the natural DirectSound receiver initialization below GetCaps; this
//   worsened the first mismatch to the capability flag and raised the diff to
//   310 bytes, so restored the captured receiver before final validation.
// - This claim rechecked the clean captured-receiver source: 12 ordered calls,
//   frame 0x88, and saved EBX/EBP/ESI/EDI remain exact, but the alias adds a
//   pre-GetCaps mov ebx,eax and leaves a 7-byte size excess.
// - Removing the alias, delaying it, or using branch-local pointer, reference,
//   alternate COM, and inline-wrapper receivers removes one Release call site
//   and expands the structural mismatch to 402 meaningful bytes; all were
//   restored. These forms do not preserve the original cleanup CFG.
// - Final unchanged validation remains MISMATCH: 171 strict differing bytes
//   (40.0468%), 427 rebuilt bytes, 12/12 ordered calls, and matching frame.
// - Next evidence needed is the period Sounddrv.cpp cleanup expression or a
//   source-level distinction that keeps both direct-member Release sites
//   without the early alias load. No source owner or ABI change is justified.
// - A new focused claim tested natural conditional/comma cleanup forms, typed
//   pointer aliases, explicit else flow, and IUnknown receiver spellings.
//   These either duplicate the clean result, merge one Release site, or emit
//   a wrong direct IUnknown call. The captured receiver remains authoritative.
// - Revisited the clean source with the target dossier and original listing.
//   The success call reloads this->main_wnd at 004BC781, not the incoming hwnd
//   home, so restored that natural member expression. This improved the strict
//   diff from 171 to 166 bytes and reduced rebuilt size from 427 to 423 bytes.
// - Nested Play-success return, direct duplicate Release, reference alias,
//   short-lived Play-result, and explicit buffer-failure label forms were
//   tested. They either merged one Release call, changed the call/CFG shape,
//   or duplicated the clean result. The member-reload source remains pinned.
#include <string.h>
#include <dsound.h>

extern "C" void __cdecl ds_stream_init(void* main_wnd, void* direct_sound, void* primary_buffer);
extern void __cdecl TSound_Driver_set_path(void*, char*);

class TSound_Driver {
public:
    unsigned char ready;
    unsigned char mute;
    unsigned char gap_02[2];
    void* main_wnd;
    IDirectSound* direct_sound;
    IDirectSoundBuffer* primary_buffer;
    int dsrval;
    char gap_14[0x04];
    int volume;
    char path[260];
    int mixer_open;
    void* mixer_handle;
    void set_path(char*);
    int init(void* hwnd, char* path);
    int open_mixer(void);
};

int TSound_Driver::init(void* hwnd, char* path) {
    int has_secondary;
    DSCAPS dscaps;
    DSBUFFERDESC dsbd;
    WAVEFORMATEX fmt;
    IDirectSound* sound;

    this->set_path(path);
    this->main_wnd = hwnd;
    this->ready = 0;

    this->dsrval = DirectSoundCreate(0, &this->direct_sound, 0);
    if (this->dsrval != 0) return 0;

    sound = this->direct_sound;

    dscaps.dwSize = 0x60;
    this->direct_sound->GetCaps(&dscaps);

    has_secondary = 0;

    if ((dscaps.dwFlags & 8) != 0) {
        this->dsrval = this->direct_sound->SetCooperativeLevel((HWND)this->main_wnd, 2);
        if (this->dsrval != 0) {
            this->dsrval = this->direct_sound->SetCooperativeLevel((HWND)this->main_wnd, 1);
        } else {
            has_secondary = 1;
        }
    } else {
        this->dsrval = this->direct_sound->SetCooperativeLevel((HWND)this->main_wnd, 1);
    }

    if (this->dsrval != 0) {
        sound->Release();
        this->direct_sound = 0;
        return 0;
    }

    memset(&dsbd, 0, sizeof(dsbd));
    dsbd.dwSize = 0x14;
    dsbd.dwFlags = 1;
    this->dsrval = this->direct_sound->CreateSoundBuffer(&dsbd, &this->primary_buffer, 0);
    if (this->dsrval == 0) {
        if (has_secondary) {
            fmt.wFormatTag = 1;
            fmt.nChannels = 1;
            fmt.nSamplesPerSec = 0x5622;
            fmt.nAvgBytesPerSec = 0xAC44;
            fmt.nBlockAlign = 2;
            fmt.wBitsPerSample = 0x10;
            fmt.cbSize = 0;
            this->dsrval = this->primary_buffer->SetFormat(&fmt);
        }

        this->dsrval = this->primary_buffer->Play(0, 0, 1);
    }

    if (this->dsrval != 0) {
        this->direct_sound->Release();
        this->direct_sound = 0;
        return 0;
    }

    this->ready = 1;
    ds_stream_init(this->main_wnd, this->direct_sound, this->primary_buffer);
    this->open_mixer();
    return this->ready;
}
