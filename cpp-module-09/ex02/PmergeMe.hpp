#ifndef PMERGEME_HPP_
#define PMERGEME_HPP_

#include <vector>
#include <deque>

class PmergeMe {
public:
	template <class T>
	static void process(T &c, int threshold = PmergeMe::kDefaultThreshold)
	{
		mergeInsertSort(c, 0, c.size() - 1, threshold);
	}
	
private:
	PmergeMe();
	~PmergeMe();
	PmergeMe(const PmergeMe &rhs);
	PmergeMe &operator=(const PmergeMe &rhs);

	static const int kDefaultThreshold = 10;

	template <class T>
	static void mergeInsertSort(T& c, int start, int end, int threshold)
	{
		if (start < end) {
			if (end - start < threshold) {
				insertSort(c, start, end);
			} else {
				int mid = start + (end - start) / 2;
				mergeInsertSort(c, start, mid, threshold);
				mergeInsertSort(c, mid + 1, end, threshold);
				merge(c, start, mid, end);
			}
		}
	}

	template <class T>
	static void insertSort(T &c, int start, int end)
	{
		for (int i = start + 1; i <= end; ++i) {
			int key = c[i];
			int j = i - 1;
			for (; j >= start && c[j] > key; --j)
				c[j + 1] = c[j];
			c[j + 1] = key;
		}
	}

	template <class T>
	static void merge(T &c, int start, int mid, int end)
	{
		int i, j, k;
		int n1 = mid - start + 1;
		int n2 = end - mid;
	
		T left(n1), right(n2);
	
		for (i = 0; i < n1; ++i)
			left[i] = c[start + i];
		for (j = 0; j < n2; ++j)
			right[j] = c[mid + 1 + j];
	
		i = 0;
		j = 0;
		k = start;
		while (i < n1 && j < n2) {
			if (left[i] <= right[j])
				c[k++] = left[i++];
			else
				c[k++] = right[j++];
		}
		while (i < n1)
			c[k++] = left[i++];
	
		while (j < n2)
			c[k++] = right[j++];
	}
};

#endif // PMERGEME_HPP_
