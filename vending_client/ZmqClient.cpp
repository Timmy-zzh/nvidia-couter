#include "ZmqClient.h"

int ZmqClient::play(std::string data)
{
    log_info << __func__ << "enter...";

    algocc::Result<int> ret = callFunc<int>("play", data);

    if (ret.valid())
    {
        return ret.val();
    }
    else
    {
        return -1;
    }
}