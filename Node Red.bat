echo off
color a
title Node Red - LowRain

goto start

:start
cls
echo ********************
echo       LowRain
echo ********************
echo.
echo 1 - Start Node Red
echo 2 - Start Node Red and open interface in browser
echo 3 - Quit
echo 999 - éàû
echo.

set choiceinput=
set /p choiceinput= What do you want to do ? : 
if %choiceinput%==1 goto choice1
if %choiceinput%==2 goto choice2
if %choiceinput%==3 goto exit
if %choiceinput%==999 goto choix
else (
    cls
    echo The value is incorrect !
    echo.
    timeout /t 5
    goto start
)

:choice1
cls
echo Node Red launched !
node-red > NUL


:choice2
cls
start http://127.0.0.1:1880/#flow/22786a49556f0f3f &::Replace your own link here
echo Node Red launched !
node-red > NUL


:choix
cls
echo Sure ? (not recommended)
echo.
echo 1 - Yes 
echo 2 - No
set choiceinput2=
set /p choiceinput2= So ? : 
if %choiceinput2%==1 goto choice1_2
if %choiceinput2%==2 goto choice2_2
else (
    cls
    echo Maybe I misunderstood.
    echo.
    timeout /t 5 > NUL
    goto choix
)

:choice1_2
echo Ok.
timeout /t 5 > NUL
cls
echo It was fifty-fifty after all.
timeout /t 5 > NUL
echo Your PC will shutdown in 60 seconds. You should save your work quickly.
timeout /t 5 > NUL
echo Have a good night !
shutdown -s -t 30

:choice2_2
cls
echo It's better this way.
timeout /t 5 > NUL
goto start