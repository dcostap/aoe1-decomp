# Variant lab guide

`tools\variant_lab.py` compiles many source/flag variants for one function,
compares each emitted object against the original function bytes, and groups
variants by emitted machine code. It is meant for **late-stage VC5 codegen-basin
work** after the behavior and likely source model are already mostly understood.
It never edits `src\scratch` or `src\matching`; all generated files live under
`build\variant_lab\<slug>\<run-id>\`.

For command syntax, the executable source of truth is still:

```bat
python tools\variant_lab.py --help
```

## Quick command reference

Create a throwaway template from the current preferred source:

```bat
python tools\variant_lab.py --init --va 0046A9E0
```

Run a lab:

```bat
python tools\variant_lab.py --va 0046A9E0 --template build\temp\0046A9E0_operator_lab.tpl.cpp
```

Inspect without compiling:

```bat
python tools\variant_lab.py --list-templates
python tools\variant_lab.py --template-help vc5_guard
python tools\variant_lab.py --template build\temp\some_lab.tpl.cpp --expand-only
python tools\variant_lab.py --template build\temp\some_lab.tpl.cpp --preview-variants 3
python tools\variant_lab.py --template build\temp\some_lab.tpl.cpp --show-variant V000042
```

Large-run controls:

```bat
python tools\variant_lab.py --va 0046A9E0 --template build\temp\some_lab.tpl.cpp --max-variants 500000
python tools\variant_lab.py --va 0046A9E0 --template build\temp\some_lab.tpl.cpp --max-variants 0
python tools\variant_lab.py --va 0046A9E0 --template build\temp\some_lab.tpl.cpp --no-dedupe-expanded
```

`--max-variants 0` disables the safety cap. `--no-dedupe-expanded` is usually
only for debugging the lab runner itself; normal labs should keep dedupe enabled.

## Basic source choices

Use `@choice` to define a source axis:

```cpp
@choice update_shape
@case compound
x += y;
@case assign
x = x + y;
@endchoice
```

Each active axis selects one `@case`. The selected label appears in reports as,
for example:

```text
src.update_shape=compound
```

Reusing the same axis name links choices together. If one active block selects
`compound`, every active `@choice update_shape` block uses `compound`. If a
linked block omits the selected case, that block emits nothing.

Duplicate `@case` labels in the same block are rejected so typoed templates fail
early.

## Nested choices

Choices may be nested inside `@case` bodies. Nested axes are active only when
their parent case is selected. This avoids multiplying unrelated branches.

```cpp
@choice outer
@case with_inner
    @choice inner
    @case a
    int x = 1;
    @case b
    int x = 2;
    @endchoice
@case no_inner
    int x = 3;
@endchoice
```

This generates three variants:

```text
src.outer=with_inner;src.inner=a
src.outer=with_inner;src.inner=b
src.outer=no_inner
```

It does **not** generate `outer=no_inner` times every `inner` case. Inactive axes
are omitted from labels and reports.

Nested `@flagchoice` blocks work too. A flag axis inside a source case is only
active when that source case is selected.

## Flag choices and flag presets

Use `@flagchoice` or `@flags` to append per-variant flags after
`config\flags\default.rsp`:

```cpp
@flagchoice debug_info
@case none
@case zd
/Zd
@endflagchoice
```

Selected flag text is removed from generated C/C++ and written to that variant's
`variant_flags.rsp`. Debug-info variants automatically get a unique `/Fd...`
when needed to avoid parallel PDB collisions.

Reusable flag presets are appended from the command line:

```bat
python tools\variant_lab.py --va 0046A9E0 --template build\temp\lab.tpl.cpp --flag-preset vc5-small
python tools\variant_lab.py --va 0046A9E0 --template build\temp\lab.tpl.cpp --flag-preset vc5-risky
python tools\variant_lab.py --va 0046A9E0 --template build\temp\lab.tpl.cpp --flag-preset vc5-debug-context
```

Flag presets are classification tools. A match under non-default appended flags
still needs normal review, re-testing, and justification before promotion.

## Reusable `@template` presets

Preset files live in:

```text
config\variant_templates\
```

They are plain text files that expand to ordinary `@choice` / `@flagchoice`
template text before parsing. List or inspect them with:

```bat
python tools\variant_lab.py --list-templates
python tools\variant_lab.py --template-help vc5_guard
```

Single-line preset usage:

```cpp
@template vc5_dummy_member_surface axis=member_ctx class=Path prefix=ctx
```

Block preset with a user body slot:

```cpp
@template vc5_guard axis=outer_resize_gate cond="maxSizeValue < other.maxSizeValue"
@slot body
    setMaxSize(other.maxSizeValue);
@endslot
@endtemplate
```

Preset arguments use shell-style `key=value` parsing. Quote values with spaces or
operators. Common defaults supplied by the lab include:

```text
prefix=<sanitized axis/name>
tmp=<prefix>_tmp
tmp2=<prefix>_tmp2
tmp3=<prefix>_tmp3
type=int
ptr=<prefix>_ptr
size=16
shift=4
ret=void
name=<prefix>_helper
params=void
index=i
inverse=!(<cond>) when cond=... is supplied
```

Inside preset files, use `{{name}}` for arguments and `{{slot:body}}` for user
slots. Slot filters can be chained:

```text
{{slot:body|trim}}
{{slot:body|rstrip}}
{{slot:body|trim|indent:4}}
```

Supported filters:

- `trim`
- `lstrip`
- `rstrip`
- `chomp` (alias for `rstrip`)
- `indent:N`

Templates may be nested inside ordinary `@case` bodies. The nested axes are only
active for the selected outer case, just like handwritten nested choices.

## Current starter preset families

| Preset | Purpose |
| --- | --- |
| `vc5_dummy_member_surface` | Neutral dummy class member declarations, ctor/dtor/operator declarations, `foo()` vs `foo(void)` style context. |
| `vc5_update_expr` | Equivalent numeric/member update spellings such as `+=`, `x = x + y`, named temps. |
| `vc5_guard` | Guarded body spellings, no-brace forms, inverted empty arms, unguarded body. |
| `vc5_loop_count` | Common counted-loop spellings around a body slot. |
| `vc5_alloc` | `operator_new`, `new[]`, count temps, byte-size temps. |
| `vc5_assign_temp` | Direct expression use versus named temp lifetime variants. |
| `vc5_bool_return` | Direct boolean return versus explicit 0/1 branches and narrow temps. |
| `vc5_helper_extract` | Helper/declaration surface experiments. |
| `vc5_standard_headers` | Opt-in standard-header on/off axes. |

Add new preset cases or new preset files as real matching work discovers reusable
VC5 basins. Use neutral names for codegen-only dummy declarations; do not invent
semantic names without evidence.

## Previewing generated code

Use preview modes before launching a broad compile run:

```bat
python tools\variant_lab.py --template build\temp\lab.tpl.cpp --expand-only
python tools\variant_lab.py --template build\temp\lab.tpl.cpp --preview-variants 5
python tools\variant_lab.py --template build\temp\lab.tpl.cpp --show-variant 17
python tools\variant_lab.py --template build\temp\lab.tpl.cpp --show-variant V000017
```

These modes do not need `--va` and do not compile. They are intended to catch
syntax mistakes, accidental giant expansions, and surprising slot indentation
before VC5 is invoked.

## Output layout

Each compile run writes:

```text
build\variant_lab\<slug>\<run-id>\
  summary.txt
  manifest.json
  variants.tsv
  groups.tsv
  axis_sensitivity.tsv
  compile_errors.tsv
  template_input.cpp
  effective_template_input.cpp       if @template or flag presets were used
  template_expansions.json           if @template presets were used
  flag_presets.tpl                   if --flag-preset was used
  work\V000000\source.cpp
  work\V000000\<slug>.obj
  work\V000000\variant_flags.rsp     if extra flags were used
  work\V000001\dedup_alias.txt       for deduped duplicate variants
  groups\G0000\representative.cpp
  groups\G0000\rebuilt.bin
  groups\G0000\rebuilt.asm
  groups\G0000\diff.txt
  matches\match_0000_V000123\...     exact-match generated sources, if any
```

Start with `summary.txt`. Then inspect `groups/Gxxxx/diff.txt`,
`groups/Gxxxx/representative.cpp`, and the specific variant row in
`variants.tsv`.

## Dedupe behavior

Before compiling, the lab hashes each fully expanded source body plus its extra
flags. Identical expansions are compiled once, then duplicate variants are
reported as aliases of the representative result. This saves time in large
nested/preset sweeps where different labels sometimes collapse to identical
source.

`summary.txt` records:

```text
Variants generated: <all expanded label states>
Compile jobs: <unique source/flag expansions compiled>
Deduped variants: <skipped duplicate compiles>
```

A deduped variant still has a `work/Vxxxxxx/source.cpp` for auditability and a
`dedup_alias.txt` pointing at the representative object.

## Reading match reports

Important `summary.txt` fields:

- `Variants generated` — all active label states after nested-choice pruning.
- `Compile jobs` — unique source/flag expansions actually compiled.
- `Unique asm groups` — number of distinct emitted-code groups.
- `Exact matches` — number of exact-match variants.
- `Axes` — active axes and labels; axes produced by presets include a
  `from @template ...` note.
- `Exact-match axis sensitivity` — per-axis summary of matching and nonmatching
  labels, e.g. `if_cond(1/1)` means 1 exact match among 1 variant using that
  label.
- `Top groups` — emitted-code groups. `exact=1` means the group has at least one
  exact variant; `exact_count=N` gives the exact number of exact variants in the
  group.

`axis_sensitivity.tsv` gives the same exact/mismatch/error counts in TSV form.

## Common patterns

Guard shape sweep:

```cpp
@template vc5_guard axis=outer_resize_gate cond="maxSizeValue < other.maxSizeValue"
@slot body
    setMaxSize(other.maxSizeValue);
@endslot
@endtemplate
```

Nested dummy-surface sweep under one source family:

```cpp
@choice context_family
@case try_dummy_surface
@template vc5_dummy_member_surface axis=member_ctx class=Path prefix=ctx
@case no_dummy_surface
@endchoice
```

This generates the dummy-member variants only under `try_dummy_surface`, plus one
`no_dummy_surface` branch.

## Policy reminders

- Broad sweeps are for late-stage convergence, not for replacing function
  understanding.
- Exact matches found by the lab still require normal source review and local
  validation before promotion.
- Reduce a winning context to the smallest proven surface before committing.
- Do not use inline asm or source-level hacks to force a match.
- For codegen-only dummy context, use neutral names like `dummy` / `codegen_dummy`.
  Do not invent semantic names or signatures.
