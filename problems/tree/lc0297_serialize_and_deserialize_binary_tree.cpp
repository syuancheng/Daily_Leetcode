#include "type.h"
#include <cstddef>
#include <string>
#include <sstream>

using namespace std;

class Codec {
public:
  // Encodes a tree to a single string.
  string serialize(TreeNode *root) {
    //找终点
    if (!root) {
      return "#";
    }

    auto l = serialize(root->left);
    auto r = serialize(root->right);

    return to_string(root->val) + " " + l + " " + r;

  }

  
  TreeNode* my_deserialize(istringstream& ss) {
    string tmp;
    if (!(ss >> tmp)) {
      return nullptr;
    }
    if (tmp == "#") {
      return nullptr;
    }

    // 当前层
    TreeNode *node = new TreeNode(stoi(tmp));

    node->left = my_deserialize(ss);
    node->right = my_deserialize(ss);

    return node;
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data) {
    istringstream ss(data);
    return my_deserialize(ss);
  }
};
