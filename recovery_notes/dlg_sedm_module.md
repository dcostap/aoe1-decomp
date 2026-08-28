# dlg_sedm direct-source hold

Status: BLOCKED.

The PDB packet has three normal owners in source order: `00440140`,
`00440360`, and `00440400`. The scalar deleting destructor at `00440340` is
compiler generated.

A direct `dlg_sedm.cpp` needs canonical `pnl_dlg.h`, `pnl_btn.h`,
`tribegam.h`, and `rge_base_game_global.h`. These headers can provide the
dialog, button, and game surfaces.

The missing provider is a composable canonical `TRIBE_Screen_Sed` declaration.
The dialog constructor needs its conversion to canonical `TPanel`. It also
needs inherited `renderArea`, `get_popup_info_file`, and `get_popup_info_id`.
The action needs its seven direct scenario-editor methods. The Open Dialog
path also needs canonical `TRIBE_Screen_Sed_Open`.

The current `scr_sed.h` has a private copy of `TPanel`, `TEasy_Panel`, and
`TScreenPanel`. It also defines `TRIBE_Screen_Sed` on that hierarchy. It
cannot appear with `pnl_dlg.h` in one translation unit.

Do not convert `scr_sed.h` alone. Its 47-body `scr_sed.cpp` module must first
compile with canonical Main View, Diamond Map View, editor-panel, Tech, and
BaseGame providers. Its legacy header currently compiles that source module.

Keep the wrapper and matching fragments until that provider work completes.
The action uses natural dialog-name literals. It has no private
`s_Scenario_*`, `s_New_Dialog`, or `s_Open_Dialog` data references.

Candidate validation rebuilt the existing `dlg_sedm_tu.cpp`. The three normal
owners and the generated destructor matched at `0.0000%`. The existing
`scr_sed.cpp` module compiled.
