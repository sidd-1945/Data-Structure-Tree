
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

void search(int target){
    tmp = root;

    while(tmp != NULL){
        if(tmp->data > target){
            tmp = tmp->left;
        }else if(tmp->data < target){
            tmp = tmp->right;
        }else{
            printf("Found");
            return ;
        }
    }
    printf("Not Found");
}

void inorder(struct Node *root){
    if(root != NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);       
    }
}

void postorder(struct Node *root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data); 
    }
}

void preorder(struct Node *root){
    if(root != NULL){
        printf("%d ",root->data); 
        preorder(root->left);
        preorder(root->right);
    }
}


int main(){
    int choice,s;
    while(1){
        printf("\nEnter 1 for Create\n2 for preorder traversal\n3 for postorder traversal\n4 for inorder traversal\n5 for search\n6 for exit\n");
        printf("Enter Choice: ");
        scanf("%d",&choice);
        if(choice == 1){
            createNode();
        }else if(choice == 2){
            preorder(root);
        }else if(choice == 3){
            postorder(root);
        }else if(choice == 4){
            inorder(root);
        }else if(choice == 5){
            printf("\nEnter a number to search: ");
            scanf("%d",&s);
            search(s);
        }else if(choice == 6){
            break;
        }else{
            printf("Invalid input!!!");
        }  
        printf("\n-----------------------------\n");       
    }
}
 