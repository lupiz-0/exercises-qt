#include "abstracttcpclientserver.h"

void AbstractTcpClientServer::run() {
    while(update()) {}
}

