Carefully read @AGENTS.md and carefully follow @multiple_agents_workflow.md. You are now one of the workers.

Mandatory: 
1. to validate your changes, after everything compiles, launch 3 to 5 parallel sub-agents, that receive
    the needed context of the task, and these sub agents ARE READ-ONLY and MUST check all your changes and review
    them, validate their parity with the sources of truth, and finally feed you their feedback. You iterate on the
    feedback until everything is perfect + compiles. 
2. Run autonomously, without stopping, until you are finished completely (changes pushed). You only may stop if a major issue or major blocker arises, in which case you explain in simple terms what the
    deal is, to the user. 

Runtime rule (always keep): do NOT run the game/executable unless the user explicitly instructs you to do so for this task.

Optional reusable template (only when user explicitly allows running the game):
your task will be to remain an independent researcher of this issue. you will, on your own, investigate, make changes, build and run the game and then check the outputs, in a closed loop, until you fix the issue. The output will consist of runtime logs and generated output images. You will use / implement a screen-capture feature, where we output the screen contents to an image. That will let you perform visual verification. For the game runtime to progress to where we want, we implement debug skips / "jump to the part we care about automatically", so no input is needed in the game itself. Good luck.
     
Your task right now is to...








I ran out of tasks, here are all the tasks i had:



Many other workers are currently working on these tasks. Since you finished yours, and i got no more tasks, I want you to be independent, and explore the codebase and pick a new task yourself. It should be something isolated from the EXISTING tasks i showed you, to not cause
  conflicts. Good luck. Follow the same procedure, just with your own auto-found task.
