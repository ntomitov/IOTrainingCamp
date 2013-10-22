/* ========================================================

	Author: Konstantin Dinev
	Date: June 2012
	Purpose: Interface for observer object and Interface 
		for observer object

   ======================================================== */

#ifndef OBSERVABLE_H

#define OBSERVABLE_H

/// <summary>
///		Oberver abstract base class
/// </summary>
class IObserver
{
public:
	/// <summary>
	///		Update method that would be triggered by the <see cref="IObservable"/> upon change of state.
	/// </summary>
	virtual void Update() = 0;
};


/// <summary>
///		Observable abstract base class
/// </summary>
class IObservable
{
public:
	/// <summary>
	///		Attaching an IObserver to the list of <see cref="IObserver"/> that the IObservable needs to notify about its state change
	/// </summary>
	/// <param> The IObserver to attach </param>
	virtual void AttachObserver(IObserver*) = 0;
	/// <summary>
	///		Detaching an IObserver from the list of <see cref="IObserver"/> that the IObservable needs to notify about its state change
	/// </summary>
	/// <param> The IObserver to detach </param>
	virtual void DetachObserver(IObserver*) = 0;
	/// <summary>
	///		Notifies the list of <see cref="IObserver"/> that the IObservable's state has changed
	/// </summary>
	virtual void Notify() = 0;
};

#endif
