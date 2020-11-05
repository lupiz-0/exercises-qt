#include "tcpserver.h"
#include <iostream>

int main(int argc, char *argv[])
{    
    Q_UNUSED(argc);
    Q_UNUSED(argv);

    TcpServer server;
    if(!server.init())
    {
        std::cerr << "Server initialization fail !!!" << '\n';
        return 1;
    }

    server.run();

    return 0;
}
