// Diagnostic replay can restore recorded srand inputs before map generation.
{
    const replaySeeds = cfg.human.replay_rng_seeds;
    let replaySeedIndex = 0;
    Interceptor.attach(target('srand'), {onEnter(args) {
        if (replaySeedIndex >= replaySeeds.length) {
            send({kind:'human-rng-seed-unrecorded', index:replaySeedIndex++, seed:args[2].toUInt32(),
                file:args[0].readCString(), line:args[1].toInt32()});
            return;
        }
        const recorded = replaySeeds[replaySeedIndex++];
        args[2] = ptr(recorded);
        send({kind:'human-rng-seed', index:replaySeedIndex - 1, seed:recorded,
            file:args[0].readCString(), line:args[1].toInt32()});
    }});
}
