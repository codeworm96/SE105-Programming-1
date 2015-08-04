#ifndef NAME_PAIRS_H
#define NAME_PAIRS_H

#include <vector>
#include <string>

class Name_pairs
{
public:
	void read_names();
	void read_ages();
	//void print() const;
	void sort(){qsort(0, name.size());};
	//getters
	const std::vector<std::string>& get_name() const {return name;};
	const std::vector<double>& get_ages() const {return age;};
private:
	//for sort
	void qsort(int, int);
	void swap(int, int);
	//data member
	std::vector<std::string> name;
	std::vector<double> age;
};

std::ostream& operator<<(std::ostream& os, const Name_pairs& np);
bool operator!=(const Name_pairs& a, const Name_pairs& b);
bool operator==(const Name_pairs& a, const Name_pairs& b);

#endif //NAME_PAIRS_H