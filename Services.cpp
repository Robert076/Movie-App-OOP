#include "Services.hpp"

using namespace std;

Services::Services()
{
	/*
	* Constructor for the Services class.
	* It creates a new Repository object.
	*/
	this->repository = Repository();
}

bool Services::addTutorial(const string& title, const string& presenter, const string& duration, const string& link, const int& likes)
{
	/*
	* Method that adds a new tutorial to the repository by calling the addTutorial method from the Repository class.
	* Input: title, a string representing the title of the tutorial.
	* 		 presenter, a string representing the presenter of the tutorial.
	* 		 duration, a string representing the duration of the tutorial.
	* 		 link, a string representing the link of the tutorial.
	* 		 likes, an integer representing the number of likes of the tutorial.
	* Output: the tutorial is added to the repository.
	* 
	*/
	Tutorial t(title, presenter, duration, link, likes);
	return this->repository.addTutorial(t);
}

bool Services::removeTutorial(const string& title)
{
	/*
	* Method that removes a tutorial from the repository by calling the removeTutorial method from the Repository class.
	* Input: title, a string representing the title of the tutorial.
	* Output: the tutorial is removed from the repository.
	*/
	return this->repository.removeTutorial(title);
}

bool Services::updateTutorial(const string& oldTitle, const string& newTitle, const string& newPresenter, const string& newDuration, const string& newLink, const int& newLikes)
{
	/*
	* Method that updates a tutorial from the repository by calling the updateTutorial method from the Repository class.
	* Input: oldTitle, a string representing the title of the tutorial that will be updated.
	* 		 newTitle, a string representing the new title of the tutorial.
	* 		 newPresenter, a string representing the new presenter of the tutorial.
	* 		 newDuration, a string representing the new duration of the tutorial.
	* 		 newLink, a string representing the new link of the tutorial.
	* 		 newLikes, an integer representing the new number of likes of the tutorial.
	* Output: the tutorial is updated in the repository.
	*/
	if(this->repository.updateTutorial(oldTitle, newTitle, newPresenter, newDuration, newLink, newLikes))
		return true;
	return false;	
}

DynamicArray<Tutorial> Services::getTutorials() const
{
	/*
	* Method that returns the tutorials from the repository by calling the getTutorials method from the Repository class.
	* Output: a DynamicArray of Tutorial objects.
	*/
	return this->repository.getTutorials();
}

DynamicArray<Tutorial> Services::getTutorialsByPresenter(const string& presenter)
{
	/*
	* Method that returns the tutorials from the repository by calling the getTutorialsByPresenter method from the Repository class.
	* Output: a DynamicArray of Tutorial objects.
	*/
	return this->repository.getTutorialsByPresenter(presenter);

}

void Services::openTutorialInBrowser(const string& link)
{
	/*
	* Method that opens a tutorial in the browser.
	* Input: link, a string representing the link of the tutorial.
	* Output: the tutorial is opened in the browser.
	*/
	string command = "start " + link;
	system(command.c_str());
}

bool Services::addToWatchlist(Tutorial tutorial)
{
	/*
	* Method that adds a tutorial to the watchlist by calling the addToWatchlist method from the Repository class.
	* Input: tutorial, a Tutorial object.
	* Output: the tutorial is added to the watchlist.
	*/
	if (this->repository.addToWatchlist(tutorial))
		return true;
	return false;
}

DynamicArray <Tutorial> Services::getWatchlist()
{
	/*
	* Method that returns the watchlist by calling the getWatchlist method from the Repository class.
	* Output: a DynamicArray of Tutorial objects.
	*/
	return this->repository.getWatchlist();
}

bool Services::removeFromWatchlist(const string& title)
{
	/*
	* Method that removes a tutorial from the watchlist by calling the removeFromWatchlist method from the Repository class.
	* Input: title, a string representing the title of the tutorial.
	* Output: the tutorial is removed from the watchlist.
	*/
	if (this->repository.removeFromWatchlist(title))
		return true;
	return false;
}

void Services::setupStartList()
{
	/*
	* Method that initializes the repository with some tutorials.
	*/
	Tutorial tutorial1("C++ Tutorial For Beginners", "Programming with Mosh", "1:22:55", "https://youtu.be/ZzaPdXTrSb8?si=oRO6Ax6aWtyy4vcK", 90138);
	Tutorial tutorial2("C++ Tutorial For Beginners - Full Course", "freeCodeCamp.org", "4:01:18", "https://youtu.be/vLnPwxZdW4Y?si=Wfo5l4Vw3Tw3WlJp", 278532);
	Tutorial tutorial3("Learn C++ with me #9 - Arrays", "Tech with Tim", "21:34", "https://www.youtube.com/watch?v=1FVBeLD_FdE", 1575);
	Tutorial tutorial4("Learn C++ with me #10 - For Loops", "Tech with Tim", "16:10", "https://www.youtube.com/watch?v=gVmTVsAn6EI", 858);
	Tutorial tutorial5("Do-While Loop", "Neso Academy", "5:02", "https://www.youtube.com/watch?v=TjkJQly2YCw", 10859);
	Tutorial tutorial6("Learn C++ With Me #11 - While, Do While Loops & Break/Continue", "Tech with Tim", "24:00", "https://www.youtube.com/watch?v=aOskrzlcBRY", 744);
	Tutorial tutorial7("C++ in 100 seconds", "Fireship", "2:45", "https://youtube.com/watch?v=MNeX4EGtR5Y", 69486);
	Tutorial tutorial8("31 nooby C++ habits you need to ditch", "mCoding", "19:55", "https://www.youtube.com/watch?v=i_wDa2AS_8w", 25856);
	Tutorial tutorial9("Forbidden C++", "javidx9", "33:06", "https://www.youtube.com/watch?v=j0_u26Vpb4w", 35945);
	Tutorial tutorial10("Functions in C++", "The Chemo", "9:49", "https://www.youtube.com/watch?v=V9zuox47zr0", 18539);
	Tutorial tutorial11("C++ user defined functions (#15)", "Bro Code", "17:13", "https://www.youtube.com/watch?v=vKTYM-DJDiw", 836);
	Tutorial tutorial12("C++ Programming Tutorial 10 - Intro to Functions", "Caleb Curry", "6:29", "https://www.youtube.com/watch?v=VZYMp7SY0W4", 2319);
	Tutorial tutorial13("C++ Tutorial - Loops In C++ [For Loop, While Loop, Do While Loop]", "Parwiz Forogh", "16:19", "https://www.youtube.com/watch?v=jNl5gJ_xSNQ", 794);
	this->repository.addTutorial(tutorial1);
	this->repository.addTutorial(tutorial2);
	this->repository.addTutorial(tutorial3);
	this->repository.addTutorial(tutorial4);
	this->repository.addTutorial(tutorial5);
	this->repository.addTutorial(tutorial6);
	this->repository.addTutorial(tutorial7);
	this->repository.addTutorial(tutorial8);
	this->repository.addTutorial(tutorial9);
	this->repository.addTutorial(tutorial10);
	this->repository.addTutorial(tutorial11);
	this->repository.addTutorial(tutorial12);
	this->repository.addTutorial(tutorial13);
}