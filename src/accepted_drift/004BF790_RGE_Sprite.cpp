// VA: 004BF790 RGE_Sprite::RGE_Sprite (656B)
// PDB source: sprite.cpp, lines 78-135
// Deserialization constructor; canonical sprite.cpp source module.
// Attempt log:
// - Replaced the field-only scaffold with the natural typed sprite
//   deserialization, draw-list allocation, and sound-facet reconstruction.
//   The first checker baseline was exact size/frame/call count, with 332
//   strict differing bytes and a register/liveness mismatch at the prologue.
// - Positive main-sound ID, self/file aliases, and count-guard spelling
//   variants did not change the emitted basin.  Final source retains the
//   ordinary typed deserializer and guarded three-entry facet loop; the
//   remaining blocker is the constructor's ESI/EDI allocation context and
//   downstream loop register topology.
// - Reordered the first assignments to last_time, delta_time, then
//   color_tables; the prologue moved farther from the oracle, so restored the
//   clean assignment order.
// - Tested the binary-proven parameter-home sound-ID writes with a file
//   alias; the direct-home form changed cleanup and grew by 70 bytes, while
//   a typed short materialization stayed in the same nonexact basin.
// - Hoisted the natural deserializer locals and split or reordered the file
//   alias assignment using the exact-TU donor pattern; output stayed at the
//   332-byte mismatch or moved to 338 bytes, so restored the clean source.
// - The remaining first hunk is the ESI/EDI assignment swap. No tested
//   natural alias or declaration-order lead changed that prologue.
// - A binary-guided facet cursor experiment recovered the original ESI/EDI
//   prologue and improved the diagnostic diff to 286 bytes, but added 8 bytes
//   and retained opaque cursor arithmetic. It was restored as diagnostic only.
// - A common typed main-sound result and an explicit positive draw-count guard
//   recovered the main-sound and draw-list CFG blocks and reduced the diff to
//   262 bytes.
// - An explicit positive micro-sound guard recovered the late zero-store
//   topology and reduced the diff to 227 bytes (91.53% shape, 247 instructions,
//   0x0C frame). Direct indexed and typed-pointer facet forms changed the frame
//   or register basin and were restored.
// - Final clean source keeps typed facet ownership. The blocker is the VC5
//   allocation and branch topology after the serialized header.
// - Exact-finish probes tested a natural initializer list, the canonical
//   class method surface, a file-handle alias, count-pointer aliases, and
//   period stdio context. The initializer, method, file, and stdio forms
//   were byte duplicates. Count-pointer aliases worsened the diff to 436.
//   Direct indexed facet members improved the diff to 197, but grew the
//   frame to 0x10 and the body to 687 bytes. Restore the typed facet form.
// - The proven TShape member type is retained. It is byte-identical to the
//   old void-pointer spelling. The original has no EH record, base call, or
//   vptr store, so this source does not invent constructor cleanup machinery.
// - Exact-finish follow-up compiled the canonical sprite owner header and
//   register-qualified read-only parameters. Both were byte duplicates.
// - A decompiler-supported typed integer-cursor loop recovered the original
//   ESI/EDI roles, frame, and most loop anchors. Its best result was 168
//   differing bytes with 94.40% shape and 672 bytes, so it was restored.
//   The remaining hunk requires the original EBP frame-cursor assignment and
//   the two omitted loop instructions. No natural reordering recovered them.
// ACCEPTED DRIFT: Size, frame, all 28 calls, and each serialized destination
// match. The original header keeps this in ESI and handle in EDI; the natural
// rebuild keeps the opposite. Both facet loops visit the same entries and
// read each frame before its sound ID. A nonnegative ID reads the same sound
// slot before the same list store. The rebuild retains the list pointer
// written by calloc, while the original reloads that member. rge_read never
// receives the member address, so it cannot change this value. Null branches,
// return values, allocation effects, fault order, and cleanup match. This
// constructor has no SEH.

extern "C" void __cdecl rge_read(int handle, void* buffer, int count);
extern "C" void* __cdecl calloc(unsigned int count, unsigned int size);

#include "..\..\include\sprite_context.h"

RGE_Sprite::RGE_Sprite(int handle, RGE_Sound** sounds,
                       RGE_Color_Table** color_tables)
{
    this->color_tables = color_tables;
    this->last_time = 0;
    this->delta_time = 0;

    rge_read(handle, this->name, 0x15);
    rge_read(handle, this, 0x0D);
    rge_read(handle, &this->resource_id, 4);
    rge_read(handle, &this->loaded, 1);
    rge_read(handle, &this->color_flag, 1);
    rge_read(handle, &this->draw_level, 1);
    rge_read(handle, &this->color_table, 2);
    rge_read(handle, &this->transparent_picking_flag, 1);
    rge_read(handle, &this->box_x1, 2);
    rge_read(handle, &this->box_y1, 2);
    rge_read(handle, &this->box_x2, 2);
    rge_read(handle, &this->box_y2, 2);
    rge_read(handle, &this->draw_list_num, 2);

    short main_sound_id;
    rge_read(handle, &main_sound_id, 2);
    rge_read(handle, &this->micro_man_sound, 1);
    rge_read(handle, &this->frame_num, 2);
    rge_read(handle, &this->facet_num, 2);
    rge_read(handle, &this->base_speed, 4);
    rge_read(handle, &this->duration, 4);
    rge_read(handle, &this->pause_between_loops, 4);
    rge_read(handle, &this->flags, 1);
    rge_read(handle, &this->id, 2);
    rge_read(handle, &this->mirror_flag, 1);

    RGE_Sound* main_sound;
    if (main_sound_id >= 0) {
        main_sound = sounds[main_sound_id];
    } else {
        main_sound = 0;
    }
    this->main_sound = main_sound;

    if (this->draw_list_num > 0) {
        this->draw_list = (RGE_Picture_List*)calloc(
            (unsigned int)this->draw_list_num, 0x10);
        rge_read(handle, this->draw_list,
                 ((int)this->draw_list_num) << 4);
    } else {
        this->draw_list = 0;
    }

    if (this->micro_man_sound != 0) {
        this->sound_list = (RGE_Sound_List*)calloc(
            (unsigned int)this->facet_num, 0x14);

        int i = 0;
        if (this->facet_num > 0) {
            do {
                RGE_Sound_List* facet = &this->sound_list[i];
                for (int j = 0; j < 3; ++j) {
                    rge_read(handle, &facet->frame[j], 2);
                    short sound_id;
                    rge_read(handle, &sound_id, 2);
                    if (sound_id < 0) {
                        facet->sound[j] = 0;
                    } else {
                        facet->sound[j] = sounds[sound_id];
                    }
                }
                ++i;
            } while (i < this->facet_num);
        }
    } else {
        this->sound_list = 0;
    }
}
