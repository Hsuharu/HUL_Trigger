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
  int BH1_or, BH2_or;
  int SAC_or, TOF_or, LC_or, TOF_HT, Other4, Other5; 
  CoinModule Region1_Coin;


//Coin -------------------------------------------------------
// *****  Beam  *****
    BH1_or = CoinAnd   ;       
    BH2_or = CoinAnd   ; 
// *****  KScattering *****
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
  // RGN1 : Region1 Module
  //-------------------------------------------------------------------------
      //-- Pi,P Beam --
  fModule.WriteModule(   RGN1::mid,   RGN1::Delay_BH1_Beam      ,          0); // 1~15  
  fModule.WriteModule(   RGN1::mid,   RGN1::Delay_BH2_Beam      ,          0); // 1~15
  fModule.WriteModule(   RGN1::mid,   RGN1::Delay_BH1_Pi        ,          0); // 1~15
  fModule.WriteModule(   RGN1::mid,   RGN1::Delay_BH2_Pi        ,          0); // 1~15
  fModule.WriteModule(   RGN1::mid,   RGN1::Delay_BH1_P         ,          0); // 1~15
  fModule.WriteModule(   RGN1::mid,   RGN1::Delay_BH2_P         ,          0); // 1~15

  fModule.WriteModule(   RGN1::mid,   RGN1::Width_BH1_Beam      ,          4); // 1~15
  fModule.WriteModule(   RGN1::mid,   RGN1::Width_BH2_Beam      ,          4); // 1~15
  fModule.WriteModule(   RGN1::mid,   RGN1::Width_BH1_Pi        ,          4); // 1~15
  fModule.WriteModule(   RGN1::mid,   RGN1::Width_BH2_Pi        ,          4); // 1~15
  fModule.WriteModule(   RGN1::mid,   RGN1::Width_BH1_P         ,          8); // 1~15
  fModule.WriteModule(   RGN1::mid,   RGN1::Width_BH2_P         ,          4); // 1~15
                                                              
      //-- K_Scat Coin--                 
  fModule.WriteModule(   RGN1::mid,   RGN1::Delay_SAC_K_Scat    ,          1); // 1~15
  fModule.WriteModule(   RGN1::mid,   RGN1::Delay_TOF_K_Scat    ,          1); // 1~15
  fModule.WriteModule(   RGN1::mid,   RGN1::Delay_LC_K_Scat     ,          1); // 1~15
  fModule.WriteModule(   RGN1::mid,   RGN1::Delay_TOF_HT_K_Scat ,          1); // 1~15
  fModule.WriteModule(   RGN1::mid,   RGN1::Delay_Other4_K_Scat ,          1); // 1~15
  fModule.WriteModule(   RGN1::mid,   RGN1::Delay_Other5_K_Scat ,          1); // 1~15

  fModule.WriteModule(   RGN1::mid,   RGN1::Width_SAC_K_Scat    ,         12); // 1~15
  fModule.WriteModule(   RGN1::mid,   RGN1::Width_TOF_K_Scat    ,         12); // 1~15
  fModule.WriteModule(   RGN1::mid,   RGN1::Width_Lucite_K_Scat ,         12); // 1~15
  fModule.WriteModule(   RGN1::mid,   RGN1::Width_TOF_HT_K_Scat ,         12); // 1~15
  fModule.WriteModule(   RGN1::mid,   RGN1::Width_Other4_K_Scat ,          8); // 1~15
  fModule.WriteModule(   RGN1::mid,   RGN1::Width_Other5_K_Scat ,          8); // 1~15
                                                              
      //-- K_Scat --                    
  fModule.WriteModule(   RGN1::mid,   RGN1::Delay_K_Scat        ,          1); // 1~15
  fModule.WriteModule(   RGN1::mid,   RGN1::Width_K_Scat        ,          4); // 1~15
                                                              
      //-- Coincidence -------         
//  fModule.WriteModule(   RGN1::mid,   RGN1::Coin_ctrl_Beam      ,   0b11);
//  fModule.WriteModule(   RGN1::mid,   RGN1::Coin_coin_Beam      ,   0b11);
//  fModule.WriteModule(   RGN1::mid,   RGN1::Coin_ctrl_K_Scat    ,   0b000011);
//  fModule.WriteModule(   RGN1::mid,   RGN1::Coin_coin_K_Scat    ,   0b000011);

  fModule.WriteModule(   RGN1::mid,   RGN1::Coin_ctrl_Beam      ,  Region1_Coin.BeamCoin(BH1_or, BH2_or) );
  fModule.WriteModule(   RGN1::mid,   RGN1::Coin_coin_Beam      ,  Region1_Coin.BeamCtrl(BH1_or, BH2_or) );
  fModule.WriteModule(   RGN1::mid,   RGN1::Coin_ctrl_K_Scat    ,  Region1_Coin.KScatCoin(SAC_or, TOF_or, LC_or, TOF_HT, Other4, Other5) );
  fModule.WriteModule(   RGN1::mid,   RGN1::Coin_coin_K_Scat    ,  Region1_Coin.KScatCtrl(SAC_or, TOF_or, LC_or, TOF_HT, Other4, Other5) );


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
