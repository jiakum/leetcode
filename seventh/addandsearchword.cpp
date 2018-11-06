
class WordDictionary {
#define DICTIONARY_SIZE (26)
    struct dictionary {
        int flag;
        struct dictionary *children[DICTIONARY_SIZE];
        dictionary(int f = 0) : flag(f) {
            for(int i = 0;i < DICTIONARY_SIZE;i++)
                children[i] = NULL;
        }
    };
    struct dictionary *head;
    public:
    /** Initialize your data structure here. */
    WordDictionary() {
        head = new dictionary(0);
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        dictionary *dict = head;
        for(int i = 0;i < word.size();i++) {
            char c = word[i];
            int index = c - 'a';

            if(index < 0 || index >= DICTIONARY_SIZE)
                return;

            if(dict->children[index] == NULL)  {
                dict->children[index] = new dictionary();
            }

            dict = dict->children[index];
        }

        dict->flag = 1;
    }

    bool sub_search(dictionary *dict, string word) {
        for(int i = 0;i < word.size();i++) {
            char c = word[i];
            int index = c - 'a';

            if(index < 0 || index >= DICTIONARY_SIZE) {
                for(int j = 0;j < DICTIONARY_SIZE;j++) {
                    if(dict->children[j] && 
                            sub_search(dict->children[j], word.substr(i + 1, word.size() - i)))
                        return true;
                }
                return false;
            }

            if(dict->children[index] == NULL)  {
                return false;
            }

            dict = dict->children[index];
        }

        return dict->flag == 1;
    }
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return sub_search(head, word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
