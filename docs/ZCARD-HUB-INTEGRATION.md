# ZCARD dentro do Z-GAME-HUB

O Z-GAME-HUB agora incorpora o código de leitura e geração do ecossistema ZCardEmu no próprio executável. Não é necessário distribuir `zcard_builder.exe`, `zconsole_demo.exe` ou outra ferramenta separada para montar e gerar cartões.

## O que o HUB monta

- Diretórios de projeto com `META/zgame.json`, `META/rom-runtime.json` ou `META/assets.zgf`.
- Cartões ZIP legacy `.zcard` e `.zcard.zip`.
- Containers `ZCF0` com regiões `MASTER`, `UPDATE`, `DLC`, `SAVE` e `USER`.
- Pacotes `ZUF0`.

A seção **ZCARD / arquivos** enumera os assets, mostra tamanhos e regiões, lê os manifestos e oferece geração `legacy`, `zcf` e `zuf` usando `ZCardBuilder` incorporado. O fluxo de geração acontece em uma thread do próprio programa para não travar a interface.

## Execução por plataforma

O HUB não emula ZCARD internamente.

- Manifestos `zgame-native-*` são aceitos somente quando a plataforma declarada corresponde ao sistema host. O executável é materializado no cache local e iniciado pelo sistema operacional.
- Manifestos `zcard-rom-runtime-*` nunca são enviados à CPU virtual. A ROM é materializada no cache local e encaminhada ao emulador externo configurado em **Configurações** para o sistema declarado (`gba`, `snes`, `gameboy-color`, `megadrive`, `ps2`, etc.).
- Se não houver emulador externo habilitado para o sistema, o HUB informa a configuração ausente e não tenta executar a ROM.
- O processo de lançamento usa argumentos sem shell e expande `{ROM}`/`{rom}` e `{CORE}`/`{core}`.

## Presets de build

O mesmo código possui presets em `CMakePresets.json`:

```powershell
cmake --preset windows-vs2022
cmake --build --preset windows-vs2022-release
```

```bash
cmake --preset linux-gcc
cmake --build --preset linux-release

cmake --preset macos-clang
cmake --build --preset macos-release
```

Para Android, configure `ANDROID_NDK_HOME` e use o Qt for Android correspondente:

```bash
cmake --preset android-arm64
cmake --build --preset android-release
```

O preset Android usa `arm64-v8a`, API 26 e o toolchain oficial do NDK. A distribuição APK/AAB continua dependente do kit Qt for Android e do SDK instalado no computador de build; o código do HUB e o código ZCARD permanecem os mesmos.
