#ifndef DATABASE_H
#define DATABASE_H

int search(int* data, int size, int val);
void sort(int* data, int size);
int array_insert(int* data, int size, int val);

class Database{
  protected:
  	int size; 
  public: 
    virtual void insert(int val) = 0;
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
	void check_status();
};

#endif