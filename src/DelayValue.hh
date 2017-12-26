#ifndef DelayVoalue_
#define DelayVoalue_

#include <iostream>
#include <cstdio>

namespace DelayValue{
  //-------------------------------------------------------------------------
  // DealyValue for Dlay_Register Module 
  //-------------------------------------------------------------------------
  namespace DLY{
    enum Delay_Value{
                DLY2_5ns   = 0b00001,   // 1
                DLY5_0ns   = 0b00010,   // 2
                DLY7_5ns   = 0b00011,   // 3
                DLY10_0ns  = 0b00100,   // 4
                DLY12_5ns  = 0b00101,   // 5
                DLY15_0ns  = 0b00110,   // 6
                DLY17_5ns  = 0b00111,   // 7
                DLY20_5ns  = 0b01000,   // 8
                DLY22_5ns  = 0b01001,   // 9
                DLY25_0ns  = 0b01010,   // 10
                DLY27_5ns  = 0b01011,   // 11
                DLY30_0ns  = 0b01100,   // 12
                DLY32_5ns  = 0b01101,   // 13
                DLY35_0ns  = 0b01110,   // 14
                DLY37_5ns  = 0b01111,   // 15
                DLY40_0ns  = 0b10000    // 16
    };
  };
  
};

#endif
