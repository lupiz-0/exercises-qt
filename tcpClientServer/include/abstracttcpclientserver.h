#pragma once

class AbstractTcpClientServer
{
public:
    AbstractTcpClientServer() = default;
    virtual ~AbstractTcpClientServer() = default;
    virtual bool init() = 0;
    void run();

protected:
    virtual bool update() = 0;

    static constexpr int BUFFER_SIZE = 256;
    char m_buffer[BUFFER_SIZE];
};

