@ECHO OFF

IF NOT DEFINED DevEnvDir (
	CALL "J:\Program Files (x86)\Microsoft Visual Studio\2019\Preview\VC\Auxiliary\Build\vcvarsall.bat" x86_amd64 >NUL
)

IF NOT EXIST build MKDIR build

SET CompilerFlags=^
	-nologo^
	-FC^
	-fp:fast^
	-GR-^
	-EHa-^
	-Od^
	-Oi^
	-MTd^
	-Zi^
	-TC^
	-Wall^
	-WX^
	-ferror-limit=50^
	-Wno-unused-parameter^
	-Wno-unused-variable^
	-Wno-unused-function^
	-Wno-nonportable-system-include-path^
	-Wno-missing-prototypes^
	-Wno-cast-align^
	-Wno-string-conversion^
	-Wno-extra-semi-stmt^
	-Wno-shift-sign-overflow

SET LinkerFlags=^
	/link^
	-incremental:no^
	-opt:ref

SET code=%cd%\code

SET libs=^
	user32.lib^
	gdi32.lib^
	winmm.lib

SET defines=^
	-DHR_SLOW=1

PUSHD build

REM DEL *.pdb >NUL 2 >NUL
 
REM ECHO WAITING FOR PDB >lock.tmp

REM DEL lock.tmp >NUL 2 >NUL

clang-cl^
	%defines%^
	%CompilerFlags%^
	%libs%^
	%code%\win32_main.c^
	-Fehandmade_ray^
	%LinkerFlags%

IF %errorlevel% neq 0 (
	POPD
	EXIT /b 1
)

POPD