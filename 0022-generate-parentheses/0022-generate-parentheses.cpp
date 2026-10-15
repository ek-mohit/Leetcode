class Solution {
    void backtrack(int n, int open, int close,
                   string& path, vector<string>& answer) {
        if (path.size() == static_cast<size_t>(2 * n)) {
            answer.push_back(path);
            return;
        }

        if (open < n) {
            path.push_back('(');
            backtrack(n, open + 1, close, path, answer);
            path.pop_back();
        }

        if (close < open) {
            path.push_back(')');
            backtrack(n, open, close + 1, path, answer);
            path.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> answer;
        string path;
        backtrack(n, 0, 0, path, answer);
        return answer;
    }
};