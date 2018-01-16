#!/bin/bash

last_log=$HOME/work/HUL_Trigger/last.log

function onoff(){
    if [ "$1" == "0" ]; then echo -e "\e[90mOFF\e[0m"; fi
    if [ "$1" == "1" ]; then echo -e "\e[32mON\e[0m"; fi
}

function coin(){
    if [ "$1" == "2" ]; then echo -e "\e[90mOFF\e[0m"; fi
    if [ "$1" == "0" ]; then echo -e "\e[90mVeto\e[0m"; fi
    if [ "$1" == "1" ]; then echo -e "\e[32mON\e[0m"; fi
}


while true
do

#date "+%Y/%m/%d %H:%M:%S"

    buf=

    while read line
    do 
	Beam_BH1=`echo $line | awk '$1=="RGN1::Coin_ctrl_Beam" {print $2}'`
	if [ "$Beam_BH1" != "" ]; then
	    Beam_BH1=`onoff $(($Beam_BH1>>1 & 1))`
	    buf=$buf"Beam_BH1\t$Beam_BH1\n"
	fi

	Beam_BH2=`echo $line | awk '$1=="RGN1::Coin_ctrl_Beam" {print $2}'`
	if [ "$Beam_BH2" != "" ]; then
	    Beam_BH2=`onoff $(($Beam_BH2 & 1))`
	    buf=$buf"Beam_BH2\t$Beam_BH2\n"
	fi

	Selector_PS=`echo $line | awk '$1=="RGN3::Selector_PS" { print $2 }'`
	if [ "$Selector_PS" != "" ]; then
	    Beam=`onoff $(($Selector_PS>>6 & 1))`
	    Beam_TOF=`onoff $(($Selector_PS>>5 & 1))`
	    Beam_pi=`onoff $(($Selector_PS>>4 & 1))`
	    Beam_p=`onoff $(($Selector_PS>>3 & 1))`
	    Coin1=`onoff $(($Selector_PS>>2 & 1))`
	    Coin2=`onoff $(($Selector_PS>>1 & 1))`
	    E03=`onoff $(($Selector_PS&1))`
	    buf=$buf"Beam\t\t$Beam\n"
	    buf=$buf"Beam_TOF\t$Beam_TOF\n"
	    buf=$buf"Beam_pi\t\t$Beam_pi\n"
	    buf=$buf"Beam_p\t\t$Beam_p\n"
	    buf=$buf"Coin1\t\t$Coin1\n"
	    buf=$buf"Coin2\t\t$Coin2\n"
	    buf=$buf"E03\t\t$E03\n"
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
	    buf=$buf"BH2_1_K\t\t$BH2_1_K\n"
	    buf=$buf"BH2_2_K\t\t$BH2_2_K\n"
	    buf=$buf"BH2_3_K\t\t$BH2_3_K\n"
	    buf=$buf"BH2_4_K\t\t$BH2_4_K\n"
	    buf=$buf"BH2_5_K\t\t$BH2_5_K\n"
	    buf=$buf"BH2_6_K\t\t$BH2_6_K\n"
	    buf=$buf"BH2_7_K\t\t$BH2_7_K\n"
	    buf=$buf"BH2_8_K\t\t$BH2_8_K\n"
	fi

	Clock=`echo $line | awk '$1=="RGN4::Selector_Clock" {print $2}'`
	if [ "$Clock" != "" ]; then
	    Clock=`onoff $Clock`
	    buf=$buf"Clock\t\t$Clock\n"
	fi

	Reserve2=`echo $line | awk '$1=="RGN4::Selector_Reserve2" {print $2}'`
	if [ "$Reserve2" != "" ]; then
	    Reserve2=`onoff    $Reserve2`
	    buf=$buf"Reserve2\t$Reserve2\n"
	fi

	Beam_PS=`echo $line | awk '$1=="RGN3::PreScale_Beam" {print $2}'`
	if [ "$Beam_PS" != "" ]; then
	    buf=$buf"Beam_PS\t\t$(($Beam_PS + 1))\n"
	fi

	Beam_TOF_PS=`echo $line | awk '$1=="RGN3::PreScale_Beam_TOF" {print $2}'`
	if [ "$Beam_TOF_PS" != "" ]; then
	    buf=$buf"Beam_TOF_PS\t$(($Beam_TOF_PS + 1))\n"
	fi

	Beam_Pi_PS=`echo $line | awk '$1=="RGN3::PreScale_Beam_Pi" {print $2}'`
	if [ "$Beam_Pi_PS" != "" ]; then
	    buf=$buf"Beam_Pi_PS\t$(($Beam_Pi_PS + 1))\n"
	fi

	Beam_P_PS=`echo $line | awk '$1=="RGN3::PreScale_Beam_P" {print $2}'`
	if [ "$Beam_P_PS" != "" ]; then
	    buf=$buf"Beam_P_PS\t$(($Beam_P_PS + 1))\n"
	fi

	Coin1_PS=`echo $line | awk '$1=="RGN3::PreScale_Coin1" {print $2}'`
	if [ "$Coin1_PS" != "" ]; then
	    buf=$buf"Coin1_PS\t$(($Coin1_PS + 1))\n"
	fi

	Coin2_PS=`echo $line | awk '$1=="RGN3::PreScale_Coin2" {print $2}'`
	if [ "$Coin2_PS" != "" ]; then
	    buf=$buf"Coin2_PS\t$(($Coin2_PS + 1))\n"
	fi

	For_E03_PS=`echo $line | awk '$1=="RGN3::PreScale_For_E03" {print $2}'`
	if [ "$For_E03_PS" != "" ]; then
	    buf=$buf"For_E03_PS\t$(($For_E03_PS + 1))"
	fi
	
    done < $last_log 

    clear
    echo -e $buf

    sleep 1
done
