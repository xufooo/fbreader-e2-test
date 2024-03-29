#!/bin/sh

MYFILE=`basename $0`
MYPATH=`echo $0 | sed -e 's/'$MYFILE'//g'`
cd $MYPATH

export FBDIR=$MYPATH
export QTDIR=/usr/lib/ezx
export LD_LIBRARY_PATH=$QTDIR/lib:$LD_LIBRARY_PATH
export PATH=$FBDIR/bin:$PATH
export HOME=$MYPATH/home 

mkdir -p $HOME

exec FBReader
