#include <iostream>
#include <memory>
#include <string>

using std::cout;
using std::endl;
using std::unique_ptr;
using std::string;

class BaseChain
{
public:
	string chainActions(const string &str)
	{
		const string output = action(str);
		if ( m_next )
			return m_next->chainActions(output);
		return output;
	}

	BaseChain &addToChain(BaseChain *link)
	{ m_next.reset(link); return *link; }

private:
	std::unique_ptr< BaseChain > m_next;

	virtual	string action(const string &) const = 0;
};

class Application : public BaseChain
{
	virtual
	string action(const string &input) const override
	{
		return "Application\n" + input;
	};
};

class Transport : public BaseChain
{
	virtual
	string action(const string &input) const override
	{
		return "Transport\n" + input;
	};
};


class Internet : public BaseChain
{
	virtual
	string action(const string &input) const override
	{
		return "Internet\n" + input;
	};
};

class DataLink : public BaseChain
{
	virtual
	string action(const string &input) const override
	{
		return "Data Link\n" + input;
	};
};

class Physical : public BaseChain
{
	virtual
	string action(const string &input) const override
	{
		return "Physical\n" + input;
	};
};

int main()
{
	Physical p;
	p.addToChain(new DataLink)
		.addToChain(new Internet)
		.addToChain(new Transport)
		.addToChain(new Application);

	cout << p.chainActions("This is TCP/IP's data flow!") << endl;
};
