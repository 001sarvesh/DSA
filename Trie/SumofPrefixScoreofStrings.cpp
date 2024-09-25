class Solution {
public:
    struct trieNode {
        int countP = 0;
        trieNode* children[26];
    };

    trieNode* gettrieNode() {
        trieNode* newNode = new trieNode();
        for (int i = 0; i < 26; i++) {
            newNode->children[i] = nullptr;
        }
        newNode->countP = 0;
        return newNode;
    }

    void insert(string &word, trieNode* root) {
        trieNode* crawl = root;

        for(char &ch: word) {
            int idx = ch - 'a';

            if(!crawl->children[idx]) {
                crawl->children[idx] = gettrieNode();
            }
            crawl->children[idx]->countP += 1; // Increment countP for prefix
            crawl = crawl->children[idx];
        }
    }

    int getScore(string &word, trieNode* root) {
        trieNode* crawl = root;
        int score = 0;

        for (char &ch: word) {
            int idx = ch - 'a';
            score += crawl->children[idx]->countP; // Add prefix count to score

            crawl = crawl->children[idx]; // Move to the next node
        }
        return score;
    }

    vector<int> sumPrefixScores(vector<string>& words) {
        int n = words.size();
        trieNode *root = gettrieNode();
        
        // Insert all words into the trie
        for(string &word: words) {
            insert(word, root);
        }
        
        vector<int> result(n);
        
        // Calculate score for each word
        for(int i = 0; i < n; i++) {
            result[i] = getScore(words[i], root);
        }
        
        return result;
    }
};
