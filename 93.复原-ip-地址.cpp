/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

// @lc code=start
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        len = s.size();
        if(len<4 || len>12) return ans;
        dfs(s, 0, 4, tmp);
        return ans;
    }
private:
    void dfs(string s, int start, int residual, vector<string> temp)
    {
        if(start == len ){
            if(residual == 0){
                ans.push_back( convert(temp) );
            }
            return ;
        }
        
        if( (len-start)>residual*3 || (len-start)<residual )
            return ;

        for(int i=0; i<3; i++){
            if( i+start>len)
                return ;
            int val = isValid(s.substr(start, i+1), i+1);
            if(val!=-1){
                temp.push_back(s.substr(start, i+1));
                dfs(s, start+i+1, residual-1, temp);
                temp.pop_back();
            }
        }
    }

    int isValid(string s, int l)
    {
        if(s[0]=='0' && l>1)
            return -1;
        int res = stoi(s);
        if(res>255)
            res = -1;
        return res;
    }

    string convert(vector<string> temp)
    {
        string res = temp[0];
        for(int i=1; i<temp.size(); i++)
            res+='.'+temp[i];
        return res;
    }

    vector<string> ans;
    vector<string> tmp;

    int len;
};
// @lc code=end

