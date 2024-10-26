#include "Repository.hpp"

using namespace std;

class Services
{
private:
	Repository repository;
public:
	Services();
	~Services() {};
	bool addTutorial(const string& title, const string& presenter, const string& duration, const string &link, const int& likes);
	bool removeTutorial(const string& title);
	bool updateTutorial(const string& oldTitle, const string& newTitle, const string& newPresenter, const string& newDuration, const string& newLink, const int& newLikes);
	DynamicArray<Tutorial> getTutorials() const;
	void setupStartList();
	DynamicArray<Tutorial> getTutorialsByPresenter(const string& presenter);
	void openTutorialInBrowser(const string& link);
	bool addToWatchlist(Tutorial tutorial);
	DynamicArray<Tutorial> getWatchlist();
	bool removeFromWatchlist(const string& title);
};