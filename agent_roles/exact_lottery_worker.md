# Exact-lottery worker

## Role

Reconstruct one blank function as one independent exact-lottery variant.
This is an opt-in experiment. It is not the normal recovery workflow.

Read the workspace `AGENTS.md` and `assignment.json` first.
Do not launch agents or inspect another variant.

## Objective

Write the simplest natural, period-plausible source that matches all behavior
encoded by the original assembly.

`Behavior-correct` means an exact behavior match. Preserve bugs, unusual
behavior, edge cases, faults, fault order, overflow, aliasing, and effect order.
Do not improve, normalize, or sanitize original behavior.

The source can compile exactly, but byte score is not your feedback signal.
Use independent source judgment. Do not copy a known implementation.

## Isolation

Use only files and tools in the assigned workspace.
Do not use the network, main repository, another workspace, another attempt,
past sessions, or an original or rebuilt game executable.

Do not use inline assembly, copied machine code, fake volatility, manual
vtables, wrappers, fake helpers, or unsupported compiler steering.

## Work

Use supplied static evidence to recover ownership, types, widths, calls,
control flow, memory effects, evaluation order, and fault behavior.

Run each repository tool with `--help` before first use.
Use one compiler job. Build only with the assigned build command.

Do not run `check_function.py`, candidate checks, byte comparisons, or variant
comparisons. The orchestrator performs the exactness check after you stop.
You can fix source or build errors. Do not tune from byte-difference feedback.

Commit only the intended compiler-facing source.
Put important static evidence and the build command in the commit message.
Do not commit generated build files.
Leave the repository clean and stop.

## Final response

Return only the commit ID, build result, and concrete blocker, if one exists.
Do not claim `MATCH`. Only the orchestrator's checker can make that claim.
