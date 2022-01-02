#include<iostream>

using namespace std;

int number =15;
// 하나의 노드 정보를 선언합니다. 
typedef struct node *treePointer;
typedef struct node{
	int data;
	treePointer leftChild,rightChild;
}node;
// 전위 순회를 구현합니다. 

void preorder(treePointer ptr){
	if(ptr){
		cout <<ptr->data<<' ';
		preorder(ptr->leftChild);
		preorder(ptr->rightChild);
	}
}
void inorder(treePointer ptr){
	if(ptr){
		inorder(ptr->leftChild);
		cout <<ptr->data<<' ';
		inorder(ptr->rightChild);
	}
}
void postorder(treePointer ptr){
	if(ptr){
		postorder(ptr->leftChild);
		postorder(ptr->rightChild);
		cout <<ptr->data<<' ';
	}
}

int main(void){
	node nodes[number +1];
	for(int i =1; i<=number; i++){ //tree 생성 
		nodes[i].data = i;
		nodes[i].leftChild=NULL;
		nodes[i].rightChild =NULL;
	}
	for(int i=1; i<=number; i++){ //포인터 연 결 
		if(i%2 ==0){
			nodes[i/2].leftChild = &nodes[i];
		}
		else{
			nodes[i/2].rightChild = &nodes[i];
		}
	}
	preorder(&nodes[1]);
	printf("\n");
	inorder(&nodes[1]);
	printf("\n");
	postorder(&nodes[1f]);
	
}




