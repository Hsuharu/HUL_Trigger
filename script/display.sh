#!/bin/bash

last_log=$HOME/work/HUL_Trigger/last.log

function onoff(){
    if [ "$1" == "0" ]; then echo -e "\e[90mOFF\e[0m"; fi
    if [ "$1" == "1" ]; then echo -e "\e[32mON\e[0m"; fi
}

<<<<<<< HEAD
function onoff_bh2k(){
    if [ "$1" == "0" ]; then echo -e "\e[90m.\e[0m"; fi
    if [ "$1" == "1" ]; then echo -e "\e[32m!\e[0m"; fi
}

=======
>>>>>>> 8f8035e224460a269bb5d4e591d850172e942b42
function coin(){
    if [ "$1" == "2" ]; then echo -e "\e[90mOFF\e[0m"; fi
    if [ "$1" == "0" ]; then echo -e "\e[90mVeto\e[0m"; fi
    if [ "$1" == "1" ]; then echo -e "\e[32mON\e[0m"; fi
}

<<<<<<< HEAD
function coin_beam(){
     if [ "$1" == "3" ]; then echo -e "\e[35mCoin\e[0m"; fi
     if [ "$1" == "1" ]; then echo -e "\e[35mBH2\e[0m"; fi
     if [ "$1" == "2" ]; then echo -e "\e[35mBH1\e[0m"; fi
}

function coin_sel(){
     if [ "$1" == "64" ]; then echo -e "\e[35mBeam\e[0m"; fi
     if [ "$1" == "32" ]; then echo -e "\e[35mSAC\e[0m"; fi
     if [ "$1" == "24" ]; then echo -e "\e[35mTOFandLC\e[0m"; fi
     if [ "$1" == "16" ]; then echo -e "\e[35mTOF\e[0m"; fi
     if [ "$1" == "8" ]; then echo -e "\e[35mLC\e[0m"; fi
     if [ "$1" == "4" ]; then echo -e "\e[35mTOF-HT\e[0m"; fi
     if [ "$1" == "2" ]; then echo -e "\e[35mBGO\e[0m"; fi
     if [ "$1" == "1" ]; then echo -e "\e[35mOther5\e[0m"; fi
     if [ "$1" == "0" ]; then echo -e "\e[90mOFF\e[0m"; fi
}


=======
<<<<<<< HEAD
function coin_beam(){
     if [ "$1" == "3" ]; then echo -e "\e[31mCoin\e[0m"; fi
     if [ "$1" == "1" ]; then echo -e "\e[31mBH2\e[0m"; fi
     if [ "$1" == "2" ]; then echo -e "\e[31mBH1\e[0m"; fi
}

function bcoin(){
     if [ "$1" == "3" ]; then echo -e "\e[32mCoin\e[0m"; fi
     if [ "$1" == "2" ]; then echo -e "\e[32mBH1\e[0m"; fi
     if [ "$1" == "1" ]; then echo -e "\e[32mBH2\e[0m"; fi
}


=======
>>>>>>> 7dfda778472af485f7d14c21b21f1d1a5688f408
>>>>>>> 8f8035e224460a269bb5d4e591d850172e942b42

while true
do

#date "+%Y/%m/%d %H:%M:%S"

    buf=

    while read line
<<<<<<< HEAD
    do
        defBeam=`echo $line | awk '$1=="RGN1::Coin_ctrl_Beam" { print $2 }'`
       	    if [ "$defBeam" != "" ]; then
       	        defBeam=`coin_beam $(($defBeam))`
       	        buf=$buf"Beam is\t$defBeam\n"
       	    fi


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
	    buf=$buf"TOF_Seg_1_8\t$TOF_Seg_1"
	    buf=$buf"$TOF_Seg_2"
	    buf=$buf"$TOF_Seg_3"
	    buf=$buf"$TOF_Seg_4"
	    buf=$buf"$TOF_Seg_5"
	    buf=$buf"$TOF_Seg_6"
	    buf=$buf"$TOF_Seg_7"
	    buf=$buf"$TOF_Seg_8\n"
	    buf=$buf"TOF_Seg_9_16\t$TOF_Seg_9"
	    buf=$buf"$TOF_Seg_10"
	    buf=$buf"$TOF_Seg_11"
	    buf=$buf"$TOF_Seg_12"
	    buf=$buf"$TOF_Seg_13"
	    buf=$buf"$TOF_Seg_14"
	    buf=$buf"$TOF_Seg_15"
	    buf=$buf"$TOF_Seg_16\n"
	    buf=$buf"TOF_Seg_17_24\t$TOF_Seg_17"
	    buf=$buf"$TOF_Seg_18"
	    buf=$buf"$TOF_Seg_19"
	    buf=$buf"$TOF_Seg_20"
	    buf=$buf"$TOF_Seg_21"
	    buf=$buf"$TOF_Seg_22"
	    buf=$buf"$TOF_Seg_23"
	    buf=$buf"$TOF_Seg_24\n"
	fi


        defExTrigger=`echo $line | awk '$1=="RGN2_5::Coin_ctrl_7" { print $2 }'`
       	    if [ "$defExTrigger" != "" ]; then
       	        defExTrigger=`coin_sel $(($defExTrigger))`
       	        buf=$buf"ExTrigger is\t$defExTrigger\n\n"
       	    fi

=======
    do 
<<<<<<< HEAD
        defBeam=`echo $line | awk '$1=="RGN1::Coin_ctrl_Beam" { print $2 }'`
       	    if [ "$defBeam" != "" ]; then
       	        defBeam=`coin_beam $(($defBeam))`
       	        buf=$buf"Beam is\t$defBeam\n\n"
       	    fi
=======
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
>>>>>>> 7dfda778472af485f7d14c21b21f1d1a5688f408
>>>>>>> 8f8035e224460a269bb5d4e591d850172e942b42

	Selector_PS=`echo $line | awk '$1=="RGN3::Selector_PS" { print $2 }'`
	if [ "$Selector_PS" != "" ]; then
	    Beam=`onoff $(($Selector_PS>>6 & 1))`
	    Beam_TOF=`onoff $(($Selector_PS>>5 & 1))`
	    Beam_pi=`onoff $(($Selector_PS>>4 & 1))`
	    Beam_p=`onoff $(($Selector_PS>>3 & 1))`
	    Coin1=`onoff $(($Selector_PS>>2 & 1))`
<<<<<<< HEAD
	    ExTrigger=`onoff $(($Selector_PS>>1 & 1))`
#	    E03=`onoff $(($Selector_PS&1))`
=======
#	    Coin2=`onoff $(($Selector_PS>>1 & 1))`
	    E03=`onoff $(($Selector_PS&1))`
>>>>>>> 8f8035e224460a269bb5d4e591d850172e942b42
	    buf=$buf"Beam\t\t$Beam\n"
	    buf=$buf"Beam_TOF\t$Beam_TOF\n"
	    buf=$buf"Beam_pi\t\t$Beam_pi\n"
	    buf=$buf"Beam_p\t\t$Beam_p\n"
	    buf=$buf"Coin1\t\t$Coin1\n"
<<<<<<< HEAD
#	    buf=$buf"E03\t\t$E03\n"
	    buf=$buf"ExTrigger\t$ExTrigger\n"
=======
#	    buf=$buf"Coin2\t\t$Coin2\n"
	    buf=$buf"E03\t\t$E03\n"
>>>>>>> 8f8035e224460a269bb5d4e591d850172e942b42
	fi


	Selector_8=`echo $line | awk '$1=="RGN4::Selector_8" {print $2}'`
	if [ "$Selector_8" != "" ]; then
	    BH2_1_K=`onoff_bh2k $(($Selector_8>>7 & 1))`
	    BH2_2_K=`onoff_bh2k $(($Selector_8>>6 & 1))`
	    BH2_3_K=`onoff_bh2k $(($Selector_8>>5 & 1))`
	    BH2_4_K=`onoff_bh2k $(($Selector_8>>4 & 1))`
	    BH2_5_K=`onoff_bh2k $(($Selector_8>>3 & 1))`
	    BH2_6_K=`onoff_bh2k $(($Selector_8>>2 & 1))`
	    BH2_7_K=`onoff_bh2k $(($Selector_8>>1 & 1))`
	    BH2_8_K=`onoff_bh2k $(($Selector_8&1))`
	    buf=$buf"BH2_K\t\t$BH2_1_K"
	    buf=$buf"$BH2_2_K"
	    buf=$buf"$BH2_3_K"
	    buf=$buf"$BH2_4_K"
	    buf=$buf"$BH2_5_K"
	    buf=$buf"$BH2_6_K"
	    buf=$buf"$BH2_7_K"
	    buf=$buf"$BH2_8_K\n"
	    # buf=$buf"BH2_1_K\t\t$BH2_1_K\n"
	    # buf=$buf"BH2_2_K\t\t$BH2_2_K\n"
	    # buf=$buf"BH2_3_K\t\t$BH2_3_K\n"
	    # buf=$buf"BH2_4_K\t\t$BH2_4_K\n"
	    # buf=$buf"BH2_5_K\t\t$BH2_5_K\n"
	    # buf=$buf"BH2_6_K\t\t$BH2_6_K\n"
	    # buf=$buf"BH2_7_K\t\t$BH2_7_K\n"
	    # buf=$buf"BH2_8_K\t\t$BH2_8_K\n"
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

<<<<<<< HEAD
#	E03_PS=`echo $line | awk '$1=="RGN3::PreScale_For_E03" {print $2}'`
#	if [ "$E03_PS" != "" ]; then
#	    buf=$buf"E03_PS\t\t$(($E03_PS + 1))\n"
=======
#	Coin2_PS=`echo $line | awk '$1=="RGN3::PreScale_Coin2" {print $2}'`
#	if [ "$Coin2_PS" != "" ]; then
#	    buf=$buf"Coin2_PS\t$(($Coin2_PS + 1))\n"
>>>>>>> 8f8035e224460a269bb5d4e591d850172e942b42
#	fi

	FreeTrigger=`echo $line | awk '$1=="Extra_Line_PreScale" {print $2}'`
	if [ "$FreeTrigger" != "" ]; then
	    buf=$buf"ExTrigger_PS\t$(($FreeTrigger + 1))\n"
	fi

<<<<<<< HEAD

    done < $last_log
=======
	ExTrigger_PS=`echo $line | awk '$1=="RGN3::Selector_PS" { print $2 }'`
	if [ "$Selector_PS" != "" ]; then
	    ExTrigger=`onoff $(($ExTrigger_PS>>2 & 1))`
	    buf=$buf"ExTrigger\t$ExTrigger\n"
	fi

	FreeTrigger=`echo $line | awk '$1=="Extra_Line_PreScale" {print $2}'`
	if [ "$FreeTrigger" != "" ]; then
	    buf=$buf"ExTrigger\t$(($FreeTrigger + 1))\n"
	fi

	
    done < $last_log 
>>>>>>> 8f8035e224460a269bb5d4e591d850172e942b42

    clear
    echo -en $buf

    sleep 1
done
