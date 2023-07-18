#include <iostream>

#include "io.h"
#include "main.h"

#include "zmq_addon.hpp"
#include <zmq.hpp>

#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"

#include <asio.hpp>
#include <time.h>

asio::io_context io;
asio::steady_timer t(io, asio::chrono::seconds(5));

// Get current date/time, format is YYYY-MM-DD.HH:mm:ss
const std::string getTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
    // for more information about date/time format
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
}
   
void print(int timeout_period)
{
    std::cout <<  getTime() << ": timer time up after " << timeout_period << " seconds!" << std::endl;
}
 
void reloadtimer()
{
    t.expires_after(std::chrono::seconds(5));
    t.async_wait([](const std::error_code ec) {
    
        if (!ec) {
                print(5);
            } else {
                std::cerr << " timer error!" << std::endl;
            }
            
        // reload the timer
        reloadtimer();
   });
}


int main() {

    std::cout << "Simple Cmake Template...." << std::endl;
    
    std::cout << "Main Module = " << MAIN_MODULE_NAME << std::endl;

    std::cout << "Lib Module  = " << LIB_MODULE_NAME << std::endl;
    
    spdlog::info("Welcome to spdlog!");
    spdlog::error("Some error message with arg: {}", 1);
    spdlog::warn("Easy padding in numbers like {:08d}", 12);
      
    std::cout <<  getTime() <<  ": Wait for 10 seconds... " << std::endl;
    
    reloadtimer();
    
    io.run();
  
 #if 0 
    zmq::context_t ctx;
    zmq::socket_t sock(ctx, zmq::socket_type::push);
    sock.bind("inproc://test");
    sock.send(zmq::str_buffer("Hello, world"), zmq::send_flags::dontwait);
    zmq::context_t context (1);
    zmq::socket_t socket (context, ZMQ_REQ);
    std::cout << "Connecting to hello world server…" << std::endl;
    socket.connect ("tcp://localhost:5555");
  
 
    for (int request_nbr = 0; request_nbr != 10; request_nbr++) {
        zmq::message_t request (5);
        memcpy (request.data (), "Hello", 5);
        std::cout << "Sending Hello " << request_nbr << "…" << std::endl;
        socket.send (request);
        zmq::message_t reply;
        socket.recv (&reply);
        std::cout << "Received World " << request_nbr << std::endl;
    }
#endif

    return 0;
}
