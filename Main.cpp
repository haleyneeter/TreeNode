//This program will take a file of letters, read the file letter by letter, and if the letter hasn't been seen beofre in the file, it will create a new node of the binary tree.
//If the letter is a repeated letter, the code will add one to the count member of the preexisitng node already one the binary tree. Code will then display the frequencies of each letter
//in the tree.

#include <queue> //I was having a really diffcult time adding a count to the node if the letter already was in the binary tree. I was searching online and saw that I could use the
#include<fstream> //include<queue> to create a queue from the STL and to push each node to the queue, and to pop the node if letter has already been added to the queue.
#include<string>
#include<iostream>
#include<ctype.h> //needed for isalpha 
using namespace std; 



struct node 
{ 
	char letter; 
	int count; 
	node *left, *right; 
}; 


node* insert(char);                 //prototypes
node* insertNode(node*, char);
void displayNode(node*);



node* insert(char letter) 
{ 

	node* newnode = new node; 
	newnode->letter = letter; 
	newnode->count = 1; 
	newnode->left = newnode->right = NULL; 

	return newnode; 
} 


node* insertNode(node* root, char letter) 
{ 

	if (root == NULL) 
	{ 
		return insert(letter); 
	} 

	queue<node*> Q;  //makes queue named Q that stores nodes
	Q.push(root); 

	do 
	{ 

		node* temp = Q.front(); //brings each node to front of queue b/c FIFO
		Q.pop();                //empties last node from queue


		if (temp->letter == letter)     //this happens if current node equals a pre-exisitng node in the tree 
		{ 
			temp->count++;              //note, no new node is inserted 
			break; 
		} 

		if (temp->left == NULL)    //this happens if left node is empty
		{ 
			temp->left = insert(letter); 
			break; 
		} 
		else 
		{ 

			if (temp->left->letter == letter)
			{ 
				temp->left->count++; 
				break; 
			} 

			Q.push(temp->left); 
		} 

		if (temp->right == NULL) 
		{ 
			temp->right = insert(letter); 
			break; 
		} 
		else 
		{ 

			if (temp->right->letter == letter) 
			{ 
				temp->right->count++; 
				break; 
			} 

			Q.push(temp->right); 
		} 
	} while (!Q.empty());

	return root; 
} 


void displayNode(node* root) 
{ 

 
	queue<node*> Q; 
	Q.push(root); 

	do
	{ 
	    node* temp = Q.front(); //brings each node to front of queue b/c FIFO
	

		if (temp->count > 0) 
		{ 
			cout << temp->letter<<":" << temp->count<<endl; 
		} 
 
		Q.pop(); 

		if (temp->left != NULL) 
		{ 
			Q.push(temp->left); 
		} 

		if (temp->right != NULL) 
		{ 
			Q.push(temp->right); 
		} 
	} while(!Q.empty());
} 


int main() 
{ 
    fstream inputFile;
    char input;
    node * myroot=NULL;
    inputFile.open("letters.txt", ios::in);
    while(inputFile)
    {
        inputFile.get(input);
        if(isalpha(input))      //Will skips anything besides letters
        {
            myroot=insertNode(myroot,input);
            
        }
    }
    displayNode(myroot);



	return 0; 
} 
