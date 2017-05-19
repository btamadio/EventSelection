cdir="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
dir=${cdir}/../

echo ${dir}

rm *.txt
rm *.sh.e*
rm *.sh.o*


#source submit_selection.sh ${dir}/files/fileList.data15_13TeV.physics_Main.2017_02_14.p2950.txt data2015_njet2 ${dir}
#source submit_selection.sh ${dir}/files/fileList.data16_13TeV.physics_Main.2017_02_14.p2950.txt data2016_njet2 ${dir}

#source submit_selection.sh ${dir}/files/fileList.RPV10.AFII.2016_07_13_v2.txt RPV10_AFII_ht1000 ${dir}
#source submit_selection.sh ${dir}/files/fileList.RPV6.AFII.2016_07_13_v2.txt RPV6_AFII_ht1000 ${dir}

#source submit_selection.sh ${dir}/files/fileList.Pythia8EvtGen_A14NNPDF23LO_jetjet_JZXW.p2688.2017_02_14.txt pythia_HTtrig_njet2 ${dir}
#source submit_selection.sh ${dir}/files/fileList.RPV10.AFII.2016_07_13_v2.txt RPV10_HTtrig ${dir}
#source submit_selection.sh ${dir}/files/fileList.RPV6.AFII.2016_07_13_v2.txt RPV6_HTtrig ${dir}

#source submit_selection.sh ${dir}/files/fileList.Sherpa_jetjet.2017_03_27.txt sherpa_HTtrig_njet2 ${dir}
#source submit_selection.sh ${dir}/files/fileList.Herwigpp_jetjet.2017_03_24.txt herwigpp_HTtrig_njet2 ${dir}

#source submit_selection.sh ${dir}/files/fileList.RPV.2017_04_30_v2.txt RPV_2017_04_30_v2 ${dir}
#source submit_selection.sh ${dir}/files/fileList.Sherpa_jetjet.JZ3_plus.2017_03_27.txt sherpa_HTtrig_njet2_JZ_plus ${dir}

source submit_selection.sh ${dir}/files/fileList.PowhegPythia_ttbar.2017_01_22.txt ttbar_combined_mass ${dir}