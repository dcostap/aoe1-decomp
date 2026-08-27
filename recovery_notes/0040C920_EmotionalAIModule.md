# 0040C920 `EmotionalAIModule::EmotionalAIModule(int, int)`

- PDB source: `aiemomod.cpp`, lines 40 to 50.
- Original size: 367 bytes.
- Flags: `config/flags/0040C920_EmotionalAIModule.rsp`.

## Recovery record

This constructor needs `/GX`. It reads six state values with `rge_read` and then sets the six state names. The final module retains this order and the module EH flags.
