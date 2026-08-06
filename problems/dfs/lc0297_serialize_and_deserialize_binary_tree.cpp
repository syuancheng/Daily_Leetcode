#include "../common/nodes.h"
#include <sstream>

using namespace std;

class Codec {
public:

  string serialize(TreeNode *root) {
    (void)root;
    return "";
  }


  TreeNode* my_deserialize(istringstream& ss) {
    (void)ss;
    return nullptr;
  }


  TreeNode *deserialize(string data) {
    (void)data;
    return nullptr;
  }
};
