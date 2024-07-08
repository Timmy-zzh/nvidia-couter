#include "ZmqClient.h"

int ZmqClient::startTest(std::string data)
{
    log_info << __func__ << " enter...";

    algocc::Result<int> ret = callFunc<int>("starttest", data);

    if (ret.valid())
    {
        return ret.val();
    }
    else
    {
        return -1;
    }
}