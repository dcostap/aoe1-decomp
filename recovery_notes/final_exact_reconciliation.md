# Final exact reconciliation

## Evidence

This reconciliation uses `build/audits/pre_final_observed/report.json`.

The report compiled all 221 configured groups.
It contains 5,061 included normal-function rows.

Before this change, the report showed:

- 3,652 registered owner matches.
- 39 registered owner regressions.
- 451 grouped matches without registration.
- 3,900 current `matching` rows.
- 73 nonexact current `matching` rows.

The report is grouped compiler evidence.
Every promoted row passed `MATCH`, ownership, boundary, relocation, and symbol checks.

## Policy

Rows with category `registered_owner_match` or `grouped_match_not_registered` become `matching`.
Each row is registered in its current translation-unit group.

Every current `matching` row in another category becomes `scratch`.
Its owner registration is removed.

All other nonexact statuses remain unchanged.
Note paths remain unchanged.
String and object entry styles remain unchanged.

New owners use the report's `expected_symbol` selector.
A removed selector is deleted only when that VA had an explicit selector.

No source code changed in this reconciliation.

## Result

The change promoted 451 exact grouped rows.
It removed 39 nonexact registered owners.

Source-module status transitions were:

- 267 `scratch` to `matching`.
- 9 `accepted_drift` to `matching`.
- 73 `matching` to `scratch`.

The final registry contains 4,103 owners from the preflight report.
A fresh focused audit proved one additional exact owner, `0041E7A0`.
Its emitted symbol is `?rge_base_game_wnd_proc@@YGJPAXIIJ@Z`.
The updated registry target is 4,104 owners and exact grouped matches.
The final report must contain zero registered owner regressions.
It must contain no unregistered `matching`-status rows.

Fresh grouped `MATCH` results supersede prior accepted-drift status statements
for these VAs: `0044B2B0`, `005059A0`, `004BE4B0`, `004421F0`, and `0046B680`.
They also supersede `0053C680`, `004D2880`, `0050D7E0`, and `004459A0`.
Each row passed ownership, boundary, relocation, and symbol checks.

The preflight lacked the copied FPO evidence and an explicit selector for
`0041E7A0`. It used the stale inferred selector
`?rge_base_game_wnd_proc@@YGKIIII@Z` and reported a missing grouped symbol.
The focused audit used the emitted selector above and reported `MATCH`.
