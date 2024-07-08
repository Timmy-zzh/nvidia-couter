#include "ZmqServiceCall.h"
#include "json/json.h"

int ZmqServiceCall::sendMsg(std::string param)
{
    log_fmt_error("ZmqServiceCall sendMsg call, param : %s", param);
    // todo something

    // zmq::message_t msg("111",3);
    // send(msg);

    Json::Value root;
    Json::FastWriter json_writer;

    root["cameraType"] = Json::Value("0000");
    root["event"] = Json::Value("eventType1");
    root["data"]["state"] = Json::Value("1111");
    std::string tomsg = json_writer.write(root);
    std::string topic = "topicTest";
    topic += "/";
    topic += "eventType1";
    // m_server->pushMessage(topic, tomsg);

    log_fmt_error("ZmqServiceCall sendMsg call, topic : %s ,tomsg:%s", topic.c_str(), tomsg.c_str());
    log_info << "topic:" << topic << ",tomsg:" << tomsg;
    std::cout << "topic:" << topic << ",tomsg:" << tomsg << std::endl;
    this->getZmqService()->pushMessage(topic, tomsg);

    return 0;
}
