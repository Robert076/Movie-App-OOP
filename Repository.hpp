#pragma once
#include "Domain.hpp"
#include "DynamicArray.hpp"

class Repository
{
private:
	DynamicArray<Tutorial> tutorials;
	DynamicArray<Tutorial> watchlist;
public:
	Repository();
	~Repository();
	bool addTutorial(Tutorial tutorial);
	DynamicArray<Tutorial> getTutorials() const;
	int getSize();
	bool removeTutorial(const string& title);
	bool updateTutorial(const string& oldTitle, const string& newTitle, const string& newPresenter, const string& newDuration, const string& newLink, const int& newLikes);
	DynamicArray<Tutorial> getTutorialsByPresenter(const string& presenter);
	DynamicArray<Tutorial> getWatchlist() const;
	bool addToWatchlist(Tutorial tutorial);
	bool removeFromWatchlist(const string& title);
};