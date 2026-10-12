# `src/flics.cpp` cleanup report

## Delivery

- Module: `src/flics.cpp`.
- Branch: `cleanup/staging-20260915-178`.
- Report: `workflow/decomp_notes/source_cleanup/wave03/flics.md`.
- Base commit: `76037279ee11dde077bb7d55aeb46b518b2bb27c`.
- Final source-cleanup commit: `983605284d47d07e749cf2fedfc6e51f17db0c8f`.
- Post-cleanup repair commit: `ffb87e4c2886668aba720bcf7a61e3a500ffde15`.
- Delta follow-up commit: `7ea3f393408decdeaeee40b0b428706a7943e4dd`.
- Changed files:
  - `src/flics.cpp`.
  - `workflow/decomp_notes/source_cleanup/wave03/flics.md`.

The source commit contains only the assigned source file. This report is a
separate assigned-file commit.

## Scope and evidence

I inspected the complete module source, the assigned header, the module note,
and every assigned procedure record. The source map at
`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/function_source_map.csv`
assigns these 15 normal owners to `C:\msdev\work\age1_x1\flics.cpp`:

`00449B30`, `00449BE0`, `00449C40`, `00449C50`, `00449DF0`, `00449E00`,
`00449E10`, `00449E20`, `00449E80`, `00449E90`, `0044A090`, `0044A100`,
`0044A2A0`, `0044A390`, and `0044A3E0`.

The procedure records are in
`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`.
Each normal procedure has `this` in `ecx` with type `RGE_Flic_Player*`.
The reviewed padding-only boundary `0044A05D` belongs to `draw`; it has no
compiler-facing source body and was not changed.

Original instruction and source-line evidence remains in:

- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0044/00449B30_RGE_Flic_Player.txt`.
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0044/00449BE0_RGE_Flic_Player.txt`.
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0044/00449C50_palette.txt`.
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0044/00449E90_draw.txt`.
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0044/0044A090_literal.txt`.
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0044/0044A100_delta_flc.txt`.
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0044/0044A2A0_delta_fli.txt`.
- `C:/Projects/my_decomps/aoe1_attempt3/inventory/functions/0044/0044A3E0_byte_run.txt`.
- `C:/Projects/my_decomps/aoe1_attempt3/orig/ghidra_decomp/flics.cpp.asm`.
- `C:/Projects/my_decomps/aoe1_attempt3/orig/ghidra_decomp/flics.cpp.decomp`.

I read `include/flics.h` but did not edit it. The module note at
`workflow/decomp_notes/flics.md` records the recovered layouts and decoder constraints.

## Original-name recovery

The PDB stack records provide these names:

| VA | PDB names | Source result |
| --- | --- | --- |
| `00449B30` | `filename` parameter | Renamed `path` to `filename`. |
| `00449BE0` | `handle` parameter | Renamed `file_handle` to `handle`. |
| `00449C50` | `palette` parameter; `index1`, `temp_buffer`, and `framehead` locals | Kept `palette` and `framehead`; renamed `chunk_index` to `index1` and `frame_buffer` to `temp_buffer`. |
| `00449E90` | `drawarea_in`, `flic_x`, `flic_y` parameters; `temp_buffer` local | Existing source names already match. |
| `0044A100` | `cur_y` local | Existing source name already matches. |
| `0044A2A0` | `cur_x` local | Renamed the outer `remaining` counter to `cur_x`. The inner horizontal cursor remains the existing `x` name. |
| `0044A3E0` | `cur_x` stack record | No source rename was forced. The original home also saves `this` and is reused by the decoder. |

The PDB records for the remaining procedures contain only `this`. The source
keeps existing descriptive names for locals without a reliable PDB mapping,
including `size`, `fd`, `chunk`, `packets`, `color_index`, `packet_count`,
`count`, `frame`, `chunk_base`, `i`, `command`, `byte_count`, `lines`,
`line_remaining`, `x`, `p`, `copy_count`, `dst`, and `line_offset`.
These are existing names, not new inferred original names.

The source keeps its existing declaration types and scopes. The PDB types
`palette::index1` as `long` and `palette::temp_buffer` as `char*`; the source
keeps `int index1` and `int* temp_buffer`. The PDB types `delta_fli::cur_x`
as `long`; the source keeps `int cur_x`. These names map by the matching stack
home and use, but this cleanup does not change their types.

The `byte_run::cur_x` PDB record is not mapped to `line_offset`. The original
record's stack home is used for the saved `this` pointer during the packed copy
paths. The source retains `line_offset` until a separate declaration review
proves a mapping.

## Constants, comments, and formatting

I read the pinned VC5 headers before replacing the file-I/O literals:

- `C:/Program Files (x86)/DevStudio/VC/Include/FCNTL.H:41` defines
  `_O_BINARY` as `0x8000`.
- `C:/Program Files (x86)/DevStudio/VC/Include/STDIO.H:209-211` defines
  `SEEK_CUR` as `1`, `SEEK_END` as `2`, and `SEEK_SET` as `0`.

The final source keeps the original numeric `0x8000` open mode and numeric
`lseek` origins. The isolated compiles proved that the `stdio.h` and `fcntl.h`
includes changed VC5 code generation. The origins are `2` for `SEEK_END` and
`0` for `SEEK_SET`. No resource lookup or resource ID exists in this module.
No shared constant or resource declaration was added.

I retained the existing comments that explain the complete FLIC header copy,
the draw-area store order, and the separate palette-chunk path. I added no
new source comment. I moved function-definition braces to the module's 1TBS
style. I did not reorder declarations or executable statements.

## Header requests and unresolved questions

Please route these parameter-name updates to the owner of `include/flics.h`:

- `RGE_Flic_Player(char* path)` to `RGE_Flic_Player(char* filename)`.
- `RGE_Flic_Player(int file_handle)` to `RGE_Flic_Player(int handle)`.

The header request changes names only. It does not change the ABI or decorated
symbol. No other shared-file request is needed.

The known non-exact `palette` and `delta_flc` source shapes remain unchanged.
Their reviewed behavior and type constraints are recorded in
`workflow/decomp_notes/flics.md`. I did not attempt a structural decoder rewrite.

## Post-cleanup matching investigation

The final validation row for `00449DF0` reports `matching_regression`.
It reports 3 changed bytes in a 14-byte function. The previous result was
`UNKNOWN`, so that result did not prove cleanup causation.

I compared the preserved baseline object with the fresh cleanup object:

- Baseline: `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/flics.obj`.
- Baseline SHA256: `766653c06ace7fba825a70373c97784ed217fb12e98c5c24fc33e1e3519b8ae6`.
- Fresh: `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/final-validation/functions/objects/flics.obj`.
- Fresh SHA256: `5496c8f3ad10b7dbd06e248fabc6d18fbb535888d838bb0d018533d69aae3d89`.

The baseline resolution bytes are
`0fbf41100fbf4912c1e0100bc1c3`. The fresh bytes are
`0fbf41120fbf4910c1e1000bc1c3`. The changed bytes reverse the two field
loads and change the shift destination.

The baseline source commit was
`6d46835cdc6e31ba879a2e6e31415327a7c7e341`. Its source SHA256 was
`9f8b2449475155db4049aa08677f883460032a0cf0fa9e7eb1e8bfa1ac28c98d`.
The pre-repair cleanup source SHA256 was
`1bd46f7fe7535e048f5dbeadf92c8e86bd3696a6c7f17fb753313c50c4d615f7`.
The cleanup body did not change the resolution expression before the repair.
It changed the surrounding compiland through names, braces, source lines, and
CRT macros. The same cleaned source produced the fresh byte order in a second
object. Older pre-cleanup objects produced the baseline byte order.

The root baseline-line experiment did not fix the drift. Its compile log is
`C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/final-validation/flics-lines-experiment/compile.json`.
Its listing is
`C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/final-validation/flics-lines-experiment/flics.cod`.
It used candidate commit `c5660f2b948e1201790d96c104d3b6a99be3eec8`, with
source SHA256 `1405e5fb2c47eacb717638d2e58dd106cb8615f137b119e82261d82236eb0922`.
Lines 718-725 show the same height-first bytes as the fresh object.

I then compiled isolated candidates with the pinned VC5 toolchain, using new
directories and `config/flags/default.rsp` each time. The candidates changed
only source copies in the build area.

| Candidate | Pre-resolution change | Resolution bytes | Source SHA256 | Object SHA256 |
| --- | --- | --- | --- | --- |
| `baseline-current-headers` | Exact baseline source | `0fbf41100fbf4912c1e0100bc1c3` | `9f8b2449475155db4049aa08677f883460032a0cf0fa9e7eb1e8bfa1ac28c98d` | `afcfe62e4b77b6c0ae4e3ab7d611608646504e3de0511552c8c93ee0bcb127cb` |
| `includes-only` | Add `fcntl.h` and `stdio.h` | `0fbf41120fbf4910c1e1000bc1c3` | `e8dfd65377633bdeb797371c14cefd036ac721127d69c1edc2c06ed5dc033a19` | `6553cf106121e00b5e242079fa35b378c4484e74099f317077bdf38571ebb257` |
| `names-braces` | Restore names and braces only | `0fbf41100fbf4912c1e0100bc1c3` | `77c3d4f7712437c30507d2a8eee92cad2e53df8cb15330fef9950c3401221596` | `01a5ff3f44d5ec40fa3d52cd150d78cfa334790075982db0a3fdd06de87943b1` |
| `includes-macros` | Add headers and seek macros | `0fbf41120fbf4910c1e1000bc1c3` | `15224c4730007beea58cbace68114cd6bed174b8358dfbe84161042dcd8b8fab` | `8728b5c2a7eb49e467d83d8ad0bea2dfc614c7084c838a44931cf50930372488` |
| `full-preceding` | Restore all preceding cleanup changes | `0fbf41120fbf4910c1e1000bc1c3` | `8221461a823fa991528ac6e012810c1fee257456f18efeff6750fe902d8ded51` | `57a5d57d1345339430076f6d258f31f8ea896fb6853b6b78fe2c7edb25ab416d` |
| `fcntl-only` | Add `fcntl.h` only | `0fbf41100fbf4912c1e0100bc1c3` | `16be4cbafe41a8f897a14e3ffb413685db3ea2bc22e693a1071dacfa6cf661bb` | `a0e360c1ee0bd353b44e4b83b12871be78891d67095a474faaedad59ae65de7c` |
| `stdio-only` | Add `stdio.h` only | `0fbf41120fbf4910c1e1000bc1c3` | `3bb6d1e8331acedc09053ff3ae3641581765b04e77b364bd138e355f893a4051` | `a34c20fee68d06a57c7c108273b0b8ac921000a6fa8695720f7726dd08bb125d` |
| `remove-stdio-literals` | Remove `stdio.h`; use seek literals | `0fbf41100fbf4912c1e0100bc1c3` | `d6a6e5046c148eef55672587c846874c57c2dad9f7c334a83c1bf1f3b906d6f6` | `07b98b2fe241ca0c54de154bd190a86ce155a7a9f13c2e6b591943dff8debb3d` |
| `remove-stdio-local-macros` | Remove `stdio.h`; define local seek macros | `0fbf41100fbf4912c1e0100bc1c3` | `6b89e7eec0d267a99970b3ffb9ce0c342462fab9667179c040b413c0409e7015` | `e46e7ab7fb56bb4ae64b60269cb9e1944a3cf60ef120d81586b134b1f3347140` |
| `remove-stdio-literals-lines` | Remove `stdio.h`; restore seek literals and baseline lines | `0fbf41100fbf4912c1e0100bc1c3` | `60965663b21744873aa3de18be76d669f92feba258cf09e254a2b86c7fa6aab7` | `4029285697fc3c2b41efc1c56e7b756a451fd5474311d15debffcbff1f53ba17` |
| `remove-stdio-literals-cleaned-resolution` | Remove `stdio.h`; restore seek literals | `0fbf41100fbf4912c1e0100bc1c3` | `6d65ba3e183a3c84076aa0e7aaaaeaf8e948e55364c02221aafc938566af56ca` | `2958f1a51c1ba3e8f36d55317450b4eff2ad57d2f59f8a214438723d7155a9ac` |

The `stdio-only` and `fcntl-only` candidates isolate the cause to the
explicit VC5 `stdio.h` include. The macro uses are not the cause by
themselves. The recovered renames and brace changes are not the cause in the
tested combinations.

The candidate logs and listings are preserved at:

- `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/flics-cause-experiments/baseline-current-headers/output-rerun/compile.json`.
- `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/flics-cause-experiments/includes-only/output/compile.json`.
- `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/flics-cause-experiments/names-braces/output/compile.json`.
- `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/flics-cause-experiments/includes-macros/output/compile.json`.
- `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/flics-cause-experiments/full-preceding/output/compile.json`.
- `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/flics-cause-experiments/fcntl-only/output/compile.json`.
- `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/flics-cause-experiments/stdio-only/output/compile.json`.
- `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/flics-cause-experiments/remove-stdio-literals/output/compile.json`.
- `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/flics-cause-experiments/remove-stdio-local-macros/output/compile.json`.
- `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/flics-cause-experiments/remove-stdio-literals-lines/output/compile.json`.
- `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/flics-cause-experiments/remove-stdio-literals-cleaned-resolution/output/compile.json`.

The first repair's object comparison also found two changed bytes in
`delta_flc`. Its prior status was `new_verified_logic`, but baseline equality
still applies. The follow-up investigation below repairs those bytes.

The first source repair is commit
`ffb87e4c2886668aba720bcf7a61e3a500ffde15`. It removes the `stdio.h` include
and restores the four original seek literals. The later follow-up removes the
remaining `fcntl.h` and `_O_BINARY` changes. The first repair source SHA256 is
`6d65ba3e183a3c84076aa0e7aaaaeaf8e948e55364c02221aafc938566af56ca`.
The accepted candidate's isolated object is
`2958f1a51c1ba3e8f36d55317450b4eff2ad57d2f59f8a214438723d7155a9ac`.

The prior commutative-OR experiment is commit
`dee72a75fe4885309a67715731d978566c439d70`. It remains in history but is
not part of the accepted source because it changed operand and read order.

No full build, broad audit, matching sweep, test, or game run was performed.

## `delta_flc` follow-up investigation

The accepted resolution repair left two changed `delta_flc` bytes. Baseline
equality applies to this function despite its former `new_verified_logic`
status.

The preserved baseline object is
`C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/flics.obj`.
Its SHA256 is
`766653c06ace7fba825a70373c97784ed217fb12e98c5c24fc33e1e3519b8ae6`.
The accepted repaired object is
`C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/flics-cause-experiments/remove-stdio-literals-cleaned-resolution/output/flics.obj`.
Its SHA256 is
`2958f1a51c1ba3e8f36d55317450b4eff2ad57d2f59f8a214438723d7155a9ac`.

Both objects place `delta_flc` in the `.text` COMDAT section `SECT18`.
The section starts at raw file offset `0xD90`, has size `0x190` bytes, and
has no relocation or line-number entries. The symbol value is zero in both
objects. The complete section SHA256 values are:

- Baseline: `f2170d184fe85ab983ddc4bf335e1117c30c05eed70a4e3a133b727f32c08c49`.
- Accepted repair: `6b78930f4deab82468b6e3a6caaf7d3405131ec6074ac69f56cec5526ba15b9c`.

Only two of the 400 section bytes differ:

| Offset | Baseline | Accepted repair | Instruction effect |
| --- | --- | --- | --- |
| Section `0x73`; file `0xE03` | `94` | `98` | First field displacement |
| Section `0x79`; file `0xE09` | `98` | `94` | Second field displacement |

At section offset `0x71`, baseline code loads
`[eax+0x94]` into `ecx`, then `[eax+0x98]` into `esi`. The accepted repair
loads `[eax+0x98]` into `ecx`, then `[eax+0x94]` into `esi`. These are the
`flic_width` and `window_buffer` fields. The source expression is unchanged.
The accepted code changes the field read and possible fault order.

The exact 16-byte windows at section offset `0x70` are:

- Baseline: `1E 8B 88 94 00 00 00 8B B0 98 00 00 00 88 5C 31`.
- Accepted repair: `1E 8B 88 98 00 00 00 8B B0 94 00 00 00 88 5C 31`.

All other code bytes are equal. All internal branch bytes and targets are
equal. `delta_flc` has no calls and no relocation targets. The complete raw
bytes and disassembly are preserved in:

- `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/delta-flc-experiments/initial-inspection/baseline-dump.txt`.
- `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/delta-flc-experiments/initial-inspection/candidate-dump.txt`.
- `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/delta-flc-experiments/initial-inspection/baseline-disasm.txt`.
- `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/delta-flc-experiments/initial-inspection/candidate-disasm.txt`.
- `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/delta-flc-experiments/delta-comparison.txt`.

The comparison artifact SHA256 is
`c81758b65f189ef01b338a23512260b07100d00df85d659d0bf1d84b4ffe879c`.

I compiled minimal, pinned VC5 candidates in new flics-only directories. The
result below records the `delta_flc` section result.

| Candidate | Isolated change | Source SHA256 | Object SHA256 | Delta result |
| --- | --- | --- | --- | --- |
| `accepted-repro` | Accepted repair control | `6d65ba3e183a3c84076aa0e7aaaaeaf8e948e55364c02221aafc938566af56ca` | `981801224cf482cd67b3d0a51f790c95025f6363a67a0e25dc9daed7e9a11d71` | Swapped |
| `delta-brace` | Restore only `delta_flc` brace | `a3ac8b60ac90635b11000ff7db4326bbe10086d269479b6c34520089cbcf276d` | `8e4f665a4d5a4cd8f2900febcae20ece7639e96ffabf1088e0c2112ea04ca08` | Swapped |
| `cleanup-braces` | Restore all function braces | `3688ac969a7b78078895312ebe64382ca56fc81a544cfdc7d64b094474e5a0a4` | `a540cd902c916e59159e078bc267e04740bf81c605053419df78312c0053e483` | Swapped |
| `cleanup-names` | Restore cleanup names | `c4b8767b55e7f2bd05a0537d30d02a5aea6dd5fb0e1d4bb6c356f036021384ee` | `5b531322549d19d8f62912556fcd99e40bcb2bffa976e78aa945f0939d995dc1` | Swapped |
| `baseline-fcntl` | Add `fcntl.h` and `_O_BINARY` | `ce2f9e2a84136ce0233968696b9d0bd411631b66b9b508ae804a25dadb047099` | `4e47b039d68d3d4513e0b3899755800ef93f9d740a578c2d407d28ed65e6c085` | Swapped |
| `baseline-fcntl-format` | Add fcntl changes and cleanup braces | `c4b8767b55e7f2bd05a0537d30d02a5aea6dd5fb0e1d4bb6c356f036021384ee` | `6363876533c49846d3c3b6a9cb96587bc19b4f2b146fd1f70749a4a107427c50` | Swapped |
| `baseline-fcntl-names` | Add fcntl changes and recovered names | `43e07eb91b2a7c23f714df52d5b29610e8adc32565258c369f62d6501f3987bb` | `b60bba6cd413bc3e46a038bafb163792a500b1c800c55c265bdeebf69b8536ee` | Swapped |
| `fcntl-include-literal` | Add `fcntl.h` only; keep `0x8000` | `16be4cbafe41a8f897a14e3ffb413685db3ea2bc22e693a1071dacfa6cf661bb` | `e16d623140632ddac90036985e34eea54a3a4159e6b656710342ae4ca956d4cf` | Swapped |
| `no-fcntl` | Remove `fcntl.h`; restore `0x8000` | `32fbd052849a744fd1bed1a399175c99182ee537cf43673cfabf05f4c462f845` | `ec4e6613b527536b473c3ae51afa831ad6846a61003b47630cb785dbb3526b07` | Baseline |

The brace and name candidates did not fix `delta_flc`. A baseline source with
`fcntl.h` also did not match. The `fcntl-include-literal` candidate proves
that the header, not the `_O_BINARY` value, triggers the swap. Removing the
header and restoring the original literal fixes the two bytes.

The full compiler logs for these candidates are preserved at:

- `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/delta-flc-experiments/accepted-repro/output/compile.json`.
- `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/delta-flc-experiments/delta-brace/output/compile.json`.
- `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/delta-flc-experiments/cleanup-braces/output/compile.json`.
- `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/delta-flc-experiments/cleanup-names/output/compile.json`.
- `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/delta-flc-experiments/baseline-fcntl/output/compile.json`.
- `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/delta-flc-experiments/baseline-fcntl-format/output/compile.json`.
- `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/delta-flc-experiments/baseline-fcntl-names/output/compile.json`.
- `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/delta-flc-experiments/fcntl-include-literal/output/compile.json`.
- `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/delta-flc-experiments/no-fcntl/output/compile.json`.

The `no-fcntl` delta section SHA256 is
`f2170d184fe85ab983ddc4bf335e1117c30c05eed70a4e3a133b727f32c08c49`.
Its `resolution` bytes also remain baseline-exact. A raw `.text` comparison
found all 15 flics function sections byte-equal to the preserved baseline.
The whole object still differs in symbols, debug records, and its timestamp.
The follow-up object dump and disassembly are preserved in:

- `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/delta-flc-experiments/no-fcntl/dump.txt`.
- `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/delta-flc-experiments/no-fcntl/disasm.txt`.
- `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/delta-flc-experiments/fcntl-include-literal/dump.txt`.
- `C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/delta-flc-experiments/fcntl-include-literal/disasm.txt`.

The follow-up source is commit
`7ea3f393408decdeaeee40b0b428706a7943e4dd`. It removes `fcntl.h` and
restores `open`'s original `0x8000` argument. It preserves source expression,
evaluation order, read order, and fault order. Its tracked source SHA256 is
`32fbd052849a744fd1bed1a399175c99182ee537cf43673cfabf05f4c462f845`.
Its compile log is
`C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/delta-flc-experiments/no-fcntl/output/compile.json`.

## Code-generation and review limits

The source edits change identifiers, brace placement, includes, and macro
spellings only. The final repairs remove the `stdio.h` and `fcntl.h` includes
and restore the original numeric file-mode and seek arguments. They keep the
original resolution and decoder expressions and operand order. They do not
change public symbols, function boundaries, casts, storage, field layout,
calls, or decoder state. The rejected operand-swap experiment is not part of
the accepted source.
The PDB/source type differences listed above remain intentionally unresolved.

I reviewed the complete source diff against the base and ran `git diff --check`.
I ran only the listed isolated flics compiler experiments. I did not run a
full build, broad matching check, audit, test, or game.
