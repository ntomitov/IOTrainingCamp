/* ========================================================

	Author: Konstantin Dinev
	Date: June 2012
	Purpose: Specific definitions for observables

   ======================================================== */

#include "Observable.h"

#ifndef SPECIFICOBSERVABLE_H

#define SPECIFICOBSERVABLE_H

#ifndef OBSERVER_MAX_SIZE

#define OBSERVER_MAX_SIZE 100

#endif

/// <summary>
///		Specific implementation of IObservable
/// </summary>
class SpecificObservable : public IObservable
{
public:
	SpecificObservable();
	~SpecificObservable();

	void AttachObserver(IObserver*);
	void DetachObserver(IObserver*);
	void Notify();

	// Accessors
	IObserver** GetObservers();
private:
	IObserver** observer_list;
	int size;
};

/// <summary>
///		Initializes a new default instance of the <see cref="SpecificObservable"/>.
/// </summary>
SpecificObservable::SpecificObservable()
{
	size = 0;
	observer_list = new IObserver *[OBSERVER_MAX_SIZE];
	for (int i = 0; i < OBSERVER_MAX_SIZE; i++) 
	{
		observer_list[i] = nullptr;
	}
}

/// <summary>
///		Destroys <see cref="SpecificObservable"/>
/// </summary>
SpecificObservable::~SpecificObservable()
{
	for (int i = 0; i < OBSERVER_MAX_SIZE; i++)
	{
		delete observer_list[i];
	}
	delete [] observer_list;
}

/// <summary>
///		Attaches <see cref="IObserver"/> to <see cref="SpecificObservable"/>
/// </summary>
/// <param name="obs">The IObserver to attach</param>
void SpecificObservable::AttachObserver(IObserver* obs)
{
	for (int i = 0; i < OBSERVER_MAX_SIZE; i++)
	{
		if (observer_list[i] == nullptr)
		{
			observer_list[i] = obs;
			return;
		}
	}
	throw("No more observers can be attached. Maximum container size exceeded.");
}

/// <summary>
///		Detaches <see cref="IObserver"/> to <see cref="SpecificObservable"/>
/// </summary>
/// <param name="obs">The IObserver to detach</param>
void SpecificObservable::DetachObserver(IObserver* obs)
{
	for (int i = 0; i < OBSERVER_MAX_SIZE; i++)
	{
		if (observer_list[i] != nullptr && observer_list[i] == obs)
		{
			delete observer_list[i];
			observer_list[i] = nullptr;
		}
	}
}

/// <summary>
///		Notifies the list of <see cref="IObserver"/> that the IObservable's state has changed
/// </summary>
void SpecificObservable::Notify()
{
	for (int i = 0; i < OBSERVER_MAX_SIZE; i++)
	{
		if (observer_list[i] != nullptr)
		{
			observer_list[i]->Update();
		}
	}
}

/// <summary>
///		Notifies the list of <see cref="IObserver"/> that the IObservable's state has changed
/// </summary>
/// <returns>The list of observers</returns>
IObserver** SpecificObservable::GetObservers()
{
	return observer_list;
}

#endif
