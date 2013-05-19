cat ../README

echo ------------------------------------------------------
echo generate makefiles
echo ------------------------------------------------------

sh clean_generate.sh

echo create product directory
mkdir product/
mkdir product/debug/

cd product/debug/

cmake ../../../

echo ------------------------------------------------------
echo building 
echo ------------------------------------------------------

make
