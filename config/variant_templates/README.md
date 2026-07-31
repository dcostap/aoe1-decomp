# Variant lab reusable templates

`tools/variant_lab.py` expands `@template` directives from this directory before
normal `@choice` parsing.  These files are intentionally plain text so matching
work can grow reusable VC5 source-shape families over time. Each preset should
start with a short `// TEMPLATE ...` comment explaining why it exists.

Canonical lab reference: `python tools\variant_lab.py --help`.

Useful inspection commands:

```bat
python tools\variant_lab.py --list-templates
python tools\variant_lab.py --template-help vc5_guard
python tools\variant_lab.py --template build\temp\some_lab.tpl.cpp --expand-only
python tools\variant_lab.py --template build\temp\some_lab.tpl.cpp --preview-variants 3
python tools\variant_lab.py --template build\temp\some_lab.tpl.cpp --preview-variants 1 --preview-full
```

`--preview-variants` is compact by default. Use `--preview-full` only to inspect
all generated text, or `--show-variant V000123` for one full expansion.

Basic usage:

```cpp
@template vc5_dummy_member_surface axis=member_ctx class=Path
```

Block templates can consume slots:

```cpp
@template vc5_guard axis=gate cond="value > 0"
@slot body
    do_work();
@endslot
@endtemplate
```

Templates may be nested inside ordinary `@case` bodies. Inner axes are only
active for the selected outer case, so this is safe for broad source-family
sweeps without multiplying unrelated branches. Identical expanded source/flag
variants are deduped before compile by default; use `--no-dedupe-expanded` only
when debugging the lab runner itself.

Template files use `{{name}}` placeholders for arguments and `{{slot:body}}` for
user-provided body slots. Slot filters can be chained, for example
`{{slot:body|trim|indent:4}}`; supported filters are `trim`, `lstrip`,
`rstrip`/`chomp`, and `indent:N`.

Current starter families:

- `vc5_dummy_member_surface` — dummy class member declarations, ctor/dtor/operator declarations, `foo()` vs `foo(void)` style context.
- `vc5_update_expr` — equivalent numeric/member update spellings (`+=`, `x=x+y`, named temps).
- `vc5_guard` — guarded body spellings, inverted empty arm, unguarded body.
- `vc5_store_order2`, `vc5_store_order3`, `vc5_store_order4` — permute independent stores/statements.
- `vc5_decl_init_order2` — separate local declaration order from init order.
- `vc5_call_result_test` — direct call-test vs result locals and result width.
- `vc5_byte_select` — condition-to-byte/value selection spellings.
- `vc5_pointer_local_use` — direct access vs pointer local lifetime variants.
- `vc5_loop_count` — common counted-loop spellings around a body slot.
- `vc5_loop_access_shape` — index loop vs running-entry local variants.
- `vc5_alloc` — `operator_new`, `new[]`, count temps, byte-size temps.
- `vc5_assign_temp` — direct expression use versus named temp lifetime variants.
- `vc5_bool_return` — direct boolean return versus explicit 0/1 branches and narrow temps.
- `vc5_vtable_pad_surface` — neutral dummy virtual slots for vtable offset probes.
- `vc5_dtor_surface` — destructor/class-surface declaration variants.
- `vc5_ctor_init_zero_surface` — constructor init-list vs body zeroing variants.
- `vc5_stack_array_shape` — stack array size/layout variants.
- `vc5_helper_extract` — helper/declaration surface experiments.
- `vc5_standard_headers` — opt-in standard-header on/off axes.

Conventions:

- Use neutral dummy names for codegen-only context. Do not invent semantic names.
- Keep each template family broad but source-level: no inline asm, no fake hacks.
- Add new cases freely as real matching work discovers reusable VC5 basins.
- Exact matches from broad presets must still be reduced and reviewed before
  promotion.

For a localized late-stage lab, combine splice templates with focused scoring and
hard invariants when appropriate:

```bat
python tools\variant_lab.py --va 004524E0 --template build\temp\gate.tpl.cpp ^
  --splice-base src\scratch\004524E0_setup.cpp ^
  --splice-start "// LAB START" --splice-end "// LAB END" ^
  --focus-range +0490-+04B0 --require-size --require-frame --require-call-set ^
  --session-owner AgentName
```

These gates do not compile a region independently. Every variant remains a full
function/TU compile; reports rank groups that preserve requested whole-function
invariants before ineligible groups. The size gate follows checker-equivalent
effective-boundary logic, ignoring unreachable compiler context tails but not
entry-reachable overflow. One lab run counts as one meaningful `variant` probe;
`--session-owner` records it against the active lease automatically.
