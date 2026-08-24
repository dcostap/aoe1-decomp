// Authentic Sound.cpp owner wrapper.
//
// PDB source: C:\\msdev\\work\\age1_x1\\Sound.cpp
// The owner order below follows the shipped address and source-line order.
// The Sound.cpp EH owners require one common flag set:
//   /nologo /c /O2 /Oy /GX
// Use config/flags/004BBF30_RGE_Sound.rsp as the checked flag source.
// This wrapper is the canonical registered Sound.cpp translation unit.
//
// Exact anchors from the original PDB and image:
//   004BBE40  RGE_Sound(FILE*,short)       lines 35-58   230 bytes
//   004BBF30  RGE_Sound(int,TSound_Driver*) lines 64-89   306 bytes
//   004BC070  RGE_Sound()                 lines 94-98    15 bytes
//   004BC080  ~RGE_Sound()                lines 103-123  111 bytes
//   004BC0F0  RGE_Sound::save             lines 129-146  158 bytes
//   004BC190  RGE_Sound::restart_sound   lines 151-165  215 bytes
//   004BC270  RGE_Sound::update           lines 170-185   95 bytes
//   004BC2D0  RGE_Sound::set_cache_time   lines 190-192   10 bytes
//   004BC2E0  RGE_Sound::play_at_update   lines 197-199    4 bytes
//   004BC2F0  RGE_Sound::update_play      lines 204-210   23 bytes
//   004BC310  RGE_Sound::play            lines 215-273  346 bytes
//   004BC470  RGE_Sound::get_file_name   lines 278-299  121 bytes
//   004BC4F0  RGE_Sound::stop            lines 304-318   71 bytes
//   004BC540  RGE_Sound::is_playing      lines 323-339   76 bytes
//
// 004BBF30, 004BC270, and 004BC310 are included because their reviewed
// sources preserve shipped behavior.  They are not exact owners.  The other
// entries are exact or exact-owner candidates in src/matching.
//
// Candidate validation with config/flags/004BBF30_RGE_Sound.rsp compiles all
// 14 owners.  Positional bytes, original boundaries, and owner symbols are
// exact for 004BBE40, 004BC070, 004BC080, 004BC0F0, 004BC190, 004BC2D0,
// 004BC2E0, 004BC2F0, 004BC470, 004BC4F0, and 004BC540.  The observed
// verified-logic owners emit 309/306 bytes at 004BBF30 and 346/346 bytes at
// 004BC310.  The accepted-drift owner emits 97/95 bytes at 004BC270; its
// reviewed early-save-register movement remains the only difference in the
// meaningful loop after resynchronization.  The object has no defined
// compiler-generated Sound owner; VC5 emits the expected EH and helper
// references from the owning methods.

#define SOUND_CANONICAL_TU 1
#include "../include/sound_context.h"

#include "matching/004BBE40_RGE_Sound.cpp"
#include "verified_logic/004BBF30_RGE_Sound.cpp"
#include "matching/004BC070_RGE_Sound.cpp"
#include "matching/004BC080_RGE_Sound.cpp"
#include "matching/004BC0F0_save.cpp"
#include "matching/004BC190_restart_sound.cpp"
#include "accepted_drift/004BC270_update.cpp"
#include "matching/004BC2D0_set_cache_time.cpp"
#include "matching/004BC2E0_play_at_update.cpp"
#include "matching/004BC2F0_update_play.cpp"
#include "verified_logic/004BC310_play.cpp"
#include "matching/004BC470_get_file_name.cpp"
#include "matching/004BC4F0_stop.cpp"
#include "matching/004BC540_is_playing.cpp"
