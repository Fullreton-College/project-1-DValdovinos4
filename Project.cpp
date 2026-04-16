#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void getWords(vector<string> &words, ifstream &file);
void sortWords(vector<string> &words);
vector<pair<string, int>> getWordCounts(vector<string> &words);
void printWordCount(vector<pair<string, int>> &wordCount);

int main() 
{
    ifstream file("holmes.txt");
    if (!file) {
        cout<<" File could not open "<<endl;
    return 1;
    }
    vector<string> words;
    getWords(words,file);
    sortWords(words);

    vector<pair<string, int>> wordCount= getWordCounts(words);
    printWordCount(wordCount);

    file.close();
   
    return 0;
}
void getWords(vector<string> &words, ifstream &file)
{
    string word;
    while(file>>word)
    {
        string clean_words;
        for (char C:word)
{
    if(isalpha(C))
    {
        clean_words += tolower(C);
    }
}
    if(!clean_words.empty()){
        words.push_back(clean_words);
    }
    }
}
void sortWords(vector<string> &words)
{
    sort(words.begin(), words.end());
}
vector<pair<string, int>> getWordCounts(vector<string> &words)
{
    vector<pair<string, int>> wordCount;
    if(words.empty())
    {
        return wordCount;
    }

    for(int i= 0; i<words.size(); i++)
    {
        if(i==0 || words[i]!=words[i-1]){
        pair<string, int>count;
        count.first= words[i];
        count.second=1;
        wordCount.push_back(count);
    }else{
        wordCount.back().second++;

    }
    }
    return wordCount;
}
void printWordCount(vector<pair<string, int>> &wordCount)
{
    for(int i=0; i<wordCount.size(); i++)
    {
        cout<<wordCount[i].first<<":"<<wordCount[i].second<<endl;
    }
}
