#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    int data;
    struct node *next;
    
};

void print(struct node *head){
    if(head != NULL){
        printf("%d ", head->data);
        print(head->next);
    }
    return;
};
struct node *add_node(char command[20], int data, struct node *head, int pos){
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    if(head == NULL){
            return new_node;
        }
    if(command == "start"){
        new_node->next = head;
        head = new_node;
    }else if (command == "end")
    {
        struct node *temp_head = head;
        while (temp_head->next != NULL)
        {
            temp_head = temp_head->next;
        }
        temp_head->next = new_node;
    }else{
        if(pos == 0){
            return add_node("start", data, head, pos);
        }
        struct node *temp_head = head;
        while (temp_head->next != NULL && pos > 1)
        {
            temp_head = temp_head->next;
            pos--;
        }
        struct node *temp = temp_head->next;
        temp_head->next = new_node;
        new_node->next = temp;
    }
    return head;
};
struct node *del_node(int pos, struct node *head){
    if(pos == 0){
        return head->next;
    }
    struct node *temp_head = head;
    while (temp_head->next != NULL && pos > 1)
    {
        temp_head = temp_head->next;
        pos--;
    }
    if(temp_head->next != NULL){
        temp_head->next = temp_head->next->next;
    }
    return head;
};

int main(){
    struct node *head = NULL;
    head = add_node("end", 12, head, 0);
    head = add_node("end", 13, head, 0);
    head = add_node("end", 14, head, 0);
    head = add_node("end", 15, head, 0);
    head = add_node("end", 16, head, 0);
    head = add_node("awa", 11, head, 0);
    head = add_node("awa", 18, head, 4);
    head = del_node(7, head);
    print(head);
    return 0;
}