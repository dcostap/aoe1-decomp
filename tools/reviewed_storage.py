"""Load reviewed owners and previously recovered, independently anchored strings."""
import json
from common import REPO_ROOT
from audit_global_initializers import read_storage

STRING_EVIDENCE = REPO_ROOT / 'workflow/decomp_notes/executable_build_evidence/string_definitions.json'


def load_reviewed_storage(original):
    entries = json.loads((REPO_ROOT / 'config/linked_reference_owners.json').read_text())['owners']
    names = {e['symbol'] for e in entries}
    for row in json.loads(STRING_EVIDENCE.read_text()):
        if not row.get('has_nul') or not row.get('anchors') or row['exact_references'] != row['total_references']:
            raise ValueError('String lacks complete recorded ownership evidence')
        value = row['ascii_prefix'].encode('ascii') + b'\0'
        if read_storage(original, int(row['original_va'], 16), len(value)) != value:
            raise ValueError('Reviewed string extent differs from original bytes: ' + row['symbol'])
        if row['symbol'] in names:
            raise ValueError('Duplicate reviewed storage symbol')
        names.add(row['symbol'])
        entries.append(dict(symbol=row['symbol'], original_va=row['original_va'], size=len(value),
                            check_initial_bytes=True, pointer_offsets=[],
                            evidence='Reviewed recovered string: ' + str(STRING_EVIDENCE.relative_to(REPO_ROOT))))
    return entries
