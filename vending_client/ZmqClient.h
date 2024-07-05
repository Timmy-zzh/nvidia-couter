#ifndef ZMQ_CLIENT_TEST_H_
#define ZMQ_CLIENT_TEST_H_

#include <string>
#include <iostream>
#include "algocc.h"
// #include "zmq/zmqclient.h"

using namespace std;

class ZmqClient : algocc::ZmqRpcClient
{
public:
    ZmqClient(const std::string &clientName = "ZmqTestClient")
        : algocc::ZmqRpcClient(clientName)
    {
        cout << "ZmqClinet construct call" << endl;
        // zmq通信需要用到的文件
        string rep_proto = "ipc:///data/work/audio-hw/req-rep.ipc";
        string req_proto = "ipc:///data/work/hw-audio/req-rep.ipc";
        string pub_proto = "ipc:///data/work/hw-audio/pub-sub.ipc";
        string sub_proto = "ipc:///data/work/audio-hw/pub-sub.ipc";

        connect(rep_proto, "");
    };

    virtual ~ZmqClient(){};

    int play(std::string data);
};

typedef algocc::Singleton<ZmqClient> ZmqClientMgr;
#define GetZmqClientMgr() ZmqClientMgr::GetInstance()
#endif