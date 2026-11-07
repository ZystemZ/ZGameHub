# Integração visual ZCONSOLE no Z-GAME-HUB

A interface nativa do Z-GAME-HUB foi atualizada diretamente em QML para incorporar a direção visual do ZCONSOLE sem substituir a lógica existente.

## O que foi implementado

- Fundo escuro atmosférico com gradiente profundo, halos verdes e brilho pulsante.
- Header com marca ZCONSOLE, busca em formato pill, ações de adicionar jogo/app e emuladores.
- Sidebar em glass panel escuro com navegação preservada entre Início, Minha biblioteca, Plataformas, Dispositivos, Loja e descoberta, Scanner, ROMs e BIOS, Quiver e Configurações.
- Hero principal com imagem do HUB, overlay escuro, destaque neon e animação de respiração da imagem.
- Carrossel de jogos com cartões maiores, profundidade, escala/opacity para item selecionado, foco visual, transições suaves e overlays de capa.
- Botões com estado normal, hover, pressionado e foco, bordas neon e animações de cor.
- Diálogos e cartões auxiliares com o mesmo tratamento de painel escuro e bordas verdes.
- Marca SVG `assets/zconsole-mark.svg` incorporada ao bundle Qt pelo `CMakeLists.txt`.
- Todas as ações originais permanecem conectadas: catálogo SQLite, lançamento, edição/exclusão, capas, scanner, emuladores, ROMs/BIOS e Quiver.

## Build

No Windows, use o fluxo já existente:

```bat
scripts\\setup-windows.bat
scripts\\build-windows.bat
```

O build continua usando Qt 6.5+, CMake, Ninja e MSVC conforme descrito no README. A validação nesta entrega foi estrutural no sandbox Linux; a compilação final deve ser executada no Windows com o toolchain Qt/MSVC do projeto.
