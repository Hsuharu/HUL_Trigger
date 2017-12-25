#include <iostream>
#include <cstdio>

#include "RegisterMap.hh"
#include "network.hh"
#include "UDPRBCP.hh"
#include "CommandMan.hh"
#include "FPGAModule.hh"
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
  // LED ---------------------------------------------------------------------------------------- 
  fModule.WriteModule(LED::mid, LED::laddr_led, 1);

  // RGN1 --------------------------------------------------------------------------------------- 
                                       //-- Beam --  
  fModule.WriteModule( RGN1::mid,   RGN1::DLY_BH1_Pi_sel       ,    1);
  fModule.WriteModule( RGN1::mid,   RGN1::DLY_BH2_Pi_sel       ,    1);
  fModule.WriteModule( RGN1::mid,   RGN1::DLY_BH1_P_sel        ,    2);
  fModule.WriteModule( RGN1::mid,   RGN1::DLY_BH2_P_sel        ,    1);
                                          //-- K_Scat --
  fModule.WriteModule( RGN1::mid,   RGN1::DLY_SAC_K_Scat_sel   ,    1);
  fModule.WriteModule( RGN1::mid,   RGN1::DLY_TOF_K_Scat_sel   ,    1);
  fModule.WriteModule( RGN1::mid,   RGN1::DLY_Lucite_K_Scat_sel,    1);
  fModule.WriteModule( RGN1::mid,   RGN1::DLY_TOF_HT_K_Scat_sel,    1);
                                          //-- Other --
  fModule.WriteModule( RGN1::mid,   RGN1::DLY_Other4_Scat      ,    1);
  fModule.WriteModule( RGN1::mid,   RGN1::DLY_Other5_Scat      ,    1);
                                          //-- K_Scat_Pre --
  fModule.WriteModule( RGN1::mid,   RGN1::DLY_K_Scat_Pre_sel   ,    1);
                                          //-- Beam --
  fModule.WriteModule( RGN1::mid,   RGN1::PWM_BH1_Pi_sel       ,    4);
  fModule.WriteModule( RGN1::mid,   RGN1::PWM_BH2_Pi_sel       ,    4);
  fModule.WriteModule( RGN1::mid,   RGN1::PWM_BH1_P_sel        ,    8);
  fModule.WriteModule( RGN1::mid,   RGN1::PWM_BH2_P_sel        ,    4);
                                          //-- K_Scat --       
  fModule.WriteModule( RGN1::mid,   RGN1::PWM_SAC_K_Scat_sel   ,    12);
  fModule.WriteModule( RGN1::mid,   RGN1::PWM_TOF_K_Scat_sel   ,    12);
  fModule.WriteModule( RGN1::mid,   RGN1::PWM_Lucite_K_Scat_sel,    12);
  fModule.WriteModule( RGN1::mid,   RGN1::PWM_TOF_HT_K_Scat_sel,    12);
                                          //-- Other --
  fModule.WriteModule( RGN1::mid,   RGN1::PWM_Other4_Scat      ,    8);
  fModule.WriteModule( RGN1::mid,   RGN1::PWM_Other5_Scat      ,    8);
                                          //-- K_Scat_Pre --
  fModule.WriteModule( RGN1::mid,   RGN1::PWM_K_Scat_Pre_sel   ,    4);
                                          
                                          //-- BPS -------
  fModule.WriteModule( RGN1::mid,   RGN1::BPS_ctrl_K_Scat      ,  0b000011);
  fModule.WriteModule( RGN1::mid,   RGN1::BPS_coin_K_Scat      ,  0b000011);
//  fModule.WriteModule( RGN1::mid,   RGN1::BPS_ctrl_K_Scat      ,  0b111100);
//  fModule.WriteModule( RGN1::mid,   RGN1::BPS_coin_K_Scat      ,  0b111100);
  
  
  // RGN2_1 --- Beam_TOF ------------------------------------------------------------------------ 
  fModule.WriteModule( RGN2_1::mid,   RGN2_1::DLY_BH2_Pi   ,     1);
  fModule.WriteModule( RGN2_1::mid,   RGN2_1::DLY_SAC_or   ,     1);
  fModule.WriteModule( RGN2_1::mid,   RGN2_1::DLY_TOF_or   ,     1);
  fModule.WriteModule( RGN2_1::mid,   RGN2_1::DLY_LC_or    ,     1);
  fModule.WriteModule( RGN2_1::mid,   RGN2_1::DLY_TOF_HT   ,     1);
  fModule.WriteModule( RGN2_1::mid,   RGN2_1::DLY_Other4   ,     1);
  fModule.WriteModule( RGN2_1::mid,   RGN2_1::DLY_Other5   ,     1);
                                                           
  fModule.WriteModule( RGN2_1::mid,   RGN2_1::PWM_BH2_Pi   ,     8);
  fModule.WriteModule( RGN2_1::mid,   RGN2_1::PWM_SAC_or   ,     8);
  fModule.WriteModule( RGN2_1::mid,   RGN2_1::PWM_TOF_or   ,     8);
  fModule.WriteModule( RGN2_1::mid,   RGN2_1::PWM_LC_or    ,     8);
  fModule.WriteModule( RGN2_1::mid,   RGN2_1::PWM_TOF_HT   ,     8);
  fModule.WriteModule( RGN2_1::mid,   RGN2_1::PWM_Other4   ,     8);
  fModule.WriteModule( RGN2_1::mid,   RGN2_1::PWM_Other5   ,     8);
                                                           
  fModule.WriteModule( RGN2_1::mid,   RGN2_1::BPS_ctrl_7   ,   0b1000011);
  fModule.WriteModule( RGN2_1::mid,   RGN2_1::BPS_coin_7   ,   0b1000011);
  
  // RGN2_2 ------------------------------------------------------------------------------------- 
  fModule.WriteModule( RGN2_2::mid,   RGN2_2::DLY_BH2_Pi   ,     1);
  fModule.WriteModule( RGN2_2::mid,   RGN2_2::DLY_SAC_or   ,     1);
  fModule.WriteModule( RGN2_2::mid,   RGN2_2::DLY_TOF_or   ,     1);
  fModule.WriteModule( RGN2_2::mid,   RGN2_2::DLY_LC_or    ,     1);
  fModule.WriteModule( RGN2_2::mid,   RGN2_2::DLY_TOF_HT   ,     1);
  fModule.WriteModule( RGN2_2::mid,   RGN2_2::DLY_Other4   ,     1);
  fModule.WriteModule( RGN2_2::mid,   RGN2_2::DLY_Other5   ,     1);
                                                           
  fModule.WriteModule( RGN2_2::mid,   RGN2_2::PWM_BH2_Pi   ,     5);
  fModule.WriteModule( RGN2_2::mid,   RGN2_2::PWM_SAC_or   ,     5);
  fModule.WriteModule( RGN2_2::mid,   RGN2_2::PWM_TOF_or   ,     5);
  fModule.WriteModule( RGN2_2::mid,   RGN2_2::PWM_LC_or    ,     5);
  fModule.WriteModule( RGN2_2::mid,   RGN2_2::PWM_TOF_HT   ,     5);
  fModule.WriteModule( RGN2_2::mid,   RGN2_2::PWM_Other4   ,     5);
  fModule.WriteModule( RGN2_2::mid,   RGN2_2::PWM_Other5   ,     5);
                                                           
  fModule.WriteModule( RGN2_2::mid,   RGN2_2::BPS_ctrl_7   ,   0b1000011);
  fModule.WriteModule( RGN2_2::mid,   RGN2_2::BPS_coin_7   ,   0b1000011);
  
  // RGN2_3 ------------------------------------------------------------------------------------- 
  fModule.WriteModule( RGN2_3::mid,   RGN2_3::DLY_BH2_Pi   ,     1);
  fModule.WriteModule( RGN2_3::mid,   RGN2_3::DLY_SAC_or   ,     1);
  fModule.WriteModule( RGN2_3::mid,   RGN2_3::DLY_TOF_or   ,     1);
  fModule.WriteModule( RGN2_3::mid,   RGN2_3::DLY_LC_or    ,     1);
  fModule.WriteModule( RGN2_3::mid,   RGN2_3::DLY_TOF_HT   ,     1);
  fModule.WriteModule( RGN2_3::mid,   RGN2_3::DLY_Other4   ,     1);
  fModule.WriteModule( RGN2_3::mid,   RGN2_3::DLY_Other5   ,     1);
                                                           
  fModule.WriteModule( RGN2_3::mid,   RGN2_3::PWM_BH2_Pi   ,     4);
  fModule.WriteModule( RGN2_3::mid,   RGN2_3::PWM_SAC_or   ,     4);
  fModule.WriteModule( RGN2_3::mid,   RGN2_3::PWM_TOF_or   ,     4);
  fModule.WriteModule( RGN2_3::mid,   RGN2_3::PWM_LC_or    ,     4);
  fModule.WriteModule( RGN2_3::mid,   RGN2_3::PWM_TOF_HT   ,     4);
  fModule.WriteModule( RGN2_3::mid,   RGN2_3::PWM_Other4   ,     4);
  fModule.WriteModule( RGN2_3::mid,   RGN2_3::PWM_Other5   ,     4);
                                                           
  fModule.WriteModule( RGN2_3::mid,   RGN2_3::BPS_ctrl_7   ,   0b1000011);
  fModule.WriteModule( RGN2_3::mid,   RGN2_3::BPS_coin_7   ,   0b1000011);
  
  // RGN2_4 --- Coin1 --------------------------------------------------------------------------- 
  fModule.WriteModule( RGN2_4::mid,   RGN2_4::DLY_BH2_Pi   ,     1);
  fModule.WriteModule( RGN2_4::mid,   RGN2_4::DLY_SAC_or   ,     2);
  fModule.WriteModule( RGN2_4::mid,   RGN2_4::DLY_TOF_or   ,     1);
  fModule.WriteModule( RGN2_4::mid,   RGN2_4::DLY_LC_or    ,     1);
  fModule.WriteModule( RGN2_4::mid,   RGN2_4::DLY_TOF_HT   ,     1);
  fModule.WriteModule( RGN2_4::mid,   RGN2_4::DLY_Other4   ,     1);
  fModule.WriteModule( RGN2_4::mid,   RGN2_4::DLY_Other5   ,     1);
                                                           
  fModule.WriteModule( RGN2_4::mid,   RGN2_4::PWM_BH2_Pi   ,     8);
  fModule.WriteModule( RGN2_4::mid,   RGN2_4::PWM_SAC_or   ,     5);
  fModule.WriteModule( RGN2_4::mid,   RGN2_4::PWM_TOF_or   ,     1);
  fModule.WriteModule( RGN2_4::mid,   RGN2_4::PWM_LC_or    ,     5);
  fModule.WriteModule( RGN2_4::mid,   RGN2_4::PWM_TOF_HT   ,     5);
  fModule.WriteModule( RGN2_4::mid,   RGN2_4::PWM_Other4   ,     4);
  fModule.WriteModule( RGN2_4::mid,   RGN2_4::PWM_Other5   ,     3);
                                                           
  fModule.WriteModule( RGN2_4::mid,   RGN2_4::BPS_ctrl_7   ,   0b1000011);
  fModule.WriteModule( RGN2_4::mid,   RGN2_4::BPS_coin_7   ,   0b1000011);
  
  // RGN2_5 ------------------------------------------------------------------------------------- 
  fModule.WriteModule( RGN2_5::mid,   RGN2_5::DLY_BH2_Pi   ,     0);
  fModule.WriteModule( RGN2_5::mid,   RGN2_5::DLY_SAC_or   ,     0);
  fModule.WriteModule( RGN2_5::mid,   RGN2_5::DLY_TOF_or   ,     0);
  fModule.WriteModule( RGN2_5::mid,   RGN2_5::DLY_LC_or    ,     0);
  fModule.WriteModule( RGN2_5::mid,   RGN2_5::DLY_TOF_HT   ,     0);
  fModule.WriteModule( RGN2_5::mid,   RGN2_5::DLY_Other4   ,     0);
  fModule.WriteModule( RGN2_5::mid,   RGN2_5::DLY_Other5   ,     0);
                                                           
  fModule.WriteModule( RGN2_5::mid,   RGN2_5::PWM_BH2_Pi   ,     4);
  fModule.WriteModule( RGN2_5::mid,   RGN2_5::PWM_SAC_or   ,     4);
  fModule.WriteModule( RGN2_5::mid,   RGN2_5::PWM_TOF_or   ,     4);
  fModule.WriteModule( RGN2_5::mid,   RGN2_5::PWM_LC_or    ,     4);
  fModule.WriteModule( RGN2_5::mid,   RGN2_5::PWM_TOF_HT   ,     4);
  fModule.WriteModule( RGN2_5::mid,   RGN2_5::PWM_Other4   ,     4);
  fModule.WriteModule( RGN2_5::mid,   RGN2_5::PWM_Other5   ,     4);
                                                           
  fModule.WriteModule( RGN2_5::mid,   RGN2_5::BPS_ctrl_7   ,   0b1000011);
  fModule.WriteModule( RGN2_5::mid,   RGN2_5::BPS_coin_7   ,   0b1000011);
  
  
  // RGN2_6 ------------------------------------------------------------------------------------- 
  fModule.WriteModule( RGN2_6::mid,  RGN2_6::DLY_BH2_Pi_E03,    1);
  fModule.WriteModule( RGN2_6::mid,  RGN2_6::DLY_Other1_E03,    1);
  fModule.WriteModule( RGN2_6::mid,  RGN2_6::DLY_Other2_E03,    2);
  fModule.WriteModule( RGN2_6::mid,  RGN2_6::DLY_Other3_E03,    2);
  fModule.WriteModule( RGN2_6::mid,  RGN2_6::DLY_Other4_E03,    2);
  fModule.WriteModule( RGN2_6::mid,  RGN2_6::DLY_Other5_E03,    2);
                                                           
  fModule.WriteModule( RGN2_6::mid,  RGN2_6::PWM_BH2_Pi_E03,    2);
  fModule.WriteModule( RGN2_6::mid,  RGN2_6::PWM_Other1_E03,    2);
  fModule.WriteModule( RGN2_6::mid,  RGN2_6::PWM_Other2_E03,    2);
  fModule.WriteModule( RGN2_6::mid,  RGN2_6::PWM_Other3_E03,    2);
  fModule.WriteModule( RGN2_6::mid,  RGN2_6::PWM_Other4_E03,    2);
  fModule.WriteModule( RGN2_6::mid,  RGN2_6::PWM_Other5_E03,    2);
                                                           
  fModule.WriteModule( RGN2_6::mid,  RGN2_6::BPS_ctrl_6    ,   0b100011);
  fModule.WriteModule( RGN2_6::mid,  RGN2_6::BPS_coin_6    ,   0b100011);

  // RGN3 --------------------------------------------------------------------------------------- 
  fModule.WriteModule( RGN3::mid,  RGN3::PS_BH2_Pi           ,    0);
  fModule.WriteModule( RGN3::mid,  RGN3::PS_Beam_TOF         ,    1);
  fModule.WriteModule( RGN3::mid,  RGN3::PS_Beam_Pi          ,    2);
  fModule.WriteModule( RGN3::mid,  RGN3::PS_Beam_P           ,    3);
  fModule.WriteModule( RGN3::mid,  RGN3::PS_Coin1            ,    4);
  fModule.WriteModule( RGN3::mid,  RGN3::PS_Coin2            ,    5);
  fModule.WriteModule( RGN3::mid,  RGN3::PS_For_E03          ,   499999 );
                                                           
//  fModule.WriteModule( RGN3::mid,  RGN3::PWM_BH2_Pi          ,    4);
//  fModule.WriteModule( RGN3::mid,  RGN3::PWM_Beam_TOF        ,    4);
//  fModule.WriteModule( RGN3::mid,  RGN3::PWM_Beam_Pi         ,    4);
//  fModule.WriteModule( RGN3::mid,  RGN3::PWM_Beam_P          ,    4);
//  fModule.WriteModule( RGN3::mid,  RGN3::PWM_Coin1           ,    4);
//  fModule.WriteModule( RGN3::mid,  RGN3::PWM_Coin2           ,    4);
//  fModule.WriteModule( RGN3::mid,  RGN3::PWM_For_E03         ,    4);
                                                           
  fModule.WriteModule( RGN3::mid,  RGN3::DLY_PS_OR           ,    1);
                                                           
  fModule.WriteModule( RGN3::mid,  RGN3::DPWM_delay_Else_OR  ,    1);
  fModule.WriteModule( RGN3::mid,  RGN3::DPWM_delay_K_Scat   ,    1);
  fModule.WriteModule( RGN3::mid,  RGN3::DPWM_counter_Else_OR,    6);
  fModule.WriteModule( RGN3::mid,  RGN3::DPWM_counter_K_Scat ,    5);
                                                           
  fModule.WriteModule( RGN3::mid,  RGN3::SEL_ctrl_7          ,  0b0100000);

  // RGN4 --------------------------------------------------------------------------------------- 
  fModule.WriteModule( RGN4::mid,  RGN4::DLY_BH2           ,    6);
  fModule.WriteModule( RGN4::mid,  RGN4::DPWM_delay_BH2_K  ,    1);
  fModule.WriteModule( RGN4::mid,  RGN4::DPWM_counter_BH2_K,    4);
  fModule.WriteModule( RGN4::mid,  RGN4::SEL_8             ,  0b11111111);
  fModule.WriteModule( RGN4::mid,  RGN4::SEL_clk           ,    1);
  fModule.WriteModule( RGN4::mid,  RGN4::SEL_rsv2          ,    1);

  // IOM ---------------------------------------------------------------------------------------- 
  fModule.WriteModule( IOM::mid, IOM::IOM_nim1  , 0b100000);
  fModule.WriteModule( IOM::mid, IOM::IOM_nim2  , 0b011111);

  fModule.WriteModule( IOM::mid, IOM::IOM_nim3  , 0b001110);
  fModule.WriteModule( IOM::mid, IOM::IOM_nim4  , 0b100101);



////////////////////////////////////////////////////////////////////////////////////////////////
//         Read                                                                               // 
////////////////////////////////////////////////////////////////////////////////////////////////
  fModule.ReadModule( RGN1::mid,   RGN1::DLY_SAC_K_Scat_sel   ,    1);
  fModule.ReadModule( RGN1::mid,   RGN1::DLY_TOF_K_Scat_sel   ,    1);
  fModule.ReadModule( RGN1::mid,   RGN1::DLY_Lucite_K_Scat_sel,    1);
  fModule.ReadModule( RGN1::mid,   RGN1::DLY_TOF_HT_K_Scat_sel,    1);
  fModule.ReadModule( RGN1::mid,   RGN1::PWM_SAC_K_Scat_sel   ,    1);
  fModule.ReadModule( RGN1::mid,   RGN1::PWM_TOF_K_Scat_sel   ,    1);
  fModule.ReadModule( RGN1::mid,   RGN1::PWM_Lucite_K_Scat_sel,    1);
  fModule.ReadModule( RGN1::mid,   RGN1::PWM_TOF_HT_K_Scat_sel,    1);

  std::cout <<  fModule.ReadModule( RGN1::mid,   RGN1::DLY_SAC_K_Scat_sel   ,    1) << std::endl;
  std::cout <<  fModule.ReadModule( RGN1::mid,   RGN1::DLY_TOF_K_Scat_sel   ,    1) << std::endl;
  std::cout <<  fModule.ReadModule( RGN1::mid,   RGN1::DLY_Lucite_K_Scat_sel,    1) << std::endl;
  std::cout <<  fModule.ReadModule( RGN1::mid,   RGN1::DLY_TOF_HT_K_Scat_sel,    1) << std::endl;

  std::cout <<  fModule.ReadModule( RGN1::mid,   RGN1::PWM_SAC_K_Scat_sel   ,    1) << std::endl;
  std::cout <<  fModule.ReadModule( RGN1::mid,   RGN1::PWM_TOF_K_Scat_sel   ,    1) << std::endl;
  std::cout <<  fModule.ReadModule( RGN1::mid,   RGN1::PWM_Lucite_K_Scat_sel,    1) << std::endl;
  std::cout <<  fModule.ReadModule( RGN1::mid,   RGN1::PWM_TOF_HT_K_Scat_sel,    1) << std::endl;

  return 0;

}// main
