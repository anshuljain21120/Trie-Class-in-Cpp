#include<unordered_map>
#include<string>

class Trie{

private:
    bool isLeaf;
    std::unordered_map<char, Trie* > umap;

public:
    Trie(bool isLeaf=false){
        // Constructor

        this->isLeaf=isLeaf;
        this->umap.clear();
    }

    void insert(std::string s){
        // inserts string starting from this Node

        if(s.empty())
            return;
        
        Trie *ptr=this;
        for(unsigned long long int i=0; i<s.size(); i++)
        {
            char c=s.at(i);
            bool cExists=(ptr->umap.find(c)!=ptr->umap.end());
            
            if(!cExists)
                ptr->umap[c] = new Trie();

            ptr = ptr->umap[c];
        }
        ptr->isLeaf=true;
    }

    bool hasString(std::string s){
        // True if Trie Node has string s

        Trie *ptr=this;
        for(unsigned long long int i=0; i<s.size(); i++)
        {
            char c=s.at(i);
            bool cExists=(ptr->umap.find(c)!=ptr->umap.end());
            
            if(!cExists)
                return false;

            ptr = ptr->umap[c];
        }
        return ptr->isLeaf;
    }

    bool hasChildren(){
        // True if Trie Node has children

        for (auto it : this->umap){
            if (it.second != NULL)
                return true;
        }
        return false;
    }

    ~Trie(){
        this->umap.clear();
    }
};
