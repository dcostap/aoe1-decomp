# Project Roadmap: Age of Empires 1 Decompilation

With the core memory layout verified and the basic rendering loop established, the following steps are prioritized to move from a "blank green screen" to a functional game world.

## Phase 1: Data & Resource Integration
- [ ] **Implement `.dat` File Loading**: The `empires.dat` file contains the "Master Objects" (templates for every unit, building, and terrain). This is critical for populating the `RGE_Master_Object` arrays.
- [ ] **Terrain Property Loading**: Populate `RGE_Map::terrain_types` and `RGE_Map::border_types` using data from the resource files.
- [ ] **DRS Shape Loading**: Enhance `TShape` to correctly parse and load sprites from `graphics.drs` and `terrain.drs`.

## Phase 2: Isometric Rendering Engine
- [ ] **Isometric Tile Drawing**: Replace the `Clear(green)` stub with actual tile rendering. This requires:
    - Diamond-to-Screen coordinate transformation.
    - Handling the 19 `tilesizes` variations used for different elevations.
- [ ] **Elevation & Slopes**: Implement the logic to select the correct tile shape based on the `height` of neighboring tiles.
- [ ] **Map Scrolling**: Connect mouse edge-scrolling and keyboard arrows to the `cur_row`/`cur_col` offsets in `RGE_Map`.

## Phase 3: Object System (The "World")
- [ ] **Master Object System**: Implement the factory pattern used by the game to spawn objects from the `empires.dat` templates.
- [ ] **Static Objects**: Implement `RGE_Static_Object` (trees, gold mines, buildings).
- [ ] **Object Rendering**: Implement the Y-sorting logic so units appear correctly behind or in front of buildings and terrain.

## Phase 4: Basic Gameplay Mechanics
- [ ] **Unit Selection**: Implement the `Visible_Unit_Manager` and selection marquee (drag-box).
- [ ] **Pathfinding Stubs**: Implement a basic A* or BFS to allow units to move between tiles.
- [ ] **Action System**: Implement `RGE_Action` to handle unit states (Idle, Move, Attack, Gather).

## Phase 5: UI & Interaction
- [ ] **TPanelSystem**: Implement the base class for the game's UI.
- [ ] **In-Game HUD**: Create the bottom bar showing selected unit stats and the mini-map.
- [ ] **Mini-map Rendering**: A low-resolution top-down view of the `RGE_Map`.

## Phase 6: Sound & Music
- [ ] **Wave Loading**: Implement `RGE_Sound` to load and play `.wav` samples from `sounds.drs`.
- [ ] **Redbook/MIDI Audio**: Implement the background music system.
