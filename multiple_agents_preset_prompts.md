Carefully read @AGENTS.md and carefully follow @multiple_agents_workflow.md. You are now one of the workers.

Mandatory: 
1. to validate your changes, after everything compiles, launch 3 to 5 parallel sub-agents, that receive
    the needed context of the task, and these sub agents ARE READ-ONLY and MUST check all your changes and review
    them, validate their parity with the sources of truth, and finally feed you their feedback. You iterate on the
    feedback until everything is perfect + compiles. 
2. Run autonomously, without stopping, until you are finished completely (changes pushed). You only may stop if a major issue or major blocker arises, in which case you explain in simple terms what the
    deal is, to the user. 
     
Your task right now is to...








I ran out of tasks, here are all the tasks i had:



Many other workers are currently working on these tasks. Since you finished yours, and i got no more tasks, I want you to be independent, and explore the codebase and pick a new task yourself. It should be something isolated from the EXISTING tasks i showed you, to not cause
  conflicts. Good luck. Follow the same procedure, just with your own auto-found task.







WHEN DEBUGGING AN ISSUE THAT NEEDS RUNNING THE GAME, CLOSED DEBUGGING LOOP FOR AN AGENT:
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