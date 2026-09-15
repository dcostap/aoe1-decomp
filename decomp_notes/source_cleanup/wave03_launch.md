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
The user later directed root to launch this wave while reviewing completed groups.
This direction removes the review pause for this assigned wave, but keeps the ten-owner limit.

Launch in owner-number order as capacity and root review permit.
Use the individual JSON request with `subagent_start` only after that owner's nine trees are ready.
Do not rerun preparation against active trees. Do not launch an owner twice.
Record each managed ID here after launch.

The first capacity check found three running owners and six completed wave 02 groups awaiting root intake.
Owner 13's request is ready, but root paused launches to clear that review queue first.
At that check, no wave 03 owner had launched.
Preparation has now completed successfully for all 90 clean worktrees and ten individual launch requests.
Available disk space afterward was approximately 85 GiB.

The next capacity check found only owner 11 active. Owner 05 had completed its correction run.
Root then launched owners 13–21 under the user's revised direction.
Owner 22 waits for an owner slot. Complete root reviews and final validation remain required.

## Queue

| Owner | Group | State | Managed ID |
| --- | --- | --- | --- |
| 13 | AI core and build support | Launched | `sa-d7a5e0d9` |
| 14 | Tribe AI and game information | Launched | `sa-6c7a8ac3` |
| 15 | Active objects and remaining actions | Launched | `sa-0f2c499a` |
| 16 | Maps and visibility | Launched | `sa-78f8ad3d` |
| 17 | Core panels | Launched | `sa-70058a7e` |
| 18 | Panel and dialog support | Launched | `sa-0acc3514` |
| 19 | Tribe panels | Launched | `sa-cdd1c097` |
| 20 | Audio and image support | Launched | `sa-704a4bba` |
| 21 | Game and editor screens | Launched | `sa-2b87499f` |
| 22 | Text and file support | Ready; capacity wait | Not launched |

No compilation, builds, matching, audits, tests, or games ran during assignment and preparation.
The same full-diff review and unchanged-output requirements remain active.
