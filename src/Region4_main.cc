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
  int BH2_K_Selector;
  char* board_ip                  ;
//  char fixedip[] = "192.168.11.11";
  char fixedip[] = "192.168.10.65";
  board_ip = fixedip;
  rbcp_header rbcpHeader;
  rbcpHeader.type = UDPRBCP::rbcp_ver_;
  rbcpHeader.id   = 0;

  FPGAModule fModule(board_ip, udp_port, &rbcpHeader, 0);
  //  std::cout << std::hex << fModule.ReadModule(BCT::mid, BCT::laddr_Version, 4) << std::endl;

/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//    BH2_K Selector       Please write SegN or Off behind BH2_KSel::          //
//                          SegN  -> N is Segment Number                       //
//                          Off -> Not Use                                     //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

  BH2_K_Selector = BH2_K_Sel::Seg1
                  |BH2_K_Sel::Seg2
                  |BH2_K_Sel::Seg3
                  |BH2_K_Sel::Seg4
                  |BH2_K_Sel::Seg5
                  |BH2_K_Sel::Seg6
                  |BH2_K_Sel::Seg7
                  |BH2_K_Sel::Seg8 ;

////////////////////////////////////////////////////////////////////////////////////////////////
//           Write                                                                            // 
//         Write                                                                              // 
//       Write                                                                                // 
////////////////////////////////////////////////////////////////////////////////////////////////


  //-------------------------------------------------------------------------
  // RGN4 : Region4 ( BH2_K )Module
  //-------------------------------------------------------------------------
  fModule.WriteModule(   RGN4::mid,  RGN4::Delay_BH2         ,              6);
  fModule.WriteModule(   RGN4::mid,  RGN4::Delay_BH2_K       ,              1);
  fModule.WriteModule(   RGN4::mid,  RGN4::Width_BH2_K       ,              4);
  fModule.WriteModule(   RGN4::mid,  RGN4::Selector_8        , BH2_K_Selector);
  fModule.WriteModule(   RGN4::mid,  RGN4::Selector_Clock    ,       Sel::Off);
  fModule.WriteModule(   RGN4::mid,  RGN4::Selector_Reserve2 ,       Sel::Off);




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
