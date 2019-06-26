@echo off
if "%1"=="" goto loop
copy cechas%1.in cechas.in >nul
echo Problem Test
echo Data %1
time<enter
cechas.exe
time<enter
fc cechas.out cechas%1.out
del cechas.in
del cechas.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17) do call %0 %%i
:end
