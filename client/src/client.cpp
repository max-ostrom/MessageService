#include <boost/asio.hpp>

#include <iostream>

#define PORT_NUMBER 20565
#define SERVER_IP_ADRESS_STR "127.0.0.1"
using namespace boost::asio::ip;
int main(int argc, char* argv[])
{
	try
	{
		const boost::asio::ip::address addr = address::from_string(SERVER_IP_ADRESS_STR);
		tcp::endpoint endPoint(addr, PORT_NUMBER);
		boost::asio::io_context io_context;

		tcp::resolver resolver(io_context);
		tcp::resolver::results_type endpoints = resolver.resolve(endPoint);
		tcp::socket socket(io_context);
		boost::asio::connect(socket, endpoints);

		while (true)
		{
			std::array<char, 128> buf;
			boost::system::error_code error;

			size_t len = socket.read_some(boost::asio::buffer(buf), error);
			if (error == boost::asio::error::eof) {
				break;
			}
			else if (error) {
				throw boost::system::system_error(error);
			}

			std::cout.write(buf.data(), len);
		}
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}