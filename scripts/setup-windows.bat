@echo off
setlocal EnableExtensions
set "ROOT=%~dp0.."
for %%I in ("%ROOT%") do set "ROOT=%%~fI"
set "QT_VERSION=6.8.3"
if not defined QT_ROOT set "QT_ROOT=%LOCALAPPDATA%\Qt\%QT_VERSION%\msvc2022_64"

where winget >nul 2>nul
if errorlevel 1 goto noWinget

echo ============================================================
echo  Z-GAME HUB Windows - preparar dependencias e compilar
echo ============================================================
echo Este script pode instalar Visual Studio C++ Build Tools,
echo CMake, Ninja, Python e Qt 6.8.3 MSVC x64 pelo WinGet/aqt.
echo O download do Qt pode ocupar varios GB. Instaladores podem
 echo solicitar permissao do Windows (UAC).
echo.

call :findQt
if defined QT_ROOT_FOUND (
  set "QT_ROOT=%QT_ROOT_FOUND%"
  echo Qt encontrado: %QT_ROOT%
) else (
  echo Qt MSVC x64 nao encontrado. Sera instalado em:
  echo %QT_ROOT%
)

call :prepareTools
if errorlevel 1 exit /b 1

if not defined QT_ROOT_FOUND call :installQt
if errorlevel 1 exit /b 1

if not exist "%QT_ROOT%\bin\windeployqt.exe" (
  echo ERRO: windeployqt.exe nao foi encontrado em "%QT_ROOT%\bin".
  echo Verifique a instalacao Qt ou defina QT_ROOT para o kit MSVC x64.
  exit /b 1
)
if not exist "%QT_ROOT%\lib\cmake\Qt6\Qt6Config.cmake" (
  echo ERRO: este diretorio nao contem uma instalacao Qt 6 de desenvolvimento completa.
  exit /b 1
)
if not exist "%QT_ROOT%\lib\cmake\Qt6Core\Qt6CoreConfig.cmake" (
  echo ERRO: Qt Core nao foi encontrado no kit Qt.
  exit /b 1
)
if not exist "%QT_ROOT%\lib\cmake\Qt6Gui\Qt6GuiConfig.cmake" (
  echo ERRO: Qt Gui nao foi encontrado no kit Qt.
  exit /b 1
)
if not exist "%QT_ROOT%\lib\cmake\Qt6Qml\Qt6QmlConfig.cmake" (
  echo ERRO: Qt QML nao foi encontrado no kit Qt.
  exit /b 1
)
if not exist "%QT_ROOT%\lib\cmake\Qt6Quick\Qt6QuickConfig.cmake" (
  echo ERRO: Qt Quick nao foi encontrado no kit Qt.
  exit /b 1
)
if not exist "%QT_ROOT%\lib\cmake\Qt6Sql\Qt6SqlConfig.cmake" (
  echo ERRO: Qt SQL nao foi encontrado no kit Qt.
  exit /b 1
)
if not exist "%QT_ROOT%\lib\cmake\Qt6Network\Qt6NetworkConfig.cmake" (
  echo ERRO: Qt Network nao foi encontrado no kit Qt.
  exit /b 1
)
if not exist "%QT_ROOT%\plugins\sqldrivers\qsqlite.dll" (
  echo ERRO: o plugin Qt SQLite nao foi encontrado em "%QT_ROOT%\plugins\sqldrivers".
  echo Reexecute este script para baixar/reparar o kit Qt 6.8.3 MSVC x64 completo.
  exit /b 1
)

set "VSINSTALL="
if exist "%ProgramFiles(x86)%\Microsoft Visual Studio\2022\Community\Common7\Tools\VsDevCmd.bat" set "VSINSTALL=%ProgramFiles(x86)%\Microsoft Visual Studio\2022\Community"
if not defined VSINSTALL if exist "%ProgramFiles%\Microsoft Visual Studio\2022\Community\Common7\Tools\VsDevCmd.bat" set "VSINSTALL=%ProgramFiles%\Microsoft Visual Studio\2022\Community"
if not defined VSINSTALL if exist "%ProgramFiles(x86)%\Microsoft Visual Studio\2022\BuildTools\Common7\Tools\VsDevCmd.bat" set "VSINSTALL=%ProgramFiles(x86)%\Microsoft Visual Studio\2022\BuildTools"
if not defined VSINSTALL if exist "%ProgramFiles%\Microsoft Visual Studio\2022\BuildTools\Common7\Tools\VsDevCmd.bat" set "VSINSTALL=%ProgramFiles%\Microsoft Visual Studio\2022\BuildTools"
if not defined VSINSTALL call :findVisualStudio
if not defined VSINSTALL (
  echo ERRO: nao foi encontrado o ambiente de compilacao MSVC 2022.
  echo Execute novamente este script depois de concluir o instalador do Visual Studio.
  exit /b 1
)
echo Preparando ambiente MSVC: %VSINSTALL%
call "%VSINSTALL%\Common7\Tools\VsDevCmd.bat" -arch=x64 -host_arch=x64
if errorlevel 1 (
  echo ERRO: nao foi possivel inicializar o ambiente MSVC.
  exit /b 1
)

if exist "%ProgramFiles%\CMake\bin" set "PATH=%ProgramFiles%\CMake\bin;%PATH%"
if exist "%LOCALAPPDATA%\Programs\CMake\bin" set "PATH=%LOCALAPPDATA%\Programs\CMake\bin;%PATH%"
if exist "%LOCALAPPDATA%\Microsoft\WinGet\Links" set "PATH=%LOCALAPPDATA%\Microsoft\WinGet\Links;%PATH%"
if exist "%VSINSTALL%\Common7\IDE\CommonExtensions\Microsoft\CMake\Ninja" set "PATH=%VSINSTALL%\Common7\IDE\CommonExtensions\Microsoft\CMake\Ninja;%PATH%"
if exist "%VSINSTALL%\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin" set "PATH=%VSINSTALL%\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin;%PATH%"
set "PATH=%QT_ROOT%\bin;%PATH%"

where cmake >nul 2>nul || (echo ERRO: CMake continua indisponivel. & exit /b 1)
where ninja >nul 2>nul || (echo ERRO: Ninja continua indisponivel. & exit /b 1)
where cl >nul 2>nul || (echo ERRO: o compilador cl.exe continua indisponivel. & exit /b 1)
echo Dependencias verificadas.
echo QT_ROOT=%QT_ROOT%
echo.
call "%~dp0build-windows.bat"
exit /b %errorlevel%

:prepareTools
where cmake >nul 2>nul
if errorlevel 1 (
  echo Instalando CMake pelo WinGet...
  winget install --id Kitware.CMake -e --source winget --accept-source-agreements --accept-package-agreements
  if errorlevel 1 (echo Falha ao instalar CMake. & exit /b 1)
)
where ninja >nul 2>nul
if errorlevel 1 (
  echo Instalando Ninja pelo WinGet...
  winget install --id Ninja-build.Ninja -e --source winget --accept-source-agreements --accept-package-agreements
  if errorlevel 1 (echo Falha ao instalar Ninja. & exit /b 1)
)
set "VSINSTALL="
if exist "%ProgramFiles(x86)%\Microsoft Visual Studio\2022\Community\Common7\Tools\VsDevCmd.bat" set "VSINSTALL=%ProgramFiles(x86)%\Microsoft Visual Studio\2022\Community"
if not defined VSINSTALL if exist "%ProgramFiles%\Microsoft Visual Studio\2022\Community\Common7\Tools\VsDevCmd.bat" set "VSINSTALL=%ProgramFiles%\Microsoft Visual Studio\2022\Community"
if not defined VSINSTALL if exist "%ProgramFiles(x86)%\Microsoft Visual Studio\2022\BuildTools\Common7\Tools\VsDevCmd.bat" set "VSINSTALL=%ProgramFiles(x86)%\Microsoft Visual Studio\2022\BuildTools"
if not defined VSINSTALL if exist "%ProgramFiles%\Microsoft Visual Studio\2022\BuildTools\Common7\Tools\VsDevCmd.bat" set "VSINSTALL=%ProgramFiles%\Microsoft Visual Studio\2022\BuildTools"
if not defined VSINSTALL call :findVisualStudio
if not defined VSINSTALL (
  echo Instalando Visual Studio 2022 C++ Build Tools pelo WinGet...
  winget install --id Microsoft.VisualStudio.2022.BuildTools -e --source winget --accept-source-agreements --accept-package-agreements --override "--wait --passive --norestart --add Microsoft.VisualStudio.Workload.VCTools --includeRecommended"
  if errorlevel 1 (echo Instalacao do Visual Studio Build Tools falhou ou foi cancelada. & exit /b 1)
  set "VSINSTALL="
  if exist "%ProgramFiles(x86)%\Microsoft Visual Studio\2022\Community\Common7\Tools\VsDevCmd.bat" set "VSINSTALL=%ProgramFiles(x86)%\Microsoft Visual Studio\2022\Community"
  if not defined VSINSTALL if exist "%ProgramFiles%\Microsoft Visual Studio\2022\Community\Common7\Tools\VsDevCmd.bat" set "VSINSTALL=%ProgramFiles%\Microsoft Visual Studio\2022\Community"
  if not defined VSINSTALL if exist "%ProgramFiles(x86)%\Microsoft Visual Studio\2022\BuildTools\Common7\Tools\VsDevCmd.bat" set "VSINSTALL=%ProgramFiles(x86)%\Microsoft Visual Studio\2022\BuildTools"
  if not defined VSINSTALL if exist "%ProgramFiles%\Microsoft Visual Studio\2022\BuildTools\Common7\Tools\VsDevCmd.bat" set "VSINSTALL=%ProgramFiles%\Microsoft Visual Studio\2022\BuildTools"
  if not defined VSINSTALL call :findVisualStudio
)
if not defined VSINSTALL (
  echo ERRO: o Visual Studio Build Tools nao foi localizado depois da instalacao.
  exit /b 1
)
exit /b 0

:findVisualStudio
set "VSINSTALL="
for %%B in ("%ProgramFiles(x86)%\Microsoft Visual Studio\2022" "%ProgramFiles%\Microsoft Visual Studio\2022") do (
  for %%E in (BuildTools Community Professional Enterprise) do (
    if not defined VSINSTALL if exist "%%~B\%%E\Common7\Tools\VsDevCmd.bat" set "VSINSTALL=%%~B\%%E"
  )
)
exit /b 0

:findQt
set "QT_ROOT_FOUND="
if defined QT_ROOT if exist "%QT_ROOT%\bin\windeployqt.exe" if exist "%QT_ROOT%\lib\cmake\Qt6\Qt6Config.cmake" if exist "%QT_ROOT%\lib\cmake\Qt6Core\Qt6CoreConfig.cmake" if exist "%QT_ROOT%\lib\cmake\Qt6Gui\Qt6GuiConfig.cmake" if exist "%QT_ROOT%\lib\cmake\Qt6Qml\Qt6QmlConfig.cmake" if exist "%QT_ROOT%\lib\cmake\Qt6Quick\Qt6QuickConfig.cmake" if exist "%QT_ROOT%\lib\cmake\Qt6Network\Qt6NetworkConfig.cmake" if exist "%QT_ROOT%\lib\cmake\Qt6Sql\Qt6SqlConfig.cmake" if exist "%QT_ROOT%\plugins\sqldrivers\qsqlite.dll" set "QT_ROOT_FOUND=%QT_ROOT%"
if defined QT_ROOT_FOUND exit /b 0
for %%R in ("C:\Qt" "%LOCALAPPDATA%\Qt" "%ProgramFiles%\Qt" "%ProgramFiles(x86)%\Qt" "W:\Qt") do (
  if exist "%%~R\" for /d %%V in ("%%~R\6.*") do (
    if exist "%%~V\msvc2022_64\bin\windeployqt.exe" if exist "%%~V\msvc2022_64\lib\cmake\Qt6\Qt6Config.cmake" if exist "%%~V\msvc2022_64\lib\cmake\Qt6Core\Qt6CoreConfig.cmake" if exist "%%~V\msvc2022_64\lib\cmake\Qt6Gui\Qt6GuiConfig.cmake" if exist "%%~V\msvc2022_64\lib\cmake\Qt6Qml\Qt6QmlConfig.cmake" if exist "%%~V\msvc2022_64\lib\cmake\Qt6Quick\Qt6QuickConfig.cmake" if exist "%%~V\msvc2022_64\lib\cmake\Qt6Network\Qt6NetworkConfig.cmake" if exist "%%~V\msvc2022_64\lib\cmake\Qt6Sql\Qt6SqlConfig.cmake" if exist "%%~V\msvc2022_64\plugins\sqldrivers\qsqlite.dll" set "QT_ROOT_FOUND=%%~V\msvc2022_64"
  )
)
exit /b 0

:installQt
set "QT_ROOT=%LOCALAPPDATA%\Qt\%QT_VERSION%\msvc2022_64"
echo Procurando Python 3 para instalar o kit Qt...
call :findPython
if not defined PYTHON_LAUNCHER (
  echo Python nao encontrado. Instalando pelo WinGet...
  winget install --id Python.Python.3.12 -e --source winget --accept-source-agreements --accept-package-agreements
  if errorlevel 1 (echo Falha ao instalar Python. & exit /b 1)
  set "PATH=%LOCALAPPDATA%\Programs\Python\Launcher;%LOCALAPPDATA%\Programs\Python\Python312;%LOCALAPPDATA%\Programs\Python\Python312\Scripts;%PATH%"
  call :findPython
)
if not defined PYTHON_LAUNCHER (
  echo ERRO: Python 3 nao foi localizado. Instale Python 3.12 e execute novamente.
  exit /b 1
)
echo Instalando aqtinstall e Qt %QT_VERSION% MSVC 2022 x64. Isso pode demorar.
%PYTHON_LAUNCHER% -m pip install --user --upgrade --no-warn-script-location aqtinstall
if errorlevel 1 (echo Falha ao instalar aqtinstall com pip. & exit /b 1)
%PYTHON_LAUNCHER% -m aqt install-qt windows desktop %QT_VERSION% win64_msvc2022_64 -O "%LOCALAPPDATA%\Qt"
if errorlevel 1 (
  echo ERRO: a instalacao Qt pelo aqtinstall falhou.
  echo Voce pode instalar Qt 6.8.3 MSVC 2022 x64 manualmente e definir QT_ROOT.
  exit /b 1
)
if not exist "%QT_ROOT%\bin\windeployqt.exe" (
  echo ERRO: a instalacao terminou sem windeployqt.exe em "%QT_ROOT%\bin".
  exit /b 1
)
if not exist "%QT_ROOT%\lib\cmake\Qt6\Qt6Config.cmake" (
  echo ERRO: Qt6Config.cmake nao foi instalado.
  exit /b 1
)
if not exist "%QT_ROOT%\lib\cmake\Qt6Core\Qt6CoreConfig.cmake" (
  echo ERRO: Qt Core nao foi instalado.
  exit /b 1
)
if not exist "%QT_ROOT%\lib\cmake\Qt6Gui\Qt6GuiConfig.cmake" (
  echo ERRO: Qt Gui nao foi instalado.
  exit /b 1
)
if not exist "%QT_ROOT%\lib\cmake\Qt6Qml\Qt6QmlConfig.cmake" (
  echo ERRO: o kit Qt nao contem o componente QML exigido pelo projeto.
  exit /b 1
)
if not exist "%QT_ROOT%\lib\cmake\Qt6Quick\Qt6QuickConfig.cmake" (
  echo ERRO: o kit Qt nao contem o componente Qt Quick exigido pelo projeto.
  exit /b 1
)
if not exist "%QT_ROOT%\lib\cmake\Qt6Sql\Qt6SqlConfig.cmake" (
  echo ERRO: Qt SQL nao foi instalado.
  exit /b 1
)
if not exist "%QT_ROOT%\lib\cmake\Qt6Network\Qt6NetworkConfig.cmake" (
  echo ERRO: o kit Qt nao contem o componente Qt Network exigido pelo projeto.
  exit /b 1
)
if not exist "%QT_ROOT%\plugins\sqldrivers\qsqlite.dll" (
  echo ERRO: o plugin QSQLITE nao foi instalado junto com o kit Qt.
  exit /b 1
)
set "QT_ROOT_FOUND=%QT_ROOT%"
exit /b 0

:findPython
set "PYTHON_LAUNCHER="
where py >nul 2>nul
if not errorlevel 1 (
  py -3 -c "import sys; raise SystemExit(0 if sys.version_info >= (3, 10) else 1)" >nul 2>nul
  if not errorlevel 1 set "PYTHON_LAUNCHER=py -3"
)
if defined PYTHON_LAUNCHER exit /b 0
for %%P in ("%LOCALAPPDATA%\Programs\Python\Python312\python.exe" "%ProgramFiles%\Python312\python.exe") do (
  if not defined PYTHON_LAUNCHER if exist "%%~P" set "PYTHON_LAUNCHER="%%~P""
)
if defined PYTHON_LAUNCHER exit /b 0
where python >nul 2>nul
if not errorlevel 1 (
  python -c "import sys; raise SystemExit(0 if sys.version_info >= (3, 10) else 1)" >nul 2>nul
  if not errorlevel 1 set "PYTHON_LAUNCHER=python"
)
exit /b 0

:noWinget
echo ERRO: o WinGet nao foi encontrado. Instale/atualize o App Installer pela Microsoft Store e execute este script novamente.
start "" "ms-windows-store://pdp/?ProductId=9NBLGGH4NNS1"
exit /b 2
