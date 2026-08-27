# Map and World header checkpoint

## Evidence checkpoint

Terra 4 commits `54d6014c7` and `c4b894f45` converged the current Map and World declarations.
They removed `map_context.h` and proved the real RMM terrain overload:

```cpp
void RGE_Map::set_terrain(
    RGE_Player*, RGE_Game_World*, short, short, short, short,
    unsigned char, unsigned char, int);
```

A grouped Map, World, rmm_terr, and rmm_obj fanout compiled all four groups.

## Nonexact results

Do not treat these registered owners as exact after that checkpoint:

- rmm_terr `00489030`: 2086 positional differences;
- rmm_obj `00486180`: 1 positional difference;
- World `00541380`: 3 positional differences;
- World `00545C00`: 157 positional differences;
- World `005462D0`: 965 positional differences and one boundary escape.

Map owner `00459060` was missing from the grouped output.

## Publication block

The checkpoint headers still define classes owned by other modules.
They are evidence, not canonical public headers.

Terra 4 must publish clean header-only Map and World declarations.
The headers must consume each external owner instead of copying it.
