#include "Services.hpp"

class UI
{
private:
	Services services;

public:
	UI();
	~UI() {};
	void run();
	void runAdmin();
	void runUser();
	void manageAddTutorial();
	void manageRemoveTutorial();
	void manageUpdateTutorial();
	void manageListAll();
	void manageSeeTutorialsByPresenter();	
	void manageSeeWatchlist();
	void manageRemoveFromWatchlist();
};