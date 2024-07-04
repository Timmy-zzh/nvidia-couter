

#include <iostream>

using namespace std;

class ZmqClient
{
private:
public:
    ZmqClient()
    {
        cout << "ZmqClinet construct call" << endl;
    }
    
    ~ZmqClient(){
         cout << "ZmqClinet vertual construct call" << endl;
    }
};
