#include <bits/stdc++.h>
using namespace ::std;

template <typename data_type> struct AVL {
  set<long long> conj;

  struct TreeNode {
    long long height;
    data_type data;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;

    TreeNode(data_type data = data_type(), TreeNode *left = nullptr,
             TreeNode *right = nullptr, TreeNode *parent = nullptr)
        : data(data), left(left), right(right), parent(parent) {}
  };

  long long h(TreeNode *v) { return (v == nullptr ? -1 : v->height); }

  void update(TreeNode *v) { v->height = 1 + max(h(v->left), h(v->right)); }

  long long FB(TreeNode *v) { return h(v->left) - h(v->right); }

  void rotate_right(TreeNode *y) {
    TreeNode *x = y->left;
    y->left = x->right;
    x->right = y;
    update(y);
    update(x);
    return x;
  }

  void rotate_left(TreeNode *x) {
    TreeNode *y = x->left;
    x->right = y->left;
    y->left = x;
    update(x);
    update(y);
    return x;
  }

  TreeNode *root;

  AVL() { root = nullptr; }

  bool search(data_type key) {
    TreeNode *current = root;
    while (current != nullptr) {
      if (current->data == key) {
        return true;
      }
      if (current->data > key) {
        current = current->left;
      } else {
        current = current->right;
      }
    }
    return false;
  }

  TreeNode *min_element(TreeNode *u) {
    if (u == nullptr)
      return nullptr;
    TreeNode *current = u;
    while (current->left != nullptr) {
      current = current->left;
    }
    return current;
  }

  TreeNode *max_element(TreeNode *u) {
    if (u == nullptr)
      return nullptr;
    TreeNode *current = u;
    while (current->right != nullptr) {
      current = current->right;
    }
    return current;
  }

  TreeNode *min_element() { return min_element(root); }

  TreeNode *max_element() { return max_element(root); }

  void insert(data_type value) { root = insert(root, value); }

  TreeNode *insert(TreeNode *u, data_type value) {
    if (u == nullptr) {
      return new TreeNode(value, 0);
    }
    if (value < u->data) {
      u->left = insert(u->left, value);
    } else {
      u->right = insert(u->right, value);
    }
    return rebalance(u);
  }

  void prlong long_inorder() {
    prlong long_subtree_inorder(root);
    cout << endl;
  }

  void prlong long_subtree_inorder(TreeNode *u) {
    if (u == nullptr)
      return;
    prlong long_subtree_inorder(u->left);
    cout << u->data << " ";
    prlong long_subtree_inorder(u->right);
  }

  void prlong long_preorder() {
    prlong long_subtree_preorder(root);
    cout << endl;
  }

  void prlong long_subtree_preorder(TreeNode *u) {
    if (u == nullptr)
      return;
    cout << u->data << " ";
    prlong long_subtree_preorder(u->left);
    prlong long_subtree_preorder(u->right);
  }

  void prlong long_postorder() {
    prlong long_subtree_postorder(root);
    cout << endl;
  }

  void prlong long_subtree_postorder(TreeNode *u) {
    if (u == nullptr)
      return;
    prlong long_subtree_postorder(u->left);
    prlong long_subtree_postorder(u->right);
    cout << u->data << " ";
  }

  TreeNode *successor(TreeNode *x) {
    if (x->right != nullptr) {
      return min_element(x->right);
    }
    TreeNode *y = x->parent;
    while (y != nullptr and y->right == x) {
      x = y;
      y = y->parent;
    }
    return y;
  }

  TreeNode *rebalance(TreeNode *v) {
    if (FB(v) > 1) {
      if (FB(v->left) < 0) {
        v->left = rotate_left(v->left);
      }
      return rotate_right(v);
    }
    if (FB(v) < -1) {
      if (FB(v->right) > 0) {
        v->right = rotate_right(v->right);
      }
      return rotate_left(v);
    }
  }

  TreeNode *predecessor(TreeNode *x) {
    if (x->left != nullptr) {
      return max_element(x->left);
    }
    TreeNode *y = x->parent;
    while (y != nullptr and y->left == x) {
      x = y;
      y = y->parent;
    }
    return y;
  }

  void transplant(TreeNode *u, TreeNode *v) {
    if (u->parent == nullptr) {
      root = v;
    } else if (u->parent->right == u) {
      u->parent->right = v;
    } else {
      u->parent->left = v;
    }
    if (v != nullptr) {
      v->parent = u->parent;
    }
    delete u;
  }

  void erase(TreeNode *u) {
    if (u->left == nullptr and u->right == nullptr) {
      transplant(u, u->left);
    } else if (u->left != nullptr and u->right != nullptr) {
      TreeNode *succ = successor(u);
      u->data = succ->data;
      transplant(succ, succ->right);
    } else {
      if (u->left)
        transplant(u, u->left);
      else
        transplant(u, u->right);
    }
  }
};

long long main() {
  long long n;
  cin >> n;
  AVL<long long> B;
  for (long long i = 0; i < n; ++i) {
    long long x;
    cin >> x;
    B.insert(x);
  }
  B.prlong long_preorder();
  B.prlong long_inorder();
  B.prlong long_postorder();
  return 0;
}
