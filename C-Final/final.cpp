#include <cstdio> 
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;

// B063040059 陳縵欣 

// BST
struct PersonalInfo{
	int ID; // ID
	char name[128]; // 姓名
	int age; // 年紀
	int gender; // 性別(1=男，2=女)
	int birthday[3]; //出生日期
	struct PersonalInfo *LeftChild;
	struct PersonalInfo *RightChild;
};
typedef struct PersonalInfo BST;
void write_file(BST *root);
void traversal(BST *root, FILE *p);

// 新增一筆資料
void insert(BST *root, BST *newNode){
	if(root == NULL) root = newNode;
	else if(newNode->ID < root->ID)	insert(root->LeftChild, newNode);
	else if(newNode->ID > root->ID)	insert(root->RightChild, newNode);
}

// 刪除一筆資料
void remove(BST *root){
	int id;
	cout << "Please input ID" << endl;
	cin >> id;
	
	BST *current = root, *temp = NULL;
	if(root == NULL) return;
	int direction = 0; // 1: left, 2:right
	
	BST *c = NULL; // pre link
	while(true){
		if(current->ID == id){
			temp = current;
			break;
		}
		else if(id < current->ID){
			c = current;
			current = current->LeftChild;
			direction = 1;
		}
		else if(id > current->ID){
			c = current;
			current = current->RightChild;
			direction = 2;
		}
	}
	
	// case 1: delete root / internal node
	if(current == root){
		if(root->RightChild == NULL){
			root = root->LeftChild;
		}
		else if(root->RightChild->LeftChild == NULL){
			root->RightChild->LeftChild = root->LeftChild;
			root = root->RightChild;
		}
		else {
			current = root->RightChild;
			c = current;
			while(current->LeftChild != NULL){
				c = current; // pre-link
				current = current->LeftChild;
			}
			BST *tempL = root->LeftChild, *tempR = root->RightChild;
			current->LeftChild = tempL;
			c->LeftChild = NULL;
			current->RightChild = tempR;
			root = current;
		}
	}
	
	// case 2: delete leaf
	else if(current->LeftChild == NULL && current->RightChild == NULL){
		if(direction == 1){
			c->LeftChild = NULL;
		}
		else if(direction == 2){
			c->RightChild = NULL;
		}
	}
	
	// delete internal node
	else{
		if(current->RightChild != NULL){
			c = current;
			current = current->RightChild;
			while(current->LeftChild != NULL){
				c = current; // pre-link
				current = current->LeftChild;
			}
			temp->age = current->age;
			temp->birthday[0] = current->birthday[0];
			temp->birthday[1] = current->birthday[1];
			temp->birthday[2] = current->birthday[2];
			temp->gender = current->gender;
			temp->ID = current->ID;
			strcpy(temp->name, current->name);
			
			
			BST *tempL = temp->LeftChild, *tempR = temp->RightChild;
			current->LeftChild = tempL;
			temp->LeftChild = NULL;
			current->RightChild = tempR;
		}
		else{
			c = current->LeftChild;
		}
	}
	
	cout << "Data deleted" << endl;
	write_file(root);
}

// 搜尋特定資料
void search(BST *root){
	int command;
	int ID;
	char name[128];
	int age;
	int gender; // 性別(1=男，2=女)
	int birthday[3]; 
	cout << "Please input field to search (1.ID 2.Name 3.Age 4.Gender 5.Birthday): ";
	cin >> command;
	if(command == 1){
		cout << "Please input ID: ";
		cin >> ID;
	}
	else if(command == 2){
		cout << "Please input name: ";
		scanf("%s", name);
	}
	else if(command == 3){
		cout << "Please input Age: ";
		cin >> age;
	}
	else if(command == 4){
		cout << "Please input Gender: ";
		cin >> gender;
	}
	else if(command == 5){
		cout << "Please input Birthday: ";
		cin >> birthday[0] >> birthday[1] >> birthday[2];
	}
}

// 修改特定資料
void modify(BST *root){
	int ID;
	char name[128];
	int age;
	int gender; // 性別(1=男，2=女)
	int birthday[3]; 
	
	cout << "Please input data ID: ";
	cin >> ID; // original ID
	
	// searching
	BST *current = root;
	while(true){
		if(root == NULL) return;
		if(ID == root->ID) break;
		if(ID == current->ID){
			break;
		}
		else if(ID < current->ID){
			current = current->LeftChild;
		}
		else{
			current = current->RightChild;
		}
	}
	
	cout << "Please input new data" << endl;
	cout << "ID: ";
	cin >> current->ID; // new id
	cout << "Name: ";
	scanf("%s", name);
	strcpy(current->name, name);
	cout << "Age: ";
	cin >> current->age;
	cout << "Gender: ";
	cin >> current->gender;
	cout << "Birthday: ";
	cin >> current->birthday[0] >> current->birthday[1] >> current->birthday[2];
	write_file(root);
}

void write_file(BST *root){
	if(root == NULL) return;
	FILE *out = fopen("newdata.txt", "w");
	BST *current = root;
	/*while(current->LeftChild != NULL){
		current = current->LeftChild;
	}
	*/
	traversal(current, out);
	fclose(out);
}

void traversal(BST *root, FILE *p){
	if(root == NULL) return;
	traversal(root->LeftChild, p);
	//fprintf(p, "%d %s %d %d %d/%d/%d\n", root->ID, root->name, root->age, root->gender, root->birthday[0], root->birthday[1], root->birthday[2]);
	printf("%d %s %d %d %d/%d/%d\n", root->ID, root->name, root->age, root->gender, root->birthday[0], root->birthday[1], root->birthday[2]);
	traversal(root->RightChild, p);
}

int main(){
	BST *database = NULL; // BST
	int command;
	FILE *in = fopen("data.txt", "r");
	
	while(!feof(in)){
		BST *newNode = (BST *) malloc(sizeof(BST));
		newNode->LeftChild = NULL;
		newNode->RightChild = NULL;
		fscanf(in, "%d%s%d%d", &(newNode->ID), newNode->name, &(newNode->age), &(newNode->gender));
		fscanf(in, "%d/%d/%d", &(newNode->birthday[0]), &(newNode->birthday[1]), &(newNode->birthday[2]));
		//printf("%d %s %d %d %d/%d/%d\n", newNode->ID, newNode->name, newNode->age, newNode->gender, newNode->birthday[0], newNode->birthday[1], newNode->birthday[2]);
		insert(database, newNode);
	}
	fclose(in);
	write_file(database);

	while(true){
		cout << "1. Add" << endl;
		cout << "2. Delete" << endl;
		cout << "3. Search" << endl;
		cout << "4. Modify" << endl;
		cout << "5. Exit" << endl;
		cout << "? ";
		cin >> command;
		if(command == 1){
			// add
			BST *newNode = (BST *) malloc(sizeof(BST));
			
			cout << "Please input new data" << endl;
			cout << "ID: ";
			cin >> newNode->ID; // new id
			cout << "Name: ";
			scanf("%s", newNode->name);
			cout << "Age: ";
			cin >> newNode->age;
			cout << "Gender: ";
			cin >> newNode->gender;
			cout << "Birthday: ";
			cin >> newNode->birthday[0] >> newNode->birthday[1] >> newNode->birthday[2];
			
			newNode->LeftChild = NULL;
			newNode->RightChild = NULL;
			insert(database, newNode);
		}
		else if(command == 2){
			// delete
			remove(database);
			write_file(database);
		}
		else if(command == 3){
			// Search
			search(database);
		}
		else if(command == 4){
			// Modify
			modify(database);
		}
		else if(command == 5) break; // exit
	}
	return 0;
}
