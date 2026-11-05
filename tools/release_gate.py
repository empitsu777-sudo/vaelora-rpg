#!/usr/bin/env python3
"""Strict, evidence-based Vaelora release gate. No optional auto-pass."""
import argparse
import hashlib
import json
import pathlib
import sys

REQUIRED = ("python_tests", "native_sanitizer", "twice_clean_rom", "emulator_boot",
            "emulator_collision", "emulator_doors", "emulator_dialogue",
            "emulator_movement", "visual_sprite_review", "user_acceptance")


def check(evidence: dict, rom: pathlib.Path | None = None, evidence_dir: pathlib.Path | None = None) -> list[str]:
    errors = []
    if not isinstance(evidence, dict):
        return ["evidence must be a JSON object"]
    if evidence.get("release_status") != "candidate_for_acceptance":
        errors.append("release_status must be candidate_for_acceptance")
    if evidence.get("open_p0_count") != 0:
        errors.append("open_p0_count must be zero")
    evidence_dir = (evidence_dir or pathlib.Path.cwd()).resolve()
    for key in REQUIRED:
        value = evidence.get(key)
        if not isinstance(value, dict) or value.get("passed") is not True or not isinstance(value.get("evidence"), str) or len(value["evidence"].strip()) < 8:
            errors.append(f"{key}: requires passed=true and a concrete evidence reference")
            continue
        evidence_file = value.get("evidence_file")
        if not isinstance(evidence_file, str) or not evidence_file:
            errors.append(f"{key}: missing evidence_file")
            continue
        candidate = (evidence_dir / evidence_file).resolve()
        if not candidate.is_relative_to(evidence_dir) or not candidate.is_file():
            errors.append(f"{key}: evidence_file unavailable or outside evidence directory")
            continue
        expected_hash = value.get("evidence_sha256")
        if not isinstance(expected_hash, str) or len(expected_hash) != 64 or hashlib.sha256(candidate.read_bytes()).hexdigest() != expected_hash:
            errors.append(f"{key}: evidence file SHA256 missing or incorrect")
    if rom is None:
        errors.append("actual .gba file required for SHA256 verification")
    elif not rom.is_file():
        errors.append(f"ROM does not exist: {rom}")
    elif evidence.get("rom_sha256") != hashlib.sha256(rom.read_bytes()).hexdigest():
        errors.append("rom_sha256 mismatch")
    return errors


def main() -> int:
    ap = argparse.ArgumentParser(description="Reject builds lacking real emulator/player evidence")
    ap.add_argument("evidence", type=pathlib.Path)
    ap.add_argument("--rom", type=pathlib.Path)
    args = ap.parse_args()
    try:
        evidence = json.loads(args.evidence.read_text(encoding="utf-8"))
    except (OSError, ValueError) as exc:
        print(f"FAIL: cannot parse evidence: {exc}", file=sys.stderr)
        return 2
    errors = check(evidence, args.rom, args.evidence.parent)
    for error in errors:
        print("FAIL:", error, file=sys.stderr)
    if errors:
        print(f"NO RELEASE: {len(errors)} unmet gates")
        return 1
    print("Gate evidence complete; independent human review still required.")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())