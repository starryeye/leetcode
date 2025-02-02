class Solution {
public:
    string reverseWords(string s) {
        
        // 앞/뒤 문자 시작 인덱스 구하기
        int left = 0;
        int right = s.size() - 1;
        while (left <= right && s[left] == ' ')
            ++left;
        while (left <= right && s[right] == ' ')
            --right;
        
        // stack 에 왼쪽 단어부터 집어 넣는다.
        stack<string> st;
        string temp_word;
        while (left <= right) {
            if (s[left] == ' ' && !temp_word.empty()) {
                st.push(temp_word);
                temp_word.clear();
            } else if (s[left] != ' ') {
                temp_word += s[left];
            }
            ++left;
        }
        st.push(temp_word);

        // 답 만들기
        string answer = "";
        while (!st.empty()) {
            
            answer += st.top(); // 집어넣은 것을 역으로 꺼내서 답을 만든다.
            st.pop();

            if (!st.empty()) {
                answer += " "; // 단어 사이 띄어쓰기
            }
        }

        return answer;
    }
};