#pragma once
#include "iostream"
#define _MAX_SIZE_ARR 256

#pragma region User_Stack_Class_Definition
template<class value_type> struct node
{
	value_type data;
	node* next;
};

template<class value_type> class Container
{
public:
	// Definition of the function for obtaining the number of elements in the stack
	uint32_t size();
	// Defining the function of checking for the presence of records in the file
	bool empty();
	// Constructor without parameters
	explicit Container();
	// Defining a function of the parent class adding an element to the stack
	virtual void push(const value_type);
	// Defining a function of the parent class removing an element from the stack
	virtual void pop();
	// Defining the virtual view function of the last added item
	virtual value_type top();
	// Destructor for the Container class
	virtual ~Container();
	// Assignment Constructor
	virtual Container& operator=(Container&);
	// Move Constructor
	virtual Container& operator=(Container&&);
protected:
	// Structure of a singly linked list
	node<value_type>* tail;
	value_type* arr;
	uint32_t _size_;
};

template<class value_type> class Vector final :
	public Container<value_type>
{
public:
	// Constructor without parameters
	explicit Vector();
	// Defining a function of the child class adding an element to the stack
	void push(const value_type) override;
	// Defining a function of the parent class removing an element from the stack
	void pop() override;
	// Overriding the view function of the last element from the base class
	value_type top() override;
	// Destructor for the Container class
	~Vector();
	// Structure of a singly linked list
	Vector& operator=(Vector&);
	// Move Constructor
	Vector& operator=(Vector&&);
};

template<class value_type> class List final :
	public Container<value_type>
{
public:
	// Constructor without parameters
	explicit List();
	// Defining a function of the child class adding an element to the stack
	void push(const value_type) override;
	// Defining a function of the parent class removing an element from the stack
	void pop() override;
	// Overriding the view function of the last element from the base class
	value_type top() override;
	// Destructor for the Container class
	~List() override;
	// Structure of a singly linked list
	List& operator=(List&);
	// Move Constructor
	List& operator=(List&&);
};

#pragma endregion User_Stack_Class_Definition

#pragma region Container_Block 

template<class value_type> Container<value_type>::Container()
{
	std::cout << "Parent class\n";
}

template<class value_type> void Container<value_type>::push(const value_type dat)
{
	std::cout << "Parent class\n";
}

template<class value_type> void Container<value_type>::pop()
{
	std::cout << "Parent class\n";
}

template<class value_type> value_type Container<value_type>::top()
{
	std::cout << "Parent class\n";
	return 0;
}

template<class value_type> uint32_t Container<value_type>::size()
{
	return _size_;
}

template<class value_type> bool Container<value_type>::empty()
{
	return ((!Container::_size_) ? 1 : 0);
}

template<class value_type> Container<value_type>::~Container()
{
	std::cout << "Parent class\n";
}

template<class value_type> Container<value_type>& Container<value_type>::operator=(Container<value_type>& temp)
{
	std::cout << "Parent class\n";
	return *this;
}

template<class value_type> Container<value_type>& Container<value_type>::operator=(Container<value_type>&& temp)
{
	std::cout << "Parent class\n";
	return *this;
}


#pragma endregion Container_Block

#pragma region Vector_Block

template<class value_type> Vector<value_type>::Vector()
{
	Container<value_type>::arr = new value_type[_MAX_SIZE_ARR];
	Container<value_type>::_size_ = 0;
}

template<class value_type> void Vector<value_type>::push(const value_type dataPush)
{
	if (Container<value_type>::_size_ != _MAX_SIZE_ARR)
	{
		Container<value_type>::arr[Container<value_type>::_size_++] = dataPush;
	}

	else
	{
		std::cout << "Стэк заполнен. Из стека был извлечён элемент" << this->top() << "и вместо него был добавлен элемент " << dataPush << "\n";
		Container<value_type>::arr[Container<value_type>::_size_ - 1] = dataPush;
		system("Pause");
	}
}

template<class value_type> void Vector<value_type>::pop()
{
	if (Container<value_type>::_size_)
	{
		Container<value_type>::arr[--Container<value_type>::_size_] = 0;
	}
}

template<class value_type> value_type Vector<value_type>::top()
{
	if (Container<value_type>::_size_ == 0)
	{
		throw std::exception("Нет данных в стэке");
	}
	return Container<value_type>::arr[Container<value_type>::_size_ - 1];
}

template<class value_type> Vector<value_type>::~Vector()
{
	delete[] Container<value_type>::arr;
	Container<value_type>::_size_ = 0;
}

template<class value_type> Vector<value_type>& Vector<value_type>::operator=(Vector<value_type>& temp)
{
	if (this == &temp)
		return *this;

	Vector<value_type> tempOne;

	delete[] this->arr;
	this->arr = temp.arr;

	return *this;
}

template<class value_type> Vector<value_type>& Vector<value_type>::operator=(Vector<value_type>&& temp)
{
	delete[] Container<value_type>::arr;

	if (this == &temp)
		return *this;

	Container<value_type>::arr = temp.arr;
	Container<value_type>::_size_ = temp._size_;

	temp.arr = nullptr;
	temp._size_ = 0;

	return *this;
}


#pragma endregion Vector_Block

#pragma region List_Block

template<class value_type> List<value_type>::List()
{
	Container<value_type>::tail = NULL;
	Container<value_type>::_size_ = 0;
}

template<class value_type> void List<value_type>::push(const value_type dataPush)
{
	node<value_type>* temp = new node<value_type>;

	temp->data = dataPush;
	temp->next = Container<value_type>::tail;
	Container<value_type>::tail = temp;
	++Container<value_type>::_size_;
}

template<class value_type> void List<value_type>::pop()
{
	if (Container<value_type>::_size_ <= 0)
	{
		return;
	}

	Container<value_type>::_size_--;
	node<value_type>* temp = Container<value_type>::tail;
	Container<value_type>::tail = Container<value_type>::tail->next;
	delete temp; 
}
template<class value_type> value_type List<value_type>::top()
{
	if (Container<value_type>::_size_ == 0)
	{
		throw std::exception("Нет данных в стэке");
	}
	return Container<value_type>::tail->data;
}

template<class value_type> List<value_type>::~List()
{
	node<value_type>* temp;
	while (Container<value_type>::_size_-- && Container<value_type>::tail)
	{
		temp = Container<value_type>::tail;
		Container<value_type>::tail = Container<value_type>::tail->next;
		delete temp;
	}
}

template<class value_type> List<value_type>& List<value_type>::operator=(List<value_type>& temp)
{
	if (this == &temp)
		return *this;

	uint32_t tmp = Container<value_type>::_size_;
	node<value_type>* tempNode;

	while (Container<value_type>::_size_-- && Container<value_type>::tail)
	{
		tempNode = Container<value_type>::tail;
		Container<value_type>::tail = Container<value_type>::tail->next;
		delete tempNode;
	}

	tempNode = temp.tail;
	Container<value_type>::_size_ = temp._size_;
	temp._size_ = tmp;

	temp.tail = Container<value_type>::tail;
	Container<value_type>::tail = tempNode;


	return *this;
}

template<class value_type> List<value_type>& List<value_type>::operator=(List<value_type>&& temp)
{
	if (this == &temp)
		return *this;

	Container<value_type>::tail = temp.tail;
	Container<value_type>::_size_ = temp._size_;


	temp.tail = nullptr;
	temp._size_ = 0;

	return *this;
}


#pragma endregion List_Block

#pragma region Stack

template <class value_type, template<typename> class Container = Vector> class Stack
{
public:
	Stack() = default;
	void push(value_type data)
	{
		m_Container.push(data);
	}
	void pop()
	{
		m_Container.pop();
	}
	bool empty()
	{
		return m_Container.empty();
	}

	uint32_t size()
	{
		return m_Container.size();
	}

	value_type top()
	{
		return m_Container.top();
	}
	Stack& operator=(const Stack& foo)
	{
		m_Container = foo.m_Container;
		return *this;
	}
	Stack& operator=(Stack&& foo)
	{
		m_Container = std::move(foo.m_Container);
		return *this;
	}

private:
	Container<value_type> m_Container;
};


#pragma endregion Stack
