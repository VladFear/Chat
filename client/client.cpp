#include "client.hpp"

TcpClient::TcpClient()
{
	std::cout << "Created Tcp client.\n";
}

void TcpClient::create_socket(const int server_port)
{
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(server_port);

	if ((_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		throw std::runtime_error(strerror(errno));

	std::string localhost = "127.0.0.1";
	if (inet_pton(AF_INET, localhost.c_str(), &serv_addr.sin_addr) <= 0)
		throw std::runtime_error(strerror(errno));

	std::cout << "Successfully created socket." << std::endl;
}

void TcpClient::connect_server() const
{
	if (connect(_socket, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0)
		throw std::runtime_error(strerror(errno));

	std::cout << "Successfully connected to server." << std::endl;
}

int TcpClient::send_data(std::string s) const
{
	send(_socket, s.c_str(), s.size() + 1, 0);
	std::cout << "Sent!" << std::endl;
	return 0;
}

int main(int argc, char** argv)
{
	TcpClient client;
	try
	{
		client.create_socket(8080);
		client.connect_server();
		client.send_data("hui");
	}
	catch (const std::exception& e)
	{
		std::cerr << "Failed due to exception: " << e.what() << std::endl;
		exit(EXIT_FAILURE);
	}

	return EXIT_SUCCESS;
}
