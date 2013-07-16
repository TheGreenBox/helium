cat ../README.md

echo ------------------------------------------------------
echo generate makefiles
echo ------------------------------------------------------

#sh linux_clean.sh

echo create product directory
mkdir product/
mkdir product/release/

cd product/release/

cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release ../../../ 

echo ------------------------------------------------------
echo building 
echo ------------------------------------------------------

make

