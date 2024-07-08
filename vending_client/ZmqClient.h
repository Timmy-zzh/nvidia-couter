#ifndef ZMQ_CLIENT_TEST_H_
#define ZMQ_CLIENT_TEST_H_

#include <string>
#include <iostream>
#include "algocc.h"
#include "zmq/zmqclient.h"

using namespace std;

/**
 * zmq客户端实现类：
 * 1、与服务链接： connect
 * 2、订阅服务端主题topic：subscribe
 * 3、注册该主题下得事件： registerEvent
 * 4、开启线程运行：start
 */
class ZmqClient : algocc::ZmqRpcClient
{
public:
    ZmqClient(const std::string &clientName = "ZmqClientTest")
        : algocc::ZmqRpcClient(clientName)
    {
        cout << "ZmqClinet construct call" << endl;
        // zmq通信需要用到的文件
        std::string rep_proto = "ipc:///data/work/counter-hw/req-rep.ipc"; // 请求
        std::string req_proto = "ipc:///data/work/hw-counter/req-rep.ipc";
        std::string pub_proto = "ipc:///data/work/hw-counter/pub-sub.ipc";
        std::string sub_proto = "ipc:///data/work/counter-hw/pub-sub.ipc"; // 订阅

        registerEvent("eventType1", [](const std::string &msg)
                      {
                        std::cout << "registerEvent msg:" << msg << std::endl;
                          log_fmt_debug("registerEvent msg:%s", msg); });

        connect(rep_proto, sub_proto);

        // 订阅主题
        subscribe("topicTest");
        start();
    };

    virtual ~ZmqClient(){};

    int startTest(std::string data);
};

typedef algocc::Singleton<ZmqClient> ZmqClientMgr;
#define GetZmqClientMgr() ZmqClientMgr::GetInstance()
#endif