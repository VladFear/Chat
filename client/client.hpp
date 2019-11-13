#include <iostream>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>

class TcpClient
{
	private:
		struct sockaddr_in serv_addr;
		int _socket;
		const short BUFFER_SIZE = 1024;

	public:
		TcpClient();
		void create_socket(const int server_port);
		void connect_server() const;
		int send_data(std::string s) const;
};
