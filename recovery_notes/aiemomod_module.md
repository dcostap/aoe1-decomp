# aiemomod canonical-base cleanup

`EmotionalAIModule` has PDB base `AIModule` and size `0x1C0`.

`include/aiemomod.h` includes canonical `aimodule.h`. It owns only
`EmotionalAIModule`. `MainDecisionAIModule` stays a forward declaration. The
module stores it only as `md`.

The direct VC5 candidate has 13 exact owners. Each reports `MATCH`, `0.0000%`.
It has no ownership, relocation, boundary, or comparison error.
