class Solution {
public:
    string simplifyPath(string path) {
        
        vector<string> stack;

        stringstream ss(path);
        string temp;

        while (getline(ss, temp, '/')) {

            if (temp == "..") {
                if (!stack.empty()) {
                    stack.pop_back();
                }
            } else if (temp != "." && !temp.empty()) {
                stack.push_back(temp);
            }
        }

        string answer = "";
        for (auto e : stack) {
            answer += "/" + e;
        }

        if (answer.empty()) {
            return "/";
        } else {
            return answer;
        }
    }
};