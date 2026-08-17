#!/usr/bin/env python3
"""
Watches src/matching/ for new files and plays the configured match sound.
Run from repo root:  python watch_matching.py
"""

import argparse
import winsound
import time
import wave
from datetime import datetime
from pathlib import Path

MATCHING_DIR = Path(__file__).parent / "src" / "matching"
MATCH_SOUND_WAV = Path(__file__).parent / "watch_matching_sound.wav"
GENERATED_SOUND_DIR = Path(__file__).parent / "build" / "temp"
BOOSTED_MATCH_SOUND_WAV_TEMPLATE = "watch_matching_sound_{percent}pct.wav"
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


def prepare_sound(src, volume_scale):
    multiplier = LOUDNESS_MULTIPLIER * volume_scale
    percent = int(round(volume_scale * 100.0))
    output_wav = GENERATED_SOUND_DIR / BOOSTED_MATCH_SOUND_WAV_TEMPLATE.format(percent=percent)

    try:
        make_louder_wav(src, output_wav, multiplier)
        return str(output_wav)
    except Exception as e:
        print(f"  error preparing loud sound, falling back to {src}: {e}")
        return str(src)


def play_tada(sound_path):
    try:
        winsound.PlaySound(sound_path, winsound.SND_FILENAME | winsound.SND_ASYNC)
    except Exception as e:
        print(f"  error playing sound: {e}")


def get_files():
    return {
        f.name
        for f in MATCHING_DIR.iterdir()
        if f.is_file() and f.suffix.lower() in {".c", ".cpp"}
    }


def parse_args():
    parser = argparse.ArgumentParser(description="Watch src/matching/ for new files and play a match sound.")
    parser.add_argument(
        "volume",
        nargs="?",
        type=float,
        default=1.0,
        help="volume scale relative to the normal watch_matching.py sound (for example, 0.3 = 30%%)",
    )
    parser.add_argument(
        "--sound",
        type=Path,
        help=f"WAV file to play (default: {MATCH_SOUND_WAV.name}, then {FALLBACK_WAV})",
    )
    args = parser.parse_args()
    if args.volume < 0:
        parser.error("volume must be non-negative")
    return args


def main():
    args = parse_args()

    if not MATCHING_DIR.exists():
        print(f"matching dir not found: {MATCHING_DIR}")
        return

    sound_source = args.sound or MATCH_SOUND_WAV
    if not sound_source.is_file():
        if args.sound:
            print(f"sound not found: {sound_source}")
            return
        sound_source = FALLBACK_WAV
    if not sound_source.is_file():
        print(f"fallback sound not found: {sound_source}")
        return
    sound_path = prepare_sound(sound_source, args.volume)

    known = get_files()
    print(f"watching {MATCHING_DIR}  ({len(known)} files known, volume {args.volume:.0%})")
    print(f"sound: {sound_source}")
    print("press Ctrl+C to stop")

    try:
        while True:
            time.sleep(0.2)
            try:
                current = get_files()
            except OSError:
                continue
            new = current - known
            known = current
            if new:
                ts = datetime.now().strftime("%H:%M")
                for name in sorted(new):
                    print(f"  [{ts}] >> new: {name}")
                    play_tada(sound_path)
    except KeyboardInterrupt:
        print("\nstopped")


if __name__ == "__main__":
    main()
