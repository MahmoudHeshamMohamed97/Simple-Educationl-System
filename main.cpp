#include <iostream>
#include <string>
using namespace std;

class course{
public:
	string name;
	float price;
	int id;
	string depend;
	course* left;
	course* right;

	course(){
		name = "";
		price = 0.0;
		id = 0;
		depend = "0";
		left = right = NULL;
	}
	course(string name, float price, int id, string depend){
		this->name = name;
		this->price = price;
		this->id = id;
		this->depend = depend;
		right = left = NULL;
	}
};

class BSTCourse{

	int sizee;
public:
	course *root;
	BSTCourse(){
		root = NULL;
		sizee = 0;
	}
	//adding by id to be easier to search and add
	void Add_Course(string name, float price, int id, string depend){
		sizee++;
		course * ptr = new course(name, price, id, depend);
		if (root == NULL)
			root = ptr;
		else{
			course *temp = root, *parent = root;
			while (temp != NULL){
				if (name > temp->name){
					parent = temp;
					              temp = temp->right;
				}
				else if (name < temp->name){
					parent = temp;
					temp = temp->left;
				}
				else{
					cout << "it's not allowed to add an identify  course" << endl;
					sizee--;
					return;
				}
			}
			if (name > parent->name)
				parent->right = ptr;
			else
				parent->left = ptr;
		}
	}
	// search by id
	course * Search(string name){
		course * ptr = root;
		while (ptr != NULL){
			if (name > ptr->name)
				ptr = ptr->right;
			else if (name < ptr->name)
				ptr = ptr->left;
			else{
				return ptr;
			}
		}
		return NULL;
	}
	void Delete(string name){
		course * ptr = root;
		course * parent = root;
		while (ptr != NULL){
			if (name > ptr->name){
				parent = ptr;
				ptr = ptr->right;
			}
			else if (name < ptr->name){
				parent = ptr;
				ptr = ptr->left;
			}
			else if (name == ptr->name){
				if (ptr->right == NULL && ptr->left == NULL)
					delete ptr;
				else if (ptr->left == NULL && ptr->right != NULL)
				{
					if (ptr->name > parent->name)
						parent->right = ptr->right;
					else if (ptr->name < parent->name)
						parent->left = ptr->right;
					delete ptr;
				}
				else if (ptr->right == NULL && ptr->left != NULL)
				{
					if (ptr->name > parent->name)
						parent->right = ptr->left;
					else if (ptr->name < parent->name)
						parent->left = ptr->left;
					delete ptr;
				}
				else if (ptr->right != NULL && ptr->left != NULL)
				{
					if (ptr->name > parent->name)
						parent = parent->right;
					else
						parent = parent->left;
					course *temp;
					ptr = ptr->left;
					while (ptr->right != NULL){
						temp = ptr;
						ptr = ptr->right;
					}
					if (ptr->left == NULL){
						parent->name = ptr->name;
						parent->id = ptr->id;
						parent->price = ptr->price;
						parent->depend = ptr->depend;
					}
					else
					{
						temp->right = ptr->left;
						parent->name = ptr->name;
						parent->id = ptr->id;
						parent->price = ptr->price;
						parent->depend = ptr->depend;
					}
					delete ptr;
				}
			}
			//
			else
				cout << "Please Check your information..." << endl;
		}
	}
	void Display(course * rot){
		if (rot == NULL)
			return;
		else
			Display(rot->left);
		cout << rot->name << " and it's id " << rot->id << " and it costs " << rot->price << endl;
		Display(rot->right);

	}
};
// std
class student{
public:
	int pass;
	string name;
	string preco;
	student *right;
	student *left;
	student(){
		name = "0";
		pass = 0;
		preco = "0";
		right = left = 0;
	}
	student(string name, int pass){
		this->name = name;
		this->pass = pass;
		preco = "0";
		right = left = NULL;
	}

};
class BSTStudent{
	int sizee;
public:
	student *root;
	void Add(string name, int pass){
		sizee++;
		student *ptr = new student(name, pass);
		if (root == NULL)
			root = ptr;
		else{
			student *temp = root, *parent = root;
			while (temp != NULL){
				if (name > temp->name){
					parent = temp;
					temp = temp->right;
				}
				else if (name < temp->name){
					parent = temp;
					temp = temp->left;
				}
				else{
					cout << "it's not allowed to add an identify student name" << endl;
					sizee--;
					return;
				}
			}
			if (name > parent->name)
				parent->right = ptr;
			else
				parent->left = ptr;
		}
	}
	student* Search(string name){
		student * ptr = root;
		while (ptr != NULL){
			if (name > ptr->name)
				ptr = ptr->right;
			else if (name < ptr->name)
				ptr = ptr->left;
			else{
				return ptr;
			}
		}
		return NULL;
	}
	void Display(student * rot){
		if (rot == NULL)
			return;
		else
			Display(rot->left);
		cout << rot->name << " and it's previous course " << rot->preco << endl;
		Display(rot->right);
	}

	void Delete(string name){
		student * ptr = root;
		student * parent = root;
		while (ptr != NULL){
			if (name > ptr->name){
				parent = ptr;
				ptr = ptr->right;
			}
			else if (name < ptr->name){
				parent = ptr;
				ptr = ptr->left;
			}
			else if (name == ptr->name){
				if (ptr->right == NULL && ptr->left == NULL)
					delete ptr;
				else if (ptr->left == NULL && ptr->right != NULL)
				{
					if (ptr->name > parent->name)
						parent->right = ptr->right;
					else if (ptr->name < parent->name)
						parent->left = ptr->right;
					delete ptr;
				}
				else if (ptr->right == NULL && ptr->left != NULL)
				{
					if (ptr->name > parent->name)
						parent->right = ptr->left;
					else if (ptr->name < parent->name)
						parent->left = ptr->left;
					delete ptr;
				}
				else if (ptr->right != NULL && ptr->left != NULL)
				{
					if (ptr->name > parent->name)
						parent = parent->right;
					else
						parent = parent->left;
					student *temp;
					ptr = ptr->left;
					while (ptr->right != NULL){
						temp = ptr;
						ptr = ptr->right;
					}
					if (ptr->left == NULL){
						parent->name = ptr->name;
						parent->pass = ptr->pass;
						parent->preco = ptr->preco;
					}
					else
					{
						temp->right = ptr->left;
						parent->name = ptr->name;
						parent->pass = ptr->pass;
						parent->preco = ptr->preco;
					}
					delete ptr;
				}
			}
			//
			else
				cout << "Please Check your information..." << endl;
		}
	}

};

int main()
{
	BSTCourse s;
	s.Add_Course("C++", 150, 5, "0");
	s.Add_Course("SP", 200, 7, "C++");
	s.Add_Course("DS", 250, 3, "SP");
	BSTStudent c;
	//c.Add("mahmoud", 123);
	//c.Add("ahmed", 123);

	cout << "Enter Who you are :" << endl << "1- Admin" << endl << "2- Student" << endl;
	int input, password = 1234567, pasin;
	cin >> input;
	if (input == 1){
		cout << "Enter The Password" << endl;
		cin >> pasin;
		if (pasin != password){
			cout << "Incorrect password please Check That again...." << endl;
			cin >> pasin;
		}
		else{
			cout << "Hello Admin" << endl;
			cout << "if you want to add a new course press 1" << endl << "but if you want to search about course press 2" << endl;
			cout << "if you want to delete course press 3" << endl << "to display courses press 4" << endl;
			cout << "to search for a student press 5" << endl << "to display students press 6" << endl;
			int x;
			cin >> x;
			while (x != 0){
				if (x == 1){
					cout << "Enter the name of the course" << endl;
					string name;
					cin >> name;
					cout << "enter it's price" << endl;
					float price;
					cin >> price;
					cout << "enter it's id" << endl;
					int id;
					cin >> id;
					cout << "Enter The course which this course depends on..." << endl;
					string depend;
					cin >> depend;
					if (s.Search(depend) == NULL){
						while (s.Search(depend) == NULL){
							cout << "Please check course name..." << endl << "Enter course name.." << endl;
							cin >> depend;
						}
					}
					s.Add_Course(name, price, id, depend);
				}
				else if (x == 2){
					cout << "Enter Course name" << endl;
					string name;
					cin >> name;
					if (s.Search(name) == NULL){
						while (s.Search(name) == NULL){
							cout << "Check Course name ..." << endl << "Enter Course name.." << endl;
							cin >> name;
						}
						cout << s.Search(name)->name << " And it's id " << s.Search(name)->id << " And it's price " << s.Search(name)->price << endl;
						cout << "And to have it you should have " << s.Search(name)->depend << " Course." << endl;
					}
					else{
						cout << s.Search(name)->name << " And it's id " << s.Search(name)->id << " And it's price " << s.Search(name)->price << endl;
						cout << "And to have it you should have " << s.Search(name)->depend << " Course." << endl;
					}
				}
				else if (x == 3){
					cout << "Enter Course name" << endl;
					string name;
					cin >> name;
					while (s.Search(name) == NULL){
						cout << "Check Course name ..." << endl << "Enter Course name.." << endl;
						cin >> name;
					}
					s.Delete(name);
				}
				else if (x == 4){
					s.Display(s.root);
				}
				else if (x == 5){
					cout << "Enter Student Name..." << endl;
					string ser;
					cin >> ser;
					if (c.Search(ser) == NULL){
						while (c.Search(ser) == NULL){
							cout << "Check Student name ..." << endl << "Enter Student name.." << endl;
							cin >> ser;
						}
						cout << c.Search(ser)->name << " And his last course was " << c.Search(ser)->preco << endl;
					}
					else
						cout << c.Search(ser)->name << " And his last course was " << c.Search(ser)->preco << endl;
				}
				else if (x == 6){
					c.Display(c.root);
				}
				else
					cout << "please check your choice" << endl;
				cout << "if you want to do a new one enter the number of the process" << endl;
				cout << "if you don't need enter zero" << endl;
				cin >> x;
			}
		}
	}
	// std
	else if (input == 2){

		cout << "Hello Student " << endl;
		cout << "1-if you are an old student." << endl << "2- if you want to register." << endl;
		int x;
		cin >> x;
		while (x != 0){
			if (x == 1){
				cout << "please enter your name.." << endl;
				string name;
				cin >> name;

				if (c.Search(name)->name == name){
					cout << "enter your password.." << endl;
					int stdpassword;
					cin >> stdpassword;
					if (stdpassword == c.Search(name)->pass){
						cout << "Hello " << name << endl;
						int stdc;
						cout << "1- to see the courses existing" << endl << "2- to add course to your semester" << endl;
						cin >> stdc;
						while (stdc != 0){
							if (stdc == 1){
								s.Display(s.root);
							}
							else if (stdc == 2)
							{
								s.Display(s.root);
								cout << "Enter the previous Course you take in your last semester.." << endl;
								cout << "If you don't have a previous course press 0." << endl;
								//course one
								string cona;
								cin >> cona;
								c.Search(name)->preco = cona;
								string wanted;
								cout << "Enter The course name you want..." << endl;
								cin >> wanted;
								//    s.Search_by_id(num);
								if (s.Search(wanted)->name == wanted){
									//check if function
									if (s.Search(wanted)->depend == cona){
										cout << "Now you added this course to your semester..." << endl;
										c.Search(name)->preco = wanted;
									}
									else
										cout << "This course not allowed for you until you complete your semester courses.." << endl;
									cout << "To Take This Course You Should Take " << s.Search(wanted)->depend << " Course." << endl;
								}
								else{
									cout << "Please Check your course name..." << endl;
									cout << "Enter course name.." << endl;
									cin >> wanted;
								}
							}
							else
								cout << "please check your choice " << endl;
							cout << "if you want to add courses to your semester or need to see courses " << endl;
							cout << "if you don't want press 0" << endl;
							cin >> stdc;
						}
					}
					else{
						cout << "Check your password..." << endl;
						cin >> stdpassword;
					}
				}
				else
				{
					cout << "check the user name..." << endl;
					cin >> name;
				}
			}
			else if (x == 2){
				cout << "please enter your name..." << endl;
				string name;
				cin >> name;
				cout << "enter your password..." << endl;
				int stdpassword;
				cin >> stdpassword;
				if (c.Search(name) == NULL){
					cout << "Thanks for your register ..." << endl;
					c.Add(name, stdpassword);
				}
				else
				{
					while (c.Search(name)->name == name){
						cout << "This name existing before , please enter another one..." << endl;
						cin >> name;
						cout << "Enter the password..." << endl;
						cin >> stdpassword;
					}
					cout << "Thanks for your register ..." << endl;
					c.Add(name , stdpassword);
				}
			}
			else
				cout << "please check your choice " << endl;
			cout << "if you want to any process again press the number of process" << endl;
			cout << "if you don't want press 0" << endl;
			cin >> x;
		}
	}
	else
		cout << "Wrong Choice please Check your input ..." << endl;

	return 0;

}


