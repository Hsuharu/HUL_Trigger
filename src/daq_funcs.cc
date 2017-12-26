#include"daq_funcs.hh"

#include<fstream>
#include<cstdlib>
#include"gzfilter.hh"

int user_stop = 0;

static const int NofHead = 3;
static const int NofData = NofHead + 2048;

static const int print_step = 1;
#define COMPRESS 1

using namespace HUL_Trigger;

// signal -----------------------------------------------------------------
void
UserStop_FromCtrlC(int signal)
{
  std::cout << "Stop request" << std::endl;
  user_stop = 1;
}

// execute daq ------------------------------------------------------------
void
daq(char* ip, rbcp_header *rbcpHeader, int runno, int eventno)
{
  (void) signal(SIGINT, UserStop_FromCtrlC);

  // TCP socket
  int sock;
  if(-1 == (sock = ConnectSocket((const char*)ip))) return;
  std::cout << "socket connected" << std::endl;

  close(sock);

  return;
}

// ConnectSocket ----------------------------------------------------------
int
ConnectSocket(const char* ip)
{
  struct sockaddr_in SiTCP_ADDR;
  unsigned int port = 24;

  int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
  SiTCP_ADDR.sin_family      = AF_INET;
  SiTCP_ADDR.sin_port        = htons((unsigned short int) port);
  SiTCP_ADDR.sin_addr.s_addr = inet_addr(ip);

  struct timeval tv;
  tv.tv_sec  = 3;
  tv.tv_usec = 0;
  setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (char*)&tv, sizeof(tv));

  int flag = 1;
  setsockopt(sock, IPPROTO_TCP, TCP_NODELAY, (char*)&flag, sizeof(flag));

  if(0 > connect(sock, (struct sockaddr*)&SiTCP_ADDR, sizeof(SiTCP_ADDR))){
    std::cerr << "#E : TCP connection error" << std::endl;
    close(sock);
    return -1;
  }
  
  return sock;
}

// Event Cycle ------------------------------------------------------------
int
Event_Cycle(int sock, unsigned int* buffer)
{
  // data read ---------------------------------------------------------
  static const unsigned int sizeHeader = NofHead*sizeof(unsigned int);
  int ret = receive(sock, (char*)buffer, sizeHeader);
  if(ret < 0) return -1;

  unsigned int n_word_data  = buffer[1] & 0x3ff;
  unsigned int sizeData     = n_word_data*sizeof(unsigned int);
  
  if(n_word_data == 0) return NofHead;

  ret = receive(sock, (char*)(buffer + NofHead), sizeData);
  if(ret < 0) return -1;
  
  return NofHead+ n_word_data;
}

// receive ----------------------------------------------------------------
int
receive(int sock, char* data_buf, unsigned int length)
{
  unsigned int revd_size = 0;
  int tmp_ret            = 0;

  while(revd_size < length){
    tmp_ret = recv(sock, data_buf + revd_size, length -revd_size, 0);

    if(tmp_ret == 0) break;
    if(tmp_ret < 0){
      int errbuf = errno;
      perror("TCP receive");
      if(errbuf == EAGAIN){
	// this is time out
      }else{
	// something wrong
	std::cerr << "TCP error : " << errbuf << std::endl;
      }

      revd_size = tmp_ret;
      break;
    }

    revd_size += tmp_ret;
  }

  return revd_size;
}

