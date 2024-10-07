#include <iostream>

#ifdef _WIN32
#define _WIN32_WINNT 0x0A00
#endif
#define ASIO_STANDALONE

#include <asio.hpp>
#include <asio/ts/buffer.hpp>
#include <asio/ts/internet.hpp>

std::vector<char> vBuffer(20 * 1024);

void GrabSomeData(asio::ip::tcp::socket& socket)
{
  socket.async_read_some(asio::buffer(vBuffer.data(), vBuffer.size()),
    [&](std::error_code ec, std::size_t length)
    {
      if (!ec) {
        std::cout << std::format("\n\nRead {} bytes\n\n", length);

        for (int i{}; i < length; ++i) {
          std::cout << vBuffer[i];
        }

        GrabSomeData(socket);
      }
    }
  );
}

int main() {
  asio::error_code ec;

  asio::io_context context;

  asio::io_context::work idleWork(context);

  std::thread thrContext = std::thread([&]() {context.run(); });

  asio::ip::tcp::endpoint endpoint(asio::ip::make_address("93.184.216.34", ec), 80);

  asio::ip::tcp::socket socket(context);

  socket.connect(endpoint, ec);

  if (!ec) {
    std::cout << std::format("Connected!") << std::endl;
  }
  else {
    std::cout << std::format("Failed to connect to address:\n{}!", ec.message()) << std::endl;
  }

  if (socket.is_open()) {
    GrabSomeData(socket);
  
    std::string sRequest =
      "GET /index.html HTTP/1.1\r\n"
      "Host: example.com\r\n"
      "Connection: close\r\n\r\n";

    socket.write_some(asio::buffer(sRequest.data(), sRequest.size()), ec);
  }

  system("pause");
  return 0;
}
