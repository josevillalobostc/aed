#include <iostream>
using namespace std;

template <typename data_type> struct LinkedNode {
  data_type data;
  LinkedNode *next;

  LinkedNode() { next = nullptr; }
  LinkedNode(data_type data, LinkedNode<data_type> *next = nullptr)
      : data(data), next(next) {}
};

template <typename data_type> struct DoublyLinkedNode {
  data_type data;
  DoublyLinkedNode *next;
  DoublyLinkedNode *prev;

  DoublyLinkedNode() { next = prev = nullptr; }
  DoublyLinkedNode(data_type data, DoublyLinkedNode *next = nullptr,
                   DoublyLinkedNode *prev = nullptr)
      : data(data), next(next), prev(prev) {}
};

template <typename data_type> struct LinkedList {
  LinkedNode<data_type> *head;
  LinkedNode<data_type> *tail;

  LinkedList() { head = tail = nullptr; }

  void push_front(data_type value) {
    // inserta nodo con data: value al inicio de la lista
    LinkedNode<data_type> *new_node = new LinkedNode<data_type>(value, head);
    if (head == nullptr) {
      tail = new_node;
    }
    head = new_node;
  }

  void push_back(data_type value) {
    if (tail == nullptr) {
      head = tail = new LinkedNode<data_type>(value);
    } else {
      tail->next = new LinkedNode<data_type>(value);
      tail = tail->next;
    }
  }

  void insert(LinkedNode<data_type> *node, data_type value) {
    // inserta nodo con data: value
    // Despues del nodo "node" que no es nulo
    LinkedNode<data_type> *new_node =
        new LinkedNode<data_type>(value, node->next);
    if (node == tail) {
      tail = new_node;
    }
    node->next = new_node;
  }

  void insert(int k, data_type value) {
    // Inserta "value como el k-ésimo valor"
    if (k == 0)
      push_front(value);
    else {
      LinkedNode<data_type> *current = head;
      for (int i = 1; i <= k - 1; ++i) {
        current = current->next;
      }
      insert(current, value);
    }
  }

  void pop_front() {
    LinkedNode<data_type> *current = head;
    head = head->next;
    if (head == nullptr)
      tail = nullptr;
    delete current;
  }

  void erase(LinkedNode<data_type> *node) {
    // Elimina el siguiente al nodo "node"
    if (node->next) {
      LinkedNode<data_type> *current = node->next;
      if (node->next == tail) {
        tail = node;
      }
      node->next = node->next->next;
      delete current;
    }
  }

  void erase(int k) {
    if (k == 0)
      pop_front();
    else {
      LinkedNode<data_type> *current = head;
      for (int i = 1; i <= k - 1; ++i) {
        current = current->next;
      }
      erase(current);
    }
  }

  void print() {
    LinkedNode<data_type> *current = head;
    while (current != nullptr) {
      cout << current->data << " ";
      current = current->next;
    }
    cout << '\n';
  }
};

template <typename data_type> struct DoubleLinkedList {
  DoublyLinkedNode<data_type> *head;
  DoublyLinkedNode<data_type> *tail;

  DoubleLinkedList() { head = tail = nullptr; }

  void push_front(data_type value) {
    // inserta nodo con data: value al inicio de la lista
    DoublyLinkedNode<data_type> *new_node =
        new DoublyLinkedNode<data_type>(value, head);
    if (head == nullptr) {
      tail = new_node;
    } else {
      head->prev = new_node;
    }
    head = new_node;
  }

  void push_back(data_type value) {
    if (tail == nullptr) {
      head = tail = new DoublyLinkedNode<data_type>(value);
    } else {
      tail->next = new DoublyLinkedNode<data_type>(value);
      tail = tail->next;
    }
  }

  void insert(DoublyLinkedNode<data_type> *node, data_type value) {
    // inserta nodo con data: value
    // Despues del nodo "node" que no es nulo
    DoublyLinkedNode<data_type> *new_node =
        new DoublyLinkedNode<data_type>(value, node->next);
    if (node == tail) {
      tail = new_node;
    }
    node->next = new_node;
  }

  void insert(int k, data_type value) {
    // Inserta "value como el k-ésimo valor"
    if (k == 0)
      push_front(value);
    else {
      DoublyLinkedNode<data_type> *current = head;
      for (int i = 1; i <= k - 1; ++i) {
        current = current->next;
      }
      insert(current, value);
    }
  }

  void pop_front() {
    DoublyLinkedNode<data_type> *node = head;
    if (head == tail) {
      delete node;
      head = tail = nullptr;
    } else {
      head = head->next;
      head->prev = nullptr;
      delete node;
    }
  }

  void pop_back() {
    DoublyLinkedNode<data_type> *node = tail;
    tail = tail->prev;
    tail->prev = nullptr;
    delete node;
  }

  void erase(DoublyLinkedNode<data_type> *node) {
    // Eliminar nodo "node" no nulo
    if (node == head) {
      pop_front();
    } else if (node == tail) {
      pop_back();
    } else {
      DoublyLinkedNode<data_type> *predecessor = node->prev;
      DoublyLinkedNode<data_type> *succesor = node->next;
      predecessor->next = succesor;
      succesor->prev = predecessor;
      delete node;
    }
  }

  void erase(int k) {
    if (k == 0)
      pop_front();
    else {
      DoublyLinkedNode<data_type> *current = head;
      for (int i = 1; i <= k - 1; ++i) {
        current = current->next;
      }
      erase(current);
    }
  }

  void print() {
    DoublyLinkedNode<data_type> *current = head;
    while (current != nullptr) {
      cout << current->data << " ";
      current = current->next;
    }
    cout << '\n';
  }
};

struct CircularLinkedList {};

int main() {
  cin.tie(0)->sync_with_stdio(false);
  DoubleLinkedList<int> L;
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    string op;
    cin >> op;
    if (op == "insert") {
      int x;
      cin >> x;
      L.push_back(x);
    } else if (op == "delete") {
      int x;
      cin >> x;
      L.erase(x);
    } else if (op == "deleteFirst") {
      L.pop_front();
    } else {
      L.pop_back();
    }
  }
  return 0;
}
