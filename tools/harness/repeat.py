"""Repeat a bounded menu capture and compare each final surface with the first."""
from __future__ import annotations

import argparse
from datetime import datetime, timezone
import json
from pathlib import Path
import sys

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
import game
from capture import capture
from compare import compare


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('target', choices=('original', 'rebuilt'))
    parser.add_argument('--count', type=int, default=20)
    parser.add_argument('--seconds', type=float, default=4)
    parser.add_argument('--fixture', type=Path)
    parser.add_argument('--clock', choices=('real', 'calls'), default='calls')
    parser.add_argument('--resolution', help='Game resolution, for example 800x600')
    parser.add_argument('--visible', action='store_true')
    args = parser.parse_args()
    if not 1 <= args.count <= 100 or not 0 < args.seconds <= 300:
        parser.error('Count must be 1..100 and seconds must be greater than zero and at most 300.')
    output = game.ROOT / 'build/runtime' / ('repeat-' + args.target + '-' + game.stamp())
    output.mkdir(parents=True)
    result = {'target': args.target, 'requested': args.count, 'runs': [],
              'scope': 'Repeated final menu pixels, palette, and controlled-clock RNG trace', 'passed': False}
    try:
        baseline = None
        for index in range(args.count):
            runtime = game.stage(args.target, select=False)
            code = capture(runtime, args.seconds, args.fixture, args.clock, args.visible, args.resolution)
            path = runtime / 'capture/report.json'
            comparison = None
            if code == 0 and baseline is not None:
                comparison = output / f'comparison-{index:03d}'
                code = compare(baseline, path, comparison)
            result['runs'].append({'capture': str(path), 'returncode': code,
                                   'comparison': str(comparison) if comparison else None})
            (output / 'report.json').write_text(json.dumps(result, indent=2) + '\n')
            if code:
                return 1
            baseline = baseline or path
        result['passed'] = True
        return 0
    finally:
        (output / 'report.json').write_text(json.dumps(result, indent=2) + '\n')
        print(f'Repeat report: {output / "report.json"}', flush=True)


if __name__ == '__main__':
    raise SystemExit(main())
