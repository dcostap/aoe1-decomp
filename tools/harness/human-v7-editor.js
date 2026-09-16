// v7 recordings may open the scenario editor and start scenarios.
// The core installs no startup blocks for this profile. Fail loudly if one appears.
if ((cfg.blockedStartups || []).length !== 0)
    throw new Error('An editor recording must not block a startup path');
