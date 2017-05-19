#!/bin/bash
jobname=$1
j=$2
dir=$3

scratch_dir=${dir}/scratch/event_selection/

date
mkdir -p ${scratch_dir}
rm -rf ${scratch_dir}/evnt_${jobname}_${j}
mkdir ${scratch_dir}/evnt_${jobname}_${j}
cd ${scratch_dir}/evnt_${jobname}_${j}

shopt -s expand_aliases
source /common/atlas/scripts/setupATLAS.sh
setupATLAS
localSetupROOT
alias root="root -l"

mkdir files;
cp ${dir}/submit_event_selection/${jobname}_${j}.txt ./files;
cp ${dir}/bin/eventSelection .

./eventSelection ${jobname}_${j}.txt 

mkdir ${dir}/samples/${jobname}/

mv miniTree.root ${dir}/samples/${jobname}/RPV_${jobname}_${j}.root

cd ;
rm -rf  ${scratch_dir}/evnt_${jobname}_${j} ;
date
