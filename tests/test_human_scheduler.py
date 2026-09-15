from pathlib import Path
import shutil
import subprocess

import pytest


ROOT = Path(__file__).resolve().parents[1]


@pytest.mark.skipif(shutil.which('node') is None, reason='Node is required for the human scheduler VM tests')
def test_serialized_human_scheduler():
    result = subprocess.run(['node', str(ROOT/'tests/human_scheduler_vm.js')],
                            cwd=ROOT, check=True, capture_output=True, text=True)
    assert result.stdout.strip() == 'PASS: human serialized scheduler VM tests'
