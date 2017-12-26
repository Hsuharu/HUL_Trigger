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
int main(int argc, char* argv[])
{
  if(1 == argc){
    std::cout << "Usage\n";
    std::cout << "hul_main [IP address]" << std::endl;
    return 0;
  }// usage
  
// body ------------------------------------------------------
  char* board_ip = argv[1];
  rbcp_header rbcpHeader;
  rbcpHeader.type = UDPRBCP::rbcp_ver_;
  rbcpHeader.id   = 0;

  FPGAModule fModule(board_ip, udp_port, &rbcpHeader, 0);
  //  std::cout << std::hex << fModule.ReadModule(BCT::mid, BCT::laddr_Version, 4) << std::endl;


////////////////////////////////////////////////////////////////////////////////////////////////
//           Write                                                                            // 
//         Write                                                                              // 
//       Write                                                                                // 
////////////////////////////////////////////////////////////////////////////////////////////////

 //-------------------------------------------------------------------------
  // LED Module
  //-------------------------------------------------------------------------
  //  fModule.WriteModule(LED::mid, LED::laddr_led, 1);


  //-------------------------------------------------------------------------
  // RGN1 : Region1 Module
  //-------------------------------------------------------------------------
                                       
      //-- Pi,P Beam --
  fModule.WriteModule(   RGN1::mid,   RGN1::Delay_BH1_Pi        ,          1);
  fModule.WriteModule(   RGN1::mid,   RGN1::Delay_BH2_Pi        ,          1);
  fModule.WriteModule(   RGN1::mid,   RGN1::Delay_BH1_P         ,          2);
  fModule.WriteModule(   RGN1::mid,   RGN1::Delay_BH2_P         ,          1);

  fModule.WriteModule(   RGN1::mid,   RGN1::Width_BH1_Pi        ,          4);
  fModule.WriteModule(   RGN1::mid,   RGN1::Width_BH2_Pi        ,          4);
  fModule.WriteModule(   RGN1::mid,   RGN1::Width_BH1_P         ,          8);
  fModule.WriteModule(   RGN1::mid,   RGN1::Width_BH2_P         ,          4);
                                                              
      //-- K_Scat Coin--                 
  fModule.WriteModule(   RGN1::mid,   RGN1::Delay_SAC_K_Scat    ,          1);
  fModule.WriteModule(   RGN1::mid,   RGN1::Delay_TOF_K_Scat    ,          1);
  fModule.WriteModule(   RGN1::mid,   RGN1::Delay_LC_K_Scat     ,          1);
  fModule.WriteModule(   RGN1::mid,   RGN1::Delay_TOF_HT_K_Scat ,          1);
  fModule.WriteModule(   RGN1::mid,   RGN1::Delay_Other4_K_Scat ,          1);
  fModule.WriteModule(   RGN1::mid,   RGN1::Delay_Other5_K_Scat ,          1);

  fModule.WriteModule(   RGN1::mid,   RGN1::Width_SAC_K_Scat    ,         12);
  fModule.WriteModule(   RGN1::mid,   RGN1::Width_TOF_K_Scat    ,         12);
  fModule.WriteModule(   RGN1::mid,   RGN1::Width_Lucite_K_Scat ,         12);
  fModule.WriteModule(   RGN1::mid,   RGN1::Width_TOF_HT_K_Scat ,         12);
  fModule.WriteModule(   RGN1::mid,   RGN1::Width_Other4_K_Scat ,          8);
  fModule.WriteModule(   RGN1::mid,   RGN1::Width_Other5_K_Scat ,          8);
                                                              
      //-- K_Scat --                    
  fModule.WriteModule(   RGN1::mid,   RGN1::Delay_K_Scat        ,          1);
  fModule.WriteModule(   RGN1::mid,   RGN1::Width_K_Scat        ,          4);
                                                              
      //-- Coincidence -------         
  fModule.WriteModule(   RGN1::mid,   RGN1::Coin_ctrl_K_Scat    ,   0b000011);
  fModule.WriteModule(   RGN1::mid,   RGN1::Coin_coin_K_Scat    ,   0b000011);
  
  
  //-------------------------------------------------------------------------
  // RGN2_1 : Region2_1 ( Beam_TOF Coin) Module
  //-------------------------------------------------------------------------
  fModule.WriteModule(   RGN2_1::mid,   RGN2_1::Delay_Beam       ,           1);
  fModule.WriteModule(   RGN2_1::mid,   RGN2_1::Delay_SAC        ,           1);
  fModule.WriteModule(   RGN2_1::mid,   RGN2_1::Delay_TOF        ,           1);
  fModule.WriteModule(   RGN2_1::mid,   RGN2_1::Delay_LC         ,           1);
  fModule.WriteModule(   RGN2_1::mid,   RGN2_1::Delay_TOF_HT     ,           1);
  fModule.WriteModule(   RGN2_1::mid,   RGN2_1::Delay_Other4     ,           1);
  fModule.WriteModule(   RGN2_1::mid,   RGN2_1::Delay_Other5     ,           1);
                                                                 
  fModule.WriteModule(   RGN2_1::mid,   RGN2_1::Width_Beam       ,           8);
  fModule.WriteModule(   RGN2_1::mid,   RGN2_1::Width_SAC        ,           8);
  fModule.WriteModule(   RGN2_1::mid,   RGN2_1::Width_TOF        ,           8);
  fModule.WriteModule(   RGN2_1::mid,   RGN2_1::Width_LC         ,           8);
  fModule.WriteModule(   RGN2_1::mid,   RGN2_1::Width_TOF_HT     ,           8);
  fModule.WriteModule(   RGN2_1::mid,   RGN2_1::Width_Other4     ,           8);
  fModule.WriteModule(   RGN2_1::mid,   RGN2_1::Width_Other5     ,           8);
                                                                 
  fModule.WriteModule(   RGN2_1::mid,   RGN2_1::Coin_ctrl_7      ,   0b1000011);
  fModule.WriteModule(   RGN2_1::mid,   RGN2_1::Coin_coin_7      ,   0b1000011);
  
  //-------------------------------------------------------------------------
  // RGN2_2 : Region2_2 ( Beam_Pi Coin ) Module
  //-------------------------------------------------------------------------
  fModule.WriteModule(   RGN2_2::mid,   RGN2_2::Delay_Beam       ,           1);
  fModule.WriteModule(   RGN2_2::mid,   RGN2_2::Delay_SAC        ,           1);
  fModule.WriteModule(   RGN2_2::mid,   RGN2_2::Delay_TOF        ,           1);
  fModule.WriteModule(   RGN2_2::mid,   RGN2_2::Delay_LC         ,           1);
  fModule.WriteModule(   RGN2_2::mid,   RGN2_2::Delay_TOF_HT     ,           1);
  fModule.WriteModule(   RGN2_2::mid,   RGN2_2::Delay_Other4     ,           1);
  fModule.WriteModule(   RGN2_2::mid,   RGN2_2::Delay_Other5     ,           1);
                                                                 
  fModule.WriteModule(   RGN2_2::mid,   RGN2_2::Width_Beam       ,           5);
  fModule.WriteModule(   RGN2_2::mid,   RGN2_2::Width_SAC        ,           5);
  fModule.WriteModule(   RGN2_2::mid,   RGN2_2::Width_TOF        ,           5);
  fModule.WriteModule(   RGN2_2::mid,   RGN2_2::Width_LC         ,           5);
  fModule.WriteModule(   RGN2_2::mid,   RGN2_2::Width_TOF_HT     ,           5);
  fModule.WriteModule(   RGN2_2::mid,   RGN2_2::Width_Other4     ,           5);
  fModule.WriteModule(   RGN2_2::mid,   RGN2_2::Width_Other5     ,           5);
                                                                 
  fModule.WriteModule(   RGN2_2::mid,   RGN2_2::Coin_ctrl_7      ,   0b1000011);
  fModule.WriteModule(   RGN2_2::mid,   RGN2_2::Coin_coin_7      ,   0b1000011);
  
  //-------------------------------------------------------------------------
  // RGN2_3 : Region2_3 ( Beam_P Coin ) Module
  //-------------------------------------------------------------------------
  fModule.WriteModule(   RGN2_3::mid,   RGN2_3::Delay_Beam       ,           1);
  fModule.WriteModule(   RGN2_3::mid,   RGN2_3::Delay_SAC        ,           1);
  fModule.WriteModule(   RGN2_3::mid,   RGN2_3::Delay_TOF        ,           1);
  fModule.WriteModule(   RGN2_3::mid,   RGN2_3::Delay_LC         ,           1);
  fModule.WriteModule(   RGN2_3::mid,   RGN2_3::Delay_TOF_HT     ,           1);
  fModule.WriteModule(   RGN2_3::mid,   RGN2_3::Delay_Other4     ,           1);
  fModule.WriteModule(   RGN2_3::mid,   RGN2_3::Delay_Other5     ,           1);
                                                                 
  fModule.WriteModule(   RGN2_3::mid,   RGN2_3::Width_Beam       ,           4);
  fModule.WriteModule(   RGN2_3::mid,   RGN2_3::Width_SAC        ,           4);
  fModule.WriteModule(   RGN2_3::mid,   RGN2_3::Width_TOF        ,           4);
  fModule.WriteModule(   RGN2_3::mid,   RGN2_3::Width_LC         ,           4);
  fModule.WriteModule(   RGN2_3::mid,   RGN2_3::Width_TOF_HT     ,           4);
  fModule.WriteModule(   RGN2_3::mid,   RGN2_3::Width_Other4     ,           4);
  fModule.WriteModule(   RGN2_3::mid,   RGN2_3::Width_Other5     ,           4);
                                                                 
  fModule.WriteModule(   RGN2_3::mid,   RGN2_3::Coin_ctrl_7      ,   0b1000011);
  fModule.WriteModule(   RGN2_3::mid,   RGN2_3::Coin_coin_7      ,   0b1000011);
  
  //-------------------------------------------------------------------------
  // RGN2_4 : Region2_4 ( Coin1 ) Module
  //-------------------------------------------------------------------------
  fModule.WriteModule(   RGN2_4::mid,   RGN2_4::Delay_Beam       ,           1);
  fModule.WriteModule(   RGN2_4::mid,   RGN2_4::Delay_SAC        ,           2);
  fModule.WriteModule(   RGN2_4::mid,   RGN2_4::Delay_TOF        ,           1);
  fModule.WriteModule(   RGN2_4::mid,   RGN2_4::Delay_LC         ,           1);
  fModule.WriteModule(   RGN2_4::mid,   RGN2_4::Delay_TOF_HT     ,           1);
  fModule.WriteModule(   RGN2_4::mid,   RGN2_4::Delay_Other4     ,           1);
  fModule.WriteModule(   RGN2_4::mid,   RGN2_4::Delay_Other5     ,           1);
                                                                 
  fModule.WriteModule(   RGN2_4::mid,   RGN2_4::Width_Beam       ,           8);
  fModule.WriteModule(   RGN2_4::mid,   RGN2_4::Width_SAC        ,           5);
  fModule.WriteModule(   RGN2_4::mid,   RGN2_4::Width_TOF        ,           1);
  fModule.WriteModule(   RGN2_4::mid,   RGN2_4::Width_LC         ,           5);
  fModule.WriteModule(   RGN2_4::mid,   RGN2_4::Width_TOF_HT     ,           5);
  fModule.WriteModule(   RGN2_4::mid,   RGN2_4::Width_Other4     ,           4);
  fModule.WriteModule(   RGN2_4::mid,   RGN2_4::Width_Other5     ,           3);
                                                                 
  fModule.WriteModule(   RGN2_4::mid,   RGN2_4::Coin_ctrl_7      ,   0b1000011);
  fModule.WriteModule(   RGN2_4::mid,   RGN2_4::Coin_coin_7      ,   0b1000011);
  
  //-------------------------------------------------------------------------
  // RGN2_5 : Region2_5 ( Coin2 ) Module
  //-------------------------------------------------------------------------
  fModule.WriteModule(   RGN2_5::mid,   RGN2_5::Delay_Beam       ,           0);
  fModule.WriteModule(   RGN2_5::mid,   RGN2_5::Delay_SAC        ,           0);
  fModule.WriteModule(   RGN2_5::mid,   RGN2_5::Delay_TOF        ,           0);
  fModule.WriteModule(   RGN2_5::mid,   RGN2_5::Delay_LC         ,           0);
  fModule.WriteModule(   RGN2_5::mid,   RGN2_5::Delay_TOF_HT     ,           0);
  fModule.WriteModule(   RGN2_5::mid,   RGN2_5::Delay_Other4     ,           0);
  fModule.WriteModule(   RGN2_5::mid,   RGN2_5::Delay_Other5     ,           0);
                                                                 
  fModule.WriteModule(   RGN2_5::mid,   RGN2_5::Width_Beam       ,           4);
  fModule.WriteModule(   RGN2_5::mid,   RGN2_5::Width_SAC        ,           4);
  fModule.WriteModule(   RGN2_5::mid,   RGN2_5::Width_TOF        ,           4);
  fModule.WriteModule(   RGN2_5::mid,   RGN2_5::Width_LC         ,           4);
  fModule.WriteModule(   RGN2_5::mid,   RGN2_5::Width_TOF_HT     ,           4);
  fModule.WriteModule(   RGN2_5::mid,   RGN2_5::Width_Other4     ,           4);
  fModule.WriteModule(   RGN2_5::mid,   RGN2_5::Width_Other5     ,           4);
                                                                 
  fModule.WriteModule(   RGN2_5::mid,   RGN2_5::Coin_ctrl_7      ,   0b1000011);
  fModule.WriteModule(   RGN2_5::mid,   RGN2_5::Coin_coin_7      ,   0b1000011);
  
  
  //-------------------------------------------------------------------------
  // RGN2_6 : Region2_6 ( For E03 Coin ) Module
  //-------------------------------------------------------------------------
  fModule.WriteModule(   RGN2_6::mid,   RGN2_6::Delay_Beam_E03  ,          1);
  fModule.WriteModule(   RGN2_6::mid,   RGN2_6::Delay_Other1_E03,          1);
  fModule.WriteModule(   RGN2_6::mid,   RGN2_6::Delay_Other2_E03,          2);
  fModule.WriteModule(   RGN2_6::mid,   RGN2_6::Delay_Other3_E03,          2);
  fModule.WriteModule(   RGN2_6::mid,   RGN2_6::Delay_Other4_E03,          2);
  fModule.WriteModule(   RGN2_6::mid,   RGN2_6::Delay_Other5_E03,          2);
                                                                
  fModule.WriteModule(   RGN2_6::mid,   RGN2_6::Width_Beam_E03  ,          2);
  fModule.WriteModule(   RGN2_6::mid,   RGN2_6::Width_Other1_E03,          2);
  fModule.WriteModule(   RGN2_6::mid,   RGN2_6::Width_Other2_E03,          2);
  fModule.WriteModule(   RGN2_6::mid,   RGN2_6::Width_Other3_E03,          2);
  fModule.WriteModule(   RGN2_6::mid,   RGN2_6::Width_Other4_E03,          2);
  fModule.WriteModule(   RGN2_6::mid,   RGN2_6::Width_Other5_E03,          2);
                                                                
  fModule.WriteModule(   RGN2_6::mid,   RGN2_6::Coin_ctrl_6      ,   0b100011);
  fModule.WriteModule(   RGN2_6::mid,   RGN2_6::Coin_coin_6      ,   0b100011);

  //-------------------------------------------------------------------------
  // RGN3 : Region3 ( Else Or )Module
  //-------------------------------------------------------------------------
  fModule.WriteModule(   RGN3::mid,  RGN3::PreScale_Beam    ,               0);
  fModule.WriteModule(   RGN3::mid,  RGN3::PreScale_Beam_TOF,               1);
  fModule.WriteModule(   RGN3::mid,  RGN3::PreScale_Beam_Pi ,               2);
  fModule.WriteModule(   RGN3::mid,  RGN3::PreScale_Beam_P  ,               3);
  fModule.WriteModule(   RGN3::mid,  RGN3::PreScale_Coin1   ,               4);
  fModule.WriteModule(   RGN3::mid,  RGN3::PreScale_Coin2   ,               5);
  fModule.WriteModule(   RGN3::mid,  RGN3::PreScale_For_E03 ,         499999 );
                                                            
  fModule.WriteModule(   RGN3::mid,  RGN3::Delay_PS_OR      ,               1);
                                                            
  fModule.WriteModule(   RGN3::mid,  RGN3::Delay_Else_OR    ,               1);
  fModule.WriteModule(   RGN3::mid,  RGN3::Width_Else_OR    ,               1);
                                                            
  fModule.WriteModule(   RGN3::mid,  RGN3::Delay_K_Scat     ,               6);
  fModule.WriteModule(   RGN3::mid,  RGN3::Width_K_Scat     ,               5);
                                                            
  fModule.WriteModule(   RGN3::mid,  RGN3::Selector_PS      ,       0b0100000);

  //-------------------------------------------------------------------------
  // RGN4 : Region4 ( BH2_K )Module
  //-------------------------------------------------------------------------
  fModule.WriteModule(   RGN4::mid,  RGN4::Delay_BH2         ,              6);
  fModule.WriteModule(   RGN4::mid,  RGN4::Delay_BH2_K       ,              1);
  fModule.WriteModule(   RGN4::mid,  RGN4::Width_BH2_K       ,              4);
  fModule.WriteModule(   RGN4::mid,  RGN4::Selector_8        ,     0b11111111);
  fModule.WriteModule(   RGN4::mid,  RGN4::Selector_Clock    ,              1);
  fModule.WriteModule(   RGN4::mid,  RGN4::Selector_Reserve2 ,              1);

  //-------------------------------------------------------------------------
  // IOM : In/Out Maneger ( NIMOUT Signal Select ) Module
  //-------------------------------------------------------------------------
  fModule.WriteModule(   IOM::mid,  IOM::NIMOUT1  ,          0b100000);
  fModule.WriteModule(   IOM::mid,  IOM::NIMOUT2  ,          0b011111);
  fModule.WriteModule(   IOM::mid,  IOM::NIMOUT3  ,          0b001110);
  fModule.WriteModule(   IOM::mid,  IOM::NIMOUT4  ,          0b100101);






////////////////////////////////////////////////////////////////////////////////////////////////
//           Read                                                                             // 
//         Read                                                                               // 
//       Read                                                                                 // 
////////////////////////////////////////////////////////////////////////////////////////////////

  fModule.ReadModule(   RGN1::mid,   RGN1::Delay_BH1_Pi,    1);
  fModule.ReadModule(   RGN1::mid,   RGN1::Delay_BH2_Pi,    1);
  fModule.ReadModule(   RGN1::mid,   RGN1::Delay_BH1_P ,    1);
  fModule.ReadModule(   RGN1::mid,   RGN1::Delay_BH2_P ,    1);
                                                       
  fModule.ReadModule(   RGN1::mid,   RGN1::Width_BH1_Pi,    1);
  fModule.ReadModule(   RGN1::mid,   RGN1::Width_BH2_Pi,    1);
  fModule.ReadModule(   RGN1::mid,   RGN1::Width_BH1_P ,    1);
  fModule.ReadModule(   RGN1::mid,   RGN1::Width_BH2_P ,    1);

  std::cout <<  fModule.ReadModule(   RGN1::mid,   RGN1::Delay_BH1_Pi,    1) << std::endl;
  std::cout <<  fModule.ReadModule(   RGN1::mid,   RGN1::Delay_BH2_Pi,    1) << std::endl;
  std::cout <<  fModule.ReadModule(   RGN1::mid,   RGN1::Delay_BH1_P ,    1) << std::endl;
  std::cout <<  fModule.ReadModule(   RGN1::mid,   RGN1::Delay_BH2_P ,    1) << std::endl;
                                                                     
  std::cout <<  fModule.ReadModule(   RGN1::mid,   RGN1::Width_BH1_Pi,    1) << std::endl;
  std::cout <<  fModule.ReadModule(   RGN1::mid,   RGN1::Width_BH2_Pi,    1) << std::endl;
  std::cout <<  fModule.ReadModule(   RGN1::mid,   RGN1::Width_BH1_P ,    1) << std::endl;
  std::cout <<  fModule.ReadModule(   RGN1::mid,   RGN1::Width_BH2_P ,    1) << std::endl;

  return 0;

}// main
