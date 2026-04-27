#!/usr/bin/env python3
"""
Watches src/matching/ for new files and plays the configured match sound.
Run from repo root:  python watch_matching.py
"""

import winsound
import time
import wave
from datetime import datetime
from pathlib import Path

MATCHING_DIR = Path(__file__).parent / "src" / "matching"
MATCH_SOUND_WAV = Path(__file__).parent / "build" / "temp" / "watch_matching_sound.wav"
BOOSTED_MATCH_SOUND_WAV = Path(__file__).parent / "build" / "temp" / "watch_matching_sound_200pct.wav"
FALLBACK_WAV = Path(r"C:\Windows\Media\tada.wav")
LOUDNESS_MULTIPLIER = 2.0


def _clip(value, low, high):
    if value < low:
        return low
    if value > high:
        return high
    return value


def make_louder_wav(src, dst, multiplier):
    """Write a PCM WAV with samples multiplied and clipped, so distortion is allowed."""
    dst.parent.mkdir(parents=True, exist_ok=True)

    with wave.open(str(src), "rb") as inp:
        params = inp.getparams()
        frames = inp.readframes(inp.getnframes())

    width = params.sampwidth
    boosted = bytearray()

    if width == 1:
        for sample in frames:
            centered = sample - 128
            boosted.append(_clip(int(centered * multiplier), -128, 127) + 128)
    elif width in (2, 3, 4):
        low = -(1 << (width * 8 - 1))
        high = (1 << (width * 8 - 1)) - 1
        for i in range(0, len(frames), width):
            sample = int.from_bytes(frames[i:i + width], "little", signed=True)
            sample = _clip(int(sample * multiplier), low, high)
            boosted.extend(sample.to_bytes(width, "little", signed=True))
    else:
        raise ValueError(f"unsupported WAV sample width: {width}")

    with wave.open(str(dst), "wb") as out:
        out.setparams(params)
        out.writeframes(bytes(boosted))


def match_sound_path():
    src = MATCH_SOUND_WAV if MATCH_SOUND_WAV.exists() else FALLBACK_WAV
    if src == FALLBACK_WAV:
        print(f"  configured sound not found, falling back to {FALLBACK_WAV}")

    try:
        if (not BOOSTED_MATCH_SOUND_WAV.exists() or
                BOOSTED_MATCH_SOUND_WAV.stat().st_mtime < src.stat().st_mtime):
            make_louder_wav(src, BOOSTED_MATCH_SOUND_WAV, LOUDNESS_MULTIPLIER)
        return str(BOOSTED_MATCH_SOUND_WAV)
    except Exception as e:
        print(f"  error preparing loud sound, falling back to {src}: {e}")
        return str(src)


def play_tada():
    try:
        winsound.PlaySound(match_sound_path(), winsound.SND_FILENAME | winsound.SND_ASYNC)
    except Exception as e:
        print(f"  error playing sound: {e}")


def get_files():
    return set(f.name for f in MATCHING_DIR.iterdir())


def main():
    if not MATCHING_DIR.exists():
        print(f"matching dir not found: {MATCHING_DIR}")
        return

    known = get_files()
    print(f"watching {MATCHING_DIR}  ({len(known)} files known)")
    print("press Ctrl+C to stop")

    while True:
        time.sleep(0.2)
        try:
            current = get_files()
        except Exception:
            continue

        new = current - known
        if new:
            ts = datetime.now().strftime("%H:%M")
            for name in sorted(new):
                print(f"  [{ts}] >> new: {name}")
                play_tada()
            known = current


if __name__ == "__main__":
    main()
