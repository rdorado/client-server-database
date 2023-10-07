#ifndef DATABASE_H
#define DATABASE_H

int search(int* data, int size, int val);
void sort(int* data, int size);
int array_insert(int* data, int size, int val);

class TreeNode{
    int data;
	TreeNode* left;
	TreeNode* right;
  public:
    TreeNode(int val) {
	  data = val;
	  left = nullptr;
	  right = nullptr;
	}
    bool insert(int val);
	bool search(int val);
};


class Tree{
	TreeNode* root;
  public:
    Tree(){
	  root = nullptr;
	}
    bool insert(int val);
	bool search(int val);
};


class Database{
  protected:
  	int size; 
  public: 
    virtual void insert(int val) = 0;
	virtual bool query(int val) = 0;
	virtual void check_status() = 0;
	Database() {};
};

class ArrayDatabase : public Database{
    int* data;
	int size;
  public:
    ArrayDatabase(){
	  data = new int[20000];
	  size = 0;
	};
    void insert(int val);
	bool query(int val);
	void check_status();
};

class TreeDatabase : public Database{
	int size;
	Tree tree;
  public:
    TreeDatabase(){
	  size = 0;
	};
    void insert(int val);
	bool query(int val);
	void check_status();
};

#endif