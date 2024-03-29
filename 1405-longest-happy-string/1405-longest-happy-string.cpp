class Solution {
public:

    string longestDiverseString(int a, int b, int c) {
        
        //using max heap
        priority_queue<pair<int,char>> pq;
        
        if(a)
            pq.push({a,'a'});
        
        if(b)
            pq.push({b,'b'});
        
        if(c)
            pq.push({c,'c'});
        
        string ans="";
        
        while(pq.size() > 1) { //char 한개 남거나 하나도 안남을때.. 탈출
            
            pair<int,char> one = pq.top();
            pq.pop();
            
            pair<int,char> two = pq.top();
            pq.pop();
            
            if(one.first >= 2){
                ans+=one.second;
                ans+=one.second;
                one.first-=2;
            }else {
                ans+=one.second;
                one.first-=1;
            }
            
            if(two.first >= 2 && two.first >= one.first) { //two개수가 one개수를 역전할 만큼 많으면 두개씩 사용
                ans+=two.second;
                ans+=two.second;
                two.first-=2;
            }else {
                ans+=two.second;
                two.first-=1;
            }
            
            if(one.first>0)
                pq.push(one);
            
            if(two.first>0)
                pq.push(two);
            
        }
        
        if(pq.empty())
            return ans;
        
        if(pq.top().first >= 2){
            ans+=pq.top().second;
            ans+=pq.top().second;
        }else {
            ans+=pq.top().second;
        }
        
        return ans;
        
        
    }
};