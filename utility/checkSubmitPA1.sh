#!/bin/bash

#############################################################################
# File       [ checkSubmitPA1.sh ]
# Author     [ funnymean ]
# Modified   [ 2014/01/22 ]
# Synopsis   [ simple test for algorithm PA1 homework format program ]
# Note       [ If you cannot run this code, please change permission
#              chmod 744 checkSubmitPA1.sh ]
#############################################################################


if [ "$1" == "" ]; then
    echo "Usage:   ./checkSubmitPA1.sh <fileName>"
    echo "Example: ./checkSubmitPA1.sh b90901000_pa1.tgz"
    echo "This program will build a dir name checkSubmitPA1_$$ env"
    exit
fi

binaryFileName='mysort'
fileName=$1
inputfile=$2

./gen.pl 10 100

echo "Target file $fileName"
if [ ! -f $fileName ]; then
    echo "Cannot find tgz file $filename!"
    exit
fi
if [ -d check_$$ ]; then
    echo "Directory check_$$ exists"
    echo "Please delete the directory and try again"
    exit
fi

mkdir check_$$
cd check_$$


tar zxvf ../$fileName

stuid=`echo $fileName | sed -e 's/_.*//'`
echo "$fileName"
echo "$stuid"

cd ${stuid}_pa1
echo "checking README ..."
if [ ! -f README ]; then
    echo "**ERROR Cannot find README"
    cd ../../
    rm -rf check_$$
    exit
fi

echo "checking src/ ..."
if [ ! -d src ]; then
    echo "Cannot find src dir"
    cd ../../
    rm -rf check_$$
    exit
fi

echo "checking doc/ ..."
if [ ! -d doc ]; then
    echo "Cannot find doc dir"
    cd ../../
    rm -rf check_$$
    exit
fi

echo "checking report ..."
report_exist=`ls doc | grep ${stuid}_pa1_report`
if [ "${report_exist}" = "" ]; then
    echo "Connot find doc/${stuid}_pa1_report"
    cd ../../
    rm -rf check_$$
    exit
fi

rm -f bin/$binaryFileName
make clean
make

if [ ! -f bin/$binaryFileName ]; then
    echo "Connot find bin/$binaryFileName"
    cd ../../
    rm -rf check_$$
    exit
fi

./bin/mysort -IS 10.ac.in 10.ac.out

echo "checking output ..."
./utility/PA1_Result_Checker outputs/10.ac.out

cd ../../

echo "Congratulations!  Passed submission checking!"

rm -rf check_$$



