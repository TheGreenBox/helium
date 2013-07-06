cat ../README.md

echo ------------------------------------------------------
echo generate makefiles
echo ------------------------------------------------------

sh linux_clean.sh

echo create product directory
mkdir product/
mkdir product/debug/

cd product/debug/

cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug ../../../ 

echo ------------------------------------------------------
echo building 
echo ------------------------------------------------------

make

