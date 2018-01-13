#include <iostream>
#include <cstdio>

#include "RegisterMap.hh"
#include "ProbeMap.hh"
#include "DelayValue.hh"
#include "PreScaleValue.hh"
#include "network.hh"
#include "UDPRBCP.hh"
#include "CommandMan.hh"
#include "FPGAModule.hh"
#include "CoinModule.hh"
#include "rbcp.h"
#include "errno.h"
#include "daq_funcs.hh"

using namespace HUL_Trigger;
using namespace Probe;
using namespace DelayValue;
int main(int argc, char* argv[])
{
//  if(1 == argc){
  if(1 != argc){
    std::cout << "Usage\n";
//    std::cout << "hul_main [IP address]" << std::endl;
    std::cout << "ONLY_hul_main" << std::endl;
    return 0;
  }// usage
  
// body ------------------------------------------------------
//  char* board_ip = argv[1];
  char* board_ip                  ;
//  char fixedip[] = "192.168.11.11";
  char fixedip[] = "192.168.10.65";
  board_ip = fixedip;
  rbcp_header rbcpHeader;
  rbcpHeader.type = UDPRBCP::rbcp_ver_;
  rbcpHeader.id   = 0;

  FPGAModule fModule(board_ip, udp_port, &rbcpHeader, 0);

//-------------------------------------------------------------------------
// IOM : In/Out Maneger ( NIMOUT Signal Select ) Module
//-------------------------------------------------------------------------
//  fModule.WriteModule(   IOM::mid,  IOM::NIMOUT1  ,          0b100000);
//  fModule.WriteModule(   IOM::mid,  IOM::NIMOUT2  ,          0b011111);
//  fModule.WriteModule(   IOM::mid,  IOM::NIMOUT3  ,          0b001110);
//  fModule.WriteModule(   IOM::mid,  IOM::NIMOUT4  ,          0b100101);

  fModule.WriteModule(   IOM::mid,  IOM::NIMOUT1  ,        ID1::BH1_Beam);
  fModule.WriteModule(   IOM::mid,  IOM::NIMOUT2  ,        ID1::BH2_Beam);
  fModule.WriteModule(   IOM::mid,  IOM::NIMOUT3  ,        ID1::TOF_or  );
  fModule.WriteModule(   IOM::mid,  IOM::NIMOUT4  ,        ID1::clk10kHz);

                 ////////////////////////////////////////
                 //    ID 1                            //      
                 ////////////////////////////////////////
                 //     0            BH1_Beam          //        
                 //     1            BH2_Beam          //      
                 //     2            BH1_Pi            //      
                 //     3            BH2_Pi            //      
                 //     4            BH1_P             //      
                 //     5            BH2_P             //      
                 //     6            SAC_K_Scat        //      
                 //     7            TOF_K_Scat        //      
                 //     8            LC_K_Scat         //      
                 //     9            TOF_HT_K_Scat     //      
                 //     10           Other4_K_Scat     //      
                 //     11           Other5_K_Scat     //      
                 //     12           Beam_Beam_TOF     //      
                 //     13           SAC_or_Beam_TOF   //      
                 //     14           TOF_or_Beam_TOF   //      
                 //     15           LC_or_Beam_TOF    //      
                 //     16           TOF_HT_Beam_TOF   //      
                 //     17           Other4_Beam_TOF   //      
                 //     18           Other5_Beam_TOF   //      
                 //     19           Beam_Coin1        //      
                 //     20           SAC_or_Coin1      //      
                 //     21           TOF_or_Coin1      //      
                 //     22           LC_or_Coin1       //      
                 //     23           TOF_HT_Coin1      //      
                 //     24           Other4_Coin1      //      
                 //     25           Other5_Coin1      //      
                 //     26           Beam_E03          //      
                 //     27           Other1_E03        //      
                 //     28           Other2_E03        //      
                 //     29           Other3_E03        //      
                 //     30           Other4_E03        //      
                 //     31           Other5_E03        //      
                 //     32           PS_OR_DLY         //      
                 //     33           K_Scat_Else_OR    //      
                 //     34           BH2_1_DLY         //      
                 //     35           BH2_2_DLY         //      
                 //     36           BH2_3_DLY         //      
                 //     37           BH2_4_DLY         //      
                 //     38           BH2_5_DLY         //      
                 //     39           BH2_6_DLY         //     
                 //     40           BH2_7_DLY         //     
                 //     41           BH2_8_DLY         // 
                 //     42                             // 
                 //     43                             // 
                 //     44                             // 
                 //     45                             // 
                 //     46                             // 
                 ////////////////////////////////////////

  return 0;

}// main
