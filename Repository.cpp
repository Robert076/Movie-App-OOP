#include "Repository.hpp"

Repository::Repository()
{
	/*
	* Constructor for the repository class.
	* Initializes the dynamic array of tutorials.
	*/
	this->tutorials = DynamicArray<Tutorial>();
	this->watchlist = DynamicArray<Tutorial>();
}

Repository::~Repository()
{
	/*
	* Destructor for the repository class.
	* Nothing to do here, this will automatically call the destructor of the dynamic array.
	*/
}

bool Repository::addTutorial(Tutorial tutorial)
{
	/*
	* Method that adds a tutorial to the repository.
	* Input: tutorial - Tutorial object
	* Output: the tutorial is added to the repository
	*/
	for (int i = 0; i < this->tutorials.getSize(); i++)
	{
		if (this->tutorials[i].getTitle() == tutorial.getTitle())
			return false;
	}
	this->tutorials.addElement(tutorial);
	return true;
}

bool Repository::removeTutorial(const string& title)
{
	/*
	* Method that removes a tutorial from the repository.
	* Input: title - string of the title we want to remove
	* Output: the tutorial is removed from the repository
	*/
	for (int i = 0; i < this->tutorials.getSize(); i++)
	{
		if (this->tutorials[i].getTitle() == title)
		{
			this->tutorials.removeElement(i);
			return true;
		}
	}
	return false;
}

bool Repository::updateTutorial(const string& oldTitle, const string& newTitle, const string& newPresenter, const string& newDuration, const string& newLink, const int& newLikes)
{
	/*
	* Method that updates a tutorial from the repository.
	* Input: oldTitle - string of the title we want to update
	* 	     newTitle - string of the updated title
	* 		 newPresenter - string of the updated presenter
	* 		 newDuration - string of the updated duration
	*		 newLink - string of the updated link
	* 		 newLikes - integer of the updated likes
	* Output: the tutorial is updated in the repository
	*/

	
	Tutorial updatedTutorial(newTitle, newPresenter, newDuration, newLink, newLikes);
	for (int i = 0; i < this->tutorials.getSize(); i++)
		if (this->tutorials[i].getTitle() == newTitle && this->tutorials[i].getLikes() == newLikes)
			return false;

	for (int i = 0; i < this->tutorials.getSize(); i++)
	{
		if (this->tutorials[i].getTitle() == oldTitle)
		{
			this->tutorials.updateElement(i, updatedTutorial);
			return true;
		}
	}
	return false;
}

DynamicArray<Tutorial> Repository::getTutorials() const
{
	/*
	* Method that returns the tutorials from the repository.
	* Input: -
	* Output: the tutorials from the repository
	*/
	return this->tutorials;
}

int Repository::getSize()
{
	/*
	* Method that returns the size of the repository.
	* Input: -
	* Output: the size of the repository
	*/
	return this->tutorials.getSize();
}

DynamicArray<Tutorial> Repository::getTutorialsByPresenter(const string& presenter)
{
	/*
	* Method that returns the tutorials from the repository by a certain presenter.
	* Input: presenter - string of the presenter we want to search for
	* Output: the tutorials from the repository by a certain presenter
	*/
	DynamicArray<Tutorial> tutorialsByPresenter = DynamicArray<Tutorial>();
	for (int i = 0; i < this->tutorials.getSize(); i++)
	{
		if (this->tutorials[i].getPresenter() == presenter)
			tutorialsByPresenter.addElement(this->tutorials[i]);
	}
	return tutorialsByPresenter;
}

DynamicArray<Tutorial> Repository::getWatchlist() const
{
	return this->watchlist;
}

bool Repository::addToWatchlist(Tutorial tutorial)
{
	for (int i = 0; i < this->watchlist.getSize(); i++)
		if (this->watchlist[i].getTitle() == tutorial.getTitle())
			return false;
	this->watchlist.addElement(tutorial);
	return true;
}

bool Repository::removeFromWatchlist(const string& title) 
{
	for (int i = 0; i < this->watchlist.getSize(); i++)
		if (this->watchlist[i].getTitle() == title)
		{
			this->watchlist.removeElement(i);
			return true;
		}
	return false;
}