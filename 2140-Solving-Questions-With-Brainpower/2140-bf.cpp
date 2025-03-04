/*
 * This absolutely infeasable approach spans open the entire
 * binary decision tree, simulating every possible choice.
 * As every node is a BinTreeNode struct and thus is 32 bytes
 * in size, and since the size of the tree is 2^n -1 s.t. n being
 * the number of questions in the input, for only 30 questions the tree
 * would already exceed 30GB. 
 *
 * Needless to say that Leetcode does not accept this. And neither should you.
 */

class Solution {
public:
    struct BinTreeNode {
        int index;
        long long score;
        BinTreeNode* left;
        BinTreeNode* right;

        BinTreeNode(int i, long long s)
            : index(i), score(s), left(nullptr), right(nullptr) {}
    };

    long long maxScore = 0;

    void cleanUpTree(BinTreeNode* node) {
        if (!node)
            return;
        cleanUpTree(node->left);
        cleanUpTree(node->right);
        delete node;
    }

    void buildTree(BinTreeNode* node, const vector<vector<int>>& questions,
                   int n) {
        if (!node ||  node->index >= n) {
            if (node)
                maxScore = max(maxScore, node->score);
            return;
        }

        int points = questions[node->index][0];
        int brainpower = questions[node->index][1];

        //Left branch -> Solve current question/task
        node->left = new BinTreeNode(node->index + brainpower + 1, node->score + points);
        buildTree(node->left, questions, n);

        //Right branch -> Skip current question/task
        node->right = new BinTreeNode(node->index + 1, node->score);
        buildTree(node->right, questions, n);
    }

    long long mostPoints(vector<vector<int>>& questions) {
        maxScore = 0;
        BinTreeNode* root = new BinTreeNode(0, 0);
        buildTree(root, questions, questions.size());
        cleanUpTree(root);
        
        return maxScore;
    }
};
