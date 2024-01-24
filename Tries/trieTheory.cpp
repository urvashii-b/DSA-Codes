#include <bits/stdc++.h>
using namespace std;

// TRIE is a tree data structure that locates specific keys within a set.

struct Node{
    Node* links[26];
    bool flag = false;
    bool containsKey(char ch){
        return (links[ch - 'a']!=NULL);
    }
    void put(char ch, Node* temp){
        links[ch - 'a']= temp;
    }
    Node* get(char ch){
        return links[ch - 'a'];
    }
    bool setEnd(){
        flag = true;
    }
};

class Trie{
    private: Node* root;
    public:
        // Initialize your data structure 
        Trie(){
            root = new Node();
        }
        
        // inserts a word into the trie
        void insert(string word){
            Node* temp = root;
            for(int i=0;i<word.length();i++){
                if(!temp->containsKey(word[i])){
                    temp->put(word[i],new Node());
                }
                temp->get(word[i]);
            }
            temp->setEnd();
        }

        // returns if word is in trie
        bool search(string word){

        }

        // returns if there is any word in the trie that starts with the given prefix
        bool startsWith(string prefix){

        }
};

int main() {
    
    return 0;
}
