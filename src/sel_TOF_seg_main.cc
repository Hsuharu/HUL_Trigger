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
//  int TOF_segment[25];
  int TOF_seg;
//  int seg[25];
//  int On  = 1; 
//  int Off = 0; 
//  char* board_ip = argv[1];
  char* board_ip                  ;
//  char fixedip[] = "192.168.11.11";
  char fixedip[] = "192.168.10.65";
  board_ip = fixedip;
  rbcp_header rbcpHeader;
  rbcpHeader.type = UDPRBCP::rbcp_ver_;
  rbcpHeader.id   = 0;

  FPGAModule fModule(board_ip, udp_port, &rbcpHeader, 0);
  //  std::cout << std::hex << fModule.ReadModule(BCT::mid, BCT::laddr_Version, 4) << std::endl;
  
////////////////////////////////////////////////////////////////////////
//                                                                    //
//    TOF Selector       Please write SegN or Off behind TOFSel::     //
//                          SegN  -> N is Segment Number              //
//                          Off -> Not Use                            //
//                                                                    //
////////////////////////////////////////////////////////////////////////


  TOF_seg = TOFSel::Seg24 
          | TOFSel::Seg23 
          | TOFSel::Seg22 
          | TOFSel::Seg21 
          | TOFSel::Seg20
          | TOFSel::Seg19 
          | TOFSel::Seg18 
          | TOFSel::Seg17 
          | TOFSel::Seg16 
          | TOFSel::Seg15 
          | TOFSel::Seg14 
          | TOFSel::Seg13 
          | TOFSel::Seg12 
          | TOFSel::Seg11 
          | TOFSel::Seg10 
          | TOFSel::Seg9 
          | TOFSel::Seg8 
          | TOFSel::Seg7 
          | TOFSel::Seg6 
          | TOFSel::Seg5 
          | TOFSel::Seg4 
          | TOFSel::Seg3 
          | TOFSel::Seg2 
          | TOFSel::Seg1 ; 
          

////////////////////////////////////////////////////////////////////////////////////////////////
//           Write                                                                            // 
//         Write                                                                              // 
//       Write                                                                                // 
////////////////////////////////////////////////////////////////////////////////////////////////

  //-------------------------------------------------------------------------
  // Select TOF Segment   
  //-------------------------------------------------------------------------
  fModule.WriteModule(   RGN1::mid,   RGN1::SEL_TOF             ,   TOF_seg);
           

  return 0;

}// main
