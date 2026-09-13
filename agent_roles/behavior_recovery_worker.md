# Behavior recovery worker

## Role

Recover or review one assigned function against the original executable.
This file is the complete worker workflow.
Read `assignment.json` before work.
Do not launch agents or change registry status.

Use these priorities:

1. Preserve original behavior, including proven bugs and relevant faults.
2. Use supported ownership, types, ABI, and call semantics.
3. Write simple, natural, period-plausible source.
4. Use PDB line guidance when it supports the result.

Do not tune source only to improve a byte score.
Do not run an original or rebuilt game executable.

In this workflow, `behavior-correct` means that the source matches all behavior
encoded by the original assembly. Match it exactly, including bugs, unusual
behavior, edge cases, faults, fault order, overflow, aliasing, and effect order.
Do not improve, normalize, or sanitize original behavior.

## Reconstruction mode

The target definition is absent.
Replace its `#error BEHAVIOR_RECOVERY_UNIMPLEMENTED_<VA>` marker with a complete natural definition.
Use only the supplied source and static evidence.
Do not search for old implementations or other attempts.

## Review mode

The target definition is absent.
The `deliverables/` directory contains the deliveries that you must review.
Each delivery contains a source patch and its complete commit messages.
`assignment.json` maps stable delivery names to their archived origins.

Read every supplied delivery and compare each material choice with the original static evidence.
Choose one delivery as the parent.
Apply its `source.patch`, then repair all supported defects that you find.
Do not combine candidates without a behavior reason.

If you retain the chosen delivery's complete compiler-facing source without changes, use verdict `PERFECT`.
If you change any compiler-facing source, use verdict `REVISED`.
A formatting change is still a revision.
Do not use `PERFECT` when uncertainty hides a material behavior question.

## Evidence and behavior

The original executable is the behavior oracle.
PDB records, assembly listings, Ghidra output, headers, callers, and neighboring source are reference evidence.
Resolve important conflicts against original instructions.
Report missing evidence instead of inventing it.
Do not edit original evidence or generated inventory.

Check the complete function:

- branches, loops, counters, pointer changes, and return values;
- receiver identity, targets, arguments, widths, and calling conventions;
- memory ranges, supported aliases, and observable effect order;
- initialization, ownership, cleanup, lifetimes, and failure paths; and
- relevant exceptions, faults, boundaries, overflows, and proven bugs.

Do not require invented pointers into future callee-owned stack storage.
Different private stack layouts alone do not prove a behavior difference.
Use instruction addresses for important conclusions.
Describe a distinguishing input or path for a suspected gap when possible.

Prefer the natural source owner.
Do not add duplicate implementations, wrappers, function fragments, inline assembly, copied machine code, or fake compiler-steering helpers.
You may repair required declarations, layouts, callers, or helpers.
Keep all supporting changes tied to the target.

## Workspace

Use only files and tools in this workspace.
Do not use the network or inspect the main repository, other workspaces, or past sessions.
Use only the explicitly authorized compiler and SDK paths outside this workspace.

Run each repository tool with `--help` before first use.
Compile the completed target in its natural translation unit with the assigned command.
Keep generated files under `build/`.
Do not commit compiler output.
Preserve unrelated files and line endings.

## Delivery

The final commit message is the complete report. Do not create `report.md`.
Include:

- the result and important source choices;
- original evidence and instruction addresses checked;
- all supporting paths changed and why;
- the exact compile command and result; and
- open questions or unchecked behavior.

A reconstruction needs no fixed trailer.
A review final commit must end with exactly these trailers:

```text
Behavior-Recovery-Choice: delivery-01
Behavior-Recovery-Verdict: PERFECT
```

Use the actual delivery name from `assignment.json`.
Use verdict `REVISED` when you changed its compiler-facing source.
Explain every revision in the message body.

Commit all intended source changes and leave the repository clean.
The committed state and commit messages are the deliverable.
Return the final commit ID, compile result, and blockers.
Stop editing after delivery unless the orchestrator continues the assignment.
