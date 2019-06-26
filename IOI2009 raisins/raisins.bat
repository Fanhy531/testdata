@echo off
if "%1"=="" goto loop
copy raisins%1.in raisins.in >nul
echo Problem Test
echo Data %1
time<enter
raisins
time<enter
fc raisins.sol raisins%1.sol
del raisins.in
del raisins.sol
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21) do call %0 %%i
:end
