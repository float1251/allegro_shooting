#ifndef LIST_H
#define LIST_H
/**
 * 双方向リスト
 * Node_deleteではNodeデータの削除は実行しないので
 * delete前に削除すること.
 **/
typedef struct Node {
    struct Node* prev;
    struct Node* next;
    void* data; // 基本的にGameObject* が入る
} Node;

typedef struct List {
    Node* head;
    Node* last;
} List;

List* List_new();
void List_insert(List* list, Node* node);
void List_remove(List* list, Node* node);
void List_delete();

Node* Node_new();
void Node_delete(Node* n);

#endif
