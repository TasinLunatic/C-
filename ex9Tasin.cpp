#include <iostream>
#include <queue>
#include <map>
#include <string>
using namespace std;


struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = NULL;
    }
};


struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq; 
    }
};


void generateCodes(Node* root, string code, map<char, string> &huffCodes) {
    if (!root) return;

    if (!root->left && !root->right) {
        huffCodes[root->ch] = code;
    }

    generateCodes(root->left, code + "0", huffCodes);
    generateCodes(root->right, code + "1", huffCodes);
}

int main() {
    string text;

    cout << "Enter text: ";
    getline(cin, text);

   
    map<char, int> freq;

    
    for (int i = 0; i < text.length(); i++) {
        char c = text[i];
        freq[c]++;
    }

    
    priority_queue<Node*, vector<Node*>, Compare> pq;

    
    map<char, int>::iterator it;
    for (it = freq.begin(); it != freq.end(); it++) {
        pq.push(new Node(it->first, it->second));
    }

    
    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        Node* parent = new Node('\0', left->freq + right->freq);
        parent->left = left;
        parent->right = right;

        pq.push(parent);
    }

    Node* root = pq.top();

    
    map<char, string> huffCodes;
    generateCodes(root, "", huffCodes);

    
    cout << "\nHuffman Codes:\n";
    map<char, string>::iterator it2;
    for (it2 = huffCodes.begin(); it2 != huffCodes.end(); it2++) {
        if (it2->first == ' ')
            cout << "'space' : " << it2->second << endl;
        else
            cout << "'" << it2->first << "' : " << it2->second << endl;
    }

    return 0;
}


