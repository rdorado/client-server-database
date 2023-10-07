#include <arpa/inet.h>
#include <sys/socket.h>
#include <iostream>
#include <unistd.h>
#include <string.h>

#include "defs.h"

#include <chrono>
using namespace std::chrono;

int client_fd;

void client_connect()
{
  struct sockaddr_in serv_addr;
  if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
  {
    std::cout << "ERROR: Socket creation error" << std:: endl;
  }
	
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(PORT);
  
  if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
  {
    std::cout << "ERROR: Invalid address/ Address not supported" << std:: endl;
  }
  
  int status;
  if ((status = connect(client_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr))) < 0)
  {
    std::cout << "ERROR: Connection Failed " << std:: endl;
  }
}

std::string send_message(std::string message)
{
	send(client_fd, message.c_str(), message.length(), 0);
	
	char buffer[1024] = { 0 };
    int valread = read(client_fd, buffer, 1024);
	
	return std::string(buffer);
}

/**
 Test send a number to the server
 Here we put the logic to test/check answer
 */
void test(){
  milliseconds start = duration_cast< milliseconds >(system_clock::now().time_since_epoch());
  int rep = 30000;
  srand(time(0));
  for (int i=0;i<rep;i++)
  {
    int num = 1 + rand() % 500000;
	
	std::string result = send_message(std::to_string(Operation::INSERT)+std::to_string(num));	
	
  }
  milliseconds end = duration_cast< milliseconds >(system_clock::now().time_since_epoch());
  std::cout << "Test 1, insertions. Performed " << rep << " operations. Time spent: " << (end.count() - start.count()) << " ms." << std::endl;

  rep = 30000;
  start = duration_cast< milliseconds >(system_clock::now().time_since_epoch());
  for (int i=0;i<rep;i++)
  {
    int num = 1 + rand() % 500000;
	
	std::string result = send_message(std::to_string(Operation::QUERY)+std::to_string(num));	
	
  }
  end = duration_cast< milliseconds >(system_clock::now().time_since_epoch());
  std::cout << "Test 2, search. Performed " << rep << " operations. Time spent: " << (end.count() - start.count()) << " ms." << std::endl;
}

void check(){
  send_message("check");
}

int main(int argc, char* argv[])
{
  // connect to client
  client_connect();
  
  // perform the test
  test();
  check();
  // closing the connected socket
  //close(client_fd);
  std::cout << "Client disconected" << std:: endl;
  return 0;
}
