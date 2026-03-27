#include"Trie.hpp"
#include<string>
#include<cctype>
#include<vector>
#include<iostream>

Trie::Trie()
{
    root = new TrieNode();
}

void Trie::insert(const std::string& s)
{
    TrieNode* cur = root;
    for(char c : s)
    {
        if (!isalpha(c))
        {
            continue;
        }
        int i = tolower(c) - 'a';
        if(!cur->children[i])
        {
            cur->children[i] = new TrieNode();
        }
        cur = cur->children[i];
    }
    cur->end_of_word = true;
}

bool Trie::search(const std::string& s) const
{
    TrieNode* cur = root;

    for(char c : s)
    {
        int i = tolower(c) - 'a';
        if(!cur->children[i])
        {
            return false;
        }
        cur = cur->children[i];
    }
    return cur->end_of_word;
}

void Trie::print() const
{
    std::string word;
    print(root, word);
}

void Trie::print(const TrieNode* node, std::string& word) const
{
    if (!node)
    {
        return;
    }
    if (node->end_of_word)
    {
        std::cout << word << std::endl;
    }

    //Check all children
    //If chilld exist
        //add character to the end of the word
        //recurison
        //remove the last character from the word

    for(TrieNode* c : cur)
    {
        
    }
}

Trie::Trie(std::vector<std::string>& v)
{
    
}