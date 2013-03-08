#include <functional>
#include <algorithm>
#include <vector>
#include <iostream>


namespace Preload {
	

	template< typename T, typename F >
	T map( const T &list, F func )
	{
		T output;
		output.reserve(list.size());
		for ( auto &e : list )
		{ output.push_back( func(e) ); 	}
		return output;
	}

	template < typename R, typename I, typename F >
	void filterHelper( const I &first, const I &last, R &output, F func )
	{
		for ( auto itr = first; itr != last; ++itr )
		{ 
			auto permission = func(*itr);
			if ( permission )
				output.push_back(*itr);
		}
	}

	template<typename T, typename F>
	T filter( const T &list, F f )
	{
		T output;
		filterHelper(list.begin(), list.end(), output, f);

		return output;
	}


	template <typename T, typename E, typename Functor>
	E foldl( const T &first, const T &last, const E &init, Functor f )
	{
		if ( first == last )
			return init;

		auto output = f ( init, *first );
		auto itr = std::next( first );

		while ( itr != last )
		{ 
			output = f (output, *itr);
			++itr;
		}

		return output;
	}
}

#ifdef TEST_DEBUG

int main()
{
	using std::vector;
	using std::cout;

	using Preload::foldl;
	vector<int> test { 15, 6, 7, 33, 21, 4 };

	for ( auto &e: test )
	{ cout << e << " "; }
	
	cout <<	std::endl;

	//auto rr = map(test, []( const int &e ) { return e * e; });

	auto op = []( const int &first, const int &second ) { return first + second; };
	int rr = foldl( test.begin(), test.end(), 0, op );

	cout << rr << std::endl;

	return 0;
}
#endif
