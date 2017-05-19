#!/bin/bash
file=$1;
jobname=$2;
dir=$3;

j=0
while read line
do
j=$[1+$j];
k=$[$j/2];

echo $line >> ${jobname}_${k}.txt; 

done<${file}

j=0;
for j in `seq 0 $k`;
do  
    qsub -l h_vmem=1G -l projectio=1 selection.sh ${jobname} $j ${dir};
done 

echo "finished job submission " $[$j+1] " jobs submitted. "











