class Solution {
public:
    string breakPalindrome(string palindrome) {
        
        //no way to replace a character to make it not a palindrome, return an empty string.
        if(palindrome.size() <= 1)
            return "";
        
        for(int i = 0; i < palindrome.size() / 2; i++) {
            
            if(palindrome[i] != 'a') {
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        
        palindrome[palindrome.size() - 1] = 'b';
        
        return palindrome;
    }
};