@REM JUST A QUICK SCRIPT TO BUILD AND RUN THINGS 
@REM QUICKLY IN JUST SINGLE COMMAND 
@REM (its not properly setup to handle errors i.e return codes)
@REM (this file will be deleted later)


@echo off

@REM pushd simplifies things
pushd build 

echo.
echo.
echo.
echo --------------------------------------------
echo ********** GENERATING BUILD FILES **********     
echo --------------------------------------------
echo.

cmake -G "MinGW Makefiles" ..

echo.
echo.
echo.
echo ---------------------------
echo ******** BUILDING *********     
echo ---------------------------
echo.

mingw32-make

echo.
echo.
echo.
echo ---------------------------
echo ********* RUNNING *********     
echo ---------------------------
echo.

popd

start build/mandlebrot_explorer.exe
