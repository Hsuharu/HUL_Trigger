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
  if(1 == argc){
    std::cout << "Usage\n";
    std::cout << "set_nimio [IP address]" << std::endl;
    return 0;
  }// usage
  
// body ------------------------------------------------------
  char* board_ip = argv[1];
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
  fModule.WriteModule(   IOM::mid,  IOM::NIMOUT3  ,        ID2::TOF_or  );
  fModule.WriteModule(   IOM::mid,  IOM::NIMOUT4  ,        ID2::clk10kHz);

/////////////////////////////////////////////////////////////////////////////////
//    ID 1                            //     ID 2                              //      
/////////////////////////////////////////////////////////////////////////////////
//     0            BH1_Beam          //      0       Else_OR                  //        
//     1            BH2_Beam          //      1       BH2_1_K                  //      
//     2            BH1_Pi            //      2       BH2_2_K                  //      
//     3            BH2_Pi            //      3       BH2_3_K                  //      
//     4            BH1_P             //      4       BH2_4_K                  //      
//     5            BH2_P             //      5       BH2_5_K                  //      
//     6            SAC_K_Scat        //      6       BH2_6_K                  //      
//     7            TOF_K_Scat        //      7       BH2_7_K                  //      
//     8            LC_K_Scat         //      8       BH2_8_K                  //      
//     9            TOF_HT_K_Scat     //      9       BH2_K_OR                 //      
//     10           Other4_K_Scat     //      10      Other1                   //      
//     11           Other5_K_Scat     //      11      Other2                   //      
//     12           Beam_Beam_TOF     //      12      Other3                   //      
//     13           SAC_or_Beam_TOF   //      13      Other4                   //      
//     14           TOF_or_Beam_TOF   //      14      Other5                   //      
//     15           LC_or_Beam_TOF    //      15      Clock                    //      
//     16           TOF_HT_Beam_TOF   //      16      Reserve2                 //      
//     17           Other4_Beam_TOF   //      17      BH1_or                   //      
//     18           Other5_Beam_TOF   //      18      BH2_or                   //      
//     19           Beam_Coin1        //      19      SAC_or                   //      
//     20           SAC_or_Coin1      //      20      TOF_or                   //      
//     21           TOF_or_Coin1      //      21      LC_or                    //      
//     22           LC_or_Coin1       //      22      TOF_HT                   //      
//     23           TOF_HT_Coin1      //      23      Beam                     //      
//     24           Other4_Coin1      //      24      Pi_Beam                  //      
//     25           Other5_Coin1      //      25      P_Beam                   //      
//     26           Beam_E03          //      26      K_Scat                   //      
//     27           Other1_E03        //      27      Beam_TOF_Coin            //      
//     28           Other2_E03        //      28      Beam_Pi_Coin             //      
//     29           Other3_E03        //      29      Beam_P_Coin              //      
//     30           Other4_E03        //      30      Coin1_Coin               //      
//     31           Other5_E03        //      31      Coin2_Coin               //      
//     32           PS_OR_DLY         //      32      For_E03_Coin             //      
//     33           K_Scat_Else_OR    //      33      Beam_PS                  //      
//     34           BH2_1_DLY         //      34      Beam_TOF_PS              //      
//     35           BH2_2_DLY         //      35      Beam_Pi_PS               //      
//     36           BH2_3_DLY         //      36      Beam_P_PS                //      
//     37           BH2_4_DLY         //      37      Coin1_PS                 //      
//     38           BH2_5_DLY         //      38      Coin2_PS                 //      
//     39           BH2_6_DLY         //      39      For_E03_PS               //     
//     40           BH2_7_DLY         //      40      clk1MHz                  //     
//     41           BH2_8_DLY         //      41      clk100kHz                // 
//     42                             //      42      clk10kHz                 // 
//     43                             //      43      clk1kHz                  // 
//     44                             //      44                               // 
//     45                             //      45                               // 
//     46                             //      46                               // 
/////////////////////////////////////////////////////////////////////////////////

  return 0;

}// main
