# `scr_save.cpp` recovery

## Source context

PDB source: `C:\msdev\work\age1_x1\scr_save.cpp`.
The module has five normal owners in source order:
`004A71F0`, `004A75C0`, `004A7670`, `004A7850`, and `004A8060`.
`004A75A0` is the compiler-generated vector deleting destructor.

## Canonical ownership

`include/scr_save.h` owns the complete `TribeSaveGameScreen` class and all five
normal declarations. The source uses canonical panel, screen, control, game,
world, scenario, and scenario-open providers. `src/scr_save.cpp` is the direct
translation-unit owner. The old wrapper, context hierarchy, and function
fragments were removed.

The constructor uses the canonical `TPanel::error_code` field. `fillList`
uses the canonical `RGE_Prog_Info::save_dir` and `scenario_dir` fields. The
scenario-editor save path uses the typed `TRIBE_Screen_Sed` provider and its
`need_to_save_flag` field. It does not use raw offsets or child-pointer casts.

The action body uses separate path, text, and existence values. It does not
use the former `+4` stack-buffer overlays. It remains scratch because the
natural source differs by 1730 bytes and three relocation sites.

The destructor uses typed `delete` for its child controls. This is natural
ownership, but it differs from the shipped `TPanel::delete_panel` sequence.
It remains scratch with a 135-byte difference and one boundary escape.

## Candidate validation

Candidate: `build/scr_save_natural_candidate.json`.
Report: `build/candidate_tus/scr_save_final_rebased/report.json`.

The grouped candidate compiled all five normal bodies and the generated
vector deleting destructor. The constructor, `fillList`, and scenario-editor
save helper match exactly. The destructor and action remain scratch. There are
zero comparison errors.
