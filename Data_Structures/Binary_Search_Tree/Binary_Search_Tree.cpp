#include <iostream>
#include <algorithm>
#include <queue>
#include <limits.h>
using namespace std;

template<typename T>
class Node{
	private:
		T data;

	public:
		Node* right;
		Node* left;

		Node(){
			this->right = NULL;
			this->left = NULL;
		}

		T get_data(){
			return this->data;
		}

		void insert_data(T data){
			this->data = data;
		}
};

template<typename T>
class BinarySearchTree{
	public:
		Node<T>* root;
		int counter = 0;

		BinarySearchTree(){
			this->root = NULL;
		}

		Node<T>* delete_data(Node<T>* current_node, T data){
			if(current_node == NULL){
				return current_node;
			}
			else if(data < current_node->get_data()){
				current_node->left = delete_data(current_node->left, data);
			}
			else if(data > current_node->get_data()){
				current_node->right = delete_data(current_node->right, data);
			}
			else{
				if(current_node->left == NULL && current_node->right == NULL){
					delete current_node;

					current_node = NULL;
				}
				else if(current_node->left == NULL){
					Node<T>* node_to_delete = current_node;

					current_node = current_node->right;

					delete node_to_delete;
				}
				else if(current_node->right == NULL){
					Node<T>* node_to_delete = current_node;

					current_node = current_node->left;

					delete node_to_delete;
				}
				else{
					T min_data = min_data_recursively(current_node->right);

					current_node->insert_data(min_data);

					current_node->right =  delete_data(current_node->right, min_data);
				}

				return current_node;
			}
		}

		int height(){
			if(this->root == NULL){
				return -1;
			}
			else{
				queue<Node<T>*> nodes;
				int height = -1;

				nodes.push(this->root);

				while(true){
					int nodes_to_check = nodes.size();

					if(nodes_to_check == 0){
						return height;
					}

					height++;

					while(nodes_to_check > 0){
						Node<T>* node = nodes.front();

						nodes.pop();

						if(node->left != NULL){
							nodes.push(node->left);
						}

						if(node->right != NULL){
							nodes.push(node->right);
						}

						nodes_to_check--;
					}

				}
			}
		}

		int height_recursively(Node<T>* current_node){
			if(current_node == NULL){
				return -1;
			}
			else{
				return max(height_recursively(current_node->left), height_recursively(current_node->right)) + 1;
			}
		}
		
		bool if_found(T data){
			if(this->root == NULL){
				return false;
			}
			else if(this->root->get_data() == data){
				return true;
			}
			else if(this->root != NULL){
				Node<T>* current_node = this->root;

				while(current_node != NULL && current_node->get_data() != data){
					if(data <= current_node->get_data()){
						current_node = current_node->left;
					}
					else{
						current_node = current_node->right;
					}
				}

				if(current_node == NULL){
					return false;
				}
				else{
					return true;
				}
			}
			else{
				cout << "Error: In if_found() function." << endl;
			}

		}

		bool if_found_recursively(T data, Node<T>* current_node){
			if(current_node == NULL){
				return false;
			}
			else if(current_node->get_data() == data){
				return true;
			}
			else if(data < current_node->get_data()){
				return if_found_recursively(data, current_node->left);
			}
			else if(data > current_node->get_data())
				return if_found_recursively(data, current_node->right);
			else{
				cout << "Error: In in_tree() function." << endl;
			}
		}

		void insert(T data){
			if(this->root == NULL){
				Node<T>* new_node = new Node<T>();
				new_node->insert_data(data);

				this->root = new_node;
			}
			else if(this->root != NULL){
				Node<T>* new_node = new Node<T>();
				new_node->insert_data(data);

				Node<T>* current_node = this->root;
				Node<T>* previous_node = NULL;

				while(current_node != NULL){
					if(data <= current_node->get_data()){
						previous_node = current_node;
						current_node = current_node->left;
					}
					else{
						previous_node = current_node;
						current_node = current_node->right;
					}
				}

				if(data <= previous_node->get_data()){
					previous_node->left = new_node;
				}
				else{
					previous_node->right = new_node;
				}
			}
			else{
				cout << "Error: In insert() function." << endl;
			}

		}

		Node<T>* insert_recursively(T data, Node<T>** current_node){
			if(*current_node == NULL){
				Node<T>* new_node = new Node<T>();
				new_node->insert_data(data);

				*current_node = new_node;
			}
			else if(data <= (*current_node)->get_data()){
				(*current_node)->left = insert_recursively(data, &(*current_node)->left);
			}
			else if(data > (*current_node)->get_data()){
				(*current_node)->right = insert_recursively(data, &(*current_node)->right);
			}
			else{
				cout << "Error: In insert_recursively() function." << endl;
			}

			return *current_node;
		}

		bool is_binary_search_tree(Node<T>* current_node, int min_value, int max_value){
			if(current_node == NULL){
				return true;
			}
			else if(current_node->get_data() > min_value && current_node->get_data() < max_value
					&& is_binary_search_tree(current_node->left, min_value, current_node->get_data())
					&& is_binary_search_tree(current_node->right, current_node->get_data(), max_value)){

				return true;
			}
			else{
				return false;
			}
		}

		T max_data(){
			Node<T>* current_node = this->root;

			if(root != NULL){
				while(current_node->right != NULL){
					current_node = current_node->right;
				}

				return current_node->get_data();
			}
			else if(root == NULL){
				cout << "Error: In max_data() function, tree is empty." << endl;
			}
			else {
				cout << "Error: In max_data() function." << endl;
			}
		}

		T max_data_recursively(Node<T>* current_node){
			if(this->root != NULL){
				if(current_node->right == NULL){
					return current_node->get_data();
				}
				else{
					return max_data_recursively(current_node->right);
				}
			}
			else if(this->root == NULL){
				cout << "Error: In max_data_recursively() function, tree is empty." << endl;
			}
			else{
				cout << "Error: In max_data_recursively() function." << endl;
			}
		}

		T min_data(){
			Node<T>* current_node = this->root;

			if(root != NULL){
				while(current_node->left != NULL){
					current_node = current_node->left;
				}

				return current_node->get_data();
			}
			else if(root == NULL){
				cout << "Error: In min_data() function, tree is empty." << endl;
			}
			else{
				cout << "Error: In min_data() function." << endl;
			}
		}

		T min_data_recursively(Node<T>* current_node){
			if(this->root != NULL){
				if(current_node->left == NULL){
					return current_node->get_data();
				}
				else{
					return min_data_recursively(current_node->left);
				}
			}
			else if(this->root == NULL){
				cout << "Error: In min_data_recursively() function, tree is empty." << endl;
			}
			else{
				cout << "Error: In min_data_recursively() function." << endl;
			}
		}

		void print_level_order_traversal(){
			if(this->root == NULL){
				return;
			}
			else{
				queue<Node<T>*> nodes_queue;

				nodes_queue.push(this->root);

				while(nodes_queue.empty() == false){
					Node<T>* current_node = nodes_queue.front();

					cout << current_node->get_data() << endl;

					if(current_node->left != NULL){
						nodes_queue.push(current_node->left);
					}

					if(current_node->right != NULL){
						nodes_queue.push(current_node->right);
					}

					nodes_queue.pop();
				}
			}
		}

		void print_preorder(Node<T>* current_node){
			if(current_node == NULL){
				return;
			}
			else{
				cout << current_node->get_data() << endl;

				print_preorder(current_node->left);
				print_preorder(current_node->right);
			}
		}

		void print_inorder(Node<T>* current_node){
			if(current_node == NULL){
				return;
			}
			else{
				print_inorder(current_node->left);

				cout << current_node->get_data() << endl;

				print_inorder(current_node->right);
			}
		}

		void print_postorder(Node<T>* current_node){
			if(current_node == NULL){
				return;
			}
			else{
				print_postorder(current_node->left);
				print_postorder(current_node->right);

				cout << current_node->get_data() << endl;
			}
		}
};

int main(int argc, char* argv[]){

	// cout << "Example for inserting a node recursively." << endl;
	// // **************************************************************************
	// BinarySearchTree<int> test_insert_recursively;

	// test_insert_recursively.insert_recursively(1, &test_insert_recursively.root);
	// test_insert_recursively.insert_recursively(2, &test_insert_recursively.root);
	// test_insert_recursively.insert_recursively(3, &test_insert_recursively.root);
	// test_insert_recursively.insert_recursively(4, &test_insert_recursively.root);
	// test_insert_recursively.insert_recursively(5, &test_insert_recursively.root);

	// cout << test_insert_recursively.if_found_recursively(6, test_insert_recursively.root) << endl;

	// cout << endl;
	// // // ***************************************************************************


	// cout << "Example for inserting a node." << endl;
	// // *****************************************************************************
	// BinarySearchTree<int> test_insert;

	// test_insert.insert(1);
	// test_insert.insert(2);
	// test_insert.insert(3);
	// test_insert.insert(4);
	// test_insert.insert(5);

	// cout << test_insert.if_found_recursively(5, test_insert.root) << endl;

	// cout << endl;
	// // *****************************************************************************


	// cout << "Example for checking if data is in tree." << endl;
	// // *******************************************************************************
	// BinarySearchTree<int> test_if_found;

	// test_if_found.insert(1);
	// test_if_found.insert(2);
	// test_if_found.insert(3);
	// test_if_found.insert(4);
	// test_if_found.insert(5);

	// cout << test_if_found.if_found(5) << endl;

	// cout << endl;
	// // *****************************************************************************


	// cout << "Example for finding min data." << endl;
	// // ************************************************************************
	// BinarySearchTree<int> test_min_data;

	// test_min_data.insert(1);
	// test_min_data.insert(2);
	// test_min_data.insert(3);
	// test_min_data.insert(4);
	// test_min_data.insert(5);

	// cout << test_min_data.min_data() << endl;

	// cout << endl;
	// // ************************************************************************


	// cout << "Example for finding min data recursively." << endl;
	// // ***********************************************************************
	// BinarySearchTree<int> test_min_data_recursively;
	
	// test_min_data_recursively.insert(1);
	// test_min_data_recursively.insert(2);
	// test_min_data_recursively.insert(3);
	// test_min_data_recursively.insert(4);
	// test_min_data_recursively.insert(5);

	// cout << test_min_data_recursively.min_data_recursively(test_min_data_recursively.root) << endl;

	// cout << endl;
	// // **************************************************************************


	// cout << "Example for finding max data." << endl;
	// // *************************************************************************
	// BinarySearchTree<int> test_max_data;

	// test_max_data.insert(1);
	// test_max_data.insert(2);
	// test_max_data.insert(3);
	// test_max_data.insert(4);
	// test_max_data.insert(5);

	// cout << test_max_data.max_data() << endl;

	// cout << endl;
	// // **************************************************************************


	// cout << "Example for finding max data recursively." << endl;
	// // ****************************************************************************
	// BinarySearchTree<int> test_max_data_recursively;

	// test_max_data_recursively.insert(1);
	// test_max_data_recursively.insert(2);
	// test_max_data_recursively.insert(3);
	// test_max_data_recursively.insert(4);
	// test_max_data_recursively.insert(5);

	// cout << test_max_data_recursively.max_data_recursively(test_max_data_recursively.root) << endl;

	// cout << endl;
	// // ***************************************************************************


	// cout << "Example for finding height recursively." << endl;
	// // **************************************************************************
	// BinarySearchTree<int> test_height_recursively;

	// test_height_recursively.insert(8);
	// test_height_recursively.insert(4);
	// test_height_recursively.insert(6);
	// test_height_recursively.insert(3);
	// test_height_recursively.insert(7);
	// test_height_recursively.insert(5);
	// test_height_recursively.insert(10);
	// test_height_recursively.insert(11);
	// test_height_recursively.insert(9);

	// cout << test_height_recursively.height_recursively(test_height_recursively.root) << endl;

	// cout << endl;
	// // **************************************************************************************


	// cout << "Example for finding height." << endl;
	// // ************************************************************************************
	// BinarySearchTree<int> test_height;

	// test_height.insert(8);
	// test_height.insert(4);
	// test_height.insert(6);
	// test_height.insert(3);
	// test_height.insert(7);
	// test_height.insert(5);
	// test_height.insert(10);
	// test_height.insert(11);
	// test_height.insert(9);

	// cout << test_height.height() << endl;

	// cout << endl;
	// // ***********************************************************************************


	// cout << "Example for printing data using level order traversal." << endl;
	// // *********************************************************************************
	// BinarySearchTree<int> test_print_level_order_traversal;

	// test_print_level_order_traversal.insert(8);
	// test_print_level_order_traversal.insert(4);
	// test_print_level_order_traversal.insert(6);
	// test_print_level_order_traversal.insert(3);
	// test_print_level_order_traversal.insert(7);
	// test_print_level_order_traversal.insert(5);
	// test_print_level_order_traversal.insert(10);
	// test_print_level_order_traversal.insert(11);
	// test_print_level_order_traversal.insert(9);

	// test_print_level_order_traversal.print_level_order_traversal();

	// cout << endl;
	// // *************************************************************************************


	// cout << "Example for printing data using preorder, inorder and postorder traversal." << endl;
	// // ******************************************************************************************
	// BinarySearchTree<int> test_pre_in_post_order_traversal;

	// test_pre_in_post_order_traversal.insert(8);
	// test_pre_in_post_order_traversal.insert(4);
	// test_pre_in_post_order_traversal.insert(6);
	// test_pre_in_post_order_traversal.insert(3);
	// test_pre_in_post_order_traversal.insert(7);
	// test_pre_in_post_order_traversal.insert(5);
	// test_pre_in_post_order_traversal.insert(10);
	// test_pre_in_post_order_traversal.insert(11);
	// test_pre_in_post_order_traversal.insert(9);

	// cout << "Preorder" << endl;
	// test_pre_in_post_order_traversal.print_preorder(test_pre_in_post_order_traversal.root);
	// cout << endl << "Inorder" << endl;
	// test_pre_in_post_order_traversal.print_inorder(test_pre_in_post_order_traversal.root);
	// cout << endl << "Postorder" << endl;
	// test_pre_in_post_order_traversal.print_postorder(test_pre_in_post_order_traversal.root);

	// cout << endl;
	// //**************************************************************************************


	// cout << "Example for testing if binary tree is a binary search tree." << endl;
	// // *****************************************************************************************
	// BinarySearchTree<int> test_is_binary_search_tree;

	// test_is_binary_search_tree.insert(8);
	// test_is_binary_search_tree.insert(4);
	// test_is_binary_search_tree.insert(6);
	// test_is_binary_search_tree.insert(3);
	// test_is_binary_search_tree.insert(7);
	// test_is_binary_search_tree.insert(5);
	// test_is_binary_search_tree.insert(10);
	// test_is_binary_search_tree.insert(11);
	// test_is_binary_search_tree.insert(9);

	// cout << test_is_binary_search_tree.is_binary_search_tree(test_is_binary_search_tree.root, INT_MIN, INT_MAX) << endl;

	// cout << endl;
	// // *******************************************************************************************


	// cout << "Example for deleting data from tree recursively." << endl;
	// // ***************************************************************************************
	// BinarySearchTree<int> test_delete_data_recursively;

	// test_delete_data_recursively.insert(8);
	// test_delete_data_recursively.insert(4);
	// test_delete_data_recursively.insert(6);
	// test_delete_data_recursively.insert(3);
	// test_delete_data_recursively.insert(7);
	// test_delete_data_recursively.insert(5);
	// test_delete_data_recursively.insert(10);
	// test_delete_data_recursively.insert(11);
	// test_delete_data_recursively.insert(9);
	// test_delete_data_recursively.insert(12);

	// test_delete_data_recursively.delete_data(test_delete_data_recursively.root, 8);

	// test_delete_data_recursively.print_inorder(test_delete_data_recursively.root);

	// cout << endl;
	// // ******************************************************************************************

	return 0;
}  