#!/bin/bash


last_log=$HOME/work/HUL_Trigger/last.log

function onoff(){
  if [ "$1" == "0" ]; then echo OFF; fi
  if [ "$1" == "1" ]; then echo ON; fi
}


while read line
do 
 Selector_PS=`echo $line | awk '$1=="RGN3::Selector_PS" {print $2}'`
  if [ "$Selector_PS" != "" ]; then
    Beam=`onoff $(($Selector_PS>>6 & 1))`
    Beam_TOF=`onoff $(($Selector_PS>>5 & 1))`
    Beam_pi=`onoff $(($Selector_PS>>4 & 1))`
    Beam_p=`onoff $(($Selector_PS>>3 & 1))`
    Coin1=`onoff $(($Selector_PS>>2 & 1))`
    Coin2=`onoff $(($Selector_PS>>1 & 1))`
    E03=`onoff $(($Selector_PS&1))`
    echo "Beam         $Beam     "
    echo "Beam_TOF     $Beam_TOF "
    echo "Beam_pi      $Beam_pi  "
    echo "Beam_p       $Beam_p   "
    echo "Coin1        $Coin1    "
    echo "Coin2        $Coin2    "
    echo "E03          $E03      "
  fi

 Selector_8=`echo $line | awk '$1=="RGN4::Selector_8" {print $2}'`
  if [ "$Selector_8" != "" ]; then
    BH2_1_K=`onoff $(($Selector_8>>7 & 1))`
    BH2_2_K=`onoff $(($Selector_8>>6 & 1))`
    BH2_3_K=`onoff $(($Selector_8>>5 & 1))`
    BH2_4_K=`onoff $(($Selector_8>>4 & 1))`
    BH2_5_K=`onoff $(($Selector_8>>3 & 1))`
    BH2_6_K=`onoff $(($Selector_8>>2 & 1))`
    BH2_7_K=`onoff $(($Selector_8>>1 & 1))`
    BH2_8_K=`onoff $(($Selector_8&1))`
    echo "BH2_1_K      $BH2_1_K "
    echo "BH2_2_K      $BH2_2_K "
    echo "BH2_3_K      $BH2_3_K "
    echo "BH2_4_K      $BH2_4_K "
    echo "BH2_5_K      $BH2_5_K "
    echo "BH2_6_K      $BH2_6_K "
    echo "BH2_7_K      $BH2_7_K "
    echo "BH2_8_K      $BH2_8_K "
  fi

 Clock=`echo $line | awk '$1=="RGN4::Selector_Clock" {print $2}'`
  if [ "$Clock" != "" ]; then
    Clock=`onoff $Clock`
    echo "Clock        $Clock"
  fi

 Reserve2=`echo $line | awk '$1=="RGN4::Selector_Reserve2" {print $2}'`
  if [ "$Reserve2" != "" ]; then
    Reserve2=`onoff    $Reserve2`
    echo "Reserve2     $Reserve2"
  fi

 Beam_PS=`echo $line | awk '$1=="RGN3::PreScale_Beam" {print $2}'`
  if [ "$Beam_PS" != "" ]; then
    echo "Beam_PS      $(($Beam_PS + 1))"
  fi

 Beam_TOF_PS=`echo $line | awk '$1=="RGN3::PreScale_Beam_TOF" {print $2}'`
  if [ "$Beam_TOF_PS" != "" ]; then
    echo "Beam_TOF_PS  $(($Beam_TOF_PS + 1))"
  fi

 Beam_Pi_PS=`echo $line | awk '$1=="RGN3::PreScale_Beam_Pi" {print $2}'`
  if [ "$Beam_Pi_PS" != "" ]; then
    echo "Beam_Pi_PS   $(($Beam_Pi_PS + 1))"
  fi

 Beam_P_PS=`echo $line | awk '$1=="RGN3::PreScale_Beam_P" {print $2}'`
  if [ "$Beam_P_PS" != "" ]; then
    echo "Beam_P_PS    $(($Beam_P_PS + 1))"
  fi

 Coin1_PS=`echo $line | awk '$1=="RGN3::PreScale_Coin1" {print $2}'`
  if [ "$Coin1_PS" != "" ]; then
    echo "Coin1_PS     $(($Coin1_PS + 1))"
  fi

 Coin2_PS=`echo $line | awk '$1=="RGN3::PreScale_Coin2" {print $2}'`
  if [ "$Coin2_PS" != "" ]; then
    echo "Coin2_PS     $(($Coin2_PS + 1))"
  fi

 For_E03_PS=`echo $line | awk '$1=="RGN3::PreScale_For_E03" {print $2}'`
  if [ "$For_E03_PS" != "" ]; then
    echo "For_E03_PS   $(($For_E03_PS + 1))"
  fi

done < $last_log 

