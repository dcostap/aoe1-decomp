// Build compatibility translation unit.
//
// The build scripts compile `src/game/src/screens.cpp`. Some previous work removed the file
// while migrating screen/panel implementations to their dumped headers and per-screen units.
//
// Keep this TU present (empty) so the build stays stable. Do NOT add alternate screen class
// definitions here (that caused ODR/vtable issues previously).

