class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        
        //순서대로 username, timestamp, website가 들어간다.
        //map<int, string>으로 배치하여.. 자동으로 timestamp의 정렬이 될것이다.
        unordered_map<string, map<int, string>> um;
        
        //K : 패턴, v : count
        unordered_map<string, int> freq;
        
        //max count
        int maxFreq = 0;
        
        //um 초기화
        //um, username이 같아도 덮어써지지 않는다.(2차원 배열 느낌이므로..)
        for (int i = 0; i < username.size(); i++)
            um[username[i]][timestamp[i]] = website[i];
        
        
        //um, 근데 이걸 아래 for문으로 돌리면 second로 map만 뺄 수 있다.
        //같은 username이면 같은 kv 이다.
        //kv.first는 username, kv.second는 map 배열
        for (auto kv : um)
        {
            unordered_set<string> S;
            
            //tw는 하나의 배열이다. 같은 username을 가진다.
            map<int, string> tw = kv.second; //k : time, v : web
            
            //tw.size() == 4 이면 (h,c,m,h) -> S : (h c m), (h c h), (h m h), (c m h)가 적재됨
            for (auto i = tw.begin(); i != tw.end(); i++)
                for (auto j = next(i); j != tw.end(); j++)
                    for (auto k = next(j); k != tw.end(); k++)
                        S.insert(i->second + " " + j->second + " " + k->second);
            
            //패턴을 카운트하고, max count 값을 maxFreq에 업데이트한다.
            for (auto s : S)
                maxFreq = max(maxFreq, ++freq[s]);
        }

        //정답패턴 적재
        string res;
        
        for (auto kv : freq)//패턴 count map을 순회
            if (kv.second == maxFreq) // max count와 같은 것!
                res = res.empty() ? kv.first : min(kv.first, res); //정답패턴이 현재 empty면 그대로적재, 아니면 사전순으로 앞쪽(min) 패턴을 적재

        vector<string> resVec(3);
        istringstream ss(res); //정답패턴을 빈칸 기준으로 파싱하여 ss에..
        ss >> resVec[0] >> resVec[1] >> resVec[2]; //ss에서 벡터에 적재
        return resVec;
    }
};