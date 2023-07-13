#include <iostream>

#include "io.h"
#include "main.h"

#include "zmq_addon.hpp"
#include <zmq.hpp>
int main() {

    std::cout << "Simple Cmake Template...." << std::endl;
    
    std::cout << "Main Module = " << MAIN_MODULE_NAME << std::endl;

    std::cout << "Lib Module  = " << LIB_MODULE_NAME << std::endl;
    zmq::context_t ctx;
    zmq::socket_t sock(ctx, zmq::socket_type::push);
    sock.bind("inproc://test");
    sock.send(zmq::str_buffer("Hello, world"), zmq::send_flags::dontwait);
    zmq::context_t context (1);
    zmq::socket_t socket (context, ZMQ_REQ);
    std::cout << "Connecting to hello world server�" << std::endl;
    socket.connect ("tcp://localhost:5555");
    for (int request_nbr = 0; request_nbr != 10; request_nbr++) {
        zmq::message_t request (5);
        memcpy (request.data (), "Hello", 5);
        std::cout << "Sending Hello " << request_nbr << "�" << std::endl;
        socket.send (request);
        zmq::message_t reply;
        socket.recv (&reply);
        std::cout << "Received World " << request_nbr << std::endl;
    }
    return 0;
}
