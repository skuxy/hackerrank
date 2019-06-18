#include <iostream>
using namespace std;
#include <vector>

// Enter your code for reversed_binary_value<bool...>()
template <bool...digits> int reversed_binary_value()
{
    short factor = 1;
    int result = 0;
    vector<bool> digs = { digits...};
    auto it = digs.begin();
    for(int i = 0; i < digs.size() ; i++)
    {
        result += factor * (*it);
        it ++;
        factor *= 2;
    }

    return result;
};


template <int n, bool...digits>
struct CheckValues {
  	static void check(int x, int y)
  	{
    	CheckValues<n-1, 0, digits...>::check(x, y);
    	CheckValues<n-1, 1, digits...>::check(x, y);
  	}
};

template <bool...digits>
struct CheckValues<0, digits...> {
  	static void check(int x, int y)
  	{
    	int z = reversed_binary_value<digits...>();
    	std::cout << (z+64*y==x);
  	}
};

int main()
{
  	int t; std::cin >> t;

    cout << reversed_binary_value<0,0,1>() << endl;;

  	for (int i=0; i!=t; ++i) {
		int x, y;
    	cin >> x >> y;
    	CheckValues<6>::check(x, y);
    	cout << "\n";
  	}
}

