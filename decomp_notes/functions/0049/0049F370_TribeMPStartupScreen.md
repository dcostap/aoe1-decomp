# Function notes: 0049F370 `TribeMPStartupScreen`

Module notes: `decomp_notes/scr_mp_module.md`.

## Recovered attempt history

<!-- recovered:156983e18f12e5cc8928 -->
### `d050eea3c` `src/scr_mp.cpp:1-2`

Mapping: `strong`. next mapped function definition is TribeMPStartupScreen at old line 19.

```text
// PDB source module: C:\\msdev\\work\\age1_x1\\scr_mp.cpp.
// Definitions follow the original PDB source order.
```
<!-- end-recovered:156983e18f12e5cc8928 -->

<!-- recovered:b407da7fbf37e1683af6 -->
### `target-session` `build/target_sessions/0049F370_TribeMPStartupScreen.json:1-24`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=560; shape=92.0: Baseline current scratch source: 1278-byte frame/call-set match, 560 strict differing bytes; first drift is constructor local setup and unresolved literals.
probe 2 other; result=MISMATCH; diff=562; shape=92.0: Hypothesis 1: use binary-backed absolute addresses for constructor, setup, registry, and Zone strings; tests whether unresolved source literals cause strict drift.
probe 4 liveness; result=MISMATCH; diff=560; shape=92.0: Hypothesis 2: reverse initial pointer declaration order (list before cancel) to test VC5 declaration-order register coloring and early LEA scheduling. [same emitted code as probe 1]
probe 5 liveness; result=MISMATCH; diff=560; shape=92.0: Hypothesis 3: declare scalar registry outputs, tab array, and string window before panel pointer aliases to test source declaration order against observed stack homes and early LEA. [same emitted code as probe 4]
probe 6 liveness; result=MISMATCH; diff=560; shape=92.0: Hypothesis 4: split panel pointer declarations from their address assignments at body entry, testing whether VC5 schedules the proven cancel LEA before zero materialization. [same emitted code as probe 5]
probe 7 liveness; result=MISMATCH; diff=310; shape=92.01995012468828: Hypothesis 5: cache the cancel-button object before hotkey stores, testing whether a named receiver preserves the original store-before-help-factory scheduling.
probe 8 liveness; result=MISMATCH; diff=302; shape=92.26932668329177: Hypothesis 6: replace the list pointer alias with direct member expressions, testing whether VC5 emits the original early LEA and preserves list ownership across the scrollbar/help calls.
probe 9 layout; result=MISMATCH; diff=385; shape=92.71356783919597: Hypothesis 7: recover the packet's three separate adjacent char arrays instead of a typed aggregate, testing VC5 local-base placement and registry-buffer offsets.
probe 10 layout; result=MISMATCH; diff=302; shape=92.26932668329177: Hypothesis 8: represent each adjacent registry buffer as a 256-byte array, preserving the 0x300 window while testing VC5 field-width and local-base placement. [same emitted code as probe 8]
probe 11 liveness; result=MISMATCH; diff=302; shape=92.26932668329177: Hypothesis 9: move the cancel receiver declaration to function scope and assign it at the hotkey block, testing whether its lifetime changes prologue/register pressure while retaining the exact hotkey schedule. [same emitted code as probe 10]
probe 12 layout; result=MISMATCH; diff=385; shape=92.71356783919597: Hypothesis 10: use separate Data/temp_str/str arrays with explicit one-byte pads, preserving proven 0x100 strides while testing compiler local allocation versus aggregate-member lowering.
probe 13 behavior; result=MISMATCH; diff=302; shape=92.26932668329177: Hypothesis 11: keep cancel_button bound to cancelButton and pass close_button directly; binary later tab-order loads prove tabList[4] is cancelButton, not closeButton.
probe 14 liveness; result=MISMATCH; diff=302; shape=92.26932668329177: Hypothesis 12: name the tab-order base pointer (tabList + 1) before filling the array, testing whether VC5 reproduces the original LEA and stack-store schedule.
probe 15 liveness; result=MISMATCH; diff=302; shape=92.26932668329177: Hypothesis 13: scope tabList inside the final success arm, testing declaration lifetime and its impact on stack homes without changing tab-order behavior. [same emitted code as probe 14]
probe 16 liveness; result=MISMATCH; diff=319; shape=92.01995012468828: Hypothesis 14: perform the proven cancel member zero immediately after binding its address, testing dependency-driven LEA-before-XOR scheduling at the constructor entry.
probe 17 liveness; result=MISMATCH; diff=294; shape=92.51870324189527: Hypothesis 15: keep the cancel alias for later factory calls but initialize cancelButton directly with the other members, testing whether this preserves LEA-before-XOR without changing store order.
probe 18 liveness; result=MISMATCH; diff=294; shape=92.51870324189527: Hypothesis 16: move panel pointer declarations before registry locals, testing declaration order as the cause of the constructor this-home and buffer-base displacement. [same emitted code as probe 17]
probe 19 abi; result=MISMATCH; diff=295; shape=92.51870324189527: Hypothesis 17: use the binary-proven Regs address directly while retaining reviewed extern rge_base_game, testing relocation identity for the registry calls.
probe 20 abi; result=MISMATCH; diff=295; shape=92.51870324189527: Hypothesis 18: force only the registry and player-name string addresses to their binary locations, testing whether these immediate relocations are unmasked while leaving constructor literals natural.
probe 21 layout; result=MISMATCH; diff=294; shape=92.51870324189527: Hypothesis 19: place the contiguous registry buffer before scalar and tab locals, testing local allocation order as the cause of the persistent four-byte buffer displacement. [same emitted code as probe 18]
probe 25 behavior; result=MISMATCH; diff=294; shape=92.51870324189527: Correct the binary-proven fifth tab-order entry. Use a six-element local and store help_button at index 5 instead of passing the adjacent registry disposition value.
probe 26 behavior; result=MISMATCH; diff=299; shape=91.95979899497488: Measure the corrected five-pointer tab-order list.
probe 27 layout; result=MISMATCH; diff=299; shape=91.95979899497488: Scope the six-entry tab list at final use so VC5 can reuse dead registry storage, as the executable stack map shows.
probe 28 layout; result=MISMATCH; diff=299; shape=91.95979899497488: Measure the late scoped tab list with the fifth help pointer. [same emitted code as probe 26]
```
<!-- end-recovered:b407da7fbf37e1683af6 -->

<!-- recovered:b61b3cf0f0f9012df13f -->
### `bb5259305c6d` `src/scratch/0049F370_TribeMPStartupScreen.cpp:1-33`

Mapping: `exact`. historical standalone source path names this target VA.

```text
// VA: 0049F370 TribeMPStartupScreen constructor (1278B)
// scr_mp.cpp lines 68-220
//
// Baseline reconstruction: the period screen factory sequence, named panel
// ownership, local registry buffers, and the observed browser/Zone setup.
//
// Probe 1 baseline: exact frame and 33-call set; 1104 differing bytes.
// Probe 2 removed an unsupported Data owner store; diff 711.
// Probe 3 reversed the registry-name branch and improved local buffer order;
// diff 646.
// Probe 4 grouped the three proven adjacent buffers; diff 639.
// Probe 5 kept top-level output pointers and reached the best diff, 616.
// Probes 6 and 9 changed pointer lifetime and returned to the same basin.
// Probe 10 added the decompiler Data prefix store; it widened the diff and was
// restored to probe 5.
// New session probe: removed the named cancel object and reloaded the result
// through cancel_button after its factory call; diff improved to 560 and the
// cancel-button register stayed live through the factory arm. Initializing the
// output pointers at declaration emitted the same code.
// Probe 17 separate Data/temp_str/str arrays followed the binary local names;
// size fell to 1263 and diff widened to 562. Restored the contiguous typed
// local window.
// Follow-up probes 2-22: direct list/close members and a cached cancel receiver
// reduced the clean-source diff from 560 to 294 bytes. The receiver preserves
// the original hotkey stores before the help-button factory call.
// BINARY NOTE: tab-order setup loads cancelButton (+48C), not close_button
// (+494). The close-button factory uses its direct member address.
// Tested and rejected: absolute string/global forms, separate buffer locals,
// tab-order aliases, pointer declaration orders, and nested tab-list scope.
// Left in scratch: frame, size, CFG, and call set match. Remaining drift is
// VC5 local-home and register assignment around the constructor prologue and
// registry window. The best source keeps the natural output-pointer lifetime.
// FLAGS: config/flags/0049F370_TribeMPStartupScreen.rsp (/GX for EH cleanup).
```
<!-- end-recovered:b61b3cf0f0f9012df13f -->
