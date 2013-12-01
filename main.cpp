#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<list>
#include <algorithm>

#include <ctime>
using namespace std;

class StopWatch
{
	private:
		clock_t startedAt;
		clock_t stopAt;
		
	public:
		StopWatch();
		void Stop();
		void Start();
		clock_t secondsCalc();
};
StopWatch::StopWatch()
{
	startedAt = 0;
	stopAt = 0;
	
}

void StopWatch::Stop()
{
	stopAt = clock();
}
void StopWatch::Start()
{
	
	startedAt = clock();
}

clock_t StopWatch::secondsCalc()
{
	
	
	return stopAt - startedAt;
}

/*#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;*/
class Node 
{
	private:
		
		
		

	public:
		string data;
		Node *next;
		
		Node() {

		};
		void SetData(string aData) { data = aData; };
		void SetNext(Node *aNext) { next = aNext; };
		string Data() { return data; };
		Node* Next() { return next; };
		
};



class List
{
	public:
		Node* firstNode;
		Node* back;
		int size;
	
		

		List() {
			//Node* firstNode = new Node();
			firstNode = NULL;
			size = 0;
			//Node* back = new Node();
			back = firstNode;
		};
		
		void Add(string value);
		void push_front(string value);
		void insert(Node thisOne, Node newNode);
		void remove_element(int index);
		int getSize() {return size;};
		//void Print();
		void ListSearch(string target);


};

void List::Add(string value)
{
	Node* newNode = new Node();
	newNode->SetData(value);
	newNode->SetNext(NULL);
	//Node *tmp = firstNode;
	//int i = 0;
	if(firstNode != NULL)
	{
		
			
			//newNode->SetIndex(i+1);
			back->SetNext(newNode);
			back = newNode;
		
	}
	else //list is empty
	{
		firstNode = newNode;
		back = newNode;
	}
	size++;// increase size
}
void List::ListSearch(string target)
{
	Node* trace = this->firstNode;
	string hold = target;
	while (trace != NULL)
	{
		if(trace->Data() == hold)
		{
			cout << "found in List\n";
			break;
		}
		trace = trace->next;
	}
	if(trace = NULL)
		cout << "Not Found in List\n";
}



//_________________________________________
//avl node class since it will be a list
//_________________________________________
class AVL_Node
{
public:

	List* data;
	
	AVL_Node* left;
	AVL_Node* right;
	//AVL_Node* parent;
	//int right_depth;
	//int left_depth;

	AVL_Node(){
		List *data = new List();
		//data = NULL;
		//data->firstNode = NULL;
		//data->back = data->firstNode;
		//data->size = 0;
		
		//AVL_Node* left = new AVL_Node();
		left = NULL;
		//AVL_Node* right = new AVL_Node();
		right = NULL;
		//parent = NULL
	
	}


};

class AVL_Tree
{

public:
	AVL_Node* root_node;
	int size;
	

	AVL_Tree() { 
		//root_node = new AVL_Node();
		root_node = NULL;
		size = 0;
    
	}
	int getSize() const
	{
                return this->size;
    }
	AVL_Node* rotate_LL(AVL_Node *parent) 
	{ 
		AVL_Node *child = parent->left; 
		parent->left = child->right; 
		child->right = parent; 
		return child; 
	} 


	AVL_Node* rotate_RR(AVL_Node *parent) 
	{ 
		AVL_Node *child = parent->right; 
		parent->right = child->left; 
		child->left = parent; 
		return child; 
	} 


	AVL_Node* rotate_RL(AVL_Node *parent) 
	{ 
		AVL_Node *child = parent->right; 
		parent->right = rotate_LL(child); 
		return rotate_RR(parent); 
	} 


	AVL_Node* rotate_LR(AVL_Node *parent) 
	{ 
		AVL_Node *child = parent->left; 
		parent->left = rotate_RR(child); 
		return rotate_LL(parent); 
	} 
	int max(int a, int b)
	{
			return ( (a > b) ? a : b);
	}

	int get_height(AVL_Node *node) 
	{ 
		int height=0; 
		if(node != NULL) 
			height = 1 + max(get_height(node->left), get_height(node->right)); 
		return height; 
	} 

	void insert(string input)
	{
		AVL_Node* insert_node = new AVL_Node();
		insert_node = this->root_node;
		AVL_Node* cursor = new AVL_Node();
		cursor->data = new List();
		cursor->data->Add(input);

		if(insert_node == NULL)
		{
			this->root_node = new AVL_Node;
			this->root_node->data = new List();
			root_node->data->Add(input);
			//size++;
		}
		while(insert_node != NULL)
		{
			if(cursor->data->firstNode->Data() > insert_node->data->firstNode->Data())
			{
				if(insert_node->right == NULL) //insert
				{
					insert_node->right = cursor;
					//size++;

					if ((get_height(insert_node->left) - get_height(insert_node->right) )> 1){

						if((get_height(insert_node->left->left) - get_height(insert_node->left->right)) >0){
							insert_node = rotate_LL(insert_node);
						}else{
							insert_node = rotate_LR(insert_node);
						}
					}
					
					break;
				}else{// continue in loop
					insert_node = insert_node->right;
				}
			}
			else if(cursor->data->firstNode->Data() < insert_node->data->firstNode->Data())
			{
				if(insert_node->left == NULL)
				{
					insert_node->left = cursor;
					//size++;
					
					if ((get_height(insert_node->left) - get_height(insert_node->right) )< -1){

						if((get_height(insert_node->right->left) - get_height(insert_node->right->right)) <0){
							insert_node = rotate_RR(insert_node);
						}else{
							insert_node = rotate_RL(insert_node);
						}
					}
					
					break;
				}else{
					insert_node = insert_node->left;
				}
			}
			else if(cursor->data->firstNode->Data() == insert_node->data->firstNode->Data())
			{
				insert_node->data->Add(input);
				break;
			}

		}
		size++;
		
	}


	void search(string key)
	{
		AVL_Node* node = new AVL_Node();
		node = this->root_node;

		
		do{
			if(node == NULL) 
				cout<< "NOT FOUND"; 
     
			if(key == node->data->firstNode->Data()) 
			{

				cout << key << " was found in the tree and was repeated " << node->data->getSize() << " times" << endl;
				break;
			}

			else if(key < node->data->firstNode->Data()){
				if(node->left != NULL)
					node = node->left; 
				else
				{
					cout << "NOT FOUND\n";
					break;
				}

		}else{  
				if(node->right != NULL)
					node = node->right; 
				else
				{
					cout << "NOT FOUND\n";
					break;
				}
		}	
		}while(node != NULL);
	}

};

void avltree_demo(string fileName, string target);
void list_demo(string fileName, string target);
void vector_demo(string fileName, string target);

int main(int argc, char* argv[])
{
	string fileName;
	string target;
	if(argc >3)
	{
		fileName = argv[2];
		target = argv[4];
	}else if(argc==3){
		fileName = argv[1];
		target = argv[2];
	}else{
		cout << "Something is wrong with Command line input" << endl;
		fileName = "VLarge.txt";
		target = "white";
		cout << "Will Be searching for \"white\" in War and Peace instead\n";
	}
	cout << "___________________________________________\n";
	cout << "Begining AVLTree..\n";
	avltree_demo(fileName, target);
	cout << "___________________________________________\n";
	cout << "Beginning List\n";
	list_demo(fileName, target);
	cout << "___________________________________________\n";
	cout << "Beginning Vector\n";
	vector_demo(fileName, target);
	cout << "___________________________________________\n";
	
	cout << "\n";
	cout << "\n";
	cout << "\n";
	cout << "Coded By Andrew Pfundstein\n";

	system("PAUSE");

}
void avltree_demo(string fileName, string target)
{
	AVL_Tree *yolo = new AVL_Tree;
	StopWatch timer;
	
	
	ifstream file;
	//try 1
	file.open(fileName);
	
	string temp;
	timer.Start();
	if (file.is_open()) 
	{
		cout<<"Working..." << endl;
		while (file.good()) 
		{
			file >> temp;
			yolo->insert(temp);
		}
	}
	timer.Stop();
	cout << " List Size: " << yolo->getSize() << endl;
	clock_t total = timer.secondsCalc();
	cout<< endl;
	cout << "Insertion took " << total << "ticks  -- " << double(total*.001)<< " seconds"<< endl;
	file.close();
	
	StopWatch timer2;
	timer2.Start();
	yolo->search(target);
	timer2.Stop();
	total = timer2.secondsCalc();
	cout<< endl;
	cout << "Searching took " << total << "ticks  -- " << double(total*.001)<< " seconds"<< endl;
}

void list_demo(string fileName, string target)
{
	List *L = new List;
	ifstream file;
	//try 1
	file.open("VLarge.txt");
	StopWatch timer;
	string temp;
	timer.Start();
	if (file.is_open()) 
	{
		cout<<"Working..." << endl;
		while (file.good()) 
		{

			//getline (file, temp);

			file >> temp;
			L->Add(temp);
			//vec.push_back(temp);
			//cout << temp << "  ";
			
			


		}
	}
	timer.Stop();
	cout << " List Size: " << L->getSize() << endl;
	clock_t total = timer.secondsCalc();
	cout<< endl;
	cout << "that took " << total << "ticks  -- " << double(total*.001)<< " seconds"<< endl;
	file.close();

	StopWatch timer2;
	timer2.Start();
	L->ListSearch(target);
	timer2.Stop();
	total = timer2.secondsCalc();
	cout<< endl;
	cout << "Searching took " << total << "ticks  -- " << double(total*.001)<< " seconds"<< endl;


}
void vector_demo(string fileName, string target)
{
	string temp;
	vector<string> vec;
	ifstream file;
	file.open(fileName);
	
	StopWatch yolo2;
	yolo2.Start();
	if (file.is_open()) 
	{
		cout << "Working..." <<endl;
		while (file.good()) 
		{

			//getline (file, temp);

			file >> temp;
			//L->push_back(temp);
			vec.push_back(temp);
			//cout << temp << "  ";
			


		}
	}
	yolo2.Stop();
	cout << "Vector Size: " << vec.size() << endl;
	
	clock_t total = yolo2.secondsCalc();
	cout<< endl;
	cout << "insertion took " << total << "ticks  -- " << double(total*.001) << " seconds"<< endl;
	file.close();

	StopWatch timer2;
	timer2.Start();
	if(find(vec.begin(), vec.end(), target) != vec.end())
	{
		timer2.Stop();
		cout << "Item found in Vector \n";
	}else{
		timer2.Stop();
		cout << "Not Found in Vector\n";
	}
		

	total = timer2.secondsCalc();
	cout<< endl;
	cout << "Searching took " << total << "ticks  -- " << double(total*.001)<< " seconds"<< endl;

}