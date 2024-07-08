#ifndef ZMQ_SERVICE_DEMO_H_
#define ZMQ_SERVICE_DEMO_H_

#include "algocc.h"
#include <string>
#include <iostream>
/**
 * zmq服务端，等待客户端client调用
 * 1、做好zmq的底层通信连接参数设置
 * 2、然后等待客户端来调用
 * 3、拿到数据后，进行处理再回复出去
 */

class ZmqServiceDemo
{
private:
    /* data */
public:
    /**
     * 构造函数
     * 1、绑定服务zmq,  bind
     * 2、注册方法调用： registerFunc
     * 3、如果绑定了订阅服务，需要开启线程：start
     */
    ZmqServiceDemo()
    {
    }

    friend algocc::ZmqRpcServer;

    // 虚函数
    virtual ~ZmqServiceDemo() {}

    static int startTest(std::string param); // 接收数据

    static int feedback(std::string data); // 返回数据

    void init(){cout << "ZmqClinet init call" << endl;}
};

// 定义单例
typedef algocc::Singleton<ZmqServiceDemo> ZmqServiceMgr;
#define GetZmqServiceMgr() ZmqServiceMgr::GetInstance()

#endif