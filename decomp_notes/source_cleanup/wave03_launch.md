# Cleanup wave 03 launch queue

The user authorized ten more owners when ready.
The assignment reserves 80 additional modules, separate from waves 01 and 02.
The reference inventory lists 2,400 functions in these modules. This is not validation coverage.

- Common preparation base: `76037279ee11dde077bb7d55aeb46b518b2bb27c`.
- Assignments: [wave03_assignments.md](wave03_assignments.md).
- Preparation: `build/source-cleanup-20260915/prepare_wave03.py`.
- Individual launch requests: `build/source-cleanup-20260915/wave03-queue/owner-NN.json`.
- Preparation job: `bg-38`.
- Worktrees: slots 109–198, including ten owner trees and 80 worker trees.
- Disk reserve: at least 40 GiB. Preparation stops below that limit without deleting existing work.

## Capacity rule

Root must inspect active owners before each launch. Count correction runs as active owners.
Keep at most ten active owners. Each can run up to eight source workers.
Preparation does not reserve managed execution slots or start agents.
Pause new launches when completed groups need root review.

Launch in owner-number order as capacity and root review permit.
Use the individual JSON request with `subagent_start` only after that owner's nine trees are ready.
Do not rerun preparation against active trees. Do not launch an owner twice.
Record each managed ID here after launch.

The first capacity check found three running owners and six completed wave 02 groups awaiting root intake.
Owner 13's request is ready, but root paused launches to clear that review queue first.
No wave 03 owner has launched yet. The preparation job continues independently.

## Queue

| Owner | Group | State | Managed ID |
| --- | --- | --- | --- |
| 13 | AI core and build support | Preparing | Not launched |
| 14 | Tribe AI and game information | Preparing | Not launched |
| 15 | Active objects and remaining actions | Preparing | Not launched |
| 16 | Maps and visibility | Preparing | Not launched |
| 17 | Core panels | Preparing | Not launched |
| 18 | Panel and dialog support | Preparing | Not launched |
| 19 | Tribe panels | Preparing | Not launched |
| 20 | Audio and image support | Preparing | Not launched |
| 21 | Game and editor screens | Preparing | Not launched |
| 22 | Text and file support | Preparing | Not launched |

No compilation, builds, matching, audits, tests, or games ran during assignment and preparation.
The same full-diff review and unchanged-output requirements remain active.
