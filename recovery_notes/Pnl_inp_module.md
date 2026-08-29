# Pnl_inp.cpp module

## Ownership and source order

The PDB source is `C:\\msdev\\work\\age1_x1\\Pnl_inp.cpp`.
The module has 22 normal owners in the order recorded in
`config/source_modules/Pnl_inp.json`, from `00476C10` through `004781A0`.
The nearby scalar deleting destructor at `00476CD0` is compiler-generated.

This module owns `TInputPanel` only. Its owned record surface is the nested
`TInputPanel::FormatType` enum and the input fields at offsets `+0x188` through
`+0x1B7`. `TTextPanel`, `TPanel`, `TDrawArea`, `PanelNode`, and `TDigital` are
not module-owned declarations.

`include/Pnl_inp.h` now declares only `TInputPanel`. It consumes
`include/pnl_lst.h` for the inherited `TTextPanel` and `TPanel` surface and
`include/sound_context.h` for the canonical `TDigital` class. The source uses
`TTextPanel::TextNode` directly. It keeps no local type alias, base-class
layout, API record, or foreign class body.

## PDB and binary evidence

`inventory/functions/0047/00476C10_TInputPanel.txt` maps the constructor to
`Pnl_inp.cpp:36-41` and shows its call to `0047BF40`, the text-panel
constructor. The constructor stores input-owned and inherited fields at
`+0x188`, `+0x18C`, `+0x190`, `+0x194`, `+0x198`, `+0x1A0`, `+0x1A4`,
`+0x1A8`, `+0x1AC`, `+0x1AE`, `+0x1B0`, and `+0x1B4`.

`inventory/functions/0047/00476D80_setup.txt` maps `setup` to
`Pnl_inp.cpp:71-125`. The PDB and binary show the inherited setup call and
input setup fields. `inventory/types/dumps/TInputPanel.txt` proves the complete
size is `0x1B8` and records the input fields from `+0x188` through `+0x1B7`.

The source accesses the inherited surface at these locations:

- `src/Pnl_inp.cpp:30-48` writes `TPanel::handle_mouse_input` and
  `TTextPanel::bevel_type`, `panel_type`, and `horz_align`.
- `src/Pnl_inp.cpp:64-99` calls `TTextPanel::setup`, `set_alignment`,
  `set_word_wrap`, and `set_text`, and reads `TPanel::have_focus`.
- `src/Pnl_inp.cpp:102-128` calls `TPanel::set_focus`, `set_redraw`, and
  `handle_idle`.
- `src/Pnl_inp.cpp:187-351` calls inherited text access, scroll, and panel
  action methods and reads `TTextPanel` cursor fields.
- `src/Pnl_inp.cpp:354-389` reads `TPanel::render_area`, visibility fields,
  `render_rect`, and `TTextPanel` cursor fields. It calls the draw-area DC,
  lock, unlock, release, and vertical-line methods. Its line-position output
  is a `long`, matching the inherited owner ABI.
- `src/Pnl_inp.cpp:597-678` calls inherited text, scroll, and line-position
  methods and walks `TTextPanel::list` through its nested `TextNode` record.
- `src/Pnl_inp.cpp:680-720` calls `TTextPanel::currentLine`.

## Header composition

`include/Pnl_inp.h` declares only the PDB-owned `TInputPanel` surface. It
consumes `include/pnl_lst.h` for the inherited `TTextPanel`, `TPanel`, and
`TDrawArea` declarations, and `include/sound_context.h` for `TDigital`.
`pnl_lst.h` now consumes the canonical `panel.h`, `drawarea.h`, and `Shape.h`
owners. No duplicate base layout, vtable, API record, or foreign class body
remains in `Pnl_inp.h`.

The PDB and binary evidence prove `TTextPanel` at size `0x188` and
`TInputPanel` at size `0x1B8`. The source uses the inherited methods and fields
listed above through the canonical owner surface. The former Pnl_lst blocker
was resolved by commit `ab8062906`, which publishes the complete canonical
base and text-panel declarations.

`src/Pnl_inp.cpp:58-59` now passes `(char*)0` to the inherited setup call.
The binary call at `00476DE5` targets `0047C120`, the `char*` overload. The
explicit null type selects that proven overload now that canonical `pnl_lst.h`
also publishes the `long` setup overload. This change adds no fallback type or
context.

No canonical dependency is missing for this header composition. The source
keeps only body-level helper and module-string declarations; it does not copy
those declarations into the module header.

## Historical validation fanout

No compiler or validator command ran during that header-composition wave.

The planned checks were:

1. Recheck `pnl_lst.cpp` against the composed `panel.h` and `drawarea.h`
   declarations. Confirm its virtual slots, base offsets, and direct targets.
2. Recheck `Pnl_inp.cpp` through its direct source module. Confirm all 22 PDB
   owners, the `0x1B8` `TInputPanel` layout, original boundaries, relocations,
   and direct inherited targets.
3. Recheck the text-panel owner and every consumer that includes `pnl_lst.h`.
   The composed header must not introduce duplicate `TPanel`, `TDrawArea`, or
   `TTextPanel` definitions.

## Post-integration candidate validation

After integration as commit `1915feb92`, this branch was rebased onto
`source-reunification/terra-2` and ran exactly one grouped candidate command:

`python tools/validate_candidate_tu.py --proposal build/candidate_tus/Pnl_inp_grouped/proposal.json --output-dir build/candidate_tus/Pnl_inp_grouped`

The candidate compile stopped before function extraction and comparison. The
canonical Windows and CRT declarations conflict with body-level declarations
in `src/Pnl_inp.cpp` for `GetCaretBlinkTime` (line 3), `memset` (line 15),
`MessageBeep` (line 17), and `calloc` (lines 90 and 92). Canonical enum
parameters also reject the existing integer arguments to `Alignment` (lines
45, 85, and 88) and `RedrawMode` (lines 121, 200, 211, 221, 227, 238, 257,
262, 280, and 310).

No exact or observed comparison result was produced. That run changed no owner
status. The source repair below addressed those declaration and enum errors.
The current final grouped audit completes the required validation.

## Follow-up source repair

The source now uses the canonical Windows and CRT declarations supplied by the
composed headers. It removes local declarations for `GetCaretBlinkTime`,
`calloc`, `memset`, `strcpy`, `MessageBeep`, the clipboard APIs, and the
`g_SelectObject` pointer. The draw path initializes its local function pointer
from canonical `SelectObject`.

The source uses `TTextPanel::AlignHorizontalScroll`, `AlignTop`, `AlignLeft`,
and `AlignCenter` for alignment values. It uses `TPanel::RedrawNormal` for
redraw requests. These changes resolve the reported canonical enum conversion
errors without adding compatibility declarations or context.

No compiler or validator command ran for this repair, as required.

## Current exactness state

The source manifest has 17 matching owners and five scratch owners. All 17
matching owners are registered. The final grouped audit proves them exact.
`00476D80 setup` is one of these matching owners.

The five scratch owners are:

- `00476C10`
- `00476FA0`
- `00477220`
- `00477AF0`
- `00477E90`

## Historical exactness state

The pre-composition report remains under
`build/audits/Pnl_inp_review_final`. The current final grouped audit supersedes
that report for owner status and exactness.
