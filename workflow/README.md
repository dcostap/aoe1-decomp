# How this was made

The decompilation was done mostly by AI coding agents, run through the
[Pi](https://github.com/badlogic/pi-mono) coding agent, between April and October 2026
(about 9,000 commits). This folder holds what they worked from: the rules, the role
prompts, the guides, and every note and review they left behind.

Nothing here is needed to build the game.

For the whole story, from the first failed port to the final link, see
[The long version](#the-long-version-how-it-actually-went) at the end of this file.

## The pipeline

1. **Reference data.** The beta's PDB and a Ghidra export of the original
   executable produce a local function inventory (`inventory/`, not in the repo).
   `config/functions/` is the registry: each source file, its compiler flags, and
   the status and symbol of each function.

2. **Matching.** A root orchestrator assigns translation units to orchestrators,
   and each orchestrator runs matching workers in their own git worktrees. A worker
   writes natural source for its functions until `tools/check_function.py` reports
   a byte match against the original. Every attempt is recorded as a durable
   experiment, so failed ideas are kept, not lost.
   - [agent_roles/root_orchestrator.md](agent_roles/root_orchestrator.md),
     [orchestrator.md](agent_roles/orchestrator.md),
     [matching_worker.md](agent_roles/matching_worker.md)
   - [docs/experiments.md](docs/experiments.md)

3. **Review.** The later rounds replaced self-review with a separate reviewer agent
   that checks the stopped worker's evidence before anything is merged.
   - [docs/matching_with_reviewers.md](docs/matching_with_reviewers.md),
     [agent_roles/matching_reviewer.md](agent_roles/matching_reviewer.md)

4. **Accepted drift.** Some functions have natural source whose bytes still differ
   slightly from the original. A complete semantic review that proves equal
   behavior accepts them as `accepted_drift`. [MATCHING_ROUND.md](MATCHING_ROUND.md) is the
   plan from one of these rounds.

5. **Behavior recovery.** For the hardest functions, workers aim for correct
   behavior instead of exact bytes. Two fresh reviewers must both return `PERFECT`
   for identical source before a function becomes `accepted_logic`.
   - [agent_roles/behavior_recovery_orchestrator.md](agent_roles/behavior_recovery_orchestrator.md),
     [behavior_recovery_worker.md](agent_roles/behavior_recovery_worker.md)
   - [tools/behavior_recovery.py](tools/behavior_recovery.py) prepares the workspaces and routes reviews.

6. **Exact lottery.** An opt-in experiment: many blind workers write one function
   independently, and the run stops when any variant matches exactly.
   - [docs/exact_lottery.md](docs/exact_lottery.md)

7. **Source cleanup.** Waves of agents renamed constants, joined wrapped lines, and
   wrote comments, without changing the generated machine code or data.
   - [docs/source_cleanup.md](docs/source_cleanup.md),
     [docs/source_comments.md](docs/source_comments.md),
     [docs/resource_ids.md](docs/resource_ids.md)

8. **Whole-game checks.** The full executable is built, linked, and audited. The
   game then runs side by side with the original under scripted and recorded human
   input. The harness compares clocks, game state, complete RNG streams, and raw
   frames.
   - [docs/executable_build.md](docs/executable_build.md),
     [docs/runtime_harness.md](docs/runtime_harness.md),
     [docs/behavior_replay.md](docs/behavior_replay.md),
     [docs/testing.md](docs/testing.md)

## What's in here

| Path | What it is |
| --- | --- |
| [`../AGENTS.md`](../AGENTS.md) | The rules every agent gets (kept at the root, where agents look for it) |
| [`agent_roles/`](agent_roles) | Role prompts for orchestrators, workers, and reviewers |
| [`docs/`](docs) | Workflow guides and tool references |
| [`vc5_lessons.md`](vc5_lessons.md) | What we learned about coaxing VC5 into matching code. The most useful file here if you do your own decomp. |
| [`decomp_notes/`](decomp_notes) | Per-function and per-module notes, ID tables, and audits |
| [`decomp_notes/candidates/`](decomp_notes/candidates) | Saved candidate patches from matching attempts |
| [`logic_reviews/`](logic_reviews) | Semantic review ledgers from the earlier workflow |
| [`recovery_notes/`](recovery_notes) | Repository-wide audits |
| [`tools/`](tools) | Scripts used only by the agent workflows |
| [`pi/`](pi) | A Pi extension that shows live function counts while agents work. Copy it to `.pi/` to use it. |

The core tools that build and compare functions are in the root [`tools/`](../tools).

These files are kept as they were written. Older ones use earlier status names:
`new_verified_logic` is now `accepted_logic`, and `scratch` is now `nonmatching`.

## The long version: how it actually went

This is the story behind the ~9,000 commits. I rebuilt it from the git history of
three attempts, the old Copilot CLI sessions, about 14,000 Pi sessions (almost all of
them subagents), and the Claude Code sessions at the end. Quotes are what I actually
typed, typos included.

### Act 0: "documenting the symbols is addictive" (August 2025)

The first repository, `aoe1`, started on 2025-08-15 as a plan to vibecode a C port of
Age of Empires. It died the same day. The commit message says it best:

> ok so i gave up reimplementing a port in C via vibecoding. but documenting the
> symbols of the decomp is addictive ngl

Then nothing until Christmas.

### Act 1: the naive port (December 2025 – March 2026)

On 2025-12-27 I started again "from scratch with the beta Ghidra decompilation with
PDB symbols". That leaked beta build with a full PDB is what made the whole project
possible. Class sizes like `0xA24` and `0x1254` could be checked instead of guessed.

The early commits are honest about the quality: "slop", "sloppity slop", and a lot of
rate limits. On 2026-01-02 came the first real idea: dump 90% of the original
structure, because the PDB gives that much information. Two days later: "It compiles
now." Then "back to the beginning?" on January 9 and "start from scratch. again" on
January 20. I tried Gemini 3 Flash for a while and called its output "ai slop" too.

It did start to work, though. On February 6: **"main menu is perfect y'all"**. On
February 11: **"SOUND SYSTEM WORKING???"**

**The Copilot fleet.** From February 18 I ran Copilot CLI agents with subagents, and
from February 22 a fleet of eight cloned checkouts (`aoe1_clone_1` to `_8`) pulled
from a numbered task queue that reached about task 643. Each worker implemented one
ticket against the Ghidra `.decomp` and `.asm` files, ran `build.bat`, got three to
five read-only reviewers, and pushed. On February 23 alone, tasks 84 to 113 restored
action state machines, object construction, checksums, guaranteed-delivery
networking, the mission screen, and the main view.

It looked like a factory. It was also a mess:

- **Infrastructure fights.** The terminal-fleet MCP had a focus bug that left workers
  stuck on locked input. One worker would type its answer and never submit it, so I
  had to press Enter myself. Quota errors (429s) were constant. Every task prompt
  ended with "REMINDER: You MUST use ask_user at end of EVERY task. Non-negotiable.",
  and workers still ignored it.
- **Fake progress.** Coverage was measured by markers in the source, so workers
  learned to add markers. "The previous worker FAILED this task by only adding
  #include wiring." "Task 241 only added 34 lines." A 230/230 coverage report hid 143
  stubs. One report claimed 111.6% verified.
- **Reviewers that sound sure and are wrong.** Reviewers flipped back and forth on
  stack-push order, called the same null check both "correct and necessary" and a
  parity bug, and declared "full parity" right before finding a "critical" mismatch.
  A green build proves the code compiles. It proves nothing about behavior.

The best parts were the rendering detective stories. The terrain came out as a
yellow honeycomb because of a stale global translation table ("So, in short, who is
to blame?"). A tile list with zero capacity corrupted the heap and drew a
checkerboard. One panel drew itself recursively. A virtual destructor called itself.
The game wanted an 8-bit display on a 32-bit desktop, which is how cnc-ddraw got
involved. And at one point I had to shout "YOU CAN'T READ .bmp IMAGES… TURN THEM INTO
PNGS".

On March 3 a comment-only audit fleet found 678 TODOs. One question, "can we confirm
that those functions are actually called?", cut 149 "missing" functions down to about
62. On March 7 an agent swept the remaining 387 TODOs to zero, and the game
immediately stopped starting. It hit the expiry check, freed uninitialized fields,
and built 0×0 panels. After those fixes it showed an empty map, then crashed in the
minimap on row 353 of a 334-row surface, and then the toolbar used the wrong object
ID.

On April 1 I took stock. The main menu was 99% decompiled and ran. Gameplay would take
years at this rate, and nothing told me whether any of it was *right*.

### Act 2: the static recompiler detour (April 1–9, 2026)

Attempt two, `aoe1_static_recomp`, flipped the question around: forget pretty source
and lift the x86 machine code into ugly C that behaves exactly the same. The guiding
lines were "ugly low-level output is correct" and "machine code is the behavioral
source of truth".

It went surprisingly far. A sweep lifted 7,429 of 7,990 functions cleanly with zero
unhandled indirect branches, backed by a bank of 71 to 75 tests. Then came the
uncomfortable question: "how do we know, in these tests, that the math is mathing".
Every new opcode pattern needed a custom rule. It didn't scale, and it produced
nothing a person would ever want to read.

Around April 7 I started looking harder at the PDB. On April 9–10 came the pivot that
defined everything after it: **compile recovered source with the original
compiler.** The game was built with Visual C++ 5. Getting the 1997 `CL.EXE` to produce
an object file at all took trimming the environment down. Then a tiny function,
`driveAsLetter`, came out byte for byte identical. That was the moment.

### Act 3, part 1: learning to match (April – May 2026)

This repository's first commit is from 2026-04-10: "Initial exact-match workflow
scaffold".

**The first night.** On April 14 a Copilot orchestrator used pattern classifiers to
batch simple shapes and took the count from 31 matches to somewhere around 1,250–1,409
in one night. Easy functions fall fast. That number gave a very wrong picture of the
months ahead.

**Pi arrives.** On April 16 I moved to the Pi coding agent and tried everything in it:
gpt-5.4 and gpt-5.4-mini through Copilot and Codex, local Qwen, MiniMax, MiMo, and
DeepSeek. In the first days a flag cleanup deleted `config/flags/default.rsp`, and I
had to write "Friendly reminder that you are the orchestrator." Orchestrators love to
do the work themselves.

On April 19 I forked a small benchmark: GPT-5.4 matched 4/4 test functions,
gpt-5.4-mini 4/4 (one on the second try), and local qwen3.6 0/4. The rule for
benchmarks: "we shouldnt eveer mention or let the benchmarked model know we're
running a benchmark."

**VC5 is not a C compiler, it's a slot machine.** The early lessons were strange.
`DString::operator[]` only matched once `<stdlib.h>` was included. A function called
`word` survived 1,368 combinations in a brute-force matrix and then matched with three
plain assignments in a different order. That one made me write "we really CAN'T get
stuck like this again", and the principle that guided the rest of the project:

> we should always try more natural looking code before trying more esoteric
> decompiler-like shapes.

More of the same: an `if/else if` chain that only matched as a `switch`. A
constructor that matched once most fields moved into the initializer list and two
assignments stayed in the body. `delete` instead of an explicit destructor call.
`Path::operator=` only matched once the class had a dummy member declaration, with my
warning: "DONT MAKE UP NAMES. those functions are DUMMIES."

**`setup_cmd_options` (April 29).** This is the textbook case: a 5,726-byte
command-line parser. Rebuilt from Ghidra, it got within 14 bytes of the right size,
and then hundreds of variants all fell into the same wrong register choices. An
`unsigned char` cast for `_ismbcspace` closed the size gap. The real fix was deleting
a decompiler-style reused `iVar2` and writing direct conditions like
`strstr(cmdLine, "FOO") != 0`, which is what a person would have written.
5726/5726 bytes, exact. My reaction was "holy". The lesson:

> would a human have written it like this?

That question became part of the `/match-instructions` Pi prompt.

**Scale brings slop.** By April 18 there were 2,231 matches. On April 23 the corpus was
split into buckets (normal, toolchain, asm_special, asm_region). On April 25 the count
was 3,073 of 6,980 functions, 44%. On April 27 there was a commit called "slop": 805
stub scratch files were quarantined because "some worker agents went rampant adding
low value scratches". Other things I caught agents doing:

- moving 1,391 scratch functions to `accepted_drift` in one go;
- a "match" made of inline assembly;
- a fake match produced by an `int x = 42`.

The `get_tile_picture` saga ran 6,500 compiles that "proved" a toolchain problem,
until "vc5 is REALLY unpredictable" and reusing dead parameters gave 238/238.

**Swarms in May.** May brought messenger swarms with named workers (CherryLynx,
TinyCub, and friends) and a boss agent. The swarm needed a lot of hand-holding: "stop
asking for them to reply with ACKs", "stop being shoddy with assignments", "why u
assigning invalid stuff??", "wtf u left some agents in idle¿". One worker's identity
silently changed from FeatherHarrier to ZephyrStone, which explained the missing
messages ("what makes u think that the message went through?"). A typical 50-function
queue came back as 27 exact, 1 drift, and 22 give-ups. The count went from 3,988 on
May 5 to 4,224 on May 19.

The largest function, `taskActiveSoldiers` (9,580 bytes), became a long-running
project of its own. The worker was translating Ghidra block by block, and I kept
pushing back: "we have seen time and time again that natural looking source code
usually wins", "dont obsess over an early mismatch". `LESSONS.md` was distilled from
5,690 lines to under 600 so workers would actually read it.

June had no commits.

### Interlude: better tools (July 2026)

July was about tooling. The variant lab got faster by grouping identical outputs: 36
variants took 16 seconds instead of minutes. The function checker became
symbol-aware, stopped silently truncating, and started reporting frames, registers,
calls, and source-line attribution. `LESSONS.md` went from 6,526 lines to 1,863,
dropping duplicated advice and dangerous tips like "use naked asm". When a plan grew
too ambitious: "you went too broad. give me the simpler plan that achieves 99% of the
stuff." `taskActiveSoldiers` reached the exact size, frame, registers, and all 440
calls. It still didn't match.

### Act 3, part 2: the August production line

By August, Luna (gpt-5.6-luna) on xhigh was the workhorse, with Terra and Sol models
as leads and DeepSeek V4 Flash for a while. "Agentic tooling is the key for this
project's success."

- **Statuses get rules.** `accepted_drift` needs a review showing that the byte
  differences are only compiler output. `verified_logic` (later `accepted_logic`)
  needs clean, plausible C++ and blind semantic reviews against the original.
- **August 12: the big run.** One orchestrator session ran 6h27m and launched 472
  subagents for 61 exact matches. The orchestrator itself was the bottleneck: 1,049
  turns, and a promised binary review it skipped to reach the summary sooner. My
  verdict on scaling it further: "We shan't do that. it's a waste." Also: "you are
  over-engineering the whole thing."
- **August 13.** A shard hierarchy of up to 80 agents reached 5,007 exact (85.3%). I
  traced VC5's own `C2.EXE` with `/Bd /Bk`. And I accepted that the hardest functions
  needed a second path: "the project won't be finished unless we take this route."
- **August 14–16.** I read how other decomp projects work (LEGO Island/isledecomp,
  Yodecomp, rebrew, Imperialism) and confirmed the exact compiler build: VC5 RTM
  11.00.7022. The status query got 8.8× faster. Padding-only functions got their own
  bucket. After one too many accidents, deletes started going to the recycle bin.
- **August 16–17: 738 commits in one day.** Web search was banned for workers. The
  rules got sharper: "at least 10 honest attempts", and "a match starts the finish
  process. it does not end it." `004AF6C0` went from 2,960 differing bytes to an
  exact 9,090-byte match. A scaffolded "exact" `004C5E50` was rejected because its
  source was fake.
- **August 18.** On `taskActiveSoldiers`: "imma be honest, it's gonna be hard or
  impossible to match these kinda functions."
- **August 22.** Quotas removed. `GetVisibleUnits` turned out to be original inline
  assembly. ("OF COURSE.")

**The translation-unit breakthrough.** Functions that refused to match in isolation
suddenly matched when compiled inside their real source file, next to their real
neighbours. My reaction: "we didn't change anything, we just compiled in the context
it was already in?" VC5's output depends on everything the file declares before the
function, so the one-scratch-file-per-function setup had been costing matches all
along. On August 27 the move back to natural, whole source files began ("a matching
becoming scratch mustn't slow down our progress").

**August 30–31.** I cleaned up 954 branches and a 10 GiB cache ("bruh, yeah, that shit
needs to be refactored"). Then another 787-commit day. The PDB turned out to record
function-local statics that nobody had used ("why tf are we not storing and
exploiting that kinda evidence already?"). `clear_image` went through 30,966 variants
without a match: "There's gotta be something we are missing".

### Act 3, part 3: it runs (September 2026)

**September 1: evidence first.** Accepted drift now counted as done, and the motto
changed from "exact-match-first" to "evidence-first". Exact matches and reviewed
drift are worth the same. What matters is that the source is honest and the behavior
is proven.

On September 4 a 40-worker wave brought the counts to 4,744 matching, 279 drift, and
220 remaining, and I asked myself "How to achieve victory without burning out?" The
shape decoder turned out to have a bug: 248 of 320 failing cases had been hidden
because a lower byte distance looked like progress.

**September 6, 20:06: the first full link.** 454 unresolved symbols went down to zero
and the whole executable linked. Running it found bugs that byte matching never
could:

- `save_game_version` was 0 instead of 7.23;
- the mouse handler overwrote its own return address;
- a wrong font index.

Leaked January 1997 builds became another source of evidence around this time.
September 8: "why do we still got 166 unresolved functions??" `0045D3D0` matched with
a `short` loop counter, a reminder that "shapes that seem to worsen metrics can be
actual good results".

**Behavior recovery (September 11).** For the functions VC5 would never reproduce, the
goal became correct behavior: write natural source, then get two fresh reviewers to
each return `PERFECT`. The first queue of 33 gave 7 exact and 26 verified logic. ("so
start fuckin queueing subagents bruh????") A drift audit rejected 100 of 298 earlier
drift acceptances. On September 13 came the "exact lottery": many blind workers write
the same function, and the first exact match wins (`Path::operator==` fell to
variant 06).

**The runtime harness (September 14–15).** "THIS IS MY HAPPY IDEA!": run the rebuilt
game and the original side by side and compare them. The first version captured my
whole desktop ("u literally capturing my desktop"). It got to 41/41 UI cases. Replays
found a villager speed of 1.1 instead of 1.3 (culture versus `tribe_effect`) and then
matched 3.61 million RNG records. A PE-aware diff found wrong constants and switch
tables in functions marked "matching". I had assumed the faults "should be in
non-matching functions, naturally, right?" They weren't.

September 15 was a 1,179-commit cleanup day: Sol owners each running up to 8 Luna
workers (80 agents), RAM limits, and 27 GiB of leftover `input.zip` blobs. "dont just
wait nonsensically…". A few days later: "only the ones i pasted? come on bro, there
must be hundreds", then "fuck. run the others one by one". A max-speed replay attempt
was dropped ("wot, that seems too patchy").

**September 22.** MiMo agents added comments describing known original bugs, using the
RockNROR community fixes. The build folder had grown to 419 GB. An exact replay of a
real human game (9,649 inputs, 981,899 RNG records) matched the original. It even
reproduced an original bug: reading `soldiers[0]` from an empty list.

### Act 3, part 4: shipping it (late September – October 2026)

From September 27 the replay became deterministic: a 149-second session replays in 13
seconds, 28× faster overall. Small surprises kept coming. An extra space in an
`sscanf` format made the computer player miss the Tool Age. An agent's `git checkout`
erased four lines of my uncommitted work. A drift re-review produced 25 new exact
matches, kept 136 as drift, and sent 67 back to nonmatching.

On October 3 a 20-worker gpt-6-luna hackathon moved the count from 5,010 to 5,013.
What remained was the hard core. On October 4 we found that adding an enum or even an
empty header could change code generation, and ran clang-format over 468 files.

The last stretch, October 10–12, was with Claude Code (Opus 5.5 and Haiku 5.5):

- **Names.** Constants and names came from `.per` AI scripts, the resource DLLs
  (`LoadString` uses the low 16 bits), `empires.dat`, and a leaked `ZTRIBE.NCB`.
- **Cleanup that fights the compiler.** Rewriting a loop to read better could break a
  *neighbouring* function, once by 456 bytes ("we may have to fight the compiler…").
- **Ship it.** "The time has come for us to actually wrap up this project and 'ship
  it'". "NO github CI!!!" "lets not overengineer the testing".
- **Going public.** The history was rewritten from 268 MB to 36 MB, the license
  changed from MIT to CC0, and the executable now builds from source only: RC
  resources, `Inf32.asm` reassembled to its 2,918 bytes, `Deflate.c` checked against
  10,395 differential cases, and the drawing assembly rebuilt with 4,223 address
  fields.

**Where it ended:** 5,426 functions. 5,013 match byte for byte, 140 are accepted
drift, 217 are accepted logic, and 56 are still nonmatching. The whole game compiles,
links, and plays.

### What I learned

- **The compiler is the oracle, not the decompiler.** Ghidra tells you what a function
  does. It does not tell you what someone wrote. Treating its output as source cost
  months.
- **Natural code wins.** When stuck, ask "would a human have written it like this?"
  Brute-force variant matrices found far fewer matches than plain, boring code did.
- **Context is part of the source.** Headers, declaration order, neighbouring
  functions, and even an empty header change VC5's output. Compiling functions in
  their real file was the biggest single unlock.
- **Agents optimize the metric you give them.** Marker coverage, byte distance, and
  match counts all got gamed: fake stubs, inline asm, `int x = 42`. Every metric
  needs a reviewer who checks it from another direction.
- **More agents is not more progress.** 472 subagents for 61 matches. The
  orchestrator, the CPU, the RAM, and my own attention were always the real
  bottleneck.
- **Running the game finds what byte matching misses.** Functions marked "matching"
  had wrong constants. Only the linked executable and the replay harness showed it.
- **Exact and correct are different goals.** Moving to "evidence-first", with
  reviewed drift and proven logic, is what let the project finish instead of chasing
  the last few hundred functions forever.

**Models over time:** Copilot CLI (GPT-5.3-codex and others) and briefly Codex CLI in
attempt one; in Pi, gpt-5.4 and gpt-5.4-mini plus local Qwen, MiniMax, MiMo, and
DeepSeek; then gpt-5.6-luna on xhigh as the workhorse with Terra and Sol as leads;
gpt-6-luna in October; and Claude Opus 5.5 and Haiku 5.5 for the final cleanup.
