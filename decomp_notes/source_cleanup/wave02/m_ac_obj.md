# `src/m_ac_obj.cpp` source-cleanup report

## Delivery and scope

- Module: `src/m_ac_obj.cpp`.
- Base commit: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`.
- Source head commit: `7631026304e61b4f20c0d67a89893d9fd95adfdb`.
- Changed files: `src/m_ac_obj.cpp` and this report.
- Header read but not changed: `include/m_ac_obj.h`.
- Registry: `config/functions/src/m_ac_obj.cpp.json`, with `gx` flags.
- PDB source: `C:\msdev\work\age1_x1\m_ac_obj.cpp`.
- Normal source owners: 19, with 2,208 PDB bytes.

The PDB also records compiler-generated scalar deleting destructor `0044F0D0`.
It has no standalone source owner and was not edited.

Evidence used the procedure records in
`C:/Projects/my_decomps/aoe1_attempt3/inventory/pdb/scoped_symbols.json`.
The behavior-oracle file is
`C:/Projects/my_decomps/aoe1_attempt3/orig/original_full_game_files_rise_of_romes_beta_17_7_1998/XPack/empiresx.exe`.
Its SHA256 is
`88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.
The preserved pre-cleanup output is under
`C:/Projects/my_decomps/aoe1_attempt3/build/source-cleanup-20260915/preparation/baseline-build/`.

## PDB inspection coverage

The inspection covered every PDB procedure tied to `.\\Release\\m_ac_obj.obj`.
Every record has `this` in `ecx`, with the recorded class type.

| VA | Procedure | PDB stack symbols | Source status |
| --- | --- | --- | --- |
| `0044F070` | constructor | `other_object` `+0x4`; `do_setup` `+0x8` | Normal owner; recovered both names. |
| `0044F0D0` | scalar deleting destructor | `__flags` `+0x4` | Compiler-generated; no source body. |
| `0044F0F0` | constructor | `infile` `+0x4`; `sprites` `+0x8`; `sounds` `+0xC`; `do_setup` `+0x10` | Normal owner; recovered all names. |
| `0044F160` | constructor | `infile` `+0x4`; `sprites` `+0x8`; `sounds` `+0xC`; `in_id` `+0x10`; `do_setup` `+0x14` | Normal owner; recovered all names. |
| `0044F1E0` | `setup` copy overload | `other_object` `+0x4` | Normal owner; recovered the name. |
| `0044F290` | `setup` binary-file overload | `infile` `+0x4`; `sprites` `+0x8`; `sounds` `+0xC`; `command_sound_num` `+0x10`; `move_sound_num` `+0xC` | Normal owner; recovered the recorded names. |
| `0044F3C0` | `setup` text-file overload | `infile` `+0x4`; `sprites` `+0x8`; `sounds` `+0xC`; `in_id` `+0x10`; `temp_run_pattern` `+0x10`; `temp_command_sound` `+0xC`; `temp_task_by_group` `+0x14`; `temp_move_sound` `+0x8` | Normal owner; recovered the recorded names. |
| `0044F4D0` | destructor | none | Normal owner; no parameters or locals. |
| `0044F540` | `create_task_list` | none | Normal owner; no parameters or locals. |
| `0044F5A0` | `make_new_obj` | `owner` `+0x4`; `x` `+0x8`; `y` `+0xC`; `z` `+0x10` | Normal owner; recovered all names. |
| `0044F670` | `make_new_master` | none | Normal owner; no parameters or locals. |
| `0044F6E0` | `get_task` | `task_id` `+0x4` | Normal owner; the existing name matches the PDB. |
| `0044F710` | `getTaskByTaskID` | `t` `+0x4` | Normal owner; recovered `t` from the PDB. |
| `0044F760` | `copy_obj` | `source` `+0x4` | Normal owner; the existing name matches the PDB. |
| `0044F7F0` | `modify` | `amount` `+0x4`; `flag` `+0x8` | Normal owner; recovered both names. |
| `0044F820` | `modify_delta` | `amount` `+0x4`; `flag` `+0x8` | Normal owner; recovered both names. |
| `0044F850` | `modify_percent` | `amount` `+0x4`; `flag` `+0x8` | Normal owner; recovered both names. |
| `0044F880` | `save` | `outfile` `+0x4`; `command_sound_num` `-0x8`; `move_sound_num` `-0x4` | Normal owner; recovered all recorded names. |
| `0044F980` | `play_command_sound` | none | Normal owner; no parameters or locals. |
| `0044F9A0` | `play_move_sound` | none | Normal owner; no parameters or locals. |

The records have no function-static symbols. The PDB names above retain their
original spelling, including `other_object`, `in_id`, `t`, and `temp_*` names.

## Recovered and retained names

The source now uses these PDB-recovered names:

- The first constructor and copy setup use `other_object`.
- The integer-file constructor and binary setup use `infile`.
- The text-file constructor and setup use `infile` and `in_id`.
- The binary setup sound indices use `command_sound_num` and `move_sound_num`.
- The text setup temporary values use `temp_task_by_group`,
  `temp_command_sound`, `temp_move_sound`, and `temp_run_pattern`.
- `make_new_obj` uses `owner`.
- `getTaskByTaskID` uses the recorded short name `t`.
- The three modifier methods use `amount` and `flag`.
- `save` uses `outfile`, `command_sound_num`, and `move_sound_num`.

The source retained `selected_sound`, `action_source`, `index`, and
`task_count`. These names have no matching PDB local records. They are existing
source-level names, not recovered originals. No new inferred local name was
added.

The PDB records for `0044F290` and `0044F3C0` show reused stack offsets. In
particular, `move_sound_num` shares the recorded `sounds` offset, and the text
setup temporary values overlap parameter offsets. The cleanup changed names
only. It did not change declaration order, types, scopes, or storage mapping.

The source also moves function opening braces to 1TBS positions. It keeps all
casts, literals, calls, statement order, evaluation order, and explicit source
forms unchanged.

## Constants, resources, and comments

No new constant, resource ID, or comment was added.

- Existing master type literal `0x28` remains in all three setup overloads.
  No shared symbol proves its value and effective type for this use.
- Existing modifier selector `0x0D` remains numeric. No established attribute
  symbol proves this use.
- Existing serialized widths `1`, `2`, and `4` remain unchanged.
- Existing `-1` sentinels remain unchanged in task and sound-index paths.
- Existing `DAT_00570484` remains the save-version threshold. The nearby
  comment records the proven fallback that older saves reuse the command sound
  index for the move sound.

This module has no resource lookup. It has no resource-ID request.

## Header request

Owner 08 owns `include/m_ac_obj.h`. Please align its declaration parameter names
with the PDB records. Do not change types, order, scope, or ABI:

```cpp
RGE_Master_Action_Object(RGE_Master_Action_Object* other_object, int do_setup);
RGE_Master_Action_Object(int infile, RGE_Sprite** sprites,
                         RGE_Sound** sounds, int do_setup);
RGE_Master_Action_Object(FILE* infile, RGE_Sprite** sprites,
                         RGE_Sound** sounds, short in_id, int do_setup);
int setup(RGE_Master_Action_Object* other_object);
int setup(int infile, RGE_Sprite** sprites, RGE_Sound** sounds);
int setup(FILE* infile, RGE_Sprite** sprites, RGE_Sound** sounds, short in_id);
RGE_Static_Object* make_new_obj(RGE_Player* owner, float x, float y, float z);
RGE_Task* getTaskByTaskID(int t) const;
virtual void modify(float amount, unsigned char flag);
virtual void modify_delta(float amount, unsigned char flag);
virtual void modify_percent(float amount, unsigned char flag);
virtual void save(int outfile);
```

The existing `get_task(short task_id)` declaration already matches its PDB name.
No shared header or resource declaration request is open.

## Risks and validation

The source edits change identifier spellings and brace presentation only.
They do not add declarations or alter types, layouts, symbol names, calls,
relocations, or runtime data by source inspection. The header still has its old
parameter spellings until owner 08 reviews the request.

The brace changes can affect debug line records. Final validation must compare
the result with the preserved pre-cleanup output. This worker did not run that
validation.

I reviewed the complete Git diff and ran `git diff --check`.
Compilation, matching, audits, and tests were not run.
