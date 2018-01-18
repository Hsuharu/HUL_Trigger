#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <map>
#include <iomanip>

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
std::map<std::string, int> param_map; 
std::ofstream ofs;


int param(std::string key){
 std::map<std::string, int>::const_iterator itr=param_map.find(key);
 if(itr == param_map.end() ){
  std::cout << "No this key! " << key << std::endl ;  
  std::exit(-1);
 }else{
  return itr->second;
 }
}

void Write( FPGAModule& module, unsigned int module_id, std::string name, unsigned int local_address, unsigned int write_data )
{
  module.WriteModule( module_id, local_address, write_data );
  unsigned int ret = module.ReadModule( module_id, local_address, 1 );
  ofs << std::left << std::setw(30) << name << std::right << std::setw(8) << ret << std::endl; 
}

int main(int argc, char* argv[])
{
  if(2 > argc){
    std::cout << "Usage\n";
    std::cout << "hul_main [param file]" << std::endl;
    return 0;
  }// usage
  
// File Read -------------------------------------------------
  std::ifstream ifs(argv[1]);
  if(!ifs.is_open()){
  std::cout << "No such file!" << argv[1] << std::endl ;  
  return -1;
  }
  
//  std::map<std::string, int> param; 

  std::string line;
  while( ifs.good() && std::getline(ifs,line) ){
      if(line[0]=='#') continue;
      std::stringstream ss(line);
      std::string key;
      int value      ;
      ss >> key >> value ;
//      param_map[key]=value;
      param_map[key]=value;
  }

  ofs.open("last.log");
  ofs << argv[1] << std::endl << std::endl;
  
// body ------------------------------------------------------
//  std::string board_ip = "192.168.11.11";
  std::string board_ip = "192.168.10.65";
  rbcp_header rbcpHeader;
  rbcpHeader.type = UDPRBCP::rbcp_ver_;
  rbcpHeader.id   = 0;

  FPGAModule fModule(board_ip.c_str(), udp_port, &rbcpHeader, 0);
  //  std::cout << std::hex << fModule.ReadModule(BCT::mid, BCT::laddr_Version, 4) << std::endl;
  //  Coincidence function 
  CoinModule Region1_Coin;
  CoinModule Region2_1_Coin;
  CoinModule Region2_2_Coin;
  CoinModule Region2_3_Coin;
  CoinModule Region2_4_Coin;
  CoinModule Region2_5_Coin;
  CoinModule Region2_6_Coin;


////////////////////////////////////////////////////////////////////////////////////////////////
//           Write                                                                            // 
//         Write                                                                              // 
//       Write                                                                                // 
////////////////////////////////////////////////////////////////////////////////////////////////

  //-------------------------------------------------------------------------
  // LED Module
  //-------------------------------------------------------------------------
//    Write( fModule,LED::mid, LED::laddr_led, param("LED") );

  //-------------------------------------------------------------------------
  // TOF Segment Selector 
  //-------------------------------------------------------------------------
  Write( fModule,   RGN1::mid,   "RGN1::SEL_TOF" ,   RGN1::SEL_TOF             ,   
                                                                       param("TOF_Seg1") 
                                                                     | param("TOF_Seg2")  << 1
                                                                     | param("TOF_Seg3")  << 2
                                                                     | param("TOF_Seg4")  << 3
                                                                     | param("TOF_Seg5")  << 4
                                                                     | param("TOF_Seg6")  << 5
                                                                     | param("TOF_Seg7")  << 6
                                                                     | param("TOF_Seg8")  << 7
                                                                     | param("TOF_Seg9")  << 8
                                                                     | param("TOF_Seg10") << 9
                                                                     | param("TOF_Seg11") << 10
                                                                     | param("TOF_Seg12") << 11
                                                                     | param("TOF_Seg13") << 12
                                                                     | param("TOF_Seg14") << 13
                                                                     | param("TOF_Seg15") << 14
                                                                     | param("TOF_Seg16") << 15
                                                                     | param("TOF_Seg17") << 16
                                                                     | param("TOF_Seg18") << 17
                                                                     | param("TOF_Seg19") << 18
                                                                     | param("TOF_Seg20") << 19
                                                                     | param("TOF_Seg21") << 20
                                                                     | param("TOF_Seg22") << 21
                                                                     | param("TOF_Seg23") << 22
                                                                     | param("TOF_Seg24") << 23 
                                                                    );

  //-------------------------------------------------------------------------
  // RGN1 : Region1 Module
  //-------------------------------------------------------------------------
      //-- Pi,P Beam --
  Write( fModule,   RGN1::mid,   "RGN1::Delay_BH1_Beam      ",   RGN1::Delay_BH1_Beam      ,    param("RGN1::Delay_BH1_Beam"));
  Write( fModule,   RGN1::mid,   "RGN1::Delay_BH2_Beam      ",   RGN1::Delay_BH2_Beam      ,    param("RGN1::Delay_BH2_Beam"));
  Write( fModule,   RGN1::mid,   "RGN1::Delay_BH1_Pi        ",   RGN1::Delay_BH1_Pi        ,    param("RGN1::Delay_BH1_Pi"));
  Write( fModule,   RGN1::mid,   "RGN1::Delay_BH2_Pi        ",   RGN1::Delay_BH2_Pi        ,    param("RGN1::Delay_BH2_Pi"));
  Write( fModule,   RGN1::mid,   "RGN1::Delay_BH1_P         ",   RGN1::Delay_BH1_P         ,    param("RGN1::Delay_BH1_P"));
  Write( fModule,   RGN1::mid,   "RGN1::Delay_BH2_P         ",   RGN1::Delay_BH2_P         ,    param("RGN1::Delay_BH2_P"));
                                 
  Write( fModule,   RGN1::mid,   "RGN1::Width_BH1_Beam      ",   RGN1::Width_BH1_Beam      ,    param("RGN1::Width_BH1_Beam"));
  Write( fModule,   RGN1::mid,   "RGN1::Width_BH2_Beam      ",   RGN1::Width_BH2_Beam      ,    param("RGN1::Width_BH2_Beam"));
  Write( fModule,   RGN1::mid,   "RGN1::Width_BH1_Pi        ",   RGN1::Width_BH1_Pi        ,    param("RGN1::Width_BH1_Pi"));
  Write( fModule,   RGN1::mid,   "RGN1::Width_BH2_Pi        ",   RGN1::Width_BH2_Pi        ,    param("RGN1::Width_BH2_Pi"));
  Write( fModule,   RGN1::mid,   "RGN1::Width_BH1_P         ",   RGN1::Width_BH1_P         ,    param("RGN1::Width_BH1_P"));
  Write( fModule,   RGN1::mid,   "RGN1::Width_BH2_P         ",   RGN1::Width_BH2_P         ,    param("RGN1::Width_BH2_P"));
                             
      //-- K_Scat Coin--      
  Write( fModule,   RGN1::mid,   "RGN1::Delay_SAC_K_Scat    ",   RGN1::Delay_SAC_K_Scat    ,    param("RGN1::Delay_SAC_K_Scat"));
  Write( fModule,   RGN1::mid,   "RGN1::Delay_TOF_K_Scat    ",   RGN1::Delay_TOF_K_Scat    ,    param("RGN1::Delay_TOF_K_Scat"));
  Write( fModule,   RGN1::mid,   "RGN1::Delay_LC_K_Scat     ",   RGN1::Delay_LC_K_Scat     ,    param("RGN1::Delay_LC_K_Scat"));
  Write( fModule,   RGN1::mid,   "RGN1::Delay_TOF_HT_K_Scat ",   RGN1::Delay_TOF_HT_K_Scat ,    param("RGN1::Delay_TOF_HT_K_Scat"));
  Write( fModule,   RGN1::mid,   "RGN1::Delay_Other4_K_Scat ",   RGN1::Delay_Other4_K_Scat ,    param("RGN1::Delay_Other4_K_Scat"));
  Write( fModule,   RGN1::mid,   "RGN1::Delay_Other5_K_Scat ",   RGN1::Delay_Other5_K_Scat ,    param("RGN1::Delay_Other5_K_Scat"));
                            
  Write( fModule,   RGN1::mid,   "RGN1::Width_SAC_K_Scat    ",   RGN1::Width_SAC_K_Scat    ,    param("RGN1::Width_SAC_K_Scat"));
  Write( fModule,   RGN1::mid,   "RGN1::Width_TOF_K_Scat    ",   RGN1::Width_TOF_K_Scat    ,    param("RGN1::Width_TOF_K_Scat"));
  Write( fModule,   RGN1::mid,   "RGN1::Width_Lucite_K_Scat ",   RGN1::Width_Lucite_K_Scat ,    param("RGN1::Width_LC_K_Scat"));
  Write( fModule,   RGN1::mid,   "RGN1::Width_TOF_HT_K_Scat ",   RGN1::Width_TOF_HT_K_Scat ,    param("RGN1::Width_TOF_HT_K_Scat"));
  Write( fModule,   RGN1::mid,   "RGN1::Width_Other4_K_Scat ",   RGN1::Width_Other4_K_Scat ,    param("RGN1::Width_Other4_K_Scat"));
  Write( fModule,   RGN1::mid,   "RGN1::Width_Other5_K_Scat ",   RGN1::Width_Other5_K_Scat ,    param("RGN1::Width_Other5_K_Scat"));
                                                                                            
      //-- K_Scat --                                                  
  Write( fModule,   RGN1::mid,   "RGN1::Delay_K_Scat"        ,   RGN1::Delay_K_Scat        ,    param("RGN1::Delay_K_Scat"));
  Write( fModule,   RGN1::mid,   "RGN1::Width_K_Scat"        ,   RGN1::Width_K_Scat        ,    param("RGN1::Width_K_Scat"));
                                                              
      //-- Coincidence -----         
  Write( fModule,   RGN1::mid,   "RGN1::Coin_ctrl_Beam"      ,   RGN1::Coin_ctrl_Beam      ,  Region1_Coin.BeamCtrl(
                                                                                                   param("RGN1::Coin_Beam_BH1"),
                                                                                                   param("RGN1::Coin_Beam_BH2")) );
                                                           
  Write( fModule,   RGN1::mid,   "RGN1::Coin_coin_Beam"     ,   RGN1::Coin_coin_Beam      ,  Region1_Coin.BeamCoin(
			                	              				     param("RGN1::Coin_Beam_BH1"),
                                                                                                   param("RGN1::Coin_Beam_BH2")) );
                                                           
  Write( fModule,   RGN1::mid,   "RGN1::Coin_ctrl_K_Scat"    ,   RGN1::Coin_ctrl_K_Scat    ,  Region1_Coin.KScatCtrl(
   			                	              				     param("RGN1::Coin_KScat_SAC")   ,
                                                                                             param("RGN1::Coin_KScat_TOF")   , 
			                	              				     param("RGN1::Coin_KScat_LC")    ,
			                	              				     param("RGN1::Coin_KScat_TOF_HT"),
			                	              				     param("RGN1::Coin_KScat_Other4"),
			                	              				     param("RGN1::Coin_KScat_Other5")) );
                                                           
  Write( fModule,   RGN1::mid,   "RGN1::Coin_coin_K_Scat"    ,   RGN1::Coin_coin_K_Scat    ,  Region1_Coin.KScatCoin(
								     param("RGN1::Coin_KScat_SAC")   ,
								     param("RGN1::Coin_KScat_TOF")   ,
								     param("RGN1::Coin_KScat_LC")    ,
								     param("RGN1::Coin_KScat_TOF_HT"),
								     param("RGN1::Coin_KScat_Other4"),
								     param("RGN1::Coin_KScat_Other5")) );
  
  //-------------------------------------------------------------------------
  // RGN2_1 : Region2_1 ( Beam_TOF Coin) Module
  //-------------------------------------------------------------------------
  Write( fModule,   RGN2_1::mid,   "RGN2_1::Delay_Beam  "     ,   RGN2_1::Delay_Beam       ,   param("RGN2_1::Delay_Beam"));
  Write( fModule,   RGN2_1::mid,   "RGN2_1::Delay_SAC   "     ,   RGN2_1::Delay_SAC        ,   param("RGN2_1::Delay_SAC"));
  Write( fModule,   RGN2_1::mid,   "RGN2_1::Delay_TOF   "     ,   RGN2_1::Delay_TOF        ,   param("RGN2_1::Delay_TOF"));
  Write( fModule,   RGN2_1::mid,   "RGN2_1::Delay_LC    "     ,   RGN2_1::Delay_LC         ,   param("RGN2_1::Delay_LC"));
  Write( fModule,   RGN2_1::mid,   "RGN2_1::Delay_TOF_HT"     ,   RGN2_1::Delay_TOF_HT     ,   param("RGN2_1::Delay_TOF_HT"));
  Write( fModule,   RGN2_1::mid,   "RGN2_1::Delay_Other4"     ,   RGN2_1::Delay_Other4     ,   param("RGN2_1::Delay_Other4"));
  Write( fModule,   RGN2_1::mid,   "RGN2_1::Delay_Other5"     ,   RGN2_1::Delay_Other5     ,   param("RGN2_1::Delay_Other5"));
                                 
  Write( fModule,   RGN2_1::mid,   "RGN2_1::Width_Beam  "     ,   RGN2_1::Width_Beam       ,   param("RGN2_1::Width_Beam"));
  Write( fModule,   RGN2_1::mid,   "RGN2_1::Width_SAC   "     ,   RGN2_1::Width_SAC        ,   param("RGN2_1::Width_SAC"));
  Write( fModule,   RGN2_1::mid,   "RGN2_1::Width_TOF   "     ,   RGN2_1::Width_TOF        ,   param("RGN2_1::Width_TOF"));
  Write( fModule,   RGN2_1::mid,   "RGN2_1::Width_LC    "     ,   RGN2_1::Width_LC         ,   param("RGN2_1::Width_LC"));
  Write( fModule,   RGN2_1::mid,   "RGN2_1::Width_TOF_HT"     ,   RGN2_1::Width_TOF_HT     ,   param("RGN2_1::Width_TOF_HT"));
  Write( fModule,   RGN2_1::mid,   "RGN2_1::Width_Other4"     ,   RGN2_1::Width_Other4     ,   param("RGN2_1::Width_Other4"));
  Write( fModule,   RGN2_1::mid,   "RGN2_1::Width_Other5"     ,   RGN2_1::Width_Other5     ,   param("RGN2_1::Width_Other5"));
                                
  Write( fModule,   RGN2_1::mid,   "RGN2_1::Coin_ctrl_7 "     ,   RGN2_1::Coin_ctrl_7      ,   Region2_1_Coin.Ctrl7(
                                                                     param("(Beam,TOF)_Beam")   ,
                                                                     param("(Beam,TOF)_SAC")    ,
                                                                     param("(Beam,TOF)_TOF")    ,
                                                                     param("(Beam,TOF)_LC")     , 
                                                                     param("(Beam,TOF)_TOF_HT") , 
                                                                     param("(Beam,TOF)_Other4") , 
                                                                     param("(Beam,TOF)_Other5") ));

  Write( fModule,   RGN2_1::mid,   "RGN2_1::Coin_coin_7 "     ,   RGN2_1::Coin_coin_7      ,   Region2_1_Coin.Coin7(
                                                                     param("(Beam,TOF)_Beam")   ,
                                                                     param("(Beam,TOF)_SAC")    ,
                                                                     param("(Beam,TOF)_TOF")    ,
                                                                     param("(Beam,TOF)_LC")     , 
                                                                     param("(Beam,TOF)_TOF_HT") , 
                                                                     param("(Beam,TOF)_Other4") , 
                                                                     param("(Beam,TOF)_Other5") ));

  
  //-------------------------------------------------------------------------
  // RGN2_2 : Region2_2 ( Beam_Pi Coin ) Module
  //-------------------------------------------------------------------------
  Write( fModule,   RGN2_2::mid,   "RGN2_2::Delay_Beam  "    ,   RGN2_2::Delay_Beam       ,   param("RGN2_2::Delay_Beam"));
  Write( fModule,   RGN2_2::mid,   "RGN2_2::Delay_SAC   "    ,   RGN2_2::Delay_SAC        ,   param("RGN2_2::Delay_SAC"));
  Write( fModule,   RGN2_2::mid,   "RGN2_2::Delay_TOF   "    ,   RGN2_2::Delay_TOF        ,   param("RGN2_2::Delay_TOF"));
  Write( fModule,   RGN2_2::mid,   "RGN2_2::Delay_LC    "    ,   RGN2_2::Delay_LC         ,   param("RGN2_2::Delay_LC"));
  Write( fModule,   RGN2_2::mid,   "RGN2_2::Delay_TOF_HT"    ,   RGN2_2::Delay_TOF_HT     ,   param("RGN2_2::Delay_TOF_HT"));
  Write( fModule,   RGN2_2::mid,   "RGN2_2::Delay_Other4"    ,   RGN2_2::Delay_Other4     ,   param("RGN2_2::Delay_Other4"));
  Write( fModule,   RGN2_2::mid,   "RGN2_2::Delay_Other5"    ,   RGN2_2::Delay_Other5     ,   param("RGN2_2::Delay_Other5"));
                                                                                              
  Write( fModule,   RGN2_2::mid,   "RGN2_2::Width_Beam  "    ,   RGN2_2::Width_Beam       ,   param("RGN2_2::Width_Beam"));
  Write( fModule,   RGN2_2::mid,   "RGN2_2::Width_SAC   "    ,   RGN2_2::Width_SAC        ,   param("RGN2_2::Width_SAC"));
  Write( fModule,   RGN2_2::mid,   "RGN2_2::Width_TOF   "    ,   RGN2_2::Width_TOF        ,   param("RGN2_2::Width_TOF"));
  Write( fModule,   RGN2_2::mid,   "RGN2_2::Width_LC    "    ,   RGN2_2::Width_LC         ,   param("RGN2_2::Width_LC"));
  Write( fModule,   RGN2_2::mid,   "RGN2_2::Width_TOF_HT"    ,   RGN2_2::Width_TOF_HT     ,   param("RGN2_2::Width_TOF_HT"));
  Write( fModule,   RGN2_2::mid,   "RGN2_2::Width_Other4"    ,   RGN2_2::Width_Other4     ,   param("RGN2_2::Width_Other4"));
  Write( fModule,   RGN2_2::mid,   "RGN2_2::Width_Other5"    ,   RGN2_2::Width_Other5     ,   param("RGN2_2::Width_Other5"));
                                                                 
  Write( fModule,   RGN2_2::mid,   "RGN2_2::Coin_ctrl_7 "     ,   RGN2_2::Coin_ctrl_7      ,   Region2_2_Coin.Ctrl7(
                                                                     param("(Beam,pi)_Beam")   ,
                                                                     param("(Beam,pi)_SAC")    ,
                                                                     param("(Beam,pi)_TOF")    ,
                                                                     param("(Beam,pi)_LC")     , 
                                                                     param("(Beam,pi)_TOF_HT") , 
                                                                     param("(Beam,pi)_Other4") , 
                                                                     param("(Beam,pi)_Other5") ));

  Write( fModule,   RGN2_2::mid,   "RGN2_2::Coin_coin_7 "     ,   RGN2_2::Coin_coin_7      ,   Region2_2_Coin.Coin7(
                                                                     param("(Beam,pi)_Beam")   ,
                                                                     param("(Beam,pi)_SAC")    ,
                                                                     param("(Beam,pi)_TOF")    ,
                                                                     param("(Beam,pi)_LC")     , 
                                                                     param("(Beam,pi)_TOF_HT") , 
                                                                     param("(Beam,pi)_Other4") , 
                                                                     param("(Beam,pi)_Other5") ));

  //-------------------------------------------------------------------------
  // RGN2_3 : Region2_3 ( Beam_P Coin ) Module
  //-------------------------------------------------------------------------
  Write( fModule,   RGN2_3::mid,   "RGN2_3::Delay_Beam  "     ,   RGN2_3::Delay_Beam       ,   param("RGN2_3::Delay_Beam"));
  Write( fModule,   RGN2_3::mid,   "RGN2_3::Delay_SAC   "     ,   RGN2_3::Delay_SAC        ,   param("RGN2_3::Delay_SAC"));
  Write( fModule,   RGN2_3::mid,   "RGN2_3::Delay_TOF   "     ,   RGN2_3::Delay_TOF        ,   param("RGN2_3::Delay_TOF"));
  Write( fModule,   RGN2_3::mid,   "RGN2_3::Delay_LC    "     ,   RGN2_3::Delay_LC         ,   param("RGN2_3::Delay_LC"));
  Write( fModule,   RGN2_3::mid,   "RGN2_3::Delay_TOF_HT"     ,   RGN2_3::Delay_TOF_HT     ,   param("RGN2_3::Delay_TOF_HT"));
  Write( fModule,   RGN2_3::mid,   "RGN2_3::Delay_Other4"     ,   RGN2_3::Delay_Other4     ,   param("RGN2_3::Delay_Other4"));
  Write( fModule,   RGN2_3::mid,   "RGN2_3::Delay_Other5"     ,   RGN2_3::Delay_Other5     ,   param("RGN2_3::Delay_Other5"));
                                  
  Write( fModule,   RGN2_3::mid,   "RGN2_3::Width_Beam  "     ,   RGN2_3::Width_Beam       ,   param("RGN2_3::Width_Beam"));
  Write( fModule,   RGN2_3::mid,   "RGN2_3::Width_SAC   "     ,   RGN2_3::Width_SAC        ,   param("RGN2_3::Width_SAC"));
  Write( fModule,   RGN2_3::mid,   "RGN2_3::Width_TOF   "     ,   RGN2_3::Width_TOF        ,   param("RGN2_3::Width_TOF"));
  Write( fModule,   RGN2_3::mid,   "RGN2_3::Width_LC    "     ,   RGN2_3::Width_LC         ,   param("RGN2_3::Width_LC"));
  Write( fModule,   RGN2_3::mid,   "RGN2_3::Width_TOF_HT"     ,   RGN2_3::Width_TOF_HT     ,   param("RGN2_3::Width_TOF_HT"));
  Write( fModule,   RGN2_3::mid,   "RGN2_3::Width_Other4"     ,   RGN2_3::Width_Other4     ,   param("RGN2_3::Width_Other4"));
  Write( fModule,   RGN2_3::mid,   "RGN2_3::Width_Other5"     ,   RGN2_3::Width_Other5     ,   param("RGN2_3::Width_Other5"));
                                 
  Write( fModule,   RGN2_3::mid,   "RGN2_3::Coin_ctrl_7 "     ,   RGN2_3::Coin_ctrl_7      ,   Region2_3_Coin.Ctrl7(
                                                                                                  param("(Beam,p)_Beam")   ,
                                                                                                  param("(Beam,p)_SAC")    ,
                                                                                                  param("(Beam,p)_TOF")    ,
                                                                                                  param("(Beam,p)_LC")     , 
                                                                                                  param("(Beam,p)_TOF_HT") , 
                                                                                                  param("(Beam,p)_Other4") , 
                                                                                                  param("(Beam,p)_Other5") ));
                                                            
  Write( fModule,   RGN2_3::mid,   "RGN2_3::Coin_coin_7 "     ,   RGN2_3::Coin_coin_7      ,   Region2_3_Coin.Coin7(
                                                                     param("(Beam,p)_Beam")   ,
                                                                     param("(Beam,p)_SAC")    ,
                                                                     param("(Beam,p)_TOF")    ,
                                                                     param("(Beam,p)_LC")     , 
                                                                     param("(Beam,p)_TOF_HT") , 
                                                                     param("(Beam,p)_Other4") , 
                                                                     param("(Beam,p)_Other5") ));

  //-------------------------------------------------------------------------
  // RGN2_4 : Region2_4 ( Coin1 ) Module
  //-------------------------------------------------------------------------
  Write( fModule,   RGN2_4::mid,   "RGN2_4::Delay_Beam  "     ,   RGN2_4::Delay_Beam       ,   param("RGN2_4::Delay_Beam"));
  Write( fModule,   RGN2_4::mid,   "RGN2_4::Delay_SAC   "     ,   RGN2_4::Delay_SAC        ,   param("RGN2_4::Delay_SAC"));
  Write( fModule,   RGN2_4::mid,   "RGN2_4::Delay_TOF   "     ,   RGN2_4::Delay_TOF        ,   param("RGN2_4::Delay_TOF"));
  Write( fModule,   RGN2_4::mid,   "RGN2_4::Delay_LC    "     ,   RGN2_4::Delay_LC         ,   param("RGN2_4::Delay_LC"));
  Write( fModule,   RGN2_4::mid,   "RGN2_4::Delay_TOF_HT"     ,   RGN2_4::Delay_TOF_HT     ,   param("RGN2_4::Delay_TOF_HT"));
  Write( fModule,   RGN2_4::mid,   "RGN2_4::Delay_Other4"     ,   RGN2_4::Delay_Other4     ,   param("RGN2_4::Delay_Other4"));
  Write( fModule,   RGN2_4::mid,   "RGN2_4::Delay_Other5"     ,   RGN2_4::Delay_Other5     ,   param("RGN2_4::Delay_Other5"));
                                  
  Write( fModule,   RGN2_4::mid,   "RGN2_4::Width_Beam  "     ,   RGN2_4::Width_Beam       ,   param("RGN2_4::Width_Beam"));
  Write( fModule,   RGN2_4::mid,   "RGN2_4::Width_SAC   "     ,   RGN2_4::Width_SAC        ,   param("RGN2_4::Width_SAC"));
  Write( fModule,   RGN2_4::mid,   "RGN2_4::Width_TOF   "     ,   RGN2_4::Width_TOF        ,   param("RGN2_4::Width_TOF"));
  Write( fModule,   RGN2_4::mid,   "RGN2_4::Width_LC    "     ,   RGN2_4::Width_LC         ,   param("RGN2_4::Width_LC"));
  Write( fModule,   RGN2_4::mid,   "RGN2_4::Width_TOF_HT"     ,   RGN2_4::Width_TOF_HT     ,   param("RGN2_4::Width_TOF_HT"));
  Write( fModule,   RGN2_4::mid,   "RGN2_4::Width_Other4"     ,   RGN2_4::Width_Other4     ,   param("RGN2_4::Width_Other4"));
  Write( fModule,   RGN2_4::mid,   "RGN2_4::Width_Other5"     ,   RGN2_4::Width_Other5     ,   param("RGN2_4::Width_Other5"));
                                 
  Write( fModule,   RGN2_4::mid,   "RGN2_4::Coin_ctrl_7 "     ,   RGN2_4::Coin_ctrl_7      ,   Region2_4_Coin.Ctrl7(
                                                                                                  param("Coin1_Beam")   ,
                                                                                                  param("Coin1_SAC")    ,
                                                                                                  param("Coin1_TOF")    ,
                                                                                                  param("Coin1_LC")     , 
                                                                                                  param("Coin1_TOF_HT") , 
                                                                                                  param("Coin1_Other4") , 
                                                                                                  param("Coin1_Other5") ));
                                                            
  Write( fModule,   RGN2_4::mid,   "RGN2_4::Coin_coin_7 "     ,   RGN2_4::Coin_coin_7      ,   Region2_4_Coin.Coin7(
                                                                                                  param("Coin1_Beam")   ,
                                                                                                  param("Coin1_SAC")    ,
                                                                                                  param("Coin1_TOF")    ,
                                                                                                  param("Coin1_LC")     , 
                                                                                                  param("Coin1_TOF_HT") , 
                                                                                                  param("Coin1_Other4") , 
                                                                                                  param("Coin1_Other5") ));

  
  
  //-------------------------------------------------------------------------
  // RGN2_6 : Region2_6 ( For E03 Coin ) Module
  //-------------------------------------------------------------------------
  Write( fModule,   RGN2_6::mid,   "RGN2_6::Delay_Beam_E03  ",   RGN2_6::Delay_Beam_E03  ,    param("RGN2_6::Delay_Beam_E03"));
  Write( fModule,   RGN2_6::mid,   "RGN2_6::Delay_Other1_E03",   RGN2_6::Delay_Other1_E03,    param("RGN2_6::Delay_Other1_E03"));
  Write( fModule,   RGN2_6::mid,   "RGN2_6::Delay_Other2_E03",   RGN2_6::Delay_Other2_E03,    param("RGN2_6::Delay_Other2_E03"));
  Write( fModule,   RGN2_6::mid,   "RGN2_6::Delay_Other3_E03",   RGN2_6::Delay_Other3_E03,    param("RGN2_6::Delay_Other3_E03"));
  Write( fModule,   RGN2_6::mid,   "RGN2_6::Delay_Other4_E03",   RGN2_6::Delay_Other4_E03,    param("RGN2_6::Delay_Other4_E03"));
  Write( fModule,   RGN2_6::mid,   "RGN2_6::Delay_Other5_E03",   RGN2_6::Delay_Other5_E03,    param("RGN2_6::Delay_Other5_E03"));
                                  
  Write( fModule,   RGN2_6::mid,   "RGN2_6::Width_Beam_E03  ",   RGN2_6::Width_Beam_E03  ,    param("RGN2_6::Width_Beam_E03"));
  Write( fModule,   RGN2_6::mid,   "RGN2_6::Width_Other1_E03",   RGN2_6::Width_Other1_E03,    param("RGN2_6::Width_Other1_E03"));
  Write( fModule,   RGN2_6::mid,   "RGN2_6::Width_Other2_E03",   RGN2_6::Width_Other2_E03,    param("RGN2_6::Width_Other2_E03"));
  Write( fModule,   RGN2_6::mid,   "RGN2_6::Width_Other3_E03",   RGN2_6::Width_Other3_E03,    param("RGN2_6::Width_Other3_E03"));
  Write( fModule,   RGN2_6::mid,   "RGN2_6::Width_Other4_E03",   RGN2_6::Width_Other4_E03,    param("RGN2_6::Width_Other4_E03"));
  Write( fModule,   RGN2_6::mid,   "RGN2_6::Width_Other5_E03",   RGN2_6::Width_Other5_E03,    param("RGN2_6::Width_Other5_E03"));
                                 
  Write( fModule,   RGN2_6::mid,   "RGN2_6::Coin_ctrl_6     ",   RGN2_6::Coin_ctrl_6      ,   Region2_6_Coin.Ctrl6(
                                                                                                 param("Coin_Beam_E03")  ,
                                                                                                 param("Coin_Other1_E03"),
                                                                                                 param("Coin_Other2_E03"),
                                                                                                 param("Coin_Other3_E03"), 
                                                                                                 param("Coin_Other4_E03"), 
                                                                                                 param("Coin_Other5_E03") 
                                                                                                 ));
  Write( fModule,   RGN2_6::mid,   "RGN2_6::Coin_coin_6     ",   RGN2_6::Coin_coin_6      ,   Region2_6_Coin.Coin6(
                                                                                                 param("Coin_Beam_E03")  ,
                                                                                                 param("Coin_Other1_E03"),
                                                                                                 param("Coin_Other2_E03"),
                                                                                                 param("Coin_Other3_E03"), 
                                                                                                 param("Coin_Other4_E03"), 
                                                                                                 param("Coin_Other5_E03") 
                                                                                                 ));

  //-------------------------------------------------------------------------
  // RGN3 : Region3 ( Else Or )Module
  //-------------------------------------------------------------------------
  Write( fModule,   RGN3::mid,  "RGN3::Selector_PS        ",  RGN3::Selector_PS        ,  
                                                                      param("Else_OR_selector_Beam")    << 6 
                                                                    | param("Else_OR_selector_Beam_TOF")<< 5 
                                                                    | param("Else_OR_selector_Beam_Pi") << 4 
                                                                    | param("Else_OR_selector_Beam_P")  << 3 
                                                                    | param("Else_OR_selector_Coin1")   << 2 
                                                                    | param("Extra_Line_Selector")   << 1 
                                                                    | param("Else_OR_selector_For_E03")
                                                                         );
  
                               
  Write( fModule,   RGN3::mid,  "RGN3::Delay_PS_OR        ",  RGN3::Delay_PS_OR        ,      param("RGN3::Delay_PS_OR"));
                              
  Write( fModule,   RGN3::mid,  "RGN3::Delay_all_Else_OR  ",  RGN3::Delay_all_Else_OR  ,      param("RGN3::Delay_all_Else_OR"));
  Write( fModule,   RGN3::mid,  "RGN3::Width_Else_OR      ",  RGN3::Width_Else_OR      ,      param("RGN3::Width_Else_OR"));
  Write( fModule,   RGN3::mid,  "RGN3::Delay_part_Else_OR ",  RGN3::Delay_part_Else_OR ,      param("RGN3::Delay_part_Else_OR"));
                             
  Write( fModule,   RGN3::mid,  "RGN3::Delay_K_Scat       ",  RGN3::Delay_K_Scat       ,      param("RGN3::Delay_K_Scat"));
  Write( fModule,   RGN3::mid,  "RGN3::Width_K_Scat       ",  RGN3::Width_K_Scat       ,      param("RGN3::Width_K_Scat"));
                            

  //-------------------------------------------------------------------------
  // RGN4 : Region4 ( BH2_K )Module
  //-------------------------------------------------------------------------
  Write( fModule,   RGN4::mid,  "RGN4::Delay_BH2  "       ,  RGN4::Delay_BH2         ,     param("RGN4::Delay_BH2"));
  Write( fModule,   RGN4::mid,  "RGN4::Delay_BH2_K"       ,  RGN4::Delay_BH2_K       ,     param("RGN4::Delay_BH2_K"));
  Write( fModule,   RGN4::mid,  "RGN4::Width_BH2_K"       ,  RGN4::Width_BH2_K       ,     param("RGN4::Width_BH2_K"));
  Write( fModule,   RGN4::mid,  "RGN4::Selector_8 "       ,  RGN4::Selector_8        ,     
                                                                   param("Selector_(BH2_1,K)") << 7
                                                                  |param("Selector_(BH2_2,K)") << 6
                                                                  |param("Selector_(BH2_3,K)") << 5
                                                                  |param("Selector_(BH2_4,K)") << 4
                                                                  |param("Selector_(BH2_5,K)") << 3
                                                                  |param("Selector_(BH2_6,K)") << 2
                                                                  |param("Selector_(BH2_7,K)") << 1
                                                                  |param("Selector_(BH2_8,K)")
                                                                            );

  Write( fModule,   RGN4::mid,  "RGN4::Selector_Clock   " ,  RGN4::Selector_Clock    ,     param("Selector_Clock"));
  Write( fModule,   RGN4::mid,  "RGN4::Selector_Reserve2" ,  RGN4::Selector_Reserve2 ,     param("Selector_Reserve2"));

  Write( fModule,   RGN3::mid,  "RGN3::PreScale_Beam      ",  RGN3::PreScale_Beam      ,        param("RGN3::PreScale_Beam")     -1 );
  Write( fModule,   RGN3::mid,  "RGN3::PreScale_Beam_TOF  ",  RGN3::PreScale_Beam_TOF  ,        param("RGN3::PreScale_Beam_TOF") -1 );
  Write( fModule,   RGN3::mid,  "RGN3::PreScale_Beam_Pi   ",  RGN3::PreScale_Beam_Pi   ,        param("RGN3::PreScale_Beam_Pi")  -1 );
  Write( fModule,   RGN3::mid,  "RGN3::PreScale_Beam_P    ",  RGN3::PreScale_Beam_P    ,        param("RGN3::PreScale_Beam_P")   -1 );
  Write( fModule,   RGN3::mid,  "RGN3::PreScale_Coin1     ",  RGN3::PreScale_Coin1     ,        param("RGN3::PreScale_Coin1")    -1 );
  Write( fModule,   RGN3::mid,  "RGN3::PreScale_For_E03   ",  RGN3::PreScale_For_E03   ,        param("RGN3::PreScale_For_E03")  -1 );
  Write( fModule,   RGN3::mid,  "RGN3::RST_PSCNT          ",  RGN3::RST_PSCNT          ,               1);
<<<<<<< HEAD

  //-------------------------------------------------------------------------
  // Extra Line!!! [RGN2_5 : Region2_5 ( Coin2 ) Module]
  //-------------------------------------------------------------------------
  Write( fModule,   RGN2_5::mid,   "Extra_Line_Dealy_Beam   "     ,   RGN2_5::Delay_Beam       ,   param("Extra_Line_Dealy_Beam"));
  Write( fModule,   RGN2_5::mid,   "Extra_Line_Dealy_SAC    "     ,   RGN2_5::Delay_SAC        ,   param("Extra_Line_Dealy_SAC"));
  Write( fModule,   RGN2_5::mid,   "Extra_Line_Dealy_TOF    "     ,   RGN2_5::Delay_TOF        ,   param("Extra_Line_Dealy_TOF"));
  Write( fModule,   RGN2_5::mid,   "Extra_Line_Dealy_LC     "     ,   RGN2_5::Delay_LC         ,   param("Extra_Line_Dealy_LC"));
  Write( fModule,   RGN2_5::mid,   "Extra_Line_Dealy_TOF_HT "     ,   RGN2_5::Delay_TOF_HT     ,   param("Extra_Line_Dealy_TOF_HT"));
  Write( fModule,   RGN2_5::mid,   "Extra_Line_Dealy_Other4 "     ,   RGN2_5::Delay_Other4     ,   param("Extra_Line_Dealy_Other4"));
  Write( fModule,   RGN2_5::mid,   "Extra_Line_Dealy_Other5 "     ,   RGN2_5::Delay_Other5     ,   param("Extra_Line_Dealy_Other5"));
                                  
  Write( fModule,   RGN2_5::mid,   "Extra_Line_Width_Beam   "     ,   RGN2_5::Width_Beam       ,   param("Extra_Line_Width_Beam"));
  Write( fModule,   RGN2_5::mid,   "Extra_Line_Width_SAC    "     ,   RGN2_5::Width_SAC        ,   param("Extra_Line_Width_SAC"));
  Write( fModule,   RGN2_5::mid,   "Extra_Line_Width_TOF    "     ,   RGN2_5::Width_TOF        ,   param("Extra_Line_Width_TOF"));
  Write( fModule,   RGN2_5::mid,   "Extra_Line_Width_LC     "     ,   RGN2_5::Width_LC         ,   param("Extra_Line_Width_LC"));
  Write( fModule,   RGN2_5::mid,   "Extra_Line_Width_TOF_HT "     ,   RGN2_5::Width_TOF_HT     ,   param("Extra_Line_Width_TOF_HT"));
  Write( fModule,   RGN2_5::mid,   "Extra_Line_Width_Other4 "     ,   RGN2_5::Width_Other4     ,   param("Extra_Line_Width_Other4"));
  Write( fModule,   RGN2_5::mid,   "Extra_Line_Width_Other5 "     ,   RGN2_5::Width_Other5     ,   param("Extra_Line_Width_Other5"));
                                 
  Write( fModule,   RGN2_5::mid,   "RGN2_5::Coin_ctrl_7 "     ,   RGN2_5::Coin_ctrl_7      ,   Region2_5_Coin.Ctrl7(
                                                                                                  param("Extra_Line_Beam")   ,
                                                                                                  param("Extra_Line_SAC")    ,
                                                                                                  param("Extra_Line_TOF")    ,
                                                                                                  param("Extra_Line_LC")     , 
                                                                                                  param("Extra_Line_TOF_HT") , 
                                                                                                  param("Extra_Line_Other4") , 
                                                                                                  param("Extra_Line_Other5") ));
                                                            
  Write( fModule,   RGN2_5::mid,   "RGN2_5::Coin_coin_7 "     ,   RGN2_5::Coin_coin_7      ,   Region2_5_Coin.Coin7(
                                                                                                  param("Extra_Line_Beam")   ,
                                                                                                  param("Extra_Line_SAC")    ,
                                                                                                  param("Extra_Line_TOF")    ,
                                                                                                  param("Extra_Line_LC")     , 
                                                                                                  param("Extra_Line_TOF_HT") , 
                                                                                                  param("Extra_Line_Other4") , 
                                                                                                  param("Extra_Line_Other5") ));
  
  Write( fModule,   RGN3::mid,  "Extra_Line_PreScale",  RGN3::PreScale_Coin2     ,        param("Extra_Line_PreScale")    -1 );
  
  
  
  
  
=======
>>>>>>> 7dfda778472af485f7d14c21b21f1d1a5688f408
  //-------------------------------------------------------------------------
  // IOM : In/Out Maneger ( NIMOUT Signal Select ) Module
  //-------------------------------------------------------------------------
//  Write( fModule,   IOM::mid,  IOM::NIMOUT1  ,          0b100000);
//  Write( fModule,   IOM::mid,  IOM::NIMOUT2  ,          0b011111);
//  Write( fModule,   IOM::mid,  IOM::NIMOUT3  ,          0b001110);
//  Write( fModule,   IOM::mid,  IOM::NIMOUT4  ,          0b100101);
//
//  Write( fModule,   IOM::mid,  IOM::NIMOUT1  ,        ID1::BH1_Beam);
//  Write( fModule,   IOM::mid,  IOM::NIMOUT2  ,        ID1::BH2_Beam);
//  Write( fModule,   IOM::mid,  IOM::NIMOUT3  ,        ID2::SAC_or);
//  Write( fModule,   IOM::mid,  IOM::NIMOUT4  ,        ID2::Beam);

// >> >> >> src/set_nimout_main.cc!!!!!!!!!! 



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

  std::cout << "Successfully finished!" << std::endl;
  return 0;

}// main
