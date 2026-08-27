# Act Attack AIUA owner blocker

Act Attack stays held.

`UnitAIModule::currentOrder() const` owns VA `00413920`. Its decorated symbol
is `?currentOrder@UnitAIModule@@QBEHXZ`. The body reads `+0x28` and returns.

`include/act_atak_context.h` declares a partial non-const method. The matching
and scratch Act Attack sources therefore target
`?currentOrder@UnitAIModule@@QAEHXZ`. That is not the canonical direct target.

Relocation masking can hide this target mismatch in byte comparisons. It does
not prove exactness.

Do not add a method-only declaration or a partial Unit AI layout. Act Attack
must consume a genuine AIUA owner header after ManagedArray ABI fanout passes.

The current broad `include/aiuaimod.h` surface collides with foreign owners in
the Act Attack compiler context. Do not consume it. Keep this work held until
the owner-only AIUA header lands after the ManagedArray ABI fanout passes.

When the gate reopens, direct validation must require the canonical target and
relocation identity. A byte `MATCH` alone is not sufficient.
