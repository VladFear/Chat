#include "server.hpp"

TcpServer::TcpServer()
{
	std::cout << "Created Tcp server." << std::endl;
}

void TcpServer::initialize()
{
	int opt = 1;
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = INADDR_ANY;
	addr.sin_port = htons(DEFAULT_PORT);

	if ((_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		throw std::runtime_error(strerror(errno));

	if (setsockopt(_socket, SOL_SOCKET,
				SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
		throw std::runtime_error(strerror(errno));

	if (bind(_socket, (struct sockaddr*)&addr, sizeof(addr)) < 0)
		throw std::runtime_error(strerror(errno));

	if (listen(_socket, 5))
		throw std::runtime_error(strerror(errno));

	std::cout << "Successfully initialized!" << std::endl;
}

int TcpServer::accept_client() const
{
	int len = sizeof(addr);
	int user_socket = accept(_socket, (struct sockaddr*)&addr, (socklen_t*)&len);
	if (user_socket < 0)
		throw std::runtime_error(strerror(errno));

	std::cout << "Accepted client!" << std::endl;
	return user_socket;
}

std::string TcpServer::read_string(int user_sock) const
{
	char buffer[BUFFER_SIZE];
	if (read(user_sock, buffer, BUFFER_SIZE) < 0)
		throw std::runtime_error(strerror(errno));

	return std::string(buffer);
}

int main(int argc, char** argv)
{
	TcpServer server;
	try
	{
		server.initialize();

		while (true)
		{
			int user_socket = server.accept_client();
			std::cout << "Message: " << server.read_string(user_socket) << std::endl;
			std::cout << std::endl;
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << "Failed due to exception: " << e.what() << std::endl;
		exit(EXIT_FAILURE);
	}

	return EXIT_SUCCESS;
}
