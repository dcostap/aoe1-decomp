# 00411670 `ResearchAIModule::ResearchAIModule`

- PDB source: `airchmod.cpp`, lines 26 to 30.
- Original size: 169 bytes.
- Former owner: `src/matching/00411670_ResearchAIModule.cpp`.

The former isolated owner matched exactly with `/GX`.

The member initializer list sets the main-decision pointer and technology count to zero. The constructor then links the embedded technology item to itself. It clears the technology-tree name with `strcpy`.

The source now lives in `src/airchmod.cpp`. This move removes the isolated owner only. It does not change the recovered behavior.
