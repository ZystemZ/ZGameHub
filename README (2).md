# Z-GAME HUB — Windows

Edição nativa para Windows 10/11 x64, release **1.3.0**. Esta edição não usa a camada de jogos Linux: não instala nem executa Proton, Wine, Flatpak, Lutris ou Bottles.

## O que faz

- Descobre bibliotecas Steam Windows a partir de caminhos usuais e chaves do Registro, lê bibliotecas extras em `libraryfolders.vdf` e abre jogos por `steam://rungameid/<appid>`.
- Lê metadados Heroic em `%APPDATA%\heroic` e `%USERPROFILE%\.config\heroic` / `legendary`, e delega o lançamento ao Heroic para Windows pelo protocolo `heroic://launch`.
- Lê manifests `.item` locais do Epic Games Launcher e lança pela ativação de protocolo `com.epicgames.launcher`.
- Lê IDs e diretórios de instalação Ubisoft Connect no Registro do Windows e solicita a abertura por `uplay://launch/<id>/0`.
- Permite cadastrar jogos e aplicativos manualmente; executáveis `.exe` e atalhos `.lnk` podem ser iniciados diretamente.
- Mostra capas na biblioteca e permite escolher, substituir ou remover a imagem na inclusão ou edição. Cada imagem é validada e copiada para a pasta de dados do HUB, sem depender do local original.
- Porta para dentro do HUB a experiência de catálogo do Quiver: pesquisa as listas comunitárias JSON, consulta releases GitHub/GitLab, baixa pacotes ZIP, extrai-os numa pasta local e adiciona os executáveis encontrados à biblioteca. A navegação e a execução ficam no próprio Z-GAME HUB; não é necessário abrir outro launcher Quiver.
- Procura capas locais no cache Steam e tenta obter a cápsula vertical pública da Steam ao importar um jogo sem imagem local; se não houver arte vertical, tenta o cabeçalho do jogo. Para Epic, Ubisoft e Heroic, usa caminhos de imagem locais que venham nos metadados disponíveis; se não houver, a capa pode ser escolhida manualmente.
- Detecta RetroArch e cores `*_libretro.dll` nos diretórios comuns do Windows.
- Mantém o catálogo local SQLite e a interface da biblioteca.
- Inclui a tela **ROMs e BIOS**, que pesquisa recursivamente uma pasta escolhida, reconhece formatos comuns de ROM/imagem e mostra alguns nomes conhecidos de BIOS/firmware ou arquivos encontrados em pastas `BIOS`, `Firmware` e `System`. ROMs podem ser adicionadas à biblioteca e iniciadas com um emulador configurado por plataforma. Arquivos de suporte são apenas listados e não são importados como jogos.
- Inclui a tela **Quiver**, com catálogo pesquisável, atualização das listas e instalação de ports/recompilações dentro do HUB.
- A interface nativa foi atualizada com a identidade visual ZCONSOLE: fundo atmosférico, glass panels, navegação neon, hero animado, carrossel com profundidade, estados de hover/foco e transições suaves. A implementação está em `ui/Main.qml`, `ui/components/ZButton.qml` e `ui/components/GameCard.qml`; as ações do catálogo continuam conectadas aos mesmos objetos C++.
- O HUB incorpora o sistema ZCARD no próprio executável: montagem de diretórios ZGF, `.zcard`/ZIP, ZCF0, ZUF0, enumeração de assets, leitura de manifestos e geração `legacy`/`zcf`/`zuf`. Não é necessário distribuir um `zcard_builder.exe` separado.
- A execução segue a plataforma do cartão: programas `zgame-native-*` são entregues ao SO host; ROMs `zcard-rom-runtime-*` são encaminhadas somente ao emulador externo configurado para o sistema. O HUB não executa emulação interna.
- Os presets `windows-vs2022`, `windows-mingw-x64`, `linux-gcc`, `macos-clang` e `android-arm64` estão em `CMakePresets.json`. O detalhamento está em `docs/ZCARD-HUB-INTEGRATION.md`.

Na tela **Quiver**, o HUB incorpora a busca e a instalação do catálogo: baixa o `index.json` e as quatro listas JSON legadas para cache local, permite pesquisar por jogo, projeto, plataforma/tag e instala um pacote `.zip` publicado pelo repositório GitHub ou GitLab correspondente. Os executáveis encontrados entram na biblioteca, de onde são iniciados pelo Z-GAME HUB. O Quiver Launcher original não é aberto como um segundo app. O catálogo comunitário fornecido está descontinuado e não recebe novas submissões; as listas existentes continuam publicadas. A instalação não inclui jogos originais, ROMs ou BIOS.

URLs Git fornecidas para consulta ou clonagem dos projetos:

```text
https://github.com/tgeorgiadis/quiver-community-app-catalog.git
https://github.com/tgeorgiadis/quiver-launcher.git
```

A busca de ROMs é **local**. O HUB não procura nem baixa ROMs, BIOS, firmware, jogos ou arquivos de conta. A integração de catálogo Quiver baixa apenas releases de ports/recompilações publicados pelos próprios projetos. Ela não fornece ROMs nem arquivos de dados proprietários; confira a licença e as instruções de cada projeto e use somente arquivos originais que você tem direito de usar. Para títulos vinculados à Steam ou outras lojas, o HUB centraliza a biblioteca e o início, mas compras, downloads, atualizações, autenticação e DRM continuam dependendo dos serviços/clientes oficiais; o HUB não contorna essas proteções. A detecção de BIOS é uma referência baseada em nomes e pastas comuns; ela não confirma que todos os arquivos exigidos por um emulador estejam presentes ou sejam compatíveis. O suporte a `.zip`, `.7z` e `.rar` depende do emulador/core configurado; o HUB não extrai arquivos compactados. A única busca automática de imagem pela Internet nesta versão é feita para jogos importados da Steam, usando o AppID e o CDN público Steam; outros serviços não recebem consultas de pesquisa de jogo. Use somente jogos, ROMs, BIOS e outros arquivos que você tem direito de usar.

## O que acompanha o pacote

O ZIP produzido pelo build inclui o executável do HUB, dependências Qt/QML encontradas por `windeployqt`, o driver SQLite do Qt e avisos de terceiros. O Microsoft Visual C++ Runtime x64 pode ser exigido no computador de destino; `install-launchers-windows.bat` oferece instalá-lo via WinGet. Steam, Heroic, Epic Games Launcher, Ubisoft Connect e RetroArch são programas de terceiros e não são embutidos no HUB. O mesmo script pode instalá-los por WinGet, pedindo confirmação separadamente para cada aplicativo. Ele não baixa jogos ou ROMs. Antes de redistribuir publicamente um build Qt, revise os termos aplicáveis descritos em `THIRD-PARTY-NOTICES.txt`.

## Preparar dependências, compilar e empacotar

Extraia o ZIP e execute `scripts\setup-windows.bat` a partir da pasta do projeto. Se o terminal já estiver em `scripts`, rode `setup-windows.bat` diretamente:

```bat
scripts\setup-windows.bat
```

O script verifica Qt 6.8.3 MSVC x64, Visual Studio 2022 C++ Build Tools, CMake, Ninja e Python. Se algo estiver faltando, tenta instalar pelo WinGet ou usa `aqtinstall` para obter o kit Qt base. Isso pode baixar vários gigabytes e pode pedir elevação/UAC. Também verifica os componentes Qt Core, Gui, QML, Quick, SQL, Network e SQLite antes de compilar. O `build-windows.bat` abre o script de preparação se o Qt não for localizado ou estiver incompleto.

Para compilar sem preparar dependências novamente, use o **x64 Native Tools Command Prompt for VS 2022** e rode:

```bat
scripts\build-windows.bat
```

O executável intermediário fica em `build\windows\z-game-hub.exe`; a pasta implantada e o ZIP portátil ficam em `dist\windows\`. Se o Inno Setup (`ISCC.exe`) estiver no `PATH`, o build também gera `Z-GAME-HUB-Windows-Setup-v1.3.0.exe`.

Para instalar programas opcionais depois, execute `install-launchers.bat` na pasta instalada (ou `scripts\install-launchers-windows.bat` no projeto). O script usa WinGet e pergunta antes de instalar o runtime MSVC, Steam, Heroic, Epic Games Launcher, Ubisoft Connect ou RetroArch.

## Limites e validação

Esta edição Windows precisa ser compilada e testada em Windows. A leitura Epic usa manifests locais `.item`; o lançamento segue o protocolo de ativação documentado pela Epic. A descoberta Ubisoft depende das entradas `Launcher\Installs` e de IDs numéricos; o URI `uplay://` precisa de teste em instalações reais. Heroic e Steam também exigem que seus respectivos protocolos estejam registrados pelos clientes. O download automático de arte Steam requer conexão com a Internet e pode falhar por ausência da imagem ou bloqueio de rede; o seletor manual continua disponível para todos os jogos.

O catálogo comunitário Quiver fornecido é legado/descontinuado e não recebe novas submissões; as quatro listas existentes permanecem públicas e são carregadas dentro da tela Quiver do HUB. O HUB implementa nativamente o fluxo de pesquisa, consulta de releases, escolha de pacote, extração e inclusão de executáveis à biblioteca, tomando os repositórios Quiver como referência; não abre o aplicativo Quiver separado. Os projetos de ports são baixados de suas próprias releases quando o usuário escolhe um pacote. Não há catálogo remoto de ROMs nem download de jogo original, BIOS ou firmware.
