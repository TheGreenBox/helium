PRINT ../README

ECHO

ECHO ------------------------------------------------------
ECHO generate makefiles
ECHO ------------------------------------------------------

sh clean_generate.sh

ECHO create product directory
mkdir product/
mkdir product/debug/

cd product/debug/

cmake ../../../

ECHO ------------------------------------------------------
ECHO building
ECHO ------------------------------------------------------

make
