# `m_co_obj.cpp` cleanup report

## Delivery

- Module: `src/m_co_obj.cpp`
- Base commit: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`
- Final source commit: `630a5f20f737a32d1eabce6c1cc1a65a7df64990`
- Base source blob: `e7f54d212108a65a67a5b761984b1a528a751300`
- Final source blob: `13de99dd3a4af9e5a4e6f417a4a38478b0a880c2`
- Changed files:
  - `src/m_co_obj.cpp`
  - `decomp_notes/source_cleanup/wave02/m_co_obj.md`
- Header read but not changed: `include/m_co_obj.h`

The source commit contains only the assigned source file. The report is the
second assigned change and is committed in the follow-up report commit.

## PDB coverage

The source owner is `C:\\msdev\\work\\age1_x1\\m_co_obj.cpp`. I inspected all
fifteen normal VAs in `config/functions/src/m_co_obj.cpp.json`.

| VA | PDB span | Registry status | Scoped stack records | Register records |
| --- | ---: | --- | --- | --- |
| `0044FE40` | 27-30 | `matching` | `other_object`, `do_setup` | `this` |
| `0044FEC0` | 36-39 | `matching` | `infile`, `sprites`, `sounds`, `do_setup` | `this` |
| `0044FF30` | 45-48 | `matching` | `infile`, `sprites`, `sounds`, `in_id`, `do_setup` | `this` |
| `0044FFB0` | 53-99 | `matching` | `other_object` | `this` |
| `00450170` | 104-177 | `matching` | `infile`, `sprites`, `sounds`, `temp_fight_sprite` | `this` |
| `00450450` | 182-262 | `accepted_drift` | `infile`, `sprites`, `sounds`, `in_id`, `temp_area_effect_level`, `temp_fire_missile_at_frame`, `temp_break_off_combat`, `temp_base_armor`, `temp_fight_sprite` | `this` |
| `00450680` | 268-280 | `matching` | none | `this` |
| `004506D0` | 285-299 | `matching` | `owner`, `x`, `y`, `z` | `this` |
| `004507A0` | 304-306 | `matching` | none | `this` |
| `00450810` | 311-358 | `matching` | `source` | `this` |
| `00450A00` | 362-402 | `matching` | `amount`, `flag` | `this` |
| `00450B40` | 406-468 | `matching` | `amount`, `flag` | `this` |
| `00450D00` | 472-504 | `matching` | `amount`, `flag` | `this` |
| `00450E20` | 509-543 | `matching` | `outfile`, `temp_fight_sprite` | `this` |
| `00451000` | 549-577 | `accepted_drift` | `attacker`, `tot_armor` | `this` |

All `this` records have the type `RGE_Master_Combat_Object*`. The scoped PDB
file SHA-256 is `adb5adc77fd4265ca449cfa6d9baf38660ce769cacc7a7972594939e42ff0335`.

The `00450450` PDB records reuse homes. `in_id` shares `+0x10` with
`temp_area_effect_level`. `temp_base_armor` shares `+0x8` with `sprites`.
The source keeps separate declarations and keeps the `input` alias.

The compiler-generated `0044FEA0` scalar deleting destructor was also checked.
It has only the `__flags` stack record and no source body in this module.

The inspected inventory packet hashes are:

- `0044FE40_RGE_Master_Combat_Object.txt`: `c29d6abfbaebf89eab559d10e48024149751d1119d3ccabf1619faa64a47f5ee`
- `0044FEC0_RGE_Master_Combat_Object.txt`: `0f7fa62cabbf56fe73339f5c6a480c90b9aa16ddb05ae43666d0ef98fc0cee6f`
- `0044FF30_RGE_Master_Combat_Object.txt`: `416bbb44dd1cacd6d9819e6ea747f4a40fb5b8d94716a221431bb8a5145673e3`
- `0044FFB0_setup.txt`: `15fe54c970bd0f1d2796fc41e7bb17509c0be3331a33cd9d8ea635cf1928da4e`
- `00450170_setup.txt`: `b722c160f53f7dda86e9575aa748dd2bc3f614e14d56db31f5d64cb26e967ebf`
- `00450450_setup.txt`: `1754bcd2ba261071df1370f3f392d90b737c312333422621b62246497319ba85`
- `00450680_RGE_Master_Combat_Object.txt`: `0612255e3dc8482e96addb46b2c3c38c0007615f74cd151eb5bc7c74f796262f`
- `004506D0_make_new_obj.txt`: `77f036ab3d086bf38919f33dcd65d4afbc6bf729159d604d034322b4a5031cb6`
- `004507A0_make_new_master.txt`: `4cae1bde7f05c4d0451b3d7e6cbaa76babf6a60c28f2ea9f59fe20752041b466`
- `00450810_copy_obj.txt`: `0cb82b2b11a61eee0ad1794cbcd2d423c186afa067eab4c6b2b7eb22cede4536`
- `00450A00_modify.txt`: `0f19c5ecc9919f953db1323823cda80894461ff2aca9c500b876232930a0a626`
- `00450B40_modify_delta.txt`: `fbe7da9eca56e95d65b1f0a07830dae3ac3ca1b1844b7fcb9c56558909016639`
- `00450D00_modify_percent.txt`: `a333de831b4eeaa3a702a490d69d8adaa71cbd8ed05d48188d3dd207826a013d`
- `00450E20_save.txt`: `e5ba89dee2220db31cfba8e97af8d2ce5392e1084d7a0b5065b88a9d57761971`
- `00451000_calc_base_damage_ability.txt`: `729168d2e2756bce559f3c29c730ef4a442ba8a7543d7f048593fbdf6e877064`

## Name recovery

Recovered PDB names in the source definition are:

- The first constructor `source` became `other_object`.
- The integer constructor `id` became `infile`.
- The file constructor `file` became `infile`, and `id` became `in_id`.
- The pointer setup parameter `source` became `other_object`.
- The binary setup parameter `file` became `infile`.
- The binary setup local `sprite_id` became `temp_fight_sprite`.
- The text setup parameter `file` became `infile`, and `count` became `in_id`.
- The text setup local `sprite_index` became `temp_fight_sprite`.
- The factory parameter `player` became `owner`.
- The update parameters `value` and `attribute` became `amount` and `flag`.
  This applies to `modify`, `modify_delta`, and `modify_percent`.
- The save parameter `file` became `outfile`, and `sprite_id` became
  `temp_fight_sprite`.
- The damage parameter `target` became `attacker`.
- The damage local `count` became the recovered PDB name `tot_armor`.

The source already used the PDB names `do_setup`, `sprites`, `sounds`, `source`,
`x`, `y`, and `z` in their proven roles. No new inferred names were added.
Existing inferred locals remain, including `input`, `index`,
`armor_count_value`, `value_count`, `selected_sprite`, `packed`, `encoded`,
`entries`, `remaining`, `armor_count`, `base_armor`, `value`, `left`, and
`diff`.

The PDB has no one-to-one records for those locals. I did not merge them or
change their types, scopes, declaration order, or storage duration. The reused
homes in `00450450` remain separate. The existing `other` copy local also
remains because no scoped record proves a different mapping.

## Constants, resources, and comments

No constant or resource ID was added. This module has no resource lookup.
Existing attribute case values, `master_type = 0x32`, global threshold symbols,
casts, widths, and literals remain unchanged.

No source comment was added. The existing parser comment records the shipped
low-byte store for `fire_missile_at_frame`. The existing case-15 comment records
the shipped `missile_id` source for `base_armor`. The original assembly and the
image-dependency repair note support both facts.

## Code generation and header requests

The edits change parameter and local spelling, plus brace placement. They do
not change types, declarations, scopes, storage, class layout, call order,
literals, direct targets, relocations, or executable statements.

The brace and line changes can alter debug line records. Name changes can alter
debug names. No ABI symbol identity changes. The uncertain reused-stack mappings
remain untouched. Compilation is required before accepting code-generation
claims.

Request for owner 08: update declaration parameter names in `include/m_co_obj.h`
without changing types or layout. The requested names are:

- Constructors: `other_object`, `do_setup`; `infile`, `sprites`, `sounds`,
  `do_setup`; and `infile`, `sprites`, `sounds`, `in_id`, `do_setup`.
- Setup overloads: `other_object`; `infile`, `sprites`, `sounds`; and `infile`,
  `sprites`, `sounds`, `in_id`.
- `make_new_obj`: `owner`, `x`, `y`, `z`.
- `copy_obj`: `source`.
- `modify`, `modify_delta`, `modify_percent`: `amount`, `flag`.
- `save`: `outfile`.
- `calc_base_damage_ability`: `attacker`.

No resource-header request exists. No resource extraction was needed.

## Validation limits

I read the assigned workflow guides, source, matching header, registry, PDB,
function packets, Ghidra evidence, cleanup notes, and pinned toolchain record.
I ran evidence inspection, Git hash commands, full Git diff review, and
`git diff --check`.

I did not run compilation, matching, audits, builds, tests, or games. I did not
run the resource extractor. No byte equality or semantic approval is claimed.
