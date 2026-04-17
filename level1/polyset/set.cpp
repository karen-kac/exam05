#include "set.hpp"
#include "searchable_array_bag.hpp"
#include "searchable_tree_bag.hpp"

set::set() : _bag(new searchable_array_bag()) {}

set::set(const searchable_bag &other) : _bag(clone_bag(other)) {}

set::set(const set &other) : _bag(clone_bag(*other._bag)) {}

set &set::operator=(const set &other) {
	if (this != &other) {
		searchable_bag *tmp = clone_bag(*other._bag);
		delete this->_bag;
		this->_bag = tmp;
	}
	return *this;
}

set::~set() {
	delete this->_bag;
}

searchable_bag *set::clone_bag(const searchable_bag &bag_ref) {
	const searchable_tree_bag *tree = dynamic_cast<const searchable_tree_bag *>(&bag_ref);
	if (tree)
		return new searchable_tree_bag(*tree);
	const searchable_array_bag *array = dynamic_cast<const searchable_array_bag *>(&bag_ref);
	if (array)
		return new searchable_array_bag(*array);
	return new searchable_array_bag();
}

void set::insert(int value) {
	if (!this->has(value))
		this->_bag->insert(value);
}

void set::insert(int *array, int size) {
	for (int i = 0; i < size; i++)
		this->insert(array[i]);
}

bool set::has(int value) const {
	return this->_bag->has(value);
}

void set::print() const {
	this->_bag->print();
}

void set::clear() {
	this->_bag->clear();
}

searchable_bag &set::get_bag() {
	return *this->_bag;
}

const searchable_bag &set::get_bag() const {
	return *this->_bag;
}
