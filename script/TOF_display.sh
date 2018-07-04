#!/bin/bash

last_log=$HOME/work/HUL_Trigger/last.log

function onoff_bh2k(){
    if [ "$1" == "0" ]; then echo -e "\e[90m.\e[0m"; fi
    if [ "$1" == "1" ]; then echo -e "\e[32m!\e[0m"; fi
}


while true
do

#date "+%Y/%m/%d %H:%M:%S"

    buf=

    while read line
    do
	SEL_TOF=`echo $line | awk '$1=="RGN1::SEL_TOF" {print $2}'`
	if [ "$SEL_TOF" != "" ]; then
	    TOF_Seg_1=`onoff_bh2k $(($SEL_TOF & 1))`
	    TOF_Seg_2=`onoff_bh2k $(($SEL_TOF>>1 & 1))`
	    TOF_Seg_3=`onoff_bh2k $(($SEL_TOF>>2 & 1))`
	    TOF_Seg_4=`onoff_bh2k $(($SEL_TOF>>3 & 1))`
	    TOF_Seg_5=`onoff_bh2k $(($SEL_TOF>>4 & 1))`
	    TOF_Seg_6=`onoff_bh2k $(($SEL_TOF>>5 & 1))`
	    TOF_Seg_7=`onoff_bh2k $(($SEL_TOF>>6 & 1))`
	    TOF_Seg_8=`onoff_bh2k $(($SEL_TOF>>7 & 1))`
	    TOF_Seg_9=`onoff_bh2k $(($SEL_TOF>>8 & 1))`
	    TOF_Seg_10=`onoff_bh2k $(($SEL_TOF>>9 & 1))`
	    TOF_Seg_11=`onoff_bh2k $(($SEL_TOF>>10 & 1))`
	    TOF_Seg_12=`onoff_bh2k $(($SEL_TOF>>11 & 1))`
	    TOF_Seg_13=`onoff_bh2k $(($SEL_TOF>>12 & 1))`
	    TOF_Seg_14=`onoff_bh2k $(($SEL_TOF>>13 & 1))`
	    TOF_Seg_15=`onoff_bh2k $(($SEL_TOF>>14 & 1))`
	    TOF_Seg_16=`onoff_bh2k $(($SEL_TOF>>15 & 1))`
	    TOF_Seg_17=`onoff_bh2k $(($SEL_TOF>>16 & 1))`
	    TOF_Seg_18=`onoff_bh2k $(($SEL_TOF>>17 & 1))`
	    TOF_Seg_19=`onoff_bh2k $(($SEL_TOF>>18 & 1))`
	    TOF_Seg_20=`onoff_bh2k $(($SEL_TOF>>19 & 1))`
	    TOF_Seg_21=`onoff_bh2k $(($SEL_TOF>>20 & 1))`
	    TOF_Seg_22=`onoff_bh2k $(($SEL_TOF>>21 & 1))`
	    TOF_Seg_23=`onoff_bh2k $(($SEL_TOF>>22 & 1))`
	    TOF_Seg_24=`onoff_bh2k $(($SEL_TOF>>23 & 1))`
	    buf=$buf"TOF_Seg_1_8\t\t$TOF_Seg_1"
	    buf=$buf"$TOF_Seg_2"
	    buf=$buf"$TOF_Seg_3"
	    buf=$buf"$TOF_Seg_4"
	    buf=$buf"$TOF_Seg_5"
	    buf=$buf"$TOF_Seg_6"
	    buf=$buf"$TOF_Seg_7"
	    buf=$buf"$TOF_Seg_8\n"
	    buf=$buf"TOF_Seg_9_16\t\t$TOF_Seg_9"
	    buf=$buf"$TOF_Seg_10"
	    buf=$buf"$TOF_Seg_11"
	    buf=$buf"$TOF_Seg_12"
	    buf=$buf"$TOF_Seg_13"
	    buf=$buf"$TOF_Seg_14"
	    buf=$buf"$TOF_Seg_15"
	    buf=$buf"$TOF_Seg_16\n"
	    buf=$buf"TOF_Seg_17_24\t\t$TOF_Seg_17"
	    buf=$buf"$TOF_Seg_18"
	    buf=$buf"$TOF_Seg_19"
	    buf=$buf"$TOF_Seg_20"
	    buf=$buf"$TOF_Seg_21"
	    buf=$buf"$TOF_Seg_22"
	    buf=$buf"$TOF_Seg_23"
	    buf=$buf"$TOF_Seg_24\n"
	fi

    done < $last_log

    clear
    echo -e $buf

    sleep 1
done
