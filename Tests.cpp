#include "Tests.hpp"

void Tests::testDynamicArray()
{
	/*
	* Here we test all the functionalities of the dynamic array.
	*/
	DynamicArray<Tutorial> dynamicArray;
	assert(dynamicArray.getSize() == 0);
	Tutorial tutorial1{ "title1", "presenter1", "duration1", "link1", 1 };
	Tutorial tutorial2{ "title2", "presenter2", "duration2", "link2", 2 };
	Tutorial tutorial3{ "title3", "presenter3", "duration3", "link3", 3 };
	dynamicArray.addElement(tutorial1);
	assert(dynamicArray.getSize() == 1);
	dynamicArray.addElement(tutorial2);
	assert(dynamicArray.getSize() == 2);
	dynamicArray.addElement(tutorial3);
	assert(dynamicArray.getSize() == 3);
	assert(dynamicArray[0].getTitle() == "title1");
	assert(dynamicArray[1].getTitle() == "title2");
	assert(dynamicArray[2].getTitle() == "title3");
	dynamicArray.removeElement(1);
	assert(dynamicArray.getSize() == 2);
	assert(dynamicArray[0].getTitle() == "title1");
	assert(dynamicArray[1].getTitle() == "title3");
	dynamicArray.removeElement(0);
	assert(dynamicArray.getSize() == 1);
	assert(dynamicArray[0].getTitle() == "title3");
	dynamicArray.removeElement(0);
	assert(dynamicArray.getSize() == 0);
	// now we test the copy constructor
	dynamicArray.addElement(tutorial1);
	dynamicArray.addElement(tutorial2);
	dynamicArray.addElement(tutorial3);
	DynamicArray<Tutorial> dynamicArray2{ dynamicArray };
	assert(dynamicArray2.getSize() == 3);
	assert(dynamicArray2[0].getTitle() == "title1");
	assert(dynamicArray2[1].getTitle() == "title2");
	assert(dynamicArray2[2].getTitle() == "title3");
	// now we test the assignment operator
	DynamicArray<Tutorial> dynamicArray3;
	dynamicArray3 = dynamicArray2;
	assert(dynamicArray3.getSize() == 3);
	assert(dynamicArray3[0].getTitle() == "title1");
	assert(dynamicArray3[1].getTitle() == "title2");
	assert(dynamicArray3[2].getTitle() == "title3");
	// now we test the update
	Tutorial tutorial4{ "title4", "presenter4", "duration4", "link4", 4 };
	dynamicArray3.updateElement(0, tutorial4);
	assert(dynamicArray3[0].getTitle() == "title4");
	// now we test the returnPosition method
	assert(dynamicArray3.returnPosition(tutorial4) == 0);
	// now we test the iterator
	DynamicArray<Tutorial>::Iterator iterator = dynamicArray3.begin();
	assert(iterator != dynamicArray3.end());
	++iterator;
	assert(iterator != dynamicArray3.end());
	++iterator;
	assert(iterator != dynamicArray3.end());
	++iterator;
	assert(iterator == dynamicArray3.end());
	// now the return position method
	assert(dynamicArray3.returnPosition(tutorial4) == 0);
	//testing that returnPosition returns -1
	assert(dynamicArray3.returnPosition(tutorial1) == -1);
}

void Tests::testRepository()
{
	/*
	* Here we test all the functionalities of the repository.
	*/
	Repository repository;
	assert(repository.getTutorials().getSize() == 0);
	Tutorial tutorial1{ "title1", "presenter1", "duration1", "link1", 1 };
	Tutorial tutorial2{ "title2", "presenter2", "duration2", "link2", 2 };
	Tutorial tutorial3{ "title3", "presenter3", "duration3", "link3", 3 };
	repository.addTutorial(tutorial1);
	assert(repository.getTutorials().getSize() == 1);
	repository.addTutorial(tutorial2);
	assert(repository.getTutorials().getSize() == 2);
	repository.addTutorial(tutorial3);
	assert(repository.getTutorials().getSize() == 3);
	assert(repository.getTutorials()[0].getTitle() == "title1");
	assert(repository.getTutorials()[1].getTitle() == "title2");
	assert(repository.getTutorials()[2].getTitle() == "title3");
	repository.removeTutorial("title2");
	assert(repository.getTutorials().getSize() == 2);
	assert(repository.getTutorials()[0].getTitle() == "title1");
	assert(repository.getTutorials()[1].getTitle() == "title3");
	repository.removeTutorial("title1");
	assert(repository.getTutorials().getSize() == 1);
	assert(repository.getTutorials()[0].getTitle() == "title3");
	repository.removeTutorial("title3");
	assert(repository.getTutorials().getSize() == 0);
	// now we test the update
	repository.addTutorial(tutorial1);
	repository.addTutorial(tutorial2);
	repository.addTutorial(tutorial3);
	repository.updateTutorial("title1", "title4", "presenter4", "duration4", "link4", 4);
	assert(repository.getTutorials()[0].getTitle() == "title4");	
	//now we test the remaining repository methods
	assert(repository.getTutorialsByPresenter("presenter4").getSize() == 1);
	assert(repository.getTutorialsByPresenter("presenter5").getSize() == 0);
	//now we test the watchlist methods
	assert(repository.addToWatchlist(tutorial1) == true);
	assert(repository.addToWatchlist(tutorial1) == false);
	assert(repository.getWatchlist().getSize() == 1);
	assert(repository.removeFromWatchlist("title1") == true);
	assert(repository.removeFromWatchlist("title1") == false);
	//testing get size
	assert(repository.getSize() == 3);
	//testing that removeTutorial returns false if the tutorial is not in the repository
	assert(repository.removeTutorial("title5") == false);
	//testig that updateTutorail in repository returns false
	assert(repository.updateTutorial("title5", "title6", "presenter6", "duration6", "link6", 6) == false);
	//testing updateTutorial and the fact that it returns false if the updated movie has the same likes as the new ones
	assert(repository.updateTutorial("title4", "title4", "presenter4", "duration4", "link4", 4) == false);
}

void Tests::testServices()
{
	/*
	* Here we test all the functionalities of the services.
	*/
	Services services;
	assert(services.getTutorials().getSize() == 0);
	services.setupStartList();
	assert(services.getTutorials().getSize() == 13);
	services.removeTutorial("C++ Tutorial For Beginners");
	assert(services.getTutorials().getSize() == 12);
	services.removeTutorial("C++ Tutorial For Beginners - Full Course");
	assert(services.getTutorials().getSize() == 11);
	services.removeTutorial("Learn C++ with me #9 - Arrays");
	assert(services.getTutorials().getSize() == 10);
	services.removeTutorial("Learn C++ with me #10 - For Loops");
	assert(services.getTutorials().getSize() == 9);
	services.removeTutorial("Do-While Loop");
	assert(services.getTutorials().getSize() == 8);
	services.removeTutorial("Learn C++ With Me #11 - While, Do While Loops & Break/Continue");
	assert(services.getTutorials().getSize() == 7);
	services.removeTutorial("C++ in 100 seconds");
	assert(services.getTutorials().getSize() == 6);
	services.removeTutorial("31 nooby C++ habits you need to ditch");
	assert(services.getTutorials().getSize() == 5);
	services.removeTutorial("Forbidden C++");
	assert(services.getTutorials().getSize() == 4);
	services.removeTutorial("Functions in C++");
	assert(services.getTutorials().getSize() == 3);
	services.removeTutorial("C++ user defined functions (#15)");
	assert(services.getTutorials().getSize() == 2);
	services.removeTutorial("C++ Programming Tutorial 10 - Intro to Functions");
	assert(services.getTutorials().getSize() == 1);
	services.removeTutorial("C++ Tutorial - Loops In C++ [For Loop, While Loop, Do While Loop]");
	assert(services.getTutorials().getSize() == 0);
	services.setupStartList();
	services.updateTutorial("C++ Tutorial For Beginners", "Tutorial15", "Presenter5", "5:55", "Link5", 50);
	assert(services.getTutorials()[0].getTitle() == "Tutorial15");
	Services services2;
	services2.setupStartList();
	assert(services2.getTutorialsByPresenter("Programming with Mosh").getSize() == 1);
	assert(services2.getTutorialsByPresenter("freeCodeCamp.org").getSize() == 1);
	assert(services2.getTutorialsByPresenter("Tech with Tim").getSize() == 3);
	assert(services2.getTutorialsByPresenter("Neso Academy").getSize() == 1);
	assert(services2.getTutorialsByPresenter("Fireship").getSize() == 1);
	assert(services2.getTutorialsByPresenter("mCoding").getSize() == 1);
	assert(services2.addToWatchlist(services.getTutorials()[0]) == true);
	assert(services2.addToWatchlist(services.getTutorials()[0]) == false);
	assert(services2.getWatchlist().getSize() == 1);
	assert(services2.removeFromWatchlist("Tutorial15") == true);
	assert(services2.removeFromWatchlist("Tutorial15") == false);
	services2.openTutorialInBrowser("https://www.youtube.com/watch?v=VZYMp7SY0W4");
	//testing the addTutorial method
	assert(services.addTutorial("title", "presenter", "duration", "link", 1) == true);
	assert(services.addTutorial("title", "presenter", "duration", "link", 1) == false);
	//testing that updateTutorial returns false
	assert(services.updateTutorial("title", "title", "presenter", "duration", "link", 1) == false);
}

void Tests::testTutorial()
{
	/*
	* Here we test all the functionalities of the tutorial.
	*/
	Tutorial tutorial{ "title", "presenter", "duration", "link", 1 };
	assert(tutorial.getTitle() == "title");
	assert(tutorial.getPresenter() == "presenter");
	assert(tutorial.getDuration() == "duration");
	assert(tutorial.getLink() == "link");
	assert(tutorial.getLikes() == 1);
	tutorial.setTitle("title2");
	tutorial.setPresenter("presenter2");
	tutorial.setDuration("duration2");
	tutorial.setLink("link2");
	tutorial.setLikes(2);
	assert(tutorial.getTitle() == "title2");
	assert(tutorial.getPresenter() == "presenter2");
	assert(tutorial.getDuration() == "duration2");
	assert(tutorial.getLink() == "link2");
	assert(tutorial.getLikes() == 2);
}