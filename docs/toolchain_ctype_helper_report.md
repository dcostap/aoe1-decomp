# Toolchain CRT ctype helper audit report

Date: 2026-04-22

## Scope explored

- `inventory/functions/0054/0054DF40_isupper.txt`
- `inventory/functions/0054/0054DF6A_FUN_0054df6a.txt`
- `inventory/functions/0054/0054DF9A_FUN_0054df9a.txt`
- `inventory/functions/0054/0054E11A_FUN_0054e11a.txt`
- `inventory/functions/0054/0054E12D_FUN_0054e12d.txt`
- `inventory/functions/0054/0054E138_FUN_0054e138.txt`
- `inventory/functions/0054/0054E183_FUN_0054e183.txt`
- `inventory/functions/0054/0054E237_FUN_0054e237.txt`
- `inventory/functions/0054/0054E250_toupper.txt`
- `inventory/functions/0054/0054E34C_FUN_0054e34c.txt`
- `inventory/functions/0054/0054E360_tolower.txt`
- `inventory/functions/0054/0054E1E0_atof.txt`

## Goal

Audit the CRT ctype/case-conversion neighborhood and classify only the entries supported by
strong standard-library evidence.

## High-confidence conclusions

Two unnamed helper neighborhoods are high-confidence CRT ctype/runtime regions:

- `0054DF6A-0054E1D2`
- `0054E237-0054E357`

## Why this is high confidence

### 1) The listing excerpts directly expose standard CRT helper names

Hidden names visible in the listing excerpts include:

- `_islower`
- `_isdigit`
- `_isxdigit`
- `_ispunct`
- `_isalnum`
- `___isascii`
- `___toascii`
- `___iscsymf`
- `___iscsym`
- `__toupper`
- `__tolower`

Those are textbook CRT ctype/case-conversion helpers, not project-authored game code.

### 2) The implementation style is standard CRT ctype logic

Representative evidence across the region:

- checks against `___mb_cur_max`
- calls to `__isctype`
- direct use of `__pctype`
- simple bitmask tests for ctype categories
- trivial ASCII transformations like `+0x20`, `-0x20`, or `& 0x7f`

This is standard runtime/library surface.

### 3) The neighborhood is anchored by named standard CRT functions

Named standard-library neighbors include:

- `isupper`
- `isspace`
- `_isprint`
- `_isgraph`
- `_iscntrl`
- `atof`
- `toupper`
- `tolower`

The hidden helpers sit directly between or beside these standard CRT entries.

### 4) `FUN_0054e237` and `FUN_0054e34c` are internal case-conversion helpers, not app logic

The listing excerpts identify them directly as:

- `__toupper`
- `__tolower`

Both are tiny arithmetic helpers and clearly belong to the CRT case-conversion family.

## Applied classification

### Region 1: `0054DF6A-0054E1D2`

Contains hidden CRT ctype helpers such as:

- `_islower`
- `_isdigit`
- `_isxdigit`
- `_ispunct`
- `_isalnum`
- `___isascii`
- `___toascii`
- `___iscsymf`
- `___iscsym`

### Region 2: `0054E237-0054E357`

Contains hidden CRT case-conversion helpers:

- `__toupper`
- `__tolower`

## Exact-name future-proofing

This pass also adds safe exact-name CRT names to the manifest generator, including:

- `isupper`
- `isspace`
- `atof`
- `toupper`
- `tolower`
- `_islower`
- `_isdigit`
- `_isxdigit`
- `_ispunct`
- `_isalnum`
- `_isprint`
- `_isgraph`
- `_iscntrl`
- `___isascii`
- `___toascii`
- `___iscsymf`
- `___iscsym`
- `__toupper`
- `__tolower`

## Bottom line

This neighborhood is standard CRT ctype/case-conversion machinery. It should not remain in
the normal manual C/C++ decomp queue.
