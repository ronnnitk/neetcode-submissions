class Solution {
    /**
     * @param {number} x
     * @return {boolean}
     */
    isPalindrome(x) {
        if(x<0) return false;

        let div=1;
        while(x>=10*div){
            div*=10
        }

        while(x!=0){
            if(Math.floor(x/div)!=x%10) return false;
            x=Math.floor((x%div)/10);
        div=Math.floor(div/100);
        }
        return true;
    }
}
