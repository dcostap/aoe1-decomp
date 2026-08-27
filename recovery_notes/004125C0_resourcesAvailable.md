# 004125C0 `ResourceAIModule::resourcesAvailable`

- PDB source: `airesmod.cpp`, lines 263 to 278.
- Original size: 118 bytes.

## Recovery record

The source uses `count` for the first loop test. It refreshes `count` after each item test.

This shape preserved the initial count test and the bottom loop test in the fragment build.
