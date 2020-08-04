#include <iostream>
#include <string>
using namespace std;

template<typename T>
class Node{
	private:
		T data; 

	public:
		Node* next; 
		Node* previous; 

		Node(){
			next = NULL; 
			previous = NULL; 
		}

		void insert_data(T data){
			this->data = data; 
		}

		T get_data(){
			return this->data;
		}
};

template<typename T>
class DoublyLinkedList{
	private:
		Node<T>* head; 

		int LINKED_LIST_SIZE; 

	public:
		DoublyLinkedList(){
			head = NULL; 

			LINKED_LIST_SIZE = 1;
		}

		Node<T>* get_head(){
			return head;
		}

		void update_head(Node<t>* new_head){
			this->head = new_head;
		}

		void insert_at_beginning(T data){
			Node<T>* node_to_insert = new Node<T>();

			node_to_insert->insert_data(data); 
			node_to_insert->next = head;
			node_to_insert->previous = NULL; 

			if(head == NULL){
				head = node_to_insert; 
			}
			else{
				head->previous = node_to_insert; 
				head = node_to_insert; 
			}

			LINKED_LIST_SIZE++;
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
				node_to_insert->previous = NULL; 

				Node<T>* node_at_position = head;
				for(int i = 1; i < position; i++){ 
					node_at_position = node_at_position->next;
				}

				node_to_insert->next = node_at_position; 
				node_to_insert->previous = node_at_position->previous; 

				node_at_position->previous->next = node_to_insert; 
				node_at_position->previous = node_to_insert; 

				LINKED_LIST_SIZE++;
			}
		}

		void delete_at_position(int position){
			LINKED_LIST_SIZE--;  // Because for example, if linked list size is 3 we can insert node at position 4 but we cannot delete node at position 4.
			Node<T>* node_at_old_head = head; 

			if(position < 1){
				cout << "Error: Cannot delete node at poisition = " << position << ", must enter a value for position greater than or equal to one." << endl << endl;
			}
			else if(position > LINKED_LIST_SIZE){
				cout << "Error: Cannot delete node at position = " << position << ", must enter a value for position less than or equal to the size of the linked list." << endl << endl;

			}
			else if(position == 1){
				head = node_at_old_head->next; 
				head->previous = NULL; 

				delete node_at_old_head; 
			}
			else if(position == LINKED_LIST_SIZE){
				Node<T>* node_at_old_end = head;
				for(int i = 1; i < position; i++){
			 		node_at_old_end = node_at_old_end->next;
				}

				node_at_old_end->previous->next = node_at_old_end->next;

				delete node_at_old_end; 
			}
			else{
				Node<T>* node_at_position = head;
				for(int i = 1; i < position; i++){ 
			 		node_at_position = node_at_position->next;
				}

				node_at_position->previous->next = node_at_position->next; 
				node_at_position->next->previous = node_at_position->previous; 

				delete node_at_position;
			}

			LINKED_LIST_SIZE++; // Undo the LINKED_LIST_SIZE-- at the start of the function..
		}

		void reverse_linked_list(){
			// Initializes some pointers.
			Node<T>* current_node = head;
			Node<T>* previous_node = NULL;
			Node<T>* next_node = NULL;

			while(current_node != NULL){
				if(current_node->next == NULL){
					head = current_node;
				}

				next_node = current_node->next;
				current_node->next = current_node->previous;
				current_node->previous = next_node;
				current_node = next_node;
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

		void print_linked_list_in_reverse(){
			if(head == NULL){
				cout << "Error: Cannot print linked list since it is empty." << endl;
			}
			else{
				Node<T>* current_node = head;
				
				while(current_node->next != NULL){
					current_node = current_node->next;
				}

				while(current_node != NULL){
					cout << current_node->get_data() << " ";
					current_node = current_node->previous;
				}

				cout << endl;
			}

		}
};

int main(int argc, char* argv[]){

	// cout << "Example for inserting a node at the beginning." << endl;
	// // **************************************************************************
	// DoublyLinkedList<string> test_insert_at_beginning;

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
	// DoublyLinkedList<string> test_inserting_node;

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
	// DoublyLinkedList<int> test_deleting_node;

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
	// DoublyLinkedList<int> test_reversing;
	
	// test_reversing.insert_at_beginning(5);
	// test_reversing.insert_at_beginning(4);
	// test_reversing.insert_at_beginning(3);
	// test_reversing.insert_at_beginning(2);
	// test_reversing.insert_at_beginning(1);

	// test_reversing.print_linked_list();

	// test_reversing.reverse_linked_list();

	// test_reversing.print_linked_list();
	// //***************************************************************************

	return 0;
}