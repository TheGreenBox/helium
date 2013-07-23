cat ../README.md

echo ------------------------------------------------------
echo Generate makefiles
echo ------------------------------------------------------

#sh linux_clean.sh
echo Remove product/release directiry
rm -r product/release

echo Create product/release directory
mkdir product
mkdir product/release

cd product/release

cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release ../../../ 

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

