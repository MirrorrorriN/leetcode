// Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:

// Only one letter can be changed at a time
// Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
// Note:

// Return an empty list if there is no such transformation sequence.
// All words have the same length.
// All words contain only lowercase alphabetic characters.
// You may assume no duplicates in the word list.
// You may assume beginWord and endWord are non-empty and are not the same.

#include<string>
#include<queue>
#include<set>
#include<unordered_map>
#include <iostream>
using namespace std;

class Solution
{
private:
    int curMin;
    class Record{
        public:
        string word;
        int steps;
        Record(string word, int steps):word(word),steps(steps)
        {
        }
    };
public:
    vector<vector<string> > findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        curMin=INT_MAX;
        queue<Record> queue;
        set<string> wordSet(wordList.begin(), wordList.end());
        unordered_map<string,vector<string> > preWordMap;
        queue.push(Record(beginWord,0));
        bfs(endWord,wordSet,queue,preWordMap);
        vector<vector<string> > ladders;
        vector<string> ladder;
        ladder.push_back(beginWord);
        dfs(preWordMap,ladders,ladder,beginWord,endWord);
        return ladders;
    }

    void bfs(string endWord, set<string> wordSet, queue<Record> queue,unordered_map<string,vector<string> >& preWordMap)
    {
        vector<string> pre_candidates;
        int pre_steps=0;
        while(!queue.empty()){
            Record curr=queue.front();
            queue.pop();
            if(curr.word.compare(endWord)==0){
                preWordMap[endWord].push_back(curr.word);
                curMin=curr.steps;
                continue;
            }
            if(curr.steps>=curMin){
                return;
            }
            for (int i = 0; i < curr.word.length(); i++)
            {
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    if(pre_steps<curr.steps){
                        for(string preWord:pre_candidates){
                            wordSet.erase(preWord);
                        }
                        pre_candidates.clear();
                        pre_steps+=1;
                    }
                    string newWord=curr.word.substr(0,i)+ch+curr.word.substr(i+1,curr.word.length()-i-1);
                    if(wordSet.count(newWord)!=0){
                        pre_candidates.push_back(newWord);
                        preWordMap[curr.word].push_back(newWord);
                        queue.push(Record(newWord,curr.steps+1));
                    }

                }
            }
        }
    }
};

int main(int argc,char** argv)
{
    string str[]={"hot","dot","dog","lot","log","cog"};
    vector<string> wordList(str,str+6);
	Solution* x=new Solution();
    x->findLadders("hit", "cog", wordList);
    return 0;
}
