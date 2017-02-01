#pragma once
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class obpool
{
	// Default capacity for object pool.
	const static size_t DEFAULT_POOL_SIZE = 100;

	// Backing array for object pool.
	vector<T> pool;
	vector<bool> poolValidity;
	vector<size_t> nextList;

	// Returns the index of the first empty slot found.
	// Returns -1 if an empty index cannot be found.
	size_t nextEmpty();
public:
	obpool();
	~obpool();

	class handle
	{
		// back-pointer to pool
		obpool * pool;
		size_t index;

	public:
		handle();
		handle(obpool *poolPtr, size_t poolIdx) : pool(poolPtr), index(poolIdx) {}

		// Returns a reference to the object in the object pool.
		T& value();

		// Instructs the object pool to the free the slot occupied by this handle's slot.
		void free();	//??????

						// Returns true if the slot that this handle is referring to is occupied.
						// Otherwise, it should return false.
		bool isValid();

		// Returns the index of the slot pointed to by this handle.
		T getIndex() const;


		// Moves the handle to the next valid element in the pool
		handle& operator++()
		{
			// attempt to find the next valid index
			for (size_t i = index + 1; i < pool->poolValidity.size(); ++i)
			{
				if (pool->poolValidity[i])
				{
					index = i;
					return *this;
				}
			}

			// failed to find next valid index
			// we must be at the end!
			index = pool->pool.size();
			return *this;
		}

		// Returns a reference to the object in the object pool
		T& operator*() { return value(); }

		// Returns a const reference to the object in the object pool
		const T& operator*() const { return value(); }

		// Returns a reference to the object in the object pool
		T& operator->() { return value(); }

		// Returns a const reference to the object in the object pool
		const T& operator->() const { return value(); }

		// Returns true they're pointing to the same slot.
		// Otherwise, returns false.
		bool operator==(const handle& other) const { return index == other.index; }
		bool operator!=(const handle& other) const { return index != other.index; }
	};

	// Adds the given object to the object pool.
	// Returns a handle with the appropriate information to access the object pool.
	handle push(T cpy)	//It didn't want to work when I put the implementation below.
	{
		pool.resize(pool.size() * 1.5);

		int i = nextEmpty();
		assert(i != -1);
		pool[i] = cpy;
		poolValidity[i] = true;

		return handle(this, i);
	}

	void pop(size_t idx);

	// Returns true if the handle
	bool isValid(size_t idx) const;

	// Returns a reference to the object stored in the pool at the given index.
	T& at(size_t idx);
	// Returns a const reference to the object stored in the pool at the given index.
	const T& at(size_t idx) const;

	// Returns a handle referring to the first valid slot.
	handle begin()
	{
		for (int i = 0; i < poolValidity.size(); i++)
		{
			if (poolValidity[i])
				return handle(this, i);
		}
		assert(false && "Can not iterate over a pool with no elements!");
	}

	// Returns a handle referring to the slot at the given index
	handle get(size_t idx)
	{
		assert(idx < pool.size());
		return handle(this, idx);
	}


	// Returns a handle referring to the last valid slot.
	handle end()
	{
		return handle(this, pool.size());
	}

};

template<typename T>
inline size_t obpool<T>::nextEmpty()
{
	for (int i = 0; i < DEFAULT_POOL_SIZE; i++)
	{
		if (!poolValidity[i])
			return i;
	}

	size_t curSize = pool.size();
	pool.resize(pool.size() * 1.5);
	poolValidity.resize(poolValidity.size() * 1.5);

	memset(&poolValidity[curSize], 0, sizeof(bool) * curSize / 2);

	return curSize;
}

template<typename T>
inline obpool<T>::obpool()
{
	//Set all values to 0
	pool.resize(DEFAULT_POOL_SIZE);
	poolValidity.resize(DEFAULT_POOL_SIZE);
}

template<typename T>
inline obpool<T>::~obpool()
{
	//delete[] pool;
	//delete[] poolValidity;
}

template<typename T>
inline void obpool<T>::pop(size_t idx)
{
	assert(idx != -1);
	poolValidity[idx] = false;
}

template<typename T>
inline bool obpool<T>::isValid(size_t idx) const
{
	assert(idx != -1);
	return poolValidity[idx];
}

template<typename T>
inline T & obpool<T>::at(size_t idx)
{
	assert(idx != -1);
	return &pool[idx];
}

template<typename T>
inline const T & obpool<T>::at(size_t idx) const
{
	assert(idx != -1);
	return &pool[idx];
}

template<typename T>
inline obpool<T>::handle::handle()
{
	pool = nullptr;
	index = -1;
}

template<typename T>
inline T & obpool<T>::handle::value()
{
	//It didn't like me using at
	assert(index != -1);
	return pool->pool[index];
}

template<typename T>
inline void obpool<T>::handle::free()
{
	pool->poolValidity[index] = false;
}

template<typename T>
inline bool obpool<T>::handle::isValid()
{
	return pool->isValid(index);
}

template<typename T>
inline T obpool<T>::handle::getIndex() const
{
	return index;
}
