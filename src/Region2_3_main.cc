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

  int Beam, SAC_or, TOF_or, LC_or, TOF_HT, Other4, Other5; 
  CoinModule Region2_3_Coin;

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
                                                                 
//  fModule.WriteModule(   RGN2_3::mid,   RGN2_3::Coin_ctrl_7      ,   0b1000011);
//  fModule.WriteModule(   RGN2_3::mid,   RGN2_3::Coin_coin_7      ,   0b1000011);
  
  fModule.WriteModule(   RGN2_3::mid,   RGN2_3::Coin_ctrl_7      ,   Region2_3_Coin.Coin7(Beam, SAC_or, TOF_or, LC_or, TOF_HT, Other4, Other5));
  fModule.WriteModule(   RGN2_3::mid,   RGN2_3::Coin_coin_7      ,   Region2_3_Coin.Ctrl7(Beam, SAC_or, TOF_or, LC_or, TOF_HT, Other4, Other5));


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
