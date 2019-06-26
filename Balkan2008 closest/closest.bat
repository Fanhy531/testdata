@echo off
if "%1"=="" goto loop
copy closest%1.in closest.in >nul
echo Problem Test
echo Data %1
time<enter
closest.exe
time<enter
fc closest.out closest%1.out
del closest.in
del closest.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10 11) do call %0 %%i
:end
