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
  int TOF_segment[25];
  int TOF_seg;
  int seg[25];
  int On  = 1; 
  int Off = 0; 
  char* board_ip = argv[1];
  rbcp_header rbcpHeader;
  rbcpHeader.type = UDPRBCP::rbcp_ver_;
  rbcpHeader.id   = 0;

  FPGAModule fModule(board_ip, udp_port, &rbcpHeader, 0);
  //  std::cout << std::hex << fModule.ReadModule(BCT::mid, BCT::laddr_Version, 4) << std::endl;
  

      TOF_segment[1 ] =   Off;
      TOF_segment[2 ] =   Off;
      TOF_segment[3 ] =   Off;
      TOF_segment[4 ] =   Off;
      TOF_segment[5 ] =   Off;
      TOF_segment[6 ] =   Off;
      TOF_segment[7 ] =   Off;
      TOF_segment[8 ] =   Off;
      TOF_segment[9 ] =   Off;
      TOF_segment[10] =   Off;
      TOF_segment[11] =   Off;
      TOF_segment[12] =   Off;
      TOF_segment[13] =   Off;
      TOF_segment[14] =   Off;
      TOF_segment[15] =   Off;
      TOF_segment[16] =   Off;
      TOF_segment[17] =   Off;
      TOF_segment[18] =   Off;
      TOF_segment[19] =   Off;
      TOF_segment[20] =   On;
      TOF_segment[21] =   Off;
      TOF_segment[22] =   Off;
      TOF_segment[23] =   Off;
      TOF_segment[24] =   Off;


// Fanction
  if(TOF_segment[1 ] == On){seg[1 ] = 0b000000000000000000000001 ;} else { seg[1 ] = Off; } ;
  if(TOF_segment[2 ] == On){seg[2 ] = 0b000000000000000000000010 ;} else { seg[2 ] = Off; } ;
  if(TOF_segment[3 ] == On){seg[3 ] = 0b000000000000000000000100 ;} else { seg[3 ] = Off; } ;
  if(TOF_segment[4 ] == On){seg[4 ] = 0b000000000000000000001000 ;} else { seg[4 ] = Off; } ;
  if(TOF_segment[5 ] == On){seg[5 ] = 0b000000000000000000010000 ;} else { seg[5 ] = Off; } ;
  if(TOF_segment[6 ] == On){seg[6 ] = 0b000000000000000000100000 ;} else { seg[6 ] = Off; } ;
  if(TOF_segment[7 ] == On){seg[7 ] = 0b000000000000000001000000 ;} else { seg[7 ] = Off; } ;
  if(TOF_segment[8 ] == On){seg[8 ] = 0b000000000000000010000000 ;} else { seg[8 ] = Off; } ;
  if(TOF_segment[9 ] == On){seg[9 ] = 0b000000000000000100000000 ;} else { seg[9 ] = Off; } ;
  if(TOF_segment[10] == On){seg[10] = 0b000000000000001000000000 ;} else { seg[10] = Off; } ;
  if(TOF_segment[11] == On){seg[11] = 0b000000000000010000000000 ;} else { seg[11] = Off; } ;
  if(TOF_segment[12] == On){seg[12] = 0b000000000000100000000000 ;} else { seg[12] = Off; } ;
  if(TOF_segment[13] == On){seg[13] = 0b000000000001000000000000 ;} else { seg[13] = Off; } ;
  if(TOF_segment[14] == On){seg[14] = 0b000000000010000000000000 ;} else { seg[14] = Off; } ;
  if(TOF_segment[15] == On){seg[15] = 0b000000000100000000000000 ;} else { seg[15] = Off; } ;
  if(TOF_segment[16] == On){seg[16] = 0b000000001000000000000000 ;} else { seg[16] = Off; } ;
  if(TOF_segment[17] == On){seg[17] = 0b000000010000000000000000 ;} else { seg[17] = Off; } ;
  if(TOF_segment[18] == On){seg[18] = 0b000000100000000000000000 ;} else { seg[18] = Off; } ;
  if(TOF_segment[19] == On){seg[19] = 0b000001000000000000000000 ;} else { seg[19] = Off; } ;
  if(TOF_segment[20] == On){seg[20] = 0b000010000000000000000000 ;} else { seg[20] = Off; } ;
  if(TOF_segment[21] == On){seg[21] = 0b000100000000000000000000 ;} else { seg[21] = Off; } ;
  if(TOF_segment[22] == On){seg[22] = 0b001000000000000000000000 ;} else { seg[22] = Off; } ;
  if(TOF_segment[23] == On){seg[23] = 0b010000000000000000000000 ;} else { seg[23] = Off; } ;
  if(TOF_segment[24] == On){seg[24] = 0b100000000000000000000000 ;} else { seg[24] = Off; } ;

  TOF_seg = seg[1 ] | seg[2 ] | seg[3 ] | seg[3 ] | seg[4 ] | seg[5 ] | seg[6 ] |
            seg[7 ] | seg[8 ] | seg[9 ] | seg[9 ] | seg[10] | seg[11] | seg[12] |
            seg[13] | seg[14] | seg[15] | seg[16] | seg[16] | seg[17] | seg[18] |
            seg[19] | seg[20] | seg[21] | seg[22] | seg[22] | seg[23] | seg[24] ; 

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
