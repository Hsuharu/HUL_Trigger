#ifndef ProbeMap_
#define ProbeMap_

#include <iostream>
#include <cstdio>

namespace Probe{
  //-------------------------------------------------------------------------
  // ProbeID for In/Out Mnager Module 
  //-------------------------------------------------------------------------
  namespace ID1{
    enum NIMID1_for_NIMOUT1_2{
                BH1_Beam          = 0b000000,   // 0
                BH2_Beam          = 0b000001,   // 1
                BH1_pi            = 0b000010,   // 2
                BH2_pi            = 0b000011,   // 3
                BH1_p             = 0b000100,   // 4
                BH2_p             = 0b000101,   // 5
                SAC_K_Scat        = 0b000110,   // 6
                TOF_K_Scat        = 0b000111,   // 7
                LC_K_Scat         = 0b001000,   // 8
                TOF_HT_K_Scat     = 0b001001,   // 9
                Other4_K_Scat     = 0b001010,   // 10
                Other5_K_Scat     = 0b001011,   // 11
                Beam_Beam_TOF     = 0b001100,   // 12
                SAC_or_Beam_TOF   = 0b001101,   // 13
                TOF_or_Beam_TOF   = 0b001110,   // 14
                LC_or_Beam_TOF    = 0b001111,   // 15
                TOF_HT_Beam_TOF   = 0b010000,   // 16
                Other4_Beam_TOF   = 0b010001,   // 17
                Other5_Beam_TOF   = 0b010010,   // 18
                Beam_Coin1        = 0b010011,   // 19
                SAC_or_Coin1      = 0b010100,   // 20
                TOF_or_Coin1      = 0b010101,   // 21
                LC_or_Coin1       = 0b010110,   // 22
                TOF_HT_Coin1      = 0b010111,   // 23
                Other4_Coin1      = 0b011000,   // 24
                Other5_Coin1      = 0b011001,   // 25
                Beam_E03          = 0b011010,   // 26
                Other1_E03        = 0b011011,   // 27
                Other2_E03        = 0b011100,   // 28
                Other3_E03        = 0b011101,   // 29
                Other4_E03        = 0b011110,   // 30
                Other5_E03        = 0b011111,   // 31
                PS_OR_DLY         = 0b100000,   // 32
                K_Scat_Else_OR    = 0b100001,   // 33
                BH2_1_DLY         = 0b100010,   // 34
                BH2_2_DLY         = 0b100011,   // 35
                BH2_3_DLY         = 0b100100,   // 36
                BH2_4_DLY         = 0b100101,   // 37
                BH2_5_DLY         = 0b100110,   // 38
                BH2_6_DLY         = 0b100111,   // 39
                BH2_7_DLY         = 0b101000,   // 40
                BH2_8_DLY         = 0b101001    // 41
    };
  };
  
  namespace ID2{
    enum NIMID2_for_NIMOUT3_4{
                Else_OR           = 0b000000 ,   // 0    
                BH2_1_K           = 0b000001 ,   // 1    
                BH2_2_K           = 0b000010 ,   // 2    
                BH2_3_K           = 0b000011 ,   // 3    
                BH2_4_K           = 0b000100 ,   // 4    
                BH2_5_K           = 0b000101 ,   // 5    
                BH2_6_K           = 0b000110 ,   // 6    
                BH2_7_K           = 0b000111 ,   // 7    
                BH2_8_K           = 0b001000 ,   // 8    
                BH2_K_OR          = 0b001001 ,   // 9    
                Other1            = 0b001010 ,   // 10    
                Other2            = 0b001011 ,   // 11   
                Other3            = 0b001100 ,   // 12   
                Other4            = 0b001101 ,   // 13   
                Other5            = 0b001110 ,   // 14   
                Clock             = 0b001111 ,   // 15   
                Reserve2          = 0b010000 ,   // 16   
                BH1_or            = 0b010001 ,   // 17   
                BH2_or            = 0b010010 ,   // 18   
                SAC_or            = 0b010011 ,   // 19   
                TOF_or            = 0b010100 ,   // 20   
                LC_or             = 0b010101 ,   // 21   
                TOF_HT            = 0b010110 ,   // 22   
                Beam              = 0b010111 ,   // 23   
                Pi_Beam           = 0b011000 ,   // 24   
                P_Beam            = 0b011001 ,   // 25   
                K_Scat            = 0b011010 ,   // 26   
                Beam_TOF_Coin     = 0b011011 ,   // 27   
                Beam_Pi_Coin      = 0b011100 ,   // 28   
                Beam_P_Coin       = 0b011101 ,   // 29   
                Coin1_Coin        = 0b011110 ,   // 30   
                Coin2_Coin        = 0b011111 ,   // 31   
                For_E03_Coin      = 0b100000 ,   // 32   
                Beam_PS           = 0b100001 ,   // 33   
                Beam_TOF_PS       = 0b100010 ,   // 34   
                Beam_Pi_PS        = 0b100011 ,   // 35   
                Beam_P_PS         = 0b100100 ,   // 36   
                Coin1_PS          = 0b100101 ,   // 37   
                Coin2_PS          = 0b100110 ,   // 38   
                For_E03_PS        = 0b100111 ,   // 39   
                clk1MHz           = 0b101000 ,   // 40   
                clk100kHz         = 0b101001 ,   // 41   
                clk10kHz          = 0b101010 ,   // 42   
                clk1kHz           = 0b101011     // 43   
    };
  };
  
};

#endif
