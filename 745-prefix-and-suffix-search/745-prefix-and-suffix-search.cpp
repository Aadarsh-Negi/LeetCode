class TrieNode {
public:
    map<int,TrieNode*> children;
    int weight;
     TrieNode() {
        // children = new HashMap();
        weight = 0;
    }
};
class WordFilter {
public:
    TrieNode *trie;
     WordFilter(vector<string> &words) {
        trie = new TrieNode();
        int wt = 0;
        for (string &word: words) {
            TrieNode *cur = trie;
            cur->weight = wt;
            int L = word.size();
            // char[] chars = word.toCharArray();
            for (int i = 0; i < L; ++i) {

                TrieNode *tmp = cur;
                for (int j = i; j < L; ++j) {
                    int code = (word[j] - '`') * 27;
                    if (tmp->children.count(code) == 0)
                        tmp->children[code] =  new TrieNode();
                    tmp = tmp->children[code];
                    tmp->weight = wt;
                }

                tmp = cur;
                for (int k = L - 1 - i; k >= 0; --k) {
                    int code = (word[k] - '`');
                    if (tmp->children.count(code) == 0)
                        tmp->children[code] = new TrieNode();
                    tmp = tmp->children[code];
                    tmp->weight = wt;
                }

                int code = (word[i] - '`') * 27 + (word[L - 1 - i] - '`');
                if (cur->children.count(code) == 0)
                    cur->children[code] = new TrieNode();
                cur = cur->children[code];
                cur->weight = wt;

            }
            wt++;
        }
    }

     int f(string prefix, string suffix) {
        TrieNode *cur = trie;
        int i = 0, j = suffix.length() - 1;
        while (i < prefix.length() || j >= 0) {
            char c1 = i < prefix.length() ? prefix[i] : '`';
            char c2 = j >= 0 ? suffix[j] : '`';
            int code = (c1 - '`') * 27 + (c2 - '`');
            // cur = cur->children[.get(code);]
            if (cur->children.count(code) == 0) return -1;
            cur = cur->children[code];
            i++; j--;
        }
        return cur->weight;
    }
};

