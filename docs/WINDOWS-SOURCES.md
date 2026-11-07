# Referências técnicas — edição Windows 1.3.0

A integração trabalha somente com dados locais e tenta iniciar os jogos pelo cliente que os instalou. Os formatos de manifesto e as chaves do Registro podem mudar; por isso, mantenha o scanner defensivo e confira as instalações reais no Windows.

## Bibliotecas e lançamento

- [Epic Games — Multiple Launcher Installs](https://dev.epicgames.com/documentation/unreal-engine/multiple-launcher-unreal-engine-installs?lang=en-US): descreve manifests locais do Launcher no `%ProgramData%\Epic`, layouts PCB/portáteis e a finalidade de informar o diretório de instalação de cada aplicação.
- [Playnite — EpicLauncher.cs](https://github.com/JosefNemec/PlayniteExtensions/blob/master/source/Libraries/EpicLibrary/EpicLauncher.cs): implementação pública que lê arquivos `*.item` como JSON em `EpicGamesLauncher/Data/Manifests` e usa campos como `AppName`, `DisplayName` e `InstallLocation`. O scanner também exige que o diretório esteja presente.
- [Epic Games — Protocol Activation](https://dev.epicgames.com/docs/epic-games-store/protocol-activation): documenta o esquema `com.epicgames.launcher`, `action=launch` e a alternativa de usar o caminho de instalação codificado na URI. O scanner obtém esse caminho do manifesto local e confere o destino antes de abrir o protocolo.
- [Ubisoft Support — Finding the installation location for your Ubisoft game](https://www.ubisoft.com/en-us/help/connectivity-and-performance/article/finding-the-installation-location-for-your-ubisoft-game/000063991): confirma a pasta padrão de jogos Ubisoft Connect e o fluxo do cliente para consultar o diretório instalado.
- [RizSavio/UplayGameIDs](https://github.com/RizSavio/UplayGameIDs): referência comunitária, não documentação da Ubisoft, para a chave `SOFTWARE\WOW6432Node\Ubisoft\Launcher\Installs`, IDs numéricos e o padrão de URI `uplay://launch/<ID>/0`. Essa integração deve ser validada com clientes e jogos reais; IDs/URIs podem variar por jogo ou conta.
- [Heroic Games Launcher — repositório oficial](https://github.com/Heroic-Games-Launcher/HeroicGamesLauncher): código e releases do cliente suportado pela variante Windows.
- [Steam — site oficial](https://store.steampowered.com/about/): instalador do cliente Steam.

## Capas e imagens

- [Steamworks — Graphical Assets](https://partner.steamgames.com/doc/store/assets): informa as dimensões de cápsula de biblioteca Steam de 600 × 900 px. O HUB tenta usar `library_600x900.jpg` por AppID no CDN público Steam e recorre a `header.jpg` se a arte vertical não estiver disponível. Também procura as imagens correspondentes no cache de biblioteca local da Steam.
- [Steam Store appdetails — exemplo público do AppID 570](https://store.steampowered.com/api/appdetails?appids=570): resposta pública consultada durante a implementação, que inclui `header_image` e links de imagem por AppID. O cliente usa o endpoint estático do CDN apenas no momento da importação Steam sem arte local; não envia consultas por nome nem exige uma chave de API.
- [Heroic Games Launcher — issue sobre `art_cover` e `art_square`](https://github.com/Heroic-Games-Launcher/HeroicGamesLauncher/issues/2277): registra esses campos na biblioteca sideload e a limitação relatada para referências a imagens locais. O HUB só importa esses caminhos quando apontam a arquivos de imagem locais existentes; não presume que URL remota no JSON seja uma capa validada.
- [Heroic Games Launcher — issue sobre cache de imagens](https://github.com/Heroic-Games-Launcher/HeroicGamesLauncher/issues/5598): menciona a pasta `images-cache` do Heroic. Cada capa escolhida ou importada pelo HUB é copiada para a sua própria pasta de dados, para não depender do cache nem da permanência da imagem original.

As imagens importadas pelo HUB são validadas e salvas em PNG na pasta `covers` de `QStandardPaths::AppLocalDataLocation`. O HUB não redistribui os arquivos de arte com o código do aplicativo. Para Epic Games, Ubisoft Connect e outras lojas sem um identificador de imagem confiável nos metadados locais, o usuário pode selecionar a capa manualmente.

## Quiver e busca local de ROMs

- [Quiver Launcher — repositório oficial](https://github.com/tgeorgiadis/quiver-launcher): referência para o schema e o comportamento do catálogo/release usado pelo port nativo em Qt/QML. A interface própria do Quiver não é aberta nem executada pelo Z-GAME HUB.
- [Catálogo comunitário Quiver legado](https://github.com/tgeorgiadis/quiver-community-app-catalog): o próprio repositório informa que está descontinuado e não aceita novas submissões; as listas existentes continuam disponíveis para instalações compatíveis. A página informa [quiverlauncher.com/submit](https://quiverlauncher.com/submit) como canal atual de sugestão de apps.
- O HUB consome o `index.json` e as quatro listas JSON legadas via `raw.githubusercontent.com`. Para apps do catálogo, consulta a release mais recente pela API GitHub ou GitLab, limita a instalação automática a arquivos ZIP e extrai em `QuiverApps` nos dados locais do usuário. `filesToAdd`, quando presente, é aplicado como arquivos auxiliares vazios de nível superior, conforme a semântica do Quiver; o HUB não fornece conteúdo de ROM, BIOS ou jogos originais.
- A busca de ROMs do HUB é uma varredura recursiva de uma pasta escolhida pelo usuário. Ela não baixa jogos, ROMs, BIOS nem firmware. A detecção de arquivos de suporte por nome/pasta é indicativa e não valida se um emulador específico tem todos os arquivos requeridos.

## Preparação do ambiente de build

- [aqtinstall — Getting Started](https://aqtinstall.readthedocs.io/en/latest/getting_started.html) e [CLI](https://aqtinstall.readthedocs.io/en/latest/cli.html): documentam a instalação automatizada, a lista de módulos adicionais e que `install-qt` instala o kit Qt base por padrão. O script baixa Qt 6.8.3 `win64_msvc2022_64` sob `%LOCALAPPDATA%\Qt` sem passar `qtdeclarative` como módulo opcional; esse nome não aparece no catálogo `--modules` para esse kit. O aqt é uma ferramenta comunitária, não o instalador oficial do Qt.
- [aqtinstall — repositório e requisitos](https://github.com/miurahr/aqtinstall): registra Python mínimo 3.10 e recomenda a versão 3.14, além de explicar que a ferramenta distribui um SDK Qt sujeito às licenças Qt.
- [Qt QML](https://doc.qt.io/qt-6/qtqml-index.html) e [Qt Quick Controls](https://doc.qt.io/qt-6/qtquickcontrols-index.html): documentam os módulos QML/QML Controls usados pela interface.
- [Microsoft — Visual Studio Build Tools workload and component IDs](https://learn.microsoft.com/en-us/visualstudio/install/workload-component-id-vs-build-tools?view=visualstudio): identifica o workload C++ Desktop como `Microsoft.VisualStudio.Workload.VCTools`.
- [Microsoft — Visual Studio command-line parameters](https://learn.microsoft.com/en-us/visualstudio/install/use-command-line-parameters-to-install-visual-studio?view=visualstudio): descreve instalação com workloads e opções de espera/passiva usadas pelo bootstrapper.
- [Microsoft WinGet](https://learn.microsoft.com/en-us/windows/package-manager/winget/): gerenciador usado pelo script para CMake, Ninja, Python, Build Tools e instalações opcionais.
- [Qt for Windows deployment](https://doc.qt.io/qt-6/windows-deployment.html): documentação oficial de `windeployqt` e implantação de bibliotecas/plugins Qt.

## Instalação opcional dos launchers

Os clientes não são redistribuídos pelo HUB. O BAT usa WinGet com confirmação separada antes de cada instalação:

- Steam: `Valve.Steam` — [Steam oficial](https://store.steampowered.com/about/).
- Heroic: `HeroicGamesLauncher.HeroicGamesLauncher` — [FAQ oficial Heroic](https://heroicgameslauncher.com/faq).
- Epic Games Launcher: `EpicGames.EpicGamesLauncher` — [manifesto WinGet](https://github.com/microsoft/winget-pkgs/tree/master/manifests/e/EpicGames/EpicGamesLauncher) e [download oficial](https://store.epicgames.com/download).
- Ubisoft Connect: `Ubisoft.Connect` — [catálogo WinGet](https://winget.run/pkg/Ubisoft/Connect) e [site oficial Ubisoft](https://www.ubisoft.com/en-us/ubisoft-connect).
- RetroArch: `Libretro.RetroArch` — [downloads oficiais](https://www.retroarch.com/?page=platforms).

O script de dependências de desenvolvimento pode instalar componentes de build e baixar um SDK Qt local ao usuário. Isso não coloca esses itens dentro do pacote final de distribuição. Revise os termos e avisos de terceiros antes de redistribuir um build Qt.
