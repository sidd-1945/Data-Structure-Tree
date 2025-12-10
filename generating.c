//Creation of Binary Tree
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *root = NULL;
struct Node *newNode;
struct Node *tmp;

void createNode() {
    newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter Record to be inserted in the node: ");
    scanf("%d", &newNode->data);
    newNode->right = NULL;
    newNode->left = NULL;

    if (root == NULL) {
        root = newNode;
        return;
    }
    tmp = root;
    while(1){
        if(newNode->data > tmp->data){
            if(tmp->right == NULL){
                tmp->right = newNode;
                break;
            }else{
                tmp = tmp->right;
            }
        }else{
            if(tmp->left == NULL){
                tmp->left = newNode;
                break;
            }else{
                tmp = tmp->left;
            }
        }
    }
}   

int main(){
    createNode();
    createNode();
} 