# CRT reference identities

## Behavior

No game executable was run. All executable access was static.
Original PDB public records establish the addresses in `config/reviewed_reference_identities.json`.
Section 1 starts at VA `00401000`; add each public record's section offset to that address.
The manifest pins the original EXE, original PDB, and the alias library by SHA256.

The pinned VC5 LIBC archive has SHA256 `4ae22c6f35a87c55c453ad388ada649ea3ba190614be3d1ab95935ba0faa7416`.
Its `ftol.obj` exports `__ftol` at section offset zero.
All 39 bytes equal the original bytes at `0054B700`, without relocation masking.
The object hash is `689b39bdf1a7cc9cbd11098f100acff25437ccc60413b51177b356da6b63dbde`.

The library's `strstr.obj` exports `_strstr` at offset zero in its 128-byte code section.
Every byte equals the original at `0054B9A0`, except its one relocation field at offset 111.
That REL32 field names `___from_strstr_to_strchr` and reaches original VA `0054E9D6`.
The original PDB public record independently names that exact target.
The object hash is `08a7308129d8e4ac698bc145ba47db9f3b462e08c7474dd493a7ad7bc72e5a05`.

The library's `strchr.obj` exports `_strchr` at offset 16 and the shared target at offset 22.
Its entire 204-byte code section equals original bytes at `0054E9C0`, without masking.
The object hash is `fa07d24f427426afd4f3cc9cec6056207788091e464e4aebf1cdbac91a39ec6b`.
These objects were extracted under `build/crt_identity/`; no original binary was linked into game source.

## Source

Use `cvdump.exe -p orig/age1_x1.pdb` to reproduce the public records.
The inspected cvdump is the installed reccmp copy under the local pi-web-smart-fetch GitHub cache.
Use the pinned VC5 LIB.EXE `/list` and `/extract` commands to reproduce the object checks.
Archive member paths are `..\build\intel\st_obj\ftol.obj`, `build\intel\st_obj\strstr.obj`, and `build\intel\st_obj\strchr.obj`.
Use the configured minimal toolchain environment for these old tools.

Original public records show both spellings at identical addresses for:

- `_close` and `__close`: `0054CCA0`;
- `_read` and `__read`: `0054CD80`;
- `_write` and `__write`: `0054D4A0`;
- `_lseek` and `__lseek`: `0054D3E0`;
- `_itoa` and `__itoa`: `0055BD00`;
- `_stricmp` and `__stricmp`: `0054EB70`; and
- `__alloca_probe` and `__chkstk`: `0054DEE0`.

The original PDB names `__open`, `__tell`, and `__unlink` at their configured addresses.
Pinned OLDNAMES.LIB supplies the corresponding single-underscore names as weak external alias records.
For each, its weak external points to symbol index zero, the corresponding double-underscore external.
These records contain no forwarding instructions or memory effects.
Reproduce this check with pinned DUMPBIN.EXE `/symbols` on OLDNAMES.LIB.

The FPO listing calls `0054CD80` `_read`. The public records prove that `__read` is another name for that address.
This is not a reason to remove underscores from arbitrary symbols.
No C++ owner, overload, const qualification, or access decoration is aliased by this review.

## Bytes

The helper checks above provide independent full-body and direct-target evidence.
The remaining CRT rows establish identity from original public records, not complete CRT implementation equivalence.
Their acceptance applies only to the listed target address and listed names.

## Integration

The identity reader rejects changed evidence inputs.
A new original symbol outside the reviewed set keeps the target unknown.
No reviewed row can erase a conflicting owner.
The validation fingerprint includes the reviewed manifest.
Game source and registry statuses remain unchanged by this identity repair.
