cat ../README.md

echo ------------------------------------------------------
echo generate makefiles
echo ------------------------------------------------------

#sh linux_clean.sh
echo remove product directiry
rm -r product/debug

echo create product directory
mkdir product/
mkdir product/debug

cd product/debug

cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug ../../../ 

echo ------------------------------------------------------
echo building 
echo ------------------------------------------------------

make

