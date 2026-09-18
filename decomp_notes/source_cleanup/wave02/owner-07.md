# Owner 07 AI support cleanup ledger

## Scope

- Group base: `ef1c4d2e33bac077e7e4e21598f1c18722a721c6`
- Integration branch: `cleanup/staging-20260915-55`
- Sources: `src/aidipmod.cpp`, `src/aiemomod.cpp`, `src/aiinfmod.cpp`,
  `src/aimdmod.cpp`, `src/airchmod.cpp`, `src/airesmod.cpp`,
  `src/aistrmod.cpp`, and `src/aitacmod.cpp`
- Headers: the eight matching module headers under `include/`
- Header commit: `bbcdf6db55fb58ac7ae413ebd85a0859145b7493`

The header commit restores PDB parameter spellings. It does not change a type,
order, virtual slot, layout, or symbol. Each module report gives full procedure
coverage and supporting evidence.

## Workers and integration

All workers started from
`ef1c4d2e33bac077e7e4e21598f1c18722a721c6`. Each worker tree was clean at its
listed final head.

| Module | Worker | Worker commits and final head | Integrated commits | Review result |
| --- | --- | --- | --- | --- |
| `aidipmod` | `sa-2b27829e` | `222c80715f2dfee67a8ee2215a68b1d69472a5a5`, `3fcd47a9ecac335260b5d72585d3e2d09b5508a9`, final `796bec78cca0017f5ec18ea273d4175816f720b4` | `99705ad5120abd525e8dec4bd3f5d143dca5c655`, `9a751ce6a34f268e070a361df32abf4097efe38f`, `18493007a51e2d58f3dcf644801c415e217fe39e` | Approved after the resource request name and role were corrected. |
| `aiemomod` | `sa-e896f70b` | `be42c7aef4ba063d31f860faa701082262059dec`, `358843c293a6ada588cd291d2993496fbe454a07`, final `64e0177e9733f4384ddb5e597919d6c57affdcc5` | `137d2677acd4d31436a12ecca34d5a83473537da`, `a5e8dc1a857e9717341b81465ba6bf7dbefd25d0`, `8b7207a56b61aa10edbd1ef9322bc82b9460b890` | Approved after both constructor braces used 1TBS. |
| `aiinfmod` | `sa-d1a94b6b` | `0a49e85731596125d56d4b8119d48286d866e635`, final `ecbf53e0a86cf5a7410efc7c9b28c36cd566e1c1` | `9fac66bd06e18084d611fd6a7d6db8c164b78a02`, `913e7d263f34918fdae36960e72313ec894e0700` | Approved on first review. |
| `aimdmod` | `sa-3791af1c` | `305a85c363894606688f421eee0c9ebf810f4b20`, `c09b2d9ef740020a500b5f5355001000b2eb4358`, final `e30f192e87f98a44467aa4f934f37f734cd0fe0a` | `f493c978dd54c1774714cee5e35689ef01be9feb`, `d9afa5634dca4d253534fa1d1a6fc2d43542243e`, `ba5f04547380febedca6dbb6051b2e5b22c78827` | Approved after short signatures were joined. |
| `airchmod` | `sa-b48973d9` | `9a0dbca8480bf09e23927a6b9e548b65a9c1fa0c`, `d16969fa0de7016e1a25a3c0db07dd2722bed6b3`, final `f2e6f59b3c62ab60258e4b2c478be294a9d5c143` | `d1c72862949fc1e421eecabd5a718974a0ecd07e`, `ac0bdae181e2f67542e7902d22088f8b5cd5a6e6`, `8b12b7cab7670bff99b8713f76379d3a4f7f13e1` | Approved after the scoped-symbol hash was corrected. |
| `airesmod` | `sa-dab84dd7` | `239fcbdfccf99122ed33a2f6650d3661a34f68ba`, `909aa4f121da5a43806119b2f6491ee45707f03b`, `feb214c7eb6d4ed17346f4b530fc893d6860f6a6`, final `92ddf15fedcc771e953a78eff2be88a8587c252d` | `1f79012acfae89b08ca08d922ee8675399562f03`, `a4aefcbbb016a43f5b7dabcba72fa4a91779db93`, `5704debb3517cdb309f3c36763a33378317fd176`, `6a4624968915e83a0346620455a33530609ba91c` | Approved after short signatures and calls were joined. |
| `aistrmod` | `sa-d107c495` | `cd928daecef5427fb13131868ba93fd26e45cfe0`, `fc05083189ecac0b8ac0333a302eb15c8375035a`, final `412b01764b4f0bea66e24cdd3ba7a8bb253ba847` | `d34ef1a4e75675b9d41838fd8bae264cd28615be`, `78f674cd244d1380b3762870d26ff98dc8d91cd3`, `057de7cf8f869eef6396fce184938d8f55c140de` | Approved after the scoped-symbol hash was corrected. |
| `aitacmod` | `sa-dc8cc979` | `f52f474766e6c3bbdc744d0853d0e8d122c1ce3e`, final `7199471c7eb1e08e97102f445f4fc656be62d5ae` | `b26d06d7920e149f6a2c3e48c9b76cff64d49f67`, `6f1eb8e7a9a749ebfc9e8876f26b47072977d141` | Approved on first review. |

## Name mappings

The source and owned declarations now use the procedure-scoped PDB parameter
names. The main groups are:

- `aidipmod`: `pW`, `playerID`, `infile`, `m`, `timeLimit`, `outfile`,
  `likeType`, `delta`, `v`, `tributeOn`, `tributePlayer`,
  `attackWinningPlayer`, `attackWinningPlayerFactor`, and `newRelation`.
- `aiemomod`: `pW`, `playerID`, `infile`, `m`, `outfile`, `s`, `value`, and
  `delta`.
- `aiinfmod`, `aistrmod`, and `aitacmod`: `pW` and `playerID`.
- `aimdmod`: `pW`, `playerID`, `plyr`, `infile`, `v`, `outfile`, `obj`, `id`,
  `aid`, `gid`, `action`, `target`, `tt`, both full `object` overload name
  sets, `a`, `t`, `oGroup`, and `oType`.
- `airchmod`: `pW`, `playerID`, `infile`, `m`, `outfile`, `bi`, `lName`, and
  `id`.
- `airesmod`: `pW`, `playerID`, `n`, `iV`, `minV`, `maxV`, `m`, `timeLimit`,
  `ri`, `v`, `r`, and `t`.

PDB-backed locals were also restored where the storage mapping was clear. New
cleanup names use snake case. The module reports distinguish both name classes.

## Unresolved evidence

- `aidipmod` has an older note that calls `stance` scratch. The current registry
  calls all 21 owners matching. This cleanup did not resolve that prior status
  conflict.
- `aimdmod` has reused optimized stack slots in its load constructor and `save`.
  The source keeps separate declarations and scopes.
- `airchmod` keeps two PDB/source type discrepancies unchanged. They are the
  load-constructor `name` buffer and `loadTechnologyTree` local `id`.
- Several modules have optimized locals with no scoped PDB record. Their reports
  identify these names. No uncertain storage mapping forced a declaration,
  type, scope, or layout change.
- No module added a constant or changed a resource lookup.

## Shared request

Request root review for one base-language resource declaration:

```cpp
#define STRING_ID_HELP_WINDOW_TITLE 0x03EB
```

This request applies only to the `RGE_Base_Game::~RGE_Base_Game` lookup.
That call passes the result to `FindWindowA` as the window name for class
`MS_WINHELP`.

Evidence for language `0x0409`:

- `runtime/language.dll`, SHA256
  `3fca20f2f48dc029c0793f32a906a82c5e0fd99292a9f9843c4266d3aba5d0f5`,
  contains `Age of Empires Help` at `0x03EB`.
- `runtime/languagex.dll`, SHA256
  `4d574896a6b94a451fc5c20497e1d34c440f3b7d8a93219d4c82470516155a39`,
  has a missing string block for this ID. It is not an empty slot.
- The pinned original expansion `languagex.dll`, SHA256
  `a246118b980e4016b1cf87311efa04bd960799fd1b5ea29746ee6dc971c99dc2`,
  also has a missing block.
- `TRIBE_Game::get_string` checks the expansion table first. It then uses the
  base-game fallback.

`DiplomacyAIModule` also uses numeric value `0x03EB` as its module ID. That use
must remain numeric. Equal values do not prove equal roles. This request does
not block any owner 07 edit.

## Combined review and validation state

I read every complete worker diff and report. I reviewed each correction before
integration. The combined diff changes only the assigned eight sources, eight
headers, eight module reports, and this ledger. Header and source parameter
names agree. No owned header change alters a type, order, virtual slot, or
layout. No name collision or resource macro effect exists in this group.

`git diff --check` passed for the combined group diff. This is a text check, not
executable validation.

Compilation, matching, audits, and tests were not run. Builds and games were not
run. All results are reviewed but unvalidated.
