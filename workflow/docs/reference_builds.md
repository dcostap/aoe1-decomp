# Older-build reference tools

The July 1998 executable remains the behavior oracle.
Older code supplies source hypotheses, not target offsets or automatic matches.

## Index the January build

Read tool help before use:

```text
python tools/reference_build.py --help
python tools/reference_build.py index --help
python tools/reference_build.py query --help
```

`config/reference_builds.json` pins the executable and map hashes.
Supply the local download root. The tool does not download or execute older files.

```text
python tools/reference_build.py index --root C:/Users/Darius/Downloads/age_of_empires_leaked_builds --output build/references/january.json
```

The tool verifies hashes, PE/map timestamps, and image bases.
It preserves duplicate names, addresses, and object owners.
Each query verifies the manifest and original files again.
It reparses the pinned map instead of trusting cached symbol rows.

## Find a counterpart

```text
python tools/reference_build.py query --index build/references/january.json --va 004020C0 --output build/references/004020C0.json
python tools/reference_build.py query --index build/references/january.json --query tech_cost --output build/references/tech_cost.json
```

Use `--symbol` for an exact decorated name from a search result.
Quote that name in the shell.
Use `--owner` with the exact map owner when a name has several definitions.

The VA query first uses original linkage evidence.
Without that evidence, it labels registry or inventory names as search hypotheses.
Absent exact counterparts produce same-short-name candidates when a decorated search name exists.
These candidates can expose changed parameters, owners, or signatures. They do not prove correspondence.

JSON and text reports contain:

- candidate names and original object owners;
- named call targets and absolute memory references;
- original-target and older-build disassembly;
- memory operand widths, registers, scales, and displacements; and
- input hashes and explicit evidence limits.

Disassembly requires one exact named function address.
The next symbol or executable section end bounds the older inspection window.
That bound is not a proved function boundary. Hidden fragments and padding can remain inside the window.
Memory operands are instruction facts, not inferred class fields.
Instruction decode coverage appears in the JSON report.

`target_dossier.py` prints the VA query command under its next checks.

## Use the evidence

1. Compare signatures, calls, branches, loop forms, and local stack use.
2. State one source hypothesis that explains the target instructions.
3. Test natural alternatives with `variant_lab.py`.
4. Preserve tested inputs through the normal experiment workflow.
5. Validate the selected source against the July executable and affected owners.

An older implementation can explain source structure even when behavior changed later.
Never copy older constants, field offsets, or behavior without target evidence.
Do not replace the July compiler profile because an older build used another compiler.

See `workflow/decomp_notes/older_leaked_builds_survey.md` for provenance and other available evidence.
