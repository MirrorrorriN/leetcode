class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string sol;
        genParen(sol, 0, 0, n, res);
        return res;
    }
private:
    void genParen(string& sol, int open, int close, int total, vector<string>& res) {
        if (open == total && close == total) {
            res.push_back(sol);
            return;
        }
        if (open < total) {
            sol += '(';
            genParen(sol, open + 1, close, total, res);
            sol.resize(sol.length() - 1);
        }
        if (close < open) {
            sol += ')';
            genParen(sol, open, close + 1, total, res);
            sol.resize(sol.length() - 1);
        }
    }
};