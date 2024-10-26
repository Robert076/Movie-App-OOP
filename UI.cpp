#include "UI.hpp"
#include <iostream>
#include <cstdlib>

using namespace std;

void UI::run()
{
	cout << "Welcome to the application!\n";
	cout << "1. Administrator\n";
	cout << "2. User\n";
	cout << "3. Exit\n";

	int userInput;
	cin >> userInput;

	int administratorMode = 1, userMode = 2, exit = 3;
	if (userInput == administratorMode)
		UI::runAdmin();
	else if (userInput == userMode)
		UI::runUser();
	else if (userInput == exit)
		return;
	else
		cout << "Invalid input!\n";
}

UI::UI()
{
	this->services = Services();
	this->services.setupStartList();
}

void UI::runAdmin()
{
	system("cls");
	while (true)
	{
		cout << "Welcome to admin mode!\n";
		cout << "1. Add a tutorial\n";
		cout << "2. Remove a tutorial\n";
		cout << "3. Update a tutorial\n";
		cout << "4. List all tutorials\n";
		cout << "5. Exit\n";

		int userInput;
		cin >> userInput;

		int addTutorialOption = 1, removeTutorialOption = 2, updateTutorialOption = 3, listAllOption = 4, exitOption = 5;

		if (userInput == addTutorialOption)
			UI::manageAddTutorial();
		else if(userInput == removeTutorialOption)
			UI::manageRemoveTutorial();
		else if(userInput == updateTutorialOption)
			UI::manageUpdateTutorial();
		else if (userInput == listAllOption)
			UI::manageListAll();
		else if (userInput == exitOption)
			return;
		else
			cout << "Invalid input!\n";
	}
}

void UI::manageAddTutorial()
{
	string title, presenter, duration, link;
	int likes;

	while (cin.get() != '\n');
	cout << "Title: ";
	getline(cin, title);
	cout << "Presenter: ";
	getline(cin, presenter);
	cout << "Duration: ";
	getline(cin, duration);
	cout << "Link: ";
	getline(cin, link);
	cout << "Likes: ";
	cin >> likes;

	if (this->services.addTutorial(title, presenter, duration, link, likes))
		cout << "Tutorial added successfully!\n";
	else
		cout << "Tutorial already exists!\n";
}

void UI::manageRemoveTutorial()
{
	string title;
	while (cin.get() != '\n');
	cout << "Title to remove: ";
	getline(cin, title);

	bool wasRemoved = this->services.removeTutorial(title);
	if(wasRemoved)
		cout << "Tutorial removed successfully!\n";
	else
		cout << "Tutorial not found!\n";
}

void UI::manageUpdateTutorial()
{
	string oldTitle, newTitle, newPresenter, newDuration, newLink;
	int newLikes;
	while (cin.get() != '\n');
	cout << "The title of the tutorial you want to update: ";
	getline(cin, oldTitle);
	cout << "Updated title: ";
	getline(cin, newTitle);
	cout << "Updated presenter: ";
	getline(cin, newPresenter);
	cout << "Updated duration: ";
	getline(cin, newDuration);
	cout << "Updated link: ";
	getline(cin, newLink);
	cout << "Updated likes: ";
	cin >> newLikes;
	if (this->services.updateTutorial(oldTitle, newTitle, newPresenter, newDuration, newLink, newLikes))
		cout << "Tutorial updated successfully!\n";
	else
		cout << "Tutorial was either not found or one with the same title exists!\n";
}

	
void UI::manageListAll()
{
	DynamicArray<Tutorial> tutorials = this->services.getTutorials();
	for (int i = 0; i < tutorials.getSize(); i++)
	{
		cout << "Title: " << tutorials[i].getTitle() << " | Presenter: " << tutorials[i].getPresenter() << " | Duration: " << tutorials[i].getDuration() << " | Link: " << tutorials[i].getLink() << " | Likes: " << tutorials[i].getLikes() << "\n";
	}
}

void UI::runUser()
{
	system("cls");
	while (true)
	{
		cout << "1. See tutorials by a certain presenter\n";
		cout << "2. Remove tutorial from watchlist\n";
		cout << "3. See your watchlist\n";
		cout << "4. Exit\n";

		int userInput;
		cin >> userInput;

		int seeTutorialsByPresenterOption = 1, removeTutorialFromWatchlist = 2, seeWatchlistOption = 3, exitOption = 4;

		if (userInput == seeTutorialsByPresenterOption)
			UI::manageSeeTutorialsByPresenter();
		else if (userInput == removeTutorialFromWatchlist)
			UI::manageRemoveFromWatchlist();
		else if (userInput == seeWatchlistOption)
			UI::manageSeeWatchlist();
		else if(userInput == exitOption)
			return;
		else
			cout << "Invalid input!\n";
	}
}	

void UI::manageSeeTutorialsByPresenter()
{
	string presenter;
	while (cin.get() != '\n');
	cout << "Presenter: ";
	getline(cin, presenter);

	if (presenter == "all")
	{
		DynamicArray<Tutorial> tutorials = this->services.getTutorials();
		for (int i = 0; i < tutorials.getSize(); i++)
		{
			cout << "Title: " << tutorials[i].getTitle() << " | Presenter: " << tutorials[i].getPresenter() << " | Duration: " << tutorials[i].getDuration() << " | Link: " << tutorials[i].getLink() << " | Likes: " << tutorials[i].getLikes() << "\n";
			this->services.openTutorialInBrowser(tutorials[i].getLink());

			cout << "Would you like to add this tutorial to your watchlist?(yes/no)\n";
			string addToWatchlist;
			cin >> addToWatchlist;

			if (addToWatchlist == "yes")
				if (this->services.addToWatchlist(tutorials[i]))
					cout << "Tutorial added succesfully to the watchlist!\n";
				else
					cout << "Tutorial could not be added!\n";
		}
		cout << "Would you like to see them again?\n";

		string seeAgain;
		cin >> seeAgain;

		while (seeAgain == "yes")
		{
			for (int i = 0; i < tutorials.getSize(); i++)
			{
				cout << "Title: " << tutorials[i].getTitle() << " | Presenter: " << tutorials[i].getPresenter() << " | Duration: " << tutorials[i].getDuration() << " | Link: " << tutorials[i].getLink() << " | Likes: " << tutorials[i].getLikes() << "\n";
				this->services.openTutorialInBrowser(tutorials[i].getLink());

				cout << "Would you like to add this tutorial to your watchlist?(yes/no)\n";
				string addToWatchlist;
				cin >> addToWatchlist;

				if (addToWatchlist == "yes")
					if (this->services.addToWatchlist(tutorials[i]))
						cout << "Tutorial added succesfully to the watchlist!\n";
					else
						cout << "Tutorial could not be added!\n";
			}
			cout << "Would you like to see them again?\n";

			cin >> seeAgain;
		}
	}
	else
	{
		DynamicArray<Tutorial> tutorials = this->services.getTutorialsByPresenter(presenter);
		for (int i = 0; i < tutorials.getSize(); i++)
		{
			cout << "Title: " << tutorials[i].getTitle() << " | Presenter: " << tutorials[i].getPresenter() << " | Duration: " << tutorials[i].getDuration() << " | Link: " << tutorials[i].getLink() << " | Likes: " << tutorials[i].getLikes() << "\n";
			this->services.openTutorialInBrowser(tutorials[i].getLink());

			cout << "Would you like to add this tutorial to your watchlist?(yes/no)\n";
			string addToWatchlist;
			cin >> addToWatchlist;

			if (addToWatchlist == "yes")
				if (this->services.addToWatchlist(tutorials[i]))
					cout << "Tutorial added succesfully to the watchlist!\n";
				else
					cout << "Tutorial could not be added!\n";
		}

		cout << "Would you like to see them again?\n";

		string seeAgain;
		cin >> seeAgain;

		while (seeAgain == "yes")
		{
			for (int i = 0; i < tutorials.getSize(); i++)
			{
				cout << "Title: " << tutorials[i].getTitle() << " | Presenter: " << tutorials[i].getPresenter() << " | Duration: " << tutorials[i].getDuration() << " | Link: " << tutorials[i].getLink() << " | Likes: " << tutorials[i].getLikes() << "\n";
				this->services.openTutorialInBrowser(tutorials[i].getLink());

				cout << "Would you like to add this tutorial to your watchlist?(yes/no)\n";
				string addToWatchlist;
				cin >> addToWatchlist;

				if (addToWatchlist == "yes")
					if (this->services.addToWatchlist(tutorials[i]))
						cout << "Tutorial added succesfully to the watchlist!\n";
					else
						cout << "Tutorial could not be added!\n";
			}
			cout << "Would you like to see them again?\n";

			cin >> seeAgain;
		}
	}
}

void UI::manageSeeWatchlist()
{
	DynamicArray<Tutorial> watchlist = this->services.getWatchlist();

	for (int i = 0; i < watchlist.getSize(); i++)
		cout << "Title: " << watchlist[i].getTitle() << " | Presenter: " << watchlist[i].getPresenter() << " | Duration: " << watchlist[i].getDuration() << " | Link: " << watchlist[i].getLink() << " | Likes: " << watchlist[i].getLikes() << "\n";
}

void UI::manageRemoveFromWatchlist()
{
	string title;
	while (cin.get() != '\n');
	cout << "Title you want to remove from watchlist: ";
	getline(cin, title);

	if (this->services.removeFromWatchlist(title))
	{
		DynamicArray<Tutorial> tutorials = this->services.getTutorials();

		cout << "Did you like this tutorial?(yes/no)\n";
		string didTheUserLikeTheTutorial;

		cin >> didTheUserLikeTheTutorial;
		if(didTheUserLikeTheTutorial == "yes")
			for (int i = 0; i < tutorials.getSize(); i++)
				if (tutorials[i].getTitle() == title)
					this->services.updateTutorial(title, tutorials[i].getTitle(), tutorials[i].getPresenter(), tutorials[i].getDuration(), tutorials[i].getLink(), tutorials[i].getLikes() + 1);
		cout << "Tutorial succesfully removed from watchlist!\n";
	}
	else
		cout << "Could not remove tutorial from watchlist!\n";
}