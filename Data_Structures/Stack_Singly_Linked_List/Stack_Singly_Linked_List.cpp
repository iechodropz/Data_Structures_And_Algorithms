#include <iostream>
#include <string>
using namespace std;

template<typename T>
class Node{
	private:
		T data;

	public: 
		Node* next;

		Node(){
			next = NULL;
		}

		void insert_data(T data){
			this->data = data;
		}

		T get_data(){
			return this->data;
		}

};

template<typename T>
class StackSinglyLinkedList{
	private:
		Node<T>* top;

	public:
		StackSinglyLinkedList(){
			top = NULL;
		}

		void push(T data){
			Node<T>* node_to_insert = new Node<T>();

			node_to_insert->insert_data(data);
			node_to_insert->next = top;

			top = node_to_insert;
		}

		void pop(){
			if(top == NULL){
				cout << "Error: No element to pop." << endl;
			}
			else{
				Node<T>* node_at_old_top = top;
				top = node_at_old_top->next;
				delete node_at_old_top;
			}
		}

		T get_top(){
			if(top == NULL){
				cout << "Error: Cannot get top since the linked list is empty." << endl;
			}
			else{
				return top->get_data(); 
			}
		}

		bool is_empty(){
			if(top == NULL){
				return true;
			}
			else{
				return false;
			}
		}

		void print_stack(){
			if(top == NULL){
				cout << "Error: Cannot print linked list since it is empty." << endl;
			}
			else{
				Node<T>* current_node = top;
				while(current_node != NULL){
					cout << current_node->get_data() << " ";
					current_node = current_node->next;
				}

				cout << endl;
			}	
		}
};

int main(int argc, char* argv[]){

// 	cout << "Exmaple of pushing data to the stack." << endl;
// 	// *********************************************************************
// 	StackSinglyLinkedList<string> testing_push;

// 	testing_push.push("one");
// 	testing_push.push("two");
// 	testing_push.push("three");
// 	testing_push.push("four");
// 	testing_push.push("five");

// 	testing_push.print_stack();

// 	cout << endl;
// 	// **********************************************************************


// 	cout << "Exmaple of poping data from the stack." << endl;
// 	// **********************************************************************
// 	StackSinglyLinkedList<string> testing_pop;

// 	testing_pop.push("one");
// 	testing_pop.push("two");
// 	testing_pop.push("three");
// 	testing_pop.push("four");
// 	testing_pop.push("five");

// 	testing_pop.print_stack();

// 	testing_pop.pop();
// 	testing_pop.pop();
// 	testing_pop.pop();

// 	testing_pop.print_stack();

// 	cout << endl;
// 	// *********************************************************************


// 	cout << "Example of getting the data at the top of the stack." << endl;
// 	// **********************************************************************
// 	StackSinglyLinkedList<int> testing_get_top;

// 	testing_get_top.push(1);
// 	testing_get_top.push(2);
// 	testing_get_top.push(3);
// 	testing_get_top.push(4);
// 	testing_get_top.push(5);

// 	testing_get_top.print_stack();

// 	cout << testing_get_top.get_top() << endl;

// 	cout << endl;
// 	//*********************************************************************


// 	cout << "Example for testing if the stack is empty." << endl;
// 	// **********************************************************************
// 	StackSinglyLinkedList<int> testing_is_empty;

// 	cout << testing_is_empty.is_empty() << endl;

// 	testing_is_empty.push(1);
// 	testing_is_empty.push(2);
// 	testing_is_empty.push(3);
// 	testing_is_empty.push(4);
// 	testing_is_empty.push(5);

// 	cout << testing_is_empty.is_empty() << endl;
// 	// ***************************************************************************

	return 0;
}