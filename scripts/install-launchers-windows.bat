@echo off
setlocal EnableExtensions
where winget >nul 2>nul || (
  echo WinGet nao foi encontrado. Atualize o App Installer pela Microsoft Store ou instale manualmente os programas.
  pause
  exit /b 2
)

echo Este script instala somente os programas que voce escolher.
echo Nenhum jogo, ROM ou conteudo de conta sera baixado pelo Z-GAME HUB.
echo.
choice /C SN /N /M "Instalar Microsoft Visual C++ Runtime x64 (necessario se ainda nao estiver instalado)? [S/N] "
if errorlevel 2 goto STEAM
winget install --id Microsoft.VCRedist.2015+.x64 -e --source winget --accept-source-agreements --accept-package-agreements
if errorlevel 1 echo Aviso: instale manualmente o Microsoft Visual C++ 2015-2022 Redistributable x64 se o HUB nao iniciar.

:STEAM
choice /C SN /N /M "Instalar Steam (Valve)? [S/N] "
if errorlevel 2 goto HEROIC
winget install --id Valve.Steam -e --source winget --accept-source-agreements --accept-package-agreements
if errorlevel 1 echo Aviso: a instalacao Steam nao foi concluida; voce pode instala-la manualmente.

:HEROIC
choice /C SN /N /M "Instalar Heroic Games Launcher? [S/N] "
if errorlevel 2 goto EPIC
winget install --id HeroicGamesLauncher.HeroicGamesLauncher -e --source winget --accept-source-agreements --accept-package-agreements
if errorlevel 1 echo Aviso: a instalacao Heroic nao foi concluida; voce pode instala-lo manualmente.

:EPIC
choice /C SN /N /M "Instalar Epic Games Launcher? [S/N] "
if errorlevel 2 goto UBISOFT
winget install --id EpicGames.EpicGamesLauncher -e --source winget --accept-source-agreements --accept-package-agreements
if errorlevel 1 echo Aviso: a instalacao Epic Games Launcher nao foi concluida; voce pode instala-lo manualmente.

:UBISOFT
choice /C SN /N /M "Instalar Ubisoft Connect? [S/N] "
if errorlevel 2 goto RETROARCH
winget install --id Ubisoft.Connect -e --source winget --accept-source-agreements --accept-package-agreements
if errorlevel 1 echo Aviso: a instalacao Ubisoft Connect nao foi concluida; voce pode instala-lo manualmente.

:RETROARCH
choice /C SN /N /M "Instalar RetroArch (emulador opcional)? [S/N] "
if errorlevel 2 goto DONE
winget install --id Libretro.RetroArch -e --source winget --accept-source-agreements --accept-package-agreements
if errorlevel 1 echo Aviso: a instalacao do RetroArch nao foi concluida; voce pode instala-lo manualmente.

:DONE
echo.
echo Concluido. Se os launchers ja estavam abertos, reinicie o Z-GAME HUB para atualizar as deteccoes.
pause
exit /b 0
