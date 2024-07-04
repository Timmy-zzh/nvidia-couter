#include <iostream>
#include "./vending_client/ZmqClient.h"
#include "logger.h"

using namespace std;
#define CAM_VERSION  "0.0.1"

int main(int argc, char const *argv[])
{
    cout << "Hello Nvidia" << endl;
    cout << "Hello Nvidia11" << endl;

   log_fmt_info("%s build date: " __DATE__ " ,time:" __TIME__ ", Version: %s", argv[0], CAM_VERSION);

   log_fmt_debug("aljdflkja");

//    log_err << "123";

   log_fmt_error("ladjflka");

    ZmqClient *zmqClient = new ZmqClient();

    return 0;
}
