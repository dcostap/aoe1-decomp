# `taimdmd.cpp` module recovery

- PDB source: `C:\\msdev\\work\\age1_x1\\taimdmd.cpp`.
- Source: `src/taimdmd.cpp`.
- Header: `include/taimdmd.h`.
- Flags: `config/flags/004E4800_TribeMainDecisionAIModule.rsp`.
- Normal owners: 19.
- Address range: `004E4800` to `004E6870`.

## Module migration

The source follows the PDB owner order at lines 89 through 1181. It has one
compiler-facing source owner and one module-local header. The old wrapper,
fragment includes, context macro, fallback declarations, and per-function
source owners were removed.

The module manifest records all 19 normal owners. It has 15 matching and four
scratch owners. The compiler-generated scalar
deleting destructor at `004E4B60` remains outside the normal owner manifest.

## Context evidence

The original PDB module is `taimdmd.cpp`. Its source order is the address
sequence listed in the generated packet. The class owner is
`TribeMainDecisionAIModule`, with the two constructors and destructor before
the decision methods, update path, save path, and command helpers. The packet,
FPO evidence, and exact neighboring owners provide the ownership and boundary
anchors. The module header keeps the reviewed embedded module offsets and the
`0x125C8` `TribeMainDecisionAIModule` layout.

## Ownership hold

Do not submit the rejected owner-composition packet. Exact function checks do
not prove its public header ownership.

PDB layout evidence gives `MainDecisionAIModule` size `0x104` and
`TribeMainDecisionAIModule` size `0x125C8`. The construction child begins at
`+0x6C4`. `TribeConstructionAIModule::md` is at `+0x314`. These fields require
the canonical owners below. They do not permit local replacement layouts.

`MainDecisionAIModule` belongs to `aimdmod.cpp`. `BuildAIModule` belongs to
`aibldmod.cpp`. `TribeBuildAIModule` belongs to `taibldmd.cpp`.
`TribeConstructionAIModule` belongs to `taiconmd.cpp`. `TribeInformationAIModule`
belongs to `taiinfmd.cpp`. Resource, strategy, tactical, and trade AI types
belong to `tairesmd.cpp`, `taistrmd.cpp`, `taitacmd.cpp`, and `aitrdmod.cpp`.

Use `aimdmod.h`, `aibldmod.h`, `taibldmd.h`, `aiconmod.h`, `taiinfmd.h`,
`tairesmd.h`, `taistrmd.h`, `taitacmd.h`, and `aitrdmod.h` for those types.

Engine ABI views also remain blocked. Use `world.h`, `player.h`, `tplayer.h`,
`m_s_obj.h`, `stat_obj.h`, `victory.h`, and `Command.h`. The rejected header's
`RGE_Game_World` view was `0x100`; the canonical world is `0x104`. Its local
world, player, victory, map, static-object, and DecisionScore carriers cannot
remain.

`004E6870 currentScore` reads canonical objects. It loads `this->player`, then
`player->world`, checks `world->player_num`, loads `world->players[index]`,
and calls `player->victory_conditions->get_victory_points()`. The PDB range
and the direct target at `00533480` prove this sequence. The source now uses
that path. It has no DecisionScore carrier.

`taimdmd.h` consumes the canonical Main Decision, Diplomacy, Emotional, and
Trade providers and the canonical Tribe Construction and Resource providers.
`taimdmd.cpp` privately consumes canonical Player, World,
Victory, map, static-object, Tribe Game, Tribe World, and Tribe Command types.
The remaining embedded Tribe Build, Information, Strategy, and Tactical
declarations stay local only until their owner headers
are complete. Do not use their byte carriers as a provider surface.

## Exactness regressions

Migration changes the complete source context. Prior isolated exact results
are not claims about the merged source. The four scratch owners remain
honest and are not promoted:

- `004E4800` constructor: prior standalone result had 50 differing bytes.
- `004E4B80` load constructor: prior standalone result had 15 differing bytes.
- `004E5050` update: prior standalone result had 2688 differing bytes.
- `004E60D0` detask: prior standalone result had two differing bytes and one
  direct-target mismatch. The current focused merged check reports `MATCH`,
  but the owner remains scratch until the parent reviews the status move.

The prior grouped validation also showed context-sensitive regressions for
`004E4EC0` and `004E6160`. Focused checks of the merged source restore exact
213-byte and 236-byte results for those owners. Shared ABI questions from the
prior grouped validation remain outside this module migration.

The other 13 matching owners also pass focused checks with `MATCH` and
`0.0000%` positional difference. Their checks report the expected owner
symbols, boundaries, relocations, and direct targets.

No inline assembly, byte forcing, synthetic owner, or accepted drift was
added.

## Prior recovery evidence

- `004E4800`: A natural constructor with named embedded modules and the
  `MainDecisionAIModule` base call aligned all 46 direct targets. The remaining
  difference is the derived vptr store location. `novtable` probes worsened the
  result and were removed.
- `004E4B80`: Renaming setup calls to the proven `setMainDecisionAI` surface
  removed nine relocation failures. The exact-class destructor declaration was
  tested with `novtable` and the natural declaration was retained.
- `004E5050`: Named subobjects, inherited player ownership, ordered tribute
  tails, and the natural ManagedArray model were tested. The best source has
  the original call count and broad control-flow shape, but retains register,
  frame, and local-home drift. No raw offset overlay or forced scope remains.
- `004E60D0`: The natural tactical delegation now matches in the merged source
  context. The previous reduced-context result had a wrong direct target.
- `004E6160`: The natural bounded ManagedArray copy loop restores the original
  frame lifetime and all five ordered calls. Explicit allocation was replaced
  with `new[]` and `delete[]`.
- `004E6580`: The named random result is required for the exact standalone
  emission. A single expression and register probes were tested before the
  current natural declaration was retained.
- `004E6870`: The canonical field path emits `MATCH`, `0.0000%`, with matching
  ownership and zero relocation and boundary errors. It is registered exact.
