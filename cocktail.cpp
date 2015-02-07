#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
 
const int EL_COUNT = 10000, LLEN = 11;
 
class CocktailSort
{
public:
    void sort( int* arr, int len )
    {
	bool notSorted = true;
	while( notSorted )
	{
	    notSorted = false;
	    for( int a = 0; a < len - 1; a++ )
	    {
		if( arr[a] > arr[a + 1] )
		{
		    sSwap( arr[a], arr[a + 1] );
		    notSorted = true;
		}
	    }
 
	    if( !notSorted ) break;
	    notSorted = false;
 
	    for( int a = len - 1; a > 0; a-- )
	    {
		if( arr[a - 1] > arr[a] )
		{
		    sSwap( arr[a], arr[a - 1] );
		    notSorted = true;
		}
	    }
	}
    }
 
private:
    void sSwap( int& a, int& b )
    {
	   int t = a;
   	   a = b; b = t;
    }
};
 
int main( int argc, char* argv[] )
{
    srand( clock() );
    CocktailSort cs;
    int arr[EL_COUNT];
 
    for( int x = 0; x < EL_COUNT; x++ )
        arr[x] = rand() % EL_COUNT + 1;
 
    cout << "Original: " << endl << "==========" << endl;
    for( int x = 0; x < EL_COUNT; x += LLEN )
    {
	   for( int s = x; s < x + LLEN; s++ ) {
	       cout << arr[s] << ", ";
       }
 
	   cout << endl;
    }
 
    clock_t t = clock(); 
    cs.sort( arr, EL_COUNT );
    t = clock() - t;
 
    cout << endl << endl << "Sorted: " << endl << "========" << endl;
    for( int x = 0; x < EL_COUNT; x += LLEN )
    {
	for( int s = x; s < x + LLEN; s++ )
	    cout << arr[s] << ", ";
 
	    cout << endl;
    }
 
    cout << endl << endl << endl << endl;
    cout << ((float)t)/CLOCKS_PER_SEC << endl << endl; 
    return 0;
}
