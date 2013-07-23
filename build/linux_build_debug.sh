cat ../README.md

echo ------------------------------------------------------
echo Generating makefiles
echo ------------------------------------------------------

echo Remove product/debug directiry
rm -r product/debug

echo Create product/debug directory
mkdir product/
mkdir product/debug

cd product/debug

cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug ../../../ 

echo ------------------------------------------------------
echo Building 
echo ------------------------------------------------------
make

echo ------------------------------------------------------
echo Installing
echo ------------------------------------------------------
make install

echo Finished
echo ------------------------------------------------------

