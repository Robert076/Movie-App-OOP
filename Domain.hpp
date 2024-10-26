#include <string>

using namespace std;

class Tutorial
{
private:
	string title, presenter, duration, link;
	int likes;
public:
	Tutorial() : title(""), presenter(""), duration(""), link(""), likes(0) 
	{
		/*
		* Default constructor for the Tutorial class
		* Input: -
		* Output: an object of type Tutorial that has the default values
		*/
		this->title = "";
		this->presenter = "";
		this->duration = "";
		this->link = "";
		this->likes = 0;
	}
	Tutorial(string title, string presenter, string duration, string link, int likes);
	~Tutorial() {};
	string getTitle();
	string getPresenter();
	string getDuration();
	string getLink();
	int getLikes();
	bool operator==(const Tutorial& other);
	void setTitle(string title);
	void setPresenter(string presenter);
	void setDuration(string duration);
	void setLink(string link);
	void setLikes(int likes);
};