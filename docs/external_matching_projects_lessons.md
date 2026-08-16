# Lessons from Other Matching-Decompilation Projects

## Purpose

This document records the external research completed for the Age of Empires 1 reconstruction.

The project targets a 1990s Windows game built with the VC5-era Microsoft compiler. The remaining functions often have correct behavior but different generated code. Small source or context changes can alter register allocation, stack homes, inlining, x87 operation order, and block layout.

The goal of this document is to preserve external evidence. It also records which lessons apply to this repository and which lessons do not.

## Scope and evidence rule

The original Age of Empires executable remains the behavior oracle.

External projects provide:

- Compiler and linker evidence.
- Source-shape examples.
- Matching tools.
- Comparator strategies.
- Stopping rules.
- Runtime validation methods.

External projects do not prove the original Age of Empires source. Their source names and layouts remain hypotheses until local binary evidence confirms them.

## External repositories

### Direct Windows and MSVC matches

| Project | Target | Compiler | Main value |
|---|---|---|---|
| [madebr/rec2](https://github.com/madebr/rec2) | Carmageddon 2, 1998 | MSVC 5.0 / Visual Studio 97 | Closest VC5 C reconstruction and build split |
| [isledecomp/isle](https://github.com/isledecomp/isle) | LEGO Island, 1997 | MSVC 4.2 | Mature C++ ABI and vtable reconstruction |
| [shinyquagsire23/Yodecomp](https://github.com/shinyquagsire23/Yodecomp) | Yoda Stories Demo, 1997 | VC4.2 | Compiler-context and source-shape experiments |
| [dethrace-labs/dethrace](https://github.com/dethrace-labs/dethrace) | Carmageddon Windows 95 Splat Pack | MSVC 4.2 | Explicit compiler-entropy policy and effective matches |
| [agluszak/imperialism-decomp](https://github.com/agluszak/imperialism-decomp) | Imperialism, 1997 | VC5 RTM | Exact VC5 service-pack and linker experiments |
| [isledecomp/reccmp](https://github.com/isledecomp/reccmp) | Matching toolset | MSVC-focused | Effective-match and assembly-diff implementation |

### Related tools and projects

| Project | Target | Main value |
|---|---|---|
| [maci0/rebrew](https://github.com/maci0/rebrew) | Many compiler targets | MSVC5 mutation and flag-sweep framework |
| [adm244/ags2_decomp](https://github.com/adm244/ags2_decomp) | AGS 2.x DOS runtime | Original 1998 compiler workflow and per-function matching |
| [nmlgc/ReC98](https://github.com/nmlgc/ReC98) | Touhou PC-98 | Original compiler discipline and readable reconstruction |

## Local cache paths

The external repositories were fetched into local Git caches under:

```text
C:\Users\Darius\AppData\Local\pi-web-smart-fetch\github-cache\madebr\rec2
C:\Users\Darius\AppData\Local\pi-web-smart-fetch\github-cache\isledecomp\isle
C:\Users\Darius\AppData\Local\pi-web-smart-fetch\github-cache\isledecomp\reccmp
C:\Users\Darius\AppData\Local\pi-web-smart-fetch\github-cache\shinyquagsire23\Yodecomp
C:\Users\Darius\AppData\Local\pi-web-smart-fetch\github-cache\dethrace-labs\dethrace
C:\Users\Darius\AppData\Local\pi-web-smart-fetch\github-cache\agluszak\imperialism-decomp
C:\Users\Darius\AppData\Local\pi-web-smart-fetch\github-cache\maci0\rebrew
C:\Users\Darius\AppData\Local\pi-web-smart-fetch\github-cache\adm244\ags2_decomp
C:\Users\Darius\AppData\Local\pi-web-smart-fetch\github-cache\nmlgc\ReC98
```

The caches are external worktrees. They are not part of the Age of Empires repository.

Relevant source paths were expanded from sparse checkouts for `rec2`, `reccmp`, `dethrace`, and `imperialism-decomp`.

## Age of Empires toolchain baseline

The local project records this candidate in:

```text
config/toolchain.json
```

Important values:

```text
Toolchain name: vc5-host
CL.EXE:        C:\Program Files (x86)\DevStudio\VC\Bin\CL.EXE
LINK.EXE:      C:\Program Files (x86)\DevStudio\VC\Bin\LINK.EXE
Expected CL:   11.00.7022
Expected LINK: 5.00.7022
Default flags: /nologo /c /O2 /Oy
```

The toolchain is now marked `calibrated`. On 2026-08-15, a small sentinel
campaign produced exact object matches for plain C, C library use, an EH
constructor, virtual calls, floating-point code, and a separate translation
unit. The campaign used the pinned compiler and repository include paths.

The EH constructor required its existing per-function `/GX` response file.
This confirms a target context, not a new default flag set. The campaign does
not prove every translation unit or a final linked image. Do not start a broad
compiler hunt from this result.

## 1. rec2: closest VC5 project

Repository:

```text
https://github.com/madebr/rec2
```

Local paths:

```text
C:\Users\Darius\AppData\Local\pi-web-smart-fetch\github-cache\madebr\rec2\CONTRIBUTING.md
C:\Users\Darius\AppData\Local\pi-web-smart-fetch\github-cache\madebr\rec2\CMakeLists.txt
C:\Users\Darius\AppData\Local\pi-web-smart-fetch\github-cache\madebr\rec2\cmake\reccmp.cmake
C:\Users\Darius\AppData\Local\pi-web-smart-fetch\github-cache\madebr\rec2\reccmp-project.yml
```

### Target and compiler

Carmageddon 2 is a 1998 Windows game. The matching build uses Visual Studio 97 / MSVC 11.0. This is the same VC5 generation as the Age of Empires compiler candidate.

The matching build uses:

```text
/W3 /GX /DWIN32 /D_WINDOWS
/O2 /Ob2 /G5 /DNDEBUG /ML
/Gr
/machine:I386
/incremental:no
```

The project uses embedded debug information for matching builds. Its CMake file selects the matching configuration only for MSVC 11.0.

This differs from the current Age of Empires default response file. The Age of Empires project currently uses `/O2 /Oy`. The rec2 flags are evidence, not a replacement for the local flags.

### Source and contribution rules

`CONTRIBUTING.md` requires:

- Explicit calling conventions on every declaration and definition.
- A one-line function implementation header.
- Small commits.
- Every commit must build and work.
- Warning-free MSVC and MinGW builds.
- Source that stays faithful to the binary.

The one-line header rule exists because the project extracts symbols from source headers to create its Ghidra project.

### Hook-first workflow

When functions depend on each other, rec2 recommends two stages:

1. Add hooks that forward unresolved functions to the original binary.
2. Replace those hooks with reconstructed implementations later.

This keeps the executable runnable while the source reconstruction grows.

The current repository later removed the hook system. The removal commit was:

```text
e19bbaa Remove ability to hook functions
```

The lesson is that hooks are useful scaffolding. They are not a substitute for final source reconstruction.

### Build separation

The CMake project separates matching and portable builds.

Matching builds use the old compiler and historical flags. Non-matching builds use modern compilers and can enable portability or bug fixes.

This is the same separation that Age of Empires needs between:

- Exact historical reconstruction.
- Behavior-focused or modernized builds.

### Main lessons

1. Keep a runnable hybrid build during large reconstruction work.
2. Treat calling conventions as source metadata, not as inferred comments only.
3. Keep matching flags separate from portable flags.
4. Do not use the matching configuration as a modern development configuration.
5. Use hooks only as temporary integration scaffolding.

## 2. Isle and reccmp: C++ ABI and comparison methodology

Repositories:

```text
https://github.com/isledecomp/isle
https://github.com/isledecomp/reccmp
```

Local tool paths:

```text
C:\Users\Darius\AppData\Local\pi-web-smart-fetch\github-cache\isledecomp\reccmp\reccmp\compare\match_msvc.py
C:\Users\Darius\AppData\Local\pi-web-smart-fetch\github-cache\isledecomp\reccmp\reccmp\compare\functions.py
C:\Users\Darius\AppData\Local\pi-web-smart-fetch\github-cache\isledecomp\reccmp\reccmp\compare\asm\fixes.py
C:\Users\Darius\AppData\Local\pi-web-smart-fetch\github-cache\isledecomp\reccmp\reccmp\compare\asm\swap.py
C:\Users\Darius\AppData\Local\pi-web-smart-fetch\github-cache\isledecomp\reccmp\docs\annotations.md
C:\Users\Darius\AppData\Local\pi-web-smart-fetch\github-cache\isledecomp\reccmp\docs\recommendations.md
```

### C++ ABI first

The Isle project shows that function-body reconstruction is often the wrong first task.

Before recovering a body, establish:

- Calling convention.
- Parameter widths.
- Signedness.
- Return width.
- Class size.
- Member offsets.
- Base-class order.
- Vtable address.
- Vtable slot.
- Destructor kind.
- Whether a function is compiler-generated.
- Whether a function comes from a library.

A wrong class layout creates fake pointer arithmetic and false fields throughout every method.

### Annotation model

reccmp uses source annotations such as:

```cpp
// FUNCTION: LEGO1 0x100b12c0
```

It also supports:

```text
FUNCTION
STUB
TEMPLATE
SYNTHETIC
LIBRARY
VTABLE
GLOBAL
STRING
LINE
```

It supports `SYMBOL` and `FOLDED` metadata. Functions within a translation unit are expected to appear in ascending original-address order.

The address order requirement is valuable. It provides evidence about original source-file organization.

### Entities beyond functions

reccmp compares or tracks:

- Functions.
- Templates.
- Compiler-generated functions.
- Library functions.
- Folded functions.
- Vtables.
- Globals.
- Strings.
- Source lines.
- Static variables attached to functions.
- Imports.

This prevents a common error: treating a compiler-generated thunk or library body as handwritten source.

### Effective matches

reccmp distinguishes exact matches from effective matches.

An effective match is not byte-identical. It is a carefully limited proof that the difference does not change behavior.

The comparator recognizes patterns such as:

- Reversed `cmp` operands with compatible branch reversal.
- Reversed `test` operands with compatible branch behavior.
- `mov` plus a commutative operation with swapped sources.
- Reordered `fld` and `fmul` operands.
- Safe movement of an instruction when no intervening instruction observes its changed register value.
- Register-only differences when the register mapping is consistent.

It rejects cases with:

- Different instruction counts.
- Different memory operands.
- Changed jump meaning.
- Duplicated or missing operations.
- Unsafe register swaps.
- Jump-table or data-table movement.

Important commits:

```text
42ae00a  Adds handling of compiler entropy for mov-cmp-jmp
1ad8a42  handles cases where floating ops are reordered by msvc 4.2
6730161  More "safe" asm diff fixes for MSVC entropy
49b30f8  Fix: Did not check all intermediate instructions when relocating
44393e7  Fix IndexError in asm patch helpers when recomp shorter than orig
abeee40  prints diff for effective matches in verbose mode
```

### Why this matters to Age of Empires

The current project is correctly strict for promotion. It should remain byte-strict for `src/matching`.

However, it needs a separate diagnostic classification. The reccmp model suggests:

```text
EXACT
EFFECTIVE DRIFT
STRUCTURAL MISMATCH
SEMANTIC MISMATCH
INCONCLUSIVE
```

The `EFFECTIVE DRIFT` category must not hide changed calls, widths, memory effects, cleanup, or fault order.

### Pinned sequence comparison

`reccmp/compare/pinned_sequences.py` uses known instruction-line associations as anchors.

It splits the diff around pinned lines. Each interval is compared separately.

This prevents one insertion from shifting the entire rest of the report.

The Age of Empires checker already has strong positional and edit/resynchronization diagnostics. A future diagnostic mode could use stable instruction or call anchors in the same way.

## 3. Yodecomp: compiler-context laboratory

Repository:

```text
https://github.com/shinyquagsire23/Yodecomp
```

Local path:

```text
C:\Users\Darius\AppData\Local\pi-web-smart-fetch\github-cache\shinyquagsire23\Yodecomp
```

Important paths:

```text
tools\dialsweep.py
tools\frontier.py
tools\idiomscan.py
tools\permute.py
tools\bytematch.py
docs\compiler-hunt.md
docs\bytematch-candidate-401490.md
toolchain\test\func_401490.c
```

### Compiler hunt

Yodecomp compared VC4.0, VC4.1, and VC4.2:

```text
VC4.0: cl 10.00.5270
VC4.1: cl 10.10.6038
VC4.2: cl 10.20.6166
```

Their findings:

- Instruction selection was effectively frozen across the VC4.x line.
- VC4.1 and VC4.2 produced the same exact-function set in their test.
- VC4.0 differed mostly in register allocation and scheduling.
- A suspected compiler wall was later explained by source fidelity or declaration context.
- A mixed-toolchain hypothesis was weaker than a pure compiler plus ambient-context hypothesis.

This is important. A stable register mismatch does not prove that the compiler version is wrong.

### `idiomscan.py`

This tool classifies non-exact functions.

It uses:

- Register-normalized alignment.
- Register penalty.
- Mnemonic multiset differences.
- Instruction selection signals.

It distinguishes:

```text
A: pure register allocation
B: register allocation plus alignment noise
C: scheduling
D: source or instruction idiom
```

It treats these opcodes as compiler or source-shape signals:

- `imul` and `idiv`: arithmetic lowering.
- Shifts: strength reduction.
- `rep`, `movsd`, `stosd`: copy and memset lowering.
- `sete`, `cmov`: branchless lowering.
- `lea` and `add`: address arithmetic.
- `movsx` and `movzx`: signedness and width.

The Age of Empires project should add a similar batch report for scratch functions.

### `dialsweep.py`

This tool appends unused declarations to an included header and recompiles the whole set.

It measures:

- Exact functions gained.
- Exact functions lost.
- Best declaration count.
- Functions affected by each context position.

The declarations are diagnostic dials. They are not retained as fake source.

If a neutral declaration changes the target register basin, the likely missing cause may be:

- A real missing declaration.
- Include order.
- A header parse state.
- Translation-unit context.
- Compiler internal numbering.

### `frontier.py`

This tool finds the first non-exact function after exact functions in a translation unit.

The hypothesis is that earlier exact functions prove the compiler state is aligned. The first non-exact function is therefore a good context-recovery target.

Yodecomp warns that the hypothesis is not always causal. Header-phase context can affect later allocator choices.

Use the frontier as a map, not as proof.

### `permute.py`

This tool explores focused source permutations:

- Adjacent independent statement swaps.
- Leading local declaration permutations.
- Equivalent comparison forms.
- Relational operand flips.

It uses data-dependency checks and a register-aware score.

It does not blindly permute all source text.

### Hard x87 example

Yodecomp studied a difficult score function at `0x00401490`.

The function used:

- A large record scan.
- x87 accumulation.
- Integer division.
- Floating-point range checks.
- Several constant score bands.

A direct-return version produced the wrong shape.

A shared result variable reproduced the original register behavior:

```asm
mov edi, value
mov eax, edi
```

The shared result also restored the default-zero path and other cascading details.

This demonstrates that a result variable can affect much more than the final return instruction.

### Yodecomp source-shape lessons

Useful axes include:

- Several direct returns versus one result variable.
- Reusing a parameter versus introducing a local.
- One shared iterator versus separate loop variables.
- Direct API reload versus saved pointer.
- Declaration near first use versus declaration at the top.
- `switch` versus `if` chain.
- Branch order.
- Comparison algebra.
- Explicit sequencing local for call order.
- Explicit casts around narrow values.
- x87 accumulator lifetime.

## 4. Dethrace: explicit compiler-entropy policy

Repository:

```text
https://github.com/dethrace-labs/dethrace
```

Local paths:

```text
C:\Users\Darius\AppData\Local\pi-web-smart-fetch\github-cache\dethrace-labs\dethrace\CONTRIBUTING.md
C:\Users\Darius\AppData\Local\pi-web-smart-fetch\github-cache\dethrace-labs\dethrace\reccmp\AGENTS.md
C:\Users\Darius\AppData\Local\pi-web-smart-fetch\github-cache\dethrace-labs\dethrace\reccmp\README.md
C:\Users\Darius\AppData\Local\pi-web-smart-fetch\github-cache\dethrace-labs\dethrace\reccmp\get_stack_slots.py
C:\Users\Darius\AppData\Local\pi-web-smart-fetch\github-cache\dethrace-labs\dethrace\reccmp\asm-match.sh
C:\Users\Darius\AppData\Local\pi-web-smart-fetch\github-cache\dethrace-labs\dethrace\tools\progress.py
```

### Matching rules

Their local matching rules say:

- Do not declare new variables.
- Do not rename, reorder, or remove declarations.
- Only swap variable usage.
- Do not change the function signature.
- Do not add unnecessary casts.
- Do not add gotos.
- Abort when stack size differs.
- Inspect stack slots before editing.
- Fix instruction presence before jump targets.
- Make one control-flow change at a time.
- Revert a regression immediately.

These rules are project policy, not universal compiler laws. They are useful because they prevent source experiments from changing too many variables at once.

### Floating-point stop rule

Dethrace shows an x87 case where VC4.2 reordered floating operations:

```asm
fld
fmul
faddp
```

became a different equivalent sequence.

They state that such differences are often not resolvable. Their workflow is:

1. Fix every other mismatch.
2. Confirm the remaining difference is x87 compiler entropy.
3. Stop.

This is a strong argument for an explicit x87-entropy classification in Age of Empires.

### Global entropy

Dethrace notes that an unchanged function can lose accuracy after another source change. Their CI warns about this but does not always reject it.

The practical model is:

```text
local source change
    -> changed compiler context
    -> unrelated function score changes
```

The Age of Empires project should track global regressions separately from target-local progress.

### Stack-slot helper

`reccmp/get_stack_slots.py` reads the MSVC assembly listing and maps local names to stack offsets before source edits.

This supports a useful rule:

> Recover the compiler's local-home topology before changing declaration shape.

The Age of Empires checker already supports VC5 listing-derived stack maps. It should be treated as a primary source-shape clue.

### Harness separation

Dethrace keeps modern platform code in:

```text
src/harness
```

The reconstructed game code remains separate from new platform code.

This is useful for any future runnable Age of Empires port.

## 5. Imperialism: strongest VC5 RTM evidence

Repository:

```text
https://github.com/agluszak/imperialism-decomp
```

Local paths:

```text
C:\Users\Darius\AppData\Local\pi-web-smart-fetch\github-cache\agluszak\imperialism-decomp\decomp\docs\toolchain.md
C:\Users\Darius\AppData\Local\pi-web-smart-fetch\github-cache\agluszak\imperialism-decomp\decomp\docs\workflows.md
C:\Users\Darius\AppData\Local\pi-web-smart-fetch\github-cache\agluszak\imperialism-decomp\decomp\.agents\skills\decompile-function\SKILL.md
C:\Users\Darius\AppData\Local\pi-web-smart-fetch\github-cache\agluszak\imperialism-decomp\decomp\.agents\skills\decompile-function\references\matching.md
C:\Users\Darius\AppData\Local\pi-web-smart-fetch\github-cache\agluszak\imperialism-decomp\decomp\.agents\skills\decompile-function\references\cpp-recovery.md
```

### Toolchain evidence

Their target uses:

```text
VC5 RTM
CL  11.00.7022
LINK 5.00.7022
```

They tested VC5 service packs by replacing the compiler tree inside the same Docker image.

Their results show that SP1, SP2, and SP3 change code generation broadly. They rejected the service packs.

This directly supports keeping the Age of Empires VC5 RTM compiler.

### Historical SDK headers matter

Imperialism uses DirectX 5 SDK headers from August 1997.

The VC5 package includes an older DirectX 1 `dplay.h`. The retail binary uses later vtable slot positions.

They put the DirectX 5 include path before the VC5 include path.

This demonstrates that an apparently harmless SDK header mismatch can change:

- Vtable layout.
- Method slot selection.
- Call targets.
- Class declarations.
- Generated code.

### Linker flags matter

Their matching baseline pins:

```text
/OPT:NOREF
/OPT:NOICF
```

They found:

- `/OPT:REF` discards unreferenced functions and destroys the comparison surface.
- `/OPT:ICF` folds bodies and destroys vtable pairing.
- `/Gy` had no useful effect in their case.
- Average similarity can rise while exact coverage gets worse if difficult functions disappear.

The Age of Empires project must not judge linker experiments by average similarity alone.

### Structured triage

Imperialism uses three important statuses:

```text
mismatch
```

A structured machine-level difference exists. This is source-recovery evidence.

```text
effective
```

The comparator proved the difference harmless. No source action is required.

```text
inconclusive
```

The comparator could not prove safety or harm. This is not evidence of a source defect.

Their `tools/reccmp/triage.py` reports the first structured divergence and explains likely causes:

- Different field displacement.
- Different stack location.
- Different receiver.
- Different call argument.
- Different branch predicate.
- Different callee-saved state.

The Age of Empires checker already reports many lower-level facts. A future status layer should expose this three-way interpretation.

### Runtime differential testing

Imperialism has a separate runtime implementation and uses the C++ reconstruction as an oracle.

It compares the smallest meaningful state boundary. It does not copy the original ABI into the runtime implementation.

This provides a second proof dimension:

```text
machine comparison
+ runtime behavioral comparison
```

### Source recovery rules

Their matching guide says:

1. Start from retail control flow and data dependencies.
2. Preserve branch order.
3. Preserve signedness and widths.
4. Preserve literal values.
5. Preserve side-effect order.
6. Verify every call's receiver and argument setup.
7. Do not treat a Ghidra `__cdecl` label as proof.
8. Keep natural typed expressions when compiler variation is harmless.
9. Do not add casts or spills only to chase registers.
10. Trace the first structured divergence back to the source model.

Their class-recovery guide rejects:

- Raw vtable indexing as permanent source.
- Function-pointer casts as permanent source.
- Manual vtable writes.
- Placement-new bridges.
- Fake runtime helpers.
- Fake base constructors or destructors.

The class model should produce those operations naturally.

### Concrete VC5 source examples

#### Direct API reload

File:

```text
decomp/src/game/assets/TMovieView.cpp
```

The source calls `AfxGetThread()` again instead of saving its result. The comment calls this the standard MSVC500 “call again to use” idiom.

This supports testing direct reloads when a saved pointer moves register allocation.

#### Sequencing a call

File:

```text
decomp/src/game/core/TStream.cpp
```

The function stores `GetPosition()` in a local before calling `GetLength()`.

This forces the original call order. It avoids relying on unspecified C++ evaluation order.

#### Local translation-unit declaration

File:

```text
decomp/src/game/map/map_tile_adjacency.cpp
```

A declaration stays local because moving it into a widely included header perturbs other functions.

This is direct evidence for testing local declaration context before shared-header edits.

#### Inline budget control

File:

```text
decomp/src/game/map/sea_geometry.cpp
```

The source uses `#pragma inline_depth(0)` around a large function. The original VC5 output inlines a helper at some sites but emits calls at others because the inline budget is exhausted.

This suggests that call-versus-inline mismatches may require:

- Correct helper visibility.
- Correct source placement.
- Correct `/Ob` setting.
- Local `inline_depth` control.

Do not add the pragma without matching evidence.

#### Uninitialized locals and compiler shape

`TMovieView.cpp` preserves a member that is not explicitly zeroed because the retail listing does not write it. The source does not “fix” the missing initialization.

This is an important period-source rule:

> Do not initialize values only because modern source style expects it.

## 6. Rebrew: automated source and flag search

Repository:

```text
https://github.com/maci0/rebrew
```

Local path:

```text
C:\Users\Darius\AppData\Local\pi-web-smart-fetch\github-cache\maci0\rebrew
```

Relevant paths:

```text
src/rebrew/matcher/compiler.py
src/rebrew/matcher/flags.py
src/rebrew/matcher/mutator.py
src/rebrew/matcher/scoring.py
src/rebrew/match.py
docs/FLAG_SWEEP_TIERS.md
toolchain/msvc/5.0-win32/Dockerfile
```

### Compiler profiles

Rebrew has profiles for:

- MSVC 4.2 win32.
- MSVC 5.0 win32.
- MSVC 6.0 win32.
- Other old and modern compilers.

Its MSVC5 profile uses the `archaic-msvc/msvc500` source tree with a pinned SHA-256.

### Flag sweep tiers

Rebrew separates flag searches into tiers:

```text
quick:    small, high-impact sweep
 targeted: /O, /Oy, /Op and similar common axes
normal:   broader runtime and inlining axes
thorough: alignment and debug axes
full:     expensive /TP, /GR, /GX and other axes
```

The key idea is not the specific flag list. It is the staged search.

Use cheap, likely axes first. Reserve large sweeps for targets whose behavior, call set, frame, and size already match.

### Source mutations

Rebrew can mutate:

- Condition forms.
- Boolean negation.
- De Morgan forms.
- Arithmetic reassociation.
- Operand order.
- Guard clauses.
- Loop forms.
- Return placement.
- Temporary introduction and removal.
- Declaration initialization splitting.
- Pointer and array forms.
- Cast and mask forms.
- Switch and if-chain forms.
- Dummy variables.
- Volatile spill forcing.
- Stack-frame shaping.

The mutation engine is useful as a diagnostic laboratory. Its generated winner is not automatically good source.

The Age of Empires source-plausibility rule remains stricter:

- Do not retain fake volatile qualifiers.
- Do not retain dummy variables without real evidence.
- Do not retain raw offset scaffolding when named ownership is known.
- Review every automated winner as source.

## 7. AGS2 and ReC98: original compiler discipline

### AGS2

Repository:

```text
https://github.com/adm244/ags2_decomp
```

AGS2 reconstructs a DOS runtime with the original 1998 DJGPP/GCC toolchain.

Useful lessons:

- Use the original compiler whenever possible.
- Match functions individually.
- Keep a simple per-symbol diff loop.
- Separate the engine target from unrelated editor code.

The compiler differs from VC5, so its codegen lessons do not transfer directly.

### ReC98

Repository:

```text
https://github.com/nmlgc/ReC98
```

ReC98 reconstructs PC-98 games with the original Borland compiler.

Useful lessons:

- Obsolete compilers can run under emulation.
- Original libraries can remove large reconstruction work.
- Readable source and exact output can coexist.
- Separate original, debloated, and bug-fixed goals.
- Keep compiler and library versions pinned.

## Cross-project conclusions

### 1. Old MSVC is deterministic but discontinuous

The compiler is not random when inputs are identical.

Small source changes can cross optimizer thresholds. The output can then change greatly.

Typical sensitive inputs include:

- Local declaration order.
- Parameter reuse.
- Temporary lifetime.
- Header declaration order.
- Function visibility.
- Inline definitions.
- `/Ob` settings.
- x87 expression shape.
- Call sequencing.
- Translation-unit position.
- Linker folding and reference retention.

### 2. The true unit is not always one function

For difficult functions, the relevant input may be:

```text
function body
+ signature
+ class layout
+ visible declarations
+ headers
+ translation-unit order
+ inline context
+ compiler flags
+ linker settings
```

This explains why isolated scratch files eventually stop producing progress.

### 3. Some mismatches are irreducible compiler entropy

Dethrace explicitly stops on some x87 reorderings.

reccmp has safe effective-match rules for several old-MSVC variations.

Imperialism uses `inconclusive` when proof is unavailable.

The project should not force every function into exact matching.

### 4. Function size is an early gate

If the stack frame or function size is wrong, do not tune registers first.

Dethrace aborts when stack size differs.

Imperialism first reports structured memory and stack differences.

The Age of Empires checker already has structural workflow stages. This should remain authoritative.

### 5. Header changes can have global cost

Imperialism keeps some declarations in one translation unit because shared-header edits change many functions.

Yodecomp's header dial experiments show the same general effect.

Shared headers should change only when the declaration is stable and reusable.

### 6. Linker settings affect the comparison surface

Do not use `/OPT:REF` or `/OPT:ICF` casually.

Unreferenced functions may disappear. Folded functions may share addresses. Average similarity can improve while exact coverage gets worse.

### 7. Compiler-generated code needs explicit classification

A target may be:

- A handwritten function.
- A scalar deleting destructor.
- A thunk.
- A template instantiation.
- A library function.
- A folded COMDAT.
- An inline-only function.
- An out-of-line compiler-generated copy.

Do not invent handwritten source for compiler-owned bodies.

## Recommended Age of Empires improvements

### A. Add an effective-drift classifier

Create a read-only diagnostic tool. It should report:

- Exact positional equality.
- Same instruction count.
- Register-normalized equality.
- Consistent register mapping.
- Reversed compare operands.
- Compatible branch reversal.
- Commutative operand swap.
- Safe instruction movement.
- x87 `fld`/`fmul` reorder.
- Changed memory operand.
- Changed call target.
- Changed instruction count.
- Changed stack cleanup.

Do not use this tool for exact promotion. Use it to route work.

Suggested output:

```text
EXACT
EFFECTIVE_REGISTER_DRIFT
EFFECTIVE_COMMUTATIVE_DRIFT
EFFECTIVE_X87_DRIFT
STRUCTURAL_MISMATCH
SEMANTIC_MISMATCH
INCONCLUSIVE
```

### B. Add an idiom classifier

Borrow Yodecomp's `idiomscan.py` idea.

Classify each scratch function by mnemonic differences:

- Pure register allocation.
- Scheduling.
- Arithmetic lowering.
- Copy or memset lowering.
- Branchless lowering.
- Signedness or width.
- Address-generation shape.
- Broad source or CFG mismatch.

### C. Add a context-lab mode

For late-stage functions only, vary:

- Local versus shared declaration.
- Original include set.
- Header declaration order.
- Function placement.
- Preceding exact functions.
- Helper visibility.
- Inline depth.
- `/Ob1` and `/Ob2`.

Keep generated context in `build/`. Do not keep diagnostic dials in living source without proof.

### D. Use stack maps before source mutation

Run the VC5 listing stack map first.

Recover:

- Parameter homes.
- Local homes.
- Reused homes.
- Overlapping lifetimes.
- Incoming parameter reuse.

Then choose source declarations that express the observed lifetime topology.

### E. Split source and context hypotheses

Every attempt should state whether it tests:

```text
behavior
ABI/layout
control flow
local lifetime
header context
translation-unit context
inline budget
flags
linker behavior
```

Do not mix all axes in one variant family.

### F. Add a global regression report

Record target-local change and unrelated-function change separately.

An unchanged function that moves after a source edit may be compiler-context entropy. It should be visible, not silently treated as a new source defect.

### G. Use runtime evidence for stalled targets

Once exact matching reaches a stable blocker:

- Keep the clean typed source.
- Validate calls and memory effects against the executable.
- Run focused runtime comparisons when possible.
- Route proven effective drift to the semantic-review process.

Do not retain opaque codegen scaffolding only because it has a smaller byte diff.

## Suggested hard-function workflow

1. Confirm the target is a normal function.
2. Confirm the exact toolchain and response file.
3. Record the original function size and frame.
4. Inspect the original listing and stack map.
5. Confirm calls, cleanup, and memory widths.
6. Classify the first structural difference.
7. Fix ABI, layout, and CFG before register work.
8. Compare mnemonic and register-normalized shapes.
9. Test natural source forms.
10. Test one context axis at a time.
11. Use a focused variant lab only after invariants hold.
12. Classify the remaining drift.
13. Stop if only proven or strongly evidenced compiler entropy remains.
14. Validate the clean source.
15. Route the result to exact matching, accepted drift, or semantic review according to project policy.

## Final synthesis

The external projects do not show a magic source spelling that solves VC5 matching.

They show a more useful strategy:

```text
recover ABI and source ownership
        ↓
recover compiler and translation-unit context
        ↓
compare structured machine behavior
        ↓
classify exact, effective, mismatch, and inconclusive cases
        ↓
use focused source and context experiments
        ↓
stop when only compiler entropy remains
```

The Age of Empires project already has strong exact-match infrastructure. Its main missing layer is not another generic source mutation system. It is a formal distinction between:

- A wrong source model.
- A wrong compiler context.
- A safe old-MSVC codegen variation.
- A comparator limitation.
- An irreducible compiler-entropy case.

That distinction should guide the next phase of work.
