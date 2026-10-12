# Title-menu copyright comparison

The reported copyright defect also occurs in the original beta executable.
Do not attribute it to the recovered text-wrapping function.

## Controlled comparison

Both runs use copies of the same complete installed beta runtime.
Both use `NOSTARTUP GAMECD` and `DWM8And16BitMitigation`.
The original control uses the repo-local original full-game EXE, SHA-256:
`88a0392120280c1b91ee90fe6f7cf50c72e55149a16c9b1ca79505572b8b9c90`.
The rebuilt test uses build `20260907T003702275337Z`.

Both title screenshots show only the first copyright fragment, `© &`, at the left.
The product-title and warning lines appear in both screenshots.
Local screenshots:
- `build/crash/map_setup/player_id_ui/title.png`
- `build/crash/map_setup/original_title.png`

Debugger dumps taken after the title constructor show identical missing-panel state:
- first copyright panel exists;
- second copyright panel is null; and
- circle-P picture panel is null.

Original title object: `028E1538`; first copyright panel: `02BAB580`.
Rebuilt title object: `02A01538`; first copyright panel: `02B1B580`.
The rebuilt first panel has x=5, y=438, width=50, height=18, and text `© & `.
That matches the first-fragment creation path in the original constructor.
The null picture panel is consistent with the failed `get_text_rect` path.
The underlying reason for that failure is not yet established.

Both the title constructor (`0049E6D0`) and `get_text_rect` (`0047E410`) pass authoritative checks: MATCH, 0.0000%.
No title-layout source change is justified by this comparison.
A compatibility repair would change original runtime behavior and requires a separate decision.

The original control also starts a random map and responds to the Menu button.
Its achievements screen reports elapsed game time `00:01:13` after quitting.
The rebuilt test renders its first map frame but then hangs in civilian selection.
This distinguishes the new gameplay hang from the shared title-menu behavior.
