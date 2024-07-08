#include <iostream>
#include "../vending_client/ZmqClient.h"
#include "logger.h"
#include "util.h"

using namespace std;
#define CAM_VERSION "0.0.1"

int main(int argc, char const *argv[])
{
    cout << "Hello Nvidia" << endl;
    cout << "Hello Nvidia11" << endl;

    log_fmt_info("%s build date: " __DATE__ " ,time:" __TIME__ ", Version: %s", argv[0], CAM_VERSION);

    //ZmqClient *zmqClient = new ZmqClient();

    GetZmqClientMgr()->startTest("/home/yingzi/work-zzh/xxx.wav");

    while (1)
    {
        log_fmt_debug("zmqclient: zmqclient msg");
        algocc::Sleep(10000);
    }

    return 0;
}
