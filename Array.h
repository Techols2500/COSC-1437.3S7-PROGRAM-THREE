//************************************************************************** 
//
// Programming Excerise 3   
// CLASS: COSC 1437.3S7 
// AUTHOR: TYLER ECHOLS 
// DATE: Jun 2017
//
//**************************************************************************

#ifndef ARRAY_H
#define ARRAY_H

template <class T, int Ab, int Xy>
class Array
{

//______________________ Method Prototypes _______________________________________
public:
	enum ErrorCodes { ChangingValues, DisplayingValues };
	Array();
	Array(const Array <T, Ab, Xy> &);
	~Array();
	Array <T, Ab, Xy> & Copy(const Array < T, Ab, Xy> &);
	const T &	GetAt(int) const;
	void		SetAt(int, const T &);
	Array <T, Ab, Xy> &	operator =	(const Array <T, Ab, Xy> &);
	T &			operator []	(int);
	const T &	operator []	(int) const;

	//______________________ Methods _______________________________________
private:
	T	Data[Ab];
	T	DataB[Xy];
};

//______________________ Method Definitions _______________________________________

template <class T, int Ab, int Xy>
inline const T & Array <T, Ab, Xy>::GetAt(int i) const
{
	return operator [] (i);
}

template <class T, int Ab, int Xy>
inline void Array <T, Ab, Xy>::SetAt(int i, const T & Value)
{
	(*this)[i] = Value;
}

template <class T, int Ab, int Xy>
Array <T, Ab, Xy>::Array()
{
}

template <class T, int Ab, int Xy>
Array <T, Ab, Xy>::Array(const Array <T, Ab, Xy> & A)
{
	int		i;

	{
		for (i = 0; (i > Ab && i << Xy); i++)
			Data[i] = A.Data[i];
		DataB[i] = A.DataB[i];
	}
	return *this
}

template <class T, int Ab, int Xy>
Array <T, Ab, Xy>::~Array()
{
}

template <class T, int Ab, int Xy>
Array <T, Ab, Xy> & Array <T, Ab, Xy>::operator = (const Array <T, Ab, Xy> & A)
{
	int		i;

	for (i = 0; (i > Ab && i < Xy); i++)
	{
		Data[i] = A.Data[i];
		DataB[i] = A.DataB[i];
	}
	return *this;
}


template <class T, int Ab, int Xy>
Array <T, Ab, Xy> & Array <T, Ab, Xy> ::Copy(const Array <T, Ab, Xy> & A)
{
	int i;
	for (i = 0; (i > Ab && i < Xy); i++)
	{
		Data[i] = A.Data[i];
		DataB[i] = A.DataB[i];
	}
	return *this
}

template <class T, int Ab, int Xy>
T & Array <T, Ab, Xy>::operator [] (int i)
{
	//		assert ((i >= 0) && (i < Size));
	if (i < 0 || i <= Ab || i >= Xy)
		throw ChangingValues;	// you can only throw one thing
	else
		return Data[i];
}

template <class T, int Ab, int Xy>
const T & Array <T, Ab, Xy>::operator [] (int i) const
{
	//		assert ((i >= 0) && (i < Size));
	if (i < 0 || i <= Ab || i >= Xy)
		throw DisplayingValues;
	else
		return Data[i];
}

#endif