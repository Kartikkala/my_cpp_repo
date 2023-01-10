#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <cstring>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

int Ping(const std::string& ip_address) {
  // Create a socket
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    std::cerr << "Error creating socket" << std::endl;
    return -1;
  }

  // Set the timeout for the socket
  struct timeval timeout;
  timeout.tv_sec = 2;  // 2 seconds
  timeout.tv_usec = 0;
  if (setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) < 0) {
    std::cerr << "Error setting socket timeout" << std::endl;
    return -1;
  }

  // Convert the IP address to a sockaddr_in structure
  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(443);  // HTTPS
  if (inet_pton(AF_INET, ip_address.c_str(), &addr.sin_addr) <= 0) {
    std::cerr << "Error parsing IP address: " << ip_address << std::endl;
    return -1;
  }

  // Connect to the server
  auto start = std::chrono::high_resolution_clock::now();
  if (connect(sock, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
    std::cerr << "Error connecting to " << ip_address << std::endl;
    return -1;
  }
  auto end = std::chrono::high_resolution_clock::now();
  auto latency = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

  // Close the socket
  close(sock);

  return latency.count();
}

int main() {
  std::string ip_address = "8.8.8.8";  // Example IP address
  for(;;)
  {
    int ping = Ping(ip_address);
    std::cout<<ping<<"\n";
    if(ping<100)
        system("play /home/sirkartik/Downloads/echo.wav");
    sleep(2);
  }

  return 0;
}
