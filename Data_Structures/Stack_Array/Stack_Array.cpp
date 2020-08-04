#include <iostream>
#include <string>
using namespace std;
#define STACK_MAX_SIZE 100

template<typename T>
class StackArray{
	private:
		T stack_array[STACK_MAX_SIZE];
		int top;

	public:
		StackArray(){
			top = -1;
		}

		void push(T data){
			if(top == STACK_MAX_SIZE){
				cout << "Error: Cannot push anymore since the array is full." << endl;
			}
			else{
				top++;

				stack_array[top] = data;
			}
		}

		void pop(){
			if(top == -1){
				cout << "Error: No element to pop." << endl;
			}
			else{
				top--;
			}
		}

		T get_top(){
			if(is_empty == true){
				cout << "Error: Cannot get top since the stack is empty." << endl;
			}
			else{
				return stack_array[top];
			}
		}

		bool is_empty(){
			if(top == -1){
				return true;
			}
			else{
				return false;
			}
		}

		void print_stack(){
			if(top == -1){
				cout << "Error: Cannot print stack since it is empty." << endl;
			}
			else{
				for(int i = 0; i <= top; i++){
					cout << stack_array[i] << " ";
				}

				cout << endl;
			}
		}
};

int main(int argc, char* argv[]){

	// cout << "Exmaple of pushing data to the stack." << endl;
	// // *********************************************************************
	// StackArray<string> testing_push;

	// testing_push.push("one");
	// testing_push.push("two");
	// testing_push.push("three");
	// testing_push.push("four");
	// testing_push.push("five");

	// testing_push.print_stack();

	// cout << endl;
	// // **********************************************************************


	// cout << "Exmaple of poping data from the stack." << endl;
	// // **********************************************************************
	// StackArray<string> testing_pop;

	// testing_pop.push("one");
	// testing_pop.push("two");
	// testing_pop.push("three");
	// testing_pop.push("four");
	// testing_pop.push("five");

	// testing_pop.print_stack();

	// testing_pop.pop();
	// testing_pop.pop();
	// testing_pop.pop();

	// testing_pop.print_stack();

	// cout << endl;
	// // *********************************************************************


	// cout << "Example of getting the data at the top of the stack." << endl;
	// // **********************************************************************
	// StackArray<int> testing_get_top;

	// testing_get_top.push(1);
	// testing_get_top.push(2);
	// testing_get_top.push(3);
	// testing_get_top.push(4);
	// testing_get_top.push(5);

	// testing_get_top.print_stack();

	// cout << testing_get_top.get_top() << endl;

	// cout << endl;
	// // *********************************************************************


	// cout << "Example for testing if the stack is empty." << endl;
	// // **********************************************************************
	// StackArray<int> testing_is_empty;

	// cout << testing_is_empty.is_empty() << endl;

	// testing_is_empty.push(1);
	// testing_is_empty.push(2);
	// testing_is_empty.push(3);
	// testing_is_empty.push(4);
	// testing_is_empty.push(5);

	// cout << testing_is_empty.is_empty() << endl;
	// // ***************************************************************************

	return 0;
}