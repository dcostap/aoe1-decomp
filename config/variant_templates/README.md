# Variant lab reusable templates

`tools/variant_lab.py` expands `@template` directives from this directory before
normal `@choice` parsing.  These files are intentionally plain text so matching
work can grow reusable VC5 source-shape families over time.

Canonical lab reference: `python tools\variant_lab.py --help`.

Useful inspection commands:

```bat
python tools\variant_lab.py --list-templates
python tools\variant_lab.py --template-help vc5_guard
python tools\variant_lab.py --template build\temp\some_lab.tpl.cpp --expand-only
python tools\variant_lab.py --template build\temp\some_lab.tpl.cpp --preview-variants 3
```

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
- `vc5_loop_count` — common counted-loop spellings around a body slot.
- `vc5_alloc` — `operator_new`, `new[]`, count temps, byte-size temps.
- `vc5_assign_temp` — direct expression use versus named temp lifetime variants.
- `vc5_bool_return` — direct boolean return versus explicit 0/1 branches and narrow temps.
- `vc5_helper_extract` — helper/declaration surface experiments.
- `vc5_standard_headers` — opt-in standard-header on/off axes.

Conventions:

- Use neutral dummy names for codegen-only context. Do not invent semantic names.
- Keep each template family broad but source-level: no inline asm, no fake hacks.
- Add new cases freely as real matching work discovers reusable VC5 basins.
- Exact matches from broad presets must still be reduced and reviewed before
  promotion.
