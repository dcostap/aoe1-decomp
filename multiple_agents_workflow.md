This repo is worked on by multiple concurrent AI agents. Agents integrate using **plain Git** and push **directly to `master`**.

## Goals
- Keep `master` stable and up to date.
- Ensure each push is based on the latest `origin/master`.
- Resolve conflicts locally (not by breaking `master`).
- Avoid rewriting shared history.

## Hard Rules (Do Not Break)
1. **Never force-push to `master`** (no `--force`, no `--force-with-lease`).
2. **Never commit directly on `master`** (work on a task branch).
3. **Before merging into `master`, merge `origin/master` into your task branch** and resolve conflicts locally.
4. **Only fast-forward your local `master` from `origin/master`** (no accidental divergence).
5. **Only ever push to `master` if the thing compiles.**
6. **Never run the actual game / executable. We just worry about the thing compiling.**

## Per-Task Workflow (Follow Exactly)

### 0) Start clean and synced
```bash
git fetch origin --prune
git switch master
git pull --ff-only origin master
````

### 1) Create a task branch from current `master`

Branch naming:

* `agent/<short-task-name>`

```bash
git switch -c agent/<short-task-name>
```

### 2) Work and commit on the task branch

```bash
git status
git add -A
git commit -m "Describe the change, don't be vague or too generic. Then, add a more detailed description in the body of the commit message if needed. Include what you did, what you found, and any assumptions or uncertainties."
```

Repeat as needed.

## Finishing Workflow (The Critical Part)

### 3) Integrate the latest remote `master` into your task branch (MERGE)

This reduces the chance you break `master` when you finally push.

```bash
git fetch origin --prune
git merge origin/master -m "<description>"
```
Always include the merge message to prevent git from prompting the computer user to open an editor.

Resolve any conflicts locally, and repeat the steps.

### 5) Update local `master` to latest remote, then merge your task branch into it

This ensures your final push to `master` includes everything already pushed by others.

```bash
git switch master
git pull --ff-only origin master
git merge --no-ff agent/<short-task-name>
```

Notes:

* `--no-ff` records a merge commit for traceability (recommended in multi-agent work).
* If you prefer fast-forward merges when possible, omit `--no-ff`.

### 6) Push `master`

```bash
git push origin master
```

---

## If Your Push to `master` Is Rejected

This means someone else pushed to `origin/master` since your last pull.

Do **not** force push. Repeat the integration loop.
