"""Read Win32 string-table resources without loading or executing the PE file."""
from __future__ import annotations

import argparse
import hashlib
import json
from pathlib import Path
import struct

import pefile

ROOT = Path(__file__).resolve().parents[1]


def number(text: str) -> int:
    return int(text, 16 if text.lower().startswith('0x') else 10)


def read_strings(path: Path) -> tuple[str, list[dict]]:
    data = path.read_bytes()
    rows = []
    with pefile.PE(data=data) as pe:
        resources = getattr(pe, 'DIRECTORY_ENTRY_RESOURCE', None)
        for kind in resources.entries if resources else ():
            if kind.id != 6:  # RT_STRING
                continue
            for block in kind.directory.entries:
                if block.id is None or block.id < 1:
                    raise ValueError('Expected a numeric string-table block ID.')
                for language in block.directory.entries:
                    leaf = language.data.struct
                    payload = pe.get_data(leaf.OffsetToData, leaf.Size)
                    if len(payload) != leaf.Size:
                        raise ValueError('Truncated string-table resource.')
                    offset = 0
                    for slot in range(16):
                        if offset + 2 > len(payload):
                            raise ValueError('Truncated string-table length.')
                        length = struct.unpack_from('<H', payload, offset)[0]
                        offset += 2
                        end = offset + length * 2
                        if end > len(payload):
                            raise ValueError('Truncated UTF-16 string.')
                        text = payload[offset:end].decode('utf-16-le', errors='surrogatepass')
                        identifier = (block.id - 1) * 16 + slot
                        rows.append({'id': identifier, 'id_hex': f'0x{identifier:04X}',
                                     'language_id': language.id, 'language_hex': f'0x{language.id:04X}',
                                     'block_id': block.id, 'slot': slot, 'utf16_units': length, 'text': text})
                        offset = end
    return hashlib.sha256(data).hexdigest(), sorted(rows, key=lambda row: (row['id'], row['language_id']))


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--dll', type=Path, required=True, help='Explicit PE file whose string resources should be read')
    select = parser.add_mutually_exclusive_group(required=True)
    select.add_argument('--id', type=number, nargs='+',
                        help='One or more decimal or 0x-prefixed string IDs; IDs above 0xFFFF are read by their '
                             'low 16 bits, as LoadStringA does, and listed under loaded_ids')
    select.add_argument('--contains', help='Case-insensitive text search; returned text stays unchanged')
    select.add_argument('--list', action='store_true', help='List nonempty string-table slots')
    parser.add_argument('--language', type=number, help='Optional decimal or hexadecimal language ID')
    parser.add_argument('--output', type=Path, help='New JSON file under build/; otherwise print JSON')
    args = parser.parse_args()
    if args.output and (args.output.exists() or not args.output.resolve().is_relative_to((ROOT / 'build').resolve())):
        parser.error('Use a new output file under build/.')
    try:
        sha, rows = read_strings(args.dll)
        if args.language is not None:
            rows = [row for row in rows if row['language_id'] == args.language]
        loaded_ids = []
        if args.id is not None:
            # LoadStringA uses only the low 16 bits of the ID, so look up the ID it would load.
            loaded = {requested: requested & 0xFFFF for requested in args.id}
            loaded_ids = [{'requested_id': requested, 'requested_hex': f'0x{requested:X}',
                           'loaded_id': target, 'loaded_hex': f'0x{target:04X}'}
                          for requested, target in sorted(loaded.items()) if requested != target]
            selected = set(loaded.values())
            rows = [row for row in rows if row['id'] in selected]
            found = {row['id'] for row in rows}
            missing = sorted(requested for requested, target in loaded.items() if target not in found)
        else:
            missing = []
            rows = [row for row in rows if row['text'] and
                    (args.contains is None or args.contains.casefold() in row['text'].casefold())]
        result = {'file': str(args.dll.resolve()), 'sha256': sha, 'resource_type': 'RT_STRING',
                  'strings': rows, 'missing_ids': missing, 'loaded_ids': loaded_ids,
                  'scope': 'Exact resource text only; not recovered macro names or proof of which module a caller loads.',
                  'empty_slots': 'An empty slot does not distinguish an intentionally empty string from an unused ID.'}
        text = json.dumps(result, indent=2, ensure_ascii=True) + '\n'
        if args.output:
            args.output.parent.mkdir(parents=True, exist_ok=True)
            args.output.write_text(text, encoding='utf-8')
        else:
            print(text, end='')
        return 1 if missing else 0
    except (OSError, ValueError, pefile.PEFormatError) as error:
        parser.exit(1, f'{error}\n')


if __name__ == '__main__':
    raise SystemExit(main())
