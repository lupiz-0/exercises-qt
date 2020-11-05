#pragma once

class AbstractTcpClientServer
{
public:
    AbstractTcpClientServer() = default;
    virtual ~AbstractTcpClientServer() = default;
    virtual bool init() = 0;
};

