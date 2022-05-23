#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* create_node(int val){
    if(val == -1){
        return NULL;
    }
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=val;
    temp->left=NULL;
    temp->right=NULL;
    return temp; 
}

void inorder(struct node *root){
    if(!root){
        return;
    }    
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int max(int a, int b){
    if(a>b){
        return a;
    } else {
        return b;
    }
}

int height(struct node * root){
    if(!root){
        return 0;
    }
    return(1+max(height(root->left),height(root->right)));
}

void swap_nodes_at_level(struct node *root, int inc, int level, int height){
    struct node *tnode;
    if(!root){
        return;
    }
    if(level > height){
        return;
    }
    if(!(level%inc)){
        tnode=root->left;
        root->left=root->right;
        root->right=tnode;
    }
    swap_nodes_at_level(root->left, inc, level+1, height);
    swap_nodes_at_level(root->right, inc, level+1, height);
}

int tail=0;
int head=0;


void enqueue(struct node **queue, struct node *root){
    
    queue[tail]=root;
    tail++;   
}

struct node* dequeue(struct node **queue){
    
    struct node *temp = queue[head];
    head++;
    return temp;
}

int main() {
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int nodes_count, i, temp, h, tc_num, index, inc, temp1, temp2;
          
    scanf("%d", &nodes_count);
    
  //  printf("%d\n", nodes_count);
    
    // int arr[2*nodes_count+1];
    
    struct node *root_perm, *root_temp;
    
    //queue=create_queue(nodes_count);

    struct node *q[nodes_count];
    for(i=0;i<nodes_count;i++){
        q[i]=NULL;
    }    
    
    //building the array
    
    //arr[0]=1;
    
   // for(i=1;i<=2*nodes_count;i++){
     //   scanf("%d",&temp);
      //  arr[i]=temp;
   //   printf("%d ", arr[i]);
   // }
    
    i=0,index=1;
    root_temp=root_perm=create_node(1);
    enqueue(q, root_temp);
    
    while(index<=2*nodes_count) {
       
        //printf("\n In Loop : i : %d",i);
        root_temp=dequeue(q);
        //setting up the left child
        scanf("%d", &temp1);
        if(temp1 == -1){
       
        } else {
            root_temp->left=create_node(temp1);
            enqueue(q, root_temp->left);
        }
        //setting up the right child
        scanf("%d", &temp2);
        if(temp2==-1) {
            
        } else {
            root_temp->right=create_node(temp2);
            enqueue(q, root_temp->right);
        }
        index=index+2;
      //  i++;
        
    }
   
    h = height(root_perm);
    
    scanf("%d", &tc_num);
    
    //printf("%d",tc_num);
    //printf("\n");
    
    //inorder(root_perm);
    
    while(tc_num){
        scanf("%d",&inc);
        temp=inc;
        //while(temp < height){
        swap_nodes_at_level(root_perm, inc, 1, h);
        //temp=temp + inc;
        //}
        //temp=0;
        inorder(root_perm);
        printf("\n");
        tc_num--;
    }  
    
    //Tree is created at this point 
    
    return 0;
}