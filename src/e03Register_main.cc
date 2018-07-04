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

  ofs.open("e03last.log");
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
  CoinModule Region2_4_Coin;
  CoinModule Region2_5_Coin;
  CoinModule Region2_6_Coin;


////////////////////////////////////////////////////////////////////////////////////////////////
//           Write                                                                            // 
//         Write                                                                              // 
//       Write                                                                                // 
////////////////////////////////////////////////////////////////////////////////////////////////


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
 Write( fModule,   RGN3::mid,  "RGN3::Delay_PS_OR        ",  RGN3::Delay_PS_OR        ,      param("RGN3::Delay_PS_OR"));
                              
  Write( fModule,   RGN3::mid,  "RGN3::Delay_all_Else_OR  ",  RGN3::Delay_all_Else_OR  ,      param("RGN3::Delay_all_Else_OR"));
  Write( fModule,   RGN3::mid,  "RGN3::Width_Else_OR      ",  RGN3::Width_Else_OR      ,      param("RGN3::Width_Else_OR"));
  Write( fModule,   RGN3::mid,  "RGN3::Delay_part_Else_OR ",  RGN3::Delay_part_Else_OR ,      param("RGN3::Delay_part_Else_OR"));
                             
  Write( fModule,   RGN3::mid,  "RGN3::Delay_K_Scat       ",  RGN3::Delay_K_Scat       ,      param("RGN3::Delay_K_Scat"));
  Write( fModule,   RGN3::mid,  "RGN3::Width_K_Scat       ",  RGN3::Width_K_Scat       ,      param("RGN3::Width_K_Scat"));
                            

////////////////////////////////////////////////////////////////////////////////////////////////
//           Read                                                                             // 
//         Read                                                                               // 
//       Read                                                                                 // 
////////////////////////////////////////////////////////////////////////////////////////////////

//  fModule.ReadModule(   RGN1::mid,   RGN1::Width_BH1_Pi,    1);
//  fModule.ReadModule(   RGN1::mid,   RGN1::Width_BH2_Pi,    1);
//  fModule.ReadModule(   RGN1::mid,   RGN1::Width_BH1_P ,    1);
//  fModule.ReadModule(   RGN1::mid,   RGN1::Width_BH2_P ,    1);

//  std::cout <<  fModule.ReadModule(   RGN1::mid,   RGN1::Width_BH1_Pi,    1) << std::endl;
//  std::cout <<  fModule.ReadModule(   RGN1::mid,   RGN1::Width_BH2_Pi,    1) << std::endl;
//  std::cout <<  fModule.ReadModule(   RGN1::mid,   RGN1::Width_BH1_P ,    1) << std::endl;
//  std::cout <<  fModule.ReadModule(   RGN1::mid,   RGN1::Width_BH2_P ,    1) << std::endl;

  std::cout << "Successfully finished!" << std::endl;
  return 0;

}// main
