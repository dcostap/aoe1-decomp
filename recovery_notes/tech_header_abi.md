# tech.h ABI evidence

`tech.h` owns TRIBE_Tech and TRIBE_Player_Tech.

The PDB type dumps prove both complete field layouts. Their short-field gaps
use natural alignment. The header has no explicit pads or foreign owner type.

`TRIBE_Tech` has size `0x0C`. `TRIBE_Player_Tech` has size `0x10`.
The latter is non-polymorphic.

`check_for_new_tech()`, `enable(short)`, and `disable(short)` support current
callers. The executable proves their direct targets.

## Sources

- `inventory/types/dumps/TRIBE_Tech.txt`
- `inventory/types/dumps/TRIBE_Player_Tech.txt`
- `inventory/functions/0051/00513DA0_tech_abling.txt`
- `inventory/functions/0050/0050CE68_check_for_new_tech.txt`
