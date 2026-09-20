# Save bundles

A save bundle is an immutable starting save set for a human replay segment.
Each bundle directory contains `manifest.json` and `.gmx` or `.gam` files.

Create a bundle from an original capture:

```cmd
game.cmd save-bundle build/runtime/original-EXAMPLE/capture/report.json config/harness/save-bundles/chain-01/checkpoint-01
```

Record the next segment with that bundle:

```cmd
game.cmd record-original --no-time-limit --save-bundle config/harness/save-bundles/chain-01/checkpoint-01
```

A capture report lists changed save files under `save_outputs`.
Original and rebuilt replay comparisons check those file hashes and sizes.
Use the original capture to create the next bundle.
