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

  ofs.open("nimIO.log");
  ofs << argv[1] << std::endl << std::endl;
  
// body ------------------------------------------------------
//  std::string board_ip = "192.168.11.11";
  std::string board_ip = "192.168.10.65";
  rbcp_header rbcpHeader;
  rbcpHeader.type = UDPRBCP::rbcp_ver_;
  rbcpHeader.id   = 0;

  FPGAModule fModule(board_ip.c_str(), udp_port, &rbcpHeader, 0);

//-------------------------------------------------------------------------
// IOM : In/Out Maneger ( NIMOUT Signal Select ) Module
//-------------------------------------------------------------------------
//  fModule.WriteModule(   IOM::mid,  IOM::NIMOUT1  ,          0b100000);
//  fModule.WriteModule(   IOM::mid,  IOM::NIMOUT2  ,          0b011111);
//  fModule.WriteModule(   IOM::mid,  IOM::NIMOUT3  ,          0b001110);
//  fModule.WriteModule(   IOM::mid,  IOM::NIMOUT4  ,          0b100101);

  Write( fModule,  IOM::mid, "IOM::NIMOUT1"  , IOM::NIMOUT1  ,        param("IOM::NIMOUT1"));
  Write( fModule,  IOM::mid, "IOM::NIMOUT2"  , IOM::NIMOUT2  ,        param("IOM::NIMOUT2"));
  Write( fModule,  IOM::mid, "IOM::NIMOUT3"  , IOM::NIMOUT3  ,        param("IOM::NIMOUT3"));
  Write( fModule,  IOM::mid, "IOM::NIMOUT4"  , IOM::NIMOUT4  ,        param("IOM::NIMOUT4"));

                 ////////////////////////////////////////
                 //    ID 1                            //      
                 ////////////////////////////////////////
                 //     0            BH1_Beam          //        
                 //     1            BH2_Beam          //      
                 //     2            BH1_pi            //      
                 //     3            BH2_pi            //      
                 //     4            BH1_p             //      
                 //     5            BH2_p             //      
                 //     6            SAC_K_Scat        //      
                 //     7            TOF_K_Scat        //      
                 //     8            LC_K_Scat         //      
                 //     9            TOF_HT_K_Scat     //      
                 //     10           Other4_K_Scat     //      
                 //     11           Other5_K_Scat     //      
                 //     12           Beam_Beam_TOF     //      
                 //     13           SAC_or_Beam_TOF   //      
                 //     14           TOF_or_Beam_TOF   //      
                 //     15           LC_or_Beam_TOF    //      
                 //     16           TOF_HT_Beam_TOF   //      
                 //     17           Other4_Beam_TOF   //      
                 //     18           Other5_Beam_TOF   //      
                 //     19           Beam_Coin1        //      
                 //     20           SAC_or_Coin1      //      
                 //     21           TOF_or_Coin1      //      
                 //     22           LC_or_Coin1       //      
                 //     23           TOF_HT_Coin1      //      
                 //     24           Other4_Coin1      //      
                 //     25           Other5_Coin1      //      
                 //     26           Beam_E03          //      
                 //     27           Other1_E03        //      
                 //     28           Other2_E03        //      
                 //     29           Other3_E03        //      
                 //     30           Other4_E03        //      
                 //     31           Other5_E03        //      
                 //     32           PS_OR_DLY         //      
                 //     33           K_Scat_Else_OR    //      
                 //     34           BH2_1_DLY         //      
                 //     35           BH2_2_DLY         //      
                 //     36           BH2_3_DLY         //      
                 //     37           BH2_4_DLY         //      
                 //     38           BH2_5_DLY         //      
                 //     39           BH2_6_DLY         //     
                 //     40           BH2_7_DLY         //     
                 //     41           BH2_8_DLY         // 
                 //     42                             // 
                 //     43                             // 
                 //     44                             // 
                 //     45                             // 
                 //     46                             // 
                 ////////////////////////////////////////

  std::cout << "Successfully finished!" << std::endl;
  return 0;

}// main
