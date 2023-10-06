#include "database.h"
#include <iostream>

#define DATAFILE "D:\\data.txt"

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
  sort(data, size);
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

void ArrayDatabase::check_status(){
  bool sorted=true;
  //if (size > 0) std::cout << data[0] << " ";
  for(int i=0;i<size-1;i++){
    //std::cout << data[i+1] << " ";
    if (data[i] >= data[i+1])
	{
	  sorted = false;
	}
  }
  //std::cout << std::endl;
  if (sorted) std::cout << "The database is sorted. ";
  else std::cout << "The database is not sorted!! ";
  std::cout << "Readed database of size " << size << "." << std::endl;
}
