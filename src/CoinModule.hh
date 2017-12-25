#ifndef CoinModule_
#define CoinModule_

#include<iostream>
#include<vector>

#include"Uncopyable.hh"

//struct rbcp_header;

class CoinModule
: Uncopyable<CoinModule>
{
  public:
    CoinModule(int Ini = 0 )
  {
    for( int i = 0 ; i<8 ;i++){
      In[i] = 0;
      }
      Beam_coin = 0;
      Beam_ctrl = 0;
      KScat_coin = 0;
      KScat_ctrl = 0;
//      coin_reg[0]    = 0;
//      for(int i=0 ; i<7 ; i++){
//          coin_reg[i+1]    = 2^i;
//      };
//
//      ctrl_reg[0]    = 0;
//      for(int i=0 ; i<7 ; i++){
//          ctrl_reg[i+1]    = 2^i;
//      };
      coin_reg[0] = 0b00000000;
      coin_reg[8] = 0b10000000;
      coin_reg[7] = 0b01000000;
      coin_reg[6] = 0b00100000;
      coin_reg[5] = 0b00010000;
      coin_reg[4] = 0b00001000;
      coin_reg[3] = 0b00000100;
      coin_reg[2] = 0b00000010;
      coin_reg[1] = 0b00000001;

      ctrl_reg[0] = 0b00000000;
      ctrl_reg[8] = 0b10000000;
      ctrl_reg[7] = 0b01000000;
      ctrl_reg[6] = 0b00100000;
      ctrl_reg[5] = 0b00010000;
      ctrl_reg[4] = 0b00001000;
      ctrl_reg[3] = 0b00000100;
      ctrl_reg[2] = 0b00000010;
      ctrl_reg[1] = 0b00000001;

  }

    ~CoinModule()
    {
//      std::cout << " Destruct \n" ;
    }

  private:
    int BH1_or;
    int BH2_or;
    int SAC_or;
    int TOF_or;
    int LC_or ;
    int TOFHT ;
    int Other4;
    int Other5;

  public:
    unsigned int Beam_coin ;
    unsigned int Beam_ctrl ;
    unsigned int KScat_coin ;
    unsigned int KScat_ctrl ;
//    int BeamCoin(int In[1],int  In[0]) ;//{ return Beam_coin ; }
//    int BeamCtrl(int In[1],int  In[0]) ;//{ return Beam_ctrl ; }
    int BeamCoin(int BH1_or, int BH2_or) ;//{ return Beam_coin ; }
    int BeamCtrl(int BH1_or, int BH2_or) ;//{ return Beam_ctrl ; }

//    int KScatCoin(int In[5], int In[4], int In[3], int In[2], int In[1], int In[0]) ;
//    int KScatCtrl(int In[5], int In[4], int In[3], int In[2], int In[1], int In[0]) ;
    int KScatCoin(int SAC_or, int TOF_or, int LC_or, int TOFHT, int Other4, int Other5);
    int KScatCtrl(int SAC_or, int TOF_or, int LC_or, int TOFHT, int Other4, int Other5);
    int In[8];
    int coin_reg[9];
    int ctrl_reg[9];


};

//    enum CoinReg{
//      coin_reg[0] = 0b000000,
//      coin_reg[8] = 0b10000000,
//      coin_reg[7] = 0b01000000,
//      coin_reg[6] = 0b00100000,
//      coin_reg[5] = 0b00010000,
//      coin_reg[4] = 0b00001000,
//      coin_reg[3] = 0b00000100,
//      coin_reg[2] = 0b00000010,
//      coin_reg[1] = 0b00000001
//    };
//
//    enum CtrlReg{
//      ctrl_reg[0] = 0b000000,
//      ctrl_reg[8] = 0b10000000,
//      ctrl_reg[7] = 0b01000000,
//      ctrl_reg[6] = 0b00100000,
//      ctrl_reg[5] = 0b00010000,
//      ctrl_reg[4] = 0b00001000,
//      ctrl_reg[3] = 0b00000100,
//      ctrl_reg[2] = 0b00000010,
//      ctrl_reg[1] = 0b00000001
//    };
//

//int CoinModule::BeamCoin(int In[0], int In[1])
int CoinModule::BeamCoin(int BH1_or, int BH2_or) 
{
  In[0] = BH1_or;
  In[1] = BH2_or;
  for(int i=0; i<2 ; i++){
  if(In[i] == 1){
    Beam_coin = Beam_coin | coin_reg[2-i];
  }else if(In[i] == 0){              
    Beam_coin = Beam_coin | coin_reg[2-i];
  }else if(In[i] == 2){
    Beam_coin = Beam_coin | coin_reg[0];
  } 
  };
 return Beam_coin;
//  std::cout << std::bitset<8>(Beam_coin) << " " << std::bitset<8>(Beam_ctrl) << std::endl;
};

//int CoinModule::BeamCtrl(int In[1], int In[0])
int CoinModule::BeamCtrl(int BH1_or, int BH2_or) 
{
  In[0] = BH1_or;
  In[1] = BH2_or;
  for(int i=0; i<2 ; i++){
  if(In[i] == 1){
    Beam_ctrl = Beam_ctrl | ctrl_reg[2-i];
  }else if(In[i] == 0){
    Beam_ctrl = Beam_ctrl | ctrl_reg[0];
  }else if(In[i] == 2){
    Beam_ctrl = Beam_ctrl | ctrl_reg[0];
  } 
  };
 return Beam_ctrl;
};

//int CoinModule::KScatCoin(int In[5], int In[4], int In[3], int In[2], int In[1], int In[0])
int CoinModule::KScatCoin(int SAC_or, int TOF_or, int LC_or, int TOFHT, int Other4, int Other5)
{
  In[0] = SAC_or;
  In[1] = TOF_or;
  In[2] = LC_or;
  In[3] = TOFHT ;
  In[4] = Other4 ;
  In[5] = Other5 ;
  for(int i=0; i<6 ; i++){
  if(In[i] == 1){
    KScat_coin = KScat_coin | coin_reg[6-i];
  }else if(In[i] == 0){
    KScat_coin = KScat_coin | coin_reg[6-i];
  }else if(In[i] == 2){
    KScat_coin = KScat_coin | coin_reg[0];
  } 
//  std::cout << std::bitset<8>(Beam_coin) << " " << std::bitset<8>(Beam_ctrl) << std::endl;
};
 return KScat_coin;
};

//int CoinModule::KScatCtrl(int In[5], int In[4], int In[3], int In[2], int In[1], int In[0])
int CoinModule::KScatCtrl(int SAC_or, int TOF_or, int LC_or, int TOFHT, int Other4, int Other5)
{
  In[0] = SAC_or;
  In[1] = TOF_or;
  In[2] = LC_or;
  In[3] = TOFHT ;
  In[4] = Other4 ;
  In[5] = Other5 ;
  for(int i=0; i<6 ; i++){
  if(In[i] == 1){
    KScat_ctrl = KScat_ctrl | ctrl_reg[6-i];
  }else if(In[i] == 0){
    KScat_ctrl = KScat_ctrl | ctrl_reg[0];
  }else if(In[i] == 2){
    KScat_ctrl = KScat_ctrl | ctrl_reg[0];
  } 
};
 return KScat_ctrl;
};



#endif
