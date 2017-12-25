#include<fstream>
#include<iostream>
//#include<ios>

void tdc(char* source="hoge.dat")
{
  std::ifstream ifs(source, std::ios::binary);
  if(!ifs.is_open()){
    return -1;
  }

  std::cout << "open file" << std::endl;

  TH1F *hist = new TH1F("hoge", "hoge", 2048, 0, 2048);

  unsigned int buf[120];
  while(!(ifs.eof())){
    ifs.read((char*)&buf[0], 3*sizeof(unsigned int));
    hist->Fill(0x7ff & buf[2]);
  }// while

  hist->Draw();
}
