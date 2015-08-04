// turnbyturn.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <typeinfo>
#include <math.h> 
#include <time.h>
#include <stdlib.h>
using namespace std;


int main()
{
	

int range;
int floor;
int dcount;
int lr;
int locationnumber;
int used[100];
int dlist[100];
int num;
int distance;
char entry='c';
srand(time(NULL));
string directions[] = {" ","Turn left onto Commercial St","Turn right onto Lancaster Dr","Turn left onto Commercial St","Turn left onto Commercial St","Turn right onto Turner Rd","Turn left onto North River Road","Turn left onto Salem-Dallas Hwy","Turn right on Lancaster Dr","Turn right onto Lancaster Dr","Turn left onto South East Deer Park Dr","Turn right onto Lancaster Dr","Turn left onto Montgomery St","Merge right onto Santiam Hwy","Turn right onto 9th street","Turn left onto Walnut Blvd","Turn right onto Coffin Butte Rd","Turn left onto south Third St","Turn right onto East Ellendale Ave","Merge left onto Kings Valley Hwy","Turn right onto South Santiam Hwy","Turn right onto South Santiam Hwy","Turn right onto South Santiam Hwy","Turn left onto North First Street","Turn right onto Main St","Destination will be on your left","Destination will be on your right","Turn left on North Maple Ave","Turn right on Market St","Turn Left on Stoneway Dr","Turn Right on Hwy 22","Turn Left on Plaza St","Turn right on Eola Dr","Turn left on Moores Way","Turn Left on Senate St","Turn right on Doaks Ferry Rd","Turn right on Belverde St","Turn right on Gehlar Rd","Turn right on Celveland Ave","Turn Left on Eisenhower Dr","Turn right on Dalke Ridge Dr","Turn left on Crestbrook Dr","Turn left on Brekenridge St","Turn Left on Horse Clover Dr","Turn right on Rainsong Dr","Turn left on Emerald Dr","Turn right on Grice Hilld Rd","Turn left on Orchard Heights Rd","Turn right on Eagle Crest Rd","Turn right on Timothy Dr","Turn right on Lockhart Dr","Turn left on Oakcrest Dr"};
cout << "Please enter location number \n";
cin >> locationnumber;
cout << "Please enter distance \n";
cin >> distance;
//sets up range for how many directions will be used
if (distance<5)
{
	range=4;
	floor=3;
}
else if (distance<15)
{
	range=5;
	floor=4;
}
else if (distance<25)
{
	range=6;
	floor=5;
}
else if (distance<35)
{
	range=8;
	floor=6;
}
else
{
	range=10;
	floor=6;
}
//enters in how many directions will be used
dcount=rand()%range+1+floor;
//50 50 chance of left or right
lr=rand()%2+25;
int x;
int y;
int unique=0;
num=rand()%23+28; //random directions number
for(x=0;x<dcount;x++)
{
	num=rand()%23+28;
	while(unique<x) //this is supposed to stop repeat directions but I think there is a flaw
	{
		num=rand()%23+28;
		for (y=0;y<x;y++)
		{
			if(num!=used[y])
			{
				unique++;
			}
		}
	}
	dlist[x]=num;
	used[x]=num;
	unique=0;
}
dlist[x]=locationnumber; //second to last direction turns on street where location actually is
x++;
dlist[x]=lr; //says left or right
int q=0;
cout << "Now printing directions press any key button except q to print \n";
cout << "next direction to quit guidance press q \n";
while (q<=x&&entry!='q')
{
	cout << directions[dlist[q]]<< " ";
	cin >> entry;
	cout<< endl;
	q++;
}
	/*
	if(entry!='q')
	{
		cout << directions[locationnumber]<< " ";;
		cin >> entry;
	}
	if(entry!='q')
	{
		cout << directions[lr]<< " ";;
		cin >> entry;
	}
	*/
		
		
	return 0;
}

