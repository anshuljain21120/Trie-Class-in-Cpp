#include<unordered_map>
#include<string>

class TrieNode {
public:
    bool isLeaf;
    unordered_map<char, TrieNode*> umap;
    TrieNode(bool isLeaf=false) {
        this->isLeaf=isLeaf;
        this->umap.clear();
    }
    
    ~TrieNode() {
        umap.clear();
    }
};

class Trie {
private:
    TrieNode* root;
public:
    Trie(bool isLeaf=false) {
        root = new TrieNode(isLeaf);
    }
    
    void insert(string s) {
        if(s.empty()) return;
        
        TrieNode *ptr=root;
        for(int i=0; i<s.size(); i++)
        {
            char c=s.at(i);
            bool cExists=(ptr->umap.find(c)!=ptr->umap.end());
            
            if(!cExists) ptr->umap[c] = new TrieNode();
            ptr = ptr->umap[c];
        }
        ptr->isLeaf = true;
    }
    
    bool search(string s) {
        TrieNode *ptr = root;
        for(int i=0; i<s.size(); i++)
        {
            char c=s.at(i);
            bool cExists=(ptr->umap.find(c)!=ptr->umap.end());
            
            if(!cExists) return false;
            ptr = ptr->umap[c];
        }
        return ptr->isLeaf;
    }
    
    bool startsWith(string s) {
        TrieNode *ptr=root;
        for(int i=0; i<s.size(); i++)
        {
            char c=s.at(i);
            bool cExists=(ptr->umap.find(c)!=ptr->umap.end());
            
            if(!cExists) return false;
            ptr = ptr->umap[c];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
