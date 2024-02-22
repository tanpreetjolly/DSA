//brute force
class Solution {
public:

    string removeSpaces(string s){
        s.erase(remove(s.begin(), s.end(), ' '), s.end());
        return s;
    }

    string lowerCase(string s){
        transform(s.begin(), s.end(), s.begin(), ::tolower); 
        return s;
    }

    string removeSpecialCharacter(string s)
    {
        string ans = "";
        for (auto ch : s) {
            if (isalnum(ch))
                ans += ch;
        }
        return ans;
    }
 

    bool isPalindrome(string s) {
        s = removeSpaces(s);
        s = lowerCase(s);
        s= removeSpecialCharacter(s);

        int start = 0, end = s.size()-1;

        while(start<end){
            if(s[start]!=s[end]) return false;
            start++;
            end--;
        }

        return true;
    }
};


//better approach
class Solution{
    public :

    bool isPalindrome(string s){
        int start = 0, end = s.end()-1;
        while(start<=end){
            if(!isalnum(s[start])){ start ++; continue};
            if(!isalnum(s[end])){end--;continue;}
            if(tolower(s[start])!=tolower(s[end]))return false;
           else{
               start++;
               end--;
           }
        }
        return true;
    }

}