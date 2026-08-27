# 00411740 `ResearchAIModule::ResearchAIModule`

- PDB source: `airchmod.cpp`, lines 38 to 75.
- Original size: 512 bytes.
- Former owner: `src/matching/00411740_ResearchAIModule.cpp`.

The former isolated owner matched exactly with `/GX`.

The proven layout has a `0xF0` `AIModule` base, a `0x70` `ResourceItem`, and a `0x54` `TechnologyItem`. The constructor uses normal `new` allocation and a by-value `ResourceItem` argument. VC5 emits the required exception cleanup for these objects.

The first integer goes to the base constructor. The second integer is the input file handle. The source keeps this order because the executable proves it.

Each allocated item goes before the embedded technology item. The code updates both list links and the tail link.

The source now lives in `src/airchmod.cpp`. This move removes the isolated owner only. It does not change the recovered behavior.
