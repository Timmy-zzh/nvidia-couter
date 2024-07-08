#ifndef ZMQ_SERVICE_CALL_H_
#define ZMQ_SERVICE_CALL_H_

#include "algocc.h"
#include <string>
#include <iostream>
// #include "ZmqServiceDemo.h"
#include "zmq/zmqserver.h"

using namespace algocc;
/**
 * 服务端消息回复类：
 * 1、持有zmq服务对象
 * 2、当需要发送发布消息时，通过内部持有得zmqservice服务类，调用 pushMessage方法
 */
class ZmqServiceCall
{
public:
    /**
     * 构造函数
     * 1、绑定服务zmq,  bind
     * 2、注册方法调用： re
     */
    ZmqServiceCall() {}

    // 虚函数
    virtual ~ZmqServiceCall() {}

    void setZmqService(ZmqRpcServer *server)
    {
        this->mZmqServer = server;
    }

    ZmqRpcServer *getZmqService()
    {
        return this->mZmqServer;
    }

    int sendMsg(std::string param); // 接收数据

private:
    ZmqRpcServer *mZmqServer;
};

// 定义单例
typedef algocc::Singleton<ZmqServiceCall> ZmqServiceCallMgr;
#define GetZmqServiceCallMgr() ZmqServiceCallMgr::GetInstance()

#endif