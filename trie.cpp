#include <bits/stdc++.h>
using namespace std;
class Trie{
    Trie *child[26];
    bool isEnd;
    public:
        Trie()
        {
            memset(child, 0, sizeof(child));
            isEnd = false;
        }
        Trie *getChild(Trie *root, int ind)
        {
            if(root->child[ind] == NULL)
                return NULL;
            else
            {
                return root->child[ind];
            }
            
        }
        bool checkEnd(Trie *root, int ind)
        {
            return root->isEnd;
        }
        void assignChild(Trie *root, int ind)
        {
            root->child[ind] = new Trie();
        }
        void setEnd(bool val)
        {
            isEnd = val;
        }
        bool getEnd()
        {
            return isEnd;
        }
};
void insert(Trie *root, string word)
{
    Trie *curr = root;
    for(char ch:word)
    {
        int ind = ch -'a';
        if(curr->getChild(curr, ind) == NULL)
            curr->assignChild(curr, ind);
        curr = curr->getChild(curr, ind);
    }
    curr->setEnd(true);
}
bool search(Trie *root, string word)
{
    Trie *curr = root;
    for(char ch:word)
    {
        int ind = ch - 'a';
        if(curr->getChild(curr, ind) == NULL)
            return false;
        curr = curr->getChild(curr, ind);
    }
    return curr->getEnd();
}
int main()
{
    int n;
    cout<<"Enter value for n... ";
    Trie *root = new Trie();
    cin>>n;
    cout<<"Enter n strings...\n";
    while(n--)
    {
        string str;
        cin>>str;
        insert(root, str);
    }
    cout<<"Insertion successful!\n";
    cout<<"Enter n for strings to search...\n";
    cin>>n;
    while(n--)
    {
        string str;
        cin>>str;
        if(search(root, str))
            cout<<str<<" found!\n";
        else
        {
            cout<<str<<" not found!\n";
        }
    }
    return 0;
}