#!/bin/bash
job=$1

cdir="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
dir=${cdir}/../samples

cd ${dir}/${job}/
hadd main_${job}.root RPV_${job}_*.root 

cd ${dir}/../
