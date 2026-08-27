# World.cpp RGE_Base_Game call contract

Audit scope: direct calls from the original `World.cpp` compiland.
The original PDB names every target as a public, nonvirtual `RGE_Base_Game`
member in `basegame.cpp`. The original call sites use direct relative `call`
instructions.

Evidence sources:

- `inventory/pdb/function_source_map.csv`
- `inventory/all_functions.csv`
- `orig/aoe1_ghidra_assembly_listing.txt`
- `inventory/functions/0054/005420F0_load_world.txt`
- `inventory/functions/0054/00542750_new_game.txt`
- `inventory/functions/0054/00542ED0_update.txt`
- `inventory/functions/0054/005433C0_check_game_state.txt`
- `inventory/functions/0054/00543540_save.txt`
- `inventory/functions/0054/00543A00_save_scenario.txt`
- `inventory/functions/0054/00544090_load_scenario.txt`
- `inventory/functions/0054/00545CB0_difficultyLevel.txt`

## Proven declarations

All methods use `__thiscall`. `int`, `long`, `unsigned long`, and `float` have
32-bit storage in this target. The PDB decoration is part of each target
identity. `QBE` proves a const member. `QAE` proves a non-const member.

```cpp
int multiplayerGame() const;
int randomGame() const;
int campaignGame() const;
int singlePlayerGame() const;
int playerTeam(int);
int playerID(int);
int difficulty();
int campaign_open_scenario();
float get_game_speed();
unsigned char check_prog_argument(char*);
void write_scenario_header(int);
void get_campaign_info(long&, long&, long&);
unsigned char set_campaign_info(long, long, long);
void set_campaign_win();
void add_to_timing(int, unsigned long);
```

`get_campaign_info` uses three C++ references. Its PDB target is
`?get_campaign_info@RGE_Base_Game@@QAEXAAJ00@Z`; the assembly shows three
4-byte output addresses and `ret 0xc`. Do not declare pointer parameters.

`check_prog_argument` uses a mutable `char*`, not `const char*`. Its PDB target
is `?check_prog_argument@RGE_Base_Game@@QAEEPAD@Z`; the body reads one 4-byte
argument and returns its result in `AL`.

`add_to_timing` uses an `int` index and an `unsigned long` value. Its PDB target
is `?add_to_timing@RGE_Base_Game@@QAEXHK@Z`; both arguments are 4 bytes and the
callee uses `ret 0x8`.

The four mode queries are const. Their PDB targets are:

- `004223B0`: `?randomGame@RGE_Base_Game@@QBEHXZ`
- `004223C0`: `?campaignGame@RGE_Base_Game@@QBEHXZ`
- `004223F0`: `?singlePlayerGame@RGE_Base_Game@@QBEHXZ`
- `00422400`: `?multiplayerGame@RGE_Base_Game@@QBEHXZ`

`difficulty`, `playerTeam`, `playerID`, `campaign_open_scenario`,
`get_game_speed`, and the remaining listed methods are non-const. Their PDB
targets use `QAE`.

## World direct targets

These are the direct `World.cpp` calls, with the target VA proven by the raw
`E8` call bytes.

| World call site | Target |
|---|---|
| `0054232C` | `004223F0 singlePlayerGame` |
| `0054233B` | `00422EB0 get_game_speed` |
| `005427C1` | `00422400 multiplayerGame` |
| `0054293C`, `00542977`, `00542A2D` | `00422660 playerTeam` |
| `00542987`, `00542995`, `00542A56`, `00542A64` | `00422D90 playerID` |
| `005429D9` | `004223B0 randomGame` |
| `005429EC` | `004223C0 campaignGame` |
| `00542AB6` | `004223F0 singlePlayerGame` |
| `00542AC5` | `00422EB0 get_game_speed` |
| `00542F2C` | `0041C830 add_to_timing` |
| `005434F7` | `0041CF70 set_campaign_info` |
| `00543519` | `0041CFC0 set_campaign_win` |
| `00543756` | `00422640 difficulty` |
| `00543ACD` | `00422CC0 check_prog_argument` |
| `00543AF4` | `0041CDA0 write_scenario_header` |
| `005440A9` | `00422910 campaign_open_scenario` |
| `00544222` | `0041CF30 get_campaign_info` |
| `00545CC2` | `00422640 difficulty` |

The `00542F2C` call pushes the elapsed `debug_timeGetTime` result, then the
index `0xe`. The target contract therefore needs the `unsigned long` second
argument. The `00544222` call pushes addresses of the three world campaign
values. This proves the pointer-shaped machine ABI, while the PDB decoration
proves the source form is three references.

`0041CFC0` and `00422910` are direct World targets even though each target
ends with a tail jump to its `RGE_Game_Info` helper. Do not replace either
World call with a virtual call or with the helper target.

## Header ownership proposal

Add only these declarations to the public `RGE_Base_Game` class in
`include/basegame.h`. Keep them as nonvirtual members. Do not add local
World declarations, pointer substitutes, const substitutes, aliases, or
free-function shims. Keep the existing reviewed global declaration for
`rge_base_game` in its global header.
