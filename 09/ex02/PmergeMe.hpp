#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <cstddef>

class	PmergeMe {
	private:
		std::deque<int>		deq;
		std::vector<int>	vec;
		std::vector<int>	tmp;
	
	public:
		PmergeMe();
		PmergeMe(PmergeMe &pmm);
		PmergeMe	&operator=(PmergeMe const &pmm);
		~PmergeMe();
		size_t	getSize();
		bool	parse(char **argv);
		void	sortVec(int level);
		void	sortDeq(int level);
		void	getDeq();
		void	getVec();
		void	print();
		void	swapPairsVec(int pair1, int pair2, size_t pairSize);
		void	swapPairsDeq(int pair1, int pair2, size_t pairSize);
		int		jacob(int n);
};

#endif
