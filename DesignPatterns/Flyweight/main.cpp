#include <iostream>

#include "StringPool.h"

int main()
{
	StringPool pool;

	pool.getString("Slavi");
	pool.getString("Slavi");
	pool.getString("Marto");
	pool.removeString("Slavi");
	pool.getString("Marto");

	pool.print();

	return 0;
}