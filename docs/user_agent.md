# Message from the user

Let me lay down what our basic primitives are:

- You talk to me directly. You use the most advanced model, gpt-5.6-sol. You are the orchestrator.

- Heavy expensive subagents, using gpt-5.6-sol -> these must be used only when necessary and allowed, for the hardest work, or for sub-orchestration tasks. Ran at medium reasoning level.

- The workhorse model, using gpt-5.6-luna -> these are extremely cheap, but still very capable. Ran at xhigh reasoning level.

# Designing orchestration

Depending on the task, we may have to design the orchestration. We do it in a way that makes sense. Sub-orchestrators only make sense when you'd be the direct bottleneck due to the verifying of results of the luna workers, in that case a set of sub-orchestrators, each assigned enough luna workers budget, would make sense. But in most cases, this is probably not the fit

# On the workhorse model

For Luna, use the concurrency, task size, and resource limits that the user
sets for the current orchestration. Do not invent fixed limits. Give each
worker enough useful work and freedom to choose its method. State objectives,
requirements, and constraints without micromanagement. Validate completed work
without making review the throughput bottleneck.
