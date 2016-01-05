#include "alternas_s.h"

Node* Node_new() {
    Node* n = malloc(sizeof(Node));
    n->prev = NULL;
    n->next = NULL;
    n->data = NULL;
    return n;
}

void Node_delete(Node* n) {
    if(n != NULL) {
        free(n);
    }
}

List* List_new() {
    List* l = malloc(sizeof(List));
    l->head = NULL;
    l->last = NULL;
    return l;
}

void List_insert(List* list, Node* node) {
    if(list->head == NULL) {
        list->head = node;
    }else if(list->last == NULL) {
        list->last = node;
        list->head->next = node;
        node->prev = list->head;
    } else {
        list->last->next = node;
        node->prev = list->last;
        list->last = node;
    }
}

void List_remove(List* list, Node* node) {
    // 先頭だったら次のnodeを先頭にする
    if(node->prev == NULL) {
        list->head = node->next;
    }else {
        node->prev->next = node->next;
    }

    // 最後
    if(node->next == NULL) {
        list->last = node->prev;
    }else{
        node->next->prev = node->prev;
    }
}
