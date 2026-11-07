#!/usr/bin/env bash
set -euo pipefail
preset="${1:-linux-gcc}"
case "$preset" in
  windows-vs2022) build_preset="windows-vs2022-release" ;;
  windows-mingw-x64) build_preset="windows-mingw-release" ;;
  linux-gcc) build_preset="linux-release" ;;
  macos-clang) build_preset="macos-release" ;;
  android-arm64) build_preset="android-release" ;;
  *) echo "preset desconhecido: $preset" >&2; echo "use: windows-vs2022 | windows-mingw-x64 | linux-gcc | macos-clang | android-arm64" >&2; exit 2 ;;
esac
cmake --preset "$preset"
cmake --build --preset "$build_preset"
