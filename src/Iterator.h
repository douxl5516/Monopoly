#ifndef ITERATOR_H
#define ITERATOR_H

class CppIterator {
public:
	CppIterator() {}
	virtual ~CppIterator() {}
	virtual void first() = 0;
	virtual void next() = 0;
	virtual bool isLast() const = 0;
	virtual void * current() = 0;
	virtual int count() const = 0;
};

class JavaIterator {
public:
	JavaIterator() {}
	virtual ~JavaIterator() {}
	virtual void* next() = 0;
	virtual bool hasNext() const = 0;
	virtual int count() const = 0;
};
#endif // !ITERATOR_H