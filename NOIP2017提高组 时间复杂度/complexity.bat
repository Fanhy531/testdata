@echo off
if "%1"=="" goto loop
copy complexity%1.in complexity.in >nul
echo Problem Test
echo Data %1
time<enter
complexity.exe
time<enter
fc complexity.out complexity%1.ans
del complexity.in
del complexity.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
