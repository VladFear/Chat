#include <iostream>
#include <vector>
#include <unistd.h>
#include <netinet/in.h>
#include <errno.h>
#include <stdexcept>
#include <string.h>

class TcpServer
{
	private:
		struct sockaddr_in addr;
		int _socket;
		const short DEFAULT_PORT = 8080;
		const short BUFFER_SIZE = 1024;

	public:
		TcpServer();
		void initialize();
		int accept_client() const;
		std::string read_string(int user_sock) const;
};
