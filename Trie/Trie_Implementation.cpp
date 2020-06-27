#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
    struct TrieNode *children[26];
    bool isEndofWord;
};

struct TrieNode *getNode(void)
{
    struct TrieNode *pNode = new TrieNode;
    pNode->isEndofWord = false;
    for (int i = 0; i < 26; i++)
    {
        pNode->children[i] = NULL;
    }
    return pNode;
}

void insert(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
        {
            pCrawl->children[index] = getNode();
        }
        pCrawl = pCrawl->children[index];
    }
    pCrawl->isEndofWord = true;
}

bool search(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
        {
            return false;
        }
        pCrawl = pCrawl->children[index];
    }
    return (pCrawl != NULL && pCrawl->isEndofWord);
}

bool isEmpty(TrieNode *root)
{
    for (int i = 0; i < 26; i++)
        if (root->children[i])
            return false;
    return true;
}

TrieNode *remove(TrieNode *root, string key, int depth = 0)
{
    if (!root)
        return NULL;
    if (depth == key.size())
    {
        if (root->isEndofWord)
            root->isEndofWord = false;
        if (isEmpty(root))
        {
            delete (root);
            root = NULL;
        }
        return root;
    }

    // If not last character, recur for the child
    // obtained using ASCII value
    int index = key[depth] - 'a';
    root->children[index] = remove(root->children[index], key, depth + 1);

    // If root does not have any child (its only child got
    // deleted), and it is not end of another word.
    if (isEmpty(root) && root->isEndofWord == false)
    {
        delete (root);
        root = NULL;
    }
    return root;
}

int main()
{

    string keys[] = {"the", "a", "there",
                     "answer", "any", "by",
                     "bye", "their", "hero", "heroplane"};
    int n = sizeof(keys) / sizeof(keys[0]);

    struct TrieNode *root = getNode();

    // Construct trie
    for (int i = 0; i < n; i++)
        insert(root, keys[i]);

    // Search for different keys
    search(root, "the") ? cout << "Yes\n" : cout << "No\n";
    search(root, "these") ? cout << "Yes\n" : cout << "No\n";

    remove(root, "heroplane");
    search(root, "hero") ? cout << "Yes\n" : cout << "No\n";
    return 0;
}