#include "tcpclient.h"
#include <iostream>
#include <cstring>

bool argvContains(int argc, char *argv[], const char* string) {
    for(int i = 0; i < argc; i++) {
        if(std::strcmp(argv[i], string) == 0)
            return true;
    }
    return false;
}

int main(int argc, char *argv[])
{    
    Q_UNUSED(argc);
    Q_UNUSED(argv);

    TcpClient client;
    if(argvContains(argc, argv, "--only-init"))
        client.setOnlyInit(true);
    if(!client.init())
    {
        std::cerr << "Client initialization fail !!!" << '\n';
        return 1;
    }

    client.run();

    return 0;
}
