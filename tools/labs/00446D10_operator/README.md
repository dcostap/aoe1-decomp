# `00446D10_operator` VC5 micro-harness

This lab is an **isolated codegen sandbox** for the stubborn `DString::operator[](int)` near-match at VA `00446D10`.

The goal is not to churn the live scratch file over and over. The goal is to **systematically generate many tiny source variants**, compile them with the pinned VC5 toolchain, disassemble the resulting `.obj`, and cluster the outputs into stable codegen families.

## Why this exists

`00446D10` is now understood behaviorally. The remaining gap is a tiny VC5 codegen question:

- some source trees compile to an **entry-EDX** family,
- some compile to an **entry-EAX but bridge-through-EDX** family,
- and the original wants the compact final shape with `add eax,[ecx]`.

This harness lets us search that space without polluting `src\scratch`.

## Repo hygiene

Tracked files live only here:

- `tools/labs/00446D10_operator/run_lab.py`
- `tools/labs/00446D10_operator/README.md`

All generated artifacts go under the ignored build tree:

- `build/labs/00446D10_operator/generated/`
- `build/labs/00446D10_operator/obj/`
- `build/labs/00446D10_operator/asm/`
- `build/labs/00446D10_operator/reports/`

So the repo stays clean.

## What the harness does

For each variant it will:

1. write an isolated `.cpp` file under `build/labs/.../generated/`,
2. compile it with the pinned VC5 compiler and the default project response file,
3. extract `.text` bytes from the object file,
4. disassemble those bytes at VA `00446D10`,
5. compare the bytes against the original function bytes from the reference EXE,
6. classify the result into a simple family such as:
   - `entry_edx_family`
   - `entry_eax_bridge_edx_family`
   - `target_like_family`

## Usage

Run the full current matrix:

```bash
python tools/labs/00446D10_operator/run_lab.py --clean
```

Run only a subset by regex:

```bash
python tools/labs/00446D10_operator/run_lab.py --variant ptradd
```

Run only the first 12 filtered variants:

```bash
python tools/labs/00446D10_operator/run_lab.py --variant expr__fail_ternary --limit 12
```

## Outputs

After a run, inspect:

- `build/labs/00446D10_operator/reports/summary.md`
- `build/labs/00446D10_operator/reports/summary.csv`
- `build/labs/00446D10_operator/reports/summary.json`

Per-variant sources and asm are kept too:

- `build/labs/00446D10_operator/generated/<variant>.cpp`
- `build/labs/00446D10_operator/asm/<variant>.txt`

## How to extend it

Edit `run_lab.py` and add more variants in either:

- the generated expression matrix (`OFFSET_EXPRESSIONS` / `FINAL_EXPRESSION_TEMPLATES`), or
- the handwritten families in `build_handwritten_variants()`.

This is meant to be a reusable **VC5 expression-shape lab**, not just a one-shot script.
