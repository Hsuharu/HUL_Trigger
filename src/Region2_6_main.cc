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
  char fixedip[] = "192.168.11.11";
  board_ip = fixedip;
  rbcp_header rbcpHeader;
  rbcpHeader.type = UDPRBCP::rbcp_ver_;
  rbcpHeader.id   = 0;

  FPGAModule fModule(board_ip, udp_port, &rbcpHeader, 0);
  //  std::cout << std::hex << fModule.ReadModule(BCT::mid, BCT::laddr_Version, 4) << std::endl;
  int Beam, Other1, Other2, Other3, Other4, Other5; 
  CoinModule Region2_6_Coin;

// *****  KScattering *****
    Beam   = CoinAnd   ; 
    Other1 = CoinAnd   ;
    Other2 = CoinAnd   ;
    Other3 = CoinAnd   ;
    Other4 = CoinAnd   ;
    Other5 = CoinAnd   ; 


////////////////////////////////////////////////////////////////////////////////////////////////
//           Write                                                                            // 
//         Write                                                                              // 
//       Write                                                                                // 
////////////////////////////////////////////////////////////////////////////////////////////////

  
  
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
                                                                
//  fModule.WriteModule(   RGN2_6::mid,   RGN2_6::Coin_ctrl_6      ,   0b100011);
//  fModule.WriteModule(   RGN2_6::mid,   RGN2_6::Coin_coin_6      ,   0b100011);

  fModule.WriteModule(   RGN2_6::mid,   RGN2_6::Coin_ctrl_6      ,   Region2_6_Coin.Coin6(Beam, Other1, Other2, Other3, Other4, Other5));
  fModule.WriteModule(   RGN2_6::mid,   RGN2_6::Coin_coin_6      ,   Region2_6_Coin.Ctrl6(Beam, Other1, Other2, Other3, Other4, Other5));



////////////////////////////////////////////////////////////////////////////////////////////////
//           Read                                                                             // 
//         Read                                                                               // 
//       Read                                                                                 // 
////////////////////////////////////////////////////////////////////////////////////////////////

//  fModule.ReadModule(   RGN1::mid,   RGN1::Delay_BH1_Pi,    1);
//  fModule.ReadModule(   RGN1::mid,   RGN1::Delay_BH2_Pi,    1);
//  fModule.ReadModule(   RGN1::mid,   RGN1::Delay_BH1_P ,    1);
//  fModule.ReadModule(   RGN1::mid,   RGN1::Delay_BH2_P ,    1);
//                                                       
//  fModule.ReadModule(   RGN1::mid,   RGN1::Width_BH1_Pi,    1);
//  fModule.ReadModule(   RGN1::mid,   RGN1::Width_BH2_Pi,    1);
//  fModule.ReadModule(   RGN1::mid,   RGN1::Width_BH1_P ,    1);
//  fModule.ReadModule(   RGN1::mid,   RGN1::Width_BH2_P ,    1);
//
//  std::cout <<  fModule.ReadModule(   RGN1::mid,   RGN1::Delay_BH1_Pi,    1) << std::endl;
//  std::cout <<  fModule.ReadModule(   RGN1::mid,   RGN1::Delay_BH2_Pi,    1) << std::endl;
//  std::cout <<  fModule.ReadModule(   RGN1::mid,   RGN1::Delay_BH1_P ,    1) << std::endl;
//  std::cout <<  fModule.ReadModule(   RGN1::mid,   RGN1::Delay_BH2_P ,    1) << std::endl;
//                                                                     
//  std::cout <<  fModule.ReadModule(   RGN1::mid,   RGN1::Width_BH1_Pi,    1) << std::endl;
//  std::cout <<  fModule.ReadModule(   RGN1::mid,   RGN1::Width_BH2_Pi,    1) << std::endl;
//  std::cout <<  fModule.ReadModule(   RGN1::mid,   RGN1::Width_BH1_P ,    1) << std::endl;
//  std::cout <<  fModule.ReadModule(   RGN1::mid,   RGN1::Width_BH2_P ,    1) << std::endl;

  return 0;

}// main
