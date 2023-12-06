#ifndef EX02_PMERGEME_HPP_
#define EX02_PMERGEME_HPP_

#include <vector>
#include <deque>
#include <algorithm>

class PmergeMe {
public:
	template <class T>
	static void process(T &c)
	{
		if (!c.empty()) {
			fordJohnsonMergeInsertionSort(c, 0, c.size() - 1);
		}
	}
	
private:
	PmergeMe();
	~PmergeMe();
	PmergeMe(const PmergeMe &rhs);
	PmergeMe &operator=(const PmergeMe &rhs);

	template <class T>
	struct Compare {
		const T& c;
		Compare(const T& set) : c(set) {}
		bool operator()(int a, int b) { return c[a] < c[b]; }
	};

	template <class T>
	static void fordJohnsonMergeInsertionSort(T &c, int start, int end)
	{
		if (start >= end) return; // Base case for single element or invalid range
	
		// Base case for two elements
		if (end - start == 1) {
			if (c[start] > c[end]) {
				std::swap(c[start], c[end]);
			}
			return;
		}
	
		// Sort pairs and find medians
		std::vector<int> medians;
		for (int i = start; i < end; i += 2) {
			if (c[i] > c[i + 1]) {
				std::swap(c[i], c[i + 1]);
			}
			medians.push_back(i + 1);
		}
	
		// Handle odd number of elements
		if ((end - start + 1) % 2 != 0) {
			medians.push_back(end);
		}
	
		// Find median of medians
		int medianOfMedians = selectMedian(c, medians);
	
		// Partition around median of medians
		int mid = partition(c, start, end, medianOfMedians);
	
		// Recursively sort elements before and after the partition index
		fordJohnsonMergeInsertionSort(c, start, mid - 1);
		fordJohnsonMergeInsertionSort(c, mid, end);
	}
	
	template <class T>
	static int partition(T &c, int start, int end, int pivotIndex) {
		std::swap(c[pivotIndex], c[end]); // Move pivot to end
		int storeIndex = start;
		for (int i = start; i < end; i++) {
			if (c[i] < c[end]) {
				std::swap(c[i], c[storeIndex]);
				storeIndex++;
			}
		}
		std::swap(c[storeIndex], c[end]); // Move pivot to its final place
		return storeIndex;
	}


	template <class T>
	static int selectMedian(T &c, const std::vector<int> &medians) {
		std::vector<int> temp = medians;
		std::sort(temp.begin(), temp.end(), Compare<T>(c));
		return temp[temp.size() / 2];
	}
};

#endif // EX02_PMERGEME_HPP_
