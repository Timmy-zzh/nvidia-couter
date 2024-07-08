#include "ZmqServiceDemo.h"
#include "ZmqServiceCall.h"
#include "algocc.h"

int ZmqServiceDemo::startTest(std::string param)
{
    log_fmt_error("zmqservice start call, param : %s", param);

    // todo something -- sleep(10000) 模拟耗时操作

    // Sleep(2000);
    GetZmqServiceCallMgr()->sendMsg("lajdlfakd");

    return 0;
}

int ZmqServiceDemo::feedback(std::string data)
{
    log_fmt_info("zmqservice feedback param:%s", data);

    return 0;
}
