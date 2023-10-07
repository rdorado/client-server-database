#include "database.h"
#include <iostream>

#define DATAFILE "D:\\data.txt"

bool TreeNode::insert(int val)
{
  if(data < val) 
  {
	if (left)
	{
	  return left->insert(val);
	}
	else
	{
	  left = new TreeNode(val);
	  return true;
	}
  }
  else if (data > val)
  {
	if (right)
	{
	  return right->insert(val);
	}
	else
	{
	  right = new TreeNode(val);
	  return true;
	}
  }
  else return false;
}

bool TreeNode::search(int val)
{
  if(data < val) 
  {
	if (left)
	{
	  return left->insert(val);
	}
	else
	{
	  return false;
	}
  }
  else if (data > val)
  {
	if (right)
	{
	  return right->insert(val);
	}
	else
	{
	  return false;
	}
  }
  else return true;
}


bool Tree::insert(int val)
{
  if(!root)
  {
	root = new TreeNode(val);
	return true;
  }
  else return root->insert(val);
}

bool Tree::search(int val)
{
  if(!root)
  {
	return false;
  }
  else return root->insert(val);
}

int search(int* data, int size, int val)
{
  for(int i=0;i<size;i++)
  {
    if (*data++ == val) return i;
  }
  //std::cout << "search: value " << val << " not found. "<< std::endl;
  return -1;
}


void sort(int* data, int size)
{
  for(int i=0;i<size-1;i++)
  {
    for(int j=i+1;j<size;j++)
    {
	  if(data[i] > data[j])
	  {
	    int tmp = data[i];
		data[i] = data[j];
		data[j] = tmp;
	  }
    }
  }	
}


int array_insert(int* data, int size, int val)
{
  data[size] = val;
  sort(data, size + 1);
  return 0;
}

/*
   ArrayDatabase
*/

void ArrayDatabase::insert(int val){
  int index = search(data, size, val);
  if (index == -1)
  {
	array_insert(data, size, val);
	size++;
  }
};


bool ArrayDatabase::query(int val)
{
  int index = search(data, size, val);
  if (index == -1) return -1;
  return 0;
}


void ArrayDatabase::check_status(){
  bool sorted = true;
  bool print_data = true;
  if(print_data) if (size > 0) std::cout << data[0] << " ";
  for(int i=0;i<size-1;i++){
    if(print_data) std::cout << data[i+1] << " ";
    if (data[i] >= data[i+1])
	{
	  sorted = false;
	}
  }
  if(print_data) std::cout << std::endl;
  if (sorted) std::cout << "The database is sorted. ";
  else std::cout << "The database is not sorted!! ";
  std::cout << "Database size " << size << "." << std::endl;
}


/*
   TreeDatabase
*/

void TreeDatabase::insert(int val){
  bool inserted = tree.insert(val);
  if (inserted) size++;
};

bool TreeDatabase::query(int val)
{
  return tree.search(val);
}

void TreeDatabase::check_status(){
  //bool sorted=true;
  //if (size > 0) std::cout << data[0] << " ";
  /*for(int i=0;i<size-1;i++){
    //std::cout << data[i+1] << " ";
    if (data[i] >= data[i+1])
	{
	  sorted = false;
	}
  }*/
  //std::cout << std::endl;
  //if (sorted) std::cout << "The database is sorted. ";
  //else std::cout << "The database is not sorted!! ";
  std::cout << "Readed database of size " << size << "." << std::endl;
}
