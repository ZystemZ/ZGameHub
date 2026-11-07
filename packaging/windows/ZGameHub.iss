#define AppName "Z-GAME HUB"
#define AppVersion "1.3.0"
#define ProjectDir AddBackslash(SourcePath) + "..\.."
#define StageDir AddBackslash(ProjectDir) + "dist\windows\Z-GAME-HUB"

[Setup]
AppId={{B4875776-92D0-4FF3-9219-9E9F72C61110}
AppName={#AppName}
AppVersion={#AppVersion}
AppPublisher=Zystem
DefaultDirName={localappdata}\Programs\Z-GAME HUB
DefaultGroupName=Z-GAME HUB
PrivilegesRequired=lowest
ArchitecturesAllowed=x64
ArchitecturesInstallIn64BitMode=x64
OutputDir={#ProjectDir}\dist\windows
OutputBaseFilename=Z-GAME-HUB-Windows-Setup-v1.3.0
Compression=lzma2
SolidCompression=yes
WizardStyle=modern
UninstallDisplayIcon={app}\z-game-hub.exe

[Files]
Source: "{#StageDir}\*"; DestDir: "{app}"; Flags: ignoreversion recursesubdirs createallsubdirs

[Icons]
Name: "{group}\Z-GAME HUB"; Filename: "{app}\z-game-hub.exe"
Name: "{group}\Instalar launchers (opcional)"; Filename: "{app}\install-launchers.bat"
Name: "{autodesktop}\Z-GAME HUB"; Filename: "{app}\z-game-hub.exe"; Tasks: desktopicon

[Tasks]
Name: "desktopicon"; Description: "Criar atalho na área de trabalho"; GroupDescription: "Atalhos:"

[Run]
Filename: "{app}\z-game-hub.exe"; Description: "Abrir Z-GAME HUB"; Flags: nowait postinstall skipifsilent
