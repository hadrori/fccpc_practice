#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
#define all(u) begin(u),end(u)
#define pb push_back
#define mp make_pair

const int C = 128;
int N, M, B;
int costs[256];
const int inf = 1e9;

struct Node {
    Node *next[C];
    vector<int> dp;
    vector<int> match;
    int score;
    Node() { 
        fill(next, next+C, (Node *) NULL); 
        dp = vector<int> (B+1, -inf);
        score = 0;
    }
    ~Node() { rep(i,C) if(next[i] != NULL) delete next[i]; }
};

Node *construct_pma(const vector<string> &pat) {
    Node *const root = new Node();
    root->next[0] = root;
    rep(i,pat.size()) {
        const string &s = pat[i];
        Node *now = root;
        for(const char &c: s) {
            if(now->next[int(c)] == NULL) now->next[int(c)] = new Node();
            now = now->next[int(c)];
        }
        now->match.pb(i);
    }
    queue<Node*> q;
    repi(i,1,C) {
        if(root->next[i] == NULL) root->next[i] = root;
        else {
            root->next[i]->next[0] = root;
            q.push(root->next[i]);
        }
    }
    while(!q.empty()) {
        auto now = q.front();
        q.pop();
        repi(i,1,C) if(now->next[i] != NULL) {
            auto next = now->next[0];
            while(next->next[i] == NULL) next = next->next[0];
            now->next[i]->next[0] = next->next[i];
            vector<int> tmp;
            set_union(all(now->next[i]->match), all(next->next[i]->match), back_inserter(tmp));
            now->next[i]->match = tmp;
            q.push(now->next[i]);
        }
    }
    return root;
}

// size of ret should be number of patterns
void match(Node *&now, const string s, vector<int> &ret) {
    for(const char &c: s) {
        while(now->next[int(c)] == NULL) now = now->next[0];
        now = now->next[int(c)];
        for(const int &e: now->match) ret[e] = true;
    }
}
void getNodes(Node* node, vector<Node*> &nodes) {
    set<Node*> done;    
    queue<Node*> q;
    q.push(node);
    while(q.size()) {
        node = q.front(); q.pop();
        if (done.find(node) != done.end()) continue;
        done.insert(node);
        
        nodes.pb(node);
        repi(i, 0, C) if (node->next[i] != NULL)
            q.push(node->next[i]);
    }
}

void input() {
    cin >> N >> M >> B;
    rep(i, N) {
        char c;
        int cst;
        cin >> c >> cst;
        costs[c] = cst;
    }

    vector<string> pats(M);
    vector<int> scores(M);
    rep(i, M) {
        cin >> pats[i] >> scores[i];
    }
    Node* root = construct_pma(pats);

    vector<Node*> nodes;    
    getNodes(root, nodes);
    reverse(all(nodes));

    for (Node* node: nodes) {
        node->score = 0;
        for (int &mat: node->match)
            node->score += scores[mat];    
    }
    
    root->dp[0] = 0;    
    rep(i, B) for (Node* now: nodes) {
        rep(k, C) if (now->next[k] && i + costs[k] <= B) {
            Node* nxt = now->next[k];
            nxt->dp[i+costs[k]] = max(nxt->dp[i+costs[k]], now->dp[i] + (k?nxt->score:0));
        }
    }

    int ans = 0;
    for (Node* node: nodes) {
        rep(b, B+1) 
            ans = max(ans, node->dp[b]);
    }
    
    cout << ans << endl;
}

int main() {
    cout << fixed << setprecision(12);
    int t; cin >> t;
    rep(i,t) {
        cout << "Case #" << i+1 << ": ";
        input();
    }
    return 0;
}
