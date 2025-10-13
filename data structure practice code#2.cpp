#include<iostream>
using std::cin;
using std::cout;
using std::endl;

struct Node {	//定義節點結構

	int data;	
	Node* next;

	Node(int value) :data(value), next(nullptr) {}	//建構子:data結構為一個值
};

Node* createNode(int value) {		//建立節點函式
	Node* newNode = new Node(value);		//c++中使用new
	if (!newNode) {
		cout << "memeory failed\n";
		exit(1);
	}
	return newNode;
}

void traverselist(Node* head) {
	Node* current = head;	//head為current(此例為10)
	int index = 0;			//index是節點
		
	while (current != nullptr) {
		cout << "NODE:"<< index;
		cout << " VALUE:" << current->data;	//current->data為一值(此例為10)
		cout << " ADRESS:" << current;		//current為一地址(此例為10的地址)
		cout << " NEXT ADRESS:" << current->next	//current->next為一地址(此例為20的地址)
		<< endl;
		
		current = current->next;	//換成20為current
		index++;					//index++，繼續跑while
	}
}

int main() {

	Node* head = createNode(10);
	head->next = createNode(20);
	head->next->next = createNode(30);

	cout << "traverse list 10~30:\n";
	traverselist(head);


	Node* current = head;		//free
	while (current != nullptr) {
		Node* temp = current;	//10為temp
		current=current->next;	//10的下一個變成current(20 = current)
		delete temp;			//delete 10
	}
	return 0;
}


//run:
//traverse list 10~30:
//NODE:0 VALUE : 10 ADRESS : 0000016ADF8A4B40 NEXT ADRESS : 0000016ADF8A54F0
//NODE : 1 VALUE : 20 ADRESS : 0000016ADF8A54F0 NEXT ADRESS : 0000016ADF8A57C0
//NODE : 2 VALUE : 30 ADRESS : 0000016ADF8A57C0 NEXT ADRESS : 0000000000000000