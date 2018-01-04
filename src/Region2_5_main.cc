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
  int Beam, SAC_or, TOF_or, LC_or, TOF_HT, Other4, Other5; 
  CoinModule Region2_5_Coin;

// *****  KScattering *****
    Beam   = CoinAnd   ; 
    SAC_or = CoinAnd   ;
    TOF_or = CoinAnd   ;
    LC_or  = CoinAnd   ;
    TOF_HT = CoinAnd   ;
    Other4 = CoinAnd   ;
    Other5 = CoinAnd   ; 


////////////////////////////////////////////////////////////////////////////////////////////////
//           Write                                                                            // 
//         Write                                                                              // 
//       Write                                                                                // 
////////////////////////////////////////////////////////////////////////////////////////////////

  
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
                                                                 
//  fModule.WriteModule(   RGN2_5::mid,   RGN2_5::Coin_ctrl_7      ,   0b1000011);
//  fModule.WriteModule(   RGN2_5::mid,   RGN2_5::Coin_coin_7      ,   0b1000011);
  
  fModule.WriteModule(   RGN2_5::mid,   RGN2_5::Coin_ctrl_7      ,   Region2_5_Coin.Coin7(Beam, SAC_or, TOF_or, LC_or, TOF_HT, Other4, Other5));
  fModule.WriteModule(   RGN2_5::mid,   RGN2_5::Coin_coin_7      ,   Region2_5_Coin.Ctrl7(Beam, SAC_or, TOF_or, LC_or, TOF_HT, Other4, Other5));
  


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
