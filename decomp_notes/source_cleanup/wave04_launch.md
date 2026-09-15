# Cleanup wave 04 launches

The user authorized more owners for uncovered files and up to three concurrent delegated reviewers.
Root retains integration responsibility. Keep at most ten editing owners, including correction runs.

- Assignment: `decomp_notes/source_cleanup/wave04_assignments.md`.
- Preparation base: `c22ba4258c45b1178181e185d60a3b09a1add617`.
- Preparation tool: `build/source-cleanup-20260915/prepare_wave04.py`.
- Preparation job: `bg-48`, completed successfully.
- Prepared slots: 199–252, six owners and 48 workers.
- Second preparation job: `bg-49`, completed successfully for Owners 27–28.
- Existing trees and historical outputs were not reset or deleted.
- Preparation checked the 40 GiB disk reserve before each new tree.

| Owner | Group | State | Managed ID |
| --- | --- | --- | --- |
| 23 | Drawing and sprite support | Launched | `sa-40c80a1c` |
| 24 | Paths and views | Launched | `sa-161407e1` |
| 25 | Players and commands | Launched | `sa-0dfcbbfb` |
| 26 | Worlds and scenarios | Prepared; waiting for capacity and RAM headroom | Not launched |
| 27 | Game core and victory | Prepared; waiting for capacity and RAM headroom | Not launched |
| 28 | Resources and timelines | Prepared; waiting for capacity and RAM headroom | Not launched |

Root checked active owner capacity before each launch.
Owner 22 also launched under this authorization; see `wave03_launch.md`.
The new requests explicitly forbid validation commands and deletion of incident evidence.
No compilation, builds, matching checks, audits, tests, or games ran during this preparation.
