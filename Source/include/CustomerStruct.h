#pragma once

#include "TableControl.h"

struct Customer{
	char ICNumber[10]="";
	char fName[40]="";
	char name[10]="";
	char fullName[50]="";
	char gender[10]="";
	int isActive=0;
};

struct Node{
	Customer data;
	int balanceFactor=0;
	Node *leftChild=NULL;
	Node *rightChild=NULL;
	Node *parent=NULL;
};

struct CustomerTree{
	Node *root=NULL;
	int size=0;
};

CustomerTree customerList;

Customer CreateNewCustomer(char* ICNumber, char *fName, char* name, char* fullName, char *gender){
	Customer tmp;
	strcpy(tmp.ICNumber, ICNumber);
	strcpy(tmp.fName, fName);
	strcpy(tmp.name, name);
	strcpy(tmp.fullName, fullName);
	strcpy(tmp.gender, gender);

	return tmp;
}

Node *CreateNewCustomerNode(Customer cus){
	Node *tmp=new Node;
	tmp->data = cus;
	tmp->balanceFactor = 0;
	tmp->leftChild = NULL;
	tmp->rightChild = NULL;
	tmp->parent = NULL;
	return tmp;
}

Node *UpdateBalanceFactorAndReturnYa(Node *node, Node *lastAddedNode){
	Node *tmpNode = node;
	while(tmpNode->balanceFactor==0 && tmpNode->parent!=NULL){
		if(strcmp(lastAddedNode->data.ICNumber,tmpNode->data.ICNumber)<0){
			tmpNode->balanceFactor=1;
		}
		else{
			tmpNode->balanceFactor=-1;
		}
		tmpNode=tmpNode->parent;
	}
	
	return tmpNode;
}

Node *RightRotating(CustomerTree &list, Node *node){
	Node *tmpLeftChild = node->leftChild;
	Node *tmpLeftRightChild = tmpLeftChild->rightChild;
	Node *tmpRoot = node;
	if(tmpRoot->parent==NULL){
		list.root = tmpLeftChild;
		tmpLeftChild->parent=NULL;
	}
	else{
		if(strcmp(tmpRoot->data.ICNumber,tmpRoot->parent->data.ICNumber)<0){
			tmpRoot->parent->leftChild = tmpLeftChild;
			tmpLeftChild->parent = tmpRoot->parent;
		}
		else if(strcmp(tmpRoot->data.ICNumber,tmpRoot->parent->data.ICNumber)>0){
			tmpRoot->parent->rightChild = tmpLeftChild;
			tmpLeftChild->parent = tmpRoot->parent;
		}
	}
	tmpRoot->leftChild = tmpLeftRightChild;
	if(tmpLeftRightChild!=NULL) tmpLeftRightChild->parent = tmpRoot;
	tmpLeftChild->rightChild = tmpRoot;
	tmpRoot->parent = tmpLeftChild;
	return tmpLeftChild;
}

Node *LeftRotating(CustomerTree &list, Node *node){
	Node *tmpRightChild = node->rightChild;
	Node *tmpRightLeftChild = tmpRightChild->leftChild;
	Node *tmpRoot = node;
	
	if(tmpRoot->parent==NULL){
		list.root = tmpRightChild;
		tmpRightChild->parent=NULL;
	}
	else{
		if(strcmp(tmpRoot->data.ICNumber,tmpRoot->parent->data.ICNumber)<0){
			tmpRoot->parent->leftChild = tmpRightChild;
			tmpRightChild->parent = tmpRoot->parent;
		}
		else if(strcmp(tmpRoot->data.ICNumber,tmpRoot->parent->data.ICNumber)>0){
			tmpRoot->parent->rightChild = tmpRightChild;
			tmpRightChild->parent = tmpRoot->parent;
		}
	}
	tmpRoot->rightChild = tmpRightLeftChild;
	if(tmpRightLeftChild!=NULL) tmpRightLeftChild->parent = tmpRoot;
	tmpRightChild->leftChild = tmpRoot;
	tmpRoot->parent=tmpRightChild;
	return tmpRightChild;
}

void BalanceTree(Node *node, Node *lastAddedNode){
	
	Node *ya = UpdateBalanceFactorAndReturnYa(node, lastAddedNode);
	
	int imbalStatus;
	Node *s;
	if(strcmp(lastAddedNode->data.ICNumber,ya->data.ICNumber)<0){
		imbalStatus=1;
		s=ya->leftChild;
	}
	else{
		imbalStatus=-1;
		s=ya->rightChild;
	}
	
	if(ya->balanceFactor==0){
		ya->balanceFactor=imbalStatus;
		return;
	}
	
	if(ya->balanceFactor!=imbalStatus){
		ya->balanceFactor=0;
		return;
	}
	
	Node *p;
	if(s->balanceFactor==imbalStatus){
		if(imbalStatus==1) p=RightRotating(customerList, ya);
		else p=LeftRotating(customerList,ya);
		ya->balanceFactor=0;
		s->balanceFactor=0;
	}
	else{
		if(imbalStatus==1){
			p = LeftRotating(customerList,s);
			p=RightRotating(customerList,ya);
		}
		else{
			p= RightRotating(customerList,s);
			p=LeftRotating(customerList,ya);
		}
		if(p->balanceFactor==0){
			ya->balanceFactor=0;
			s->balanceFactor=0;
		}
		else{
			if(p->balanceFactor==imbalStatus){
				ya->balanceFactor=-imbalStatus;
				s->balanceFactor=0;
			}
			else{
				ya->balanceFactor=0;
				s->balanceFactor=imbalStatus;
			}
			p->balanceFactor=0;
		}
	}
}

void GetHeight(Node* node, int height, int &maxHeight){

	if(node!=NULL){
		
		GetHeight(node->leftChild, height+1, maxHeight);
		if(height>maxHeight) maxHeight=height;
		GetHeight(node->rightChild, height+1, maxHeight);
		if(height>maxHeight) maxHeight=height;
		
	}
	
}

void UpdateBalanceFactorAfterDelete(Node *node){
	if(node!=NULL){
		UpdateBalanceFactorAfterDelete(node->leftChild);
		int leftHeight=1, rightHeight=1;
		if(node->leftChild!=NULL) GetHeight(node->leftChild, 1, leftHeight);
		else leftHeight=0;
		if(node->rightChild!=NULL) GetHeight(node->rightChild, 1, rightHeight);
		else rightHeight=0;
		node->balanceFactor = leftHeight - rightHeight;
		UpdateBalanceFactorAfterDelete(node->rightChild);
	}
}

void ReBalanceTree(Node *node){
	Node *ya = node;
	
	int nodeBalance;
	while(ya!=NULL){
		int leftHeight=1, rightHeight=1;
		if(ya->leftChild!=NULL) GetHeight(ya->leftChild, 1, leftHeight);
		else leftHeight=0;
		if(ya->rightChild!=NULL) GetHeight(ya->rightChild, 1, rightHeight);
		else rightHeight=0;
		nodeBalance = leftHeight - rightHeight;
		if(nodeBalance<-1 || nodeBalance>1){
			break;
		}
		ya=ya->parent;
	}
	
	Node *p;
	if(ya!=NULL){
		if(nodeBalance>0){
			if(ya->leftChild->balanceFactor!=1){
				p=LeftRotating(customerList, ya->leftChild);
			}
			p=RightRotating(customerList, ya);
		}
		else if(nodeBalance<0){
			if(ya->rightChild->balanceFactor!=-1){
				p=RightRotating(customerList, ya->rightChild);
			}
			p=LeftRotating(customerList, ya);
		}
		UpdateBalanceFactorAfterDelete(p);
	}
	else{
		UpdateBalanceFactorAfterDelete(customerList.root);
	}
}

void InsertNodeIntoAVL(CustomerTree &list, Node *node){
	if(list.root==NULL){
		list.root = node;
	}
	else{
		Node *tmpNode = list.root;
		Node *p=list.root;
		while(tmpNode!=NULL){
			p=tmpNode;
			if(strcmp(node->data.ICNumber,tmpNode->data.ICNumber)<0){
				tmpNode = tmpNode->leftChild;
			}
			else if(strcmp(node->data.ICNumber,tmpNode->data.ICNumber)>0){
				tmpNode = tmpNode->rightChild;
			}
		}
		if(strcmp(node->data.ICNumber,p->data.ICNumber)<0){
			p->leftChild = node;
			node->parent = p;
		}
		else if(strcmp(node->data.ICNumber,p->data.ICNumber)>0){
			p->rightChild = node;
			node->parent = p;
		}
		BalanceTree(p, node);
	}
	list.size++;
}

Node *MostLeftNode(Node *node){
	Node *tmp = node;
	while(tmp->leftChild!=NULL){
		tmp = tmp->leftChild;
	}
	return tmp;
}

Node *FindNodeByICNumber(CustomerTree &list, char* ICNumber){
	Node *tmp = list.root;
	while(tmp!=NULL){
		if(strcmp(tmp->data.ICNumber,ICNumber)==0) return tmp;
		else if(strcmp(ICNumber,tmp->data.ICNumber)<0){
			tmp = tmp->leftChild;
		}
		else if(strcmp(ICNumber,tmp->data.ICNumber)>0){
			tmp = tmp->rightChild;
		}
	}
	return NULL;
}

void DeleteNodeFromAVL(CustomerTree &list, Node *node){
	if(node->parent==NULL){//Node root
		if(node->leftChild==NULL && node->rightChild==NULL){
			Node *tmp = node;
			list.root = NULL;
			delete tmp;
		}
		else if(node->leftChild==NULL){
			Node *tmp = node;
			list.root = node->rightChild;
			node->rightChild->parent = NULL;
			delete tmp;
		}
		else if(node->rightChild==NULL){
			Node *tmp = node;
			list.root = node->leftChild;
			node->leftChild->parent = NULL;
			delete tmp;
		}
		else{
			Node *mostLeft = MostLeftNode(node->rightChild);
			if(strcmp(mostLeft->data.ICNumber,mostLeft->parent->data.ICNumber)<0){
				node->data = mostLeft->data;
				mostLeft->parent->leftChild = (mostLeft->rightChild!=NULL)?mostLeft->rightChild:NULL;
				if(mostLeft->rightChild!=NULL) mostLeft->rightChild->parent = mostLeft->parent;
			}
			else if(strcmp(mostLeft->data.ICNumber,mostLeft->parent->data.ICNumber)>0){//Truong hop node trai nhat la node con phai node can xoa
				node->data = mostLeft->data;
				mostLeft->parent->rightChild = (mostLeft->rightChild!=NULL)?mostLeft->rightChild:NULL;
				if(mostLeft->rightChild!=NULL) mostLeft->rightChild->parent = mostLeft->parent;
			}
			Node *mostLeftParent = mostLeft->parent;
			delete mostLeft;
			ReBalanceTree(mostLeftParent);
		}
	}
	else{
		if(node->leftChild==NULL && node->rightChild==NULL){
			Node *tmp = node;
			if(strcmp(tmp->data.ICNumber,node->parent->data.ICNumber)<0){
				node->parent->leftChild = NULL;
			}
			else if(strcmp(tmp->data.ICNumber,node->parent->data.ICNumber)>0){
				node->parent->rightChild = NULL;
			}
			Node *parent = node->parent;
			delete tmp;
			ReBalanceTree(parent);
		}
		else if(node->leftChild==NULL){
			Node *tmp = node;
			if(strcmp(tmp->data.ICNumber,node->parent->data.ICNumber)<0){
				node->parent->leftChild = node->rightChild;
				node->rightChild->parent = node->parent;
			}
			else if(strcmp(tmp->data.ICNumber,node->parent->data.ICNumber)>0){
				node->parent->rightChild = node->rightChild;
				node->rightChild->parent = node->parent;
			}
			Node *parent = node->parent;
			delete tmp;
			ReBalanceTree(parent);
		}
		else if(node->rightChild==NULL){
			Node *tmp = node;
			if(strcmp(tmp->data.ICNumber,node->parent->data.ICNumber)<0){
				node->parent->leftChild = node->leftChild;
				node->leftChild->parent = node->parent;
			}
			else if(strcmp(tmp->data.ICNumber,node->parent->data.ICNumber)>0){
				node->parent->rightChild = node->leftChild;
				node->leftChild->parent = node->parent;
			}
			Node *parent = node->parent;
			delete tmp;
			ReBalanceTree(parent);
		}
		else{
			Node *mostLeft = MostLeftNode(node->rightChild);
			if(strcmp(mostLeft->data.ICNumber,mostLeft->parent->data.ICNumber)<0){
				node->data = mostLeft->data;
				mostLeft->parent->leftChild = (mostLeft->rightChild!=NULL)?mostLeft->rightChild:NULL;
				if(mostLeft->rightChild!=NULL) mostLeft->rightChild->parent = mostLeft->parent;
			}
			else if(strcmp(mostLeft->data.ICNumber,mostLeft->parent->data.ICNumber)>0){//Truong hop node trai nhat la node con phai node can xoa
				node->data = mostLeft->data;
				mostLeft->parent->rightChild = (mostLeft->rightChild!=NULL)?mostLeft->rightChild:NULL;
				if(mostLeft->rightChild!=NULL) mostLeft->rightChild->parent = mostLeft->parent;
			}
			Node *mostLeftParent = mostLeft->parent;
			delete mostLeft;
			ReBalanceTree(mostLeftParent);
		}
	}

	list.size--;
}

void GetAllDataInTree(Node *node, int &i, int &j, Table &tbl){
	if(node!=NULL && i<=pageTableControl.currentPage*10+10){
		GetAllDataInTree(node->leftChild, i, j, tbl);
		if(i>=pageTableControl.currentPage*10 && i<=pageTableControl.currentPage*10+9){
			AddCellTableContent(tbl, j, 0, node->data.ICNumber);
			AddCellTableContent(tbl, j, 1, node->data.fullName);
			AddCellTableContent(tbl, j, 2, node->data.gender);
			j++;
		}
		i++;
		GetAllDataInTree(node->rightChild, i, j, tbl);
	}
}

void ClearAllTreeList(Node *node){
	if(node!=NULL){
		ClearAllTreeList(node->leftChild);
		ClearAllTreeList(node->rightChild);
		delete node;
	}
}

void ClearAllDataFromTree(CustomerTree &list){
	ClearAllTreeList(list.root);
	list.size=0;
	list.root=NULL;
}

void ActiveCustomer(CustomerTree &list, char *ICNumber){
	Node *tmp = list.root;
	while(tmp!=NULL){
		if(strcmp(tmp->data.ICNumber,ICNumber)==0){
//			std::cout<<"Hello"<<std::endl;
			tmp->data.isActive++;
			break;
		}
		else if(strcmp(ICNumber,tmp->data.ICNumber)<0){
			tmp = tmp->leftChild;
		}
		else if(strcmp(ICNumber,tmp->data.ICNumber)>0){
			tmp = tmp->rightChild;
		}
	}
}

void UpdateActiveCustomer(CustomerTree &list, char *ICNumber){
	Node *tmp = list.root;
	while(tmp!=NULL){
		if(strcmp(tmp->data.ICNumber,ICNumber)==0){
//			std::cout<<"Hello"<<std::endl;
			tmp->data.isActive--;
			break;
		}
		else if(strcmp(ICNumber,tmp->data.ICNumber)<0){
			tmp = tmp->leftChild;
		}
		else if(strcmp(ICNumber,tmp->data.ICNumber)>0){
			tmp = tmp->rightChild;
		}
	}
}

bool isActive(CustomerTree &list, char *ICNumber){
	if(FindNodeByICNumber(list, ICNumber)->data.isActive==0) return false;
	return true;
}

void EditCustomerByICNumber(CustomerTree &list, char *ICNumber, char* cusFName, char *cusLName, char *fullName, char *gender){
	Node *tmp = FindNodeByICNumber(list, ICNumber);
	strcpy(tmp->data.fName,cusFName);
	strcpy(tmp->data.name,cusLName);
	strcpy(tmp->data.fullName,fullName);
	strcpy(tmp->data.gender,gender);
}

bool isCustomerInTimeRange(FlightList list, DateTime tmpStartTime, char *ICNumber){
	NodeFlight *tmp = list.phead;
	while(tmp!=NULL){
		if(tmp->data.status==0 || tmp->data.status==3){
		}
		else{
			unsigned long int minFlightStart = MinDiff(tmp->data.timeStart);
			unsigned long int minFlightEnd = minFlightStart+180;
			unsigned long int minNewStart = MinDiff(tmpStartTime);
			unsigned long int minNewEnd = minNewStart+180;
			
			if((minNewStart>=minFlightStart && minNewStart<=minFlightEnd) ||
			(minNewEnd>=minFlightStart && minNewEnd<=minFlightEnd)
			){
				for(int i=0; i<tmp->data.ticket.size; i++){
					if(strcmp(tmp->data.ticket.tickets[i].idPersonalNumber, ICNumber)==0){
						return true;
					}
				}
			}
				
		}
		tmp=tmp->pNext;
	}
	return false;
}
