/**在经过几次自我思路纠正后，基本的算法复杂度已经控制住了，但仍然timeout
 * 最终是通过一些小修改以及修改set为unordered_set达到AC
 * 使用标准库函数时也要注意其背后实现复杂度
**/
#include<string>
#include<queue>
#include<unordered_set>
#include<unordered_map>
#include <iostream>
using namespace std;

class Solution
{
private:
    int curMin;
public:
    vector<vector<string> > findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        curMin=INT_MAX;
        queue<vector<string> > queue;
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        vector<vector<string> > ladders;
        if(wordSet.count(endWord)==0){
            return ladders;
        }
        vector<string> ladder;
        ladder.push_back(beginWord);
        queue.push(ladder);
        bfs(endWord,wordSet,ladders,queue);
        return ladders;
    }

    void bfs(string endWord, unordered_set<string>& wordSet, vector<vector<string> >& ladders,
    queue<vector<string> >& queue)
    {
        unordered_set<string> pre_candidates;
        int pre_steps=1;
        while(!queue.empty()){
            vector<string> curr=queue.front();
            queue.pop();
            if(curr.size()>=this->curMin){
                return;
            }
            if(pre_steps<curr.size()){
                for(string preWord:pre_candidates){
                    wordSet.erase(preWord);
                }
                pre_candidates.clear();
                pre_steps=curr.size();
            }
            string last=curr.back();
            for (int i = 0; i < curr.back().length(); i++)
            {
                string newWord=last;
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    newWord[i]=ch;
                    if(wordSet.count(newWord)!=0){
                        pre_candidates.insert(newWord);
                        vector<string> next=curr;
                        next.push_back(newWord);
                        if(newWord==endWord){
                            ladders.push_back(next);
                            this->curMin=next.size();
                        }else{
                            queue.push(next);
                        }
                    }

                }
            }
        }
    }
};