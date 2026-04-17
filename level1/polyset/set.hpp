#ifndef EXAM_ASSIGNMENTS_SET_HPP
#define EXAM_ASSIGNMENTS_SET_HPP

#include "searchable_bag.hpp"

class set : public searchable_bag {
private:
	searchable_bag *_bag;

	static searchable_bag *clone_bag(const searchable_bag &);

public:
	set();
	set(const searchable_bag &);
	set(const set &);
	set &operator=(const set &);
	~set();

	void insert(int);
	void insert(int *, int);
	bool has(int) const;
	void print() const;
	void clear();

	searchable_bag &get_bag();
	const searchable_bag &get_bag() const;
};

#endif