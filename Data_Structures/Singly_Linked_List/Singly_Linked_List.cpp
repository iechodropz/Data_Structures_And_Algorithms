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
class SinglyLinkedList{
	private:
		Node<T>* head; 

		int LINKED_LIST_SIZE; 

	public:
		SinglyLinkedList(){
			head = NULL; 

			LINKED_LIST_SIZE = 1; 
		}

		Node<T>* get_head(){
			return head;
		}

		void update_head(Node<T>* new_head){
			this->head = new_head;
		}

		void insert_at_beginning(T data){
			Node<T>* node_to_insert = new Node<T>(); 

			node_to_insert->insert_data(data); 
			node_to_insert->next = head; 

			head = node_to_insert; 

			LINKED_LIST_SIZE++;
		}

		void insert_at_end(T data){
			insert_at_position(data, LINKED_LIST_SIZE);
		}

		void insert_at_position(T data, int position){
			if(position < 1){
				cout << "Error: Cannot insert node with data = " << data << " at position = " << position << ", must enter a value for position greater than 1." << endl << endl;
			}
			else if(position > LINKED_LIST_SIZE){
				cout << "Error: Cannot insert node with data = " << data << " at position = " << position << ", must enter a value for position less than or equal to the size of the linked list + 1." << endl << endl;
			}
			else if(position == 1){
				insert_at_beginning(data);
			}
			else{
				Node<T>* node_to_insert = new Node<T>();

				node_to_insert->insert_data(data);
				node_to_insert->next = NULL;

				Node<T>* previous_node = head;
				for(int i = 1; i < position - 1; i++){
					previous_node = previous_node->next;
				}

				node_to_insert->next = previous_node->next;
				previous_node->next = node_to_insert;

				LINKED_LIST_SIZE++;
			}
		}

		void delete_at_position(int position){
			LINKED_LIST_SIZE--; // Because for example, if linked list size is 3 we can insert node at position 4 but we cannot delete node at position 4.
			Node<T>* node_at_old_head = head;

			if(position < 1){
				cout << "Error: Cannot delete node at poisition = " << position << ", must enter a value for position greater than or equal to one." << endl << endl;
			}
			else if(position > LINKED_LIST_SIZE){
				cout << "Error: Cannot delete node at position = " << position << ", must enter a value for position less than or equal to the size of the linked list." << endl << endl;

			}
			else if(head == NULL){
				cout << "Error: The linked list is empty." << endl;
			}
			else if(position == 1){
				head = node_at_old_head->next;

				delete node_at_old_head;
			}
			else{
				Node<T>* previous_node = head;
				for(int i = 1; i < position - 1; i++){
			 		previous_node = previous_node->next;
				}

				Node<T>* node_to_delete = previous_node->next;

				previous_node->next = node_to_delete->next;

				delete node_to_delete;
			}

			LINKED_LIST_SIZE++; // Undo the LINKED_LIST_SIZE-- at the start of the function.
		}

		void reverse_linked_list(){
			// Initializes some pointers.
			Node<T>* current_node = head;
			Node<T>* previous_node = NULL;
			Node<T>* next_node = NULL;

			while(current_node != NULL){
				next_node = current_node->next;
				current_node->next = previous_node;
				previous_node = current_node;
				current_node = next_node;
			}

			head = previous_node;
		}

		void reverse_linked_list_recursively(Node<T>* current_node){
			// Base case of the reccursion.
			if(current_node->next == NULL){
				head = current_node;
				return;
			}
			else{
				reverse_linked_list_recursively(current_node->next);

				Node<T>* previous_node = current_node->next;
				previous_node->next = current_node;
				current_node->next = NULL;
			}
		}

		void print_linked_list(){
			if(head == NULL){
				cout << "Error: Cannot print linked list since it is empty." << endl;
			}
			else{
				Node<T>* current_node = head;
				while(current_node != NULL){
					cout << current_node->get_data() << " ";
					current_node = current_node->next;
				}

				cout << endl;
			}
		}

		void print_linked_list_recursively(Node<T>* current_node){
			if(head == NULL){
				cout << "Error: Cannot print linked list since it is empty." << endl;
			}
			else if(current_node == NULL){
				return;
			}
			else{
				cout << current_node->get_data() << " ";

				print_linked_list_recursively(current_node->next);
			}
		}

		void print_linked_list_in_reverse_recrusively(Node<T>* current_node){
			if(head == NULL){
				cout << "Error: Cannot print linked list since it is empty." << endl;
			}
			// Base case.
			else if(current_node == NULL){
				return;
			}
			else{
				print_linked_list_in_reverse_recrusively(current_node->next);

				cout << current_node->get_data() << " ";
			}
		}
};

int main(int argc, char* argv[]){

	// cout << "Example for inserting a node at the beginning." << endl;
	// // **************************************************************************
	// SinglyLinkedList<string> test_insert_at_beginning;

	// test_insert_at_beginning.insert_at_beginning("five");
	// test_insert_at_beginning.insert_at_beginning("four");
	// test_insert_at_beginning.insert_at_beginning("three");
	// test_insert_at_beginning.insert_at_beginning("two");
	// test_insert_at_beginning.insert_at_beginning("one");

	// test_insert_at_beginning.print_linked_list();

	// cout << endl;
	// // ***************************************************************************


	// cout << "Example for inserting a node at nth position." << endl;
	// // ***************************************************************************
	// SinglyLinkedList<string> test_inserting_node;

	// test_inserting_node.insert_at_beginning("five");
	// test_inserting_node.insert_at_beginning("four");
	// test_inserting_node.insert_at_beginning("three");
	// test_inserting_node.insert_at_beginning("two");
	// test_inserting_node.insert_at_beginning("one");

	// test_inserting_node.print_linked_list();

	// test_inserting_node.insert_at_position("one",1);
	// test_inserting_node.insert_at_position("two",2);
	// test_inserting_node.insert_at_position("three",3);
	// test_inserting_node.insert_at_position("four",4);
	// test_inserting_node.insert_at_position("five",5);

	// test_inserting_node.print_linked_list();

	// cout << endl;
	// // ****************************************************************************


	// cout << "Example for deleting a node at nth position." << endl;
	// // ****************************************************************************
	// SinglyLinkedList<int> test_deleting_node;

	// test_deleting_node.insert_at_beginning(5);
	// test_deleting_node.insert_at_beginning(4);
	// test_deleting_node.insert_at_beginning(3);
	// test_deleting_node.insert_at_beginning(2);
	// test_deleting_node.insert_at_beginning(1);

	// test_deleting_node.print_linked_list();

	// test_deleting_node.delete_at_position(4);

	// test_deleting_node.print_linked_list();

	// cout << endl;
	// // ***************************************************************************


	// cout << "Example for reversing a linked list." << endl;
	// // ***************************************************************************
	// SinglyLinkedList<int> test_reversing;
	// test_reversing.insert_at_beginning(5);
	// test_reversing.insert_at_beginning(4);
	// test_reversing.insert_at_beginning(3);
	// test_reversing.insert_at_beginning(2);
	// test_reversing.insert_at_beginning(1);

	// test_reversing.print_linked_list();

	// test_reversing.reverse_linked_list();

	// test_reversing.print_linked_list();

	// cout << endl;
	// //***************************************************************************


	// cout << "Example for printing linked list using recursion." << endl;
	// // ***************************************************************************
	// SinglyLinkedList<int> test_recursion_print;

	// test_recursion_print.insert_at_beginning(5);
	// test_recursion_print.insert_at_beginning(4);
	// test_recursion_print.insert_at_beginning(3);
	// test_recursion_print.insert_at_beginning(2);
	// test_recursion_print.insert_at_beginning(1);

	// test_recursion_print.print_linked_list_recursively(test_recursion_print.get_head());

	// cout << endl << endl;
	// // ***************************************************************************


	// cout << "Example for printing linked list in reverse order using recursion." << endl;
	// // *************************************************************************
	// SinglyLinkedList<int> test_recursion_reverse_print;

	// test_recursion_reverse_print.insert_at_beginning(5);
	// test_recursion_reverse_print.insert_at_beginning(4);
	// test_recursion_reverse_print.insert_at_beginning(3);
	// test_recursion_reverse_print.insert_at_beginning(2);
	// test_recursion_reverse_print.insert_at_beginning(1);

	// test_recursion_reverse_print.print_linked_list_in_reverse_recrusively(test_recursion_reverse_print.get_head());

	// cout << endl << endl;
	// // **************************************************************************


	// cout << "Example for reversing a linked list using recursion." << endl;
	// // *************************************************************************
	// SinglyLinkedList<int> test_recursion_reversing;

	// test_recursion_reversing.insert_at_beginning(5);
	// test_recursion_reversing.insert_at_beginning(4);
	// test_recursion_reversing.insert_at_beginning(3);
	// test_recursion_reversing.insert_at_beginning(2);
	// test_recursion_reversing.insert_at_beginning(1);

	// test_recursion_reversing.reverse_linked_list_recursively(test_recursion_reversing.get_head());

	// test_recursion_reversing.print_linked_list();
	// //***************************************************************************

	return 0;
};