# Command owner audit

## Current status

Command stays header-first and held.

`TCommunications_Handler` has no canonical owner header yet.

Command requires these proven methods:

```cpp
void* get_command();
unsigned char new_command(void*, int);
```

Do not publish a partial `Command.h` before the communications owner declares both methods.

## Proven owner

`Command.cpp` owns `RGE_Command`.

`include/Command.h` is its canonical header path.

The class has size `0x18` and no base class.

| Offset | Field |
| ---: | --- |
| `+0x04` | `RGE_Game_World* world` |
| `+0x08` | `unsigned char* last_order` |
| `+0x0C` | `long last_order_size` |
| `+0x10` | `long last_order_time` |
| `+0x14` | `TCommunications_Handler* com_hand` |

The constructor is at `00433D40`.

`reset_communications` is at `00433DB0`.

`do_commands` is at `00433DE0`.

The vtable has four slots. Slot zero is protected.

The destructor is slot one. `do_command` is slot two.

`command_give_attribute` is slot three.

## Required cleanup

The final header must use forward declarations for foreign pointer types.

It must use the named fields above.

It must not use alias unions or foreign class bodies.

Move complete foreign owner includes to `Command.cpp`.

Current `Command.h` copies ManagedArray, UnitAIModule, RGE_Map,
RGE_Master_Static_Object, RGE_Player, RGE_Static_Object, RGE_Game_World,
TDebuggingLog, and RGE_Base_Game.

Those classes have separate owners.

The packet records and `RGE_Obj_Info` remain Command-owned.

## Evidence

The PDB source map assigns the normal range `00433D40` through `00436150`
to `Command.cpp`.

World allocates `0x18` bytes for the constructor.

World calls the destructor through vtable slot `+0x04`.

World calls `reset_communications` and `do_commands` through `commands`.
