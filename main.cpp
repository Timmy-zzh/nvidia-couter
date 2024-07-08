#include <iostream>
#include "vending_service/ZmqServiceDemo.h"
#include "vending_service/ZmqServiceCall.h"
#include "zmq/zmqserver.h"

using namespace algocc;
using namespace std;
#define CAM_VERSION "0.0.1"

static ZmqRpcServer g_server;

static void init_server_zmq(void)
{
    std::string rep_proto = "ipc:///data/work/counter-hw/req-rep.ipc";
    std::string req_proto = "ipc:///data/work/hw-counter/req-rep.ipc";
    std::string pub_proto = "ipc:///data/work/hw-counter/pub-sub.ipc";
    std::string sub_proto = "ipc:///data/work/counter-hw/pub-sub.ipc";

    g_server.registerFunc("starttest", &ZmqServiceDemo::startTest);
    g_server.registerFunc("feedback", &ZmqServiceDemo::feedback);

    g_server.bind(rep_proto, sub_proto);

    g_server.start();
}

int main(int argc, char const *argv[])
{
    cout << "Hello Nvidia" << endl;
    cout << "Hello Nvidia11" << endl;

    log_fmt_info("%s build date: " __DATE__ " ,time:" __TIME__ ", Version: %s", argv[0], CAM_VERSION);

    log_fmt_debug("aljdflkja");

    init_server_zmq();

    //    log_err << "123";
    GetZmqServiceCallMgr()->setZmqService(&g_server);

    log_fmt_error("ladjflka");
    GetZmqServiceMgr()->init();

    static int count = 0;

    while (1)
    {
        count++;
        // if (count == 2)
        // {
        //     GetZmqServiceCallMgr()->sendMsg("lajdlfakd");
        // }

        log_fmt_debug("zmq service: zmqservice msg");
        //algocc::Sleep(10000);
        g_server.popWaitMessage();
    }

    return 0;
}
