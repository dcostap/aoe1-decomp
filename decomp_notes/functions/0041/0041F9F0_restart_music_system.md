# Function notes: 0041F9F0 `restart_music_system`

Module notes: `decomp_notes/basegame_module.md`.

## Recovered attempt history

<!-- recovered:51271cd74c0cd6363003 -->
### `a14d0eb20b12` `src/scratch/0041F9F0_restart_music_system.cpp:1-41`

Mapping: `exact`. historical standalone source path names this target VA.

```text
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
// Retry 2026-08-02 Luna-41F9F0: corrected the local music field layout and TMusic call
// prototypes from repo ground truth; no emitted-byte change.
// An inline post-null helper was a productive source-context probe: it reproduced the
// delayed callee-save prologue and exact early-null block, improving the best build to
// 144 aligned bytes / 149-byte boundary. A narrow volatile read on the first track_to
// comparison preserved the original direct `cmp [eax+78h]` and later reload, giving 138
// equal bytes, 96.61% exact-block coverage, and only three resync spans.
// The remaining structural gap is binary-proven at basegame.cpp:2882: original has the
// redundant `test edx,edx; je file; mov esi,[eax+78h]; test esi,esi; je file`, while VC5
// removes the first two instructions after every natural/direct-member spelling tried.
// Volatile-addressing the local creates a stack home and a broad 164-byte mismatch;
// duplicate predicates, nested positive flow, and repeated direct members are codegen
// duplicates. Left in scratch pending a source-context lead that preserves that block.
```
<!-- end-recovered:51271cd74c0cd6363003 -->
