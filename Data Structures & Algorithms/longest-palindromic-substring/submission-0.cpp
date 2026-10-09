class Solution {
public:
    string longestPalindrome(string s) {
        int reslen=0;
        int resindx=0;

        for(int i=0;i<s.length();i++){

            //odd length
            int l=i,r=i;
            while(l>=0 && r<s.size() && s[l]==s[r]){
                if(r-l+1 > reslen){
                    reslen=r-l+1;
                    resindx=l;
                }
                l--;
                r++;                
            }

            //even
            l=i;
            r=i+1;
            while(l>=0 && r<s.size() && s[l]==s[r]){
                if(r-l+1 > reslen){
                    reslen=r-l+1;
                    resindx=l;
                }
                l--;
                r++;                
            }
        }
        return s.substr(resindx,reslen);
    }
};
