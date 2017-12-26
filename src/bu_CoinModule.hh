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
      :BH1_or(Ini)
      ,BH2_or(Ini)
      ,Beam_coin(Ini)
      ,Beam_ctrl(Ini)
  {
  }

    ~CoinModule()
    {
//j      std::cout << " Destruct \n" ;
    }

  private:
    int BH1_or;
    int BH2_or;

  public:
    unsigned int Beam_coin ;
    unsigned int Beam_ctrl ;
//    void Beam(int BH1_or, int BH2_or);
    int BeamCoin(int BH1_or, int BH2_or) ;//{ return Beam_coin ; }
    int BeamCtrl(int BH1_or, int BH2_or) ;//{ return Beam_ctrl ; }

    int KScatCoin(int SAC_or, int TOF_or, int LC_or, int TOFHT, int Other4, int Other5)
    int KScatCtrl(int SAC_or, int TOF_or, int LC_or, int TOFHT, int Other4, int Other5)

};

    enum CoinReg{
      coin_not    = 0b000000,
      coin_BH1    = 0b000010,
      coin_BH2    = 0b000001,
      coin_tof    = 0b100000,
      coin_sac    = 0b010000,
      coin_lc     = 0b001000,
      coin_tofht  = 0b000100,
      coin_other4 = 0b000010,
      coin_other5 = 0b000001
    };


    enum CtrlReg{
      ctrl_not    = 0b000000,
      ctrl_BH1    = 0b000010,
      ctrl_BH2    = 0b000001,
      ctrl_tof    = 0b100000,
      ctrl_sac    = 0b010000,
      ctrl_lc     = 0b001000,
      ctrl_tofht  = 0b000100,
      ctrl_other4 = 0b000010,
      ctrl_other5 = 0b000001
    };


int CoinModule::BeamCoin(int BH1_or, int BH2_or)
{
  if(BH1_or == 1){
    Beam_coin = Beam_coin | coin_BH1;
  }else if(BH1_or == 0){
    Beam_coin = Beam_coin | coin_BH1;
  }else if(BH1_or == 2){
    Beam_coin = Beam_coin | coin_not;
  } 

  if(BH2_or == 1){
    Beam_coin = Beam_coin | coin_BH2;
  }else if(BH2_or == 0){
    Beam_coin = Beam_coin | coin_BH2;
  }else if(BH2_or == 2){
    Beam_coin = Beam_coin | coin_not;
  } 
 
 return Beam_coin;
//  std::cout << std::bitset<8>(Beam_coin) << " " << std::bitset<8>(Beam_ctrl) << std::endl;
};

int CoinModule::BeamCtrl(int BH1_or, int BH2_or)
{
  if(BH1_or == 1){
    Beam_ctrl = Beam_ctrl | ctrl_BH1;
  }else if(BH1_or == 0){
    Beam_ctrl = Beam_ctrl | ctrl_not;
  }else if(BH1_or == 2){
    Beam_ctrl = Beam_ctrl | ctrl_not;
  } 

  if(BH2_or == 1){
    Beam_ctrl = Beam_ctrl | ctrl_BH2;
  }else if(BH2_or == 0){
    Beam_ctrl = Beam_ctrl | ctrl_not;
  }else if(BH2_or == 2){
    Beam_ctrl = Beam_ctrl | ctrl_not;
  } 

 return Beam_ctrl;
};

int CoinModule::KScatCoin(int SAC_or, int TOF_or, int LC_or, int TOFHT, int Other4, int Other5)
{
  if(SAC_or == 1){
    KScat_coin = KScat_coin | coin_SAC;
  }else if(SAC_or == 0){
    KScat_coin = KScat_coin | coin_SAC;
  }else if(SAC_or == 2){
    KScat_coin = KScat_coin | coin_not;
  } 

  if(TOF_or == 1){
    KScat_coin = KScat_coin | coin_TOF;
  }else if(TOF_or == 0){
    KScat_coin = KScat_coin | coin_TOF;
  }else if(TOF_or == 2){
    KScat_coin = KScat_coin | coin_not;
  } 
 
  if(LC_or == 1){
    KScat_coin = KScat_coin | coin_LC;
  }else if(LC_or == 0){
    KScat_coin = KScat_coin | coin_LC;
  }else if(LC_or == 2){
    KScat_coin = KScat_coin | coin_not;
  } 
 
  if(TOFHT == 1){
    KScat_coin = KScat_coin | coin_LC;
  }else if(TOFHT == 0){
    KScat_coin = KScat_coin | coin_LC;
  }else if(TOFHT == 2){
    KScat_coin = KScat_coin | coin_not;
  } 
 
  if(Other4 == 1){
    KScat_coin = KScat_coin | coin_LC;
  }else if(Other4 == 0){
    KScat_coin = KScat_coin | coin_LC;
  }else if(Other4 == 2){
    KScat_coin = KScat_coin | coin_not;
  } 
 
  if(Other5 == 1){
    KScat_coin = KScat_coin | coin_LC;
  }else if(Other5 == 0){
    KScat_coin = KScat_coin | coin_LC;
  }else if(Other5 == 2){
    KScat_coin = KScat_coin | coin_not;
  } 
 
 return KScat_coin;
//  std::cout << std::bitset<8>(Beam_coin) << " " << std::bitset<8>(Beam_ctrl) << std::endl;
};

int CoinModule::KScatCtrl(int SAC_or, int TOF_or, int LC_or, int TOFHT, int Other4, int Other5)
{
  if(SAC_or == 1){
    KScat_ctrl = KScat_ctrl | ctrl_SAC;
  }else if(SAC_or == 0){
    KScat_ctrl = KScat_ctrl | ctrl_SAC;
  }else if(SAC_or == 2){
    KScat_ctrl = KScat_ctrl | ctrl_not;
  } 

  if(TOF_or == 1){
    KScat_ctrl = KScat_ctrl | ctrl_TOF;
  }else if(TOF_or == 0){
    KScat_ctrl = KScat_ctrl | ctrl_TOF;
  }else if(TOF_or == 2){
    KScat_ctrl = KScat_ctrl | ctrl_not;
  } 
 
  if(LC_or == 1){
    KScat_ctrl = KScat_ctrl | ctrl_LC;
  }else if(LC_or == 0){
    KScat_ctrl = KScat_ctrl | ctrl_LC;
  }else if(LC_or == 2){
    KScat_ctrl = KScat_ctrl | ctrl_not;
  } 
 
  if(TOFHT == 1){
    KScat_ctrl = KScat_ctrl | ctrl_LC;
  }else if(TOFHT == 0){
    KScat_ctrl = KScat_ctrl | ctrl_LC;
  }else if(TOFHT == 2){
    KScat_ctrl = KScat_ctrl | ctrl_not;
  } 
 
  if(Other4 == 1){
    KScat_ctrl = KScat_ctrl | ctrl_LC;
  }else if(Other4 == 0){
    KScat_ctrl = KScat_ctrl | ctrl_LC;
  }else if(Other4 == 2){
    KScat_ctrl = KScat_ctrl | ctrl_not;
  } 
 
  if(Other5 == 1){
    KScat_ctrl = KScat_ctrl | ctrl_LC;
  }else if(Other5 == 0){
    KScat_ctrl = KScat_ctrl | ctrl_LC;
  }else if(Other5 == 2){
    KScat_ctrl = KScat_ctrl | ctrl_not;
  } 
 
 return KScat_ctrl;
};



#endif
