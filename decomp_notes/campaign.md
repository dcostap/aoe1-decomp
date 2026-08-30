# campaign.cpp source reunification

## Context gate

- **PDB source:** `C:\\msdev\\work\\age1_x1\\campaign.cpp`.
- **Source order:** `00423230` lines 22-54, `00423330` lines 65-90,
  `00423480` lines 94-100, `004234B0` lines 104-169, `00423690` lines
  175-193, `00423710` lines 198-200, `00423720` lines 205-207,
  `00423730` lines 212-223, and `004237A0` lines 227-229.
- **Class owner:** all nine normal owners are members of `RGE_Campaign`.
- **Address sequence:** the sequence above is the PDB packet sequence and is
  also the source definition order in `src/campaign.cpp`.
- **Type evidence:** the inventory records a `0x20C` `RGE_Campaign`, a
  `0x108` `RGE_Campaign_Header`, and a `0x208` `RGE_Scenario_Offset`.
  The source header records the named fields and uses natural alignment.
- **Generated owners:** the packet reports no nearby compiler-generated
  entries.

The packet command was:

A retired translation-unit planning pass recorded the initial migration data.

It reports nine normal owners, 1325 normal bytes, eight matching-bank owners,
one accepted-drift owner, and eight registered exact owners.

## Reunification

`src/campaign.cpp` now owns all nine handwritten definitions in PDB source
order. `include/campaign.h` owns the campaign records. The canonical
`src/campaign.cpp` privately includes the canonical `include/basegame.h` and
`include/rge_base_game_global.h` surfaces. `RGE_Base_Game::prog_info` is at
`+0x0C`. The public campaign header contains only its owned records.
`src/campaign.cpp` privately includes the canonical `include/main.h` after
`campaign.h`; this completes the period `RGE_Prog_Info` definition without
adding it to `tribegam.h` or `campaign.h`. The struct is `0x1238` bytes, with
`scenario_dir` at `+0xC17` and `campaign_dir` at `+0xD1C`.
The source uses `campaign_dir`, not a foreign gap or local layout. It uses the
direct declarations from `include/mystring.h` for `getstring`. It has no
context macros, manual vtables, inline assembly, raw byte cursor, or fallback
declaration machinery.

The source preserves the established direct CRT and executable helper targets.
`create_file` keeps the shipped scenario-entry update order and the 300-byte
local path buffer. `scenario_info` keeps the unsigned allocation count and
positive-count loop, but uses typed scenario indexing instead of the former
manual stride expression.

## Status ledger

Before migration, the packet reported these eight registered exact owners:

- `00423230`, `00423330`, `00423480`, `004234B0`, `00423690`, `00423710`,
  `00423720`, and `004237A0`.

`00423730` was in `src/accepted_drift` and had no registered exact result.
After migration, `config/functions/src/campaign.cpp.json` records the same eight
owners as `matching` and records `00423730` as `scratch`. No status was
promoted by this structural move. No generated entry was present before or
after.

The former wrapper, module context header, and nine source-bank fragments were
removed. The removed files were:

- `src/campaign_tu.cpp`
- `include/campaign_context.h`
- `src/matching/00423230_RGE_Campaign.cpp`
- `src/matching/00423330_RGE_Campaign.cpp`
- `src/matching/00423480_RGE_Campaign.cpp`
- `src/matching/004234B0_create_file.cpp`
- `src/matching/00423690_open_scenario.cpp`
- `src/matching/00423710_get_name.cpp`
- `src/matching/00423720_scenario_number.cpp`
- `src/accepted_drift/00423730_scenario_info.cpp`
- `src/matching/004237A0_get_scenario_name.cpp`

## Validation and regressions

The worker generated the packet and ran the grouped candidate from
`build/campaign_recheck.json`. The candidate uses the natural
`src/campaign.cpp` source and `config/flags/default.rsp`.
The eight exact owners (`00423230`, `00423330`, `00423480`, `004234B0`,
`00423690`, `00423710`, `00423720`, and `004237A0`) all report `MATCH`,
`0.0000%`, correct owner symbols, boundaries, relocations, and direct targets.
This proves that the canonical `prog_info` and `campaign_dir` access now close
for the matching owners.

The candidate also checks `00423730` as a scratch observed owner. It remains a
94-byte mismatch (rebuilt size 98 versus original size 100), with matching
ownership and no relocation or boundary errors. The fresh standalone check
reports a high-severity control-flow difference and 0% exact-block coverage.
This is broad structural drift, not accepted drift.

The first compile exposed two canonical ABI requirements: `basegame.h` needs
the struct tag and `__stdcall` on `wnd_proc`, and the period `calloc`
declaration uses unsigned arguments. The final candidate compiles with those
canonical declarations. No context header or foreign layout is used.

Historical evidence for `00423730` remains unresolved. Its former note records
an accepted-drift result with a code-size overshoot in one early form and a
remaining LEA-byte difference in the later form. The current natural typed
index form is now scratch after the fresh structural check.

## ABI requests

`RGE_Campaign` has different incomplete declarations in `include/gameinfo.h`
and `include/scr_cam.h`. Do not repair those files in this worker. Proposed
shared declaration: the reviewed `RGE_Campaign` surface in `include/campaign.h`,
including the `0x20C` record, both constructors, the destructor, and all seven
helpers. Affected modules are `campaign`, `gameinfo`, and `scr_cam` in the Terra
shard. After coordinator approval, rebuild all three translation units and
all registered groups that consume `RGE_Campaign`; rerun ownership, boundary,
relocation, and direct-target checks. This remains a blocking external fanout
request for full-module integration, but it does not block this source move.

The module also needs one shared owner for `campaign_version`, currently used
as `extern long campaign_version`. Proposed declaration is the existing
`extern long` surface. The coordinator should locate or assign its global
owner, then rebuild `campaign` and the constructor callers. This is a
non-blocking declaration-ownership request for this migration.
