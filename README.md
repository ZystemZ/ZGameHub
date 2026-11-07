# Z-GAME HUB

**Launcher, biblioteca e centro de controle do ecossistema Zystem/ZConsole.**

O Z-GAME HUB é um aplicativo nativo desenvolvido em C++ e Qt/QML para organizar jogos, aplicativos, ROMs, ZCARDs, ports e ferramentas em uma única interface. A experiência visual usa a identidade do **ZCONSOLE**: tema escuro, painéis translúcidos, brilho verde-neon, navegação por seções, carrossel de capas, foco por teclado e animações suaves.

> Esta documentação descreve a edição nativa multiplataforma do HUB. A pasta `ui/` contém a interface Qt/QML; a pasta `src/` contém o catálogo, scanner, launcher, integração Quiver e suporte incorporado a ZCARD.

## Sumário

- [Visão geral](#vis%C3%A3o-geral)

- [Principais recursos](#principais-recursos)

- [Como o sistema funciona](#como-o-sistema-funciona)

- [ZCARD](#zcard)

- [Execução de jogos e ROMs](#execu%C3%A7%C3%A3o-de-jogos-e-roms)

- [Interface ZCONSOLE](#interface-zconsole)

- [Arquitetura](#arquitetura)

- [Requisitos](#requisitos)

- [Compilação no Windows](#compila%C3%A7%C3%A3o-no-windows)

- [Compilação multiplataforma](#compila%C3%A7%C3%A3o-multiplataforma)

- [Organização do código](#organiza%C3%A7%C3%A3o-do-c%C3%B3digo)

- [Integrações](#integra%C3%A7%C3%B5es)

- [Segurança e limites](#seguran%C3%A7a-e-limites)

- [Créditos e referências](#cr%C3%A9ditos-e-refer%C3%AAncias)

- [Licença](#licen%C3%A7a)

## Visão geral

O HUB centraliza o acesso aos conteúdos instalados no computador ou armazenados em cartões ZCARD. Ele não substitui os sistemas operacionais, launchers ou emuladores instalados pelo usuário. Em vez disso, organiza os caminhos, manifesta as configurações e inicia cada conteúdo pelo backend apropriado.

O fluxo principal é:

```
Biblioteca do usuário
        │
        ├── Jogos e aplicativos nativos
        ├── ROMs e imagens
        ├── ZCARDs / ZGF / ZCF0 / ZUF0
        ├── Ports e recompilações Quiver
        └── Jogos de launchers conectados
                │
                ▼
          Z-GAME HUB
                │
        ├── Sistema operacional host
        ├── Launcher oficial configurado
        └── Emulador externo configurado
```

O HUB não baixa ROMs, BIOS, jogos proprietários ou arquivos de conta. Ele trabalha com arquivos que o usuário possui ou com releases públicas selecionadas pelo próprio usuário.

## Principais recursos

- Biblioteca local persistente em SQLite.

- Carrossel visual com capas e seleção por teclado.

- Tela de biblioteca com pesquisa, filtros e plataformas.

- Inclusão manual de jogos, aplicativos, executáveis, atalhos e ROMs.

- Capas locais copiadas para o diretório de dados do aplicativo.

- Detecção e configuração de RetroArch e cores libretro.

- Tela **ROMs e BIOS** para pesquisa local de ROMs e arquivos de suporte.

- Tela **ZCARD / arquivos** para montar, inspecionar e gerar cartões.

- ZCARDs exibidos diretamente na mesma biblioteca de jogos e aplicativos.

- Capas internas dos ZCARDs carregadas e armazenadas em cache local.

- Clique em um ZCARD para montar e executar seu conteúdo.

- Execução de jogos nativos pelo sistema operacional compatível.

- Encaminhamento de ROMs para o emulador externo configurado.

- Integração com Steam, Epic Games Launcher, Ubisoft Connect e Heroic.

- Integração nativa com o catálogo comunitário Quiver.

- Navegação Quiver, download de releases escolhidas e inclusão dos executáveis no catálogo.

- Atalho global `F11` para alternar entre janela normal e tela cheia.

- Interface QML com controles personalizados, foco neon, popups escuros e transições.

- Presets CMake para Windows, Linux, macOS e Android.

## Como o sistema funciona

### Catálogo local

O catálogo é armazenado em SQLite no diretório de dados do sistema. Cada item possui, entre outros campos:

- título;

- caminho local;

- plataforma;

- origem (`manual`, `Steam`, `Epic`, `Ubisoft`, `Heroic`, `Quiver` ou `zcard`);

- comando de inicialização;

- capa;

- disponibilidade.

Jogos tradicionais são carregados pelo `GameCatalog`. ZCARDs são indexados pelo `ZCardService` e combinados com os jogos normais no mesmo modelo QML da biblioteca.

### Descoberta automática de ZCARDs

Na inicialização, o HUB procura cartões nas pastas padrão:

```
<dados do aplicativo>/ZCards
<Documentos>/ZCards
<home do usuário>/ZCards
```

Também é possível abrir um arquivo ou diretório manualmente pela tela **ZCARD / arquivos**. Ao abrir um cartão manualmente, ele também é registrado na lista de acesso da biblioteca.

### Capas de ZCARD

O HUB procura capas dentro do próprio cartão. São reconhecidos nomes contendo termos como:

```
cover
capa
poster
boxart
thumbnail
```

Formatos de imagem aceitos:

```
PNG, JPG, JPEG e WEBP
```

A capa encontrada é convertida para PNG e salva no cache local do aplicativo. O ZCARD original não é alterado.

## ZCARD

O suporte a ZCARD está incorporado no executável do HUB. Não é necessário distribuir um `zcard_builder.exe` separado.

### Formatos carregados

O HUB pode montar e inspecionar:

- diretórios de projeto com `META/zgame.json`;

- diretórios com `META/rom-runtime.json`;

- diretórios com `META/assets.zgf`;

- cartões ZIP legacy `.zcard` e `.zcard.zip`;

- containers `ZCF0`;

- regiões `MASTER`, `UPDATE`, `DLC`, `SAVE` e `USER`;

- pacotes `ZUF0`.

### Geração

A tela **ZCARD / arquivos** gera três formatos:

```
legacy
zcf
zuf
```

A geração utiliza o código incorporado do `ZCardBuilder`, executado em uma thread separada para não bloquear a interface. O relatório de criação e validação aparece dentro da própria tela.

### Manifestos

Um cartão nativo pode declarar um executável por meio de `META/zgame.json`:

```json
{
  "format": "zgame-native-0.2",
  "title": "Meu jogo",
  "platform": "windows",
  "executable": "native/windows-x86/game.exe"
}
```

Uma ROM pode usar `META/rom-runtime.json`:

```json
{
  "format": "zcard-rom-runtime-0.1",
  "title": "Minha ROM",
  "rom": "roms/game.gba",
  "system": "gba"
}
```

### Montar e executar

Ao clicar em um ZCARD da biblioteca:

1. o HUB monta o cartão;

1. lê o manifesto;

1. localiza a capa e o conteúdo;

1. valida o caminho do arquivo;

1. materializa o executável ou a ROM em cache quando necessário;

1. executa o programa nativo no sistema compatível ou encaminha a ROM ao emulador configurado.

## Execução de jogos e ROMs

### Jogos nativos

Executáveis nativos só são executados quando a plataforma do cartão corresponde ao sistema host:

| Manifesto | Sistema esperado |
| --- | --- |
| `platform: windows` | Windows |
| `platform: linux` | Linux |
| `platform: macos` ou `darwin` | macOS |
| `platform: android` | Android |

Um executável Windows não é enviado para um emulador virtual pelo HUB. Ele é iniciado pelo sistema operacional Windows. O mesmo princípio vale para Linux, macOS e Android.

### ROMs

ROMs não são tratadas como executáveis ZConsole. Elas são encaminhadas ao perfil configurado em **Configurações** para o sistema declarado no manifesto.

Exemplos de sistemas:

```
gba
nes
snes
gameboy
gameboy-color
megadrive
n64
ps1
ps2
gamecube
```

A configuração pode conter:

- executável do emulador;

- argumentos;

- core opcional;

- preset de tela cheia ou janela;

- proporção de imagem;

- marcador `{ROM}` ou `{rom}`;

- marcador `{CORE}` ou `{core}`.

Se nenhum emulador estiver configurado, o HUB não tenta executar a ROM e informa o que precisa ser configurado.

## Interface ZCONSOLE

A interface foi reconstruída individualmente em Qt/QML, sem usar a imagem de referência como screenshot ou plano de fundo.

A linguagem visual inclui:

- fundo atmosférico escuro;

- painéis translúcidos;

- brilho verde-neon;

- carrossel de capas com profundidade;

- navegação por seções;

- foco visual para teclado e controle;

- botões `ZButton`;

- campos `ZTextField`;

- combos `ZComboBox`;

- áreas `ZTextArea`;

- popups escuros;

- animações de escala, opacidade, foco e transição;

- atalho `F11` para tela cheia.

Os componentes visuais ficam em:

```
ui/components/ZButton.qml
ui/components/ZTextField.qml
ui/components/ZComboBox.qml
ui/components/ZTextArea.qml
ui/components/GameCard.qml
```

## Arquitetura

```
Z-GAME-HUB-Windows/
├── CMakeLists.txt
├── CMakePresets.json
├── README.md
├── THIRD-PARTY-NOTICES.txt
├── src/
│   ├── main.cpp
│   ├── GameCatalog.h/.cpp
│   ├── Scanner.h/.cpp
│   ├── Launcher.h/.cpp
│   ├── QuiverIntegration.h/.cpp
│   ├── ZCardService.h/.cpp
│   └── zconsole/
│       ├── include/zconsole/
│       └── src/
├── ui/
│   ├── Main.qml
│   └── components/
├── docs/
├── scripts/
└── packaging/
```

### Módulos principais

- `GameCatalog`: banco SQLite, biblioteca, capas, launchers e emuladores.

- `Scanner`: procura ROMs, BIOS, aplicativos e candidatos em pastas locais.

- `Launcher`: inicialização de processos e comandos configurados.

- `QuiverIntegration`: consulta de catálogo, releases e instalação de ports.

- `ZCardService`: montagem, inspeção, capas, manifestos e geração de ZCARD.

- `src/zconsole`: código incorporado do sistema ZCARD e estruturas de runtime necessárias.

- `Main.qml`: composição da interface, navegação, carrossel e interações.

## Requisitos

### Windows

- Windows 10 ou Windows 11 x64.

- Visual Studio 2022 com ferramentas C++.

- Qt 6.8.3 MSVC 2022 x64.

- CMake.

- Ninja.

- Python 3 para o fluxo automático de instalação.

- SQLite via plugin `QSQLITE` do Qt.

### Linux

- Qt 6.5 ou superior com Core, Gui, QML, Quick, SQL e Network.

- CMake 3.21 ou superior.

- Ninja.

- GCC ou Clang com C++20.

### macOS

- Qt 6.5 ou superior.

- Xcode Command Line Tools.

- CMake.

- Ninja.

- Apple Clang com C++20.

### Android

- Qt for Android correspondente à versão usada.

- Android SDK.

- Android NDK.

- CMake e Ninja.

- Variável `ANDROID_NDK_HOME` configurada.

## Compilação no Windows

O caminho mais simples é executar:

```
scripts\setup-windows.bat
```

O script verifica ou prepara:

- Visual Studio 2022 C++;

- CMake;

- Ninja;

- Python;

- Qt 6.8.3 MSVC x64;

- módulos Qt Core, Gui, QML, Quick, SQL e Network;

- plugin SQLite do Qt.

Se as dependências já estiverem preparadas, use um **x64 Native Tools Command Prompt for VS 2022**:

```
scripts\build-windows.bat
```

O build gera:

```
build\windows\z-game-hub.exe
dist\windows\Z-GAME-HUB\
dist\windows\Z-GAME-HUB-Windows-v1.3.0-x64.zip
```

Se o Inno Setup estiver disponível no `PATH`, também será criado um instalador `.exe`.

O Qt pode ser informado manualmente:

```
set QT_ROOT=C:\Users\SeuUsuario\AppData\Local\Qt\6.8.3\msvc2022_64
scripts\build-windows.bat
```

## Compilação multiplataforma

Os presets estão em `CMakePresets.json`.

### Windows com Visual Studio

```
cmake --preset windows-vs2022
cmake --build --preset windows-vs2022-release
```

### Windows com MinGW/Ninja

```bash
cmake --preset windows-mingw-x64
cmake --build --preset windows-mingw-release
```

### Linux

```bash
cmake --preset linux-gcc
cmake --build --preset linux-release
```

### macOS

```bash
cmake --preset macos-clang
cmake --build --preset macos-release
```

### Android arm64-v8a

```bash
export ANDROID_NDK_HOME=/caminho/para/android-ndk
cmake --preset android-arm64
cmake --build --preset android-release
```

Também existe um script auxiliar:

```bash
scripts/build-platform.sh linux-gcc
scripts/build-platform.sh macos-clang
scripts/build-platform.sh android-arm64
```

O preset Android prepara a compilação CMake para `arm64-v8a`. A geração final de APK/AAB ainda depende do kit Qt for Android, SDK, NDK e configuração de empacotamento disponíveis no computador de build.

## Integrações

### ZConsole

O Z-GAME HUB é um dos projetos do ecossistema Zystem e serve como central para o projeto ZConsole, seus cartões, ROMs, projetos nativos e aplicativos relacionados.

- Projeto principal: [ZConsole](https://github.com/zystemz/zconsole)

- Organização/perfil do mantenedor: [github.com/zystemz](https://github.com/zystemz/)

### ZCardEmu

O suporte a ZCARD foi incorporado a partir do código do projeto ZCardEmu fornecido para integração. Ele fornece as estruturas de cartão, runtime de assets, containers, regiões, arquivos e builder usados pelo HUB.

O endereço público específico do repositório ZCardEmu não foi informado neste pacote. Consulte o perfil do mantenedor para localizar a publicação correspondente:

- [Projetos de zystemz no GitHub](https://github.com/zystemz/)

### Quiver

O HUB implementa uma integração nativa em Qt/QML com o catálogo comunitário Quiver. Ele não distribui nem executa o aplicativo Quiver separado.

- [Quiver Launcher](https://github.com/tgeorgiadis/quiver-launcher)

- [Quiver Community App Catalog](https://github.com/tgeorgiadis/quiver-community-app-catalog)

- [Quiver Launcher — licença](https://github.com/tgeorgiadis/quiver-launcher/blob/main/LICENSE)

O catálogo comunitário é legado/descontinuado e pode não receber novas submissões. Os projetos instalados pelo catálogo continuam sujeitos às licenças e regras de seus próprios mantenedores.

### Steam

A biblioteca Steam é descoberta localmente e o HUB solicita o lançamento pelo protocolo `steam://rungameid/<appid>`. Steam, jogos, autenticação, DRM, downloads e atualizações pertencem à Valve e não são embutidos no HUB.

- [Steamworks](https://partner.steamgames.com/)

- [Steam](https://store.steampowered.com/)

### Epic Games Launcher

O HUB lê manifests locais `.item` e usa o protocolo de ativação do Epic Games Launcher quando disponível.

- [Epic Games Store](https://store.epicgames.com/)

- [Epic Developer Resources](https://dev.epicgames.com/)

### Ubisoft Connect

O HUB pode localizar instalações e IDs do Ubisoft Connect no Windows e solicitar a inicialização pelo protocolo `uplay://`.

- [Ubisoft Connect](https://www.ubisoft.com/en-us/ubisoft-connect)

### Heroic Games Launcher

A integração aceita protocolos `heroic://launch` para instalações configuradas. Heroic não é incluído no pacote.

- [Heroic Games Launcher](https://github.com/Heroic-Games-Launcher/HeroicGamesLauncher)

### RetroArch e cores libretro

O HUB detecta RetroArch e cores libretro instalados pelo usuário. O executável e o core são configurados por plataforma; o HUB não redistribui cores ou jogos.

- [RetroArch](https://www.retroarch.com/)

- [Libretro](https://www.libretro.com/)

- [Libretro cores](https://github.com/libretro)

### Qt, CMake e SQLite

- [Qt](https://www.qt.io/)

- [Qt Licensing](https://www.qt.io/licensing/)

- [CMake](https://cmake.org/)

- [Ninja](https://ninja-build.org/)

- [SQLite](https://www.sqlite.org/)

## Segurança e limites

- O HUB não executa ROM como executável ZEXE.

- Caminhos de arquivos de cartão são validados contra traversal.

- Comandos de emulador são iniciados sem shell quando configurados pelo catálogo.

- O HUB não baixa ROMs, BIOS, firmware ou jogos proprietários.

- Arquivos compactados dependem do emulador/core configurado; o HUB não assume que todo `.zip`, `.7z` ou `.rar` seja executável.

- Uma extensão `.iso` não determina sozinha o sistema. O manifesto deve declarar se é PC, PlayStation, Nintendo ou outro sistema.

- Executáveis nativos são aceitos somente para o sistema operacional compatível.

- Launchers e emuladores externos precisam estar instalados e configurados pelo usuário.

- A integração Quiver baixa somente releases escolhidas pelo usuário a partir das fontes públicas indicadas no catálogo.

- A imagem automática de jogos Steam pode depender de conexão e do CDN público da Steam.

- O plugin SQLite e as bibliotecas Qt devem respeitar as licenças de suas respectivas distribuições.

- Não redistribua jogos, ROMs, BIOS, firmware ou assets de terceiros sem autorização.

## Créditos e referências

### Autoria do projeto

- **Zystem / zystemz** — arquitetura do Z-GAME HUB, integração com ZConsole, interface ZCONSOLE, catálogo, scanner, launcher e integração de ZCARD.

- Repositórios do ecossistema: [github.com/zystemz](https://github.com/zystemz/).

### Projetos incorporados ou utilizados como referência

- **ZConsole** — formato, runtime e ecossistema de cartões: [github.com/zystemz/zconsole](https://github.com/zystemz/zconsole).

- **ZCardEmu** — código de containers, assets, runtime e builder fornecido para integração neste projeto. O endereço público específico não foi informado; consulte [github.com/zystemz](https://github.com/zystemz/).

- **Quiver Launcher** — referência de catálogo e integração de ports: [github.com/tgeorgiadis/quiver-launcher](https://github.com/tgeorgiadis/quiver-launcher).

- **Quiver Community App Catalog** — listas públicas de catálogo: [github.com/tgeorgiadis/quiver-community-app-catalog](https://github.com/tgeorgiadis/quiver-community-app-catalog).

- **Qt** — toolkit gráfico, QML, SQLite plugin e runtime de aplicação: [qt.io](https://www.qt.io/).

- **CMake/Ninja** — configuração e compilação: [cmake.org](https://cmake.org/) e [ninja-build.org](https://ninja-build.org/).

- **RetroArch/Libretro** — emulação externa e cores configuráveis: [retroarch.com](https://www.retroarch.com/) e [github.com/libretro](https://github.com/libretro).

As marcas Steam, Epic Games, Ubisoft, Heroic, RetroArch, Qt, CMake, Ninja e demais nomes de terceiros pertencem aos seus respectivos proprietários. A presença de uma integração não significa endosso, propriedade ou distribuição desses produtos pelo Z-GAME HUB.

## Licença

Este repositório ainda não contém um arquivo `LICENSE`. Até que uma licença seja adicionada pelo mantenedor, não presuma autorização para copiar, modificar, redistribuir ou incorporar o código.

As dependências e integrações de terceiros possuem suas próprias licenças. Consulte [`THIRD-PARTY-NOTICES.txt`](THIRD-PARTY-NOTICES.txt) antes de redistribuir builds.

## Contribuição

Sugestões, correções e pull requests são bem-vindos. Ao contribuir:

1. descreva o sistema operacional e a versão do Qt usada;

1. informe o comando de build executado;

1. inclua o erro completo quando houver falha;

1. não envie ROMs, BIOS, jogos proprietários ou arquivos pessoais;

1. preserve a separação entre o HUB, os emuladores externos e os conteúdos dos usuários.
