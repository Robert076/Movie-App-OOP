template <typename T>

class DynamicArray
{
private:
	int size, capacity;
	T* elements;
	void resize(int factor = 2);
public:
	DynamicArray(int capacity = 10); // constructor
	DynamicArray(const DynamicArray &other); // copy constructor
	~DynamicArray(); // destructor
	T& operator[](int index); // getter
	DynamicArray& operator=(const DynamicArray &other); // assignment operator
	void addElement(T element); // add element to the end of the array
	void removeElement(int index); // remove element at index
	void updateElement(int index, T element); // update element at index
	int getSize(); // get the number of elements in the array
	int getCapacity(); // get the capacity of the array
	int returnPosition(const T& element); // return the position of the element in the array)

	class Iterator
	{
	private:
		T* pointerToElement;
	public:
		Iterator(T* pointerToElement = nullptr) : pointerToElement(pointerToElement) {}
		Iterator& operator++()
		{
			pointerToElement++;
			return *this;
		}
		Iterator operator++(int)
		{
			Iterator copy = *this;
			pointerToElement++;
			return copy;
		}
		bool operator==(const Iterator& other) const
		{
			return pointerToElement == other.pointerToElement;
		}
		bool operator!=(const Iterator& other) const
		{
			return pointerToElement != other.pointerToElement;
		}
	};
	Iterator begin() const
	{
		return Iterator(this->elements);
	}
	Iterator end() const
	{
		return Iterator(this->elements + this->size);
	}
};

template <typename T>

DynamicArray<T>::DynamicArray(int capacity)
{
	/*
	* Constructor for the Dynamic Array class
	* Input: capacity - integer
	* Output: the Dynamic Array object is created
	*/
	this->capacity = capacity;
	this->size = 0;
	this->elements = new T[capacity];
}

template <typename T>

DynamicArray<T>::DynamicArray(const DynamicArray& other)
{
	/*
	* Copy constructor for the Dynamic Array class
	* Input: other - Dynamic Array object
	* Output: the Dynamic Array object is created
	*/
	this->size = other.size;
	this->capacity = other.capacity;
	this->elements = new T[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elements[i] = other.elements[i];
}

template <typename T>

DynamicArray<T>::~DynamicArray()
{
	/*
	* Destructor for the Dynamic Array class
	* Input: -
	* Output: the Dynamic Array object is destroyed
	*/
	delete[] this->elements;
}

template <typename T>

DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray& other)
{
	/*
	* Assignment operator for the Dynamic Array class
	* Input: other - Dynamic Array object
	* Output: the current object is assigned the values of the other object
	* Return: the current object
	*/
	if (this != &other)
	{
		this->size = other.size;
		this->capacity = other.capacity;
		delete[] this->elements;
		this->elements = new T[this->capacity];
		for (int i = 0; i < this->size; i++)
			this->elements[i] = other.elements[i];
	}
	return *this;
}

template <typename T>

void DynamicArray<T>::addElement(T element)
{
	/*
	* Add an element to the end of the array
	* Input: element - T
	* Output: the element is added to the end of the array
	*/
	if (this->size == this->capacity)
		this->resize();
	this->elements[this->size++] = element;
}

template <typename T>

void DynamicArray<T>::removeElement(int index)
{
	/*
	* Remove an element from the array
	* Input: index - integer
	* Output: the element at the given index is removed
	* Note: the elements after the removed element are shifted one position to the left
	*/
	for (int i = index; i < this->size - 1; i++)
		this->elements[i] = this->elements[i + 1];
	this->size--;
}

template <typename T>

void DynamicArray<T>::updateElement(int index, T newElement)
{
	/*
	* Update an element in the array
	* Input: index - integer, newElement - T
	* Output: the element at the given index is updated
	*/
	this->elements[index] = newElement;
}

template <typename T>

T& DynamicArray<T>::operator[](int index)
{
	/*
	* Getter for the element at a given index
	* Input: index - integer
	* Output: the element at the given index
	* Return: the element at the given index
	*/
	return this->elements[index];
}

template <typename T>

int DynamicArray<T>::getSize()
{
	/*
	* Get the number of elements in the array
	* Input: -
	* Output: the number of elements in the array
	* Return: the number of elements in the array
	*/
	return this->size;
}

template <typename T>

int DynamicArray<T>::getCapacity()
{
	/*
	* Get the capacity of the array
	* Input: -
	* Output: the capacity of the array
	* Return: the capacity of the array
	*/
	return this->capacity;
}

template <typename T>

void DynamicArray<T>::resize(int factor)
{
	/*
	* Resize the array
	* Input: factor - integer (default is 2)
	* Output: the array is resized
	*/
	this->capacity *= factor;
	T* newElements = new T[this->capacity];
	for (int i = 0; i < this->size; i++)
		newElements[i] = this->elements[i];
	delete[] this->elements;
	this->elements = newElements;
}

template <typename T>

int DynamicArray<T>::returnPosition(const T& element)
{
	/*
	* Return the position of the element in the array
	* Input: element - T
	* Output: the position of the element in the array
	* Return: the position of the element in the array
	*/
	for (int i = 0; i < this->size; i++)
		if (this->elements[i] == element)
			return i;
	return -1;
}