
#include<iostream>

using namespace std;

class S
{
	private:struct NODE
{
	string letter;
	NODE *left;
	NODE *right;
};
	NODE *root;

public:S()
{
	root = NULL;
}
void InsertLetter(string x, NODE *&p)
{
	if (p == NULL)
{
	p = new(NODE); p->letter = x;
	p->left = p->right = NULL;
}

else
{
if (x < p->letter)InsertLetter(x, p->left);
if (x > p->letter)InsertLetter(x, p->right);
}
}

void display(NODE *p)
{
if (p != NULL)
{
	display(p->left); 
	cout<<p->letter<<"";
	display(p->right);
}
}
void InsertLetter(string x){ InsertLetter(x, root); }
void display() { display(root); }
};

int main()
{
	S t;
	string sentence;
	string a;
	cout<<"Enter the sentence: "<<endl;
	getline(cin,sentence);
	for(int i =0;i<sentence.length();i++)
	{

		a=sentence[i];
		t.InsertLetter(a);
	}


	cout << "Result: ";
	t.display();


	return 0;
}
