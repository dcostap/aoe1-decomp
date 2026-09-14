"""Compare the final captured surface and palette. This does not compare full game state."""
from __future__ import annotations

import argparse
import json
from pathlib import Path


def load_frame(report_path: Path, frame_count=None):
    from PIL import Image
    report = json.loads(report_path.read_text())
    if report['errors'] or not report['frames']:
        raise ValueError('Capture has errors or no frames.')
    frame = report['frames'][-1] if frame_count is None else next(
        row for row in report['frames'] if row['count'] == frame_count)
    payload = report_path.with_name(frame['file']).with_suffix('.bin').read_bytes()
    width, height, pitch = frame['width'], frame['height'], frame['pitch']
    if len(payload) != pitch * height + 1024:
        raise ValueError('Invalid frame payload.')
    pixels = b''.join(payload[y*pitch:y*pitch+width] for y in range(height))
    palette = payload[pitch*height:]
    image = Image.frombytes('P', (width, height), pixels)
    image.putpalette(bytes(channel for i in range(256) for channel in palette[i*4:i*4+3]))
    return report, frame, pixels, palette, image.convert('RGB')


def compare(left: Path, right: Path, output: Path, left_frame=None, right_frame=None, compare_rng=True):
    from PIL import Image, ImageChops
    a, af, ap, ac, ai = load_frame(left, left_frame)
    b, bf, bp, bc, bi = load_frame(right, right_frame)
    if ai.size != bi.size:
        raise ValueError('Surface dimensions differ.')
    # Different inputs invalidate a comparison instead of silently broadening its claim.
    for key in ('graphics_sha256', 'graphics_config_sha256'):
        if a['manifest'].get(key) != b['manifest'].get(key):
            raise ValueError(f'Capture environments differ: {key}')
    if a['arguments'] != b['arguments']:
        raise ValueError('Game arguments differ.')
    if a.get('fixture') != b.get('fixture'):
        raise ValueError('Input fixtures differ.')
    if a.get('clock') != b.get('clock'):
        raise ValueError('Clock profiles differ.')
    if a.get('registry_inputs') != b.get('registry_inputs'):
        raise ValueError('Registry inputs differ.')
    if a.get('script_sha256') != b.get('script_sha256') and 'registry_inputs' in a:
        raise ValueError('Instrumentation templates differ.')
    def assets(report):
        manifest = report['manifest']
        values = {row['path']: row['sha256'] for row in manifest.get('copied_files_before_exe_replacement', [])}
        values.update({path: row['sha256'] for path, row in manifest.get('overrides', {}).items()})
        return values
    if assets(a) != assets(b):
        raise ValueError('Asset inputs differ.')
    output.mkdir(parents=True, exist_ok=False)
    delta = ImageChops.difference(ai, bi)
    changed = sum(pixel != (0, 0, 0) for pixel in delta.getdata())
    mask = Image.new('RGB', ai.size)
    mask.putdata([(255, 0, 255) if pixel != (0, 0, 0) else (0, 0, 0) for pixel in delta.getdata()])
    mask.save(output / 'difference.png')
    pair = Image.new('RGB', (ai.width * 2, ai.height))
    pair.paste(ai, (0, 0))
    pair.paste(bi, (ai.width, 0))
    pair.save(output / 'side-by-side.png')
    result = {'scope': 'Selected Paint-entry surface, not full execution',
              'left': str(left.resolve()), 'right': str(right.resolve()),
              'left_frame': af['count'], 'right_frame': bf['count'],
              'different_indices': sum(x != y for x, y in zip(ap, bp)),
              'different_palette_entries': sum(ac[i:i+4] != bc[i:i+4] for i in range(0, 1024, 4)),
              'different_rgb_pixels': changed, 'rgb_bounds': delta.getbbox(),
              'match': ap == bp and ac == bc}
    if compare_rng and a.get('clock') == 'calls':
        sa, sb = a['status'], b['status']
        result['rng_match'] = (sa['rngCount'] == len(sa['rngTrace']) and
                               sb['rngCount'] == len(sb['rngTrace']) and sa['rngTrace'] == sb['rngTrace'])
        result['match'] = result['match'] and result['rng_match']
    (output / 'report.json').write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps(result, indent=2))
    return 0 if result['match'] else 1


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('left', type=Path, help='First capture/report.json')
    parser.add_argument('right', type=Path, help='Second capture/report.json')
    parser.add_argument('--output', required=True, type=Path, help='New evidence directory')
    args = parser.parse_args()
    return compare(args.left, args.right, args.output)


if __name__ == '__main__':
    raise SystemExit(main())
