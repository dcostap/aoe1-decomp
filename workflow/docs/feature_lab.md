# Native feature maps

The feature lab creates maps through the original engine. It does not write a custom save format.
The generator is an editable script: `tools/harness/feature_lab_setup.js`.

## Open a map

Run these commands from the repository root:

```cmd
game.cmd feature-lab open
game.cmd feature-lab open --fixture config/harness/feature_lab_9_16
```

Select **Single Player > Load Game > feature_lab**.
Each command creates a private runtime. It does not change personal saves.
The visible game runs normally. It does not use the test clock or the automatic camera tour.

## Run comparisons

```cmd
game.cmd feature-lab test-all
game.cmd feature-lab test --fixture config/harness/feature_lab --runs 3
```

Feature workers run one at a time. `--jobs` set to one is allowed. Values above one are
rejected because parallel runs showed drift. This applies to `test` and
`test-all`, including each nested capture set.

`test-all` runs both civilization sets. Each set uses three originals and three rebuilt games by default.
Each set checks all 15 capture pairs. A failed case does not skip the other civilization set.

The test requires both capture equality and activity coverage. It does not hide a reconstruction difference with a tolerance.
Use `--output build/feature-lab/NEW-NAME` to select a new output directory.

For a single diagnostic capture:

```cmd
game.cmd feature-lab replay --target original --fixture config/harness/feature_lab
game.cmd feature-lab replay --target rebuilt --fixture config/harness/feature_lab
```

The default capture has 800 controlled idle turns. A shorter `--turns` value can leave activities or camera views incomplete.

## Generate a new reference

```cmd
game.cmd feature-lab generate --output build/feature-lab/new-map
game.cmd feature-lab generate --civilization-offset 8 --output build/feature-lab/new-map-9-16
game.cmd feature-lab generate --layout chaos --output build/feature-lab/new-chaos
```

Two layouts exist. `features` builds the activity lanes. `chaos` builds one stress battle.
Each layout is one setup script, and `buildFeatureMap` plus `issueFeatureOrders` are the whole contract.
The fixture records its layout in `fixture.json`.

Generation uses the repository original executable. It opens the normal editor and controls its map request.
Setup runs on the game thread. Native methods apply civilization effects, age grants, terrain, objects, and resources.
The original placement checker must accept every explicit object placement.

The generator saves the map, closes the editor, and loads the save in gameplay mode.
It submits normal commands, runs twelve world updates, and saves the active game.
The replay loads that unchanged active save. It does not run the generator against rebuilt code.

The fixture contains four files:

- `feature_lab.gmx`: the original engine's active save.
- `fixture.json`: save identity, hashes, and generator settings.
- `setup.json`: object IDs, labels, positions, and initial commands.
- `catalog.json`: master definitions read from the original players.

The manifest checks the save and both metadata files before game startup.
Publish these four files together after original-repeat qualification. Generation outputs stay under `build/`.

## Map contents

### Feature layout

Each map has eight players on a 240-by-240 map. Two maps provide civilization slots 1–8 and 9–16.
The setup applies each civilization's normal effect through the engine.
Stone, Tool, Bronze, and Iron ages each appear twice. These age grants do not count as research coverage.

Each player has the editor-visible ordinary unit and building catalog. Ships have separate water areas.
The map also has natural objects, terrain samples, and elevation changes.

Activity areas exercise:

- Berry, wood, gold, stone, and hunting work.
- Farming and fishing.
- Melee, missile, siege, and naval combat.
- Conversion and healing.
- Construction, repair, training, and research.
- Boarding, unloading, and an unloading request at a blocked shore.
- Trade cargo collection and return.

The setup supplies resources, trade goods, population room, and building allowance.
It creates ordinary catalog entries even when normal research has not unlocked them.
It does not enable strategic computer players. Unit actions still use the normal game code.

### Chaos layout

One map, `chaos-battle`, stresses collection and combat at the same time.
It has 1,444 objects and 1,316 orders.

- Eight homes sit in a ring. Each home has a town centre, 15 resource nodes, and 10 villagers.
- Each villager gathers one random node near its home.
- Each home also holds **one** unit of its own civilization and a random few enemy units, three to four of them.
  The owner unit attacks an intruder. Half the intruders attack the owner unit, and the rest raid the villagers.
- The centre square holds 1,200 combat units, 150 per civilization, placed at random positions.
  Each one is ordered at a random enemy, so the whole mass engages.
- Every player is hostile to every other player.

The generator tries random tiles until the engine placement checker accepts a position.
It uses a local generator seeded from `generator.seed`, so a regenerated map repeats.
It does not mirror civilizations. The result is meant to be uneven.

## Evidence and limits

`report.json` separates capture completion, comparisons, and feature coverage.
A worker's `passed` field means its capture completed correctly. Its `coverage.passed` field answers a separate question.
The comparison report requires both results. A started command alone does not prove its intended effect.

Coverage checks resource increases, health changes, owner changes, transport membership, completed construction, new units, and completed research.
Trade coverage requires a loaded cargo to return. Initial cargo and setup technology grants do not count as replay activity.
The report also lists observed action fields for each actor with an initial order.

The chaos layout checks a smaller set: one worker carrying for each of the five resources, battle damage, and guard movement.
It places one own-civilization unit and a random few enemy units inside each home, and orders them at each other.
It has no catalog lane, so it makes no draw claim.

The camera requests redraws after view changes. Draw observations list catalog objects that did not reach the object draw method.
A draw call is not proof that every pixel of an object was visible. Inspect the saved images and video too.

Comparisons include defined world, player, object, and action fields. They also include the complete debug RNG stream and caller identities.
Clock counts, camera requests, command receipts, terminal boundaries, and raw image samples remain exact.
The `rgb` result distinguishes changed RGB samples from timestamp-only video differences.

The separate control profile adds twenty milliseconds per idle boundary and one millisecond per debug-clock call.
It suppresses native timer messages and queued paints. It controls input polling and requests paints explicitly.
It does not change the frozen human replay profiles or their startup restrictions.

These maps are broad tests, not exhaustive proof. Catalog presence does not prove every action or every civilization-specific rule.
Most activity orders use player 1. Other civilizations mainly supply catalog and state coverage.
The chaos map is deliberately uneven: it does not mirror civilizations, and it drives every player against every other.
Strategic AI, multiplayer, campaigns, audio, cinematics, and victory conditions need separate cases.
Full hidden-state equality and observer neutrality remain unproved.

Read [the testing guide](testing.md) before reporting broader project validation.
