"""Compare full game-client images at named replay boundaries, not desktop images."""
import hashlib
from pathlib import Path

from PIL import Image, ImageChops


def load_checkpoints(path, report):
    expected = report['fixture']['replay'].get('captures', [])
    rows = (report.get('status') or {}).get('ui', {}).get('checkpoints', [])
    if len(rows) != len(expected):
        raise ValueError('Capture checkpoint count differs from the scenario.')
    result = []
    for spec, row in zip(expected, rows):
        if not isinstance(row.get('name'), str) or not row['name'].isidentifier():
            raise ValueError('Invalid capture name.')
        if any(row.get(key) != spec[key] for key in ('name', 'after_updates')):
            raise ValueError('Capture checkpoint identity differs from the scenario.')
        if row.get('boundary') != 'Paint-entry' or type(row.get('updates')) is not int or row['updates'] < spec['after_updates']:
            raise ValueError('Invalid capture boundary.')
        if type(row.get('input')) is not int or row['input'] < 0 or not isinstance(row.get('panel'), str):
            raise ValueError('Missing capture input or panel identity.')
        name = row.get('composite', '')
        if not name or Path(name).name != name:
            raise ValueError('Invalid capture image path.')
        with Image.open(path.parent / name) as saved:
            if saved.width < 1 or saved.height < 1 or saved.width > 4096 or saved.height > 4096:
                raise ValueError('Invalid capture dimensions.')
            image = saved.convert('RGB')
        frames = [frame for frame in report.get('frames', []) if frame['count'] == row.get('frame')]
        if len(frames) != 1 or image.size != (frames[0]['width'], frames[0]['height']):
            raise ValueError('Capture image dimensions differ from the captured surface.')
        if hashlib.sha256(image.tobytes()).hexdigest() != row.get('rgb_sha256'):
            raise ValueError('Capture image hash differs from its report.')
        result.append((row, image))
    return result


def compare_captures(left_path, right_path, left, right, output=None):
    enabled = bool(left['fixture']['replay'].get('captures') or right['fixture']['replay'].get('captures'))
    result = {'enabled':enabled, 'passed':True, 'checkpoints':[]}
    try:
        a, b = load_checkpoints(left_path, left), load_checkpoints(right_path, right)
        if len(a) != len(b):
            raise ValueError('Capture counts differ between runs.')
        for index, ((x, ai), (y, bi)) in enumerate(zip(a, b)):
            keys = ('name', 'after_updates', 'updates', 'input', 'boundary', 'panel')
            boundary_matches = all(x.get(key) == y.get(key) for key in keys)
            same_size = ai.size == bi.size
            difference = ImageChops.difference(ai, bi) if same_size else None
            bounds = difference.getbbox() if difference else None
            equal = same_size and bounds is None
            row = {'name':x['name'], 'passed':boundary_matches and equal,
                   'boundary_matches':boundary_matches, 'pixels_match':equal,
                   'left_updates':x['updates'], 'right_updates':y['updates'],
                   'left_size':list(ai.size), 'right_size':list(bi.size), 'difference_bounds':bounds,
                   'left_image':str(left_path.parent / x['composite']),
                   'right_image':str(right_path.parent / y['composite'])}
            if output is not None:
                directory = output / f'{index:03d}-{x["name"]}'
                directory.mkdir(parents=True, exist_ok=True)
                pair = Image.new('RGB', (ai.width + bi.width, max(ai.height, bi.height)))
                pair.paste(ai, (0, 0))
                pair.paste(bi, (ai.width, 0))
                pair.save(directory / 'side-by-side.png')
                row['side_by_side'] = str(directory / 'side-by-side.png')
                if difference is not None:
                    difference.save(directory / 'difference.png')
            result['checkpoints'].append(row)
            result['passed'] &= row['passed']
    except (OSError, ValueError, KeyError, TypeError) as error:
        result.update(passed=False, error=str(error))
    return result
