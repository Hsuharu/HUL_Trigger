#!/bin/bash


last_log=$HOME/work/HUL_Trigger/nimIO.log

function onoff(){
  if [ "$1" == "0" ]; then echo -e "\e[90mOFF\e[0m"; fi
  if [ "$1" == "1" ]; then echo -e "\e[32mON\e[0m"; fi
}
function nimid(){
  if [ "$1" == "0" ];  then echo  "BH1_Beam       "; fi
  if [ "$1" == "1" ];  then echo  "BH2_Beam       "; fi
  if [ "$1" == "2" ];  then echo  "BH1_pi         "; fi
  if [ "$1" == "3" ];  then echo  "BH2_pi         "; fi
  if [ "$1" == "4" ];  then echo  "BH1_p          "; fi
  if [ "$1" == "5" ];  then echo  "BH2_p          "; fi
  if [ "$1" == "6" ];  then echo  "K_Scat_SAC     "; fi
  if [ "$1" == "7" ];  then echo  "K_Scat_TOF     "; fi
  if [ "$1" == "8" ];  then echo  "K_Scat_LC       "; fi
  if [ "$1" == "9" ];  then echo  "K_Scat_TOF_HT  "; fi
  if [ "$1" == "10" ]; then echo  "K_Scat_Other4  "; fi
  if [ "$1" == "11" ]; then echo  "K_Scat_Other5  "; fi
  if [ "$1" == "12" ]; then echo  "Beam_TOF_Beam  "; fi
  if [ "$1" == "13" ]; then echo  "Beam_TOF_SAC_or"; fi
  if [ "$1" == "14" ]; then echo  "Beam_TOF_TOF_or"; fi
  if [ "$1" == "15" ]; then echo  "Beam_TOF_LC_or "; fi
  if [ "$1" == "16" ]; then echo  "Beam_TOF_TOF_HT"; fi
  if [ "$1" == "17" ]; then echo  "Beam_TOF_Other4"; fi
  if [ "$1" == "18" ]; then echo  "Beam_TOF_Other5"; fi
  if [ "$1" == "19" ]; then echo  "Beam_Coin1     "; fi
  if [ "$1" == "20" ]; then echo  "Coin1_SAC_or   "; fi
  if [ "$1" == "21" ]; then echo  "Coin1_TOF_or   "; fi
  if [ "$1" == "22" ]; then echo  "Coin1_LC_or    "; fi
  if [ "$1" == "23" ]; then echo  "Coin1_TOF_HT   "; fi
  if [ "$1" == "24" ]; then echo  "Coin1_Other4   "; fi
  if [ "$1" == "25" ]; then echo  "Coin1_Other5   "; fi
  if [ "$1" == "26" ]; then echo  "E03_Beam       "; fi
  if [ "$1" == "27" ]; then echo  "E03_Other1     "; fi
  if [ "$1" == "28" ]; then echo  "E03_Other2     "; fi
  if [ "$1" == "29" ]; then echo  "E03_Other3     "; fi
  if [ "$1" == "30" ]; then echo  "E03_Other4     "; fi
  if [ "$1" == "31" ]; then echo  "E03_Other5     "; fi
  if [ "$1" == "32" ]; then echo  "PS_OR_DLY      "; fi
  if [ "$1" == "33" ]; then echo  "Else_OR_K_Scat "; fi
  if [ "$1" == "34" ]; then echo  "(BH2_1,K)       "; fi
  if [ "$1" == "35" ]; then echo  "(BH2_2,K)       "; fi
  if [ "$1" == "36" ]; then echo  "(BH2_3,K)       "; fi
  if [ "$1" == "37" ]; then echo  "(BH2_4,K)       "; fi
  if [ "$1" == "38" ]; then echo  "(BH2_5,K)       "; fi
  if [ "$1" == "39" ]; then echo  "(BH2_6,K)       "; fi
  if [ "$1" == "40" ]; then echo  "(BH2_7,K)       "; fi
  if [ "$1" == "41" ]; then echo  "(BH2_8,K)       "; fi
}

while true
do
#date "+%Y/%m/%d %H:%M:%S"
while read line
do 
 NIMOUT1=`echo $line | awk '$1=="IOM::NIMOUT1" {print $2}'`
  if [ "$NIMOUT1" != "" ]; then
    NIMOUT1=`nimid $(($NIMOUT1))`
    echo "NIMOUT1    $NIMOUT1"
  fi

 NIMOUT2=`echo $line | awk '$1=="IOM::NIMOUT2" {print $2}'`
  if [ "$NIMOUT2" != "" ]; then
    NIMOUT2=`nimid $(($NIMOUT2))`
    echo "NIMOUT2    $NIMOUT2"
  fi

 NIMOUT3=`echo $line | awk '$1=="IOM::NIMOUT3" {print $2}'`
  if [ "$NIMOUT3" != "" ]; then
    NIMOUT3=`nimid $(($NIMOUT3))`
    echo "NIMOUT3    $NIMOUT3"
  fi

 NIMOUT4=`echo $line | awk '$1=="IOM::NIMOUT4" {print $2}'`
  if [ "$NIMOUT4" != "" ]; then
    NIMOUT4=`nimid $(($NIMOUT4))`
    echo "NIMOUT4    $NIMOUT4"
  fi

done < $last_log 

sleep 5 
clear
done
