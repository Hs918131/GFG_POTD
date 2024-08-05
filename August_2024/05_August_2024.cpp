class Solution {
  public:
    vector <int> bottomView(Node *root) {
        if (!root) return {};

        map<int, int> bottomViewMap; 
        queue<pair<Node*, int>> q;   
        q.push({root, 0});
        while (!q.empty()) {
            auto front = q.front();
            q.pop();

            Node* node = front.first;
            int hd = front.second;

            bottomViewMap[hd] = node->data;

            if (node->left) {
                q.push({node->left, hd - 1});
            }

            if (node->right) {
                q.push({node->right, hd + 1});
            }
        }

        vector<int> result;
        for (const auto& entry : bottomViewMap) {
            result.push_back(entry.second);
        }

        return result;
    }
};
