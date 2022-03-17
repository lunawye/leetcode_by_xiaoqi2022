class LogSystem {
public:
    vector<long long> second = {12*31*24*3600, 31*24*3600, 24*3600, 3600, 60, 1};
    map<string, int> unit = {{"Year",0},{"Month",1},{"Day",2},{"Hour",3},{"Minute",4},{"Second",5}};
    map<int,string>res;
    LogSystem() {

    }
    
    void put(int id, string timestamp) {
        res[id]=timestamp;
    }
    
    long long count_time(string time,string granularity,bool flag)
    {
        int Year=(stoi(time.substr(0,4))-1999);
        int Month=stoi(time.substr(5,2));
        int Day=stoi(time.substr(8,2));
        int Hour=stoi(time.substr(11,2));
        int Minute=stoi(time.substr(14,2));
        int Second=stoi(time.substr(17,2));
        long long t=0;
        vector<int> LogTime={Year,Month,Day,Hour,Minute,Second};
        //将每年每月每天每小时每分钟每秒转为每秒时间
        for(int i=0;i<=unit[granularity];i++)
            t+=LogTime[i]*second[i];
        if(flag==true) t+=second[unit[granularity]]-1;
        //对于某个精度，要加上，如对于精度为年，需要变成2017:12:31:24:59:59=2017+1year-1s
        //每个月每天可以减1再乘秒数，因为每个月每天没有从0开始的，都是从1开始，此处不减计算答案也正确
        return t;
        
    }
    vector<int> retrieve(string start, string end, string granularity) {
        long long start_time=count_time(start,granularity,false);
        long long end_time=count_time(end,granularity,true);
        vector<int> ans;
        for(auto i=res.begin();i!=res.end();i++)
        {
            int t=count_time(i->second,granularity,false);
            if(start_time<=t&&t<=end_time) ans.push_back(i->first);
        }
        return ans;

    }
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem* obj = new LogSystem();
 * obj->put(id,timestamp);
 * vector<int> param_2 = obj->retrieve(start,end,granularity);
 */