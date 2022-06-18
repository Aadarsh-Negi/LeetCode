class TrieNode {
public:
    TrieNode *children[27];
    int weight;
     TrieNode() {
        // children = new TrieNode[27];
        for(int i=0;i<27;i++) children[i] = NULL;
        weight = 0;
    }
};
class WordFilter {
public:
    TrieNode *trie;
     WordFilter(vector<string> &words) {
        trie = new TrieNode();
        for (int weight = 0; weight < words.size(); ++weight) {
            string word = words[weight] + "{";
            for (int i = 0; i < word.length(); ++i) {
                TrieNode *cur = trie;
                cur->weight = weight;
                for (int j = i; j < 2 * word.length() - 1; ++j) {
                    int k = word[j % word.length()] - 'a';
                    if (cur->children[k] == NULL)
                        cur->children[k] = new TrieNode();
                    cur = cur->children[k];
                    cur->weight = weight;
                }
            }
        }
    }
     int f(string prefix, string suffix) {
        TrieNode *cur = trie;
        suffix+='{';
        suffix+=prefix;
        for (char &letter:suffix) {
            if (cur->children[letter - 'a'] == NULL) return -1;
            cur = cur->children[letter - 'a'];
        }
        return cur->weight;
    }
};

