#ifndef REGISTERH_
#define REGISTERH_

namespace HUL_Trigger{
  //-------------------------------------------------------------------------
  // LED Module
  //-------------------------------------------------------------------------
  namespace LED{
    static const int mid = 0x0;
    enum LocalAddress{
      laddr_led   = 0x000 // W/R, [7:0] select trigger line
    };
  };


  //-------------------------------------------------------------------------
  // RGN1 : Region1 Module
  //-------------------------------------------------------------------------
  namespace RGN1{
    static const int mid = 0x1;
    enum LocalAddress{
      SEL_TOF             = 0x000 ,    //  w/r, [23:0],select  TOF  
      //-- Pi,P Beam --
      Delay_BH1_Beam      = 0xa00 ,    //  w/r, [4:0], select  delay
      Delay_BH2_Beam      = 0xa10 ,    //  w/r, [4:0], select  delay
      Delay_BH1_Pi        = 0xa20 ,    //  w/r, [4:0], select  delay
      Delay_BH2_Pi        = 0xa30 ,    //  w/r, [4:0], select  delay
      Delay_BH1_P         = 0xa40 ,    //  w/r, [4:0], select  delay
      Delay_BH2_P         = 0xa50 ,    //  w/r, [4:0], select  delay

      Width_BH1_Beam      = 0xb00 ,    //  w/r, [4:0], select  width
      Width_BH2_Beam      = 0xb10 ,    //  w/r, [4:0], select  width
      Width_BH1_Pi        = 0xb20 ,    //  w/r, [4:0], select  width
      Width_BH2_Pi        = 0xb30 ,    //  w/r, [4:0], select  width
      Width_BH1_P         = 0xb40 ,    //  w/r, [4:0], select  width
      Width_BH2_P         = 0xb50 ,    //  w/r, [4:0], select  width

      //-- K_Scat Coin--
      Delay_SAC_K_Scat    = 0xa60 ,    //  w/r, [4:0], select  delay
      Delay_TOF_K_Scat    = 0xa70 ,    //  w/r, [4:0], select  delay
      Delay_LC_K_Scat     = 0xa80 ,    //  w/r, [4:0], select  delay
      Delay_TOF_HT_K_Scat = 0xa90 ,    //  w/r, [4:0], select  delay
      Delay_Other4_K_Scat = 0xaa0 ,    //  w/r, [4:0], select  delay
      Delay_Other5_K_Scat = 0xab0 ,    //  w/r, [4:0], select  delay

      Width_SAC_K_Scat    = 0xb60 ,    //  w/r, [4:0], select  width
      Width_TOF_K_Scat    = 0xb70 ,    //  w/r, [4:0], select  width
      Width_Lucite_K_Scat = 0xb80 ,    //  w/r, [4:0], select  width
      Width_TOF_HT_K_Scat = 0xb90 ,    //  w/r, [4:0], select  width
      Width_Other4_K_Scat = 0xba0 ,    //  w/r, [4:0], select  width
      Width_Other5_K_Scat = 0xbb0 ,    //  w/r, [4:0], select  width

      //-- K_Scat --           
      Delay_K_Scat        = 0xac0 ,    //  w/r, [4:0], select  delay
      Width_K_Scat        = 0xbc0 ,    //  w/r, [4:0], select  width

      //-- Coincidence -------
      Coin_ctrl_Beam      = 0xc00 ,    //  W/R, [7:0], select sig
      Coin_coin_Beam      = 0xc10 ,     //  W/R, [7:0], select sig 
      Coin_ctrl_K_Scat    = 0xc20 ,    //  W/R, [7:0], select sig
      Coin_coin_K_Scat    = 0xc30      //  W/R, [7:0], select sig 
    };
  };

  //-------------------------------------------------------------------------
  // RGN2_1 : Region2_1 ( Beam_TOF Coin) Module
  //-------------------------------------------------------------------------
  namespace RGN2_1{
    static const int mid = 0x2;
    enum LocalAddress{

      Delay_Beam        = 0xa00, // w/r, [4:0], select  delay
      Delay_SAC         = 0xa10, // w/r, [4:0], select  delay
      Delay_TOF         = 0xa20, // w/r, [4:0], select  delay
      Delay_LC          = 0xa30, // w/r, [4:0], select  delay
      Delay_TOF_HT      = 0xa40, // w/r, [4:0], select  delay
      Delay_Other4      = 0xa50, // w/r, [4:0], select  delay
      Delay_Other5      = 0xa60, // w/r, [4:0], select  delay

      Width_Beam        = 0xb00, // w/r, [4:0], select  width
      Width_SAC         = 0xb10, // w/r, [4:0], select  width
      Width_TOF         = 0xb20, // w/r, [4:0], select  width
      Width_LC          = 0xb30, // w/r, [4:0], select  width
      Width_TOF_HT      = 0xb40, // w/r, [4:0], select  width
      Width_Other4      = 0xb50, // w/r, [4:0], select  width
      Width_Other5      = 0xb60, // w/r, [4:0], select  width

      Coin_ctrl_7       = 0xc00, // W/R, [6:0], select sig
      Coin_coin_7       = 0xc10  // W/R, [6:0], select sig 

    };
  };

  //-------------------------------------------------------------------------
  // RGN2_2 : Region2_2 ( Beam_Pi Coin ) Module
  //-------------------------------------------------------------------------
  namespace RGN2_2{
    static const int mid = 0x3;
    enum LocalAddress{

      Delay_Beam        = 0xa00, // w/r, [4:0], select  delay
      Delay_SAC         = 0xa10, // w/r, [4:0], select  delay
      Delay_TOF         = 0xa20, // w/r, [4:0], select  delay
      Delay_LC          = 0xa30, // w/r, [4:0], select  delay
      Delay_TOF_HT      = 0xa40, // w/r, [4:0], select  delay
      Delay_Other4      = 0xa50, // w/r, [4:0], select  delay
      Delay_Other5      = 0xa60, // w/r, [4:0], select  delay

      Width_Beam        = 0xb00, // w/r, [4:0], select  width
      Width_SAC         = 0xb10, // w/r, [4:0], select  width
      Width_TOF         = 0xb20, // w/r, [4:0], select  width
      Width_LC          = 0xb30, // w/r, [4:0], select  width
      Width_TOF_HT      = 0xb40, // w/r, [4:0], select  width
      Width_Other4      = 0xb50, // w/r, [4:0], select  width
      Width_Other5      = 0xb60, // w/r, [4:0], select  width

      Coin_ctrl_7       = 0xc00, // W/R, [6:0], select sig
      Coin_coin_7       = 0xc10  // W/R, [6:0], select sig 

    };
  };

  //-------------------------------------------------------------------------
  // RGN2_3 : Region2_3 ( Beam_P Coin ) Module
  //-------------------------------------------------------------------------
  namespace RGN2_3{
    static const int mid = 0x4;
    enum LocalAddress{

      Delay_Beam        = 0xa00, // w/r, [4:0], select  delay
      Delay_SAC         = 0xa10, // w/r, [4:0], select  delay
      Delay_TOF         = 0xa20, // w/r, [4:0], select  delay
      Delay_LC          = 0xa30, // w/r, [4:0], select  delay
      Delay_TOF_HT      = 0xa40, // w/r, [4:0], select  delay
      Delay_Other4      = 0xa50, // w/r, [4:0], select  delay
      Delay_Other5      = 0xa60, // w/r, [4:0], select  delay

      Width_Beam        = 0xb00, // w/r, [4:0], select  width
      Width_SAC         = 0xb10, // w/r, [4:0], select  width
      Width_TOF         = 0xb20, // w/r, [4:0], select  width
      Width_LC          = 0xb30, // w/r, [4:0], select  width
      Width_TOF_HT      = 0xb40, // w/r, [4:0], select  width
      Width_Other4      = 0xb50, // w/r, [4:0], select  width
      Width_Other5      = 0xb60, // w/r, [4:0], select  width

      Coin_ctrl_7       = 0xc00, // W/R, [6:0], select sig
      Coin_coin_7       = 0xc10  // W/R, [6:0], select sig 

    };
  };

  //-------------------------------------------------------------------------
  // RGN2_4 : Region2_4 ( Coin1 ) Module
  //-------------------------------------------------------------------------
  namespace RGN2_4{
    static const int mid = 0x5;
    enum LocalAddress{

      Delay_Beam        = 0xa00, // w/r, [4:0], select  delay
      Delay_SAC         = 0xa10, // w/r, [4:0], select  delay
      Delay_TOF         = 0xa20, // w/r, [4:0], select  delay
      Delay_LC          = 0xa30, // w/r, [4:0], select  delay
      Delay_TOF_HT      = 0xa40, // w/r, [4:0], select  delay
      Delay_Other4      = 0xa50, // w/r, [4:0], select  delay
      Delay_Other5      = 0xa60, // w/r, [4:0], select  delay

      Width_Beam        = 0xb00, // w/r, [4:0], select  width
      Width_SAC         = 0xb10, // w/r, [4:0], select  width
      Width_TOF         = 0xb20, // w/r, [4:0], select  width
      Width_LC          = 0xb30, // w/r, [4:0], select  width
      Width_TOF_HT      = 0xb40, // w/r, [4:0], select  width
      Width_Other4      = 0xb50, // w/r, [4:0], select  width
      Width_Other5      = 0xb60, // w/r, [4:0], select  width

      Coin_ctrl_7       = 0xc00, // W/R, [6:0], select sig
      Coin_coin_7       = 0xc10  // W/R, [6:0], select sig 

    };
  };

  //-------------------------------------------------------------------------
  // RGN2_5 : Region2_5 ( Coin2 ) Module
  //-------------------------------------------------------------------------
  namespace RGN2_5{
    static const int mid = 0x6;
    enum LocalAddress{

      Delay_Beam        = 0xa00, // w/r, [4:0], select  delay
      Delay_SAC         = 0xa10, // w/r, [4:0], select  delay
      Delay_TOF         = 0xa20, // w/r, [4:0], select  delay
      Delay_LC          = 0xa30, // w/r, [4:0], select  delay
      Delay_TOF_HT      = 0xa40, // w/r, [4:0], select  delay
      Delay_Other4      = 0xa50, // w/r, [4:0], select  delay
      Delay_Other5      = 0xa60, // w/r, [4:0], select  delay

      Width_Beam        = 0xb00, // w/r, [4:0], select  width
      Width_SAC         = 0xb10, // w/r, [4:0], select  width
      Width_TOF         = 0xb20, // w/r, [4:0], select  width
      Width_LC          = 0xb30, // w/r, [4:0], select  width
      Width_TOF_HT      = 0xb40, // w/r, [4:0], select  width
      Width_Other4      = 0xb50, // w/r, [4:0], select  width
      Width_Other5      = 0xb60, // w/r, [4:0], select  width

      Coin_ctrl_7       = 0xc00, // W/R, [6:0], select sig
      Coin_coin_7       = 0xc10  // W/R, [6:0], select sig 

    };
  };

  //-------------------------------------------------------------------------
  // RGN2_6 : Region2_6 ( For E03 Coin ) Module
  //-------------------------------------------------------------------------
  namespace RGN2_6{
    static const int mid = 0x7;
    enum LocalAddress{
      Delay_Beam_E03    = 0xa00, // w/r, [4:0], select  delay
      Delay_Other1_E03  = 0xa10, // w/r, [4:0], select  delay
      Delay_Other2_E03  = 0xa20, // w/r, [4:0], select  delay
      Delay_Other3_E03  = 0xa30, // w/r, [4:0], select  delay
      Delay_Other4_E03  = 0xa40, // w/r, [4:0], select  delay
      Delay_Other5_E03  = 0xa50, // w/r, [4:0], select  delay

      Width_Beam_E03    = 0xb00, // w/r, [4:0], select  delay
      Width_Other1_E03  = 0xb10, // w/r, [4:0], select  delay
      Width_Other2_E03  = 0xb20, // w/r, [4:0], select  delay
      Width_Other3_E03  = 0xb30, // w/r, [4:0], select  delay
      Width_Other4_E03  = 0xb40, // w/r, [4:0], select  delay
      Width_Other5_E03  = 0xb50, // w/r, [4:0], select  delay

      Coin_ctrl_6        = 0xc00, // W/R, [5:0], select sig
      Coin_coin_6        = 0xc10  // W/R, [5:0], select sig 

    };
  };

  //-------------------------------------------------------------------------
  // RGN3 : Region3 ( Else Or )Module
  //-------------------------------------------------------------------------
  namespace RGN3{
    static const int mid = 0x8;
    enum LocalAddress{

      PreScale_Beam     = 0xd00, // w/r, [23:0], select Preset Scale Value(0 ~ 2^23-1) 
      PreScale_Beam_TOF = 0xd10, // w/r, [23:0], select Preset Scale Value(0 ~ 2^23-1) 
      PreScale_Beam_Pi  = 0xd20, // w/r, [23:0], select Preset Scale Value(0 ~ 2^23-1) 
      PreScale_Beam_P   = 0xd30, // w/r, [23:0], select Preset Scale Value(0 ~ 2^23-1) 
      PreScale_Coin1    = 0xd40, // w/r, [23:0], select Preset Scale Value(0 ~ 2^23-1) 
      PreScale_Coin2    = 0xd50, // w/r, [23:0], select Preset Scale Value(0 ~ 2^23-1) 
      PreScale_For_E03  = 0xd60, // w/r, [23:0], select Preset Scale Value(0 ~ 2^23-1) 
      RST_PSCNT         = 0xe10, // w/r, [23:0], select Preset Scale Value(0 ~ 2^23-1) 

      Delay_PS_OR       = 0xa00, // w/r, [4:0], 
      Delay_part_Else_OR     = 0xa10, // w/r, [4:0], 

      Delay_all_Else_OR     = 0xaa0, // w/r, [4:0], 
      Width_Else_OR     = 0xba0, // w/r, [4:0], 

      Delay_K_Scat      = 0xab0, // w/r, [4:0], 
      Width_K_Scat      = 0xbb0, // w/r, [4:0], 

      Selector_PS       = 0xe00,  // w/r, [6:0], 
//      Reset_PS          = 0xe10  // w/r, [6:0], 

    };
  };

  //-------------------------------------------------------------------------
  // RGN4 : Region4 ( BH2_K )Module
  //-------------------------------------------------------------------------
  namespace RGN4{
    static const int mid = 0x9;
    enum LocalAddress{

      Delay_BH2         = 0xaa0, // w/r, [4:0], 
      Delay_BH2_K       = 0xa00, // w/r, [4:0], 
      Width_BH2_K       = 0xb00, // w/r, [4:0], 
      Selector_8        = 0xe00, // w/r, [8:0], 
      Selector_Clock    = 0xe10, // w/r, [0], 
      Selector_Reserve2 = 0xe20 // w/r, [0], 

    };
  };

  //-------------------------------------------------------------------------
  // IOM : In/Out Maneger ( NIMOUT Signal Select ) Module
  //-------------------------------------------------------------------------
  namespace IOM{
    static const int mid = 0xa;
    enum LocalAddress{
      NIMOUT1           = 0x010, // W/R, [5:0],NIMOUT1 select sig 
      NIMOUT2           = 0x020, // W/R, [5:0],NIMOUT2 select sig 
      NIMOUT3           = 0x030, // W/R, [5:0],NIMOUT3 select sig 
      NIMOUT4           = 0x040  // W/R, [5:0],NIMOUT4 select sig 
    };
  };



  // BCT --------------------------------------------------------------------
  namespace BCT{
    static const int mid = 0xe;
    enum LocalAddress{
      laddr_Reset       = 0x0, // W, assert reset signal from BCT
      laddr_Version     = 0x10,// R, [31:0]
      laddr_ReConfig    = 0x20 // W, Reconfig FPGA by SPI
    };
  };

  //-------------------------------------------------------------------------
  // COIN  
  //-------------------------------------------------------------------------
  enum CoinDef{
    CoinAnd=1, CoinNot=0, DontCare=2
  };

  //-------------------------------------------------------------------------
  // TOF Selector 
  //-------------------------------------------------------------------------
  namespace TOFSel{
    enum SegmentSel{
        Off   = 0x0,
        Seg1  = 0x1,
        Seg2  = 0x2,
        Seg3  = 0x4,
        Seg4  = 0x8,
        Seg5  = 0x10,
        Seg6  = 0x20,
        Seg7  = 0x40,
        Seg8  = 0x80,
        Seg9  = 0x100,
        Seg10 = 0x200,
        Seg11 = 0x400,
        Seg12 = 0x800,
        Seg13 = 0x1000,
        Seg14 = 0x2000,
        Seg15 = 0x4000,
        Seg16 = 0x8000,
        Seg17 = 0x10000,
        Seg18 = 0x20000,
        Seg19 = 0x40000,
        Seg20 = 0x80000,
        Seg21 = 0x100000,
        Seg22 = 0x200000,
        Seg23 = 0x400000,
        Seg24 = 0x800000
    };
  };

  //-------------------------------------------------------------------------
  // Selector for Clock and Reserve2
  //-------------------------------------------------------------------------
  namespace Sel{
    enum Selector{
        Off   = 0x0,
        On    = 0x1,
    };
  };

  //-------------------------------------------------------------------------
  // Selector for BH2_K 
  //-------------------------------------------------------------------------
  namespace BH2_K_Sel{
    enum BH2_KSel{
        Off   = 0x0,
        Seg1  = 0x80,
        Seg2  = 0x40,
        Seg3  = 0x20,
        Seg4  = 0x10,
        Seg5  = 0x8,
        Seg6  = 0x2,
        Seg7  = 0x4,
        Seg8  = 0x1,
    };
  };

  //-------------------------------------------------------------------------
  // Selector for Else_OR
  //-------------------------------------------------------------------------
  namespace Else_OR_Sel{
    enum Else_OR_Sel{
        Off   = 0x0,
        PreScale_Beam      = 0x40,
        PreScale_Beam_TOF  = 0x20,
        PreScale_Beam_Pi   = 0x10,
        PreScale_Beam_P    = 0x8,
        PreScale_Coin1     = 0x2,
        PreScale_Coin2     = 0x4,
        PreScale_For_E03   = 0x1,
    };
  };

};
#endif
