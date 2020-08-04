#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class QueueVector{
	private:
		vector<T> queue;

	public:
		void enqueue(T data){
			queue.push_back(data);
		}

		void dequeue(){
			if(queue.empty() == true){
				cout << "Error: Cant dequeue since the queue is empty." << endl;
			}
			else{
				queue.erase(queue.begin());
			}
		}

		T front(){
			if(queue.empty() == true){
				cout << "Error: Cannot get the front since the queue is empty." << endl;
			}
			else{
				return queue.at(0);
			}
		}

		bool is_empty(){
			return queue.empty();
		}

		void print_queue(){
			if(queue.empty() == true){
				cout << "Error: Cannot print the queue since the queue is empty." << endl;
			}
			else {
				for(int i = 0; i < queue.size(); i++){
					cout << queue.at(i) << " ";
				}
			}

			cout << endl;
		}
};

int main(int argc, char* argv[]){

	// cout << "Example for inserting data to the queue." << endl;
	// // **************************************************************************
	// QueueVector<string> testing_enqueue;

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
	// QueueVector<int> testing_dequeue;

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
	// QueueVector<int> testing_front;

	// testing_front.enqueue(1);
	// testing_front.enqueue(2);
	// testing_front.enqueue(3);
	// testing_front.enqueue(4);
	// testing_front.enqueue(5);

	// testing_front.print_queue();

	// cout << testing_front.front() << endl;

	// cout << endl;
	// // ***************************************************************************


	// cout << "Exmaple for testing if the queue is empty." << endl;
	// // ***************************************************************************
	// QueueVector<int> testing_is_empty;

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