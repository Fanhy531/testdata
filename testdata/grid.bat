@echo off
if "%1"=="" goto loop
copy gridtest%1.in grid.in >nul
echo Problem Test
echo Data %1
time<enter
grid.exe
time<enter
fc grid.out gridtest%1.out
del grid.in
del grid.out
pause
goto end
:loop
for %%i in (01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16 17 18 19 20) do call %0 %%i
:end
