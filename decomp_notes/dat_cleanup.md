# `DAT_` cleanup ledger

This ledger records reviews of generated `DAT_` names in compiler-facing source.

Use one of these results:

- `named`: Evidence supports a descriptive source name.
- `removed`: The declaration or definition is generated scaffolding.
- `retained`: The storage is real, but available evidence does not support a name.

Do not replace uncertainty with an invented name.

The audit also removes duplicate non-`DAT_` scaffolding when it owns the same
original storage as a reviewed symbol.

## Reviewed symbols

| Symbol | Result | Evidence |
| --- | --- | --- |
| `DAT_00575780` | removed | The original read-only `5.0f` has one reference from `stuffAvoidancePath`. The PDB has no global symbol at this address. The rebuilt function reads VC5's literal pool at `0x005562F0`. The separate `game_globals.obj` definition links at `0x00564324` and has no source reference. |
| `DAT_00575778` | removed | The original read-only `0.2f` has one reference from `stuffAvoidancePath`. The PDB has no global symbol at this address. The rebuilt function reads VC5's literal pool at `0x005562E8`. The separate definition has no source reference. |
| `DAT_0057577c` | removed | The original read-only `10.0f` has one reference from `stuffAvoidancePath`. The PDB has no global symbol at this address. The rebuilt function reads VC5's literal pool at `0x005562EC`. The separate definition has no source reference. |
| `DAT_00575784` | removed | The original read-only `25.0f` has one reference from `saveTheTown`. The PDB has no global symbol at this address. The rebuilt function reads VC5's literal pool at `0x005562F4`. The separate definition has no source reference. |
| `DAT_0057575c` | removed | The original read-only `-2.0f` is part of the `taitacmd.cpp` constant pool. The PDB has no global symbol at this address. Recovered source uses the literal, and no source references the separate definition. |
| `DAT_00575760` | removed | The original read-only `100.0f` is part of the `taitacmd.cpp` constant pool. The PDB has no global symbol at this address. Recovered source uses the literal, and no source references the separate definition. |
| `DAT_00575764` | removed | The original read-only value is the single-precision `0.01f` bit pattern. It is part of the `taitacmd.cpp` constant pool. The PDB has no global symbol, and no source references the separate definition. |
| `DAT_00575768` | removed | The original read-only `-0.5f` is part of the `taitacmd.cpp` constant pool. The PDB has no global symbol at this address. Recovered source uses equivalent literals, and no source references the separate definition. |
| `DAT_00575770` | removed | The original read-only `0.0` double is part of the `taitacmd.cpp` constant pool. The PDB has no global symbol at this address, and no source references the separate definition. |
| `DAT_00575758` | removed | The original read-only `-1.0f` has five comparison references in `taitacmd.cpp`. The PDB has no global symbol at this address. Source now uses the literal sentinel, which lets VC5 own the translation unit's constant-pool entry. |
| `DAT_00575700` through `DAT_00575754` | removed | These 20 read-only values form an earlier part of the `taitacmd.cpp` constant pool. The PDB has no global symbol for any entry. Recovered source already uses literals, and no source references the separate definitions. |
| `DAT_00577318` through `DAT_0057732c` | named | These six read-only values gate fields in `T_Scenario` file loading. Their comparison sites and values establish scenario file versions `1.13`, `1.02`, `1.03`, `1.04`, `1.12`, and `1.05`. The new `g_scenario_file_version_*` names are descriptive cleanup names, not recovered PDB names. |
| `DAT_00575618`, `DAT_0057561c` | named | These values gate conditional `TribeMainDecisionAIModule` save-file reads. Their new names state the owning module and version threshold. |
| `DAT_00575634` | removed | The original read-only `1.0f` has one code reference, but recovered source has no reference to the separate scaffold definition. The PDB has no global symbol at this address. |
| `DAT_00575690` | named | This `1.5f` value gates the strategy AI difficulty field during save-file loading. |
| `DAT_005756e0` through `DAT_005756ec` | named | These four values gate fields in `TacticalAIGroup::load`. Their names state the owning type and version threshold. |
| `DAT_005756f0` through `DAT_005756fc` | named | These four values control tactical distance clamping, offsets, and line-of-sight factors. Their names describe each use without claiming PDB provenance. |
| `DAT_00575550` through `DAT_00575560` | named | These five values gate conditional fields in `TribeInformationAIModule` save-file loading. Their names state the owning module and version threshold. |
| `DAT_00575564` through `DAT_0057557c` | removed | These seven read-only information-AI constants have no PDB symbols. Source now uses their direct float literals for distance, placement, size, and sentinel operations. |
| `DAT_00575580` through `DAT_005755c0` | removed | These 14 read-only information-AI constants have no PDB symbols. Source now uses direct literals for ratings, radii, influence factors, resource scores, and fallback times. |
| `DAT_0057548c` through `DAT_00575498` | removed | These four read-only build-AI constants have no PDB symbols. `TribeBuildAIModule::cancelBuildItem` already uses the corresponding literals for half-size and two-tile bounds. |
| `DAT_00575268` | removed | The original read-only `6.5f` has no source reference. `TRIBE_Action_Repair::setup` already uses the literal save-version threshold. |
| `DAT_0057526c` | named | The original read-only `2.0f` is subtracted from repair distance before range checks. The new `g_repair_distance_offset` name describes that role. |
| `DAT_00575270` | named | The original read-only `0.4` double is the repair distance threshold. The new `g_repair_distance_threshold` name describes that role. |
| `DAT_00575278` | removed | The original read-only `0.0f` has no source reference. The repair update path uses the literal zero threshold. |
| `DAT_0057527c` | removed | The original read-only `-0.5f` has no source reference. `meet_target` uses the corresponding literal coordinate offset. |
| `DAT_00575150` | named | This read-only zero is used by hunt actions to test whether a unit carries any amount. The new `g_hunt_empty_amount` name states that role. |
| `DAT_00575168` | named | This read-only `1.0` double is the hunt action's distance threshold for a drop target. The new `g_hunt_drop_distance_threshold` name states that role. |
| `DAT_0057518c` | removed | The original read-only `7.23f` has no source reference. `TRIBE_Action_Make_Obj` already uses the literal save-version threshold. |
| `DAT_00575190` | named | This read-only negative epsilon adjusts make-object placement radii. The new `g_make_obj_radius_adjustment` name describes its use without changing its sign. |
| `DAT_00575198` | named | This read-only scale converts the random integer to a placement fraction in `TRIBE_Action_Make_Obj::place_obj`. |
| `DAT_0057519c` | removed | The original read-only `4.0f` has no source reference. `place_obj` already uses the corresponding literal expansion factor. |
| `DAT_005751a0` | named | This read-only `100.0f` converts make-object work into a percentage in `get_info`. The new `g_make_obj_progress_percent` name states that role. |
| `DAT_00575000` | named | This read-only `4.0f` multiplies conversion chance for the special player branch. The new `g_conversion_special_player_factor` name states that role. |
| `DAT_00575004` | named | This read-only `8.0f` multiplies conversion chance for selected object groups. The new `g_conversion_special_group_factor` name states that role. |
| `DAT_00575070` | named | This read-only zero is the discovery-artifact timer threshold. The new `g_discovery_artifact_timer_threshold` name states that role. |
| `DAT_00575078` | named | This read-only `1.0f` adjusts the lower discovery-artifact scan bounds. The new `g_discovery_artifact_scan_lower_adjustment` name replaces the source-local DAT label. |
| `DAT_0057507c` | named | This read-only `-1.0f` adjusts the upper discovery-artifact scan bounds. The new `g_discovery_artifact_scan_upper_adjustment` name states that role. |
| `DAT_005750e0` | named | This read-only `0.1f` is the healing attribute threshold before work is scaled. The new `g_heal_attribute_threshold` name states that role. |
| `DAT_005750e8` | named | This read-only `0.5` double is the minimum healing distance threshold. The new `g_heal_distance_threshold` name states that role. |
| `DAT_00574524` | named | This read-only zero is used by the spawn panel when it checks for a held attribute. The new `g_spawn_panel_empty_attribute_amount` name states that role. |
| `DAT_00574528` | named | This read-only zero double is compared with a sprite's accumulated delta time. The new `g_sprite_zero_delta_time` name states that role. |
| `DAT_0057473c` | named | This read-only `100.0f` scales health to a percentage in `RGE_Static_Object::check_damage_sprites`. |
| `DAT_00574740` | named | This read-only random scale converts damage-sprite placement values to fractions. |
| `DAT_00574748` | named | This read-only `3.0f` sets the lower object-bounds adjustment. |
| `DAT_0057474c` | named | This read-only `-3.0f` sets the upper object-bounds adjustment. |
| `DAT_00574718`, `DAT_00574724` through `DAT_00574738`, `DAT_00574744`, `DAT_00574750`, `DAT_00574758`, and `DAT_00574764` through `DAT_00574774` | removed | These read-only constants have no source references or PDB symbols. Their owners now use compiler literals or unrelated reviewed constants. |
| `DAT_005749e0` | removed | The original read-only `7.21f` has no source reference. Building-object loading already uses the literal save-version threshold. |
| `DAT_005749e8` | named | This read-only `0.001` double is subtracted from the upper tile coordinate before map writes. The new `g_build_tile_coordinate_epsilon` name states that role. |
| `DAT_005749f0` | removed | The original read-only `0.01f` has no source reference. |
| `DAT_005749f4` | named | This read-only zero is used for building HP and attribute checks. The new `g_building_zero_hp` name states its main role. |
| `DAT_005749f8` | named | This read-only `0.5` double scales the refund percentage in `cancel_build`. |
| `DAT_00574a00` | named | This read-only `1.0` double clamps the refund percentage and supplies the building one-point HP threshold. |
| `DAT_00574a08` | named | This read-only `1.0f` supplies the normal building minimum damage amount. |
| `DAT_00574a0c` | removed | The original read-only `100.0f` has no source reference. The progress calculation uses the direct literal. |
| `DAT_00574a10` | named | This read-only `0.1` double detects very small damage for selected building groups. |
| `DAT_00574a18` | named | This read-only `0.1f` is applied as minimum damage for those groups. |
| `DAT_00574c78` | named | This read-only `1.0f` is the combat object's one-point attribute and damage threshold. |
| `DAT_00574c7c` | named | This read-only `-1.0f` adjusts combat-object player attributes during setup. |
| `DAT_00574c88` | named | This read-only `1.0` double gates combat damage handling and one-point HP checks. |
| `DAT_00574c98` | named | This read-only zero controls combat-object step and distance comparisons. |
| `DAT_00574ca0` | named | This read-only `-0.5f` adjusts combat-object tile-center coordinates. |
| `DAT_00574ca4` | named | This read-only negative two-pi value normalizes negative angles in cliff checks. |
| `DAT_00574ca8` | named | This read-only zero double gates area attacks with no effect range. |
| `DAT_00574f08` | named | This read-only zero double is the artifact action timer threshold. |
| `DAT_00574f10` | named | This read-only `1.0f` adjusts the lower artifact ownership scan bounds. |
| `DAT_00574f14` | named | This read-only `-1.0f` adjusts the upper artifact ownership scan bounds. |
| `DAT_00574ffc` | named | This read-only random scale converts conversion chance values to fractions. |
| `DAT_00574c80`, `DAT_00574c90`, `DAT_00574c94`, `DAT_00574c9c`, `DAT_00574f78`, `DAT_00574ff0`, and `DAT_00574ff8` | removed | These read-only constants have no source references or PDB symbols. Their owners use direct literals or do not need the separate storage. |
| `DAT_00573ae8`, `DAT_00573aec`, `DAT_00573af0`, and `DAT_00573af8` | removed | These read-only action and scenario constants have no source references or PDB symbols. Their owners use direct literals. |
| `DAT_00572138` through `DAT_0057217c` | removed | These ten read-only scenario-version constants have no source references or PDB symbols. `RGE_Scenario` uses source literals, including `1.15f` in `Get_Version`. |
| `DAT_00572968` | named | This read-only `0.001f` scales elapsed time for scroll-panel movement. The new `g_scroll_time_scale` name states that role. |
| `DAT_00572970`, `DAT_00572978` | removed | These read-only zero constants have no source references or PDB symbols. The fade step code uses direct zero comparisons. |
| `DAT_0057297c` | named | This read-only `100.0f` scales fade progress. The new `g_fade_progress_scale` name states that role. |
| `DAT_00572ce0`, `DAT_00572ce8` through `DAT_00572cf8` | removed | These read-only game-speed constants have no source references or PDB symbols. Their owners use direct literals or separate state values. |
| `DAT_00572ce4` | named | This read-only zero is the no-area-effect range check in script game updates. The new `g_no_area_effect_range` name states that role. |
| `DAT_00570418` | named | This read-only `7.06f` value gates the doppleganger `CantSeeBits` save field. |
| `DAT_00570440` | removed | The original read-only `-1.0f` has no source reference. The fractal circle code uses the direct literal. |
| `DAT_00570484` | named | This read-only `6.92f` value gates the master action move-sound save field. |
| `DAT_00570500` | named | This read-only `7.01f` value gates the master combat save fields. |
| `DAT_00570504` | named | This read-only zero initializes the base damage ability total. |
| `DAT_00570508` | named | This read-only zero double is the positive damage-difference threshold. |
| `DAT_00570510` | named | This read-only `1.0` double is the minimum total threshold for base damage ability. |
| `DAT_00570518` | named | This read-only `1.0f` is the fallback base damage ability total. |
| `DAT_00570610` | named | This read-only `7.04f` value gates static-object outline fields during loading. |
| `DAT_00570614` | named | This read-only `7.12f` value gates the static-object copy ID during loading. |
| `DAT_00570618` | named | This read-only zero float is used by static-object radius, terrain, and distance checks. |
| `DAT_0057061c` | named | This read-only coordinate epsilon trims static-object placement bounds. |
| `DAT_00570620` | named | This read-only zero double is used by static-object map and radius checks. |
| `DAT_00570628` | named | This read-only `3.0f` sets the lower static-object placement bounds. |
| `DAT_0057062c` | named | This read-only `-3.0f` sets the upper static-object placement bounds. |
| `DAT_005706a8` | named | This read-only `7.0f` value gates the modern map save format. |
| `DAT_005706ac` | named | This read-only zero marks a terrain animation interval with no pause frames. |
| `DAT_005706c0` | named | This read-only `0.5` double is the tile-map half-unit. |
| `DAT_005706d0` | named | This read-only `-0.5` double supplies the tile-map diagonal sign. |
| `DAT_005706d8` | named | This read-only `1.0` double supplies the tile-map unit span. |
| `DAT_005706e8` | named | This read-only `0.001f` scales map world time. |
| `DAT_00570934` | named | This read-only zero is used by missile map and collision checks. |
| `DAT_00570938` | named | This read-only `3.0f` sets the lower missile collision bounds. |
| `DAT_0057093c` | named | This read-only `-3.0f` sets the upper missile collision bounds. |
| `DAT_00570940` | named | This read-only negative tenth adjusts missile vertical collision bounds. |
| `DAT_00570630`, `DAT_00570634`, `DAT_00570638`, `DAT_00570648`, `DAT_00570654`, `DAT_0057065c`, `DAT_00570664`, `DAT_0057066c`, `DAT_005706b0`, `DAT_005706b4`, `DAT_005706ec`, and `DAT_00570930` | removed | These read-only values have no source references or PDB symbols. Their owners use direct literals or do not need separate storage. |
| `DAT_00570b40`, `DAT_00570b68`, `DAT_00570b70`, and `DAT_00570b78` | named | These read-only full-circle, pi, and inverse-full-circle values support moving-object angle conversion. Their new names state the numeric role and type. |
| `DAT_00570b48`, `DAT_00570b4c`, and `DAT_00570b50` | named | These read-only zero and two-pi values bound moving-object angles. |
| `DAT_00570b54`, `DAT_00570b58`, and `DAT_00570b5c` | named | These read-only values gate moving-object save fields at versions `1.3`, `7.22`, and `7.23`. |
| `DAT_00570b60` and `DAT_00570b64` | named | These read-only one and negative-one values adjust moving-object facet deltas. |
| `DAT_00570b7c`, `DAT_00570b80`, `DAT_00570b84`, `DAT_00570b88`, and `DAT_00570b90` | named | These read-only half, time, quarter-pi, and tile-center values support movement and facet calculations. |
| `DAT_00570b98`, `DAT_00570ba0`, `DAT_00570ba8`, and `DAT_00570bd8` | named | These read-only zero, waypoint-distance, radius-adjustment, and close-waypoint values control movement range checks. |
| `DAT_00570bb0`, `DAT_00570bb8`, `DAT_00570bc8`, and `DAT_00570bd0` | named | These read-only turn-delta bounds control trivial movement and facet correction. |
| `DAT_00570bc0`, `DAT_00570be0`, `DAT_00570bf0`, `DAT_00570bfc`, and `DAT_00570c00` | named | These read-only speed-offset, facet-angle, and angle-tolerance values control movement speed and facet selection. |
| `DAT_00570c20` | named | This read-only `-10000.0f` value scales music fade volume. The new `g_music_fade_volume_scale` name states that role. |
| `DAT_00570c24`, `DAT_00570c28`, and `DAT_00570c30` | removed | These read-only values have no source references or PDB symbols. Music code uses its own constants. |
| `DAT_00571e50`, `DAT_00571e54`, `DAT_00571e58`, `DAT_00571e5c`, and `DAT_00571e60` | named | These read-only random-map path cost and vertical heuristic adjustments now use `g_rmm_path_*` names. |
| `DAT_00571ed0` | named | This read-only two-thirds value scales random-map octagon area. |
| `DAT_00571f20`, `DAT_00571f28`, `DAT_00571f30`, `DAT_00571f38`, and `DAT_00571f40` | named | These read-only random-map area and tile-ratio factors now use `g_rmm_*` names. |
| `DAT_00571f48`, `DAT_00571f4c`, `DAT_00571f50`, and `DAT_00571f54` | named | These read-only elevation-module random scale values now use `g_rmm_elevation_*` names. |
| `DAT_00571ce8`, `DAT_00571e4c`, `DAT_00571e70`, `DAT_00571e78`, `DAT_00571e80`, `DAT_00571ea8`, `DAT_00571eac`, `DAT_00571eb0`, `DAT_00571eb8`, `DAT_00571ec0`, and `DAT_00571edc` | removed | These read-only values have no source references or PDB symbols. Random-map owners use direct literals or do not need separate storage. |
| `DAT_0056f49c` | named | This read-only `1.0f` is the default combat attack modifier and the long-range weapon threshold. |
| `DAT_0056f4a0` | named | This read-only zero double gates area attacks and positive damage accumulation. |
| `DAT_0056f4a8` | named | This read-only zero float supplies combat area distances and the initial damage total. |
| `DAT_0056f4ac` | named | This read-only `-6.0f` adjusts missile weapon range. |
| `DAT_0056f4d8` | named | This read-only `8.0` double limits the compact command-group extent. |
| `DAT_0056f4e0` | named | This read-only zero double gates command coordinate and target-radius checks. |
| `DAT_0056f4e8` | named | This read-only `1.0f` adjusts command map upper bounds. |
| `DAT_0056f880` | named | This read-only `100.0f` scales the diplomacy attribute for display. |
| `DAT_0056f014`, `DAT_0056f018`, `DAT_0056f020`, `DAT_0056f028`, `DAT_0056f030`, `DAT_0056f034`, `DAT_0056f210`, `DAT_0056f218`, `DAT_0056f498`, `DAT_0056f4b0`, `DAT_0056f4b8`, `DAT_0056f4bc`, `DAT_0056f4f4`, `DAT_0056f4f8`, `DAT_0056f4fc`, `DAT_0056f500`, `DAT_0056f5fc`, `DAT_0056f604`, `DAT_0056f608`, `DAT_0056f740`, `DAT_0056f744`, `DAT_0056f748`, `DAT_0056f74c`, `DAT_0056f884`, `DAT_0056f888`, `DAT_0056f890`, and `DAT_0056f894` | removed | These read-only values have no source references or PDB symbols. Their owners use direct literals or do not need separate storage. |
| `DAT_0056e0cc` | named | This read-only `-0.3f` adjusts the attack radius distance. |
| `DAT_0056e278` | named | This read-only zero float is the gatherer's positive carried-amount threshold. |
| `DAT_0056e290` | named | This read-only `1.0` double limits the gather drop-off distance. |
| `DAT_0056e380` | named | This read-only `0.5f` supplies the missile half-time and average-velocity factors. |
| `DAT_0056e388` | named | This read-only zero double gates positive missile speed and ballistic ratio. |
| `DAT_0056e390` | named | This read-only `1.0f` limits special missile target-speed normalization. |
| `DAT_0056e394` | named | This read-only zero float is the missile minimum-speed fallback. |
| `DAT_0056e6c8`, `DAT_0056e6cc` | named | These read-only coordinate adjustments bound transport terrain checks. |
| `DAT_0056e0b8`, `DAT_0056e0d0`, `DAT_0056e138`, `DAT_0056e1a0`, `DAT_0056e1a4`, `DAT_0056e1a8`, `DAT_0056e210`, `DAT_0056e318`, `DAT_0056e400`, `DAT_0056e418`, `DAT_0056e63c`, `DAT_0056e640`, `DAT_0056e644`, `DAT_0056e648`, `DAT_0056e6c0`, `DAT_0056e784`, `DAT_0056e788`, `DAT_0056e80c`, `DAT_0056e810`, `DAT_0056ebb8`, and `DAT_0056ebbc` | removed | These read-only values have no source references or PDB symbols. Their owners use direct literals or do not need separate storage. |
| `DAT_0056ebc0` | named | This read-only `100.0f` scales distance-based unit-AI priority and base damage. |
| `DAT_0056ebc4` | named | This read-only `0.01f` scales the high-difficulty reaction distance. |
| `DAT_0056ebc8` | named | This read-only zero float gates unit-AI damage, distance, and coordinate checks. |
| `DAT_0056ebd0` | named | This read-only `1.0f` adjusts unit-AI map upper bounds and the minimum target hit-point test. |
| `DAT_0056ebd4` | named | This read-only `-1.0f` adjusts the unit-AI weapon-range test. |
| `DAT_0056ebd8` | named | This read-only `50.0f` scales target damage capability in unit-AI threat estimates. |
| `DAT_0056ebdc` | named | This read-only `0.5f` scales distance for multi-attacker threat estimates. |
| `DAT_0056ebe0` | named | This read-only `-5.0f` adjusts the unit-AI resource line-of-sight limit. |
| `DAT_0056ebe4` | named | This read-only `-0.5f` adjusts unit-AI coordinate samples. |
| `DAT_0056ebf4` | named | This read-only `-2.0f` adjusts unit-AI desired target distance. |
| `DAT_0056ec00`, `DAT_0056ec08` | named | These read-only `-1.0` and `1.0` doubles bound unit-AI target-coordinate changes. |
| `DAT_0056ee78` | named | This read-only `0.001` double is the minimum sprite animation interval. |
| `DAT_0056ee80` | named | This read-only scale converts random values to sprite frame time. |
| `DAT_0056ebec`, `DAT_0056ebf8`, `DAT_0056ebe8`, `DAT_0056ee00`, and `DAT_0056ee88` | removed | These read-only values have no source references or PDB symbols. Their owners use direct literals or do not need separate storage. |
| `DAT_00575348` | named | This read-only zero float gates carried trade goods and source-player resource checks. |
| `DAT_00575350` | named | This read-only zero double gates trade action timers and invalid pickup coordinates. |
| `DAT_00575358` | named | This read-only factor converts squared pickup distance to a trade modifier. |
| `DAT_0057535c` | named | This read-only scale adjusts the distance-based trade modifier. |
| `DAT_00575360` | named | This read-only `0.35f` supplies the initial and minimum trade transfer modifier. |
| `DAT_00575368` | named | This read-only `0.35` double is the trade modifier threshold. |
| `DAT_00575370` | named | This read-only `75.0f` caps a trade transfer amount. |
| `DAT_005753d8` | removed | This read-only value has no source references or PDB symbols. |
| `DAT_005758b0` | named | This read-only `3.0f` scales generic AI evasive movement and ranged rate-of-fire movement. |
| `DAT_005758bc` | named | This read-only `1.0f` is the soldier AI range and evasive-distance threshold. |
| `DAT_005758c0` | named | This read-only `2.0f` is the soldier AI fallback coordinate offset. |
| `DAT_005758c4` | named | This read-only zero float gates ranged and priest AI retreat movement. |
| `DAT_005758d8` | named | This read-only `7.0f` scales fishing-ship evasive movement. |
| `DAT_005758dc` | named | This read-only `4.0f` offsets soldier AI random evasive coordinates. |
| `DAT_005758e0` | named | This read-only `10.0f` selects the soldier AI coordinate fallback. |
| `DAT_005758e4` | named | This read-only `-2.0f` adjusts soldier AI fallback coordinates. |
| `DAT_005758b4`, `DAT_005758b8`, `DAT_005758c8`, `DAT_005758cc`, `DAT_005758d0`, and `DAT_005758d4` | removed | These read-only values have no source references or PDB symbols. |
| `DAT_00570e40` through `DAT_00570e80` | named | These read-only path constants control zero values, diagonal distance, action range, coordinate scaling, bounds, rounding, and terrain passability. The new `g_path_*` names state those roles. |
| `DAT_00570e88`, `DAT_00570e98`, `DAT_00570ea0`, `DAT_00570ea8`, `DAT_00570eb0`, `DAT_00570eb8`, and `DAT_00570ec8` | removed | These read-only path and player values have no source references or PDB symbols. Their owners use direct literals or separate state values. |
| `DAT_00570e90` | named | This read-only `4.01f` value gates the player allied-LOS save field. |
| `DAT_00570ec0` | named | This read-only `7.09f` value gates the player doppleganger-list save field. |
| `DAT_00570ec4` | named | This read-only zero rejects empty player attribute commands. |

## Related duplicate storage

| Symbol | Result | Evidence |
| --- | --- | --- |
| `g_time` | removed | `g_time` and `save_game_version` both modeled original address `0x0058EBCC` with initial value `7.23f`. `TribeMainDecisionAIModule` uses the value for conditional save-file reads. Source now uses the canonical `save_game_version` owner. |

## Validation

No build or test ran for this milestone. The active cleanup workflow defers them to final validation.
