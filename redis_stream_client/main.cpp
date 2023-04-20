#include "redis_tool.hpp"

using namespace std;

int main(int argc,const char *argv[])
{
    string id;
    map<string,string> field_string_map;
    int ret = 0;

    RedisTool redisTool("127.0.0.1",6379);
    redisTool.Connect();
    while(1)
    {
        ret = redisTool.XgroupRead("mystream","mygroup","consumer2",id,field_string_map,1,">");
        if(1 == ret)
        {
            ret = redisTool.XACK("mystream","mygroup",field_string_map["delivered_id"]);
            if(1 == ret)
            {
                cout << "XACK id:" << id << " successfully" << endl;
            }
        }
        
    }
    

    
    redisTool.Close();

    return 0;
    

}