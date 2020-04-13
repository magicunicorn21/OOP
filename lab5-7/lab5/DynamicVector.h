#pragma once
#include <string>

template <typename T>

class DynamicVector
{
private:
	T* elements_;
	int size_;
	int capacity_;

public:
	DynamicVector(int capacity = 10);
	DynamicVector(const DynamicVector& vectorToCopy);
	~DynamicVector();
	DynamicVector& operator=(const DynamicVector& vectorToAssign);
	void add(const T& newElement);
	void remove(const int position);
	void update(const int position, const T& updatedElement);
	T& operator[](int position);
	int getSize() const;

private:
	void resize(double factor = 2);
};

template <typename T>
DynamicVector<T>::DynamicVector(int capacity)
{
	size_ = 0;
	capacity_ = capacity;
	elements_ = new T[capacity];
}

template <typename T>
DynamicVector<T>::DynamicVector(const DynamicVector<T>& vectorToCopy)
{
	size_ = vectorToCopy.size_;
	capacity_ = vectorToCopy.capacity_;
	elements_ = new T[capacity_];
	for (int index = 0; index < size_; index++)
		elements_[index] = vectorToCopy.elements_[index];
}

template <typename T>
DynamicVector<T>::~DynamicVector()
{
	delete[] elements_;
}

template <typename T>
DynamicVector<T>& DynamicVector<T>::operator=(const DynamicVector<T>& vectorToAssign)
{
	if (this == &vectorToAssign)
		return *this;
	size_ = vectorToAssign.size_;
	capacity_ = vectorToAssign.capacity_;
	delete[] elements_;
	elements_ = new T[capacity_];
	for (int index = 0; index < size_; index++)
		elements_[index] = vectorToAssign.elements_[index];
	return *this;
}

template <typename T>
void DynamicVector<T>::add(const T& newElement)
{
	if (size_ == capacity_)
		resize();
	elements_[size_] = newElement;
	size_++;
}

template <typename T>
void DynamicVector<T>::remove(const int position)
{
	if (position < size_ && position >= 0)
	{
		elements_[position] = elements_[size_ - 1];
		size_--;
	}
}

template <typename T>
void DynamicVector<T>::update(const int position, const T& updatedElement)
{
	elements_[position] = updatedElement;
}

template <typename T>
void DynamicVector<T>::resize(double factor)
{
	capacity_ *= factor;
	T* elements = new T[capacity_];
	for (int index = 0; index < size_; index++)
		elements[index] = elements_[index];
	delete[] elements_;
	elements_ = elements;
}

template <typename T>
T& DynamicVector<T>::operator[](int position)
{
	return elements_[position];
}

template <typename T>
int DynamicVector<T>::getSize() const
{
	return size_;
}
