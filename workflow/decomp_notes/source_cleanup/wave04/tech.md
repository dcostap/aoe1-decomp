# Source cleanup: `src/tech.cpp`

## Scope

- Module: `src/tech.cpp`.
- Source owner: `src/tech.cpp`.
- Header status: `include/tech.h` was not changed.
- Base commit: `c22ba4258c45b1178181e185d60a3b09a1add617`.
- Final source commit: `87fa48bff8ba7e220ed59b3ca1e8b920594248c3`.
- Change result: source formatting only.

The cleanup moves each function opening brace to its definition line. It joins
split function signatures where the split had no source value. It changes no
tokens, types, expressions, control flow, calls, constants, field order, or
ownership behavior.

## Function inventory and PDB coverage

The original function inventories establish one contiguous body for each row.
The body ends are inclusive. The original public symbols establish the method
identity and overload. PDB module stream `0027` is `Release/tech.obj`.

The module has no procedure records. It has no procedure-scoped parameter,
local, register, or line records. Therefore, every declaration mapping below
is unresolved in the PDB. Existing source names remain unchanged because the
source, caller, type, and decorated public-symbol evidence support the method
names, but not new local names.

| VA | Original body | Source declaration | PDB declaration mapping | Prior byte status |
|---|---|---|---|---|
| `0050B840` | `0050B840-0050BB83` | `TRIBE_Tech::TRIBE_Tech(int, TRIBE_World*)` | None: parameters, locals, registers, and lines absent | Match |
| `0050BB84` | `0050BB84-0050BF27` | `TRIBE_Tech::TRIBE_Tech(char*)` | None: parameters, locals, registers, and lines absent | Match |
| `0050BF28` | `0050BF28-0050BF9B` | `TRIBE_Tech::~TRIBE_Tech()` | None: parameters, locals, registers, and lines absent | Match |
| `0050BF9C` | `0050BF9C-0050BFEC` | `TRIBE_Tech::do_tech(short, RGE_Player*)` | None: parameters, locals, registers, and lines absent | Match |
| `0050BFED` | `0050BFED-0050C2F9` | `TRIBE_Tech::save(int)` | None: parameters, locals, registers, and lines absent | Match |
| `0050C2FA` | `0050C2FA-0050C332` | `TRIBE_Tech::get_help_message(short)` | None: parameters, locals, registers, and lines absent | Match |
| `0050C333` | `0050C333-0050C36B` | `TRIBE_Tech::get_help_page(short)` | None: parameters, locals, registers, and lines absent | Match |
| `0050C36C` | `0050C36C-0050C3A4` | `TRIBE_Tech::get_hotkey(short)` | None: parameters, locals, registers, and lines absent | Match |
| `0050C3A5` | `0050C3A5-0050C4FB` | `TRIBE_Player_Tech::TRIBE_Player_Tech(int, TRIBE_Tech*, RGE_Player*, unsigned char)` | None: parameters, locals, registers, and lines absent | Match |
| `0050C4FC` | `0050C4FC-0050C561` | `TRIBE_Player_Tech::TRIBE_Player_Tech(TRIBE_Tech*, RGE_Player*, unsigned char)` | None: parameters, locals, registers, and lines absent | Match |
| `0050C562` | `0050C562-0050C58B` | `TRIBE_Player_Tech::~TRIBE_Player_Tech()` | None: parameters, locals, registers, and lines absent | Match |
| `0050C58C` | `0050C58C-0050C5A6` | `TRIBE_Player_Tech::get_tech_state(short)` | None: parameters, locals, registers, and lines absent | Match |
| `0050C5A7` | `0050C5A7-0050C5E4` | `TRIBE_Player_Tech::undo_tech(short)` | None: parameters, locals, registers, and lines absent | Match |
| `0050C5E5` | `0050C5E5-0050C6AC` | `TRIBE_Player_Tech::do_tech(short)` | None: parameters, locals, registers, and lines absent | Match |
| `0050C6AD` | `0050C6AD-0050C72F` | `TRIBE_Player_Tech::research(short, float)` | None: parameters, locals, registers, and lines absent | Match |
| `0050C730` | `0050C730-0050CA9D` | `TRIBE_Player_Tech::tech_cost(short, short&, short&, short&, short&, short&, short&)` | None: parameters, locals, registers, and lines absent | Accepted drift |
| `0050CA9E` | `0050CA9E-0050CC24` | `TRIBE_Player_Tech::check_tech_cost(short, short*)` | None: parameters, locals, registers, and lines absent | Accepted drift |
| `0050CC25` | `0050CC25-0050CD72` | `TRIBE_Player_Tech::start_research(short, unsigned char, short*)` | None: parameters, locals, registers, and lines absent | Open |
| `0050CD73` | `0050CD73-0050CE67` | `TRIBE_Player_Tech::cancel_research(short, unsigned char)` | None: parameters, locals, registers, and lines absent | Match |
| `0050CE68` | `0050CE68-0050D079` | `TRIBE_Player_Tech::check_for_new_tech()` | None: parameters, locals, registers, and lines absent | Open |
| `0050D07A` | `0050D07A-0050D0F9` | `TRIBE_Player_Tech::save(int)` | None: parameters, locals, registers, and lines absent | Match |
| `0050D0FA` | `0050D0FA-0050D177` | `TRIBE_Player_Tech::get_progress(short)` | None: parameters, locals, registers, and lines absent | Match |
| `0050D178` | `0050D178-0050D196` | `TRIBE_Player_Tech::get_name(short)` | None: parameters, locals, registers, and lines absent | Match |
| `0050D197` | `0050D197-0050D1B7` | `TRIBE_Player_Tech::get_string_id(short)` | None: parameters, locals, registers, and lines absent | Match |
| `0050D1B8` | `0050D1B8-0050D1D8` | `TRIBE_Player_Tech::get_string_id2(short)` | None: parameters, locals, registers, and lines absent | Match |
| `0050D1D9` | `0050D1D9-0050D1F8` | `TRIBE_Player_Tech::get_button_location(short)` | None: parameters, locals, registers, and lines absent | Match |
| `0050D1F9` | `0050D1F9-0050D280` | `TRIBE_Player_Tech::do_rev_tech(short)` | None: parameters, locals, registers, and lines absent | Match |
| `0050D281` | `0050D281-0050D305` | `TRIBE_Player_Tech::rev_tech(short)` | None: parameters, locals, registers, and lines absent | Match |
| `0050D306` | `0050D306-0050D382` | `TRIBE_Player_Tech::disable(short)` | None: parameters, locals, registers, and lines absent | Match |
| `0050D383` | `0050D383-0050D3FF` | `TRIBE_Player_Tech::enable(short)` | None: parameters, locals, registers, and lines absent | Match |
| `0050D400` | `0050D400-0050D41C` | `TRIBE_Player_Tech::get_help_message(short)` | None: parameters, locals, registers, and lines absent | Match |
| `0050D41D` | `0050D41D-0050D439` | `TRIBE_Player_Tech::get_help_page(short)` | None: parameters, locals, registers, and lines absent | Match |
| `0050D43A` | `0050D43A-0050D456` | `TRIBE_Player_Tech::get_hotkey(short)` | None: parameters, locals, registers, and lines absent | Match |

The prior review records report 29 matches, two accepted drifts, and two open
functions. The cleanup did not change that status.

## Names and declaration decisions

No function names changed. No new names were added.

The original public symbols support these identities. Examples include:

- `??0TRIBE_Tech@@QAE@HPAVTRIBE_World@@@Z` at `0050B840`.
- `??0TRIBE_Tech@@QAE@PAD@Z` at `0050BB84`.
- `?do_tech@TRIBE_Tech@@QAEEFPAVRGE_Player@@@Z` at `0050BF9C`.
- `??0TRIBE_Player_Tech@@QAE@HPAVTRIBE_Tech@@PAVRGE_Player@@E@Z` at `0050C3A5`.
- `?start_research@TRIBE_Player_Tech@@QAEEFEPAF@Z` at `0050CC25`.
- `?check_for_new_tech@TRIBE_Player_Tech@@QAEEXZ` at `0050CE68`.

The same public-symbol set supports the remaining method names in the table.
Caller names and the reviewed class layouts support the current parameter names
and field roles. The PDB does not prove those names. No local or parameter was
renamed without that proof.

## Resource and lookup review

`src/tech.cpp` has no resource ID lookup. It reads tech records with
`rge_read` and copies a record name with `getstring`. No `LoadString`, resource
handle, numeric resource ID, override table, or fallback module occurs in this
source. Resource override and fallback review is not applicable.

## Possible code-generation effects

The edit changes source layout only. It does not change compiler tokens or
control flow. The original module has no line records, so the edit cannot
preserve a known source-line map. A compile was not run, so byte identity was
not rechecked here. The prior match and drift records remain the evidence for
code generation.

## Validation limits

Per the task limit, I did not run compilation, a build, an audit, validation,
tests, or the game. I only inspected the source, callers, inventories, types,
public symbols, and PDB module data. I also ran the whitespace-only
`git diff --check` command after the edit.
