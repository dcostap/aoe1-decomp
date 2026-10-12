# Visual culture IDs

Base commit: `425acd2ffbc6ef25dd1cda944ba7daf4d6fb784e`.
The commit that adds this report contains the complete cleanup.

## Meaning and ownership

Culture selects shared building art and interface art. It is not the civilization ID.
Several civilizations use the same culture.
The original Gaia prototype even uses culture 3, not culture 0.

Added these descriptive cleanup macros in the existing `include/player.h`:

| Value | Name | Original prototype names in this group |
| --- | --- | --- |
| 0 | `RGE_CULTURE_EGYPTIAN` | Egyptian, Assyrian, Sumerian |
| 1 | `RGE_CULTURE_GREEK` | Greek, Minoan, Phoenician |
| 2 | `RGE_CULTURE_BABYLONIAN` | Babylonian, Hittite, Persian |
| 3 | `RGE_CULTURE_EAST_ASIAN` | Gaia, Shang, Yamato, Choson |
| 4 | `RGE_CULTURE_ROMAN` | Roman, Carthage, Palmyra, Macedonian |
| 5 | `RGE_CULTURE_COUNT` | Number of supported visual cultures; not another culture |

These names describe the shared styles. They are not recovered original macro or enum names.
The first three style names use representative civilizations from their groups.
East Asian describes the Shang, Yamato, and Choson group; it does not rename those civilizations.
The data calls the expansion prototypes `Carthage` and `Palmyra`.
Their game civilization names remain Carthaginian and Palmyran.

The owner header declares the live player's culture field.
All changed source modules already obtain this header through their existing includes.
The macros add no storage or enum type. Each expands to the same unsuffixed `int` literal as before.

## Original data evidence

Read the pinned compressed database without loading or running the game:

`orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/data2/empires.dat`

SHA256: `5ea86fadafc9f92dcc692d6210f377a1f6c0d82280b5b2a30a46b492b7c5253c`.
Raw DEFLATE decoding produces 1,403,005 bytes with the header `VER 3.7`.

The binary loader reads 20 name bytes, two shorts, the attribute floats, and one culture byte.
The original `RGE_Master_Player(int)` instructions at `004610C0`–`00461143` prove this order.
All 17 inspected records have 58 attributes.
Their culture byte lies 256 bytes after the name begins.
The player-count field at decoded offset `029A8C` contains 17.
The type byte before each inspected name contains 1.
These independent fields distinguish the prototype records from other name occurrences.

| Prototype | Decoded name offset | Culture |
| --- | --- | --- |
| Gaia | `029A8F` | 3 |
| Egyptian | `03EBF0` | 0 |
| Greek | `0501A6` | 1 |
| Babylonian | `06175C` | 2 |
| Assyrian | `072D12` | 0 |
| Minoan | `0842C8` | 1 |
| Hittite | `09587E` | 2 |
| Phoenician | `0A6E34` | 1 |
| Sumerian | `0B83EA` | 0 |
| Persian | `0C99A0` | 2 |
| Shang | `0DAF56` | 3 |
| Yamato | `0EC50C` | 3 |
| Choson | `0FDAC2` | 3 |
| Roman | `10F078` | 4 |
| Carthage | `12062E` | 4 |
| Palmyra | `131BE4` | 4 |
| Macedonian | `14319A` | 4 |

Offsets and instruction addresses use hexadecimal notation. Culture values use decimal notation.

## Original executable evidence

Read the executable bytes directly with PE parsing and x86 instruction decoding:

`orig/empiresx.exe`

SHA256: `88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.
This is the file pinned by `config/executable.json`.
Original instruction listings and existing declarations supply supporting symbol names, not a separate behavior oracle.

- `TRIBE_Screen_Game::player_changed`, `00498A50`, loads the byte at player offset `54`.
  At `00498B00`, it compares culture with 5; `JL` at `00498B0F` retains values below 5.
  Other values take the zero fallback.
  The Roman resource branch compares culture with 4 at `00498B26`.
- `TRIBE_Screen_Game::setup_buttons`, `004996C0`, reads the same player byte.
  It compares with 5 at `00499728`, but uses `JLE` at `0049972F`.
  Thus, culture 5 still bypasses this fallback. The cleanup preserves this different boundary.
- The editor building-icon loop compares with 4 at `004B0186` and sets the mapped index to 1 at `004B018D`.
  It writes the mapped slot at `004B01E8`, then checks the five-iteration limit at `004B0205`.
  The cleanup names this existing Roman-to-Greek mapping without changing its slot writes or allocations.

## Changed source

Changed files:

- `include/player.h`: five culture IDs, one count, and the domain comments.
- `src/scr_game.cpp`: 25 substitutions in culture dispatch, resource selection, fallbacks, and building-icon loops.
- `src/scr_sed.cpp`: one building-icon destruction count.
- `src/scr_sed2.cpp`: four substitutions in icon initialization, loading, and the existing culture mapping.
- `src/spnl_obj.cpp`: two default culture values for the editor object panel.
- `workflow/decomp_notes/culture_ids.md`: this report.

All 32 substituted values retain their numeric values and effective types.
Applied the existing clang-format settings to the game source and owner header.
Only the longer culture-color condition needed new wrapping.
The other three sources preserve their original formatting.

The existing five-entry array declarations remain unchanged. This task adds no header includes.
Serialization, culture copies, dynamic array indices, object fields, palette indices, and resource arithmetic remain unchanged.
No signature, layout, registry entry, compiler profile, parameter name, or local name changed.

## Other uses and limits

The discovery search covered `src/` and `include/`.
Other uses already name the culture field or pass its data value; they need no literal replacement:

- `src/mst_play.cpp` reads and saves the prototype culture byte.
- `src/player.cpp` reads, copies, and saves the live player culture byte.
- `src/t_b_obj.cpp` copies the owner's culture and saves the building culture byte.
- `src/tpnl_obj.cpp` selects building icons from that stored culture.
- `src/tworld.cpp` supplies the culture value to an existing statistics field.

The `save_culture = -1` value remains a cache sentinel, not a culture ID.
The AI debug text in `src/tplayer.cpp` calls a civilization index a culture number.
It still prints `master_player_id - 1`; this original string remains unchanged.
The scenario editor still keeps its construction culture when its civilization setting changes.
No behavior repairs belong to this naming pass.

Unrelated `src/player.cpp`, `src/tplayer.cpp`, and `.idea/` changes remain outside this commit.

## Validation

Reports are under `build/culture-cleanup/`.
The preserved baseline uses `build/button-command-cleanup/functions/report.json` and its objects.
Before editing, all 225 input fingerprints and object hashes matched the working tree.
The retained global object, its input fingerprint, and all 78 input records also matched.

Ran these final checks:

- Compiled all 225 configured function groups with the pinned VC5 recipes; no compile errors occurred.
- Compiled integration-only `src/game_globals.cpp` with the configured `default` profile.
- Compared all 226 C/C++ non-debug object payloads; no differences occurred.
  This checks section bytes, sizes, flags, relocations, and allocated symbol identities.
  Private compiler labels retain section/offset identity; debug records are excluded.
- Checked all 5,013 exact matching claims; all passed.
- Compared all 5,426 function observations and summaries; none changed, appeared, or disappeared.
- Checked matching ownership; no duplicate owners, owner mismatches, class/free mismatches, or repair entries occurred.
- Rechecked all 225 final input fingerprints and object hashes; all matched the fresh report.
- Checked all 32 substituted numeric values, inverse source restoration, header scope, and LF line endings.
  Three source files restore directly; the game source also needs reversal of the single wrapped condition.
- Checked the fresh global input fingerprint, all 78 input records, and its object hash; all matched.
- Ran `git diff --check`; it passed.

The 413 nonmatching observations remain unchanged.
They include 217 verified-logic observations, 140 accepted-drift observations, 44 grouped mismatches, and 12 boundary problems.
This cleanup does not resolve those existing limits or prove full game behavior.

The user requested generated-output parity and matching checks only.
No linked executable build, linked-image audit, assembly rebuild, automated test suite, or runtime suite ran.
Runtime executable selection remains unchanged.
