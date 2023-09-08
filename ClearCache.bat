@echo off
call "%~dp0Builder\Lib\Scripts\Approve.bat" "Do you want to remove all cache?"

rmdir Binaries /S /Q

for /d %%B in (Plugins\*) do rmdir %%B\Intermediate /S /Q
for /d %%B in (Plugins\*) do rmdir %%B\Binaries     /S /Q

rmdir Intermediate\Build /S /Q
rmdir Intermediate\ProjectFiles /S /Q
rmdir .vs /S /Q

del *.sdf /F /Q
del *.sln /F /Q