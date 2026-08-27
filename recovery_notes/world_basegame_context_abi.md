# World context BaseGame ABI audit

## Scope

This note records the stale `RGE_Base_Game` surfaces in these migration
scaffolds:

- `include/world_context.h:334-364`;
- `src/world_phase2_context.h:405-435`;
- `src/tworld_phase2_context.h:44-93` and `:654`.

No context header or source body was changed. These headers are evidence only.
The canonical owner is `include/basegame.h`. The reviewed global is
`include/rge_base_game_global.h`.

The canonical class size is `0xA24`. Its nested
`RGE_Base_Game::RGE_Game_Options` size is `0xA8`.

## Common wrong declarations

Both World contexts have the same wrong declarations.
The tworld context has these errors too.

| Scaffold declaration | Canonical declaration in `basegame.h` | Canonical symbol | Scaffold symbol or effect |
| --- | --- | --- | --- |
| `virtual long wnd_proc(void*, unsigned int, unsigned int, long)` | `virtual long __stdcall wnd_proc(void*, unsigned int, unsigned int, long)` | `?wnd_proc@RGE_Base_Game@@UAGJPAXIIJ@Z` | Default member convention selects `?wnd_proc@RGE_Base_Game@@UAEJPAXIIJ@Z`. |
| `void add_to_timing(int, int)` | `void add_to_timing(int, unsigned long)` | `?add_to_timing@RGE_Base_Game@@QAEXHK@Z` | `int` selects `?add_to_timing@RGE_Base_Game@@QAEXHH@Z`. |
| `int multiplayerGame()` | `int multiplayerGame() const` | `?multiplayerGame@RGE_Base_Game@@QBEHXZ` | Missing `const` selects `?multiplayerGame@RGE_Base_Game@@QAEHXZ`. |
| `int randomGame()` | `int randomGame() const` | `?randomGame@RGE_Base_Game@@QBEHXZ` | Missing `const` selects `?randomGame@RGE_Base_Game@@QAEHXZ`. |
| `int campaignGame()` | `int campaignGame() const` | `?campaignGame@RGE_Base_Game@@QBEHXZ` | Missing `const` selects `?campaignGame@RGE_Base_Game@@QAEHXZ`. |
| `int singlePlayerGame()` | `int singlePlayerGame() const` | `?singlePlayerGame@RGE_Base_Game@@QBEHXZ` | Missing `const` selects `?singlePlayerGame@RGE_Base_Game@@QAEHXZ`. |
| `void get_campaign_info(long*, long*, long*)` | `void get_campaign_info(long&, long&, long&)` | `?get_campaign_info@RGE_Base_Game@@QAEXAAJ00@Z` | Pointer parameters select `?get_campaign_info@RGE_Base_Game@@QAEXPAJ00@Z`. |

These types have the same 32-bit argument width in several cases.
They still select different decorated symbols.

The common field prefix is also wrong:

| Scaffold field and offset | Canonical field and offset |
| --- | --- |
| `char gap_08[4]` at `+0x08` | `RGE_Scenario_File_Info* scenario_info` at `+0x08` |
| `RGE_Prog_Info* save_prog_info` at `+0x0C` | `RGE_Prog_Info* prog_info` at `+0x0C` |
| `RGE_Prog_Info* prog_info` at `+0x10` | `void* prog_window` at `+0x10` |

The scaffold stops after `+0x10`. The canonical class continues through
`+0xA24`. `save_prog_info` is not a canonical member. The World save callers
therefore use a wrong name that happens to read the canonical `prog_info` slot.

`world_context.h` also stops its virtual surface after the three `get_string`
overloads. It omits `get_string2`, both panel getters, and all later virtuals.
`world_phase2_context.h` declares `get_string2` and both panel getters, but omits
the virtuals from `new_scenario_header` through `set_interface_messages`.
The early slot numbers remain usable only for the declarations that are present.
The omitted tail is not a canonical class surface.

## `world_context.h`

In addition to the common errors, this context has no `get_string2`, panel
getter, scenario factory, notification, or later BaseGame declaration. Its
`RGE_Base_Game` object is only a short prefix. The first pointer slots have the
right width, but the names and ownership are wrong as shown above.

The following declarations are correct in type, but only as local references to
the canonical member functions:

```cpp
unsigned char set_campaign_info(long, long, long);
void set_campaign_win();
int difficulty();
unsigned char check_prog_argument(char*);
void write_scenario_header(int);
float get_game_speed();
int playerTeam(int);
int playerID(int);
int campaign_open_scenario();
```

Their canonical symbols are, respectively,

```text
?set_campaign_info@RGE_Base_Game@@QAEEJJJ@Z
?set_campaign_win@RGE_Base_Game@@QAEXXZ
?difficulty@RGE_Base_Game@@QAEHXZ
?check_prog_argument@RGE_Base_Game@@QAEEPAD@Z
?write_scenario_header@RGE_Base_Game@@QAEXH@Z
?get_game_speed@RGE_Base_Game@@QAEMXZ
?playerTeam@RGE_Base_Game@@QAEHH@Z
?playerID@RGE_Base_Game@@QAEHH@Z
?campaign_open_scenario@RGE_Base_Game@@QAEHXZ
```

The correct-looking list does not make the enclosing class canonical.

## `world_phase2_context.h`

This context has the common errors. Its `check_prog_argument(char*)` and
`get_string2`, `get_view_panel`, and `get_map_panel` declarations have the
canonical type and slot order. The following direct helpers still have the
common wrong forms:

- `add_to_timing(int, int)`;
- non-`const` `multiplayerGame`, `randomGame`, `campaignGame`, and
  `singlePlayerGame`;
- pointer-form `get_campaign_info`.

It also carries the wrong `scenario_info`, `prog_info`, and `save_prog_info`
field surface. The save callers use `save_prog_info` at `+0x0C`; the canonical
source must use `prog_info` at that offset.

## `tworld_phase2_context.h`

### Virtual declarations

The first three `get_string` declarations have the right individual types but
the wrong order. This changes the vtable slots:

| Context slot | Context declaration | Canonical slot | Canonical declaration and symbol |
| ---: | --- | ---: | --- |
| 7 | `get_string(long)` | 7 | `get_string(int, long, char*, int)` — `?get_string@RGE_Base_Game@@UAEPADHJJPADH@Z` |
| 8 | `get_string(long, char*, int)` | 8 | `get_string(long, char*, int)` — `?get_string@RGE_Base_Game@@UAEPADJPADH@Z` |
| 9 | `get_string(int, long, char*, int)` | 9 | `get_string(long)` — `?get_string@RGE_Base_Game@@UAEPADJ@Z` |

`get_string2`, `get_view_panel`, and `get_map_panel` then have the canonical
individual types and slot positions.

The scenario factory group is also wrong:

| Context declaration and slot | Canonical declaration and slot | Canonical symbol |
| --- | --- | --- |
| slot 13: `void* new_scenario_header(int)` | slot 13: `RGE_Scenario_Header* new_scenario_header(RGE_Scenario*)` | `?new_scenario_header@RGE_Base_Game@@UAEPAVRGE_Scenario_Header@@PAVRGE_Scenario@@@Z` |
| slot 14: `void* new_scenario_header(void*)` | slot 14: `RGE_Scenario_Header* new_scenario_header(int)` | `?new_scenario_header@RGE_Base_Game@@UAEPAVRGE_Scenario_Header@@H@Z` |
| slot 15: `void* new_scenario_info(int)` | slot 15: `RGE_Scenario* new_scenario_info(int)` | `?new_scenario_info@RGE_Base_Game@@UAEPAVRGE_Scenario@@H@Z` |
| slot 16: `void notification(int, int, int, int, int)` | slot 16: `void notification(int, long, long, long, long)` | `?notification@RGE_Base_Game@@UAEXHJJJJ@Z` |

The context forms would select `?new_scenario_header@RGE_Base_Game@@UAEPAXH@Z`,
`?new_scenario_header@RGE_Base_Game@@UAEPAXPAX@Z`,
`?new_scenario_info@RGE_Base_Game@@UAEPAXH@Z`, and
`?notification@RGE_Base_Game@@UAEXHHHHH@Z`.

The context omits every canonical virtual from `reset_comm` through
`set_interface_messages`.

### Direct BaseGame helpers

These context declarations are wrong against the canonical ABI:

| Context declaration | Canonical declaration | Canonical symbol |
| --- | --- | --- |
| `int scenarioGame()` | `int scenarioGame() const` | `?scenarioGame@RGE_Base_Game@@QBEHXZ` |
| `int randomGame()` | `int randomGame() const` | `?randomGame@RGE_Base_Game@@QBEHXZ` |
| `int campaignGame()` | `int campaignGame() const` | `?campaignGame@RGE_Base_Game@@QBEHXZ` |
| `int multiplayerGame()` | `int multiplayerGame() const` | `?multiplayerGame@RGE_Base_Game@@QBEHXZ` |
| `int allowCheatCodes()` | `int allowCheatCodes() const` | `?allowCheatCodes@RGE_Base_Game@@QBEHXZ` |
| `int fullVisibility()` | `int fullVisibility() const` | `?fullVisibility@RGE_Base_Game@@QBEHXZ` |
| `unsigned char check_prog_argument(const char*)` | `unsigned char check_prog_argument(char*)` | `?check_prog_argument@RGE_Base_Game@@QAEEPAD@Z` |
| `void reset_countdown_timer(int)` | `void reset_countdown_timer(long)` | `?reset_countdown_timer@RGE_Base_Game@@QAEXJ@Z` |
| `void set_map_visible(int)` | `void set_map_visible(unsigned char)` | `?set_map_visible@RGE_Base_Game@@QAEXE@Z` |
| `void set_map_fog(int)` | `void set_map_fog(unsigned char)` | `?set_map_fog@RGE_Base_Game@@QAEXE@Z` |

The current checked-in `basegame.h` does not yet publish
`scenarioGame`, `allowCheatCodes`, `fullVisibility`, `pathFinding`,
`mpPathFinding`, `set_map_visible`, or `set_map_fog`. The original PDB and
symbols still prove the forms above. `pathFinding()` and `mpPathFinding()`
have the canonical non-`const` `unsigned char` return surface and symbols
`?pathFinding@RGE_Base_Game@@QAEEXZ` and
`?mpPathFinding@RGE_Base_Game@@QAEEXZ`; they are pending publication, not a
reason to keep this context as an owner.

`victoryType`, `mapSize`, `mapType`, `victoryAmount`, `randomizePositions`,
`fullTechTree`, `resourceLevel`, `startingAge`, `deathMatch`, `popLimit`,
`allowTrading`, and `longCombat` do not belong to `RGE_Base_Game`. They belong
to `TRIBE_Game`. The context puts them on the wrong base class. The original
symbols prove these owners:

```text
?victoryType@TRIBE_Game@@QBE?AW4VictoryType@1@XZ
?mapSize@TRIBE_Game@@QBE?AW4MapSize@1@XZ
?mapType@TRIBE_Game@@QBE?AW4MapType@1@XZ
?victoryAmount@TRIBE_Game@@QBEHXZ
?randomizePositions@TRIBE_Game@@QAEHXZ
?fullTechTree@TRIBE_Game@@QAEHXZ
?resourceLevel@TRIBE_Game@@QAE?AW4ResourceLevel@1@XZ
?startingAge@TRIBE_Game@@QAE?AW4Age@1@XZ
?deathMatch@TRIBE_Game@@QAEEXZ
?popLimit@TRIBE_Game@@QAEEXZ
?allowTrading@TRIBE_Game@@QAEHXZ
?longCombat@TRIBE_Game@@QAEHXZ
```

The context's separate `TRIBE_Game` redeclarations also use `int` for the
enum getters and omit their `const` qualifiers. A natural TRIBE owner must
use the PDB-qualified enum and symbol forms.

### Object and global ABI

`tworld_phase2_context.h` declares no BaseGame data members. Its class is a
four-byte vptr-only shell, not the canonical `0xA24` object. Its nested
`RGE_Game_Options` is only `unsigned char data[0xA8]`; the size is right, but
its canonical named fields are missing.

It declares:

```cpp
extern TRIBE_Game* rge_base_game;
```

The reviewed declaration is:

```cpp
extern RGE_Base_Game* rge_base_game;
```

The context selects `?rge_base_game@@3PAVTRIBE_Game@@A`.
The canonical global selects `?rge_base_game@@3PAVRGE_Base_Game@@A`.

## Why exact checks can mask these errors

The checker can report `MATCH` while it masks every relocation. For example:

- `build/diff/00542ED0_update.txt` reports `Result: MATCH`, `0.0000%`, and
  `relocations safely masked 67/67`. The extracted object uses
  `?add_to_timing@RGE_Base_Game@@QAEXHH@Z`, not the canonical `...QAEXHK@Z`.
- `build/diff/00542750_new_game.txt` reports `Result: MATCH`, `0.0000%`, and
  `relocations safely masked 51/51`. Its object uses non-`const` `QAE`
  symbols for the four game-state queries. The canonical symbols use `QBE`.
- `build/diff/00543A00_save_scenario.txt` reports `Result: MATCH`, `0.0000%`,
  and `relocations safely masked 39/39` while the source uses the fake
  `save_prog_info` member and a local context declaration.

On 32-bit x86, `int`, `long`, and `unsigned long` occupy four bytes.
Pointers and references also pass one four-byte value. `const` on a nonvirtual
member changes the decorated name without changing the call instruction.
A masked relative call can therefore have identical bytes for a wrong target.

The fake field prefix has the same problem. `save_prog_info` at `+0x0C`
produces the same load as canonical `prog_info` at `+0x0C`. A checker that
compares bytes and masks relocations cannot prove field ownership. The raw
`RGE_Game_Options` array has the correct size for the same reason.

Virtual omissions can also hide. A check that calls only early slots does not
inspect the omitted tail. Virtual overloads can remain hidden when no caller
uses the affected slot. The tworld overload errors become visible only when a
call uses the moved scenario or string slot.

A valid exact result must retain relocation target identity, class ownership,
boundaries, and the canonical declarations. Do not promote these context
matches as ABI evidence.

## Why natural World must not include these contexts

Natural World must consume canonical owners. It must not include these files:

1. Each file defines a private `RGE_Base_Game` class. These definitions have
   different fields, virtual tails, overload order, and direct helper symbols.
   They cannot coexist with `include/basegame.h`.
2. `world_context.h` and `world_phase2_context.h` use the same include guard,
   `AOE1_WORLD_SCENARIO_CONTEXT_H`. Include order can silently discard one
   complete scaffold and select another.
3. The contexts copy foreign `RGE_Game_World`, `RGE_Map`, `RGE_Player`,
   `RGE_Scenario`, and other owners. Their raw gaps, unions, and compatibility
   names are local evidence, not shared ABI.
4. `tworld_phase2_context.h` changes the global `rge_base_game` type and
   declares Tribe-only helpers on `RGE_Base_Game`. It also uses a four-byte
   BaseGame shell in place of the `0xA24` object.
5. The contexts can produce exact body bytes by using matching offsets while
   still selecting wrong decorated calls or wrong owners. Including one in
   natural World would make the false result part of the source ABI.

Keep these files for bounded migration checks only. Publish the missing clean
owners, include `basegame.h` once, and remove the context dependencies before
claiming a natural World module.
