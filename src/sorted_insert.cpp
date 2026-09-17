/*!
 * Testbed for the insert-in-sorted algorithm.
 *
 * How to compile:  g++ -Wall -std=c++17  sorted_insert.cpp -o si
 */

#include <algorithm>  // suffle, swap
#include <array>      // std::array
#include <iostream>   // cout, endl
#include <iterator>   // distance

// Useful alias representing a function pointer.
using Compare = bool (*)(const int&, const int&);

/**
 *  Inserts a new element in the range, keeping the range sorted,
 *  and return the new last element in the range.
 *
 *  \note We assume there is enough space in range to insert an extra element.
 *
 *  \param first Iterator to the first element in range.
 *  \param last Iterator to past the last element in range.
 *  \param val The element we wish to insert.
 *  \param cmp The function pointer that compares two elements.
 *  \return An iterator to the new `last` of the range [`first`;`last`).
 *
 *  The function inserts a new element `val` in the range [`first`;`last`)
 *  in such a way to preserve the current sorting order.
 *  The new range becomes [`first`;`last`+1).
 *  We assume there is a strict total order relation among the elements
 *  in the range. The strict total order is tested with `cmp(a,b)`, which
 *  return `true` if `a < b`, and false otherwise.
 *
 *  If the elements are not sorted the result is undefined.
 */
int* insert_in_sorted(const int* first, int* last, int val, Compare cmp) {
	auto it = last;
	while (it > first && cmp (val, *(it-1))) {
			*it = *(it-1);
			it--;
	}	
	*it = val;
  return ++last;
}


/// Prints the elemets of the specified range on the standard output stream.
/*!
 * Prints the elements of the range `[first,last)` in the standard output.
 * @param first Pointer to the beginning of the range to print.
 * @param last Pointer past the last element of the range to print.
 */
void print_array(const int* first, const int* last) {
  std::cout << "    Array: [ ";
  std::copy(first, last, std::ostream_iterator<int>(std::cout, " "));
  std::cout << "]\n";
}

void insertionSort (int* first, int* last, Compare cmp) {
	auto nLast = first;
	while (nLast != last) {
		nLast = insert_in_sorted(first, nLast, *nLast, cmp);
		print_array(first, nLast);
	}
}
/// The comparison function. This is part of the client code.
/*!
 * Comparison function that implements a total strict order among inegers.
 * @param a the first element in the comparison.
 * @param b the second element in the comparison.
 * @return `true` if `a` preceeds `b`, `false` otherwise.
 */
bool compare_ints(const int& a, const int& b) { return (a < b); }

/// The client code starts here.
int main() {
  // ================================================================================
  // I. PREPARATION
  // --------------------------------------------------------------------------------
  // The data array with fixed value
  std::array source{ 8, 2, 1, 10, 3, 5, 7, 6, 4, 9 };
  /*
  // This is the destination (sorted) array that will receive the input data.
  std::array<int, source.size()> destination;
  // Fill up the destination array with zeros.
  std::fill(destination.begin(), destination.end(), 0);
  // Show the data source
  std::cout << ">>> Data source\n";
  */
  print_array(source.begin(), source.end());

  // ================================================================================
  // II. INSERTING VALUES AND KEEPING THE ARRAY SORTED
  // --------------------------------------------------------------------------------

  insertionSort(source.begin(), source.end(), compare_ints);

  print_array(source.begin(), source.end());

  std::cout << "\n>>> Normal ending...\n\n";

  return EXIT_SUCCESS;
}
