#pragma once
#include <bits/stdc++.h>
using namespace std;

// ============================================================================
// SNIPPET 1: ADAPTADOR ARRAYS <-> PUNTEROS (ÁRBOL AVL / BST)
// ============================================================================
// Úsalo cuando el problema te dé la entrada en arrays (L[i], R[i], val[i])
// pero tú prefieras manipular el árbol usando punteros tradicionales.
// ============================================================================

template <typename T = int>
struct TreePointerAdapter {
    struct TreeNode {
        int id; // ID original del nodo (1 a n)
        T data;
        int height;
        TreeNode *left;
        TreeNode *right;
        TreeNode *parent;

        TreeNode(int id = 0, T data = T())
            : id(id), data(data), height(0), left(nullptr), right(nullptr), parent(nullptr) {}
    };

    TreeNode* root = nullptr;
    vector<TreeNode*> nodes; // Mapea id -> puntero al TreeNode

    int h(TreeNode* v) { return v ? v->height : -1; }
    void update(TreeNode* v) { v->height = 1 + max(h(v->left), h(v->right)); }
    int FB(TreeNode* v) { return h(v->left) - h(v->right); }

    // Construye el árbol en punteros recibiendo los arrays de entrada
    void build_from_arrays(int n, const vector<T>& val, const vector<int>& L, const vector<int>& R, int root_id = 1) {
        nodes.assign(n + 1, nullptr);
        for (int i = 1; i <= n; ++i) {
            nodes[i] = new TreeNode(i, val.empty() ? T() : val[i]);
        }

        for (int i = 1; i <= n; ++i) {
            if (L[i] != 0) {
                nodes[i]->left = nodes[L[i]];
                nodes[L[i]]->parent = nodes[i];
            }
            if (R[i] != 0) {
                nodes[i]->right = nodes[R[i]];
                nodes[R[i]]->parent = nodes[i];
            }
        }

        root = (n > 0) ? nodes[root_id] : nullptr;
        compute_heights(root);
    }

    void compute_heights(TreeNode* u) {
        if (!u) return;
        compute_heights(u->left);
        compute_heights(u->right);
        update(u);
    }

    // Exporta el árbol de punteros de vuelta a arrays (para salidas tipo Problema C)
    void export_to_arrays(int n, int& out_root_id, vector<int>& out_L, vector<int>& out_R) {
        out_root_id = root ? root->id : 0;
        out_L.assign(n + 1, 0);
        out_R.assign(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            if (nodes[i]) {
                out_L[i] = nodes[i]->left ? nodes[i]->left->id : 0;
                out_R[i] = nodes[i]->right ? nodes[i]->right->id : 0;
            }
        }
    }

    // Verificación de BST
    void get_inorder(TreeNode* u, vector<T>& res) {
        if (!u) return;
        get_inorder(u->left, res);
        res.push_back(u->data);
        get_inorder(u->right, res);
    }

    bool is_bst() {
        vector<T> order;
        get_inorder(root, order);
        for (size_t i = 1; i < order.size(); ++i) {
            if (order[i - 1] >= order[i]) return false;
        }
        return true;
    }

    // Verificación de balance AVL (|FB| <= 1 en todos los nodos)
    bool is_avl(TreeNode* u) {
        if (!u) return true;
        if (abs(FB(u)) > 1) return false;
        return is_avl(u->left) && is_avl(u->right);
    }

    bool is_avl() {
        return is_avl(root);
    }

    // Rotación izquierda con punteros
    TreeNode* rotate_left(TreeNode* x) {
        TreeNode* y = x->right;
        x->right = y->left;
        if (y->left) y->left->parent = x;
        y->parent = x->parent;
        if (x->parent) {
            if (x->parent->left == x) x->parent->left = y;
            else x->parent->right = y;
        } else {
            root = y;
        }
        y->left = x;
        x->parent = y;
        update(x);
        update(y);
        return y;
    }

    // Rotación derecha con punteros
    TreeNode* rotate_right(TreeNode* y) {
        TreeNode* x = y->left;
        y->left = x->right;
        if (x->right) x->right->parent = y;
        x->parent = y->parent;
        if (y->parent) {
            if (y->parent->left == y) y->parent->left = x;
            else y->parent->right = x;
        } else {
            root = x;
        }
        x->right = y;
        y->parent = x;
        update(y);
        update(x);
        return x;
    }
};

// ============================================================================
// SNIPPET 2: BST BÁSICO CON ARRAYS (Pool estático con reciclaje)
// ============================================================================
template <int MAXN = 200005, typename T = int>
struct BST_Array {
    int L[MAXN], R[MAXN], P[MAXN];
    T val[MAXN];
    int trash[MAXN], trash_sz = 0;
    int node_cnt = 0;
    int root = 0;

    void init() {
        root = node_cnt = trash_sz = 0;
        L[0] = R[0] = P[0] = 0;
    }

    int new_node(T v) {
        int u = (trash_sz > 0) ? trash[--trash_sz] : ++node_cnt;
        val[u] = v;
        L[u] = R[u] = P[u] = 0;
        return u;
    }

    void free_node(int u) {
        trash[trash_sz++] = u;
    }

    int search(T key) {
        int cur = root;
        while (cur != 0) {
            if (val[cur] == key) return cur;
            if (key < val[cur]) cur = L[cur];
            else cur = R[cur];
        }
        return 0;
    }

    int min_element(int u) {
        if (u == 0) return 0;
        while (L[u] != 0) u = L[u];
        return u;
    }

    int max_element(int u) {
        if (u == 0) return 0;
        while (R[u] != 0) u = R[u];
        return u;
    }

    int successor(int x) {
        if (R[x] != 0) return min_element(R[x]);
        int y = P[x];
        while (y != 0 && R[y] == x) {
            x = y;
            y = P[y];
        }
        return y;
    }

    int predecessor(int x) {
        if (L[x] != 0) return max_element(L[x]);
        int y = P[x];
        while (y != 0 && L[y] == x) {
            x = y;
            y = P[y];
        }
        return y;
    }

    void insert(T v) {
        int z = new_node(v);
        int y = 0, x = root;
        while (x != 0) {
            y = x;
            if (v < val[x]) x = L[x];
            else x = R[x];
        }
        P[z] = y;
        if (y == 0) root = z;
        else if (v < val[y]) L[y] = z;
        else R[y] = z;
    }
};
