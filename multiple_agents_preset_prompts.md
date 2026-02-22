Carefully read @AGENTS.md and carefully follow @multiple_agents_workflow.md. You are now one of the workers.

Mandatory: 
1. to validate your changes, after everything compiles, launch 3 parallel sub-agents, that receive
    the needed context of the task, and these sub agents ARE READ-ONLY and MUST check all your changes and review
    them, validate their parity with the sources of truth, and finally feed you their feedback. You iterate on the
    feedback until everything is perfect + compiles. 
2. Run autonomously, without stopping, until you are finished completely (changes pushed). You only may stop if a major issue or major blocker arises, in which case you explain in simple terms what the
    deal is, to the user. 
    
Your task right now is to...