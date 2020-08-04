#include <iostream>
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

template<typename T>
class QueueSinglyLinkedList{

	private:
		SinglyLinkedList<T> queue;

	public:
		void enqueue(T data){
			queue.insert_at_end(data);
		}

		void dequeue(){
			queue.delete_at_position(1);
		}

		Node<T>* front(){
			if(queue.get_head() == NULL){
				cout << "Error: Can't get the front of the queue since it is empty." << endl;
			}
			else{
				return queue.get_head();
			}
		}

		bool is_empty(){
			if(queue.get_head() == NULL){
				return true;
			}
			else{
				return false;
			}
		}

		void print_queue(){
			if(queue.get_head() == NULL){
				cout << "Error: Can't print queue since the queue is empty." << endl;
			}
			else{
				Node<T>* current_node = queue.get_head();
				while(current_node != NULL){
					cout << current_node->get_data() << " ";
					current_node = current_node->next;
				}
			}

			cout << endl;
		}
};

int main(int argc, char* argv[]){

	// cout << "Example for inserting data to the queue." << endl;
	// // **************************************************************************
	// QueueSinglyLinkedList<string> testing_enqueue;

	// testing_enqueue.enqueue("one");
	// testing_enqueue.enqueue("two");
	// testing_enqueue.enqueue("three");
	// testing_enqueue.enqueue("four");
	// testing_enqueue.enqueue("five");

	// testing_enqueue.print_queue();

	// cout << endl;
	// // ***************************************************************************


	// cout << "Example for deleting data from the queue." << endl;
	// // *************************************************************************
	// QueueSinglyLinkedList<int> testing_dequeue;

	// testing_dequeue.enqueue(1);
	// testing_dequeue.enqueue(2);
	// testing_dequeue.enqueue(3);
	// testing_dequeue.enqueue(4);
	// testing_dequeue.enqueue(5);

	// testing_dequeue.print_queue();

	// testing_dequeue.dequeue();
	// testing_dequeue.dequeue();
	// testing_dequeue.dequeue();

	// testing_dequeue.print_queue();

	// cout << endl;
	// // ****************************************************************************


	// cout << "Example for getting the data at the beginning of the queue." << endl;
	// // ****************************************************************************
	// QueueSinglyLinkedList<int> testing_front;

	// testing_front.enqueue(1);
	// testing_front.enqueue(2);
	// testing_front.enqueue(3);
	// testing_front.enqueue(4);
	// testing_front.enqueue(5);

	// testing_front.print_queue();

	// cout << testing_front.front()->get_data() << endl;

	// cout << endl;
	// // ***************************************************************************


	// cout << "Exmaple for testing if the queue is empty." << endl;
	// // ***************************************************************************
	// QueueSinglyLinkedList<int> testing_is_empty;

	// testing_is_empty.enqueue(1);
	// testing_is_empty.enqueue(2);
	// testing_is_empty.enqueue(3);
	// testing_is_empty.enqueue(4);
	// testing_is_empty.enqueue(5);

	// testing_is_empty.print_queue();

	// cout << testing_is_empty.is_empty() << endl;


	// testing_is_empty.dequeue();
	// testing_is_empty.dequeue();
	// testing_is_empty.dequeue();
	// testing_is_empty.dequeue();
	// testing_is_empty.dequeue();

	// testing_is_empty.print_queue();

	// cout << testing_is_empty.is_empty() << endl;
	// // ************************************************************************

	return 0;
}