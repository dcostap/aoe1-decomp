# Rpnl_tim.cpp source recovery

The PDB module owns the constructor, draw, and idle methods in source order.
The scalar deleting destructor and the no-PDB tail-jump destructor are compiler
generated. They have no standalone source files.

`rpnl_tim.h` owns only `RGE_Panel_Time`. The source uses canonical panel, draw
area, Base Game, world, player, color table, and game-global declarations.

The existing method bodies retain their reviewed source order and period GDI
calls. The direct candidate check matches all three owners and the generated
deleting destructor.
