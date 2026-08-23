// Authentic later basegame.cpp owner segment.
//
// PDB module: C:\\msdev\\work\\age1_x1\\basegame.cpp
// The registered basegame_prefix_tu.cpp ends at 0041EBF0.  This wrapper is
// deliberately unregistered.  It does not change that prefix or config.
//
// PDB owner order after the registered boundary:
//   0041ED00 setup_chat                  2437-2444
//   0041ED70 setup_registry              2451-2459
//   0041EDE0 setup_debugging_log         2465-2477
//   0041EE90 setup_comm                  2483-2506
//   0041EFF0 reset_comm                  2512-2521
//   0041F030 setup_sound_system          2527-2552
//   0041F110 setup_music_system          2558-2624
//   0041F2D0 setup_shapes                2630-2647
//   0041F400 setup_sounds                2653-2676
//   0041F560 setup_fonts                 2682-2732
//   0041F730 setup_blank_screen          2737-2749
//   0041F800 setup_timings               2755-2768
//   0041F830 stop_sound_system           2774-2809
//   0041F920 restart_sound_system       2815-2858
//   0041F9B0 stop_music_system           2864-2870
//   0041F9F0 restart_music_system       2876-2888
//   0041FA90 shutdown_music_system      2894-2903
//   0041FAF0 make_font                  2909-2930
//   0041FBC0 make_font                  2936-2964
//   0041FC90 check_for_cd               2977-3028
//   0041FDE0 check_expiration           3034-3051
//   0041FE50 check_multi_copies         3057-3095
//   0041FF20 check_paint                3101-3149
//   00420000 clear_window               3155-3168
//   00420050 create_world               3174-3176
//   004200B0 close                     3182-3184
//   004200D0 create_dialog              3190-3205
//   00420110 delete_dialog              3211-3217
//   00420130 set_game_mode              3223-3226
//   00420150 set_player                 3232-3241
//   00420180 get_paused                 3247-3252
//   004201A0 get_font                   3258-3262
//   004201C0 get_shape                  3268-3272
//   004201E0 get_sound                  3278-3282
//   00420200 request_pause              3288-3293
//   00420220 set_paused                 3299-3311
//   00420270 get_mouse_info             3317-3331
//   004202E0 get_mouse_pos              3337-3347
//   00420330 get_player                 3353-3361
//   00420360 draw_window                3367-3369
//   00420370 mouse_on                   3375-3388
//   004203E0 mouse_off                  3394-3407
//   00420440 set_windows_mouse          3413-3442
//   00420500 set_mouse_cursor           3448-3457
//   00420560 set_mouse_facet            3463-3465
//   00420580 enum_wnd_proc              3469-3474
//   004205B0 enum_child_proc            3477-3482
//   004205E0 enum_thread_proc           3485-3490
//   00420610 close_thread_windows       3493-3497
//   00420650 close_child_windows        3500-3507
//   004206D0 wnd_proc                   3513-3975
//   00420F60 handle_idle               3981-4098
//   00421110 handle_mouse_move         4104-4143
//   004211D0 handle_key_down           4154-4219
//   004212E0 handle_user_command       4225-4291
//   004213A0 handle_command            4297-4302
//   004213C0 handle_music_done          4308-4313
//   004213E0 handle_paint              4319-4531
//   00421830 handle_activate           4537-4598
//   00421910 handle_init_menu          4604-4609
//   00421930 handle_exit_menu          4615-4620
//   00421950 handle_size               4626-4649
//   004219F0 handle_palette_changed    4655-4678
//   00421A80 handle_query_new_palette  4683-4726
//   00421B70 handle_close              4732-4744
//   00421BB0 handle_destroy            4750-4761
//   00421BF0 calc_timings               4767-4914
//   00421FA0 calc_timing_text           4920-4939
//   00422030 show_timings               4945-4948
//   00422050 show_comm                  4954-4960
//   00422090 show_ai                    4965-4970
//   004220D0 send_game_options          4976-4979
//   004220F0 receive_game_options        4985-4996
//
// 00422050, 00422090, and 004220F0 are included through narrow,
// binary-proven field overlays. Their local buffers, panel publication, game
// option state, and call fault order stay in the target sources; the context
// wrapper supplies only the preceding real class. send_game_options keeps its
// public virtual ABI and its own field overlay. The owner boundary is the end
// of receive_game_options at 00422128, before the padding at 00422129.
// 0041F6FA is a two-byte padding/data-dispatch block inside the 0041F560
// source span.  It is not an owner include.  The exact earlier anchor
// 0041E7A0 remains in the registered prefix and is checked independently.
// The exact later anchors 00421FA0 and 004220F0 are included below.
//
// Canonical target declarations are kept in the owner source.  The timing
// record is eight dwords: accum_time, last_time, start_time, include_in_total,
// is_summary, last_single_time, max_time, and last_max_time.  The base-game
// layout places timing records at +0x528 with a 0x20-byte stride and keeps the
// publication counters at +0x504, +0x508, and +0x50C.  The target retains its
// six calls, timer publication, rollover behavior, and original fault order.
// Fresh grouped object audit under these flags: calc_timings is 934/934 with
// two relocation-masked bytes; calc_timing_text is 144/144 with zero masked
// bytes; show_timings is 18/18 with zero masked bytes; show_comm is 64/64,
// show_ai is 61/61, send_game_options is 29/29, and receive_game_options is
// 57/57 with zero non-relocation differences. The registered 0041E7A0 anchor
// also passes its authoritative checker independently.
//
// Evidence-backed module flags: /nologo /c /O2 /Oy /GX.  The neighboring
// setup_chat and setup_registry owners have EH-backed C++ construction and
// exact flag files with this set.  This wrapper adds no flag or config entry.
//
// Exact sibling anchors: 0041E7A0 rge_base_game_wnd_proc (registered prefix),
// 00421FA0 calc_timing_text, 00422030 show_timings, 00422050 show_comm,
// 00422090 show_ai, 004220D0 send_game_options, and 004220F0
// receive_game_options.
// The safe grouped boundary for this pass is 004220F0's end at 00422128;
// 00422129-0042212F is padding before the next owner.
// No dummy predecessor, inline assembly, fake volatility, raw vtable, or
// synthetic owner is used here.

#define BASEGAME_SEGMENT_CONTEXT 1

#include "accepted_drift/00421BF0_calc_timings.cpp"
#include "matching/00421FA0_calc_timing_text.cpp"
#include "matching/00422030_show_timings.cpp"
#include "matching/00422050_show_comm.cpp"
#include "matching/00422090_show_ai.cpp"
#include "matching/004220D0_send_game_options.cpp"
#include "matching/004220F0_receive_game_options.cpp"

#undef BASEGAME_SEGMENT_CONTEXT
