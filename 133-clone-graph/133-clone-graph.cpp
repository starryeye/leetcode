/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) 
    {
        
        if (!node) {
            return NULL;
        }
        
        //최초, {}은 Null이 아니라 빈 벡터
        Node* copy = new Node(node -> val, {});
        check[node] = copy;
        
        queue<Node*> que;
        que.push(node);
        
        while (!que.empty()) 
        {
            Node* cur = que.front();
            que.pop();
            
            for (Node* neighbor : cur -> neighbors) 
            {
                
                if (check.find(neighbor) == check.end()) //있으면 방문했다는 의미 + 다음으로 갈필요가 없음
                {//neighbor에 해당되는 해시 key값이 없다면
                    check[neighbor] = new Node(neighbor -> val, {});
                    que.push(neighbor);
                }
                
                //현재 노드에서 다음 노드로의 연결(one-way), 다음 큐에서 two-way
                check[cur] -> neighbors.push_back(check[neighbor]);
            }
        }
        
        return copy;
    }
    
private:
    // check 용도로 사용한다
    // key는 해시값으로 변환되어 사용된다.
    // origin의 주소가 key이며, copy의 주소값이 value 이다.
    unordered_map<Node*, Node*> check;
};