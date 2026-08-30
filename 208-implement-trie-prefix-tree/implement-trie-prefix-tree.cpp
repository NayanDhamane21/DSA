class Trie {
    struct Node {
        Node* ch[26] = {};
        bool end = false;
    };
    Node* root;
public:
    Trie() : root(new Node()) {}
    void insert(string word) {
        auto node = root;
        for (char c : word) {
            if (!node->ch[c - 'a']) node->ch[c - 'a'] = new Node();
            node = node->ch[c - 'a'];
        }
        node->end = true;
    }
    bool search(string word) {
        auto node = find(word);
        return node && node->end;
    }
    bool startsWith(string prefix) {
        return find(prefix) != nullptr;
    }
    Node* find(string& s) {
        auto node = root;
        for (char c : s) {
            if (!node->ch[c - 'a']) return nullptr;
            node = node->ch[c - 'a'];
        }
        return node;
    }
};