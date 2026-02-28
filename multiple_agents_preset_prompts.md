Carefully read @AGENTS.md and carefully follow @multiple_agents_workflow.md. You are now one of the workers.

Mandatory: 
1. to validate your changes, after everything compiles, launch 3 to 5 parallel sub-agents, that receive
    the needed context of the task, and these sub agents ARE READ-ONLY and MUST check all your changes and review
    them, validate their parity with the sources of truth, and finally feed you their feedback. You iterate on the
    feedback until everything is perfect + compiles. 
    **NOTE:** If sub-agent launches fail due to rate limits (429 errors, quota exceeded), that is OK and expected.
    In that case, perform the review pass yourself without sub-agents — read each changed file, compare against
    the decomp source of truth, verify parity, and ensure the build passes. Do NOT let rate-limited sub-agents
    block your progress.
2. Run autonomously, without stopping, until you are finished completely (changes pushed). You only may stop if a major issue or major blocker arises, in which case you explain in simple terms what the
    deal is, to the user. 
     
Your task right now is to...








I ran out of tasks, here are all the tasks i had:



Many other workers are currently working on these tasks. Since you finished yours, and i got no more tasks, I want you to be independent, and explore the codebase and pick a new task yourself. It should be something isolated from the EXISTING tasks i showed you, to not cause
  conflicts. Good luck. Follow the same procedure, just with your own auto-found task.







=== WHEN DEBUGGING AN ISSUE THAT NEEDS RUNNING THE GAME, CLOSED DEBUGGING LOOP FOR AN AGENT ===

your task will be to remain an independent researcher of this issue. you will, on your own, investigate, make changes, build and run the game and then check the outputs, in a closed loop, until you fix the issue. 
The output will consist of runtime logs and generated output images. You will use / implement a screen-capture feature, where we output the screen contents to an image. 
That will let you perform visual verification. For the game runtime to progress to where we want, we implement debug skips / "jump to the part we care about automatically", so no input is needed in the game itself. Good luck.









We have a workflow for parallel agents described in #file:multiple_agents_workflow.md . I have a fleet of up to 10 agents working in parallel. To each of them I feed that multiple_agents_workflow.md file and then the task he has to perform. 
Congratulations, you have a big role to play: you are the project supervisor. You inspect the commits that come from those agents, and update our task list #file:multiple_agents_task_queue.md . You will also need to gain a deep understanding of the entire source code repository, and be able to add and update the tasks. It's very important to choose the right tasks to add, and to scope each task correctly:
- tasks are independent, and the body of the task in that file must contain all the ifno each agent needs: each agent is provided with the task body and nothing else, so they arent aware of the other tasks, so include all info that a task needs to know about in each body. 
- i modify the "assigned to agent" checkbox.
- you modify the completed checkbox whenever an agent worked on the task and pushed its contents, or whenever a task got completed on its own or maybe as a side-effect, or when a task is now obsolete and should be removed. Note that a task requirements may be incomplete, but we still mark it as complete so we can move on (we can then add new tasks that would fullfill the last requirements of this task or fill its holes)
- each task must be a balance of big and small; can't be too small that an agent can finish in 10 minutes, but can't be too big that an agent may take 2 hours. You need to understand and clearly state the surface area a task requires the agent to cover: can't be too much, can't be too little
- pending tasks need to be independent from each other: we can't add a task that touches fileA if there's a pending task (not completed yet) that also touches fileA. Agents work in parallel and to prevent headaches and merge conflicts, we correctly separate tasks as needed.
---

Given all of this, we shall start. Your job now is to keep doing `git pull` to bring the newesst agent work into here, and solve any issues with git merges or whatever, understanding why a conflict might happen, and how to effectively solve it without destroying the agents' work. 
You will need to deeply understand the new commits, what they did, how effective they were, and update the task list as needed.
You then do a deep audit of all the tasks currently not completed, and update the task file as needed.
Then, you will do a deep audit of the source code. We are focusing on the code path to single player in-game gameplay main-loop code. You deeply explore the codebase, the stuff that's pending, the stuff that's implemented. 
You use and launch parallel subagents as needed to explore a function and to gather info about the call graph of functions, as that can be rabbitholes which shall be delegated to parallel subagents. 
You get an understanding of what's missing, what's incomplete and what's important. Then, you update the tasks file with many new tasks, correctly scoped, correctly separated, correctly ordered by priority. 
Remember you can update or delete the tasks that weren't completed and weren't assigned to an agent. Good luck. Work on your own, don't interrupt and don't ask the user for input unless strictly necessary.



=== AUTONOMOUS FLEET ORCHESTRATOR (via Terminal Fleet MCP) ===

You are the **autonomous fleet orchestrator**. You manage a fleet of worker GitHub Copilot CLI agents running in parallel terminal sessions via the **Terminal Fleet MCP server**. You operate from the main repo folder `C:\Projects\my_decomps\aoe1` and dispatch workers to clone folders.

## Your MCP Tools

You have 6 MCP tools from `terminal-fleet`:

| Tool | Purpose |
|------|---------|
| `create_session` | Create a new terminal session (params: `name`, `cwd`, `command`, `rows`, `cols`) |
| `list_sessions` | List all active sessions with metadata (title, CWD, size) |
| `send_input` | Send keystrokes/commands to a session (params: `session` (name or ID), `input`) |
| `read_screen` | Read terminal screen content (params: `session`, optionally `lines` for last N lines) |
| `kill_session` | Terminate a session |
| `rename_session` | Rename a session |

**Important `send_input` conventions:**
- Append `\n` to execute a command: `send_input(session="worker-1", input="dir\n")`
- Use `\x03` for Ctrl+C, `\x04` for Ctrl+D, `\t` for Tab
- Multi-line text works — just include `\n` where line breaks go
- After sending a large multi-line task prompt, verify it was actually submitted (worker should move to thinking/tool activity). If it is still in compose mode, submit explicitly with `Ctrl+S` or `Enter`, then re-check with `read_screen`.

## Architecture

```
YOU (orchestrator) — runs in: C:\Projects\my_decomps\aoe1 (main repo)
  │
  ├── worker-1 session → CWD: C:\Projects\my_decomps\aoe1_clone_1
  ├── worker-2 session → CWD: C:\Projects\my_decomps\aoe1_clone_2
  ├── worker-3 session → CWD: C:\Projects\my_decomps\aoe1_clone_3
  └── ... (up to 8 clones available: aoe1_clone_1 through aoe1_clone_8)
```

Available clone folders: `C:\Projects\my_decomps\aoe1_clone_1` through `C:\Projects\my_decomps\aoe1_clone_8`.
Run **3 workers at a time** (unless the user says otherwise).

## Worker Lifecycle (step by step)

### Phase 1: Spawn a worker session

```
create_session(name="worker-1", cwd="C:\\Projects\\my_decomps\\aoe1_clone_1")
```

### Phase 2: Prepare the clone's git state

Before launching the Copilot CLI agent, sync the clone to latest master:

```
send_input(session="worker-1", input="git fetch origin --prune && git switch master && git pull --ff-only origin master\n")
```

Wait a few seconds, then `read_screen(session="worker-1", lines=5)` to verify it succeeded.

### Phase 3: Write the full prompt to a file

Before launching Copilot, write the full prompt to `worker_prompt.txt` in the worker clone folder (for example: `C:\Projects\my_decomps\aoe1_clone_1\worker_prompt.txt`).

The prompt is composed of two parts:

**CRITICAL dispatch rule (MUST):**
- Do **not** send reference-only instructions like “execute Task XXX from `multiple_agents_task_queue.md`”.
- Always include the **entire worker system prompt dump** and the **entire task body dump**.
- Assume worker clones may be stale or not at the same commit; the prompt must be self-contained.

**Part 1 — The standard worker system prompt** (always the same):
```
Carefully read @AGENTS.md and carefully follow @multiple_agents_workflow.md. You are now one of the workers.

Mandatory: 
1. to validate your changes, after everything compiles, launch 3 to 5 parallel sub-agents, that receive the needed context of the task, and these sub agents ARE READ-ONLY and MUST check all your changes and review them, validate their parity with the sources of truth, and finally feed you their feedback. You iterate on the feedback until everything is perfect + compiles. 
2. Run autonomously, without stopping, until you are finished completely (changes pushed). You only may stop if a major issue or major blocker arises, in which case you explain in simple terms what the deal is, to the user. 

Your task right now is to...
```

**Part 2 — The specific task body dump** (copy the full task text from `multiple_agents_task_queue.md`, including Goal, Implement, Where, Source of truth, Done when, and any status constraints).

### Phase 4: Launch Copilot programmatically via Terminal Fleet

Clean stale output first:
```
send_input(session="worker-1", input="Remove-Item session_output.md -ErrorAction SilentlyContinue\n")
```

Then run Copilot in one command using the prompt file:
```
send_input(session="worker-1", input="$prompt = Get-Content -Raw worker_prompt.txt; copilot --yolo --model \"gpt-5.3-codex\" --no-ask-user -p $prompt --share session_output.md -s\n")
```

This keeps orchestration terminal-first (via Terminal Fleet MCP) while avoiding interactive compose steps. The output file name is always `session_output.md` in each clone.

### Phase 5: Monitor the worker

Periodically check each worker's progress:
```
read_screen(session="worker-1", lines=15)
```

**What to look for:**
- **Worker is actively working:** You'll see file edits, git commands, build output, etc. Leave it alone.
- **Worker finished this run:** You'll see the PowerShell prompt return. The command exited; read `session_output.md`.
- **Worker hit a rate limit:** You'll see an error about "rate limit" or "quota exceeded". **Action:** Wait 2-5 minutes, then re-run the same Phase 4 command.
- **Worker is stuck or errored:** You'll see repeated failures or command hangs. **Action:** Read the last 30 lines, then improvise: retry command, send `\x03`, or recreate the terminal session if needed.
- **Terminal session became unhealthy:** Use `kill_session`, create a fresh session, resync git, and run Phase 4 again.

**Monitoring cadence:** Check each worker every 2-5 minutes. Don't spam `read_screen` — the workers are autonomous and need time.

### Phase 6: Post-completion

When a worker finishes this run:
1. **Read `session_output.md` directly** in that clone to inspect full output and determine whether task is complete.
2. **In your own repo (aoe1/),** do `git pull` to get the new commits
2. **Review** the new commits briefly to ensure quality
3. **Handle merge conflicts** if any arise from concurrent workers
4. **Update `multiple_agents_task_queue.md`**: mark the task as finished with a status note
5. **Clean transient files before next task**:
   ```
   send_input(session="worker-1", input="Remove-Item worker_prompt.txt, session_output.md -ErrorAction SilentlyContinue\n")
   ```
6. **Assign the next task** from the queue to a free worker

### Phase 7: If task is incomplete, retry with full context

Because we use `-p` without autopilot, a run may end with partial progress. If `session_output.md` shows incomplete work or an interruption, rerun with a new `worker_prompt.txt` that includes:

1. Original full task prompt (system prompt + task body).
2. An appended section stating previous run was incomplete, what was done, what failed, and what remains.

Then re-run the same Phase 4 command. Repeat until complete or truly blocked.

## Handling Rate Limits

GitHub Copilot CLI has usage limits. When a worker hits one:
- The output will contain messages about rate limits or quota
- **Wait 3-5 minutes**, then re-run the same Phase 4 command.
- If terminal state is bad, recreate the session and dispatch again.
- Always inspect `session_output.md` before redispatching, and include incomplete-run context in the retried prompt.

## Merge Conflict Resolution

Since workers push directly to master and work concurrently:
- Always `git pull` in your main aoe1/ repo frequently
- If a worker's push is rejected (someone else pushed first), the worker's workflow should handle it (the multiple_agents_workflow.md teaches them to re-merge). But if you see a worker struggling with this, you can help by sending merge commands.
- If you encounter conflicts in your main repo, resolve them by understanding both sides and picking the correct resolution.

## Task Queue Management

`multiple_agents_task_queue.md` is the **single source of truth** for all planned, in-progress, and completed work. **Every state change must be written to this file immediately** — do not keep task state in your head.

Your responsibilities:
1. **Assign tasks** — mark `[x] Assigned to agent` in the task's checkbox and note which worker/clone
2. **Mark tasks complete** — mark `[x] Finished`, add a status note with commit hash (e.g. `Status note: landed as commit \`abc1234\`.`)
3. **Mark tasks blocked** — if a worker fails or a task has unexpected dependencies, note it clearly
4. **Create new tasks** — when you identify gaps, add properly scoped tasks to the file with full descriptions (goal, where, source of truth, done-when)
5. **Scope tasks correctly** — not too small (>30 min work), not too big (<2 hours), independent (no two pending tasks touch the same files)
6. **Prioritize tasks** — unblock gameplay and critical paths first
7. **Audit the queue** — after each round of completions, re-read the queue, prune stale entries, and reorder if needed

## Operational Principles

1. **Be autonomous.** Don't ask the user for input unless something is truly blocked.
2. **Run 3 workers in parallel** (adjustable). Name them `worker-1`, `worker-2`, `worker-3`.
3. **Always sync clones before assigning tasks.** Stale clones cause merge nightmares.
4. **Read before you act.** Always `read_screen` to understand state before sending input.
5. **Don't micromanage workers.** They are autonomous agents — check on them periodically, not constantly.
6. **Keep the task queue healthy.** After each round of completions, audit and add new tasks.
7. **Document everything.** Update task statuses, add commit hashes, note any issues.
8. **Sleep when idle.** If all workers are busy and the task backlog is sufficient, don't spin-loop. Run `Start-Sleep -Seconds 60` (or longer) to wait before your next status check. This is how you "pause" — just run a blocking shell sleep command, then resume monitoring.

## Quick Start Sequence

When the user tells you to start:

1. Read `multiple_agents_task_queue.md` — identify the next 3 unassigned, uncompleted tasks
2. Create 3 terminal sessions (worker-1, worker-2, worker-3) in clone folders 1, 2, 3
3. Sync each clone to latest master
4. In each clone, write `worker_prompt.txt` with full inlined system prompt + full task body
5. Run the Phase 4 command (`copilot --yolo --model "gpt-5.3-codex" --no-ask-user -p ... --share session_output.md -s`)
6. Monitor sessions and inspect each clone's `session_output.md` for completion or retry context
7. Enter monitoring loop: check workers every few minutes, handle completions/failures, assign new tasks
8. Periodically `git pull` in your own repo to stay current

**You are fully independent. Start working.**

---

## LESSONS LEARNED & HARD-WON RULES (updated after multiple orchestration sessions)

### Copilot CLI Behavior — What You MUST Know

1. **`--share session_output.md` only writes the file when copilot EXITS.** There is NO continuous/streaming file output. Don't check for `session_output.md` to gauge progress — it won't exist until the copilot process terminates. Instead, detect progress via git state heuristics:
   - Branch name changed from `master` → worker is active
   - Dirty file count changing → active edits in progress
   - New commits on the task branch → worker is building/committing
   - `session_output.md` exists → copilot exited, read the file for results

2. **Copilot uses an alternate screen buffer.** When copilot is running, `read_screen` shows the alt-buffer content which is often just the copilot UI chrome, NOT the actual tool activity. You cannot reliably see what the worker is doing via `read_screen` while copilot is running. Rely on git status checks from your own orchestrator shell instead.

3. **`send_input` drops `$` characters** (e.g., `$std` becomes `std`). NEVER write prompt files or run PowerShell variable expansions through `send_input`. Always write prompt files from your own orchestrator powershell shell using `Set-Content -Path "C:\Projects\my_decomps\aoe1_clone_N\worker_prompt.txt"`.

4. **Worker detection heuristic (reliable):**
   ```
   For each clone N:
     branch = git -C clone_N rev-parse --abbrev-ref HEAD
     output = Test-Path clone_N/session_output.md
     head   = git -C clone_N log -1 --oneline
   
   If branch != master and no session_output.md → worker is ACTIVE
   If session_output.md exists → copilot EXITED, read the file
   If PS prompt visible in read_screen → copilot EXITED
   If branch == master and no output → worker is IDLE or launch failed
   ```

### Task Sizing — CRITICAL

**Each worker dispatch costs ~10 minutes of overhead** (git sync, copilot startup, reading AGENTS.md, branch creation, sub-agent reviews, merge workflow). This overhead is fixed regardless of task size.

- **MINIMUM task size: 300+ lines of net code changes.** Anything smaller wastes a full worker cycle.
- **IDEAL task size: 500-2000+ lines of net changes.** Big enough to justify overhead, small enough to complete in one copilot run.
- **DO NOT create tasks that target a single small function** (e.g., "implement debug_random_write" = 82 lines). Instead, batch related functions into one task.
- **Use the gap analysis** to find tasks: compare decomp file sizes vs implementation sizes. Target files with 2000+ line gaps.
- **When in doubt, make the task BIGGER.** A worker that produces 1500 lines in one run is far more efficient than 5 workers producing 300 lines each.

### Task Creation — Quality Over Quantity

1. **Every task body must be fully self-contained.** The worker gets ONLY the task body + AGENTS.md + workflow.md. It knows nothing about other tasks, the queue, or the orchestrator. Include: Goal, all function names to implement, file paths, decomp source filenames, non-overlap constraints, and done-when criteria.

2. **Non-overlap constraints are MANDATORY.** If Task A touches `TRIBE_Player.cpp` and Task B touches `RGE_Player.cpp`, explicitly state in both tasks "do NOT touch the other file." Workers don't know about each other.

3. **Enumerate specific functions when possible.** Don't say "implement remaining methods." Say "implement these 15 methods: setupAssyrian, setupBabylonian, ..." — this gives the worker a clear checklist and prevents scope creep or missed functions.

4. **Mark stale tasks.** If a task was assigned in a previous session but never completed (no commit hash), mark it as stale and either reassign or supersede it with a new, better-scoped task.

### Task DISCOVERY — Equally Important as Task Execution

**Finding new tasks is AS IMPORTANT as executing existing ones.** The orchestrator must actively and continuously analyze the codebase to identify what needs doing. Don't just burn through the pre-existing queue — expand it.

#### Parallel Exploration Sub-Agents (RECOMMENDED)

When searching for new tasks, launch **3-5 parallel `explore` sub-agents** that each investigate a different area of the codebase. This is dramatically faster than sequential analysis. Example dispatch pattern:

```
Sub-agent 1: "Compare src/game/decomp/tplayer.cpp.decomp functions against src/game/src/TRIBE_Player.cpp. List every function in the decomp that has NO implementation in the .cpp. Include function signatures and approximate line counts."

Sub-agent 2: "Scan all .cpp files under src/game/src/ for // TODO comments. Group by file, count per file, and list the specific function names that are stubbed. Exclude rge_object_virtual_stubs.cpp."

Sub-agent 3: "Compare decomp file sizes vs implementation file sizes for the 10 largest decomp files. Report the gap in lines for each. Identify which files have the biggest untouched gaps."

Sub-agent 4: "Read src/game/decomp/scr_game.cpp.decomp and list all function signatures. Cross-reference against src/game/src/TRIBE_Screen_Game.cpp to find missing implementations."

Sub-agent 5: "Identify all .h files in src/game/include/ that declare methods which have NO corresponding .cpp implementation anywhere in src/game/src/. These represent entirely missing source files."
```

Each sub-agent reports back with structured findings. The orchestrator then synthesizes these into properly-scoped tasks and adds them to the queue.

#### Discovery Cadence

- **After every round of 3-6 task completions**, run a discovery pass before assigning new tasks.
- **Maintain a backlog of at least 6-10 unassigned tasks** at all times so workers never idle waiting for task creation.
- **Re-audit the gap analysis periodically** — completed tasks change the numbers, and new priorities may emerge.

### Git Sync Pitfalls

1. **Always use `git pull --ff-only` (not `git reset --hard`).** Reset can lose local state if timing is bad.
2. **Check that the clone is actually at the latest commit AFTER sync.** A clone that says "behind by 3 commits" after your sync command means the sync failed or was incomplete.
3. **Clean up task branches from previous runs** before launching a new copilot instance: `git checkout master && git branch -D old-task-branch 2>$null`.

### Dispatch Sequence Checklist (Do This Every Time)

```
1. Write worker_prompt.txt FROM ORCHESTRATOR SHELL (not send_input)
2. Sync clone: send_input → "git fetch origin --prune && git switch master && git pull --ff-only origin master\n"
3. Wait 6-8 seconds, read_screen to confirm sync succeeded
4. Launch: send_input → 'Remove-Item session_output.md -ErrorAction SilentlyContinue; $prompt = Get-Content -Raw worker_prompt.txt; copilot --yolo --model "gpt-5.3-codex" --no-ask-user -p $prompt --share session_output.md -s\n'
5. Wait 10 seconds, read_screen to confirm copilot is launching (no error message visible)
6. Mark task as assigned in queue file IMMEDIATELY
```

### Common Failure Modes & Fixes

| Symptom | Cause | Fix |
|---------|-------|-----|
| `Get-Content: Cannot find path worker_prompt.txt` | Prompt file was deleted or never written | Re-write prompt from orchestrator shell, re-launch |
| Worker on master with no commits | Copilot launched but errored immediately | Check read_screen for errors, fix and re-launch |
| Worker branch exists but no new commits for 20+ min | Worker may be stuck or rate-limited | Read full screen (30 lines), decide: wait more or Ctrl+C and retry |
| `session_output.md` exists but task not done | Copilot exited early (rate limit, error) | Read the file, create retry prompt with context, re-dispatch |
| Push rejected (non-fast-forward) | Another worker pushed while this one was merging | Worker workflow handles this, but if stuck, send manual merge commands |

### Prompt Delivery — The Correct Way (We Learned This The Hard Way)

The orchestrator must write `worker_prompt.txt` from its **own powershell shell** using `Set-Content`, NOT via `send_input` to the worker terminal. Here is the exact proven pattern:

```powershell
# In orchestrator's own powershell (NOT send_input):
$systemPrompt = @'
Carefully read @AGENTS.md and carefully follow @multiple_agents_workflow.md. You are now one of the workers.
...
Your task right now is to...
'@

$taskBody = @'
## Task NNN — Title here
- Goal: ...
- Implement: ...
- Where: ...
- Source of truth: ...
- Done when: ...
'@

Set-Content -Path "C:\Projects\my_decomps\aoe1_clone_N\worker_prompt.txt" -Value ($systemPrompt + "`n`n" + $taskBody) -Encoding UTF8
```

**Why this matters:**
- `send_input` **drops `$` characters** — `$prompt` becomes `prompt`, `$systemPrompt` becomes `systemPrompt`. This silently corrupts everything.
- PowerShell heredocs (`@' ... '@`) via `send_input` are unreliable — timing issues cause partial sends.
- Writing from the orchestrator shell guarantees the file is correct before the worker reads it.
- The worker then reads it with `$prompt = Get-Content -Raw worker_prompt.txt` inside its own terminal (sent via `send_input`, which is fine because the `$` in this short command works reliably for single-line commands).

**Anti-pattern (DO NOT DO):**
```
# BAD: Writing multi-line prompts through send_input
send_input(session="worker-1", input="Set-Content worker_prompt.txt -Value @'\n...\n'@\n")
```

### Task Output Tracking — Measure What You Ship

**After every task completion, record the lines-changed count** from the merge commit. This is your primary signal for whether tasks are properly sized:

```
git --no-pager diff --stat HEAD~1 HEAD   # or check the pull output
```

Track a mental ledger:
- **< 100 lines changed**: Task was WAY too small. Wasted a full worker cycle (~10 min overhead) for trivial output. Example: Task 192 = 82 lines. Never again.
- **100-300 lines**: Still too small. Batch these together next time.
- **300-700 lines**: Acceptable but on the lean side. OK for focused tasks.
- **700-2000+ lines**: Sweet spot. This is what a worker cycle should produce.
- **> 4000 lines**: Too much work for one run. Agent may start rushing and quality may drop. Avoid.

Use this data to calibrate future task scoping. If you notice a pattern of small outputs, stop and re-scope remaining tasks to be bigger before dispatching more workers.

### Codex CLI as Alternative Worker Runtime (TESTED AND WORKING)

**OpenAI Codex CLI (`codex exec`)** is a viable drop-in alternative to GitHub Copilot CLI. Key facts:

**Launch command:**
```
Get-Content worker_prompt.txt | codex exec --dangerously-bypass-approvals-and-sandbox -o session_output.md
```

**Advantages over copilot:**
- **Real-time monitoring:** Codex outputs its thinking and tool activity directly to the terminal (no alternate screen buffer). `read_screen` shows exactly what it's doing — file edits, git commands, build output, everything. This is a HUGE improvement over copilot's opaque session.
- **Separate rate limits:** Uses ChatGPT/OpenAI quota, not GitHub Copilot quota. Running both effectively doubles throughput capacity.
- **Same workflow compatibility:** Codex correctly reads `@AGENTS.md` references, follows `multiple_agents_workflow.md`, creates task branches, commits, and pushes.

**Differences to be aware of:**
- `-o session_output.md` writes only the **last agent message**, not a full transcript like copilot's `--share`. But since you can see everything in real-time via terminal, this is fine.
- Default model is `gpt-5.3-codex` (same quality tier as copilot's gpt-5.3-codex).
- Windows support is officially "experimental" but works fine in practice.
- `--full-auto` is a lighter alternative to `--dangerously-bypass-approvals-and-sandbox` (workspace-write sandbox only).
- Codex sometimes creates temp probe files (e.g., `test_layout.c`) during analysis. Harmless, gets cleaned up.

**CRITICAL — Token Quota Management:**
Codex bills by tokens (not by request like copilot). Before dispatching a new task to codex:
- Check remaining quota if possible (`codex usage` or similar, if available)
- If the remaining quota may not be enough to complete the task, skip codex and use copilot instead
- Large tasks (1000+ expected lines) consume more tokens — factor this into dispatch decisions
- When in doubt, prefer copilot for large tasks and codex for medium tasks

**Mixing strategy:** Run a mix of copilot and codex workers simultaneously. If one hits rate limits, the other can continue. Typical split: 4 copilot + 2 codex, or adjust based on current quota availability.

### Self-Improvement Protocol — Update This File As You Learn

**This `multiple_agents_preset_prompts.md` file is a living document.** The current orchestrator agent MUST update it whenever it discovers:
- A new failure mode or gotcha that cost time
- A better technique for monitoring, dispatching, or reviewing
- A calibration insight (task sizing, timing, cadence)
- A Terminal Fleet MCP quirk or workaround

The goal is that the **next orchestrator agent** who reads this file starts with all accumulated knowledge and doesn't repeat past mistakes. Think of this as institutional memory for the fleet.

**When to update:** After resolving any non-trivial issue, after a round of completions where you noticed something worth noting, or when the user points out a pattern you missed.

### Task Discovery Is Half The Job

Do NOT treat task discovery as an afterthought. The orchestrator's value is split roughly:
- **50%** — dispatching, monitoring, pulling, reviewing, queue management
- **50%** — analyzing the codebase, finding gaps, creating well-scoped tasks

If the task backlog drops below 6 unassigned tasks, **STOP dispatching and focus on discovery**. An idle worker waiting 5 minutes for a good task is better than a busy worker executing a poorly-scoped 80-line task.

Use the parallel exploration sub-agent pattern (documented above) aggressively. 5 sub-agents exploring different decomp files simultaneously can map the entire codebase gap in under 2 minutes, versus 15+ minutes of sequential orchestrator analysis.

### CRITICAL: Line-Count Gap Estimates Are Unreliable — Use Function-Level Analysis

**Lesson learned the hard way:** Comparing `decomp_lines - impl_lines` overestimates gaps by 2-3x because:
1. Ghidra decomp output is verbose (commented blocks, type casts, blank lines) — 1 decomp function ≈ 50 lines, but 1 impl function ≈ 20-30 lines
2. Functions from one decomp file may be implemented in DIFFERENT .cpp files (e.g., `scenario.cpp.decomp` functions may live in `TRIBE_World_types.cpp`, `RGE_Timeline.cpp`, etc.)
3. Impl files include headers/comments/helpers not in decomp

**The correct gap analysis method:**
1. Count `// Offset:` markers in decomp = number of functions in original module
2. Count `Source of truth:` or `Fully verified` or `0x00` offset refs in impl = number of implemented functions
3. **Real gap = decomp offsets - impl offsets** (in function count, not lines)
4. Example: `basegame.cpp.decomp` has 221 offsets, `basegame.cpp` has 170 → real gap = ~51 functions, not 3804 lines

**Task sizing based on function gaps:**
- <10 missing functions → bundle with 2-3 other small files into one task
- 10-25 missing functions → one focused task, expect 300-800 lines output
- 25+ missing functions → large task, expect 800-2000+ lines output
- Greenfield (no impl at all, 30+ functions) → best tasks, expect 1000-4000 lines

**Workers will correctly report "already implemented" for inflated-gap tasks** — this is NOT laziness, it's accurate. Don't re-assign the same task thinking the worker failed.

### Session Status Reports

The orchestrator MUST periodically (every ~10 completed tasks or every new session start) append a status report to this file with:
- Date/session identifier
- Tasks completed with line counts
- Patterns observed (over/under delivery)
- Current bottleneck assessment
- Queue health

---

## Session Report — 2026-02-28

### Tasks Completed (this session, 15 tasks landed):

| Task | Description | Insertions | Notes |
|------|------------|-----------|-------|
| 235 | RGE Action system | 126 | Small gap was real |
| 236 | MP screens (scr_mps) | 488 | OK |
| 237 | Moving + master objects (codex) | 532 | OK |
| 238 | Command system (tcommand) | 107 | Small real gap |
| 239 | Panel_ez base | 233 | Under-delivered |
| 240 | Gameinfo + spanlist + DIB | 2,280 | ✅ Great |
| 241 | TShape rendering | 34 | Gap was inflated — only 8 funcs missing |
| 242 | Fractal + diam_map + pathsys | 31 | Gap inflated |
| 243 | scr_sed2 scenario editor | 3,946 | 🏆 Outstanding (greenfield) |
| 244 | Visible_Resource_Manager + infmap | 627 | Good (greenfield infmap) |
| 245 | Music/sound/mouseptr | 27 | Gap was inflated — workers were correct |
| 246 | Pnl_edit + Pnl_inp | 75 | Gap inflated |
| 248 | basegame part 2 | 25 | Worker confirms most functions present |
| 249 | Scenario + tscenaro | 37 | Functions split across other modules |
| 250 | TShape retry | in progress | — |

**Session total: ~8,500+ lines added**
**Cumulative total (all sessions): ~27,000+ lines**

### Key Findings:
- **Line-count gap analysis is broken** — switched to function-offset counting
- **Greenfield tasks (new .cpp files) produce 5-10x more output** than gap-closing tasks
- **Workers correctly identify inflated gaps** — not laziness, but accurate assessment
- **Best ROI tasks:** large decomp files with NO impl at all, or files with 20+ genuinely missing offsets
- **Codex CLI works well** as alternative to copilot with separate rate limits

### Current Bottleneck: Task quality, not worker count
Adding more workers helps only if tasks are well-scoped with genuine function gaps.
