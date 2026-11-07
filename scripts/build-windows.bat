@echo off
setlocal EnableExtensions
set "ROOT=%~dp0.."
for %%I in ("%ROOT%") do set "ROOT=%%~fI"
if "%QT_ROOT%"=="" (
  echo QT_ROOT nao esta definido. Iniciando verificacao automatica das dependencias...
  call "%~dp0setup-windows.bat"
  if errorlevel 1 exit /b 1
  exit /b 0
)
if not exist "%QT_ROOT%\bin\windeployqt.exe" (
  echo O Qt informado nao esta completo. Iniciando a preparacao automatica...
  call "%~dp0setup-windows.bat"
  if errorlevel 1 exit /b 1
  exit /b 0
)
if not exist "%QT_ROOT%\lib\cmake\Qt6\Qt6Config.cmake" (
  echo Qt6Config.cmake nao foi encontrado. Iniciando a preparacao automatica...
  call "%~dp0setup-windows.bat"
  if errorlevel 1 exit /b 1
  exit /b 0
)
set "QT_READY=1"
if not exist "%QT_ROOT%\lib\cmake\Qt6Core\Qt6CoreConfig.cmake" set "QT_READY=0"
if not exist "%QT_ROOT%\lib\cmake\Qt6Gui\Qt6GuiConfig.cmake" set "QT_READY=0"
if not exist "%QT_ROOT%\lib\cmake\Qt6Qml\Qt6QmlConfig.cmake" set "QT_READY=0"
if not exist "%QT_ROOT%\lib\cmake\Qt6Quick\Qt6QuickConfig.cmake" set "QT_READY=0"
if not exist "%QT_ROOT%\lib\cmake\Qt6Sql\Qt6SqlConfig.cmake" set "QT_READY=0"
if not exist "%QT_ROOT%\lib\cmake\Qt6Network\Qt6NetworkConfig.cmake" set "QT_READY=0"
if not exist "%QT_ROOT%\plugins\sqldrivers\qsqlite.dll" set "QT_READY=0"
if "%QT_READY%"=="0" (
  echo Faltam componentes Qt/QML ou SQLite. Iniciando o reparo automatico...
  call "%~dp0setup-windows.bat"
  if errorlevel 1 exit /b 1
  exit /b 0
)
where cmake >nul 2>nul
if errorlevel 1 (
  echo CMake nao encontrado. Iniciando a preparacao automatica...
  call "%~dp0setup-windows.bat"
  if errorlevel 1 exit /b 1
  exit /b 0
)
where ninja >nul 2>nul
if errorlevel 1 (
  echo Ninja nao encontrado. Iniciando a preparacao automatica...
  call "%~dp0setup-windows.bat"
  if errorlevel 1 exit /b 1
  exit /b 0
)
where cl >nul 2>nul
if errorlevel 1 (
  echo MSVC nao esta inicializado. Iniciando a preparacao automatica...
  call "%~dp0setup-windows.bat"
  if errorlevel 1 exit /b 1
  exit /b 0
)
set "PATH=%QT_ROOT%\bin;%PATH%"
set "BUILD=%ROOT%\build\windows"
set "STAGE=%ROOT%\dist\windows\Z-GAME-HUB"
set "ZIP=%ROOT%\dist\windows\Z-GAME-HUB-Windows-v1.3.0-x64.zip"

cmake -S "%ROOT%" -B "%BUILD%" -G Ninja -DCMAKE_BUILD_TYPE=Release -DCMAKE_PREFIX_PATH="%QT_ROOT%"
if errorlevel 1 exit /b 1
cmake --build "%BUILD%" --parallel
if errorlevel 1 exit /b 1
if not exist "%BUILD%\z-game-hub.exe" (
  echo Executavel nao foi gerado.
  exit /b 1
)

if exist "%STAGE%" rmdir /s /q "%STAGE%"
mkdir "%STAGE%"
copy /y "%BUILD%\z-game-hub.exe" "%STAGE%\z-game-hub.exe" >nul
"%QT_ROOT%\bin\windeployqt.exe" --release --no-compiler-runtime --qmldir "%ROOT%\ui" --dir "%STAGE%" "%STAGE%\z-game-hub.exe"
if errorlevel 1 exit /b 1

rem QSQLITE e carregado dinamicamente; garanta que o driver seja distribuido.
if not exist "%QT_ROOT%\plugins\sqldrivers\qsqlite.dll" (
  echo Driver qsqlite.dll nao encontrado em %QT_ROOT%\plugins\sqldrivers.
  exit /b 1
)
if not exist "%STAGE%\sqldrivers" mkdir "%STAGE%\sqldrivers"
copy /y "%QT_ROOT%\plugins\sqldrivers\qsqlite.dll" "%STAGE%\sqldrivers\qsqlite.dll" >nul
copy /y "%~dp0install-launchers-windows.bat" "%STAGE%\install-launchers.bat" >nul
copy /y "%ROOT%\README.md" "%STAGE%\README.txt" >nul
copy /y "%ROOT%\THIRD-PARTY-NOTICES.txt" "%STAGE%\THIRD-PARTY-NOTICES.txt" >nul

if not exist "%ROOT%\dist\windows" mkdir "%ROOT%\dist\windows"
if exist "%ZIP%" del /q "%ZIP%"
set "ZGH_STAGE=%STAGE%"
set "ZGH_ZIP=%ZIP%"
powershell -NoProfile -ExecutionPolicy Bypass -Command "Compress-Archive -Path (Join-Path $env:ZGH_STAGE '*') -DestinationPath $env:ZGH_ZIP -Force"
if errorlevel 1 exit /b 1
where ISCC.exe >nul 2>nul
if not errorlevel 1 (
  ISCC.exe "%ROOT%\packaging\windows\ZGameHub.iss"
  if errorlevel 1 exit /b 1
) else (
  echo Inno Setup nao encontrado; foi gerado apenas o ZIP portatil.
)
echo.
echo Build Windows concluido:
echo Executavel: %STAGE%\z-game-hub.exe
echo Pacote: %ZIP%
echo O pacote inclui Qt/QML e SQLite. Steam, Heroic, Epic, Ubisoft Connect, RetroArch e jogos nao sao embutidos.
exit /b 0
