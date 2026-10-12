# DirectPlay error names in the communication error handler

## Scope

The starting commit is `8d30afbf0`.
`RGE_Comm_Error::ShowReturn` (`00424EB0`, status `matching`) now names all 81 HRESULT literals.
Only `src/com_err.cpp` changed. Its threshold tree, branch order, and log texts are unchanged.

The module now includes the approved period header `third_party/directplay/include/dplay.h`.
It uses the same relative form as `src/com_hand.cpp`. No flag profile or registry entry changed.
The pinned VC5 `DPLAY.H` stops at `DPERR_USERCANCEL` and cannot name the DirectPlay 2 and 3 codes.

## Name sources

- `0x8877xxxx` values use `MAKE_DPHRESULT` codes from the approved `dplay.h` (`_FACDP` is `0x877`).
- When `dplay.h` defines a DirectPlay alias for a COM code, the handler uses that alias.
  These aliases are `DPERR_UNSUPPORTED`, `DPERR_PENDING`, `DPERR_GENERIC`, `DPERR_NOINTERFACE`,
  `DPERR_OUTOFMEMORY`, and `DPERR_INVALIDPARAMS`.
- The remaining COM codes use pinned VC5 `WINERROR.H` names: `E_POINTER`, `E_ABORT`,
  `E_ACCESSDENIED`, `E_HANDLE`, and `CLASS_E_NOAGGREGATION`.

The old `(long)` casts were removed. Each SDK name already has `HRESULT` (`long`) type.

## Original log mismatches

The function is byte-exact, so these mismatches are original behavior:

| Code | Name | Logged text |
| --- | --- | --- |
| `0x88770140` | `DPERR_UNINITIALIZED` | "Unknown application specified" |
| `0x8877014A` | `DPERR_NONEWPLAYERS` | "The session is in the process of connecting" |
| `0x8877042E` | `DPERR_NOTLOBBIED` | "Security authentify failed." |
| `0x887707D0` | `DPERR_AUTHENTICATIONFAILED` | "Not A Lobby Session" |

`DPERR_NONEWPLAYERS` still sends `COMM_NO_NEW_PLAYERS`. Only its log text is wrong.
A short source comment records these mismatches.

## Validation

Artifacts are under `build/cleanup-2026-10-10/` (`dperr-2`).
The baseline is the full audit at `c41e6039a`. `com_err.cpp` did not change between that commit and the start of this work.

- The single affected group compiled, and all four exact claims passed.
- Its non-debug object payload matches the baseline. This covers section bytes, relocations, and symbols.
- `git diff --check` and the line-ending check passed. clang-format 21.1.8 was applied.

No linked executable build, image audit, automated tests, or runtime suites ran.
