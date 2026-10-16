# Guía y Snippets de Árboles (AED / Competitiva)

Esta carpeta contiene las implementaciones modulares de árboles binarios en C++ tanto con **Punteros tradicionales** como con **Arrays estáticos**, junto con un **Adaptador** para pasar de uno a otro.

---

## Índice de Archivos

1. **[`tree_snippets.hpp`](tree_snippets.hpp)**: Adaptador Arrays $\leftrightarrow$ Punteros y BST estático con arrays.
2. **[`avl_arrays.cpp`](avl_arrays.cpp)**: Árbol AVL balanceado 100% sobre arrays (con `insert`, `erase` físico, rebalanceo y rotaciones).
3. **[`rbtree_arrays.cpp`](rbtree_arrays.cpp)**: Árbol Red-Black (Rojinegro) balanceado 100% sobre arrays (algoritmo CLRS completo).
4. **[`miavl.cpp`](miavl.cpp)**: Tu AVL clásico basado en punteros (`TreeNode*`).
5. **[`mirbtree.cpp`](mirbtree.cpp)**: Tu Red-Black Tree clásico basado en punteros.

---

## 1. El Adaptador: De Arrays a Punteros (y viceversa)

Úsalo cuando el problema del juez te dé el árbol en arrays (`val[i]`, `L[i]`, `R[i]`) pero tú prefieras resolverlo con tus funciones habituales de punteros (`u->left`, `u->right`, `u->parent`).

### Cómo usarlo en tu código:

```cpp
#include "tree_snippets.hpp"

int main() {
    int n;
    cin >> n;
    vector<int> val(n + 1), L(n + 1), R(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> val[i] >> L[i] >> R[i];
    }

    // 1. Construir el árbol de punteros a partir de los arrays:
    TreePointerAdapter<int> tree;
    tree.build_from_arrays(n, val, L, R);

    // 2. Usar tus métodos de punteros:
    if (!tree.is_bst()) {
        cout << "NINGUNO\n";
    } else if (!tree.is_avl()) {
        cout << "BST\n";
    } else {
        cout << "AVL\n";
    }

    // 3. Si necesitas exportar de vuelta a arrays (como en Problema C):
    int final_root;
    vector<int> out_L, out_R;
    tree.export_to_arrays(n, final_root, out_L, out_R);
    cout << "Nueva raiz: " << final_root << "\n";
}
```

---

## 2. Árbol AVL con Arrays ([`avl_arrays.cpp`](avl_arrays.cpp))

Usa arrays contiguos en lugar de memoria dinámica (`new`/`delete`). Es **3x a 5x más rápido** y no fragmenta la memoria.

### Características clave:
* **El nodo `0` es el centinela `nullptr`**: `H[0] = -1` (la altura del subárbol vacío es -1).
* **Fórmula de balance directa**: `FB(v) = H[L[v]] - H[R[v]]`.
* **Reciclaje de memoria**: Si borras nodos con `erase(u)`, sus IDs van a una pila `trash` para ser reutilizados en la próxima inserción, evitando desbordar el tamaño del array.

### Métodos incluidos:
- `tree.init()`
- `tree.insert(x)`
- `tree.erase(u)`
- `tree.search(key)`
- `tree.successor(x)` / `tree.predecessor(x)`
- `tree.min_element(u)` / `tree.max_element(u)`
- `tree.print_inorder()`

---

## 3. Red-Black Tree con Arrays ([`rbtree_arrays.cpp`](rbtree_arrays.cpp))

Traslada la especificación del libro CLRS (*Introduction to Algorithms*) a arrays planos.

### Características clave:
* **El nodo `0` es el centinela `Tnil`**: `color[0] = BLACK`.
* Todos los punteros nulos apuntan a `0`.
* Inserción en $O(\log n)$ con rebalanceo de colores y rotaciones (`insert_fix`).
* Borrado físico completo con `delete_fix` en $O(\log n)$.

---

## Tabla de Equivalencias Rápidas

| Concepto | Versión Punteros | Versión Arrays |
| :--- | :--- | :--- |
| **Puntero al nodo** | `TreeNode* u` | `int u` |
| **Hijo Izquierdo** | `u->left` | `L[u]` |
| **Hijo Derecho** | `u->right` | `R[u]` |
| **Padre** | `u->parent` | `P[u]` |
| **Clave / Valor** | `u->data` | `val[u]` |
| **Altura** | `u->height` | `H[u]` |
| **Color (RB)** | `u->color` | `color[u]` |
| **Puntero Nulo (`nullptr` / `Tnil`)** | `nullptr` / `Tnil` | `0` |
| **Crear nodo nuevo (`new`)** | `new TreeNode(...)` | `u = (trash_sz ? trash[--trash_sz] : ++node_cnt)` |
| **Liberar nodo (`delete`)** | `delete u` | `trash[trash_sz++] = u` |
