/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class solution
{
    void dfs(Node *current, Node *node, vector<Node *> &visited)
    {
        visited[node->val] = node;

        for (auto element : current->neighbors)
        {
            if (visited[element->val] == NULL)
            {
                Node *newnode = new Node(element->val);
                (node->neighbors).push_back(newnode);

                dfs(element, newnode, visited);
            }

            else
                (node->neighbors).push_back(visited[element->val]);
        }
    }

public:
    Node *cloneGraph(Node *node)
    {
        if (node == NULL)
            return NULL;

        vector<Node *> visited(1000, NULL);
        Node *copy = new Node(node->val);

        visited[node->val] = copy;

        // Iterate for all neighbors

        for (auto current : node->neighbors)
        {
            if (visited[current->val] == NULL)
            {
                Node *newnode = new Node(current->val);
                (copy->neighbors).push_back(newnode);
                dfs(current, newnode, visited);
            }
            else
                (copy->neighbors).push_back(visited[current->val]);
        }
        return copy;
    }
};