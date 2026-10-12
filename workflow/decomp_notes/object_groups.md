# Master-object group names

`include/m_s_obj.h` names the `RGE_Master_Static_Object::object_group` values with
`OBJECT_GROUP_*` macros. Groups that were not named before have new names in this pass. Each
name describes what the group contains in the pinned `XPack/data2/empires.dat`. These are cleanup
labels; they are not developer names.

| Value | Macro | empires.dat members |
| --- | --- | --- |
| 0 | `OBJECT_GROUP_ARCHER` | Soldier-Archer1-3, Hero_Spy, Hero_Tower |
| 5 | `OBJECT_GROUP_FISH` | Fish-tuna, Fish-Salmon, shore fish, Fish_Whale |
| 6 | `OBJECT_GROUP_INFANTRY` | Soldier-Inf1-6 and infantry heroes |
| 7 | `OBJECT_GROUP_FORAGE` | Forage-Fruit |
| 0x0C | `OBJECT_GROUP_CAVALRY` | Soldier-Cavalry1-3, Scout, Camel, cavalry heroes |
| 0x0D | `OBJECT_GROUP_SIEGE_WEAPON` | Balista, Catapult1-3, Hero_Catapult |
| 0x0E | `OBJECT_GROUP_TERRAIN` | Terrain_Path_*, Shallows, cactus, bones |
| 0x10 | `OBJECT_GROUP_TREE_STUMP` | Tree_Stump1-3 |
| 0x17 | `OBJECT_GROUP_CHARIOT_ARCHER` | Soldier-Chariot2 |
| 0x18 | `OBJECT_GROUP_WAR_ELEPHANT` | Soldier-Elephant, Armor_Elephant, Hero_Hannibal |
| 0x19 | `OBJECT_GROUP_HERO` | Hero-Perseus, Xerxes, Tiberius, Jason, Archimedes |
| 0x1A | `OBJECT_GROUP_ELEPHANT_ARCHER` | Soldier-El_Archer |
| 0x1C | `OBJECT_GROUP_PHALANX` | Soldier-Phal1-3 |
| 0x1D | `OBJECT_GROUP_TRAINED_LION` | Lion_Trained |
| 0x1E | `OBJECT_GROUP_FLAG` | Flag, Flag_B |
| 0x23 | `OBJECT_GROUP_CHARIOT` | Soldier-Chariot1, Hvy_Chariot |
| 0x24 | `OBJECT_GROUP_HORSE_ARCHER` | Soldier-Cavalry3_Arch, Cavalry4, Hero_Horse_Archer |
| 0x25 | `OBJECT_GROUP_DOPPLEGANGER` | Doppleganger |
| 0x27 | `OBJECT_GROUP_SLINGER` | Soldier-Slinger |

These values stay numeric:

- Group 11 has 71 members: missiles, rubble, corpses, smoke, and flares. `RGE_Master_Static_Object`
  marks the group as recyclable. No single short name covers it.
- Groups 0x11, 0x1F, 0x21, and 0x26 have no members in the file. The AI still tests 0x1F and 0x21
  next to fish (for example, `importantResource` and the fishing-ship code), so they are probably
  water-resource groups. The data does not prove this.

## Where the names are used

The names are used only where the compared value is provably an object group. Each case was
checked by reading the field or parameter, such as `master_obj->object_group`,
`importantObjectMemory[i].group`, the `oGroup` parameter of `mostDamaged`, the `importantUnit`,
`importantResource`, and `importantMisc` arguments, `importantWhenDead`,
`canAttackUnitAtNeutrality`, and `convertToLOSResourceType`.

These look like group checks but are not:

- The second argument of `closestObject` is `desiredRelation`, not a group.
- `checkGroup` in the `taitacmd.cpp` civilian tasking is a mode flag.
- Many locals named `group` in `taitacmd.cpp`, `taipbook.cpp`, and `scr_game.cpp` are
  `TacticalAIGroup` pointers.
- In `TribeInformationAIModule::findClosestDropsite`, the local named `group` holds
  `master_obj->id`. Its values are master IDs: Town Center, Storage Pit, and Granary. The food
  resources Forage-Fruit and Farm go to the Granary. The code now uses those names.

`TRIBE_Action_Convert` in `tact_cnv.cpp` also tests master IDs. Those IDs are
now named: Town Center, Artifact, both ruins, and Wonder.

Validation: a full translation-unit audit kept all 5,013 exact claims. 224 of 225 object payloads
equal the baseline. The one difference is `rmm_tdbc.obj`, from the earlier include change recorded
in `master_object_ids.md`.
