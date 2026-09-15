# Source comments

Guidance for the source-cleanup pilot and later wave. Read this with [source cleanup](source_cleanup.md).

## Main rule

Add comments sporadically, where they answer a useful question.
Do not document every function, parameter, field, branch, or literal.
A module can need no new comments.

Explain behavior that names and types cannot explain clearly:

- An unexpected dependency or processing order.
- Ownership, lifetime, units, or a special value that callers could misunderstand.
- A confirmed original bug or a required compatibility constraint.
- A non-obvious algorithm, table, or important data structure.

Do not narrate statements. Do not add comments to meet a quota.

```cpp
struct Position {
    float x;
    float y;
};
```

These fields need no comments that merely say “X position” and “Y position.”
Document the coordinate space or units only when that distinction matters and evidence establishes it.

## Ordinary explanations: `//`

Use a short nearby comment for local behavior or a constraint.
Prefer an explanation of why, rather than a translation of the next statement.

For example, `RGE_Base_Game::get_string(long)` returns a shared buffer in `src/basegame.cpp`:

```cpp
// The next get_string(long) call overwrites this shared buffer.
```

That explains a lifetime constraint. A comment such as “Get the string” does not help.

Use trailing comments only for short facts. Do not align unrelated declarations by changing large sections of whitespace.

## Important interfaces and concepts: `/** ... */`

Use a documentation block only when the concept needs one.
Good candidates include a central data structure, an unusual interface contract, or a substantial algorithm.

Start with one useful sentence. Add detail only when needed.
Use tags such as `@param[out]`, `@return`, `@note`, or `@warning` selectively.
Do not add a tag for every parameter.

Illustrative form, not a claim about a particular repository function:

```cpp
/**
 * Finds the floor below the query point.
 *
 * @param[out] surface Receives the selected surface, or null when none exists.
 * @return The floor height, or the documented no-floor sentinel.
 */
```

A routine with obvious arguments and results does not need this block.
Do not add author banners, dates, change histories, or a Doxygen setup as part of cleanup.

## Unusual original behavior: `//!`

Reserve this marker for facts that deserve special attention.
Examples include a confirmed original bug, a surprising width conversion, or an established compiler constraint.
Repeat `//!` on each continuation line.

Illustrative form:

```cpp
//! @bug When index equals count, this reads one entry past the array.
//! Preserve the original comparison.
```

Use lowercase `@bug` only when evidence proves the defective behavior.
A surprising expression alone does not prove a bug.
When useful, state the trigger, effect, and limits on whether the code can reach it.
Do not silently repair the behavior while documenting it.

Use `//!<` only for a rare trailing declaration note that needs documentation treatment.
Ordinary fields do not need it.

## Facts, hypotheses, and evidence

State observed behavior first. Do not present guessed intent as recovered fact.

Prefer a precise fact:

```cpp
// This path uses a larger search radius than the preceding path.
```

Avoid unsupported claims:

```cpp
// The original developers forgot to use the correct radius.
```

Do not add speculative comments throughout the source.
Put unresolved interpretations and research questions in the module report.
A useful uncertainty note can remain near the code when readers must know that limit.

Preserve existing accurate evidence notes and reviewed bug comments.
If a comment is wrong, record the evidence for correcting it in the report.
Do not delete it merely because it looks unusual.

A compiler note must identify the real constraint and its evidence.
Do not invent matching claims during a wave that defers compiler checks.
Avoid comments such as “VC5 needs this” without an existing supporting result.

## Writing and formatting

- Use short sentences and active voice.
- Use one term for one idea.
- Match the module's surrounding indentation and line endings.
- Keep comments close to the code they explain.
- Do not paste decompiler output, disassembly dumps, or long investigation histories into source comments.
- Keep detailed evidence in durable notes or the cleanup report.
- Do not replace fixed debug paths or original debug line numbers with `__FILE__` or `__LINE__`.

Comments can affect builds that use line-dependent macros. Do not assume every comment edit is byte-neutral.

## Inspiration

This guide adapts the SM64 patterns described in the user-supplied September 15 comment-style study.
That study inspected SM64 commit `9921382a68bb0c865e5e45eb594d9c64db59b1af`.
The patterns are useful conventions, not a formal SM64 policy or recovered Age of Empires style.

We adopt sparse explanations, selective documentation blocks, and explicit notes for important original behavior.
We do not adopt blanket function documentation, comment quotas, or an unrelated repository's formatter settings.
